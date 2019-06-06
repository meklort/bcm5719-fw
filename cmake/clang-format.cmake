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

if(CMAKE_SCRIPT_MODE_FILE)
	SET(ARGUMENTS )
	SET(CLANG_FORMAT ${CMAKE_ARGV3})
	SET(FILES ${CMAKE_ARGV4})

	FOREACH(FILE ${FILES})
		MESSAGE("Formatting ${FILE}")
		EXECUTE_PROCESS(COMMAND ${CLANG_FORMAT} -style=file -i "${FILE}")
		LIST(APPEND ARGUMENTS ${FILE})
	ENDFOREACH() 
else()

	SET(CLANG_FORMAT ${COMPILER_BASE}/bin/clang-format)
	add_custom_target(clang-format cmake -P ${CMAKE_CURRENT_LIST_FILE}
						${CLANG_FORMAT} $<TARGET_PROPERTY:clang-format,FORMAT_SOURCES>
						WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
						VERBATIM)

	function(format_sources)
		MESSAGE("Formatting sources ${ARGN}")

		set_property(TARGET clang-format APPEND PROPERTY FORMAT_SOURCES ${ARGN})
	endfunction(format_sources)

	function(format_target_sources target)
		set(paths )
		get_target_property(sources ${target} SOURCES)
		foreach(source ${sources})
			get_source_file_property(path ${source} LOCATION)
			LIST(APPEND paths ${path})
		endforeach()

		format_sources(${paths})
	endfunction(format_target_sources)
endif()