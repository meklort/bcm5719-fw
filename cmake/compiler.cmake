################################################################################
###
### @file       CMakeLists.txt
###
### @project
###
### @brief      compiler configuration
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2018-2022, Evan Lojewski
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

SET(COMPILER_BASE $ENV{HOME}/llvm-bcm5719)

FIND_PROGRAM(CMAKE_C_COMPILER
            NAMES flint_bcm5719-clang clang
            HINTS ${COMPILER_BASE}/bin/
            NO_DEFAULT_PATH
            REQUIRED)

FIND_PROGRAM(CMAKE_CXX_COMPILER
            NAMES flint_bcm5719-clang++ clang++
            HINTS ${COMPILER_BASE}/bin/
            NO_DEFAULT_PATH
            REQUIRED)

SET(CMAKE_ASM_COMPILER  ${COMPILER_BASE}/bin/clang)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions")

# Extract Compiler version information
EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} --version OUTPUT_VARIABLE version OUTPUT_STRIP_TRAILING_WHITESPACE)
STRING(REGEX MATCH "(.*) version ([0-9]*.[0-9]*.[0-9]*) \\((.*) (.*)\\)" out ${version})
SET(COMPILER_NAME    ${CMAKE_MATCH_1})
SET(COMPILER_VERSION ${CMAKE_MATCH_2})
SET(COMPILER_URL     ${CMAKE_MATCH_3})
SET(COMPILER_HASH    ${CMAKE_MATCH_4})

# Generate SBOM GUID
USWID_UUID(COMPILER_TAG_ID "${COMPILER_NAME}-${COMPILER_VERSION}")

# Create the compiler uswid ini file
configure_file(${CMAKE_SOURCE_DIR}/cmake/compiler.uswid.ini.in ${CMAKE_BINARY_DIR}/compiler.uswid.ini @ONLY)
