#!/bin/sh
################################################################################
###
### @file       build.sh
###
### @project    bcm5719
###
### @brief      Top level build script.
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2020, Evan Lojewski
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

GENERATOR=
BUILD_DIR=build
ARGS="$@"

if [ ! -x "$CMAKE" ]
then
    CMAKE=$(which cmake3)
    if [ ! -x "$CMAKE" ]
    then
        CMAKE=$(which cmake)
        if [ ! -x "$CMAKE" ]
        then
            echo "ERROR: Unable to locate cmake."
            exit 127
        fi
    fi
fi

if [ ! -x "$CPACK" ]
then
    CPACK=$(which cpack3)
    if [ ! -x "$CPACK" ]
    then
        CPACK=$(which cpack)
        if [ ! -x "$CPACK" ]
        then
            echo "ERROR: Unable to locate cpack."
            exit 127
        fi
    fi
fi

NINJA=$(which ninja-build)
if [ -x "$NINJA" ]
then
    GENERATOR=-GNinja
else
    NINJA=$(which ninja)
    if [ -x "$NINJA" ]
    then
        GENERATOR=-GNinja
    else
        echo "WARNING: Unable to locate ninja."
    fi
fi

echo "Using cmake: $CMAKE $GENERATOR"

set -e

# Clean out the build folder.
"$CMAKE" -E remove_directory "$BUILD_DIR"
"$CMAKE" -E make_directory "$BUILD_DIR"

cd "$BUILD_DIR"

# Do the build
"$CMAKE" .. $GENERATOR $ARGS
"$CMAKE" --build .

# Ensure formatting is correct
"$CMAKE" --build . --target check-format

# Run the tests
"$CMAKE" --build . --target test

# Generate release packages.
"$CMAKE" --build . --target package
# Work around an issue with --target package_source that fails due to ('s in the path
"$CPACK" --config ./CPackSourceConfig.cmake
