////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_SHM_CHANNEL0_sim.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_SHM_CHANNEL0_sim
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
#include <bcm5719_SHM_CHANNEL0.h>

void init_bcm5719_SHM_CHANNEL0_sim(void *base,
    uint32_t (*read)(uint32_t val, uint32_t offset, void *args),
    uint32_t (*write)(uint32_t val, uint32_t offset, void *args))
{
    SHM_CHANNEL0.mIndexReadCallback = read;
    SHM_CHANNEL0.mIndexReadCallbackArgs = base;

    SHM_CHANNEL0.mIndexWriteCallback = write;
    SHM_CHANNEL0.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref SHM_CHANNEL0. */
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelInfo. */
    SHM_CHANNEL0.NcsiChannelInfo.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelInfo.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMcid. */
    SHM_CHANNEL0.NcsiChannelMcid.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMcid.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL0.reserved_8[i].installReadCallback(read, (uint8_t *)base);
        SHM_CHANNEL0.reserved_8[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelBfilt. */
    SHM_CHANNEL0.NcsiChannelBfilt.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelBfilt.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMfilt. */
    SHM_CHANNEL0.NcsiChannelMfilt.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMfilt.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelSetting1. */
    SHM_CHANNEL0.NcsiChannelSetting1.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelSetting1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelSetting2. */
    SHM_CHANNEL0.NcsiChannelSetting2.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelSetting2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelVlan. */
    SHM_CHANNEL0.NcsiChannelVlan.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelVlan.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL0.reserved_32[i].installReadCallback(read, (uint8_t *)base);
        SHM_CHANNEL0.reserved_32[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacHigh. */
    SHM_CHANNEL0.NcsiChannelAltHostMacHigh.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelAltHostMacHigh.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacMid. */
    SHM_CHANNEL0.NcsiChannelAltHostMacMid.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelAltHostMacMid.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacLow. */
    SHM_CHANNEL0.NcsiChannelAltHostMacLow.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelAltHostMacLow.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL0.reserved_48[i].installReadCallback(read, (uint8_t *)base);
        SHM_CHANNEL0.reserved_48[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0High. */
    SHM_CHANNEL0.NcsiChannelMac0High.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac0High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0Mid. */
    SHM_CHANNEL0.NcsiChannelMac0Mid.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac0Mid.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0Low. */
    SHM_CHANNEL0.NcsiChannelMac0Low.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac0Low.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL0.reserved_64[i].installReadCallback(read, (uint8_t *)base);
        SHM_CHANNEL0.reserved_64[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1High. */
    SHM_CHANNEL0.NcsiChannelMac1High.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac1High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1Mid. */
    SHM_CHANNEL0.NcsiChannelMac1Mid.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac1Mid.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1Low. */
    SHM_CHANNEL0.NcsiChannelMac1Low.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac1Low.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL0.reserved_80[i].installReadCallback(read, (uint8_t *)base);
        SHM_CHANNEL0.reserved_80[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac2High. */
    SHM_CHANNEL0.NcsiChannelMac2High.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac2High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac2Mid. */
    SHM_CHANNEL0.NcsiChannelMac2Mid.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac2Mid.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac2Low. */
    SHM_CHANNEL0.NcsiChannelMac2Low.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac2Low.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM_CHANNEL0.reserved_96[i].installReadCallback(read, (uint8_t *)base);
        SHM_CHANNEL0.reserved_96[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac3High. */
    SHM_CHANNEL0.NcsiChannelMac3High.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac3High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac3Mid. */
    SHM_CHANNEL0.NcsiChannelMac3Mid.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac3Mid.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac3Low. */
    SHM_CHANNEL0.NcsiChannelMac3Low.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac3Low.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0VlanValid. */
    SHM_CHANNEL0.NcsiChannelMac0VlanValid.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac0VlanValid.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac0Vlan. */
    SHM_CHANNEL0.NcsiChannelMac0Vlan.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac0Vlan.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1VlanValid. */
    SHM_CHANNEL0.NcsiChannelMac1VlanValid.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac1VlanValid.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelMac1Vlan. */
    SHM_CHANNEL0.NcsiChannelMac1Vlan.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelMac1Vlan.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelStatus. */
    SHM_CHANNEL0.NcsiChannelStatus.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelResetCount. */
    SHM_CHANNEL0.NcsiChannelResetCount.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelResetCount.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelPxe. */
    SHM_CHANNEL0.NcsiChannelPxe.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelPxe.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelDropfil. */
    SHM_CHANNEL0.NcsiChannelDropfil.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelDropfil.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelSlink. */
    SHM_CHANNEL0.NcsiChannelSlink.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelSlink.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 3; i++)
    {
        SHM_CHANNEL0.reserved_148[i].installReadCallback(read, (uint8_t *)base);
        SHM_CHANNEL0.reserved_148[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelDbg. */
    SHM_CHANNEL0.NcsiChannelDbg.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelDbg.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 3; i++)
    {
        SHM_CHANNEL0.reserved_164[i].installReadCallback(read, (uint8_t *)base);
        SHM_CHANNEL0.reserved_164[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNetworkRx. */
    SHM_CHANNEL0.NcsiChannelNetworkRx.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelNetworkRx.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNetworkTx. */
    SHM_CHANNEL0.NcsiChannelNetworkTx.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelNetworkTx.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNcsiRx. */
    SHM_CHANNEL0.NcsiChannelNcsiRx.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelNcsiRx.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNcsiTx. */
    SHM_CHANNEL0.NcsiChannelNcsiTx.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelNcsiTx.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNcsiDropped. */
    SHM_CHANNEL0.NcsiChannelNcsiDropped.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelNcsiDropped.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelNetworkDropped. */
    SHM_CHANNEL0.NcsiChannelNetworkDropped.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelNetworkDropped.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_CHANNEL_t.NcsiChannelAen. */
    SHM_CHANNEL0.NcsiChannelAen.r32.installReadCallback(read, (uint8_t *)base);
    SHM_CHANNEL0.NcsiChannelAen.r32.installWriteCallback(write, (uint8_t *)base);


}
