################################################################################
###
### @file       changelog.cmake
###
### @project    bcm5719
###
### @brief      fwupd support code for generating a changelog.
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

# List all topics here that should be included in the release notes.
SET(FWUPD_TOPICS LVFS APE Stage1)

# Convert to lower case while preserving original case.
FOREACH(TOPIC IN LISTS FWUPD_TOPICS)
    STRING(TOLOWER "${TOPIC}" TOPIC_LOWER)
    SET(FWUPD_${TOPIC_LOWER}_NAME ${TOPIC})
ENDFOREACH()
STRING(TOLOWER "${FWUPD_TOPICS}" FWUPD_TOPICS)

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

    IF(TOPIC IN_LIST FWUPD_TOPICS)
        string(STRIP ${CMAKE_MATCH_2} CMAKE_MATCH_2)
        LIST(APPEND FWUPD_CHANGELOG_${TOPIC} ${CMAKE_MATCH_2})
    ENDIF()
ENDFOREACH()

SET(FWUPD_CHANGELOG )
FOREACH(TOPIC IN LISTS FWUPD_TOPICS)
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
