// quectel_test.c
// Test program za Quectel EG912U-GL modul (GPRS/GNSS) na Atlas-TPL BB plocici.
// Radi DVE stvari: (1) upali modul preko GPIO-a (LDO + PWRKEY), (2) salje
// AT komande preko UART-a i cita odgovor.
//
// Kompajliranje: gcc quectel_test.c -o quectel_test
// Pokretanje:    sudo ./quectel_test   (root je potreban zbog /sys/class/gpio)

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

/* GPIO brojevi - (GPIO_A17/A20/A21 -> sysfs 17/20/21).*/

#define GPIO_LDO_ON   21   // GNSS_LDO_ON  - napajanje modula (BB plocica)
#define GPIO_PWRKEY   20   // GNSS_PWR_KEY - PWRKEY modula (Quectel pin 15)
#define GPIO_RESET    17   // GNSS_RST_KEY - RESET_N modula (Quectel pin 17)

/* UART port ka MAIN_TXD/MAIN_RXD (Quectel pinovi 35/34)*/

#define QUECTEL_UART_DEVICE   "/dev/ttySS1"  
#define QUECTEL_BAUD           B115200

/* ===================== GPIO (sysfs) pomocne funkcije ===================== */

/**
 * @brief Eksportuje GPIO liniju ako vec nije (bezopasno ako vec jeste - ignorisemo gresku)
 */
void gpio_export(int gpio_num) {
    char path[64];
    int fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("Ne mogu da otvorim /sys/class/gpio/export");
        return;
    }
    char buf[16];
    int len = snprintf(buf, sizeof(buf), "%d", gpio_num);
    write(fd, buf, len);  
    close(fd);

    // Mala pauza da sysfs stigne da napravi folder gpioN/
    usleep(100000);
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/direction", gpio_num);
}

/**
 * @brief Postavlja GPIO liniju kao izlaz
 */
int gpio_set_output(int gpio_num) {
    char path[64];
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/direction", gpio_num);
    int fd = open(path, O_WRONLY);
    if (fd < 0) {
        perror("Ne mogu da postavim GPIO smer");
        return -1;
    }
    write(fd, "out", 3);
    close(fd);
    return 0;
}

/**
 * @brief Postavlja vrednost GPIO linije (0 ili 1)
 */
int gpio_set_value(int gpio_num, int value) {
    char path[64];
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", gpio_num);
    int fd = open(path, O_WRONLY);
    if (fd < 0) {
        perror("Ne mogu da postavim GPIO vrednost");
        return -1;
    }
    write(fd, value ? "1" : "0", 1);
    close(fd);
    return 0;
}

/* ===================== Sekvenca ukljucivanja modula ===================== */

/**
 * @brief Ukljucuje Quectel modul: prvo napajanje (LDO), pa PWRKEY impuls,
 *        pa ceka da modul zavrsi boot (Turn-on Timing).
 */
void quectel_power_on(void) {
    printf("Ukljucivanje Quectel modula\n");

    gpio_export(GPIO_LDO_ON);
    gpio_export(GPIO_PWRKEY);
    gpio_export(GPIO_RESET);

    gpio_set_output(GPIO_LDO_ON);
    gpio_set_output(GPIO_PWRKEY);
    gpio_set_output(GPIO_RESET);

    // RESET_N drzimo na 0 (neaktivan) 
    gpio_set_value(GPIO_RESET, 0);

    // 1) Napajanje (LDO) prvo
    gpio_set_value(GPIO_LDO_ON, 1);
    printf("  LDO ukljucen, napon se stabilizuje. \n");
    usleep(200000); //200ms

    // 2) PWRKEY nisko >= 2s (iz datasheet-a T1 = 2s)
    gpio_set_value(GPIO_PWRKEY, 1);
    printf("  PWRKEY nisko 2.5s...\n");
    sleep(1);
    usleep(500000); //500ms
    sleep(1);
    gpio_set_value(GPIO_PWRKEY, 1);

    // 3) Cekanje da modul zavrsi boot (T3 = 5.05s, uzimamo 6s rezerve)
    printf("  Boot 6s...\n");
    sleep(6);

    printf("Modul je spreman za AT komande.\n\n");
}

/* ===================== UART otvaranje  ===================== */

int quectel_uart_open(void) {
    int fd = open(QUECTEL_UART_DEVICE, O_RDWR | O_NOCTTY); //O_NOCTTY sprecava da ovaj serijski port postane kontrolni terminal
    if (fd < 0) {
        perror("Ne mogu da otvorim ", QUECTEL_UART_DEVICE);
        return -1;
    }

    struct termios tty;
    if (tcgetattr(fd, &tty) != 0) {     //tcgetattr cita trenutna podesavanja porta 
        perror("tcgetattr");
        close(fd);
        return -1;
    }

    cfmakeraw(&tty);        // cfmakeraw postavlja port u raw mode - salju se/primaju sorovi bajtovi tacno onako kako se posalju 
    cfsetispeed(&tty, QUECTEL_BAUD);        // postavclja baud rate za ulaz i izlaz na 115200
    cfsetospeed(&tty, QUECTEL_BAUD);


    //standardna 8N1 konfiguracija za serijsku komunikaciju
    tty.c_cflag &= ~PARENB;     // bez parity bita
    tty.c_cflag &= ~CSTOPB;     // 1 stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;         // 8 data bita
    tty.c_cflag &= ~CRTSCTS;    // bez hardverske flow kontrole
    tty.c_cflag |= (CLOCAL | CREAD);    // ignorisi modem control linije, omoguci citanje
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);    // bez softverske xon/xoff kontrole

    // VMIN/VTIME: citanje se ne blokira zauvek - vraca se posle 0.5s ako nema podataka
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 5;   // 5 * 0.1s = 0.5s timeout

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("tcsetattr");
        close(fd);
        return -1;
    }

    return fd;
}

/* ===================== Slanje AT komande i citanje odgovora ===================== */

/**
 * @brief Salje AT komandu (dodaje \r\n automatski) i ispisuje sve sto stigne
 *        nazad u sledecih ~2 sekunde. Ne parsira odgovor - 
 *        cilj je da se vidi da li modul nesto kaze.
 */

int pokusaj = 0;


void quectel_send_at(int fd, const char *command) {
    char tx_buf[256];
    int len = snprintf(tx_buf, sizeof(tx_buf), "%s\r\n", command);

    printf(">> %s\n", command);
    write(fd, tx_buf, len);

    // Citamo odgovor u par navrata (modul ponekad salje odgovor u vise komada)
    char rx_buf[512];
    for (pokusaj = 0; pokusaj < 8; pokusaj++) {
        int n = read(fd, rx_buf, sizeof(rx_buf) - 1);
        if (n > 0) {
            rx_buf[n] = '\0';
            printf("<< %s", rx_buf);
        }
    }
    printf("\n");
}

/* ===================== Glavni test tok ===================== */

int main(void) {
    quectel_power_on();

    int uart_fd = quectel_uart_open();
    if (uart_fd < 0) {
        printf("Ne mogu da otvorim UART ka modulu. Proveri QUECTEL_UART_DEVICE.\n");
        return EXIT_FAILURE;
    }

    printf("=== Osnovni test (da li modul uopste odgovara) ===\n");
    quectel_send_at(uart_fd, "AT");

    printf("=== GPRS/mobilna mreza ===\n");
    quectel_send_at(uart_fd, "AT+CPIN?");     // da li SIM kartica radi
    quectel_send_at(uart_fd, "AT+CSQ");       // kvalitet signala
    quectel_send_at(uart_fd, "AT+CREG?");     // registracija na mrezu
    quectel_send_at(uart_fd, "AT+CGATT?");    // GPRS attach status

    printf("=== GNSS ===\n");
    quectel_send_at(uart_fd, "AT+QGPS=1");    // ukljuci GPS prijemnik
    sleep(2);
    quectel_send_at(uart_fd, "AT+QGPSLOC?");  // pokusaj da procitas poziciju (moze biti prazno prvi put)

    close(uart_fd);
    return EXIT_SUCCESS;
}
