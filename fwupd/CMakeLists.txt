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


project(fwupd)

find_program(GCAB gcab)
IF(NOT GCAB)
    MESSAGE("Unable to locate gcab - disabling fwupd package generation")
    RETURN()
ENDIF()


SET(DESCRIPTION "Firmware update to improve stability.")

configure_file(talos2-metainfo.xml.in com.meklort.bcm5719.talos2.metainfo.xml)

add_custom_command(OUTPUT talos2-port0.${VERSION_STRING}.fw
    COMMAND bcmflash -c -t file -i talos2-port0.${VERSION_STRING}.fw
        -1 $<TARGET_PROPERTY:stage1,RESOURCE>
        -a $<TARGET_PROPERTY:ape-port0,RESOURCE>
    DEPENDS stage1 ape-port0
    VERBATIM
)

add_custom_command(OUTPUT talos2-bcm5719-${VERSION_STRING}.cab
    COMMAND ${GCAB} -c -z talos2-bcm5719-${VERSION_STRING}.cab
        com.meklort.bcm5719.talos2.metainfo.xml
        talos2-port0.${VERSION_STRING}.fw
    DEPENDS talos2-port0.${VERSION_STRING}.fw com.meklort.bcm5719.talos2.metainfo.xml
)
add_custom_target(fwupd ALL DEPENDS talos2-bcm5719-${VERSION_STRING}.cab)

INSTALL(FILES "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/talos2-bcm5719-${VERSION_STRING}.cab" DESTINATION fwupd)
