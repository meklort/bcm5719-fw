################################################################################
###
### @file       arm.cmake
###
### @project
###
### @brief      ARM (Cortex-M3) specific configurations
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

SET(ARM_COMPILE_OPTIONS -nostdlib -nodefaultlibs -fomit-frame-pointer -target thumbv7-none-eabi -mcpu=cortex-m3 -mfloat-abi=soft -fno-builtin)
SET(ARM_LINK_OPTIONS --gc-sections)
# SET(CMAKE_EXE_LINKER_FLAGS -static)

# ASM files
SET(CMAKE_INCLUDE_FLAG_ASM "-I")
SET(CMAKE_ASM_COMPILE_OBJECT "<CMAKE_ASM_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -o <OBJECT> -c <SOURCE>")

SET(CMAKE_arm_LINK_EXECUTABLE "ld.lld  <OBJECTS> <LINK_LIBRARIES> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> -Bstatic -o <TARGET>")

# ARM-specific executables
function(arm_add_executable target)
    add_executable(${target} ${ARGN})

    target_compile_options(${target} PRIVATE ${ARM_COMPILE_OPTIONS})
    target_link_libraries(${target} ${ARM_LINK_OPTIONS})
    set_property(TARGET ${target} PROPERTY LINKER_LANGUAGE arm)

    add_custom_command(
        TARGET ${target} POST_BUILD
        COMMAND elf2ape -i ${target} -o ${target}.bin
        BYPRODUCTS ${target}.bin
        DEPENDS elf2ape)

    add_custom_command(
        OUTPUT ${target}.c
        COMMAND xxd -i ${target}.bin ${target}.c
        DEPENDS ${target}
        VERBATIM)

    # Add host binary
    add_library(${target}-binary EXCLUDE_FROM_ALL ${target}.c)
endfunction(arm_add_executable)

# ARM-specific libraries
function(arm_add_library target)
    add_library(${target} ${ARGN})

    target_compile_options(${target} PRIVATE ${ARM_COMPILE_OPTIONS})
endfunction(arm_add_library)

function(arm_linker_script target script)
    set_property(TARGET ${target} APPEND APPEND_STRING PROPERTY LINK_FLAGS "--script=\"${script}\"")

    set_target_properties(${target} PROPERTIES LINK_DEPENDS ${script})
endfunction(arm_linker_script)
