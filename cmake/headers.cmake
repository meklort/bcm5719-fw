################################################################################
###
### @file       headers.cmake
###
### @project
###
### @brief      Header auto-detection
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

# Import the CHECK_INCLUDE_FILES macros
include(CheckIncludeFiles)
CHECK_INCLUDE_FILES("endian.h" ENDIANNESS_CONFIG_HAVE_ENDIAN_H)
CHECK_INCLUDE_FILES("sys/endian.h" ENDIANNESS_CONFIG_HAVE_SYS_ENDIAN_H)
CHECK_INCLUDE_FILES("linux/ethtool.h" CONFIG_HAVE_LINUX_ETHTOOL_H)

FUNCTION(ADD_ENDIANNESS_DEFINES TARGET)
    IF(ENDIANNESS_CONFIG_HAVE_ENDIAN_H)
        target_compile_definitions(${TARGET} PRIVATE "-DENDIANNESS_CONFIG_HAVE_ENDIAN_H=1")
    ENDIF()

    IF(ENDIANNESS_CONFIG_HAVE_SYS_ENDIAN_H)
        target_compile_definitions(${TARGET} PRIVATE "-DENDIANNESS_CONFIG_HAVE_SYS_ENDIAN_H=1")
    ENDIF()
ENDFUNCTION()

FUNCTION(ADD_ETHTOOL_DEFINES TARGET)
    IF(CONFIG_HAVE_LINUX_ETHTOOL_H)
        target_compile_definitions(${TARGET} PRIVATE "-DCONFIG_HAVE_LINUX_ETHTOOL_H=1")
    ENDIF()
ENDFUNCTION()
