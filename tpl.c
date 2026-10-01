#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <rtdm/rtdm.h> // Xenomai RTDM zaglavlje

// Struktura za I2C poruku unutar Linux/Xenomai kernela
struct i2c_msg {
    unsigned short addr;
    unsigned short flags;
#define I2C_M_RD 0x0001
    unsigned short len;
    unsigned char *buf;
};

// Struktura koju tvoj patlas_h3 drajver očekuje preko ioctl-a ili write-a
struct i2c_rdwr_ioctl_data {
    struct i2c_msg *msgs;
    int nmsgs;
};

// Eksterne promenljive iz Yacc parsera
extern FILE *yyin;
extern int yyparse();
extern struct dac_config my_dac;

int main(int argc, char **argv) {
    // 1. Otvaranje i parsiranje konfiguracionog fajla
    yyin = fopen("tpl.conf", "r");
    if (!yyin) {
        perror("Ne mogu otvoriti tpl.conf");
        return -1;
    }
    
    if (yyparse() != 0) {
        fprintf(stderr, "Parsiranje neuspesno!\n");
        return -1;
    }
    fclose(yyin);

    printf("Uspesno procitana konfiguracija!\n");
    printf("DAC Adresa: 0x%02X, Pocetna vrednost: %d\n", my_dac.addr, my_dac.init_val);

    // 2. Otvaranje Xenomai RTDM I2C drajvera (patlas)
    // U Xenomai okruženju, RTDM uređaji se otvaraju sa aplikativne strane preko običnog open-a
    int fd = open("/dev/rtdm/patlas", O_RDWR);
    if (fd < 0) {
        perror("Greska pri otvaranju /dev/rtdm/patlas. Da li je ucitana patlas_h3?");
        return -1;
    }

    // 3. Priprema podataka za LTC2635 DAC prema šemi i datasheet-u
    unsigned char tx_buffer[3];
    
    // Bajt 1: Komanda 0x06 (Uključi internu referencu)
    tx_buffer[0] = (0x06 << 4) | 0x00; 
    tx_buffer[1] = 0x00;
    tx_buffer[2] = 0x00;

    struct i2c_msg msg[1];
    msg[0].addr = my_dac.addr; // 0x10 pročitano iz parsera
    msg[0].flags = 0;          // 0 znači upis (Write)
    msg[0].len = 3;            // Šaljemo 3 bajta
    msg[0].buf = tx_buffer;

    // Slanje komande za uključenje reference drajveru patlas
    write(fd, msg, sizeof(msg)); 
    printf("Poslata komanda za ukljucivanje interne reference.\n");

    // Bajtovi za postavljanje napona (Komanda 0x03 - Write and Update kanal A)
    tx_buffer[0] = (0x03 << 4) | 0x00; // 0x30
    tx_buffer[1] = (my_dac.init_val >> 4) & 0xFF; // MSB podataka
    tx_buffer[2] = (my_dac.init_val << 4) & 0xFF; // LSB podataka

    // Ponovno slanje za promenu analognog izlaza
    write(fd, msg, sizeof(msg));
    printf("Uspesno upisana vrednost %d na DAC izlaz!\n", my_dac.init_val);

    close(fd);
    return 0;
}