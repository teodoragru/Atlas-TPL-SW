#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/spi/spi.h>  // Glavno zaglavlje za SPI podbelesku kernela

MODULE_LICENSE("XX");
MODULE_AUTHOR("Teodora");
MODULE_DESCRIPTION("Test drajver za proveru SPI komunikacije sa AD4130");
MODULE_VERSION("1.0");

/* 
 * Komandni bajt (Communications Register) ima sledeći format:
 * Bit 7: 0 za upis (Write), 1 za čitanje (Read) 
 * Bit 5-0: Adresa registra -> 0x05 za ID register
 */
#define AD4130_REG_ID      0x05  
#define AD4130_READ_BIT    0x40  

/* Funkcija za čitanje 8-bitnog ID registra sa AD4130 */
static int ad4130_read_id(struct spi_device *spi, u8 *id_value) {
    u8 tx_buf[2] = {0}; // Šaljemo 2 bajta: [Komanda sa adresom, Dummy bajt da generišemo takt]
    u8 rx_buf[2] = {0}; // Primamo 2 bajta: [Ignoriše se, Stvarna vrednost registra]
    struct spi_transfer t;
    struct spi_message m;
    int status;

    // Priprema komandnog bajta za čitanje ID registra (0x40 | 0x05 = 0x45)
    tx_buf[0] = AD4130_READ_BIT | AD4130_REG_ID;
    tx_buf[1] = 0x00; // Dummy bajt (dok ga šaljemo, ADC nam vraća podatak u istom trenutku)

    // Inicijalizacija SPI poruke unutar Linux kernela
    spi_message_init(&m);
    memset(&t, 0, sizeof(t));

    t.tx_buf = tx_buf;
    t.rx_buf = rx_buf;
    t.len = 2; // Ukupna dužina prenosa u bajtovima

    spi_message_add_tail(&t, &m);
    
    // Izvršavanje sinhrone SPI transakcije
    status = spi_sync(spi, &m);
    if (status < 0) {
        dev_err(&spi->dev, "SPI greska tokom citanja ID registra: %d\n", status);
        return status;
    }

    // Podatak se nalazi u drugom bajtu (rx_buf[1]) jer je u prvom bajtu ADC ćutao dok je primao adresu
    *id_value = rx_buf[1];
    return 0;
}

/* * PROBE funkcija: Pokreće se automatski kada kernel upari drajver sa 
 * definisanim SPI uređajem u Device Tree-ju (npr. preko sysconfig.sh)
 */
static int ad4130_probe(struct spi_device *spi) {
    u8 chip_id = 0xFF;
    int ret;

    dev_info(&spi->dev, "AD4130: Probe funkcija pokrenuta. Inicijalizujem SPI...\n");

    // Podešavanje SPI parametara specifičnih za AD4130-8 
    spi->mode = SPI_MODE_3;       // AD4130 koristi CPOL=1, CPHA=1 (SPI Mod 3)
    spi->bits_per_word = 8;       // Prenos ide bajt po bajt
    spi->max_speed_hz = 1000000;  // Postavljamo brzinu na sigurnih 1 MHz za testiranje
    
    ret = spi_setup(spi);
    if (ret < 0) {
        dev_err(&spi->dev, "Neuspesno podesavanje SPI parametara!\n");
        return ret;
    }

    // POKRETANJE TESTA KOMUNIKACIJE
    ret = ad4130_read_id(spi, &chip_id);
    if (ret == 0) {
        dev_info(&spi->dev, "===============================================\n");
        dev_info(&spi->dev, "AD4130 SPI TEST USPESAN!\n");
        dev_info(&spi->dev, "Procitana vrednost ID registra: 0x%02X (Ocekivano: 0x00)\n", chip_id);
        dev_info(&spi->dev, "===============================================\n");
    } else {
        dev_err(&spi->dev, "Komunikacija sa AD4130 nije uspela.\n");
    }

    return 0;
}

/* REMOVE funkcija: Pokreće se kada se modul gasi */
static int ad4130_remove(struct spi_device *spi) {
    dev_info(&spi->dev, "AD4130: Modul je uspesno uklonjen sa magistrale.\n");
    return 0;
}

/* Tabela za prepoznavanje uređaja (Mora da odgovara imenu u Device Tree-ju) */
static const struct spi_device_id ad4130_id[] = {
    { "ad4130", 0 },
    { }
};
MODULE_DEVICE_TABLE(spi, ad4130_id);

/* Glavna struktura koja povezuje probe i remove funkcije */
static struct spi_driver ad4130_driver = {
    .driver = {
        .name = "ad4130",
        .owner = THIS_MODULE,
    },
    .probe = ad4130_probe,
    .remove = ad4130_remove,
    .id_table = ad4130_id,
};

/* Komanda insmod pokreće ovu funkciju i registruje drajver u Linux SPI podsistemu */
static int __init ad4130_init(void) {
    return spi_register_driver(&ad4130_driver);
}

/* Komanda rmmod pokreće ovu funkciju */
static void __exit ad4130_exit(void) {
    spi_unregister_driver(&ad4130_driver);
}

module_init(ad4130_init);
module_exit(ad4130_exit);