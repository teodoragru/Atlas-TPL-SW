#ifndef AD4130_H
#define AD4130_H

#include <stdint.h>
#include <gpiod.h>

// Smer komunikacije (R/W bit na poziciji 6)
#define AD4130_WRITE            0x00
#define AD4130_READ             0x40

// Ključni registri iz AD4130-8 datasheet-a
#define AD4130_REG_STATUS       0x00  // 8-bitni
#define AD4130_REG_ADC_CONTROL  0x01  // 16-bitni
#define AD4130_REG_DATA         0x04  // 24-bitni
#define AD4130_REG_ID           0x07  // 8-bitni
#define AD4130_REG_CH0          0x10  // 16-bitni

// Očekivani fabrički ID za AD4130 seriju
#define AD4130_EXPECTED_ID      0xCC

// Funkcije drajvera
int ad4130_init_system(const char *spi_device, const char *gpio_chip_name, const int *cs_gpio_pins);
void ad4130_close_system(void);
uint32_t ad4130_read_reg(int adc_index, uint8_t reg, size_t reg_size);
void ad4130_write_reg(int adc_index, uint8_t reg, uint32_t value, size_t reg_size);
void ad4130_software_reset(int adc_index);

#endif // AD4130_H