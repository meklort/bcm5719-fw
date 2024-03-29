################################################################################
###
### @file       utils/CMakeLists.txt
###
### @project
###
### @brief      Utilities CMake file
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

add_subdirectory(bcmregtool)
add_subdirectory(bcmflash)

add_subdirectory(apeconsole)

add_subdirectory(ape2elf)
add_subdirectory(elf2ape)

add_subdirectory(bin2c)
add_subdirectory(cat)

# Check to see if python3 is installed, as it's needed for uSWID generation.
FIND_PROGRAM(PYTHON NAMES python3 PATHS /usr/bin/)
IF (NOT PYTHON)
    MESSAGE(STATUS "Disabling uSWID generation due to missing python executable.")
    SET(USWID_ENABLED OFF)
    SEt(USWID_FORCE FORCE)
ELSE()
    MESSAGE(STATUS "Enabling uSWID generation.")
    SET(USWID_ENABLED ON)
    SEt(USWID_FORCE )
ENDIF()
SET(USWID_ENABLED ${USWID_ENABLED} CACHE BOOL "Include uSWID information in firmware image." ${USWID_FORCE})
