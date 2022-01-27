################################################################################
###
### @file       CMakeLists.txt
###
### @project    bcm5719
###
### @brief      CMake configuration file for generating fwupd packages.
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2020, Evan Lojewski
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

SET(APP_STREAM_PREFIX   com.raptorcs.bcm5719.firmware)

add_custom_target(fwupd ALL)

FUNCTION(CREATE_FWUPD_CAB TARGET_ID TARGET_NAME VARIANT FIRMWARE_ID HARDWARE_ID)
    IF(HARDWARE_ID)
        SET(HARDWARE_FILTER "<hardware>${HARDWARE_ID}</hardware>")
    ELSE()
        SET(HARDWARE_FILTER "")
    ENDIF()
    configure_file(metainfo.xml.in ${APP_STREAM_PREFIX}.${TARGET_ID}.metainfo.xml @ONLY)

    add_custom_command(OUTPUT ${TARGET_ID}-${VARIANT}.${VERSION_STRING}.fw
        COMMAND bcmflash -c ${TARGET_ID} -t file -i ${TARGET_ID}-${VARIANT}.${VERSION_STRING}.fw
            -1 $<TARGET_PROPERTY:stage1-${VARIANT},RESOURCE>
            -a $<TARGET_PROPERTY:ape-${VARIANT},RESOURCE>
        COMMAND touch -d "${VERSION_TIMESTAMP}" ${TARGET_ID}-${VARIANT}.${VERSION_STRING}.fw
        DEPENDS stage1-${VARIANT} ape-${VARIANT}
        VERBATIM
    )

    add_custom_command(OUTPUT ${TARGET_ID}-bcm5719-${VERSION_STRING}.cab
    COMMAND touch -d "${VERSION_TIMESTAMP}" ${APP_STREAM_PREFIX}.${TARGET_ID}.metainfo.xml
    COMMAND ${GCAB} -c -z ${TARGET_ID}-bcm5719-${VERSION_STRING}.cab
            ${APP_STREAM_PREFIX}.${TARGET_ID}.metainfo.xml
            ${TARGET_ID}-${VARIANT}.${VERSION_STRING}.fw
        DEPENDS
            ${APP_STREAM_PREFIX}.${TARGET_ID}.metainfo.xml
            ${TARGET_ID}-${VARIANT}.${VERSION_STRING}.fw
    )

    add_custom_target(build-${TARGET_ID}-bcm5719-${VERSION_STRING}.cab DEPENDS ${TARGET_ID}-bcm5719-${VERSION_STRING}.cab)
    add_dependencies(fwupd build-${TARGET_ID}-bcm5719-${VERSION_STRING}.cab)

    INSTALL(FILES
            "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_ID}-bcm5719-${VERSION_STRING}.cab"
        DESTINATION
            fwupd
    )
ENDFUNCTION()

include(changelog.cmake)

SET(DESCRIPTION
    "<p>This stable release has the following changes:</p>\n${FWUPD_CHANGELOG}")


# Build LVFS/fwupd cab files
CREATE_FWUPD_CAB(
    talos2 "Talos II" port0
    "5d8b12bf-1973-58fc-8b31-3e50fe31954d" # PCI\VEN_14E4&DEV_1657&SUBSYS_14E41981
    "8e28b419-552d-52a6-9a3c-ea2efad5ea66|88201a40-2d9d-51c5-b1ee-ec58659bc701" # Restrict to HardwareID-10: "IBM" + "rcs,talos" + "RAPTOR COMP SYS" + "T2P9D01 REV 1.00" and "T2P9D01 REV 1.01"
)
CREATE_FWUPD_CAB(
    blackbird "Blackbird" port2
    "5d8b12bf-1973-58fc-8b31-3e50fe31954d" # PCI\VEN_14E4&DEV_1657&SUBSYS_14E41981
    "9153212f-20c7-5457-a287-22e08f79ea0e" # Restrict to HardwareID-10: "IBM" + "rcs,blackbird" + "RAPTOR COMP SYS" + "C1P9S01 REV 1.01"
)

# Test LVFS file for the KH08P. Should not be used in production.
# This firmware is only useful for testing fwupd with a KH08P and should
# never be pushed into a testing or stable remote!
# The FIXME below will ensure that the LVFS would block any promotion out
# of private or embargo.
SET(DESCRIPTION
    "<p>NCSI support is not implemented via MCTP. As a result, remote management capabilities are not supported on this card.</p>
                <p>This stable release has the following changes:</p>\n${FWUPD_CHANGELOG}")
CREATE_FWUPD_CAB(
    kh08p "FIXME KH08P" port0
    "ec5b8a9e-973b-58cc-935b-8322fabaebe9" # PCI\VEN_14E4&DEV_1657&SUBSYS_14E41904
    False # No hardware Restrictions
)
