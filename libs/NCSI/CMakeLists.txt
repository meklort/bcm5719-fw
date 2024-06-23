################################################################################
###
### @file       libs/Ethernet/CMakeLists.txt
###
### @project
###
### @brief      NCSI CMake file
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2019-2020, Evan Lojewski
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

project(NCSI)

SET(SOURCES
    ncsi.c
    include/NCSI.h
    include/Ethernet.h
)

# Host Simulation library
simulator_add_library(${PROJECT_NAME} STATIC ncsi.c)
target_link_libraries(${PROJECT_NAME} PRIVATE simulator MII APE)
target_link_libraries(${PROJECT_NAME} PUBLIC Network)
target_include_directories(${PROJECT_NAME} PUBLIC ../../include)
target_include_directories(${PROJECT_NAME} PUBLIC include)

IF("${CMAKE_C_COMPILER_VERSION}" VERSION_GREATER_EQUAL "10.0.0")
# Note: Ignore a few warnings from compiling c as c++ files on llvm 10.
target_compile_options(${PROJECT_NAME} PRIVATE -Wno-c99-designator -Wno-reorder-init-list)
ENDIF()

# ARM Library
arm_add_library(${PROJECT_NAME}-arm STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME}-arm PRIVATE MII-arm APE-arm printf-arm)
target_link_libraries(${PROJECT_NAME}-arm PUBLIC Network-arm)
target_include_directories(${PROJECT_NAME}-arm PUBLIC ../../include)
target_include_directories(${PROJECT_NAME}-arm PUBLIC include)

format_target_sources(${PROJECT_NAME})

ADD_ENDIANNESS_DEFINES(${PROJECT_NAME})

add_subdirectory(tests)
