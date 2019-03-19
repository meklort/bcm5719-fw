################################################################################
###
### @file       CMakeLists.txt
###
### @project    bcm5719
###
### @brief      First binary stage for the bcm5719
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


project(stage1)

# Firmware
set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/stage1.ld")
mips_add_executable(${PROJECT_NAME}
            init_hw.c
            main.c
            crt.s)
mips_linker_script(${PROJECT_NAME} ${LINKER_SCRIPT})

target_link_libraries(${PROJECT_NAME} NVRam-mips MII-mips VPD-mips APE-mips)
target_link_libraries(${PROJECT_NAME} bcm5719)
target_compile_options(${PROJECT_NAME} PRIVATE -nodefaultlibs)


# Simulator add_executable
simulator_add_executable(sim-${PROJECT_NAME}
            init_hw.c
            main.c)

target_link_libraries(sim-${PROJECT_NAME} simulator)
target_link_libraries(sim-${PROJECT_NAME} NVRam MII VPD APE)
