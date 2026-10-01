/*
 * ad4130_test.c  -  samostalni test program za ADC AD4130-8 (Atlas-TPL_AI)
 *
 * Svrha: izolovano testiranje ADC-a (bez DAC-a, port ekspandera i UART-ova).
 *
 * Struktura fajla:
 *   1) PARAMETRI / HARDVER      - SPI, referenca, gain
 *   2) MAPA REGISTARA AD4130-8  - adrese i bitovi (datasheet Rev. A, str. 82-106)
 *   3) SPI NIVO                 - transfer, citanje i upis registra
 *   4) KONFIGURACIJA ADC-a      - OVDE SE SETUJE SVE, korak po korak, sa komentarima
 *   5) MERENJE                  - cekanje RDYB, citanje DATA, konverzija u volte, statistika
 *   6) main()                   - argumenti, otvaranje SPI-ja, poziv konfiguracije i merenja
 *
 * Prevodjenje:
 *   gcc -O2 -Wall -o ad4130_test ad4130_test.c
 *
 * Upotreba:  ./ad4130_test [opcije]
 *   -p N     AINP: pozitivni ulaz AIN0..AIN15              (podrazumevano 3 = AIN3)
 *   -m N     AINM: negativni ulaz 0..15 ili "avss"          (podrazumevano avss = single-ended)
 *   -d       dijagnostika: ADC meri (AVDD-AVSS)/6 (interni kanal, spoljni ulaz se ne koristi)
 *   -b       bipolarno (offset binary) kodiranje            (podrazumevano unipolarno / straight binary)
 *   -f FS    FS filtera sinc3, 1..2047                      (podrazumevano 48 -> 50 SPS)
 *   -n N     broj uzoraka, 0 = do Ctrl+C                    (podrazumevano 0)
 *   -k F     faktor za prikaz napona na konektoru           (podrazumevano 1.0, za Vin kanale 4.3)
 *   -D DEV   SPI uredjaj                                    (podrazumevano /dev/spidev0.0)
 *   -v       ispis sirovih SPI bajtova
 *   -h       pomoc
 *
 * Primeri:
 *   ./ad4130_test -p 3 -k 4.3      AIN3 prema AVSS, prikazuje i napon * 4.3
 *   ./ad4130_test -d -n 50         dijagnostika, ocekivano ~0.55 V (AVDD = 3.3 V)
 *   ./ad4130_test -p 4 -m 5        diferencijalno AIN4 - AIN5 (strujni ulaz Iin1)
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>


/* ====================================================================== */
/* 1) PARAMETRI / HARDVER                                                  */
/* ====================================================================== */

#define SPI_DEVICE_DEFAULT  "/dev/spidev0.0"
#define SPI_SPEED_HZ        1000000u    /* datasheet dozvoljava do 5 MHz (tSCK >= 200 ns) */
#define SPI_BITS            8
#define SPI_MODE_AD4130     SPI_MODE_3  /* CPOL=1, CPHA=1 */

#define ADC_VREF_V          2.5         /* interna referenca, INT_REF_VAL = 0 -> 2.5 V   */
#define ADC_GAIN            1.0         /* PGA gain, mora da odgovara CONFIG_0 (PGA_n)   */
#define AD4130_MCLK_HZ      76800.0     /* interni oscilator                             */

#define USE_CS_PIN          1           /* 1 = CSB_EN=1 (4-wire, CS uokviruje transfer),
                                           0 = CSB_EN=0 (3-wire, CS se ignorise).
                                           Ako citanje registara nazad ne prolazi, probaj 0. */

#define WARMUP_SAMPLES      3           /* prvih nekoliko uzoraka posle starta se odbacuje */
#define READY_TIMEOUT_MS    3000        /* koliko najduze cekamo RDYB = 0                  */
#define TWR_DEL_US          100         /* pauza posle upisa (tWR_DEL = 3..4 / fMCLK ~ 52 us) */
#define REF_SETTLE_US       2000        /* cekanje da se interna referenca umiri (280 us tipicno) */


/* ====================================================================== */
/* 2) MAPA REGISTARA AD4130-8                                              */
/* ====================================================================== */

/* COMMS (prvi bajt svake transakcije): bit7 WEN = 0, bit6 R/W (1 = citanje), bit5:0 adresa */
#define AD4130_COMMS_READ   0x40

/* Adrese registara */
#define REG_STATUS          0x00    /* 1 bajt  */
#define REG_ADC_CONTROL     0x01    /* 2 bajta */
#define REG_DATA            0x02    /* 3 bajta (+1 bajt STATUS ako je DATA_STATUS=1) */
#define REG_IO_CONTROL      0x03    /* 2 bajta */
#define REG_ID              0x05    /* 1 bajt  */
#define REG_ERROR           0x06    /* 2 bajta, R/W1C */
#define REG_ERROR_EN        0x07    /* 2 bajta */
#define REG_MCLK_COUNT      0x08    /* 1 bajt  */
#define REG_CHANNEL(m)      (0x09 + (m))    /* 3 bajta, m = 0..15 */
#define REG_CONFIG(n)       (0x19 + (n))    /* 2 bajta, n = 0..7  */
#define REG_FILTER(n)       (0x21 + (n))    /* 3 bajta, n = 0..7  */

/* STATUS bitovi */
#define ST_RDYB             0x80    /* 0 = podatak spreman, 1 = nije spreman */
#define ST_MASTER_ERR       0x40    /* bar jedan flag u ERROR registru je postavljen */
#define ST_POR_FLAG         0x10    /* power-on reset desio se, brise se citanjem STATUS-a */
#define ST_CH_ACTIVE        0x0F    /* broj kanala cija je konverzija u DATA registru */

/* ADC_CONTROL bitovi */
#define ADC_CTRL_BIPOLAR        (UINT32_C(1) << 14) /* 1 = offset binary, 0 = straight binary */
#define ADC_CTRL_INT_REF_VAL    (UINT32_C(1) << 13) /* 0 = 2.5 V, 1 = 1.25 V                  */
#define ADC_CTRL_DATA_STATUS    (UINT32_C(1) << 10) /* 1 = STATUS bajt se lepi iza DATA       */
#define ADC_CTRL_CSB_EN         (UINT32_C(1) << 9)  /* 1 = CS pin aktivan (4-wire)            */
#define ADC_CTRL_INT_REF_EN     (UINT32_C(1) << 8)  /* 1 = interna referenca ukljucena        */
#define ADC_CTRL_MODE(x)        ((uint32_t)(x) << 2)/* bitovi [5:2]                           */
#define ADC_MODE_CONTINUOUS     0x0
#define ADC_MODE_IDLE           0x4
/* bitovi [1:0] CLK_SEL = 00 -> interni oscilator 76.8 kHz, bez izlaza na CLK pin */

/* ERROR_EN bitovi */
#define ERR_EN_MCLK_CNT         (UINT32_C(1) << 12) /* ukljucuje MCLK brojac (MCLK_COUNT)     */
#define ERR_EN_ADC_ERR          (UINT32_C(1) << 7)  /* flag: rezultat u klipovanju / saturacija modulatora */
#define ERR_EN_SPI_IGNORE       (UINT32_C(1) << 6)  /* flag: SPI pristup dok je ADC zauzet (default 1) */

/* CHANNEL_m bitovi */
#define CH_ENABLE               (UINT32_C(1) << 23)
#define CH_SETUP(x)             ((uint32_t)(x) << 20)   /* koji setup (CONFIG/FILTER/OFFSET/GAIN) */
#define CH_AINP(x)              ((uint32_t)(x) << 13)
#define CH_AINM(x)              ((uint32_t)(x) << 8)

/* Kodovi ulaza za AINP / AINM (CHANNEL_m): 0..15 = AIN0..AIN15, plus: */
#define AIN_AVSS                17      /* analogna masa -> single-ended merenje */
#define AIN_AVDD_DIV6_P         20      /* (AVDD-AVSS)/6 +   */
#define AIN_AVDD_DIV6_M         21      /* (AVDD-AVSS)/6 -   */

/* CONFIG_n bitovi */
#define CFG_REF_SEL(x)          ((uint32_t)(x) << 4)    /* bitovi [5:4]                        */
#define CFG_REF_REFOUT_AVSS     2                       /* 10 = REFOUT/AVSS = interna referenca */
#define CFG_PGA(x)              ((uint32_t)(x) << 1)    /* bitovi [3:1], 0 = gain 1            */
#define CFG_PGA_BYP             (UINT32_C(1) << 0)      /* 1 = PGA premosten (gain fiksno 1)   */

/* FILTER_n bitovi */
#define FILT_MODE(x)            ((uint32_t)(x) << 12)   /* bitovi [15:12]                      */
#define FILT_MODE_SINC3         2
#define FILT_FS(x)              ((uint32_t)(x) & 0x7FF) /* bitovi [10:0]                       */


/* ====================================================================== */
/* 3) SPI NIVO                                                             */
/* ====================================================================== */

typedef struct {
    const char *spi_dev;    /* putanja SPI uredjaja                         */
    uint8_t     ainp;       /* kod pozitivnog ulaza                         */
    uint8_t     ainm;       /* kod negativnog ulaza                         */
    int         diag_avdd;  /* 1 = merimo (AVDD-AVSS)/6                     */
    int         bipolar;    /* 1 = offset binary, 0 = straight binary       */
    unsigned    fs;         /* FS sinc3 filtera                             */
    long        n_samples;  /* 0 = beskonacno                               */
    double      disp_factor;/* faktor za prikaz napona na konektoru         */
} test_cfg_t;

static int g_verbose = 0;
static volatile sig_atomic_t g_stop = 0;

static void on_sigint(int sig)
{
    (void)sig;
    g_stop = 1;
}

static void hexdump(const char *label, const uint8_t *buf, int len)
{
    int i;
    printf("    %-5s [%d B]:", label, len);
    for (i = 0; i < len; i++) printf(" %02X", buf[i]);
    printf("\n");
}

/* Jedan SPI transfer (CS se spusta na pocetku i podize na kraju transfera) */
static int spi_xfer(int fd, const uint8_t *tx, uint8_t *rx, int len)
{
    struct spi_ioc_transfer tr;
    memset(&tr, 0, sizeof(tr));
    tr.tx_buf = (uintptr_t)tx;
    tr.rx_buf = (uintptr_t)rx;
    tr.len = (uint32_t)len;
    tr.speed_hz = SPI_SPEED_HZ;
    tr.bits_per_word = SPI_BITS;
    tr.cs_change = 0;

    if (g_verbose) hexdump("MOSI", tx, len);
    if (ioctl(fd, SPI_IOC_MESSAGE(1), &tr) < 1) {
        perror("SPI_IOC_MESSAGE");
        return -1;
    }
    if (g_verbose) hexdump("MISO", rx, len);
    return 0;
}

/* Citanje registra duzine 1..4 bajta (MSB prvi). Rezultat u *out. */
static int ad4130_read_reg(int fd, uint8_t reg, int len, uint32_t *out)
{
    uint8_t tx[8] = {0}, rx[8] = {0};
    uint32_t v = 0;
    int i;

    if (len < 1 || len > 4) return -1;
    tx[0] = AD4130_COMMS_READ | (reg & 0x3F);   /* DIN ostaje 0 dok citamo podatke */
    if (spi_xfer(fd, tx, rx, 1 + len) < 0) return -1;
    for (i = 0; i < len; i++) v = (v << 8) | rx[1 + i];
    *out = v;
    return 0;
}

/* Upis registra duzine 1..4 bajta (MSB prvi) */
static int ad4130_write_reg(int fd, uint8_t reg, uint32_t val, int len)
{
    uint8_t tx[8] = {0}, rx[8] = {0};
    int i;

    if (len < 1 || len > 4) return -1;
    tx[0] = reg & 0x3F;                         /* bit6 = 0 -> upis */
    for (i = 0; i < len; i++) tx[1 + i] = (uint8_t)(val >> (8 * (len - 1 - i)));
    if (spi_xfer(fd, tx, rx, 1 + len) < 0) return -1;
    usleep(TWR_DEL_US);     /* tWR_DEL: razmak izmedju uzastopnih upisa (ADC_CONTROL / ERROR) */
    return 0;
}

/* Upis registra + citanje nazad + poredjenje. Ispisuje [OK] ili [GRESKA]. */
static int ad4130_write_verify(int fd, uint8_t reg, uint32_t val, int len, const char *name)
{
    uint32_t rb = 0;

    if (ad4130_write_reg(fd, reg, val, len) < 0) return -1;
    if (ad4130_read_reg(fd, reg, len, &rb) < 0) return -1;
    if (rb != val) {
        fprintf(stderr, "  [GRESKA] %-12s poslato 0x%0*X, procitano nazad 0x%0*X\n",
                name, len * 2, (unsigned)val, len * 2, (unsigned)rb);
        return -1;
    }
    printf("  [OK]     %-12s = 0x%0*X\n", name, len * 2, (unsigned)val);
    return 0;
}


/* ====================================================================== */
/* 4) KONFIGURACIJA ADC-a                                                  */
/*                                                                         */
/*    Redosled (prati preporuku iz datasheet-a, str. 80):                  */
/*      0. softverski reset                                                */
/*      1. provera komunikacije (ID, STATUS)                               */
/*      2. ERROR_EN        - dijagnostika                                  */
/*      3. ADC_CONTROL     - interfejs, referenca, kodiranje, MODE = idle  */
/*      4. CONFIG_0        - referenca, PGA, struje                        */
/*      5. FILTER_0        - digitalni filter i brzina uzorkovanja         */
/*      6. CHANNEL_0       - koji ulazi se mere                            */
/*      7. pauza za referencu                                              */
/*      8. ADC_CONTROL     - MODE = continuous (start konverzija)          */
/* ====================================================================== */

/* KORAK 0: softverski reset.
 * 64 uzastopne jedinice na DIN (8 x 0xFF) vracaju sve registre na default.
 * Posle reseta ADC odmah radi u continuous modu na CHANNEL_0 = AIN0/AIN1 sa
 * spoljnom referencom (REFIN1), pa ga u koraku 3 prvo stavljamo u idle.
 * Posle reseta treba sacekati >= 160/fMCLK = 2.1 ms (tRESET_DELAY). */
static int cfg_soft_reset(int fd)
{
    uint8_t tx[8], rx[8];

    memset(tx, 0xFF, sizeof(tx));
    if (spi_xfer(fd, tx, rx, sizeof(tx)) < 0) return -1;
    usleep(5000);
    printf("  [OK]     softverski reset\n");
    return 0;
}

/* KORAK 1: provera komunikacije.
 * ID (0x05): SILICON_ID[3:2] = 01, MODEL_ID[1:0] = 01 za LFCSP -> ocekuje se 0x05.
 * STATUS (0x00): citanjem se brise POR_FLAG (bit 4) koji je postavljen posle reseta. */
static int cfg_check_comm(int fd)
{
    uint32_t id = 0, st = 0;

    if (ad4130_read_reg(fd, REG_ID, 1, &id) < 0) return -1;
    printf("  ID registar = 0x%02X (ocekivano 0x05 za LFCSP)\n", (unsigned)id);
    if (id == 0x00 || id == 0xFF) {
        fprintf(stderr, "  [GRESKA] ID je 0x%02X - SPI komunikacija ne radi (provera: mod, CS, ozicenje)\n",
                (unsigned)id);
        return -1;
    }
    if (id != 0x05) printf("  [UPOZORENJE] ID nije 0x05 - proveri da li je u pitanju LFCSP verzija\n");

    if (ad4130_read_reg(fd, REG_STATUS, 1, &st) < 0) return -1;
    printf("  STATUS posle reseta = 0x%02X (POR_FLAG=%u, ocekivano 1 pri prvom citanju)\n",
           (unsigned)st, (unsigned)((st & ST_POR_FLAG) ? 1 : 0));
    return 0;
}

/* KORAK 2: ERROR_EN (0x07, 2 bajta) - koje dijagnostike su ukljucene.
 *   bit 12 MCLK_CNT_EN  = 1 -> MCLK_COUNT registar broji (provera da oscilator radi)
 *   bit  7 ADC_ERR_EN   = 1 -> flag kad je rezultat u klipovanju (van opsega) ili modulator u saturaciji
 *   bit  6 SPI_IGNORE_ERR_EN = 1 -> flag ako SPI pristup dodje dok ADC nije spreman (default ukljucen)
 * Sve ostalo je 0. Rezultat: 0x10C0 */
static int cfg_error_enable(int fd)
{
    uint32_t v = ERR_EN_MCLK_CNT | ERR_EN_ADC_ERR | ERR_EN_SPI_IGNORE;

    return ad4130_write_verify(fd, REG_ERROR_EN, v, 2, "ERROR_EN");
}

/* Sklapa vrednost ADC_CONTROL (0x01, 2 bajta) za zadati MODE.
 *   bit 14 BIPOLAR       = c->bipolar -> 1: offset binary (0 V = 0x800000), 0: straight binary (0 V = 0x000000)
 *   bit 13 INT_REF_VAL   = 0          -> interna referenca 2.5 V
 *   bit 10 DATA_STATUS   = 1          -> iza 24-bitnog podatka dolazi STATUS bajt (kanal, greske)
 *   bit  9 CSB_EN        = USE_CS_PIN -> CS pin aktivan (4-wire)
 *   bit  8 INT_REF_EN    = 1          -> interna referenca ukljucena (REFOUT = 2.5 V)
 *   bits [5:2] MODE      = mode       -> 0000 continuous, 0100 idle
 *   bits [1:0] CLK_SEL   = 00         -> interni oscilator 76.8 kHz, CLK pin ostaje neaktivan */
static uint32_t adc_control_value(const test_cfg_t *c, unsigned mode)
{
    uint32_t v = 0;

    if (c->bipolar) v |= ADC_CTRL_BIPOLAR;
    v |= ADC_CTRL_DATA_STATUS;
    if (USE_CS_PIN) v |= ADC_CTRL_CSB_EN;
    v |= ADC_CTRL_INT_REF_EN;
    v |= ADC_CTRL_MODE(mode);
    return v;
}

/* KORAK 3 i 8: upis ADC_CONTROL */
static int cfg_adc_control(int fd, const test_cfg_t *c, unsigned mode, const char *name)
{
    return ad4130_write_verify(fd, REG_ADC_CONTROL, adc_control_value(c, mode), 2, name);
}

/* KORAK 4 i 5: ADC setup 0 = CONFIG_0 + FILTER_0 (koristi ga CHANNEL_0 preko SETUP_0 = 0) */
static int cfg_setup0(int fd, const test_cfg_t *c)
{
    /* CONFIG_0 (0x19, 2 bajta):
     *   [15:13] I_OUT1_n  = 000 -> ekscitaciona struja 1 iskljucena
     *   [12:10] I_OUT0_n  = 000 -> ekscitaciona struja 0 iskljucena
     *   [ 9: 8] BURNOUT_n = 00  -> burnout struje iskljucene
     *   [    7] REF_BUFP_n = 0  -> bafer na REFIN(+) nije potreban (koristimo internu referencu)
     *   [    6] REF_BUFM_n = 0  -> bafer na REFIN(-) nije potreban
     *   [ 5: 4] REF_SEL_n = 10  -> REFOUT/AVSS = interna referenca (2.5 V)
     *   [ 3: 1] PGA_n     = 000 -> gain 1
     *   [    0] PGA_BYP_n = 0   -> PGA ukljucen (fabricka kalibracija pojacanja je radjena sa PGA_BYP = 0)
     * Rezultat: 0x0020 */
    uint32_t config0 = CFG_REF_SEL(CFG_REF_REFOUT_AVSS) | CFG_PGA(0);

    /* FILTER_0 (0x21, 3 bajta):
     *   [23:21] SETTLE_n      = 000 -> front-end settling 32 MCLK (~0.4 ms) pre konverzije
     *   [20:16] REPEAT_n      = 0   -> bez ponavljanja konverzije
     *   [15:12] FILTER_MODE_n = 0010 -> sinc3
     *   [10: 0] FS_n          = c->fs -> ODR = fMCLK / 32 / FS  (FS = 48 -> 50 SPS, FS = 10 -> 240 SPS)
     * Za FS = 48 rezultat je 0x002030 (to je i default posle reseta). */
    uint32_t filter0 = FILT_MODE(FILT_MODE_SINC3) | FILT_FS(c->fs);

    if (ad4130_write_verify(fd, REG_CONFIG(0), config0, 2, "CONFIG_0") < 0) return -1;
    if (ad4130_write_verify(fd, REG_FILTER(0), filter0, 3, "FILTER_0") < 0) return -1;
    return 0;
}

/* KORAK 6: CHANNEL_0 (0x09, 3 bajta) - jedini kanal koji je ukljucen.
 *   [   23] ENABLE_m    = 1       -> kanal je u sekvenci
 *   [22:20] SETUP_m     = 000     -> koristi CONFIG_0 / FILTER_0 / OFFSET_0 / GAIN_0
 *   [   19] PDSW_m      = 0       -> PSW prekidac se ne koristi
 *   [   18] THRES_EN_m  = 0       -> FIFO prag se ne koristi
 *   [17:13] AINP_m      = c->ainp -> pozitivni ulaz (3 = AIN3)
 *   [12: 8] AINM_m      = c->ainm -> negativni ulaz (17 = AVSS -> single-ended)
 *   [ 7: 4] I_OUT1_CH_m = 0, [3:0] I_OUT0_CH_m = 0 -> bez efekta, struje su iskljucene u CONFIG_0
 * Ostali kanali (CHANNEL_1..15) su posle reseta iskljuceni, pa ih ne diramo.
 * Primer: AIN3 prema AVSS -> 0x807100 */
static int cfg_channel0(int fd, const test_cfg_t *c)
{
    uint32_t ch0 = CH_ENABLE | CH_SETUP(0) | CH_AINP(c->ainp) | CH_AINM(c->ainm);

    return ad4130_write_verify(fd, REG_CHANNEL(0), ch0, 3, "CHANNEL_0");
}

/* Provera oscilatora preko MCLK_COUNT (0x08).
 * Brojac se uvecava na svakih 131 MCLK impulsa (586.26 Hz) i vraca se na 0 posle 255,
 * pa iz razlike dva citanja i proteklog vremena procenjujemo frekvenciju. */
static int cfg_check_clock(int fd)
{
    struct timespec t1, t2;
    uint32_t c1 = 0, c2 = 0;
    double dt, f_khz;
    unsigned delta;

    if (ad4130_read_reg(fd, REG_MCLK_COUNT, 1, &c1) < 0) return -1;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    usleep(100000);
    if (ad4130_read_reg(fd, REG_MCLK_COUNT, 1, &c2) < 0) return -1;
    clock_gettime(CLOCK_MONOTONIC, &t2);

    dt = (double)(t2.tv_sec - t1.tv_sec) + (double)(t2.tv_nsec - t1.tv_nsec) * 1e-9;
    delta = (unsigned)((c2 - c1) & 0xFF);
    f_khz = (dt > 0.0) ? ((double)delta * 131.0 / dt) / 1000.0 : 0.0;
    printf("  MCLK_COUNT: 0x%02X -> 0x%02X za %.1f ms => MCLK ~ %.1f kHz (ocekivano 76.8 kHz)%s\n",
           (unsigned)c1, (unsigned)c2, dt * 1000.0, f_khz,
           (delta == 0) ? "  [UPOZORENJE: brojac se ne menja, oscilator ne radi?]" : "");
    return 0;
}

/* Ispis (i brisanje) flagova iz ERROR registra. Ispisuje se samo prvih 5 puta. */
static void report_errors(int fd)
{
    static const struct { unsigned bit; const char *name; } flags[] = {
        {11, "AINP_OV_UV"}, {10, "AINM_OV_UV"}, {9, "REF_OV_UV"}, {8, "REF_DETECT"},
        {7, "ADC_ERR(klipovanje/saturacija)"}, {6, "SPI_IGNORE"}, {5, "SPI_SCLK_CNT"},
        {4, "SPI_READ"}, {3, "SPI_WRITE"}, {2, "SPI_CRC"}, {1, "MM_CRC"}, {0, "ROM_CRC"},
    };
    static int printed = 0;
    uint32_t e = 0;
    unsigned i;

    if (ad4130_read_reg(fd, REG_ERROR, 2, &e) < 0 || e == 0) return;
    if (printed < 5) {
        printf("  [ERROR registar] 0x%04X:", (unsigned)e);
        for (i = 0; i < sizeof(flags) / sizeof(flags[0]); i++)
            if (e & (UINT32_C(1) << flags[i].bit)) printf(" %s", flags[i].name);
        printf("\n");
        if (++printed == 5) printf("  (dalje ne ispisujem ERROR flagove, ali ih brisem)\n");
    }
    ad4130_write_reg(fd, REG_ERROR, e, 2);  /* R/W1C: upis jedinica brise flagove */
}

/* Cela konfiguracija, redom. Vraca 0 ako je sve proslo. */
static int ad4130_configure(int fd, const test_cfg_t *c)
{
    uint32_t io = 0;

    printf("KONFIGURACIJA:\n");

    if (cfg_soft_reset(fd) < 0)                                    return -1;  /* korak 0 */
    if (cfg_check_comm(fd) < 0)                                    return -1;  /* korak 1 */
    if (cfg_error_enable(fd) < 0)                                  return -1;  /* korak 2 */
    if (cfg_adc_control(fd, c, ADC_MODE_IDLE, "ADC_CONTROL") < 0)  return -1;  /* korak 3: idle + referenca ON */
    if (cfg_setup0(fd, c) < 0)                                     return -1;  /* koraci 4 i 5 */
    if (cfg_channel0(fd, c) < 0)                                   return -1;  /* korak 6 */

    /* IO_CONTROL (0x03) se NE dira: ostaje 0x0000 -> INT_PIN_SEL = 00 (data ready ide na DOUT/RDY),
     * GPO_CTRL_P2 = 0 (AIN3/P2 ostaje analogni ulaz). Samo ga procitamo radi provere. */
    if (ad4130_read_reg(fd, REG_IO_CONTROL, 2, &io) < 0)           return -1;
    printf("  IO_CONTROL = 0x%04X (ocekivano 0x0000)\n", (unsigned)io);

    usleep(REF_SETTLE_US);                                                      /* korak 7 */

    if (cfg_adc_control(fd, c, ADC_MODE_CONTINUOUS, "ADC_CONTROL") < 0) return -1;  /* korak 8: START */
    cfg_check_clock(fd);
    report_errors(fd);          /* obrisi flagove nastale pri reset-u/konfiguraciji */
    printf("\n");
    return 0;
}


/* ====================================================================== */
/* 5) MERENJE                                                              */
/* ====================================================================== */

/* Konverzija 24-bitnog koda u napon na ulazu ADC-a (AINP - AINM).
 *   unipolarno (BIPOLAR = 0): Vin = code / 2^24 * VREF / gain      (0 V = 0x000000, VREF = 0xFFFFFF)
 *   bipolarno  (BIPOLAR = 1): Vin = (code / 2^23 - 1) * VREF / gain (0 V = 0x800000) */
static double code_to_volts(uint32_t code, int bipolar)
{
    if (bipolar) return ((double)code / 8388608.0 - 1.0) * (ADC_VREF_V / ADC_GAIN);
    return (double)code / 16777216.0 * (ADC_VREF_V / ADC_GAIN);
}

/* Cekanje da RDYB (STATUS bit 7) padne na 0 = nov rezultat u DATA registru.
 * Citamo STATUS (1 bajt), a ne DATA, da ne bismo prekinuli upis novog rezultata.
 * Vraca: 0 spreman, 1 timeout, 2 prekinuto sa Ctrl+C, -1 SPI greska. */
static int ad4130_wait_ready(int fd, int timeout_ms)
{
    long waited_us = 0;
    uint32_t st = 0;

    while (!g_stop) {
        if (ad4130_read_reg(fd, REG_STATUS, 1, &st) < 0) return -1;
        if (!(st & ST_RDYB)) return 0;
        usleep(500);
        waited_us += 500;
        if (waited_us > (long)timeout_ms * 1000) return 1;
    }
    return 2;
}

/* Citanje DATA (3 bajta) + appendovani STATUS (1 bajt, jer je DATA_STATUS = 1) */
static int ad4130_read_sample(int fd, uint32_t *code, uint8_t *status)
{
    uint32_t raw = 0;

    if (ad4130_read_reg(fd, REG_DATA, 4, &raw) < 0) return -1;
    *code = (raw >> 8) & 0xFFFFFF;
    *status = (uint8_t)(raw & 0xFF);
    return 0;
}

/* Statistika (Welford) */
typedef struct { unsigned long n; double mean, m2, min, max; } stats_t;

static void stats_add(stats_t *s, double x)
{
    double d = x - s->mean;

    s->n++;
    s->mean += d / (double)s->n;
    s->m2 += d * (x - s->mean);
    if (s->n == 1 || x < s->min) s->min = x;
    if (s->n == 1 || x > s->max) s->max = x;
}

/* Kvadratni koren bez libm (da link ne trazi -lm) */
static double my_sqrt(double x)
{
    double r;
    int i;

    if (x <= 0.0) return 0.0;
    r = (x > 1.0) ? x : 1.0;
    for (i = 0; i < 100; i++) r = 0.5 * (r + x / r);
    return r;
}

/* Glavna petlja merenja: ispisuje svaki uzorak, na kraju statistiku */
static int run_measurement(int fd, const test_cfg_t *c)
{
    stats_t st;
    unsigned long taken = 0;
    long printed = 0;
    uint32_t code = 0;
    uint8_t status = 0;
    int r;

    memset(&st, 0, sizeof(st));
    printf("MERENJE (Ctrl+C za prekid):\n");

    while (!g_stop && (c->n_samples == 0 || printed < c->n_samples)) {
        r = ad4130_wait_ready(fd, READY_TIMEOUT_MS);
        if (r == 2) break;
        if (r == 1) {
            fprintf(stderr, "[GRESKA] RDYB ne pada na 0 posle %d ms - konverzija ne radi "
                            "(proveri takt, MODE i referencu).\n", READY_TIMEOUT_MS);
            return -1;
        }
        if (r < 0) return -1;

        if (ad4130_read_sample(fd, &code, &status) < 0) return -1;
        taken++;
        if (taken <= WARMUP_SAMPLES) continue;      /* odbaci prve uzorke posle starta */

        {
            double v_adc = code_to_volts(code, c->bipolar);
            double v_con = v_adc * c->disp_factor;

            printf("#%-5ld CH%u  kod=%8u (0x%06X)", printed + 1, (unsigned)(status & ST_CH_ACTIVE),
                   (unsigned)code, (unsigned)code);
            if (c->bipolar) printf(" [rel. %+d]", (int)code - 0x800000);
            printf("  Vadc=%+9.6f V", v_adc);
            if (c->disp_factor != 1.0) printf("  Vkonektor=%+9.4f V", v_con);
            printf("\n");
            stats_add(&st, v_adc);
            printed++;
        }

        if (status & ST_MASTER_ERR) report_errors(fd);
    }

    if (st.n > 1) {
        double sd = my_sqrt(st.m2 / (double)(st.n - 1));

        printf("\nSTATISTIKA (%lu uzoraka): srednja = %+.6f V, min = %+.6f V, max = %+.6f V, "
               "p-p = %.1f uV, sigma = %.1f uV\n",
               st.n, st.mean, st.min, st.max, (st.max - st.min) * 1e6, sd * 1e6);
        if (c->disp_factor != 1.0)
            printf("                       srednja * %.3f = %+.4f V\n", c->disp_factor, st.mean * c->disp_factor);
    }
    return 0;
}


/* ====================================================================== */
/* 6) main()                                                               */
/* ====================================================================== */

static void usage(const char *prog)
{
    printf("Upotreba: %s [-p AINP] [-m AINM|avss] [-d] [-b] [-f FS] [-n N] [-k F] [-D DEV] [-v]\n"
           "  -p N     pozitivni ulaz AIN0..AIN15 (default 3)\n"
           "  -m N     negativni ulaz 0..15 ili 'avss' (default avss = single-ended)\n"
           "  -d       dijagnostika: meri (AVDD-AVSS)/6, ocekivano ~0.55 V za AVDD = 3.3 V\n"
           "  -b       bipolarno (offset binary) kodiranje (default unipolarno)\n"
           "  -f FS    FS sinc3 filtera 1..2047 (default 48 -> 50 SPS); ODR = 76800/32/FS\n"
           "  -n N     broj uzoraka (0 = do Ctrl+C)\n"
           "  -k F     faktor za prikaz napona na konektoru (npr. 4.3)\n"
           "  -D DEV   SPI uredjaj (default %s)\n"
           "  -v       ispis sirovih SPI bajtova\n", prog, SPI_DEVICE_DEFAULT);
}

static int parse_long(const char *s, long lo, long hi, long *out)
{
    char *end = NULL;
    long v;

    errno = 0;
    v = strtol(s, &end, 0);
    if (errno || end == s || *end != '\0' || v < lo || v > hi) return -1;
    *out = v;
    return 0;
}

int main(int argc, char **argv)
{
    test_cfg_t cfg;
    int opt, fd, rc;
    long v;
    uint8_t mode = SPI_MODE_AD4130;
    uint8_t bits = SPI_BITS;
    uint32_t speed = SPI_SPEED_HZ;

    /* podrazumevane vrednosti: AIN3 prema AVSS, unipolarno, 50 SPS */
    cfg.spi_dev = SPI_DEVICE_DEFAULT;
    cfg.ainp = 3;
    cfg.ainm = AIN_AVSS;
    cfg.diag_avdd = 0;
    cfg.bipolar = 0;
    cfg.fs = 48;
    cfg.n_samples = 0;
    cfg.disp_factor = 1.0;

    while ((opt = getopt(argc, argv, "p:m:dbf:n:k:D:vh")) != -1) {
        switch (opt) {
        case 'p':
            if (parse_long(optarg, 0, 15, &v) < 0) { fprintf(stderr, "-p: 0..15\n"); return EXIT_FAILURE; }
            cfg.ainp = (uint8_t)v;
            break;
        case 'm':
            if (strcmp(optarg, "avss") == 0) cfg.ainm = AIN_AVSS;
            else if (parse_long(optarg, 0, 15, &v) == 0) cfg.ainm = (uint8_t)v;
            else { fprintf(stderr, "-m: 0..15 ili avss\n"); return EXIT_FAILURE; }
            break;
        case 'd': cfg.diag_avdd = 1; break;
        case 'b': cfg.bipolar = 1; break;
        case 'f':
            if (parse_long(optarg, 1, 2047, &v) < 0) { fprintf(stderr, "-f: 1..2047\n"); return EXIT_FAILURE; }
            cfg.fs = (unsigned)v;
            break;
        case 'n':
            if (parse_long(optarg, 0, 100000000L, &v) < 0) { fprintf(stderr, "-n: >= 0\n"); return EXIT_FAILURE; }
            cfg.n_samples = v;
            break;
        case 'k': {
            char *end = NULL;
            double k = strtod(optarg, &end);
            if (end == optarg || *end != '\0' || k == 0.0) { fprintf(stderr, "-k: broj != 0\n"); return EXIT_FAILURE; }
            cfg.disp_factor = k;
            break;
        }
        case 'D': cfg.spi_dev = optarg; break;
        case 'v': g_verbose = 1; break;
        case 'h':
        default:
            usage(argv[0]);
            return (opt == 'h') ? EXIT_SUCCESS : EXIT_FAILURE;
        }
    }

    if (cfg.diag_avdd) {            /* dijagnostika: interni kanal (AVDD-AVSS)/6 */
        cfg.ainp = AIN_AVDD_DIV6_P;
        cfg.ainm = AIN_AVDD_DIV6_M;
    }

    printf("AD4130-8 test | SPI %s | AINP=%u AINM=%u%s | %s | FS=%u (%.1f SPS) | VREF=%.3f V gain=%.0f\n\n",
           cfg.spi_dev, (unsigned)cfg.ainp, (unsigned)cfg.ainm,
           cfg.diag_avdd ? " (dijagnostika AVDD/6)" : "",
           cfg.bipolar ? "bipolarno (offset binary)" : "unipolarno (straight binary)",
           cfg.fs, AD4130_MCLK_HZ / 32.0 / (double)cfg.fs, ADC_VREF_V, ADC_GAIN);

    fd = open(cfg.spi_dev, O_RDWR);
    if (fd < 0) {
        perror(cfg.spi_dev);
        return EXIT_FAILURE;
    }
    if (ioctl(fd, SPI_IOC_WR_MODE, &mode) < 0 ||
        ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits) < 0 ||
        ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        perror("podesavanje SPI parametara");
        close(fd);
        return EXIT_FAILURE;
    }

    signal(SIGINT, on_sigint);

    rc = ad4130_configure(fd, &cfg);            /* <-- sva konfiguracija je gore, u sekciji 4 */
    if (rc == 0) rc = run_measurement(fd, &cfg);/* <-- merenje, sekcija 5 */

    close(fd);
    return (rc == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
