#include <stdio.h>
#include <stdbool.h>
#include "bme280.h"
#include "lcd_i2c.h"

int main() {
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    i2c_init(i2c1, 100 * 1000);
    gpio_set_function(6, GPIO_FUNC_I2C);
    gpio_set_function(7, GPIO_FUNC_I2C);
    gpio_pull_up(6);
    gpio_pull_up(7);


    i2c_write_blocking(i2c1, 0x76, 0x76 << 1, 1, false);
    i2c_write_blocking(i2c1, 0x76, 0xD0, 1, false);
    i2c_write_blocking(i2c1, 0x76, (0x76 << 1) | 0x1, 1, false);

    uint8_t bf;
    int result = i2c_read_blocking(i2c1, 0x76, &bf, 1, false);
    printf("Result: %d\n", result);

    return 0;
}
