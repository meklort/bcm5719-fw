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

SET(MIPS_COMPILE_OPTIONS -nostdlib -nodefaultlibs -fomit-frame-pointer -target mips -mcpu=mips2 )
SET(MIPS_LINK_OPTIONS --gc-sections)
# SET(CMAKE_EXE_LINKER_FLAGS -static)

# ASM files
SET(CMAKE_INCLUDE_FLAG_ASM "-I")
SET(CMAKE_ASM_COMPILE_OBJECT "<CMAKE_ASM_COMPILER> -x assembler-with-cpp <DEFINES> <INCLUDES> <FLAGS> -o <OBJECT> -c <SOURCE>")

SET(CMAKE_mips_LINK_EXECUTABLE "${COMPILER_BASE}/bin/ld.lld  <OBJECTS> <LINK_LIBRARIES> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> -Bstatic -o <TARGET>")

generate_lint_config("${MIPS_COMPILE_OPTIONS}" ${CMAKE_BINARY_DIR}/clang-mips.lnt)

# MIPS-specific executables
function(mips_add_executable target)
    add_executable(${target} ${ARGN})

    target_compile_options(${target} PRIVATE ${MIPS_COMPILE_OPTIONS})
    target_link_libraries(${target} ${MIPS_LINK_OPTIONS})
    set_property(TARGET ${target} PROPERTY LINKER_LANGUAGE mips)

    add_custom_command(
        TARGET ${target} POST_BUILD
        COMMAND ${COMPILER_BASE}/bin/llvm-objcopy -O binary ${target} ${target}.bin
        BYPRODUCTS ${target}.bin)

    set_target_properties(${target} PROPERTIES RESOURCE ${CMAKE_CURRENT_BINARY_DIR}/${target}.bin)
    set_target_properties(${target} PROPERTIES LINT_CONFIG ${CMAKE_BINARY_DIR}/clang-mips.lnt)

endfunction(mips_add_executable)

# MIPS-specific libraries
function(mips_add_library target)
    add_library(${target} ${ARGN})

    target_compile_options(${target} PRIVATE ${MIPS_COMPILE_OPTIONS})
    set_target_properties(${target} PROPERTIES LINT_CONFIG ${CMAKE_BINARY_DIR}/clang-mips.lnt)
endfunction(mips_add_library)

function(mips_linker_script target script)
    set_property(TARGET ${target} APPEND APPEND_STRING PROPERTY LINK_FLAGS "--script=\"${script}\"")

    set_target_properties(${target} PROPERTIES LINK_DEPENDS ${script})
endfunction(mips_linker_script)
