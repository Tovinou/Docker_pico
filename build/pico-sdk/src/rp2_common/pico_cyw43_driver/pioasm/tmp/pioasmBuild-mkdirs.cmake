# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/komlan/pico-sdk/tools/pioasm"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/pioasm"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/pioasm-install"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
