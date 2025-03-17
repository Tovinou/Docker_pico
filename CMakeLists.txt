cmake_minimum_required(VERSION 3.13)

# Set PICO_SDK_PATH if not already set
if (NOT DEFINED PICO_SDK_PATH)
    set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
endif()

# Force fetch picotool from git to resolve version mismatch
set(PICOTOOL_FORCE_FETCH_FROM_GIT ON CACHE BOOL "" FORCE)

# Include the SDK
include(pico_sdk_import.cmake)

# Set project name and language
project(pico_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Create include directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include)

# Add source files
add_executable(${PROJECT_NAME}
    main.c
    joystick.c
    sensor.c
    lcd.c
    server_2.c
    alarm.c
)

# Pull in common dependencies
target_link_libraries(${PROJECT_NAME} 
    pico_stdlib              # Basic SDK
    hardware_adc             # For joystick
    hardware_pwm             # For alarm buzzer
    hardware_gpio            # For general GPIO
    hardware_timer           # For timing functions
    pico_time               # For time functions
    hardware_i2c            # For LCD if using I2C
)

# Enable USB output, disable UART output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${PROJECT_NAME})

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${PICO_SDK_PATH}/src/common/pico_stdlib/include
    ${PICO_SDK_PATH}/src/rp2_common/hardware_gpio/include
    ${PICO_SDK_PATH}/src/rp2_common/hardware_adc/include
    ${PICO_SDK_PATH}/src/rp2_common/hardware_pwm/include
    ${PICO_SDK_PATH}/src/rp2_common/hardware_i2c/include
    ${PICO_SDK_PATH}/src/common/pico_time/include
    ${PICO_SDK_PATH}/src/rp2_common/hardware_timer/include
) 