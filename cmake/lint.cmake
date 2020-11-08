################################################################################
###
### @file       lint.cmake
###
### @project
###
### @brief      Lint specific support routines
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

SET(LINT_DUMMY ${CMAKE_CURRENT_LIST_DIR}/lint-dummy.c)

FUNCTION(generate_lint_config COMPILER_OPTIONS OUTPUT_LNT OUTPUT_H)
    MESSAGE(STATUS "Generating ${OUTPUT_LNT}")
    execute_process(
        COMMAND "${CMAKE_C_COMPILER}" -DNO_FLINT ${COMPILER_OPTIONS} -dM -E "${LINT_DUMMY}"
        OUTPUT_VARIABLE DEFINES
    )

    configure_file(".clang.h.in" ${OUTPUT_H})

    execute_process(
        COMMAND "${CMAKE_C_COMPILER}" -DNO_FLINT ${ARM_COMPILE_OPTIONS} -v "${LINT_DUMMY}"
        ERROR_VARIABLE VERBOSE_OUT
        ERROR_STRIP_TRAILING_WHITESPACE
    )
    STRING(REPLACE "\n" ";" VERBOSE_OUT "${VERBOSE_OUT}")
    SET(SYSTEM_INCLUDES )
    SET(ADD_INCLUDES False)

    FOREACH(line IN LISTS VERBOSE_OUT)
        IF("${line}" STREQUAL "End of search list.")
            # End of list
            break()
        ENDIF()

        IF(ADD_INCLUDES)
            STRING(STRIP "${line}" line)
            LIST(APPEND SYSTEM_INCLUDES ${line})
        ENDIF()

        IF("${line}" STREQUAL "#include <...> search starts here:")
            # Beginning of list.
            SET(ADD_INCLUDES True)
        ENDIF()
    ENDFOREACH()

    SET(INCLUDES )
    FOREACH(include IN LISTS SYSTEM_INCLUDES)
        LIST(APPEND INCLUDES "+libdir(${include})")
        LIST(APPEND INCLUDES "--i${include}")
    ENDFOREACH()
    STRING(REPLACE ";" "\n" INCLUDES "${INCLUDES}")

    configure_file(".clang.lnt.in" ${OUTPUT_LNT})
ENDFUNCTION()
