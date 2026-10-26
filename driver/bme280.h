#pragma once

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"

#define ADDRESS 0x76

uint8_t bme280_get_id();
static void bme280_write_byte(uint8_t reg, uint8_t data);
static void bme280_read(uint8_t reg, uint8_t *buffer);
