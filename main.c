#include <stdio.h>
#include "bme280.h"

int main() {
    i2c_init(i2c1, 100 * 1000);
    gpio_set_function(6, GPIO_FUNC_I2C);
    gpio_set_function(7, GPIO_FUNC_I2C);
    gpio_pull_up(6);
    gpio_pull_up(7);



    return 0;
}
