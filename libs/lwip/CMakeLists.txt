################################################################################
###
### @file       libs/lwip/CMakeLists.txt
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

project(lwip)
SET(LWIP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lwip/)
include(lwip/src/Filelists.cmake)

SET(SOURCES
    ${lwipnoapps_SRCS}
    ${lwiphttp_SRCS}
    ${lwipiperf_SRCS}
    sys_arch.c
)

# ARM Library
arm_add_library(${PROJECT_NAME}-arm STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME}-arm PRIVATE FreeRTOS-arm printf-arm)
target_include_directories(${PROJECT_NAME}-arm PUBLIC ../../include)
target_include_directories(${PROJECT_NAME}-arm PUBLIC include)

target_include_directories(${PROJECT_NAME}-arm PUBLIC lwip/src/include)
target_include_directories(${PROJECT_NAME}-arm PUBLIC lwip/src/include)

target_include_directories(${PROJECT_NAME}-arm PRIVATE port)

set_source_files_properties(${LWIP_DIR}/src/core/ipv4/ip4.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting
set_source_files_properties(${LWIP_DIR}/src/core/inet_chksum.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting
# set_source_files_properties(${LWIP_DIR}/src/core/pbuf.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting
set_source_files_properties(${LWIP_DIR}/src/core/mem.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting
set_source_files_properties(${LWIP_DIR}/src/core/memp.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting
# set_source_files_properties(${LWIP_DIR}/src/core/netif.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting
# set_source_files_properties(${LWIP_DIR}/src/netif/ethernet.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting
set_source_files_properties(${LWIP_DIR}/src/core/tcp_in.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting
# set_source_files_properties(${LWIP_DIR}/src/core/tcp_out.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting

set_source_files_properties(${LWIP_DIR}/src/apps/lwiperf/lwiperf.c PROPERTIES COMPILE_OPTIONS "-O3") # Disable linting

# add_executable(mkfs lwip/src/apps/http/makefsdata/makefsdata.c)
# target_include_directories(mkfs PUBLIC ../../include)
# target_include_directories(mkfs PUBLIC include)

# target_include_directories(mkfs PUBLIC lwip/src/include)
# target_include_directories(mkfs PUBLIC lwip/src/include)

# target_include_directories(mkfs PRIVATE port)

# Disable errors due to linting until all issues are fixed.
target_compile_definitions(${PROJECT_NAME}-arm PRIVATE "-DNO_FLINT")
