# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# compile ASM with /usr/bin/arm-none-eabi-gcc
ASM_DEFINES = -DLIB_BOOT_STAGE2_HEADERS=1 -DPICO_32BIT=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_RP2040=1

ASM_INCLUDES = -I/home/komlan/pico-sdk/src/rp2040/boot_stage2/asminclude -isystem /home/komlan/pico-sdk/src/rp2040/hardware_regs/include -isystem /home/komlan/pico-sdk/src/rp2_common/hardware_base/include -isystem /home/komlan/pico-sdk/src/common/pico_base_headers/include -isystem /mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/generated/pico_base -isystem /home/komlan/pico-sdk/src/boards/include -isystem /home/komlan/pico-sdk/src/rp2040/pico_platform/include -isystem /home/komlan/pico-sdk/src/rp2_common/pico_platform_compiler/include -isystem /home/komlan/pico-sdk/src/rp2_common/pico_platform_panic/include -isystem /home/komlan/pico-sdk/src/rp2_common/pico_platform_sections/include -isystem /home/komlan/pico-sdk/src/rp2040/boot_stage2/include

ASM_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g

