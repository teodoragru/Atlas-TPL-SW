/*

POSLEDNJA VERZIJA 22.5.2026. sadrzi generisanje sinusoide i njeno slanje na primar, 
sadrzi inicijalizaciju sekundara, citanje sta se nalazi na registrima demod1 i demod2 sa sekundara??
sadrzi registre za LPF i BPF, racunanje pozicije i faze
update: i2c magistrala i setovanje pinova IO4-6
PLUS POZIV I CITANJE IZ RAM-a
doodavanje i2c 2 i paljenje LED na TB, testiranje DI/DO radi
gsel postavljanje prvo na 0 pa na 1
ispravlejen NDS2 za izvlacenje faze, ispravljena read32_bit funkcija

kod pre modifikacije da se citaju tri razlicita broja sa demod2

*/



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <errno.h>
#include <linux/i2c-dev.h>
#include <arpa/inet.h>

// Inicijalizacija za SPI
#define SPI_PATH "/dev/spidev1.0"
#define PI 3.14159265358979323846 
#define CS_PIN 13

// Inicijalizacija za I2C-0 (PCA9554PW)
#define I2C_PATH_0         "/dev/i2c-0"
#define PCA9554_U15_ADDR        0x21  // U15
#define PCA9554_U13_ADDR        0x20
#define PCA_INPUT               0x00
#define PCA_OUTPUT              0x01
#define PCA_POLARITY            0x02
#define PCA_CONFIG              0x03

#define REN                     0x10
#define RA0                     0x20
#define RA1                     0x40
#define U15_GSEL_BIT            (1 << 1)

//Inicijalizacija za I2C-2 (CAT9555YI)
#define I2C_PATH_2         "/dev/i2c-2"
#define CAT9555YI_U4_ADDR       0x20 // DI/DO port expander
#define CAT9555YI_U5_ADDR       0x24 // LED diode port expander
#define CAT_INPUT_P0            0x00
#define CAT_INPUT_P1            0x01
#define CAT_OUTPUT_P0           0x02
#define CAT_OUTPUT_P1           0x03
#define CAT_CONFIG_P0           0x06
#define CAT_CONFIG_P1           0x07



// Adrese registara

#define REG_WAVEGEN_CTRL        0x78  // Page 2
#define REG_WAVEFORM_TABLE_LEN  0x7A  // Page 2
#define REG_DAC_OFFSET_LO       0x7C  // Page 2
#define REG_DAC_OFFSET_HI       0x7D  // Page 2
#define REG_ALPWR               0x50  // Page 2
#define REG_LVDT_OP_CTRL        0x3C  // Page 2
#define MICRO_INTERFACE_CONTROL 0x0C  // Page 0
#define REG_AMUX_CTRL           0x67  // Page 2
#define REG_LVDT_LPBK_CTRL      0x3D  // Page 2
#define DIG_IF_CTRL             0x06  // Page 2
#define DAC_CTRL_STATUS         0x38  // Page 2
#define OP_STAGE_CTRL           0x3B  // Page 2
#define S3_ADC_CFG_1            0x26  // Page 2
#define DATA_WAVE_PAGE_ADDR     0x19  // Page 2
#define AMUX_ACT                0x64  // Page 2
#define AMUX_TOUT_MUX_CTRL      0x66  // Page 2
#define DAC_LPBK_CTRL           0x3A  //Page 2



//Registri za sekundare S1 i S2
#define S1_CFG                  0x27  // Page 2
#define S2_CFG                  0x28  // Page 2
#define S1_S2_CFG               0x29  // Page 2
#define DEMOD1_CONFIG           0x20  // Page 2
#define DEMOD2_CONFIG           0x21  // Page 2
#define S1_S2_DEMOD_CFG_1       0x24  // Page 2
#define DEMOD1_DATA             0x10  // Page 0
#define DEMOD2_DATA             0x14  // Page 0

#define DEMOD1_BPF_B1           0x98  // Page 2
#define DEMOD1_BPF_A2           0x9C  // Page 2
#define DEMOD1_BPF_A3           0xA0  // Page 2
#define DEMOD1_LPF_B1           0xA4  // Page 2
#define DEMOD1_LPF_A2           0xA8  // Page 2

#define DEMOD2_BPF_B1           0xB4  // Page 2 
#define DEMOD2_BPF_A2           0xB8  // Page 2
#define DEMOD2_BPF_A3           0xBC  // Page 2
#define DEMOD2_LPF_B1           0xC0  // Page 2
#define DEMOD2_LPF_A2           0xC4  // Page 2

//Registri za informaciju o fazi
#define DAC_SIN_NDS1            0xE4  // Page 2
#define DAC_SIN_NDS2            0xE6  // Page 2
#define DEMOD1_PH1DATA          0x2C  // Page 0
#define DEMOD1_PH2DATA          0x30  // Page 0
#define DEMOD2_PH1DATA          0x34  // Page 0
#define DEMOD2_PH2DATA          0x38  // Page 0



// GPIO registri (Page 7)
#define REG_GPIO_OUTPUT         0x31
#define REG_GPIO_DIR            0x32
#define REG_GPIO_OTYPE          0x33
#define REG_PIN_MUX             0x40



uint8_t addr;
uint8_t data;
int cs_fd;
int ret; 
uint8_t rw;
int spi_fd;
int i2c0_fd;
int i2c2_fd;


static void pabort(const char *s)
{
	if (errno != 0)
		perror(s);
	else
		printf("%s\n", s);

	abort();
}

// I2C-0 transfer

void pca9554_write(int fd, uint8_t addr, uint8_t reg, uint8_t value) {
    
    if (ioctl(fd, I2C_SLAVE, addr) < 0) {
        perror("I2C-0 Slave Address Error");
        return;
    }

    uint8_t buf[2] = {reg, value};
    if (write(fd, buf, 2) != 2) {
        perror("I2C Write Error");
    }
}

void init_expander(int fd, uint8_t addr) {
    // 0x8F postavlja IO4,5,6 kao izlaze, ostali su ulazi
    pca9554_write(fd, addr, PCA_CONFIG, 0x00);
}


void set_gain_config(int fd, uint8_t addr, int ren, int ra0, int ra1, int gsel) {
    uint8_t val = 0xFF; 
    

    if (addr == PCA9554_U15_ADDR) {
        if (gsel) {
            val |= U15_GSEL_BIT;  // Postavi GSEL na 1
        } else {
            val &= ~U15_GSEL_BIT; // Postavi GSEL na 0
        }
    }

    if (!ren) val &= ~REN; 
    if (!ra0) val &= ~RA0;
    if (!ra1) val &= ~RA1;
    pca9554_write(fd, addr, PCA_OUTPUT, val);
}

//I2C-2 transfer

void cat9555_write(int fd, uint8_t addr, uint8_t reg, uint8_t value) {

    if (ioctl(fd, I2C_SLAVE, addr) < 0) {
        perror("I2C-2 Slave Address Error");
        return;
    }
        
    uint8_t buf[2] = {reg, value};
    if (write(fd, buf, 2) != 2) {
        perror("I2C Write Error on CAT9555");
    }
}

uint8_t cat9555_read(int fd, uint8_t addr, uint8_t reg) {
    if (ioctl(fd, I2C_SLAVE, addr) < 0) 
        return 0;
    write(fd, &reg, 1);

    uint8_t value;

    read(fd, &value, 1);
    return value;
}


// SPI transfer
int pga970_transfer(int spi_fd, uint8_t rw, uint8_t function, uint8_t addr, uint8_t data, uint8_t *rx_buf) {
    uint8_t tx[3];
    uint8_t rx[3] = {0};

    // ~The reads always happen at 16-bit aligned addresses, bit 13 always zero during reads
    uint16_t addr_to_send = addr;
    if (rw == 0) {
        addr_to_send &= ~(1 << 13); 
        addr_to_send &= ~0x01;      
    }

    // BAJT 0: [Func 23:21] | [Addr 20:16] 
    tx[0] = ((function & 0x07) << 5) | ((addr_to_send >> 3) & 0x1F);

    // BAJT 1: [Addr 15:13] | [RW] (12) | [Data 11:8]
    tx[1] = ((addr_to_send & 0x07) << 5) | ((rw & 0x01) << 4) | ((data >> 4) & 0x0F);

    // BAJT 2: [Data 7:4] | [Don't care] (3:0)
    tx[2] = (data & 0x0F) << 4;

    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)tx,
        .rx_buf = (unsigned long)rx,
        .len = 3,
        .delay_usecs = 10,
        .speed_hz = 100000,
        .bits_per_word = 8,
    };

    gpio_write(CS_PIN, 0); 
    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &tr);   
    gpio_write(CS_PIN, 1);


    if (rx_buf != NULL) {
        rx_buf[0] = rx[0]; rx_buf[1] = rx[1]; rx_buf[2] = rx[2];
    }

    //if (!(function == 0x1)){
     //  printf("SPI TX (MOSI): 0x%02X 0x%02X 0x%02X | SPI RX (MISO): 0x%02X 0x%02X 0x%02X \n", tx[0], tx[1], tx[2], rx[0], rx[1], rx[2]);}
  //  return 0;
}


uint32_t read_32bit(int spi_fd, uint8_t func, uint8_t base_addr)
{
    uint8_t rx[3];

    uint8_t b0, b1, b2, b3;

    // Čitanje base_addr i base_addr+1
    pga970_transfer(spi_fd, 0, func, base_addr, 0x00, NULL);
    pga970_transfer(spi_fd, 0, func, base_addr, 0x00, rx);

    b3 = rx[1];   // ADDR       
    b2 = rx[2];   // ADDR + 1

    // Čitanje base_addr+2 i base_addr+3
    pga970_transfer(spi_fd, 0, func, base_addr + 2, 0x00, NULL);
    pga970_transfer(spi_fd, 0, func, base_addr + 2, 0x00, rx);

    b1 = rx[1];   // ADDR + 2
    b0 = rx[2];   // ADDR + 3       MSB

    uint32_t value =
        ((uint32_t)b3 << 24) |
        ((uint32_t)b2 << 16) |
        ((uint32_t)b1 << 8)  |
        ((uint32_t)b0);


    return value;
}

// Upis i citanje
void write_and_verify(int fd, uint8_t func, uint8_t addr, uint8_t data, const char* name) {
    uint8_t rx[3] = {0};
    
    //Upis, rw == 1
    pga970_transfer(fd, 1, func, addr, data, NULL);
    //usleep(100); 
    
    // Prvo citanje, rw ==0 
    pga970_transfer(fd, 0, func, addr, 0x00, NULL);
    
    // Dummy read
    pga970_transfer(fd, 0, func, addr, 0x00, rx);
    
    // printf("DEBUG [%s] @ Addr 0x%02X: Sent 0x%02X | Recieved: %02X %02X %02X\n", 
    //        name, addr, data, rx[0], rx[1], rx[2]);
    
    // if (rx[1] == data) {
    //     printf("OK\n");
    // } else {
    //     printf("ERROR (Expected in rx[1] 0x%02X, got 0x%02X)\n", data, rx[1]);
    // }
}


void write_16bit(int fd, uint8_t func, uint8_t addr, uint16_t val, const char* name)
{
    write_and_verify(fd, func, addr,     (val >> 8) & 0xFF, name);
    write_and_verify(fd, func, addr + 1,  val       & 0xFF, name);
}

// void write_24bit(int fd, uint8_t func, uint8_t addr, uint32_t val, const char* name) //24 bit
// {
//     uint8_t b0 = val & 0xFF;         // LSB
//     uint8_t b1 = (val >> 8) & 0xFF;  // MID
//     uint8_t b2 = (val >> 16) & 0xFF; // MSB

//     write_and_verify(fd, func, addr, b0, name);
//     write_and_verify(fd, func, addr + 1, b1, name);
//     write_and_verify(fd, func, addr + 2, b2, name);
// }


void write_24bit(int fd, uint8_t func, uint8_t addr, uint32_t val, const char* name) {
    uint8_t b2 = (val >> 16) & 0xFF; // MSB ide prvi
    uint8_t b1 = (val >> 8) & 0xFF;  // MID
    uint8_t b0 = val & 0xFF;         // LSB ide zadnji

    write_and_verify(fd, func, addr, b2, name);
    write_and_verify(fd, func, addr + 1, b1, name);
    write_and_verify(fd, func, addr + 2, b0, name);
}


void readback_waveform_ram(int fd, int num_samples)
{
    uint8_t rx[3] = {0};
    int n = 0;

    printf("\n--- WAVEFORM RAM READBACK ---\n");

    // Waveform RAM page 0x08: adrese 0x000 - 0x0FF unutar waveform RAM-a
    write_and_verify(fd, 0x2, DATA_WAVE_PAGE_ADDR, 0x08, "READBACK_PAGE_WAVEFORM_0");

    for (n = 0; n < num_samples; n++) {
        uint8_t addr = 2 * n;

        /*
         * PGA970 read:
         * 1) prvi transfer zadaje read komandu
         * 2) drugi transfer vraca podatke iz prethodne read komande
         *
         * Za 16-bit aligned address:
         * rx[1] = data from ADDR
         * rx[2] = data from ADDR + 1
         */

        pga970_transfer(fd, 0, 0x1, addr, 0x00, NULL);
        pga970_transfer(fd, 0, 0x1, addr, 0x00, rx);

        uint8_t byte0 = rx[1];   // RAM[addr]
        uint8_t byte1 = rx[2];   // RAM[addr + 1]

        uint16_t val_lo_hi = ((uint16_t)byte1 << 8) | byte0;

        uint16_t val_hi_lo = ((uint16_t)byte0 << 8) | byte1;

        printf(
            "n=%02d addr=0x%02X RAM[addr]=0x%02X RAM[addr+1]=0x%02X | LO-HI=%5u | HI-LO=%5u\n",
            n, addr, byte0, byte1, val_lo_hi, val_hi_lo
        );
    }

    printf("--- END WAVEFORM RAM READBACK ---\n\n");
}

void setup_pga970(spi_fd) {
    printf("\n--- CONFIGURATION ---\n");

    // SPI enable
    write_and_verify(spi_fd, 0x2, DIG_IF_CTRL, 0x01, "DIG_IF_CTRL");

    // Micro Reset and Digital Interface enable
    write_and_verify(spi_fd, 0x0, MICRO_INTERFACE_CONTROL, 0x03, "MICRO_RESET");



    printf("--- CONFIGURATION FOR SECONDARY TRANSFORMATORS---\n");

    write_and_verify(spi_fd, 0x2, REG_ALPWR, 0x04, "ALPWR_VREF");

    // Postavljanje S1 i S2 pojacanja. Sx_SEM=0 (Differential), Sx_GAIN=11 (2x pojačanje)
    write_and_verify(spi_fd, 0x2, S1_CFG, 0x00, "S1_CFG_GAIN");
    write_and_verify(spi_fd, 0x2, S2_CFG, 0x11, "S2_CFG_GAIN");

    // Bias/VCOM Podešavanje, VCM_EN=0, BIAS_VCM_CTRL=00 (1.00V)
    write_and_verify(spi_fd, 0x2, S1_S2_CFG, 0x03, "S1_S2_VCM_CONFIG");

    

    // TEST MUX Povezivanje analognog izlaza direktno na ADC ulaz
   // write_and_verify(spi_fd, 0x2, REG_AMUX_CTRL, 0xF5, "AMUX_S1_S2"); //


    // NDS1 -> 0 (Sinusna komponenta)
    write_and_verify(spi_fd, 0x2, DAC_SIN_NDS1, 0x00, "NDS1_SINE");

    // NDS2 -> WAVEFORM_TABLE_LEN (Kosinusna komponenta)
    write_and_verify(spi_fd, 0x2, DAC_SIN_NDS2, 0xF9, "NDS2_COS"); //At DAC_SIN_NDS2 = WAVEFORM_TABLE_LEN, the DEMOD1_PH1DATA = A*cos(phase)



    // Napajanje i reference (VREF Enable)
   // write_and_verify(spi_fd, 0x2, REG_ALPWR, 0x04, "ALPWR_VREF");

    // Turn off waveform DAC
    write_and_verify(spi_fd, 0x2, REG_WAVEGEN_CTRL, 0x00, "WAVEGEN_CTRL");


    static const uint16_t wave_lut[250] = {13, 40, 66, 92, 119, 145, 171, 198, 224, 251, 277, 303, 
    330, 356, 382, 408, 435, 461, 487, 513, 539, 566, 592, 618, 
    644, 670, 696, 722, 748, 774, 800, 826, 852, 878, 903, 929, 
    955, 980, 1006, 1032, 1057, 1083, 1108, 1134, 1159, 1184, 1210, 1235, 
    1260, 1285, 1310, 1335, 1360, 1385, 1410, 1435, 1460, 1485, 1509, 1534, 
    1558, 1583, 1607, 1632, 1656, 1680, 1704, 1728, 1752, 1776, 1800, 1824, 
    1848, 1871, 1895, 1919, 1942, 1965, 1989, 2012, 2035, 2058, 2081, 2104, 
    2127, 2149, 2172, 2194, 2217, 2239, 2262, 2284, 2306, 2328, 2350, 2372, 
    2393, 2415, 2437, 2458, 2479, 2501, 2522, 2543, 2564, 2585, 2605, 2626, 
    2647, 2667, 2687, 2708, 2728, 2748, 2768, 2787, 2807, 2827, 2846, 2865, 
    2885, 2904, 2923, 2942, 2961, 2979, 2998, 3016, 3034, 3053, 3071, 3089, 
    3106, 3124, 3142, 3159, 3177, 3194, 3211, 3228, 3245, 3261, 3278, 3294, 
    3311, 3327, 3343, 3359, 3374, 3390, 3406, 3421, 3436, 3451, 3466, 3481, 
    3496, 3510, 3525, 3539, 3553, 3567, 3581, 3595, 3608, 3622, 3635, 3648, 
    3661, 3674, 3687, 3699, 3712, 3724, 3736, 3748, 3760, 3772, 3783, 3795, 
    3806, 3817, 3828, 3839, 3849, 3860, 3870, 3880, 3890, 3900, 3910, 3919, 
    3929, 3938, 3947, 3956, 3965, 3974, 3982, 3990, 3998, 4006, 4014, 4022, 
    4030, 4037, 4044, 4051, 4058, 4065, 4071, 4078, 4084, 4090, 4096, 4102, 
    4107, 4113, 4118, 4123, 4128, 4133, 4137, 4142, 4146, 4150, 4154, 4158, 
    4162, 4165, 4169, 4172, 4175, 4177, 4180, 4183, 4185, 4187, 4189, 4191, 
    4193, 4194, 4195, 4196, 4197, 4198, 4199, 4199, 4200, 4200};
    
    int n;
    //Upisivanje na prvu stranu data waveform-a (128 uzoraka * 2 bajta = 256 bajtova), dok se ne popuni i prelazak na next page
    for (n = 0; n < 250; n++) {
        if(n < 128) {
          write_and_verify(spi_fd, 0x2, DATA_WAVE_PAGE_ADDR, 0x08, "PAGE_WAVEFORM_0");
        }

        else if(n == 128) {
            write_and_verify(spi_fd, 0x2, DATA_WAVE_PAGE_ADDR, 0x09, "PAGE_WAVEFORM_1");
       }

        // Svaka tacka LUT-a je 16-bitna (HI pa LO bajt), adresa u okviru stranice (0–255 bajtova)
        int addr = (n % 128) * 2;

        uint16_t val = wave_lut[n];
        uint8_t lo_byte = val & 0xFF;         // Donji bajt (LSB)
        uint8_t hi_byte = (val >> 8) & 0xFF;  // Gornji bajt (MSB)

        
        // Upis HI i LO bajta
        pga970_transfer(spi_fd, 1, 0x1, addr, lo_byte, NULL); 
        pga970_transfer(spi_fd, 1, 0x1, addr + 1, hi_byte, NULL);     

        // pga970_transfer(spi_fd, 1, 1, addr, (val >> 8) & 0xFF, NULL);     // gornjih 8 bita adrese u waveform ram-u
        // pga970_transfer(spi_fd, 1, 1, addr + 1, val & 0xFF, NULL);        // donjih 8 bita adrese u waveform ram-u

    }

   // readback_waveform_ram(spi_fd, 50);


    write_and_verify(spi_fd, 0x2, S3_ADC_CFG_1, 0x01, "S3_ADC");


    // // Turn off waveform DAC
    // write_and_verify(spi_fd, 0x2, REG_WAVEGEN_CTRL, 0x00, "WAVEGEN_CTRL");

    // DAC konfiguracija
    write_and_verify(spi_fd, 0x2, DAC_CTRL_STATUS, 0x01, "DAC_ENABLE");
    
    // Gain 2 V/V i aktivacija filtracije (DACCAP_EN = 0)
    write_and_verify(spi_fd, 0x2, OP_STAGE_CTRL, 0x04, "OP_STAGE");


    // upis offseta u registre

    write_and_verify(spi_fd, 0x2, REG_DAC_OFFSET_LO, 0x08, "DAC_OFFSET_LO");
    write_and_verify(spi_fd, 0x2, REG_DAC_OFFSET_HI, 0x2C, "DAC_OFFSET_HI");

    write_and_verify(spi_fd, 0x2, REG_WAVEFORM_TABLE_LEN, 0xF9, "TABLE_LEN"); 

    // Connects waveform DAC output to waveform gain
   // write_and_verify(spi_fd, 0x2, REG_AMUX_CTRL, 0xF5, "AMUX_WAVEGEN"); //UPDATE DODALA SAM F7 UMESTO F1, ukljucila S1 i S2 ADCS
    
    // Diferencijalni mod, Gain 1.67, VCM 1.25V, DAC bias 0.82V
    write_and_verify(spi_fd, 0x2, REG_LVDT_OP_CTRL, 0x38, "LVDT_DIFF_MODE");

    // Loopback off
    write_and_verify(spi_fd, 0x2, DAC_LPBK_CTRL, 0x00, "DAC_ON");
    write_and_verify(spi_fd, 0x2, REG_LVDT_LPBK_CTRL, 0x01, "LPBK_ON");
    

    // Wave generator start
    write_and_verify(spi_fd, 0x02, REG_WAVEGEN_CTRL, 0x01, "WAVEGEN_START");

    write_and_verify(spi_fd, 0x2, DEMOD1_CONFIG, 0x00, "DEMOD1_EN");  //demod disable, output rate is 128 us
    write_and_verify(spi_fd, 0x2, DEMOD2_CONFIG, 0x00, "DEMOD2_EN");

    // DEMODULATOR 1
    // BPF (24-bit)  40Hz bandwidth, f0 1kHz , output rate 128us
    write_24bit(spi_fd, 0x2, DEMOD1_BPF_B1, 0x00083C, "D1_BPF_B1");
    write_24bit(spi_fd, 0x2, DEMOD1_BPF_A2, 0xFFF679, "D1_BPF_A2");
    write_24bit(spi_fd, 0x2, DEMOD1_BPF_A3, 0xFFEF88, "D1_BPF_A3");
    // LPF (16-bit)
    write_16bit(spi_fd, 0x2, DEMOD1_LPF_B1, 0x0207, "D1_LPF_B1");
    write_16bit(spi_fd, 0x2, DEMOD1_LPF_A2, 0x7BF2, "D1_LPF_A2");

    // DEMODULATOR 2
    // BPF (24-bit)
    write_24bit(spi_fd, 0x2, DEMOD2_BPF_B1, 0x00083C, "D2_BPF_B1");
    write_24bit(spi_fd, 0x2, DEMOD2_BPF_A2, 0xFFF679, "D2_BPF_A2");
    write_24bit(spi_fd, 0x2, DEMOD2_BPF_A3, 0xFFEF88, "D2_BPF_A3");
    // LPF (16-bit)
    write_16bit(spi_fd, 0x2, DEMOD2_LPF_B1, 0x0207, "D2_LPF_B1");
    write_16bit(spi_fd, 0x2, DEMOD2_LPF_A2, 0x7BF2, "D2_LPF_A2");

    
    // Aktivacija Demodulatora 
    write_and_verify(spi_fd, 0x2, DEMOD1_CONFIG, 0x01, "DEMOD1_EN");  //demod enable, output rate is 128 us
    write_and_verify(spi_fd, 0x2, DEMOD2_CONFIG, 0x01, "DEMOD2_EN");

    write_and_verify(spi_fd, 0x2, S1_S2_DEMOD_CFG_1, 0x08, "S1_S2_DEMOD");

    write_and_verify(spi_fd, 0x2, AMUX_ACT, 0x02, "AMUX_ACT");
    write_and_verify(spi_fd, 0x2, AMUX_TOUT_MUX_CTRL, 0x0A, "AMUX_TOUT");
    write_and_verify(spi_fd, 0x2, REG_AMUX_CTRL, 0xFF, "AMUX_S1_S2");
    
    
    
    printf("--- END OF CONFIGURATION ---\n");

    
}



int main() {

    if (gpio_export(CS_PIN) < 0) {
        printf("Can't export pin \n");
        //return -1; 
}

    cs_fd = gpio_direction_output(CS_PIN, 1);
    if (cs_fd < 0){
        pabort("Can't set gpio direction \n");
        return -1; }
         
    spi_fd = open(SPI_PATH, O_RDWR);
    if (spi_fd < 0) {
        pabort("Can't open SPI device \n"); 
    }

    i2c0_fd = open(I2C_PATH_0, O_RDWR);
    if (i2c0_fd < 0) {
        pabort("Can't open I2C device \n"); 
    }

    i2c2_fd = open(I2C_PATH_2, O_RDWR);
    if (i2c2_fd < 0) {
        pabort("Can't open I2C device \n"); 
    }

    //SPI
    uint8_t mode = SPI_MODE_1;
    ioctl(spi_fd, SPI_IOC_WR_MODE, &mode);


    //I2C-0
    ioctl(i2c0_fd, I2C_SLAVE, PCA9554_U15_ADDR);
    init_expander(i2c0_fd, PCA9554_U15_ADDR);

    //U13
    pca9554_write(i2c0_fd, PCA9554_U13_ADDR, PCA_CONFIG, 0x00);  //Inicijalizacija, pinovi su output
    pca9554_write(i2c0_fd, PCA9554_U13_ADDR, PCA_OUTPUT, 0x00);  // gain = 0.125


    // Postavljanje pojacanja (REN, RA0, RA1) gain = 1, gsel=0
    set_gain_config(i2c0_fd, PCA9554_U15_ADDR, 1, 1, 1, 0);
    usleep(1000);
    set_gain_config(i2c0_fd, PCA9554_U15_ADDR, 1, 1, 1, 1);

    printf("Port ekspanderi su inicijalizovani preko I2C.\n");

    ioctl(i2c2_fd, I2C_SLAVE, CAT9555YI_U5_ADDR);

    //I2C-2
    cat9555_write(i2c2_fd, CAT9555YI_U5_ADDR, CAT_CONFIG_P0, 0x00);
    cat9555_write(i2c2_fd, CAT9555YI_U5_ADDR, CAT_CONFIG_P1, 0x00);

    cat9555_write(i2c2_fd, CAT9555YI_U5_ADDR, CAT_OUTPUT_P0, 0xFF);
    cat9555_write(i2c2_fd, CAT9555YI_U5_ADDR, CAT_OUTPUT_P1, 0xFF);

    printf("LED su inicijalizovane.\n");
    
    ioctl(i2c2_fd, I2C_SLAVE, CAT9555YI_U4_ADDR);

    // DO = 0 (izlazi) i DOx_STAT = 1 (ulazi),u DI0-4 = 1 (ulazi)
    // P0: 1110 0011 = 0xE3 (1 = Input, 0 = Output)
    cat9555_write(i2c2_fd, CAT9555YI_U4_ADDR, CAT_CONFIG_P0, 0xE3);   
    cat9555_write(i2c2_fd, CAT9555YI_U4_ADDR, CAT_OUTPUT_P0, 0xE3); 

    printf("U4: DO0-2 su aktivni. Proveri 24V na izlazu.\n");

    // DI0-2 = 1, ostale nisu povezane -> 0xFF ili 0x03?
    cat9555_write(i2c2_fd, CAT9555YI_U4_ADDR, CAT_CONFIG_P1, 0xFF); 

    
    setup_pga970(spi_fd);

    // Otvaranje fajlova
    FILE *f_demod1 = fopen("demod1.txt", "w");
    FILE *f_demod2 = fopen("demod2.txt", "w");

    if (f_demod1 == NULL || f_demod2 == NULL) {
    perror("Greska pri otvaranju fajlova");
    return -1;
    }

    printf("\n READING DATA FROM SECONDARY TRANSFORMATORS (S1 i S2)\n");
    while (1) {
        uint8_t di_port1 = cat9555_read(i2c2_fd, CAT9555YI_U4_ADDR, CAT_INPUT_P1);
        uint8_t di_port0 = cat9555_read(i2c2_fd, CAT9555YI_U4_ADDR, CAT_INPUT_P0);
        
        
        // Čitamo 32-bitne podatke sa adresa 0x10 (S1) i 0x14 (S2) s1 i s2 amplitude
        uint32_t s1_raw = read_32bit(spi_fd, 0x0, DEMOD1_DATA);
        uint32_t s2_raw = read_32bit(spi_fd, 0x0, DEMOD2_DATA);
        uint32_t ph1_raw = read_32bit(spi_fd, 0x0, DEMOD2_PH1DATA);
        uint32_t ph2_raw = read_32bit(spi_fd, 0x0, DEMOD2_PH2DATA);


        // // Sign extension na 32bitas
        int32_t s1_val  = (int32_t)ntohl(s1_raw);
        int32_t s2_val  = (int32_t)ntohl(s2_raw);
        int32_t ph1_val = (int32_t)ntohl(ph1_raw);
        int32_t ph2_val = (int32_t)ntohl(ph2_raw);

        // int32_t s1_val  = (int32_t)(s1_raw);
        // int32_t s2_val  = (int32_t)(s2_raw);
        // int32_t ph1_val = (int32_t)(ph1_raw);
        // int32_t ph2_val = (int32_t)(ph2_raw);


    
        // Upis u txt fajlove
        fprintf(f_demod1, "%06X\n", s1_val );
        fprintf(f_demod2, "%06X\n", s2_val );

        fflush(f_demod1);
        fflush(f_demod2);


        double position = 0.0;

        if ((s1_val + s2_val) != 0) {
            position = ((double)(s1_val - s2_val)) /
                    ((double)(s1_val + s2_val));
        }

      // double dc_output_magnitude = ((double)s2_val * 2.5 * M_PI) / (2.0 * 8388608.0);  // 2^23 = 8388608.0
      double amplitude = ((double)s2_raw * 2.5 * M_PI) / (2.0 * 8388608.0);  // 2^23 = 8388608.0

        // Racunanje faze u radijanima pa u stepenima
        double phase_rad = atan2((double)ph1_val, (double)ph2_val);     //phase = arctan(DEMOD1_PH1_DATA/DEMOD1_PH2_DATA)
        double phase_deg = phase_rad * (180.0 / M_PI);
        
        // DI0-DI2 su na Port 1, bitovi 0,1,2
        //printf("DI stanje: Port1(DI0-2)=0x%02X, Port0(DI3-4)=0x%02X\n", di_port1, di_port0);

        printf("DEMOD1 raw: 0x%08X | DEMOD1: 0x%08X | DEMOD1 dec: %d\n", s1_raw, s1_val, s1_val);
        printf("DEMOD2 raw: 0x%08X | DEMOD2: 0x%08X | DEMOD2 dec: %d| \n POZICIJA: %.3f | AMPLITUDA D2: %.5f \n\n", s2_raw, s2_val, s2_val, position, amplitude);
       // printf(" DC Output Magnitude: %.3f V | FAZA: %.2f°\n", dc_output_magnitude, phase_deg);
        //fflush(stdout);
        
        usleep(50000); // 50ms pauza
    }
    close(spi_fd);
    close(i2c0_fd);
    close(i2c2_fd);
    return 0;
}




