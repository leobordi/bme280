cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(bme280 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(driver)

add_executable(bme280
    main.c
)

target_link_libraries(bme280 
    pico_stdlib
    hardware_i2c
    bme280_driver
)

pico_add_extra_outputs(bme280)

pico_enable_stdio_usb(bme280 1)
pico_enable_stdio_uart(bme280 0)
