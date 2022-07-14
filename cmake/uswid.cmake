################################################################################
###
### @file       uswid.cmake
###
### @project
###
### @brief      USWID support routines
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2022, Evan Lojewski
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

FUNCTION(USWID_UUID var str)
    STRING(UUID ${var} NAMESPACE 6ba7b810-9dad-11d1-80b4-00c04fd430c8 NAME "${str}" TYPE SHA1)
    MESSAGE("Setting ${var} to ${${var}}")
    SET(${var} ${${var}} PARENT_SCOPE)
ENDFUNCTION()

FUNCTION(GENERATE_USWID target)
    # Find all uswid.ini files and geenerate the uswid payload.
    GET_PROPERTY(sources TARGET ${target} PROPERTY SOURCES)
    SET(swidinput )
    SET(depends )
    FOREACH(file IN LISTS sources)
        IF(${file} MATCHES ".*\\.uswid\\.ini$")
            GET_SOURCE_FILE_PROPERTY(path ${file} LOCATION)
            LIST(APPEND swidinput "--load" "${path}")
            LIST(APPEND depends "${file}")
        ENDIF()
    ENDFOREACH()

    # TODO: Make this resolve all swid files at compile time, not config time.
    IF(swidinput AND USWID_ENABLED)
        SET(SWID_FILE "${CMAKE_CURRENT_BINARY_DIR}/${target}.uswid")
        MESSAGE(STATUS "Creating ${SWID_FILE}")
        ADD_CUSTOM_COMMAND(
            OUTPUT ${SWID_FILE}
            COMMAND "uswid/cli.py" --compress ${swidinput} --save "${SWID_FILE}"
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/utils/python-uswid"
            DEPENDS ${depends}
            VERBATIM
        )
        ADD_CUSTOM_TARGET(${target}-swid DEPENDS ${SWID_FILE})
        SET_TARGET_PROPERTIES(${target}-swid PROPERTIES RESOURCE ${SWID_FILE})

        ADD_DEPENDENCIES(${target} ${target}-swid)
    ELSEIF(swidinput)
        MESSAGE(WARNING "Skipping ${target}.uswid")
    ENDIF()
ENDFUNCTION()
