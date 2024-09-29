////////////////////////////////////////////////////////////////////////////////
///
/// @file       fileio.cpp
///
/// @project    bcm5719-fw
///
/// @brief      Support routines for accessing files.
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018-2020, Evan Lojewski
/// @cond
///
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
/// 1. Redistributions of source code must retain the above copyright notice,
/// this list of conditions and the following disclaimer.
/// 2. Redistributions in binary form must reproduce the above copyright notice,
/// this list of conditions and the following disclaimer in the documentation
/// and/or other materials provided with the distribution.
/// 3. Neither the name of the copyright holder nor the
/// names of its contributors may be used to endorse or promote products
/// derived from this software without specific prior written permission.
///
////////////////////////////////////////////////////////////////////////////////
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
/// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
/// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
/// POSSIBILITY OF SUCH DAMAGE.
/// @endcond
////////////////////////////////////////////////////////////////////////////////

#include "bcmflash.h"

#include <fstream>
#include <iostream>
#include <stdio.h>

using std::fstream;

bool bcmflash_file_init(const char *name)
{
    (void)name;

    return true;
}

bool bcmflash_file_write(const char *name, void *buffer, size_t len)
{
    std::cout << "Writing to " << name << "." << std::endl;
    FILE *out = fopen(name, "w+");
    if (out)
    {
        fwrite(buffer, len, 1, out);
        fclose(out);
        return true;
    }
    else
    {
        std::cerr << "Unable to open " << name << " for writing." << std::endl;
        return false;
    }
}

size_t bcmflash_file_size(const char *name)
{
    fstream infile;
    infile.open(name, fstream::in | fstream::binary | fstream::ate);

    if (infile.is_open())
    {
        return infile.tellg();
    }

    return 0;
}

bool bcmflash_file_read(const char *name, void *buffer, size_t len)
{
    fstream infile;
    infile.open(name, fstream::in | fstream::binary);

    if (infile.is_open())
    {
        // Overwrite position
        infile.read(static_cast<char *>(buffer), len);
        infile.close();

        return true;
    }
    else
    {
        return false;
    }
}
