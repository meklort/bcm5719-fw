################################################################################
###
### @file       CMakeLists.txt
###
### @project
###
### @brief      Top level CMake file
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

enable_testing()
include(GoogleTest)

SET(COMPILER_BASE       $ENV{HOME}/llvm-bcm5719)


FIND_PROGRAM(CMAKE_C_COMPILER
            NAMES flint_bcm5719-clang clang
            HINTS ${COMPILER_BASE}/bin/
            NO_DEFAULT_PATH
            REQUIRED)

FIND_PROGRAM(CMAKE_CXX_COMPILER
            NAMES flint_bcm5719-clang++ clang++
            HINTS ${COMPILER_BASE}/bin/
            NO_DEFAULT_PATH
            REQUIRED)

SET(CMAKE_ASM_COMPILER  ${COMPILER_BASE}/bin/clang)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions")

include(cmake/version.cmake)

cmake_minimum_required(VERSION 3.5.1)
project(bcm5719-fw VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

include(cmake/clang-format.cmake)
include(cmake/clang-analyzer.cmake)
include(cmake/config.cmake)

add_subdirectory(tests)

add_subdirectory(libs)
add_subdirectory(utils)


add_subdirectory(simulator)
add_subdirectory(stage1)

add_subdirectory(ape)

add_subdirectory(fwupd)
