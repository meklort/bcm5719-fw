////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.c
///
/// @project
///
/// @brief      Main stage1 code
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018, Evan Lojewski
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

#include "ape.h"

#include <APE_SHM.h>

void __attribute__((noreturn)) loaderLoop(void)
{
    // Update SHM.Sig to signal ready.
    SHM.SegSig.bits.Sig = SHM_SEG_SIG_SIG_LOADER;
    SHM.FwStatus.bits.Ready = 1;

    for(;;)
    {
        uint32_t command = SHM.LoaderCommand.bits.Command;
        if(!command) continue;

        uint32_t arg0 = SHM.LoaderArg0.r32;
        uint32_t arg1 = SHM.LoaderArg1.r32;

        switch(command)
        {
            default:
                break;

            case SHM_LOADER_COMMAND_COMMAND_READ_MEM:
            {
                // Read word address specified in arg0
                uint32_t* addr = ((void*)arg0);
                SHM.LoaderArg0.r32 = *addr;
                break;
            }
            case SHM_LOADER_COMMAND_COMMAND_WRITE_MEM:
            {
                // Write word address specified in arg0 with arg1
                uint32_t* addr = ((void*)arg0);
                *addr = arg1;
                break;
            }
            case SHM_LOADER_COMMAND_COMMAND_CALL:
            {
                // call address specified in arg0.
                void (*function)(uint32_t) = ((void*)arg0);
                function(arg1);
                break;
            }
        }

        // Mark command as handled.
        SHM.LoaderCommand.bits.Command = 0;
    }
}

void __attribute__((noreturn)) __start()
{
    initRxFromNetwork();
    loaderLoop();
}