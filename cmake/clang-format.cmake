################################################################################
###
### @file       clang-format.cmake
###
### @project    
###
### @brief      clang-format cmake support
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

IF(CMAKE_SCRIPT_MODE_FILE)
    SET(ARGUMENTS )
    SET(CLANG_FORMAT ${CMAKE_ARGV4})
    SET(FILES ${CMAKE_ARGV5})

    IF(CHECK)
        SET(ERROR_FILES )
        FOREACH(FILE ${FILES})
            MESSAGE("Checking ${FILE}")
            EXECUTE_PROCESS(COMMAND ${CLANG_FORMAT} -style=file --output-replacements-xml "${FILE}" 
                            OUTPUT_VARIABLE OUT RESULT_VARIABLE RES)
            STRING(REGEX MATCH "<replacement " MATCHES ${OUT})
            IF(MATCHES)
                LIST(APPEND ERROR_FILES ${FILE})
            ENDIF()
        ENDFOREACH()

        IF(ERROR_FILES)
            FOREACH(FILE ${ERROR_FILES})
                MESSAGE("Invalid formatting: ${FILE}")
            ENDFOREACH()
            MESSAGE(FATAL_ERROR "Invalid formatting detected. Please run check-format")
        ENDIF()
    ELSE()
        FOREACH(FILE ${FILES})
            MESSAGE("Formatting ${FILE}")
            EXECUTE_PROCESS(COMMAND ${CLANG_FORMAT} -style=file -i "${FILE}")
        ENDFOREACH()
    ENDIF()
ELSE()

    SET(CLANG_FORMAT ${COMPILER_BASE}/bin/clang-format)
    ADD_CUSTOM_TARGET(clang-format cmake -DCHECK=False -P ${CMAKE_CURRENT_LIST_FILE}
                        ${CLANG_FORMAT} $<TARGET_PROPERTY:clang-format,FORMAT_SOURCES>
                        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                        VERBATIM)

    ADD_CUSTOM_TARGET(check-format cmake -DCHECK=True -P ${CMAKE_CURRENT_LIST_FILE}
                        ${CLANG_FORMAT} $<TARGET_PROPERTY:clang-format,FORMAT_SOURCES>
                        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                        VERBATIM)

    FUNCTION(format_sources)
        MESSAGE("Formatting sources ${ARGN}")

        SET_PROPERTY(TARGET clang-format APPEND PROPERTY FORMAT_SOURCES ${ARGN})
    ENDFUNCTION(format_sources)

    FUNCTION(format_target_sources target)
        SET(paths )
        GET_TARGET_PROPERTY(sources ${target} SOURCES)
        FOREACH(source ${sources})
            GET_SOURCE_FILE_PROPERTY(type ${source} LANGUAGE)
            GET_SOURCE_FILE_PROPERTY(path ${source} LOCATION)
            GET_FILENAME_COMPONENT(ext ${path} EXT)
            IF("${type}" STREQUAL "C" OR "${type}" STREQUAL "CXX" OR "${ext}" STREQUAL ".h")
                LIST(APPEND paths ${path})
            ENDIF()
        ENDFOREACH()

        format_sources(${paths})
    ENDFUNCTION(format_target_sources)
ENDIF()