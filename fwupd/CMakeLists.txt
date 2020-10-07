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

# Generate the Changelog for LVFS/FWUPD
SET(FWUPD_TOPCIS APE Stage1)
# Convert o lower case while preserving original case.
FOREACH(TOPIC IN LISTS FWUPD_TOPCIS)
    STRING(TOLOWER "${TOPIC}" TOPIC_LOWER)
    SET(FWUPD_${TOPIC_LOWER}_NAME ${TOPIC})
ENDFOREACH()
STRING(TOLOWER "${FWUPD_TOPCIS}" FWUPD_TOPCIS)

STRING(REPLACE "\n" ";" CHANGELIST ${CHANGELOG})

# Sort the changelog by topics.
FOREACH(CHANGE IN LISTS CHANGELIST)
    # Find changes in the format of "topic: subject (#GHID)"
    STRING(REGEX MATCHALL "([^:]*):[ \t\r\n]*(.*)(\\(#[0-9]*\\))" FOUND "${CHANGE}")
    IF(FOUND)
        SET(TOPIC ${CMAKE_MATCH_1})
        SET(SUBJECT ${CMAKE_MATCH_2})
        SET(GITHUB_ID ${CMAKE_MATCH_3})
    ELSE()
        # Find changes in the format of "topic: subject"
        STRING(REGEX MATCHALL "([^:]*):[ \t\r\n]*(.*)" FOUND "${CHANGE}")
        SET(TOPIC ${CMAKE_MATCH_1})
        SET(SUBJECT ${CMAKE_MATCH_2})
        SET(GITHUB_ID False)
    ENDIF()
    STRING(TOLOWER "${TOPIC}" TOPIC)

    IF(TOPIC IN_LIST FWUPD_TOPCIS)
        string(STRIP ${CMAKE_MATCH_2} CMAKE_MATCH_2)
        LIST(APPEND FWUPD_CHANGELOG_${TOPIC} ${CMAKE_MATCH_2})
    ENDIF()
ENDFOREACH()

SET(FWUPD_CHANGELOG )
FOREACH(TOPIC IN LISTS FWUPD_TOPCIS)
    IF(FWUPD_CHANGELOG_${TOPIC})
        LIST(APPEND FWUPD_CHANGELOG "                <p>${FWUPD_${TOPIC}_NAME} Changes:</p>")
        LIST(APPEND FWUPD_CHANGELOG "                <ul>")
        FOREACH(CHANGE IN LISTS FWUPD_CHANGELOG_${TOPIC})
            LIST(APPEND FWUPD_CHANGELOG "                    <li>${CHANGE}</li>")
        ENDFOREACH()
        LIST(APPEND FWUPD_CHANGELOG "                </ul>")
    ENDIF()
ENDFOREACH()
STRING(REPLACE ";" "\n" FWUPD_CHANGELOG "${FWUPD_CHANGELOG}")

SET(DESCRIPTION
    "<p>This stable release has the following changes:</p>\n${FWUPD_CHANGELOG}")


configure_file(talos2-metainfo.xml.in com.meklort.bcm5719.talos2.metainfo.xml)
configure_file(blackbird-metainfo.xml.in com.meklort.bcm5719.blackbird.metainfo.xml)
configure_file(kh08p-metainfo.xml.in com.meklort.bcm5719.kh08p.metainfo.xml)

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
    DEPENDS
        com.meklort.bcm5719.talos2.metainfo.xml
        talos2-port0.${VERSION_STRING}.fw
)

add_custom_command(OUTPUT blackbird-port2.${VERSION_STRING}.fw
    COMMAND bcmflash -c -t file -i blackbird-port2.${VERSION_STRING}.fw
        -1 $<TARGET_PROPERTY:stage1,RESOURCE>
        -a $<TARGET_PROPERTY:ape-port2,RESOURCE>
    DEPENDS stage1 ape-port2
    VERBATIM
)

add_custom_command(OUTPUT blackbird-bcm5719-${VERSION_STRING}.cab
    COMMAND ${GCAB} -c -z blackbird-bcm5719-${VERSION_STRING}.cab
        com.meklort.bcm5719.blackbird.metainfo.xml
        blackbird-port2.${VERSION_STRING}.fw
    DEPENDS
        com.meklort.bcm5719.talos2.metainfo.xml
        blackbird-port2.${VERSION_STRING}.fw
)

add_custom_command(OUTPUT kh08p-bcm5719-${VERSION_STRING}.cab
    COMMAND ${GCAB} -c -z kh08p-bcm5719-${VERSION_STRING}.cab
        com.meklort.bcm5719.kh08p.metainfo.xml
        talos2-port0.${VERSION_STRING}.fw
    DEPENDS
        com.meklort.bcm5719.kh08p.metainfo.xml
        talos2-port0.${VERSION_STRING}.fw
)
add_custom_target(
    fwupd ALL
    DEPENDS talos2-bcm5719-${VERSION_STRING}.cab
            blackbird-bcm5719-${VERSION_STRING}.cab
            kh08p-bcm5719-${VERSION_STRING}.cab
)

INSTALL(FILES
            "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/talos2-bcm5719-${VERSION_STRING}.cab"
            "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/blackbird-bcm5719-${VERSION_STRING}.cab"
            "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/kh08p-bcm5719-${VERSION_STRING}.cab"
        DESTINATION
            fwupd
)
