// user space za DAC kovertor i komunikacija preko i2c-a

//POSLEDNJA VERZIJA 25/9/2026


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>          // atoi (tekst->broj), EXIT_SUCCESS/EXIT_FAILURE
#include <fcntl.h>
#include <unistd.h>          // close(), read(), write(), usleep()
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <errno.h>
#include <signal.h>
#include <linux/spi/spidev.h>
#include <termios.h>         // podešavanje serijskih portova i tastature
#include <sys/select.h>
#include <string.h>          // strlen() - potrebno za RS232 test


/* I2C za Atlas-TPL_AO */
#define I2C_BUS_PATH        "/dev/i2c-0" // LTC2635 DAC-ovi
#define I2C_BUS_EXPANDERS  "/dev/i2c-2" // PCA9554 Ekspanderi

/* I2C adrese DAC-a */
#define DAC_I_OUT_ADDR      0x10    // DAC za strujne izlaze (+-20mA)
#define DAC_V_OUT_ADDR      0x52    // DAC za naponske izlaze (0-10V)

// #define I2C_MUX_ADDR        0x73


/* SPI za Atlas-TPL_AI */
#define SPI_DEVICE          "/dev/spidev0.0" // SPI putanja 


/* UART dAPV    */
#define RS232_UART_DEVICE "/dev/ttySS1"   // <-- PROVERI
#define RS232_BAUD B9600            


/* UART2 -> fiber optic TX/RX (U10/U11/U13 na COMM plocici) */
#define UART2_DEVICE         "/dev/ttySS2"
#define UART2_BAUD            B115200

/* Taster na TASTATURI koji okida LED3 test */
#define BLINK_KEY             'b'
#define SPI_SPEED           1000000          // 1 MHz brzina takta za test
#define SPI_BITS_PER_WORD   8
#define SPI_MODE            SPI_MODE_3
// #define CS_PIN              32

/* LTC2635 Komande */
#define CMD_INPUT           0x0     // Upis u input registar izabranog kanala (0000b)
#define CMD_COPY_UPDATE     0x1     // Kopira podatak iz inputa u DAC (0001b)
#define CMD_WRITE_INPUT     0x2     // Upis u izabrani input reg (0010b)
#define CMD_WRITE           0x3     // Upis i trenutno azuriranje izlaza (0011b)
#define CMD_POWER_DOWN      0x4     // Gasi izabrani DAC kanal (0100b
#define CMD_PD_CHIP         0x5     // Gasi sve DAC kanale i internu referencu (0101b)
#define CMD_INT_REF         0x6     // Izbor interne reference (0110b)
#define CMD_NO              0x7     // Bez operacije (0111b)

/* LTC2635 Adrese kanala */
#define CH_A                0x0     // Kanal 0 - A
#define CH_B                0x1     // Kanal 1 - B 
#define CH_C                0x2     // Kanal 2 - C
#define CH_D                0x3     // Kanal 3 - D
#define CH_ALL              0xF     // Svi kanali odjednom


/* Port Ekspanderi */
#define PCA9554_REG_INPUT   0x00    // registar za čitanje stanja ulaza
#define PCA9554_REG_OUTPUT  0x01    // registar za pisanje stanja izlaza
#define PCA9554_REG_POLAR   0x02
#define PCA9554_REG_CONFIG  0x03    // registar koji bira ko je ulaz a ko izlaz

/* Adrese port expandera */ 
#define ADDR_U4_DI   0x27  // U4  (A2=1, A1=1, A0=1)
#define ADDR_U8_DIO  0x26  // U8  (A2=1, A1=1, A0=0)
#define ADDR_U15_DO  0x23  // U15 (A2-0, A1=1, A0=0)


/* AD4130-8 Registri */
#define AD4130_REG_STATUS   0x00 // 1 bajt
#define AD4130_REG_ADC_CTRL 0x01 // 2 bajta
#define AD4130_REG_DATA     0x02 // 3 bajta
#define AD4130_REG_ID       0x05 // 1 bajt

#define AD4130_REG_MCLK_COUNT 0x08 // 1 bajt - broji otkucaje internog takta (dijagnostika)
#define AD4130_REG_ERROR_EN 0x07 // 2 bajta - MCLK_CNT_EN je bit 12 ovde


#define AD4130_REG_CH0      0x09  // Pocetni registar za Kanal 0 (CHANNEL_0..CHANNEL_15 su na 0x09-0x18)

/* Parametri za konverziju sirovog koda u napon (moraju odgovarati stvarnoj ADC_CTRL/CONFIG_0 konfiguraciji!) */
#define ADC_VREF        2.5    // Interna referenca, volti (INT_REF_VAL=0 => 2.5V)
#define ADC_GAIN        1      // PGA gain (CONFIG_0 PGA_n=000 => gain=1)

/**
 * @brief Konvertuje sirovi 24-bitni ADC kod u napon (V) na samom ADC ulazu (AINP-AINM).
 *        Racuna po formuli za BIPOLARNI mod (ADC_CONTROL bit14=1):
 *        Vin = ((Code / 2^23) - 1) * Vref/Gain
 *        Za konverziju napona na Vin_x prikljucku pomnozi sa faktorom slabljenja  ~ 3.3V
 */
double adc_code_to_volts(uint32_t code) {
    return (((double)code / 8388608.0) - 1.0) * (ADC_VREF / ADC_GAIN);
}

/* Port expander funkcije za upis i citanje registara */

int pca9554_write_reg(int fd, uint8_t dev_addr, uint8_t reg, uint8_t val) {
    if (ioctl(fd, I2C_SLAVE, dev_addr) < 0) {
        perror("PCA9554 I2C_SLAVE adresa nije postavljena");
        return -1;
    }
    uint8_t buf[2] = {reg, val};    //[koji registar, koja vrednost]
    if (write(fd, buf, 2) != 2) {
        perror("Greska pri upisu u PCA9554 registar");
        return -1;
    }
    return 0;
}

int pca9554_read_reg(int fd, uint8_t dev_addr, uint8_t reg, uint8_t *val) {
    if (ioctl(fd, I2C_SLAVE, dev_addr) < 0) {
        perror("PCA9554 I2C_SLAVE adresa nije postavljena");
        return -1;
    }
    if (write(fd, &reg, 1) != 1) {
        perror("Greska pri slanju adrese PCA9554 registra");
        return -1;
    }
    if (read(fd, val, 1) != 1) {
        perror("Greska pri citanju iz PCA9554 registra");
        return -1;
    }
    return 0;
}




/**
 * @brief Slanje komande i podatka na LTC2635 DAC preko I2C magistrale
 * * @param fd File deskriptor otvorenog I2C uređaja
 * @param dev_addr 7-bitna I2C adresa ciljnog DAC-a
 * @param cmd 4-bitna komanda za LTC2635
 * @param chan 4-bitna adresa kanala
 * @param code 12-bitna digitalna vrednost (0 - 4095)
 * @return int 0 ako je uspešno, -1 u slučaju greške
 */


int dac_write(int fd, uint8_t dev_addr, uint8_t cmd, uint8_t chan, uint16_t code) {
    if (ioctl(fd, I2C_SLAVE, dev_addr) < 0) {
        perror("I2C_SLAVE adresa nije postavljena");
        return -1;
    }

    /* DAC je 12 bitni (0 - 4095) */
    if (code > 4095) {
        code = 4095;
    }

    /* Formatiranje bajtova za LTC2635:
     * Bajt 0: [COMMAND (4 bita) | CHANNEL ADDRESS (4 bita)]  C3-C0 | A3-A0
     * 16-bitni podatak je levo poravnat -> code << 4
     * Bajt 1: MSB (bita 11..4)
     * Bajt 2: LSB (bita 3..0) + 4 don't care bita
     */
    uint16_t data = (code & 0x0FFF) << 4;            // DAC ocekuje 16bit broj gde je korisno samo gornjih 12 bita
    
    uint8_t buf[3];
    buf[0] = ((cmd & 0x0F) << 4) | (chan & 0x0F);   // prvi bajt: komanda + kanal
    buf[1] = (uint8_t)((data >> 8) & 0xFF);         // gornjih 8 bita
    buf[2] = (uint8_t)(data & 0xFF);                // donjih 8 bita

    if (write(fd, buf, 3) != 3) {
        perror("Greska pri komunikaciji na I2C magistrali.");
        return -1;
    }

    return 0;
}

/**
 * @brief Inicijalizacija interne reference za LTC2635 DAC
 */
int dac_init_internal_ref(int fd, uint8_t dev_addr) {
    printf(" Postavljanje interne reference za DAC na adresi 0x%02X.\n", dev_addr);
    return dac_write(fd, dev_addr, CMD_INT_REF, CH_ALL, 0);
}

/**
 * @brief Otvara i konfigurise UART2 (fiber optic TX preko U10/U11, RX preko U13)
 *        Ekvivalent komandi u terminalu:
 *        stty -F /dev/ttySS2 115200 cs8 -cstopb -parenb -crtscts raw -echo -ixon -ixoff clocal
 * @return file descriptor ili -1 u slucaju greske
 */
int uart2_open(void) {
    int fd = open(UART2_DEVICE, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("Ne mogu da otvorim " UART2_DEVICE);
        return -1;
    }

    struct termios tty;                  // termios je paket promenljivih koja opisuje sva podesavanja serijskog porta - brzinu, br. bita, parnost itd
    if (tcgetattr(fd, &tty) != 0) {      // procitaj trenutna podesavanja porta u promenljivu tty
        perror("tcgetattr UART2");
        close(fd);
        return -1;
    }

    cfmakeraw(&tty);                    // postavi raw mod: bez obrade karaktera (ekvivalent 'raw -echo')
    cfsetispeed(&tty, UART2_BAUD);      // brzina za prijem tj. input speed
    cfsetospeed(&tty, UART2_BAUD);      // brzina za slanje tj. output speed

    tty.c_cflag &= ~PARENB;             // bez parnosti     (-parenb)
    tty.c_cflag &= ~CSTOPB;             // 1 stop bit       (-cstopb)
    tty.c_cflag &= ~CSIZE;              // prvo obrisemo postojece podesavanje velicine karaktera
    tty.c_cflag |= CS8;                 // postavljamo 8 bita po karakteru (cs8)
    tty.c_cflag &= ~CRTSCTS;            // bez hardverskog flow control (-crtscts)
    tty.c_cflag |= (CLOCAL | CREAD);    // ignorisi modem linije, ukljuci prijem (clocal)
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // bez softverskog flow control (-ixon -ixoff)

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {        // TCSANOW - change attributes immediately
        perror("tcsetattr UART2"); 
        close(fd);
        return -1;
    }

    return fd;
}



/**
 * @brief Otvara i konfigurise RS232 (UART1, kanal A na COMM plocici, ka dAPV-p slave uredjaju)
 *        Isti princip kao uart2_open(), samo drugi uredjaj/baud.
 * @return file descriptor ili -1 u slucaju greske
 */
int rs232_uart_open(void) {
    int fd = open(RS232_UART_DEVICE, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("Ne mogu da otvorim " RS232_UART_DEVICE);
        return -1;
    }

    struct termios tty;
    if (tcgetattr(fd, &tty) != 0) {
        perror("tcgetattr RS232");
        close(fd);
        return -1;
    }

    cfmakeraw(&tty);
    cfsetispeed(&tty, RS232_BAUD);
    cfsetospeed(&tty, RS232_BAUD);

    tty.c_cflag &= ~PARENB;             // bez parnosti (podesi ako dAPV-p trazi drugacije)
    tty.c_cflag &= ~CSTOPB;             // 1 stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;                 // 8 data bita
    tty.c_cflag &= ~CRTSCTS;            // bez hardverskog flow control
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);

    // VMIN/VTIME: ne blokiraj citanje zauvek - vrati se posle 1s ako dAPV-p ne odgovori
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 10;   // 10 * 0.1s = 1s timeout

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("tcsetattr RS232");
        close(fd);
        return -1;
    }

    return fd;
}



/**
 * @brief Salje test poruku ka dAPV-p preko RS232 (UART1) i ispisuje sta stigne nazad.
 *        NAPOMENA: "TEST\r\n" je samo POCETNI test da li fizicka veza uopste radi
 *        (da li dAPV-p bilo cim reaguje). Ako dAPV-p koristi Modbus RTU ili neki
 *        drugi binarni protokol, ovo treba zameniti odgovarajucim frejmom kad se
 *        utvrdi tacan format iz dAPV-p dokumentacije.
 */
void rs232_test(int fd) {
    const char *test_msg = "TEST\r\n";
    ssize_t written = write(fd, test_msg, strlen(test_msg));
    if (written < 0) {
        perror("Greska pri upisu na RS232");
        return;
    }
    printf("[RS232] >> Poslato: %s", test_msg);

    char rx_buf[256];
    int n = read(fd, rx_buf, sizeof(rx_buf) - 1);
    if (n > 0) {
        rx_buf[n] = '\0';
        printf("[RS232] << Primljeno (%d B): %s\n", n, rx_buf);
    } else {
        printf("[RS232] Nema odgovora od dAPV-p (proveri fizicku vezu, baud rate, ili protokol).\n");
    }
}


/**
 * @brief Salje test-obrazac (0x55 = "U", maksimalna ucestalost 1/0 prelaza)
 *        preko UART2 -> pali LED3 
 */
void uart2_blink_test(int fd) {
    static const char pattern[] = "UUUUUUUU";
    ssize_t written = write(fd, pattern, sizeof(pattern) - 1);
    if (written < 0) {
        perror("Greska pri upisu na UART2");
    }
}

/* Cuvamo originalna podesavanja terminala da ih vratimo pri izlasku iz programa */
static struct termios orig_stdin_termios;

/**
 * @brief Handler za Ctrl+C (SIGINT) - vraca terminal u normalan mod pre izlaska,
 *        inace bi terminal ostao "zaglavljen" bez echo-a posle gasenja programa.
 */
void sigint_handler(int signum) {
    (void)signum;
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_stdin_termios);      // vrati tastaturu u normalu
    printf("\nPrekinut rad. \n");
    exit(EXIT_SUCCESS);
}

/**
 * @brief Prebacuje stdin (tastaturu) u raw/non-canonical mod, bez lokalnog echo-a,
 *        tako da se taster registruje odmah (bez cekanja na Enter).
 *        Mora se pozvati keyboard_restore() pre izlaska iz programa!
 */
void keyboard_raw_mode(void) {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &orig_stdin_termios);
    raw = orig_stdin_termios;
    raw.c_lflag &= ~(ICANON | ECHO); // bez cekanja na Enter, bez ispisivanja pritisnutog tastera
    raw.c_cc[VMIN] = 0;              // read() se ne blokira ako nema unosa
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

/** @brief Vraca terminal u normalan (kanonicki) mod */
void keyboard_restore(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_stdin_termios);
}

/**
 * @brief Proverava da li je pritisnut BLINK_KEY, bez blokiranja programa.
 * @return 1 ako je BLINK_KEY pritisnut ovog ciklusa, inace 0
 */
int keyboard_blink_requested(void) {
    fd_set fds;
    struct timeval tv = {0, 0};     // timeout 0 = samo trenutna provera, ne cekaj
    FD_ZERO(&fds);                  // isprazni skup fajl-deskriptora
    FD_SET(STDIN_FILENO, &fds);     // dodaj "tastaturu" u taj skup

    if (select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0) {      // select() vraca >0 SAMO ako ima nešto spremno za citanje
        char c;
        if (read(STDIN_FILENO, &c, 1) == 1 && c == BLINK_KEY) {
            return 1;
        }
    }
    return 0;
}


/* Postavi na 0 da iskljucis ispis sirovih SPI bajtova (MOSI/MISO) na svaki transfer, 1 je za debug mode */
#define SPI_DEBUG 1
int i = 0;

/**
 * @brief Ispisuje niz bajtova u heksadecimalnom obliku, sa oznakom (MOSI/MISO...)
 */
void spi_hexdump(const char *label, const uint8_t *buf, int len) {
    printf("    %-6s [%d B]: ", label, len);
    for (i = 0; i < len; i++) {
        printf("%02X ", buf[i]);
    }
    printf("\n");
}

/**
 * @brief Pomocna funkcija za SPI transfer za AD4130-8
 * 
 * 
 */

int spi_transfer(int fd, uint8_t *tx, uint8_t *rx, int len) {
    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)tx,
        .rx_buf = (unsigned long)rx,
        .len = len,
        .speed_hz = SPI_SPEED,
        .delay_usecs = 0,
        .bits_per_word = 8,
        .cs_change = 0, 
    };

#if SPI_DEBUG
    spi_hexdump("MOSI ->", tx, len);     // ako debugujemo, ispisi sta se salje
#endif

    if (ioctl(fd, SPI_IOC_MESSAGE(1), &tr) < 1) {
        perror("Greška pri SPI transferu");
        return -1;
    }

#if SPI_DEBUG
    spi_hexdump("MISO <-", rx, len);    // ako debugujemo, ispisi sta se prima
#endif

    return 0;
}


/* Softverski reset: Slanje 64 uzastopne jedinice (8 bajtova 0xFF) */
void ad4130_soft_reset(int fd) {
    uint8_t tx[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t rx[8] = {0};
    spi_transfer(fd, tx, rx, 8);
    printf("Softverski reset. \n");
    usleep(5000); 
}

/* Citanje registra sa AD4130 */
int idx = 0;
uint32_t ad4130_read_reg(int fd, uint8_t reg_addr, int reg_len) {
    uint8_t tx[5] = {0};
    uint8_t rx[5] = {0};
    
    // Bajt 0: COMMS komanda -> Bit 6 = 1 (Citanje)
    tx[0] = 0x40 | (reg_addr & 0x3F);
    
    if (spi_transfer(fd, tx, rx, 1 + reg_len) < 0) return 0;
    
    uint32_t result = 0;
    for (idx = 0; idx < reg_len; idx++) {
        result = (result << 8) | rx[1 + idx];   
    }
    return result;
}

/* Upis u registar AD4130 */
int ad4130_write_reg(int fd, uint8_t reg_addr, uint32_t val, int reg_len) {
    uint8_t tx[8] = {0};
    uint8_t rx[8] = {0};
    
    // Bajt 0: COMMS komanda -> Bit 6 = 0 (Upis)
    tx[0] = 0x00 | (reg_addr & 0x3F);
    
    for (idx = 0; idx < reg_len; idx++) {
        tx[1 + idx] = (val >> (8 * (reg_len - 1 - idx))) & 0xFF;
    }
    
    return spi_transfer(fd, tx, rx, 1 + reg_len);
}



int main(int argc, char *argv[]) {
    // Zadati testni DAC kod preko argumenta komandne linije (npr. ./dac_us 2048)
    // Ako nije zadato, podrazumevano 0 (0V/0mA)

    uint16_t napon_kod_test = 0;
    if (argc > 1) {
        int uneto = atoi(argv[1]);          // pretvori tekst (npr "2048") u broj
        if (uneto < 0) uneto = 0;
        if (uneto > 4095) uneto = 4095;     // 12-bit DAC max
        napon_kod_test = (uint16_t)uneto;
        printf("Testni DAC kod zadat preko argumenta: %d\n", napon_kod_test);
    }
    int i2c_fd, i2c_exp_fd;
    uint8_t val = 0;
    int spi_fd;
    int uart2_fd;
    int rs232_fd;
    uint8_t mode = SPI_MODE_3;              // Mode 3 je za AD4130
    uint8_t bits = SPI_BITS_PER_WORD;
    uint32_t speed = SPI_SPEED;
    int ch = 0;

    // Pracenje promena na digital inputs
    uint8_t prev_u4_val = 0xFF;  // Za DI1 - DI8
    uint8_t prev_u8_val = 0xFF;  // Za DI9 i DI10

    /* Otvaranje I2C-0 magistrale (DAC) */
    i2c_fd = open(I2C_BUS_PATH, O_RDWR);
    if (i2c_fd < 0) {
        perror("Greska sa I2C magistralom." I2C_BUS_PATH);
        return EXIT_FAILURE;
    }

    /* Otvaranje I2C-2 magistrale (Ekspanderi) */
    i2c_exp_fd = open(I2C_BUS_EXPANDERS, O_RDWR);
    if (i2c_exp_fd < 0) {
        perror("Greska pri otvaranju " I2C_BUS_EXPANDERS);
        close(i2c_fd);
        return EXIT_FAILURE;
    }

    /* Otvaranje SPI drajvera */
    spi_fd = open(SPI_DEVICE, O_RDWR);
    if (spi_fd < 0) {
        perror("Ne mogu da otvorim SPI uredjaj " SPI_DEVICE);
        close(i2c_fd);
        close(i2c_exp_fd);
        return EXIT_FAILURE;
    }

    /* Otvaranje UART2 (fiber optic TX/RX - LED3/LED4 indikatori) */
    uart2_fd = uart2_open();
    if (uart2_fd < 0) {
        printf("UART2 nije otvoren \n");
        }

    /* Otvaranje RS232 (UART1 - COMM plocica, kanal A, ka dAPV-p slave uredjaju) */
    rs232_fd = rs232_uart_open();
    if (rs232_fd < 0) {
        printf("RS232 (UART1) nije otvoren \n");
        }


    keyboard_raw_mode();
    signal(SIGINT, sigint_handler);
    printf("Pritisni '%c' u bilo kom trenutku da upalis LED3 blink test.\n\n", BLINK_KEY);

    /* Konfiguracija SPI magistrale */
    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &mode) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        perror("Greska pri podešavanju SPI parametara");
        close(spi_fd);
        return EXIT_FAILURE;
    }
    /* Inicijalizacija periferija */

    // Softverski reset
    ad4130_soft_reset(spi_fd);

    // uint8_t tx_debug[2] = {0};
    // uint8_t rx_debug[2] = {0};
    
    // tx_debug[0] = 0x40 | (AD4130_REG_ID & 0x3F); // Komanda za citanje ID registra
    // tx_debug[1] = 0x00;                          // dummy bajt
    
    // Pokrecemo transfer duzine 3 bajta (1 komanda + 1 bajt za ID registar)
    //spi_transfer(spi_fd, tx_debug, rx_debug, 2);
    
    // Standardno citanje ID-a
    uint8_t chip_id = (uint8_t)ad4130_read_reg(spi_fd, AD4130_REG_ID, 1);

//     printf("[SPI DEBUG]\n");
//     printf("  Bajt 0 (Odgovor na komandu): 0x%02X\n", rx_debug[0]);
//     printf("  Bajt 1 (Prvi bajt podatka):  0x%02X\n", rx_debug[1]);
//    //printf("  Bajt 2 (Drugi bajt podatka): 0x%02X\n", rx_debug[2]);
//     printf("---------------------------------------------------\n");
    printf("Procitani ID ADC registra: 0x%02X\n", chip_id);



    // DIJAGNOSTIKA TAKTA: ukljuci MCLK brojac (bit 12 u ERROR_EN), procitaj ga dvaput
    // sa pauzom - ako se vrednost NE menja, interni oscilator/takt ne radi (nista se
    // onda ne moze konvertovati, RDYB nikad nece pasti na 0).
    ad4130_write_reg(spi_fd, AD4130_REG_ERROR_EN, 0x1000, 2); // bit12 = MCLK_CNT_EN
    uint8_t mclk1 = (uint8_t)ad4130_read_reg(spi_fd, AD4130_REG_MCLK_COUNT, 1);
    usleep(50000); // 50ms pauza
    uint8_t mclk2 = (uint8_t)ad4130_read_reg(spi_fd, AD4130_REG_MCLK_COUNT, 1);
    printf("DIJAGNOSTIKA TAKTA: MCLK_COUNT prvo citanje=0x%02X, drugo (posle 50ms)=0x%02X %s\n",
           mclk1, mclk2,
           (mclk1 != mclk2) ? "-> TAKT RADI (vrednost se promenila)" : "-> UPOZORENJE: TAKT SE NE MENJA!");




    // Konfiguracija 8 kanala (4 Naponska + 4 Strujna ulaza)
    //
    // Mapiranje:
    //   CH0 -> Vin1 : AINP=AIN0,  AINN=AVSS       (single-ended)
    //   CH1 -> Vin2 : AINP=AIN1,  AINN=AVSS       (single-ended)
    //   CH2 -> Vin3 : AINP=AIN3,  AINN=AVSS       
    //   CH3 -> Vin4 : AINP=AIN2,  AINN=AVSS
    //   CH4 -> Iin1 : AINP=AIN4,  AINN=AIN5       (diferencijalni par AI_P1/AI_N1)
    //   CH5 -> Iin2 : AINP=AIN6,  AINN=AIN7       (AI_P2/AI_N2)
    //   CH6 -> Iin3 : AINP=AIN8,  AINN=AIN9       (AI_P3/AI_N3)
    //   CH7 -> Iin4 : AINP=AIN10, AINN=AIN11      (AI_P4/AI_N4)
    //
    // CHANNEL_m je 24-bitni registar (3 bajta), adrese 0x09-0x18.
    // AINM=AVSS (0x11) iz datasheeta .. analogna masa je negativni ulaz ADC-a; ADC meri AINP - AVSS

    #define ADC_AIN_AVSS 0x11
    static const uint8_t ch_ainp[8] = {0, 1, 3, 2, 4,  6,  8,  10};
    static const uint8_t ch_ainm[8] = {ADC_AIN_AVSS, ADC_AIN_AVSS, ADC_AIN_AVSS, ADC_AIN_AVSS,
                                        5,  7,  9,  11};

    // Postavi na broj kanala (0-7) da ADC konvertuje samo taj kanal. Postavi na -1 za
    // normalan rad (svih 8 kanala u rotaciji).
    #define SINGLE_CHANNEL_TEST 1   // 7 = Iin4 (izolovano testiranje sa strujnim generatorom na J5)

    for (ch = 0; ch < 8; ch++) {
        uint32_t enable_bit = (SINGLE_CHANNEL_TEST < 0 || ch == SINGLE_CHANNEL_TEST) ? 1 : 0;
        uint32_t ch_config = (enable_bit << 23) |            // Bit 23: ENABLE_m
                             (0UL << 20) |                   // Bits 22-20: SETUP_m = 0 (Setup 0)
                             (0UL << 19) |                   // Bit 19: PDSW_m = 0
                             (0UL << 18) |                   // Bit 18: THRES_EN_m = 0
                             ((uint32_t)ch_ainp[ch] << 13) | // Bits 17-13: AINP_m
                             ((uint32_t)ch_ainm[ch] << 8);   // Bits 12-8: AINM_m

        // Upisujemo konfiguraciju u registre kanala (svaki sledeci registar je na adresi +1), 3 bajta (24-bit)
        ad4130_write_reg(spi_fd, AD4130_REG_CH0 + ch, ch_config, 3);
    
    // VERIFIKACIJA UPISA - procitaj CHANNEL_m nazad, uporedi sa onim sto je poslato
        {
            uint32_t readback = ad4130_read_reg(spi_fd, AD4130_REG_CH0 + ch, 3);
            if (readback != ch_config) {
                printf("  [CH%d] Ne podudara se: poslato 0x%06X, procitano nazad 0x%06X. \n",
                       ch, ch_config, readback);
            } else if (enable_bit == 1) {
                printf("  [CH%d] Verifikovano: 0x%06X. \n", ch, readback);
            }
        }
    }

    if (SINGLE_CHANNEL_TEST >= 0) {
        printf("Samo je kanal %d aktivan (izolovano testiranje) - ostalih 7 iskljuceno.\n", SINGLE_CHANNEL_TEST);
    } else {
        printf("Svih 8 kanala (CH0-CH7) uspesno konfigurisano.\n");
    }

    // Konfiguracija Setup 0 (CONFIG_0, adresa 0x19) - koriste je svi nasi kanali (SETUP_m=0)
    // Bits [5:4] REF_SEL_n = 10 (REFOUT, AVSS - interna referenca), PGA gain = 1 (bypass)
    #define AD4130_REG_CONFIG0 0x19
    ad4130_write_reg(spi_fd, AD4130_REG_CONFIG0, 0x0020, 2);

    // VERIFIKACIJA UPISA - procitaj CONFIG_0 nazad i uporedi sa onim sto smo poslale.
    {
        uint32_t readback = ad4130_read_reg(spi_fd, AD4130_REG_CONFIG0, 2);
        printf("Proveravanje CONFIG_0: poslato 0x0020, procitano nazad 0x%04X %s\n",
               readback, (readback == 0x0020) ? "-> OK" : "-> Not OK");
    }



    // Pokretanje kontinualnog rezima konverzije u ADC_CTRL registru
    // Bit 14 = BIPOLAR (1 = bipolarno kodiranje: 0x000000=-Vref/gain, 0x800000=0V, 0xFFFFFF=+Vref/gain)
    //          ovo je globalni bit, vazi za SVE kanale (i naponske i strujne)
    // Bit 13 = INT_REF_VAL (0 = 2.5V interna referenca, 1 = 1.25V) - ostaje 0 => 2.5V
    // Bit 10 = DATA_STATUS (1 = status bajt se lepi na kraj DATA registra pri citanju)
    // Bit 8  = INT_REF_EN  (1 = ukljucuje internu referencu)
    // Bits 5-2 (MODE) = 0000 (Continuous Conversion Mode, vec je default)
    ad4130_write_reg(spi_fd, AD4130_REG_ADC_CTRL, 0x0500, 2);


    // VERIFIKACIJA UPISA - isto za ADC_CTRL
    {
        uint32_t readback = ad4130_read_reg(spi_fd, AD4130_REG_ADC_CTRL, 2);
        printf("Verifikacija ADC_CTRL: poslato 0x4500, procitano nazad 0x%04X %s\n",
               readback, (readback == 0x4500) ? "-> OK" : "-> Not OK");
    }


    /* Port expanderi */

    pca9554_write_reg(i2c_exp_fd, ADDR_U4_DI, PCA9554_REG_CONFIG, 0xFF);            // U4: Svi ulazi
    pca9554_write_reg(i2c_exp_fd, ADDR_U8_DIO, PCA9554_REG_CONFIG, 0b11001111);           // U8: IO0,1 ulazi (DI9, DI10); IO4,5 izlazi (DO9, DO10)
    pca9554_write_reg(i2c_exp_fd, ADDR_U15_DO, PCA9554_REG_CONFIG, 0x00);           // U15: Svi izlazi
    printf("Port ekspanderi (U4, U8, U15) su konfigurisani.\n");

    /* DAC (LTC2635)*/

    dac_init_internal_ref(i2c_fd, DAC_I_OUT_ADDR);
    dac_init_internal_ref(i2c_fd, DAC_V_OUT_ADDR);
    printf("DAC reference postavljene.\n\n");



while (1) {
        //  PROVERA ADC-a (SPI)
        if (spi_fd >= 0) {
        // Citamo 4 bajta odjednom (3 bajta DATA + 1 bajt STATUS)
        //uint32_t raw_read = ad4130_read_reg(spi_fd, AD4130_REG_DATA, 4);

        uint32_t raw_read;
        int pokusaji = 0;
        do {
            raw_read = ad4130_read_reg(spi_fd, AD4130_REG_DATA, 4);
            pokusaji++;
            if (raw_read & 0x80) {
                usleep(2000); // 2ms pauza izmedju pokusaja - ukupno do 2000*2ms = 4 sekunde strpljenja
            }
        } while ((raw_read & 0x80) && pokusaji < 2000);

        if (raw_read & 0x80) {
            printf("UPOZORENJE: RDYB i dalje 1 posle %d pokusaja (~%d ms cekanja) - preskacem ovaj ciklus.\n",
                   pokusaji, pokusaji * 2);
        } else {
            if (pokusaji > 1) {
                printf("(RDYB se oslobodio posle %d pokusaja, ~%d ms)\n", pokusaji, pokusaji * 2);
            }
        uint32_t adc_data = (raw_read >> 8) & 0xFFFFFF;
        uint8_t adc_status = raw_read & 0xFF;
        uint8_t kanal = adc_status & 0x0F;


 
        if (kanal < 4) {
            double v_adc = adc_code_to_volts(adc_data);
            double v_ulaz = v_adc * 4.3;
            printf("[ADC] Naponski ulaz Vin%d | Kod: %d (0x%06X) | ADC ulaz: %.4f V | ADC ulaz * 4.3: %.4f V\n",
                   kanal + 1, adc_data, adc_data, v_adc, v_ulaz);
        } else if (kanal >= 4 && kanal < 8) {
            double v_adc = adc_code_to_volts(adc_data);
            printf("[ADC] Strujni ulaz Iin%d  | Kod: %d (0x%06X) | ADC ulaz: %.4f V\n",
                   (kanal - 4) + 1, adc_data, adc_data, v_adc);
        }
        } // kraj else (RDYB je bio 0, podatak svez)
    }



        
        // // Razdvajamo podatke i status
        // uint32_t adc_data = (raw_read >> 8) & 0xFFFFFF; // Gornja 3 bajta su 24-bitni podatak
        // uint8_t adc_status = raw_read & 0xFF;           // Najnizi bajt je Status

        // // Donja 4 bita statusnog registra nam govore sa kog tacno kanala je stigao uzorak
        // uint8_t kanal = adc_status & 0x0F;

    //     if (kanal < 4) {
    //         // Kanali 0, 1, 2, 3 odgovaraju Vin1, Vin2, Vin3, Vin4
    //         double v_adc = adc_code_to_volts(adc_data);       // Napon na samom ADC ulazu (posle slabljenja ploce)
    //         double v_ulaz = v_adc * 4.3;                       // Procenjeni stvarni napon na Vin konektoru (slabljenje 4.3x)
    //         printf("[ADC] Naponski ulaz Vin%d | Kod: %d (0x%06X) | ADC ulaz: %.4f V | ADC ulaz * 4.3: %.4f V\n",
    //                kanal + 1, adc_data, adc_data, v_adc, v_ulaz);
    //     } else if (kanal >= 4 && kanal < 8) {
    //         // Kanali 4, 5, 6, 7 odgovaraju strujnim ulazima Iin1, Iin2, Iin3, Iin4
    //         double v_adc = adc_code_to_volts(adc_data);
    //         printf("[ADC] Strujni ulaz Iin%d  | Kod: %d (0x%06X) | ADC ulaz: %.4f V\n",
    //                (kanal - 4) + 1, adc_data, adc_data, v_adc);
    //     }
    // }


        int i = 0;
        uint8_t ch = 0;

        // PROVERA PORT EKSPANDERA U4 (DI1 - DI8)
        
        // if (pca9554_read_reg(i2c_exp_fd, ADDR_U4_DI, PCA9554_REG_INPUT, &val) == 0) {
        //     if (val != prev_u4_val) { // Ispis samo ako se promeni bilo koji DI1-DI8 taster/pin
        //         printf("[U4 PROMENA] Novo stanje: 0x%02X -> ", val);
        //         for (i = 0; i < 8; i++) {
        //             printf("DI%d=%d ", i + 1, (val & (1 << i)) ? 1 : 0);
        //         }
        //         printf("\n");
        //         prev_u4_val = val;
        //     }
        // }

        
        // // PROVERA PORT EKSPANDERA U8 (DI9 i DI10)

        // if (pca9554_read_reg(i2c_exp_fd, ADDR_U8_DIO, PCA9554_REG_INPUT, &val) == 0) {
        //     uint8_t trenutni_ulazi = val & 0x03; // Maskiramo samo prva dva bita (IO0 i IO1)
            
        //     if (trenutni_ulazi != (prev_u8_val & 0x03)) { // Ispis samo pri promeni stanja DI9 ili DI10
        //         uint8_t di9_stanje  = (val & (1 << 0)) ? 1 : 0;
        //         uint8_t di10_stanje = (val & (1 << 1)) ? 1 : 0;
        //         printf("[U8 PROMENA] Novo stanje -> DI9 (IO0) = %d, DI10 (IO1) = %d\n", di9_stanje, di10_stanje);
        //         prev_u8_val = val;
        //     }
        // }
        // // Odrzavanje izlaza DO9 i DO10 (Pinovi IO4 i IO5 na U8 postavljeni na HIGH)
        // pca9554_write_reg(i2c_exp_fd, ADDR_U8_DIO, PCA9554_REG_OUTPUT, 0x30);

        // PROVERA PORT EKSPANDERA U15 (DO1 - DO8)

        // // Ovde rucno kontrolisemo sta je upaljeno od izlaza na U15 modulu (0xFF pali sve)
        // uint8_t do_test_mask = 0xFF; 
        // pca9554_write_reg(i2c_exp_fd, ADDR_U15_DO, PCA9554_REG_OUTPUT, do_test_mask);

        // PROVERA DAC KONVERTORA (I2C-0)

        // Strujni izlazi (DAC_I_OUT) -> kod 0 postavlja 1.25V (odgovara 0mA)
        for (ch = 0; ch < 4; ch++) {
            dac_write(i2c_fd, DAC_I_OUT_ADDR, CMD_WRITE, ch, 0);
        }

        // Naponski izlazi (DAC_V_OUT) 
        // Kod 0 = 0V | Kod 2048 = 5V | Kod 4095 = 10V
        uint16_t napon_kod_v = napon_kod_test; // Zadati testni kod (iz argumenta komandne linije, ili 0 ako nije zadat)
        
        dac_write(i2c_fd, DAC_V_OUT_ADDR, CMD_WRITE, CH_A, napon_kod_v); // Glavni testni izlaz (J3)
        dac_write(i2c_fd, DAC_V_OUT_ADDR, CMD_WRITE, CH_B, 0);           // Ostali kanali
        dac_write(i2c_fd, DAC_V_OUT_ADDR, CMD_WRITE, CH_C, 0);
        dac_write(i2c_fd, DAC_V_OUT_ADDR, CMD_WRITE, CH_D, 0);

        printf("[DAC] Osvezen naponski izlaz CH_A na kod %d\n", napon_kod_v);
        {
            // Procena ocekivanog izlaznog napona na VOUT1 konektoru:
            // DAC: Vdac = kod/4096 * 2.5V (interna referenca)
            // Izlazni op-amp (U9A): gain = 1 + R38/R37 = 1 + 33k/10k = 4.3
            double v_dac = (napon_kod_v / 4096.0) * 2.5;
            double v_ocekivano = v_dac * 4.3;
            printf("[DAC] Ocekivan napon na VOUT1: ~%.3f V\n", v_ocekivano);
        }

        // PROVERA UART2 / OPTICKOG PREDAJNIKA (LED3 treperi svaki ciklus dok radi test)
        if (uart2_fd >= 0) {
            uart2_blink_test(uart2_fd);
        }

        /* LED3 treperi SAMO na pritisak BLINK_KEY tastera. Otkomentarisati ako zatreba:

        if (uart2_fd >= 0 && keyboard_blink_requested()) {
            printf("[UART2] '%c' pritisnut -> saljem test-obrazac (LED3 treba da zatrepce)\n", BLINK_KEY);
            uart2_blink_test(uart2_fd);
        }

        */

        
        // PROVERA RS232 (UART1 -> COMM plocica -> dAPV-p slave uredjaj)
        if (rs232_fd >= 0) {
            rs232_test(rs232_fd);
        }
        
       // usleep(250000); // Provera celog hardverskog sklopa 4 puta u sekundi
    }

    /* Zatvaranje I2C magistrale */
    close(i2c_fd);
    close(i2c_exp_fd);
    close(spi_fd);
    if (uart2_fd >= 0) {
        close(uart2_fd);
    }
    if (rs232_fd >= 0) {
        close(rs232_fd);
    }
    keyboard_restore();
    printf("\nTest uspesno zavrsen\n");

    return EXIT_SUCCESS;
}
