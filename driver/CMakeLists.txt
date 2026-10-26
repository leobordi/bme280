add_library(bme280_driver INTERFACE)

target_sources(bme280_driver INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/bme280.c
)

target_include_directories(bme280_driver INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(bme280_driver INTERFACE
    pico_stdlib
    hardware_i2c
)
