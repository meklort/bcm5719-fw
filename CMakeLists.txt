################################################################################
###
### @file       CMakeLists.txt
###
### @project    
###
### @brief      Top level CMake file
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2018, Evan Lojewski
### @cond
###
### All rights reserved.
###
### Redistribution and use in source and binary forms, with or without
### modification, are permitted provided that the following conditions are met:
### 1. Redistributions of source code must retain the above copyright notice,
### this list of conditions and the following disclaimer.
### 2. Redistributions in binary form must reproduce the above copyright notice,
### this list of conditions and the following disclaimer in the documentation
### and/or other materials provided with the distribution.
### 3. Neither the name of the copyright holder nor the
### names of its contributors may be used to endorse or promote products
### derived from this software without specific prior written permission.
###
################################################################################
###
### THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
### AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
### IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
### ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
### LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
### CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
### SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
### INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
### CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
### ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
### POSSIBILITY OF SUCH DAMAGE.
### @endcond
################################################################################

cmake_minimum_required(VERSION 3.11)

IF(NOT DOES_BUILD)

include(ExternalProject)

ExternalProject_Add(simulator 
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    CMAKE_ARGS -DCMAKE_USER_MAKE_RULES_OVERRIDE=cmake/SimulatorMakeRulesOverwrite.cmake -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/
    USES_TERMINAL_BUILD 1
    USES_TERMINAL_CONFIGURE 1
    USES_TERMINAL_INSTALL 1
    BUILD_ALWAYS 1
)

ExternalProject_Add(firmware 
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    CMAKE_ARGS -DCMAKE_USER_MAKE_RULES_OVERRIDE=cmake/FirmwareMakeRulesOverwrite.cmake -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/fw -DCMAKE_TOOLCHAIN_FILE=cmake/MIPSToolchain.cmake
    USES_TERMINAL_BUILD 1
    USES_TERMINAL_CONFIGURE 1
    USES_TERMINAL_INSTALL 1
    BUILD_ALWAYS 1
)

ELSE()

add_definitions(-Werror -Wall -Os
    -ffunction-sections
    -fdata-sections
)

IF(NOT SIMULATOR)
add_definitions(-nodefaultlibs)
ENDIF()

IF(SIMULATOR)
add_definitions(-DCXX_SIMULATOR)
add_subdirectory(simulator)
add_subdirectory(utils)
ENDIF(SIMULATOR)

add_subdirectory(libs)


IF(SIMULATOR)
add_subdirectory(tests)
ENDIF(SIMULATOR)

add_subdirectory(stage0)

# add_subdirectory(bcmflash)
# add_subdirectory(bcmfwtool)
ENDIF()