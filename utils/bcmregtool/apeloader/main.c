////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.c
///
/// @project
///
/// @brief      Main apeloader code
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

#include <APE_SHM.h>
#include <APE_SHM1.h>
#include <APE_SHM2.h>
#include <APE_SHM3.h>

void init_shm(volatile SHM_t *shm)
{
    // Update shm->Sig to signal ready.
    shm->SegSig.bits.Sig = SHM_SEG_SIG_SIG_LOADER;
    shm->FwStatus.bits.Ready = 1;
}

void handle_command(volatile SHM_t *shm)
{
    uint32_t command = shm->LoaderCommand.bits.Command;
    if (!command)
    {
        return;
    }

    uint32_t arg0 = shm->LoaderArg0.r32;
    uint32_t arg1 = shm->LoaderArg1.r32;

    switch (command)
    {
        default:
            break;

        case SHM_LOADER_COMMAND_COMMAND_READ_MEM:
        {
            // Read word address specified in arg0
            uint32_t *addr = ((void *)arg0);
            shm->LoaderArg0.r32 = *addr;
            break;
        }
        case SHM_LOADER_COMMAND_COMMAND_WRITE_MEM:
        {
            // Write word address specified in arg0 with arg1
            uint32_t *addr = ((void *)arg0);
            *addr = arg1;
            break;
        }
        case SHM_LOADER_COMMAND_COMMAND_CALL:
        {
            // call address specified in arg0.
            void (*function)(uint32_t) = ((void *)arg0);
            function(arg1);
            break;
        }
    }

    // Mark command as handled.
    shm->LoaderCommand.bits.Command = 0;
}

int __start()
{
    init_shm(&SHM);
    init_shm(&SHM1);
    init_shm(&SHM2);
    init_shm(&SHM3);

    for (;;)
    {
        handle_command(&SHM);
        handle_command(&SHM1);
        handle_command(&SHM2);
        handle_command(&SHM3);
    }
}