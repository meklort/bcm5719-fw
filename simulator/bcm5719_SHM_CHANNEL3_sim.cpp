////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_SHM_CHANNEL3_sim.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_SHM_CHANNEL3_sim
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2020, Evan Lojewski
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
/// 3. Neither the name of the <organization> nor the
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

#include <stdint.h>
#include <utility>
#include <bcm5719_SHM_CHANNEL3.h>

#ifdef __ppc64__
#define BARRIER()    do { asm volatile ("sync 0\neieio\n" ::: "memory"); } while(0)
#else
#define BARRIER()    do { asm volatile ("" ::: "memory"); } while(0)
#endif

static uint32_t read_from_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    return *(uint32_t *)base;
}

static uint32_t write_to_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    *(uint32_t *)base = val;
    BARRIER();
    return val;
}

void init_bcm5719_SHM_CHANNEL3_sim(void *base)
{
    SHM_CHANNEL3.mIndexReadCallback = read_from_ram;
    SHM_CHANNEL3.mIndexReadCallbackArgs = base;

    SHM_CHANNEL3.mIndexWriteCallback = write_to_ram;
    SHM_CHANNEL3.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref SHM_CHANNEL3. */
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelInfo. */
    SHM_CHANNEL3.NcsiChannelInfo.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelInfo.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMcid. */
    SHM_CHANNEL3.NcsiChannelMcid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMcid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL3.reserved_8[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM_CHANNEL3.reserved_8[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelBfilt. */
    SHM_CHANNEL3.NcsiChannelBfilt.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelBfilt.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMfilt. */
    SHM_CHANNEL3.NcsiChannelMfilt.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMfilt.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelSetting1. */
    SHM_CHANNEL3.NcsiChannelSetting1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelSetting1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelSetting2. */
    SHM_CHANNEL3.NcsiChannelSetting2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelSetting2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelVlan. */
    SHM_CHANNEL3.NcsiChannelVlan.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelVlan.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL3.reserved_32[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM_CHANNEL3.reserved_32[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacHigh. */
    SHM_CHANNEL3.NcsiChannelAltHostMacHigh.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelAltHostMacHigh.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacMid. */
    SHM_CHANNEL3.NcsiChannelAltHostMacMid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelAltHostMacMid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacLow. */
    SHM_CHANNEL3.NcsiChannelAltHostMacLow.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelAltHostMacLow.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL3.reserved_48[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM_CHANNEL3.reserved_48[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0High. */
    SHM_CHANNEL3.NcsiChannelMac0High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac0High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0Mid. */
    SHM_CHANNEL3.NcsiChannelMac0Mid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac0Mid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0Low. */
    SHM_CHANNEL3.NcsiChannelMac0Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac0Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL3.reserved_64[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM_CHANNEL3.reserved_64[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1High. */
    SHM_CHANNEL3.NcsiChannelMac1High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac1High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1Mid. */
    SHM_CHANNEL3.NcsiChannelMac1Mid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac1Mid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1Low. */
    SHM_CHANNEL3.NcsiChannelMac1Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac1Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL3.reserved_80[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM_CHANNEL3.reserved_80[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac2High. */
    SHM_CHANNEL3.NcsiChannelMac2High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac2High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac2Mid. */
    SHM_CHANNEL3.NcsiChannelMac2Mid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac2Mid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac2Low. */
    SHM_CHANNEL3.NcsiChannelMac2Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac2Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL3.reserved_96[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM_CHANNEL3.reserved_96[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac3High. */
    SHM_CHANNEL3.NcsiChannelMac3High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac3High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac3Mid. */
    SHM_CHANNEL3.NcsiChannelMac3Mid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac3Mid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac3Low. */
    SHM_CHANNEL3.NcsiChannelMac3Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac3Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0VlanValid. */
    SHM_CHANNEL3.NcsiChannelMac0VlanValid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac0VlanValid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0Vlan. */
    SHM_CHANNEL3.NcsiChannelMac0Vlan.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac0Vlan.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1VlanValid. */
    SHM_CHANNEL3.NcsiChannelMac1VlanValid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac1VlanValid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1Vlan. */
    SHM_CHANNEL3.NcsiChannelMac1Vlan.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelMac1Vlan.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelStatus. */
    SHM_CHANNEL3.NcsiChannelStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelResetCount. */
    SHM_CHANNEL3.NcsiChannelResetCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelResetCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelPxe. */
    SHM_CHANNEL3.NcsiChannelPxe.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelPxe.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelDropfil. */
    SHM_CHANNEL3.NcsiChannelDropfil.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelDropfil.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelSlink. */
    SHM_CHANNEL3.NcsiChannelSlink.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelSlink.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 3; i++)
    {
        SHM_CHANNEL3.reserved_148[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM_CHANNEL3.reserved_148[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelDbg. */
    SHM_CHANNEL3.NcsiChannelDbg.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelDbg.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 3; i++)
    {
        SHM_CHANNEL3.reserved_164[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM_CHANNEL3.reserved_164[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNetworkRx. */
    SHM_CHANNEL3.NcsiChannelNetworkRx.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelNetworkRx.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNetworkTx. */
    SHM_CHANNEL3.NcsiChannelNetworkTx.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelNetworkTx.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNcsiRx. */
    SHM_CHANNEL3.NcsiChannelNcsiRx.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelNcsiRx.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNcsiTx. */
    SHM_CHANNEL3.NcsiChannelNcsiTx.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelNcsiTx.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNcsiDropped. */
    SHM_CHANNEL3.NcsiChannelNcsiDropped.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelNcsiDropped.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNetworkDropped. */
    SHM_CHANNEL3.NcsiChannelNetworkDropped.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelNetworkDropped.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelAen. */
    SHM_CHANNEL3.NcsiChannelAen.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM_CHANNEL3.NcsiChannelAen.r32.installWriteCallback(write_to_ram, (uint8_t *)base);


}
