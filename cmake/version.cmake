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
SET(VERSION_MINOR 4)
SET(VERSION_PATCH )

SET(VERSION_FILE ${CMAKE_SOURCE_DIR}/version)
IF(EXISTS ${VERSION_FILE})
    # Release package including a version file.
    FILE(STRINGS ${VERSION_FILE} lines)
    LIST(GET lines 0 FULL_VERSION)
    STRING(REPLACE "." ";" FULL_VERSION ${FULL_VERSION})

    LIST(GET FULL_VERSION 0 VERSION_MAJOR)
    LIST(GET FULL_VERSION 1 VERSION_MINOR)
    LIST(GET FULL_VERSION 2 VERSION_PATCH)
ELSE()
    # Within a git repository
    EXECUTE_PROCESS(COMMAND git rev-list --count HEAD
                    OUTPUT_VARIABLE VERSION_PATCH
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
ENDIF()

SET(VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

add_compile_options(
    -DVERSION_MAJOR=${VERSION_MAJOR}
    -DVERSION_MINOR=${VERSION_MINOR}
    -DVERSION_PATCH=${VERSION_PATCH}
)

FILE(WRITE ${CMAKE_BINARY_DIR}/version ${VERSION_STRING})

INSTALL(FILES ${CMAKE_BINARY_DIR}/version DESTINATION .)
