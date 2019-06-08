////////////////////////////////////////////////////////////////////////////////
///
/// @file       init.c
///
/// @project
///
/// @brief      Initialization code for TX to network / RX from network.
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

#include <APE_DEVICE.h>
#include <Network.h>

void Network_SetMACAddr(NetworkPort_t *port, uint16_t high, uint32_t low, uint32_t index, bool enabled)
{
    uint32_t match_high = (high << 16) | (low >> 16);
    uint16_t match_low = (low << 16);

    APE_PERI.BmcToNcSourceMacMatch0High.r32 = match_high;
    APE_PERI.BmcToNcSourceMacMatch1High.r32 = match_high;
    APE_PERI.BmcToNcSourceMacMatch2High.r32 = match_high;
    APE_PERI.BmcToNcSourceMacMatch3High.r32 = match_high;
    APE_PERI.BmcToNcSourceMacMatch4High.r32 = match_high;
    APE_PERI.BmcToNcSourceMacMatch5High.r32 = match_high;
    APE_PERI.BmcToNcSourceMacMatch6High.r32 = match_high;
    APE_PERI.BmcToNcSourceMacMatch7High.r32 = match_high;
    APE_PERI.BmcToNcSourceMacMatch0Low.r32 = match_low;
    APE_PERI.BmcToNcSourceMacMatch1Low.r32 = match_low;
    APE_PERI.BmcToNcSourceMacMatch2Low.r32 = match_low;
    APE_PERI.BmcToNcSourceMacMatch3Low.r32 = match_low;
    APE_PERI.BmcToNcSourceMacMatch4Low.r32 = match_low;
    APE_PERI.BmcToNcSourceMacMatch5Low.r32 = match_low;
    APE_PERI.BmcToNcSourceMacMatch6Low.r32 = match_low;
    APE_PERI.BmcToNcSourceMacMatch7Low.r32 = match_low;

    if (port)
    {
        port->device->PerfectMatch1High.r32 = high;
        port->device->PerfectMatch1Low.r32 = low;
    }
}
