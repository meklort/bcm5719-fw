################################################################################
###
### @file       libs/Network/CMakeLists.txt
###
### @project
###
### @brief      Network CMake file
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2019, Evan Lojewski
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

project(Network)

SET(SOURCES
    ports.c
    tx.c
    rx.c
    generic.c
#     include/Network.h
)
set_source_files_properties(rx.c PROPERTIES COMPILE_OPTIONS "-Ofast")
set_source_files_properties(tx.c PROPERTIES COMPILE_OPTIONS "-Ofast")

# Host Simulation library
simulator_add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE simulator NCSI MII APE)
target_include_directories(${PROJECT_NAME} PUBLIC ../../include)
target_include_directories(${PROJECT_NAME} PUBLIC include)

# ARM Library
arm_add_library(${PROJECT_NAME}-arm STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME}-arm PRIVATE NCSI-arm printf-arm MII-arm APE-arm)
target_include_directories(${PROJECT_NAME}-arm PUBLIC ../../include)
target_include_directories(${PROJECT_NAME}-arm PUBLIC include)

format_target_sources(${PROJECT_NAME})

# add_subdirectory(tests)

ADD_ENDIANNESS_DEFINES(${PROJECT_NAME})

# Disable errors due to linting until all isssues are fixed.
target_compile_definitions(${PROJECT_NAME}-arm PRIVATE "-DNO_FLINT_ERRORS")
