add_executable(${PROJECT_NAME}
        hw/gpio.c hw/i2c.c hw/uart.c
        agathis/base.c
        platform.c callback.c main.c)



# This configuration file outlines some of the ways Arduino CMake
# can be used. For a detailed explenation of all the options please
# reade README.rst.

#set(ARDUINO_DEFAULT_BOARD nano.atmega328) # Default Board ID, when not specified
#set(ARDUINO_DEFAULT_PORT /dev/ttyUSB0) # Default Port, when not specified

#====================================================================#
# master_writer example from Wire library
#====================================================================#
#generate_arduino_example(wire_example
#                         LIBRARY Wire
#                         EXAMPLE master_writer)

# Alternative: by vairables
#set(wire_example_LIBRARY Wire)
#set(wire_example_EXAMPLE master_writer)
#
#generate_arduino_example(wire_example)

#====================================================================#
# Original blink sketch (from Arduino SDK examples)
#====================================================================#

# Some installations have renamed the example directories
#if (EXISTS "${ARDUINO_SDK_PATH}/examples/01.Basics/Blink")
#    set(BLINK_SKETCH "${ARDUINO_SDK_PATH}/examples/01.Basics/Blink")
#else()
#    set(BLINK_SKETCH "${ARDUINO_SDK_PATH}/examples/1.Basics/Blink")
#endif()

#generate_arduino_firmware(blink_original
#    SKETCH "${BLINK_SKETCH}"
#    PORT  /dev/ttyACM0
#    SERIAL picocom @SERIAL_PORT@
#    BOARD uno)

# Alternative: by variables
#set(blink_original_SKETCH "${BLINK_SKETCH}")
#set(blink_original_PORT  /dev/ttyACM)
#set(blink_original_SERIAL picocom @SERIAL_PORT@)
#set(blink_original_BOARD uno)
#
#generate_arduino_firmware(blink_original)




#====================================================================#
# Bundled blink sketch example
#====================================================================#
#generate_arduino_firmware(blink_bundled
#    SKETCH Blink
#    PROGRAMMER usbtinyisp
#    NO_AUTOLIBS)

# Alternative: by variables
#set(blink_bundled_SKETCH Blink)
#set(blink_bundled_PROGRAMMER usbtinyisp)
#set(blink_bundled_NO_AUTOLIBS true)
#
#generate_arduino_firmware(blink_bundled)




#====================================================================#
# Advanced static library exmaple
#====================================================================#
#generate_arduino_library(blink_lib
#    SRCS blink_lib.cpp
#    HDRS blink_lib.h
#    BOARD uno)

# Alternative: by variables
#set(blink_lib_SRCS blink_lib.cpp)
#set(blink_lib_HDRS blink_lib.h)
#set(blink_lib_BOARD uno)
#
#generate_arduino_library(blink_lib)




#====================================================================#
# Advanced firwmare example
#====================================================================#
#set( LST_SRC "")
#message( "LST_SRC: ${LST_SRC}" )

#file( GLOB LST_C ${CMAKE_CURRENT_SOURCE_DIR}/hw/*.c )
#message( "LST_C: ${LST_C}" )
#list( APPEND LST_SRC ${LST_C} )
#message( "LST_SRC: ${LST_SRC}" )

#file( GLOB LST_C ${CMAKE_CURRENT_SOURCE_DIR}/agathis/*.c )
#message( "LST_C: ${LST_C}" )
#list( APPEND LST_SRC ${LST_C} )
#message( "LST_SRC: ${LST_SRC}" )

#file( GLOB LST_C ${CMAKE_CURRENT_SOURCE_DIR}/cli/*.c )
#message( "LST_C: ${LST_C}" )

#include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
#list( APPEND LST_SRC main.c platform.c callback.c )
#message( "LST_SRC: ${LST_SRC}" )
#generate_avr_firmware( ${PROJECT_NAME}
#    SRCS ${LST_SRC}
#)

# Alternative: by variables
#set(blink_SRCS blink.cpp)
#set(blink_LIBS blink_lib)
#set(blink_BOARD uno)
#
#generate_arduino_firmware(blink)
