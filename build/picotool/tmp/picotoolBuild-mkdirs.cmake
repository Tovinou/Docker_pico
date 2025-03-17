# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/_deps/picotool-src"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/_deps/picotool-build"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/_deps"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/picotool/tmp"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/picotool/src/picotoolBuild-stamp"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/picotool/src"
  "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/picotool/src/picotoolBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/picotool/src/picotoolBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/c/Jensen/Embedded/Docker_pico/pico_zero/build/picotool/src/picotoolBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
