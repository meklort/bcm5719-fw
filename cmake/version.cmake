################################################################################
###
### @file       version.cmake
###
### @project    bcm5719
###
### @brief      Version configuration
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

SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 5)
SET(VERSION_PATCH )

SET(SEMVER_REGEX "v?(0|[1-9]*)\\.(0|[0-9]*)\\.(0|[0-9]*)")

SET(VERSION_FILE ${CMAKE_SOURCE_DIR}/version)
SET(CHANGELOG_FILE ${CMAKE_SOURCE_DIR}/changelog)
IF(EXISTS ${VERSION_FILE})
    # Release package including a version file.
    FILE(STRINGS ${VERSION_FILE} lines)
    LIST(GET lines 0 FULL_VERSION)
    LIST(GET lines 1 VERSION_DATE)
    LIST(GET lines 2 VERSION_TIMESTAMP)
    STRING(REPLACE "." ";" FULL_VERSION ${FULL_VERSION})

    LIST(GET FULL_VERSION 0 VERSION_MAJOR)
    LIST(GET FULL_VERSION 1 VERSION_MINOR)
    LIST(GET FULL_VERSION 2 VERSION_PATCH)

    # Read in changelog
    FILE(READ ${CHANGELOG_FILE} CHANGELOG)
ELSE()
    # Within a git repository

    # Find the previous tag. This should be in the format of "vMajor.Minor.Patch"
    # HEAD~1 is used here to ensure release tags build properly.
    EXECUTE_PROCESS(COMMAND git describe --abbrev=0 --tags HEAD~1
                    OUTPUT_VARIABLE PREVIOUS_TAG
                    OUTPUT_STRIP_TRAILING_WHITESPACE)

    STRING(REGEX MATCHALL "${SEMVER_REGEX}" DID_MATCH "${PREVIOUS_TAG}")
    SET(PREVIOUS_MAJOR ${CMAKE_MATCH_1})
    SET(PREVIOUS_MINOR ${CMAKE_MATCH_2})
    SET(PREVIOUS_PATCH ${CMAKE_MATCH_3})

    EXECUTE_PROCESS(COMMAND git rev-list --count ${PREVIOUS_TAG}..HEAD
                    OUTPUT_VARIABLE VERSION_PATCH
                    OUTPUT_STRIP_TRAILING_WHITESPACE)

    EXECUTE_PROCESS(COMMAND git log --pretty=format:%s ${PREVIOUS_TAG}..HEAD
                    OUTPUT_VARIABLE CHANGELOG
                    OUTPUT_STRIP_TRAILING_WHITESPACE)


    # If we are on the same Major/Minor version, continue increasing the patch version.
    IF("${PREVIOUS_MAJOR}.${PREVIOUS_MINOR}" VERSION_EQUAL "${VERSIN_MAJOR}.${VERSION_MINOR}")
        MATH(EXPR VERSION_PATCH "${PREVIOUS_PATCH} + ${VERSION_PATCH}")
    ELSEIF("${PREVIOUS_MAJOR}.${PREVIOUS_MINOR}" VERSION_GREATER "${VERSIN_MAJOR}.${VERSION_MINOR}")
        # We somehow regressed in versioning.
        MESSAGE(FATAL_ERROR "Last release ${PREVIOUS_TAG} is newer than current ${VERSION_MAJOR}.${VERSION_MINOR}.x")
    ELSE()
        # No released versions for this major.minor pair.
    ENDIF()

    EXECUTE_PROCESS(COMMAND git log -1 --date=short --format=%cd
                    OUTPUT_VARIABLE VERSION_DATE
                    OUTPUT_STRIP_TRAILING_WHITESPACE)

    EXECUTE_PROCESS(COMMAND git log -1 --date=short --format=%cD
                    OUTPUT_VARIABLE VERSION_TIMESTAMP
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
ENDIF()

SET(VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

add_compile_options(
    -DVERSION_MAJOR=${VERSION_MAJOR}
    -DVERSION_MINOR=${VERSION_MINOR}
    -DVERSION_PATCH=${VERSION_PATCH}
)

FILE(WRITE ${CMAKE_BINARY_DIR}/version "${VERSION_STRING}\n${VERSION_DATE}\n${VERSION_TIMESTAMP}")
FILE(WRITE ${CMAKE_BINARY_DIR}/changelog ${CHANGELOG})

INSTALL(FILES ${CMAKE_BINARY_DIR}/version DESTINATION .)
INSTALL(FILES ${CMAKE_BINARY_DIR}/changelog DESTINATION .)
