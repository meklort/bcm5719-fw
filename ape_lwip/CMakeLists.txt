################################################################################
###
### @file       CMakeLists.txt
###
### @project    bcm5719
###
### @brief      APE stage for the bcm5719
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2018-2020, Evan Lojewski
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


project(ape_lwip)
# add_compile_options("-Osdf")
# Firmware
function(ape_firmware PORT)
    SET(TARGET ${PROJECT_NAME}-port${PORT})
    arm_add_executable(${TARGET}
                main.c
                localtime.c
                vectors.c
                rmu.c
                include/ape_main.h
                )
                arm_linker_script(${TARGET} "${CMAKE_CURRENT_SOURCE_DIR}/ape.ld")

    target_include_directories(${TARGET} PRIVATE include)
    target_link_libraries(${TARGET} NVRam-arm MII-arm APE-arm Network-arm NCSI-arm Timer-arm printf-arm FreeRTOS-arm lwip-arm)
    target_link_libraries(${TARGET} bcm5719-arm)
    target_link_libraries(${TARGET}
        --defsym=NETWORK_PORT=${PORT}
        --defsym=VERSION_MAJOR=${VERSION_MAJOR}
        --defsym=VERSION_MINOR=${VERSION_MINOR}
        --defsym=VERSION_PATCH=${VERSION_PATCH})
    target_compile_options(${TARGET} PRIVATE -nodefaultlibs)
    target_compile_definitions(${TARGET} PRIVATE NETWORK_PORT=${PORT})

    install(TARGETS ${TARGET} DESTINATION fw RESOURCE)

endfunction()

ape_firmware(0)
ape_firmware(2)

format_target_sources(${PROJECT_NAME}-port0)

# Simulator add_executable
# simulator_add_executable(sim-${PROJECT_NAME}
            # init_hw.c
            # main.c)

# target_link_libraries(sim-${PROJECT_NAME} simulator)
# target_link_libraries(sim-${PROJECT_NAME} NVRam MII VPD APE)
