# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

FILE(GLOB_RECURSE usbhost ${CMAKE_SOURCE_DIR}/src/usbhost/*.*)
FILE(GLOB_RECURSE blehid ${CMAKE_SOURCE_DIR}/src/blehid/*.*)

idf_component_register(SRCS ${usbhost} ${blehid} main.c
                        PRIV_REQUIRES usb esp_driver_gpio)
