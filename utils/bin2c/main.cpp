////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.cpp
///
/// @project
///
/// @brief      Main utility for converting binary files to embeddable c code.
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2019, Evan Lojewski
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
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;
using optparse::OptionParser;

string& escape(std::string& str)
{
    std::replace(str.begin(), str.end(), ' ', '_'); // No spaces allowed
    std::replace(str.begin(), str.end(), '-', '_'); // Replace -'s with _'s
    std::replace(str.begin(), str.end(), '.', '_'); // Replace .'s with _'s
    std::replace(str.begin(), str.end(), ',', '_'); // Replace ,'s with _'s
    std::replace(str.begin(), str.end(), ':', '_'); // Replace :'s with _'s
    std::replace(str.begin(), str.end(), '[', '_'); // Replace ['s with _'s
    std::replace(str.begin(), str.end(), ']', '_'); // Replace ]'s with _'s

    while(str.find("—") != std::string::npos)
    {
        str.replace(str.find("—"), strlen("—"), "_"); // Replace @'s with _AT_'s.
    }

    while(str.find("@") != std::string::npos)
        {
        str.replace(str.find("@"), 1, "_AT_"); // Replace @'s with _AT_'s.
    }

    while(str.find("/") != std::string::npos)
    {
        str.replace(str.find("/"), 1, "_DIV_"); // Replace /'s with _DIV_'s.
    }

    return str;
}

int main(int argc, char const *argv[])
{
    ofstream outfile;
    ifstream infile;
    OptionParser parser = OptionParser().description("Binary to C Header utility");

    parser.add_option("-i", "--input")
        .dest("input")
        .help("Input binary file to convert")
        .metavar("INPUT");

    parser.add_option("-o", "--output")
        .dest("output")
        .help("Output header file")
        .metavar("OUTPUT");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();

    if (!options.is_set("input"))
    {
        cerr << "Please specify an input binary file to use." << endl;
        parser.print_help();
        exit(-1);
    }

    if (!options.is_set("output"))
    {
        cerr << "Please specify an output header file to write." << endl;
        parser.print_help();
        exit(-1);
    }

    string filename = options["input"];

    infile.open(options["input"], ios::in | ios::binary);
    if (!infile.is_open())
    {
        cerr << "Unable to open input file " << options["input"];
        exit(-1);
    }

    outfile.open(options["output"], ios::out | ios::trunc);
    if (!outfile.is_open())
    {
        cerr << "Unable to open output file " << options["output"];
        exit(-1);
    }

    escape(filename);

    cout << "New name: " << filename;

    outfile << "unsigned char " << filename << "[] = {" << endl;

    int count = 0;
    char byte;
    // Read input file, byte by byte.
    while (infile.get(byte))
    {
        if (!count)
        {
            // Newline, add indent.
            outfile << "    ";
        }

        // Output a hex byte...
        outfile << "0x" << std::setw(2) << std::setfill('0') << std::hex << (int)((uint8_t)byte) << ",";
        count = (count + 1) % 8;

        if (!count)
        {
            // End of line.
            outfile << endl;
        }
    }

    if (count)
    {
        // Previous line did not end.
        outfile << endl;
    }

    outfile << "};" << endl;
    outfile << "unsigned int " << filename << "_len = sizeof(" << filename << ");" << endl;

    outfile.flush();
    outfile.close();

    return 0;
}
