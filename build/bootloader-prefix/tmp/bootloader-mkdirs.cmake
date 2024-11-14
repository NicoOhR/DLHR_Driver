# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/nimoor/esp/esp-idf/components/bootloader/subproject"
  "/home/nimoor/Projects/dlhr_driver/build/bootloader"
  "/home/nimoor/Projects/dlhr_driver/build/bootloader-prefix"
  "/home/nimoor/Projects/dlhr_driver/build/bootloader-prefix/tmp"
  "/home/nimoor/Projects/dlhr_driver/build/bootloader-prefix/src/bootloader-stamp"
  "/home/nimoor/Projects/dlhr_driver/build/bootloader-prefix/src"
  "/home/nimoor/Projects/dlhr_driver/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/nimoor/Projects/dlhr_driver/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/nimoor/Projects/dlhr_driver/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
