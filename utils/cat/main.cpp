////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.cpp
///
/// @project
///
/// @brief      Concatenation utility for joining binary files.
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2022, Evan Lojewski
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

#include <OptionParser.h>
#include <fstream>

using optparse::OptionParser;
using std::fstream;

int main(int argc, char const *argv[])
{
    OptionParser parser = OptionParser().description("Concatenation Utility");

    parser.add_option("-i", "--input").dest("input").metavar("INPUT").action("append").help("Read from the input ape binary");

    parser.add_option("-o", "--output").dest("output").metavar("OUTPUT").help("Save to the specified output elf file");

    optparse::Values options = parser.parse_args(argc, argv);

    if (!options.is_set("output"))
    {
        parser.print_usage();
        std::cerr << parser.prog() << ": error: No output file specified." << std::endl;
        exit(-1);
    }

    if (!options.is_set("input"))
    {
        parser.print_help();
        std::cerr << parser.prog() << ": error: No input files specified." << std::endl;
        exit(-1);
    }

    fstream outfile;
    outfile.open(options.get("output"), fstream::out | fstream::binary);
    if (outfile.is_open())
    {
        const std::list<std::string> &infiles = options.all("input");
        for (std::list<std::string>::const_iterator iter = infiles.cbegin(); iter != infiles.cend(); ++iter)
        {
            fstream infile;
            infile.open(*iter, fstream::in | fstream::binary);

            if (infile.is_open())
            {
                char c;
                while (infile.get(c))
                {
                    outfile.write(&c, 1);
                }
            }
            else
            {
                std::cerr << " Unable to open input file '" << *iter << "'" << std::endl;
                exit(-1);
            }
        }
    }
    else
    {
        std::cerr << " Unable to open output file '" << options["output"] << "'" << std::endl;
        exit(-1);
    }

    return 0;
}
