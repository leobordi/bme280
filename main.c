#include <stdio.h>
#include <stdbool.h>
#include "driver/bme280.h"

int main() {
    i2c_init(i2c1, 100 * 1000);
    gpio_set_function(6, GPIO_FUNC_I2C);
    gpio_set_function(7, GPIO_FUNC_I2C);
    gpio_pull_up(6);
    gpio_pull_up(7);

    uint8_t a = 0x76 << 1;
    uint8_t b = 0xD0;
    uint8_t c = (0x76 << 1) | 0x1;

    i2c_write_blocking(i2c1, 0x76, &a, 1, false);
    i2c_write_blocking(i2c1, 0x76, &b, 1, false);
    i2c_write_blocking(i2c1, 0x76, &c, 1, false);

    uint8_t bf;
    int result = i2c_read_blocking(i2c1, 0x76, &bf, 1, false);
    printf("Result: %d\n", result);

    return 0;
}
