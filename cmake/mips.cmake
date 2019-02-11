################################################################################
###
### @file       mips.cmake
###
### @project
###
### @brief      MIPS specific configurations
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

SET(MIPS_COMPILE_OPTIONS -nostdlib -nodefaultlibs -fomit-frame-pointer -target mips )
SET(MIPS_LINK_OPTIONS -static-libgcc)
SET(CMAKE_EXE_LINKER_FLAGS -static)

# ASM files
SET(CMAKE_INCLUDE_FLAG_ASM "-I")
SET(CMAKE_ASM_COMPILE_OBJECT "<CMAKE_ASM_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -o <OBJECT> -c <SOURCE>")

SET(CMAKE_mips_LINK_EXECUTABLE "ld.lld  <OBJECTS> <LINK_LIBRARIES> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> -Bstatic -o <TARGET>")

# MIPS-specific executables
function(mips_add_executable target)
    add_executable(${target} ${ARGN})

    target_compile_options(${target} PRIVATE ${MIPS_COMPILE_OPTIONS})
    set_property(TARGET ${target} APPEND PROPERTY LINK_OPTIONS ${MIPS_LINK_OPTIONS})
    set_property(TARGET ${target} PROPERTY LINKER_LANGUAGE mips)
endfunction(mips_add_executable)

# MIPS-specific libraries
function(mips_add_library target)
    add_library(${target} ${ARGN})

    target_compile_options(${target} PRIVATE ${MIPS_COMPILE_OPTIONS})
endfunction(mips_add_library)
