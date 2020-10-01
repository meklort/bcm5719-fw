################################################################################
###
### @file       simulator.cmake
###
### @project    bcm5719-fw
###
### @brief      Simulator specific configurations
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

SET(SIMULATOR_COMPILE_OPTIONS -DCXX_SIMULATOR -x c++ -fno-rtti -fno-exceptions)
SET(SIMULATOR_LINK_OPTIONS )

# MIPS-specific executables
function(simulator_add_executable target)
    add_executable(${target} ${ARGN})

    target_compile_options(${target} PRIVATE ${SIMULATOR_COMPILE_OPTIONS})
    set_property(TARGET ${target} APPEND PROPERTY LINK_OPTIONS ${SIMULATOR_LINK_OPTIONS})
endfunction(simulator_add_executable)

# MIPS-specific libraries
function(simulator_add_library target)
    add_library(${target} ${ARGN})

    target_compile_options(${target} PRIVATE ${SIMULATOR_COMPILE_OPTIONS})
endfunction(simulator_add_library)
