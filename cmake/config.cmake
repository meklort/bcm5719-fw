################################################################################
###
### @file       config.cmake
###
### @project    
###
### @brief      High level configuration
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

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall -Os -ffunction-sections -fdata-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall -Os -ffunction-sections -fdata-sections")

# Remove default libraries to ensure cross compilng works as expected.
SET(CMAKE_C_IMPLICIT_LINK_LIBRARIES "")
SET(CMAKE_CXX_IMPLICIT_LINK_LIBRARIES "")

# Settings and build rules for simulator targets
include(${CMAKE_CURRENT_LIST_DIR}/simulator.cmake)

# Settings and build rules for mips targets
include(${CMAKE_CURRENT_LIST_DIR}/mips.cmake)

# Settings and build rules for arm targets
include(${CMAKE_CURRENT_LIST_DIR}/arm.cmake)

# Settings for generating release packages
include(${CMAKE_CURRENT_LIST_DIR}/cpack.cmake)
