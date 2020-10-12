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

ADD_CUSTOM_TARGET(lint)

FUNCTION(lint_target_sources target)
    GET_PROPERTY(lint_cfg TARGET ${target} PROPERTY LINT_CONFIG)
    GET_PROPERTY(sources TARGET ${target} PROPERTY SOURCES)
    GET_PROPERTY(includes TARGET ${target} PROPERTY INCLUDE_DIRECTORIES)
    GET_PROPERTY(options TARGET ${target} PROPERTY COMPILE_OPTIONS)
    GET_PROPERTY(interface_includes TARGET ${target} PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
    # MESSAGE(FATAL_ERROR ${lint_cfg})
    SET(ARGS)

    # Pass along defines
    FOREACH(option IN LISTS options)
        STRING(FIND "${option}" "-D" IS_DEFINE)
        STRING(FIND "${option}" "-U" IS_UNDEFINE)
        IF(IS_DEFINE EQUAL 0 OR IS_UNDEFINE EQUAL 0)
            LIST(APPEND ARGS "${option}")
        ENDIF()
    ENDFOREACH()

    # Pass along includes
    FOREACH(include IN LISTS includes interface_includes)
        LIST(APPEND ARGS "-i${include}")
    ENDFOREACH()

    FOREACH(source ${sources})
        GET_SOURCE_FILE_PROPERTY(type ${source} LANGUAGE)
        GET_SOURCE_FILE_PROPERTY(path ${source} LOCATION)
        GET_FILENAME_COMPONENT(ext ${path} EXT)

        IF("${type}" STREQUAL "C" OR "${type}" STREQUAL "CXX")
            MESSAGE("Adding lint command for ${path}")

            ADD_CUSTOM_COMMAND(TARGET ${target} PRE_LINK
                COMMAND pclint $<TARGET_PROPERTY:${target},LINT_CONFIG> ${ARGS} ${defines} ${path}
                VERBATIM
            )
        ENDIF()
    ENDFOREACH()
ENDFUNCTION(lint_target_sources)


FUNCTION(generate_lint_config COMPILER_OPTIONS OUTPUT)
    SET(HEADER ${OUTPUT}.h)
    execute_process(
        COMMAND "${CMAKE_COMMAND}" -E touch "${CMAKE_BINARY_DIR}/dummy.c"
        COMMAND "${CMAKE_C_COMPILER}" ${COMPILER_OPTIONS} -dM -E "${CMAKE_BINARY_DIR}/dummy.c"
        OUTPUT_FILE ${HEADER}
    )
    execute_process(
        COMMAND "${CMAKE_COMMAND}" -E touch "${CMAKE_BINARY_DIR}/dummy.c"
        COMMAND "${CMAKE_C_COMPILER}" ${ARM_COMPILE_OPTIONS} -v "${CMAKE_BINARY_DIR}/dummy.c"
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
        LIST(APPEND INCLUDES "--i(${include})")
    ENDFOREACH()
    STRING(REPLACE ";" "\n" INCLUDES "${INCLUDES}")

    configure_file(".clang.lnt.in" ${OUTPUT})
ENDFUNCTION()
