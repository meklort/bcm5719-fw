////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_DEVICE_sim.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_DEVICE_sim
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2021, Evan Lojewski
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
#include <bcm5719_DEVICE.h>

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

void init_bcm5719_DEVICE_sim(void *base)
{
    DEVICE.mIndexReadCallback = read_from_ram;
    DEVICE.mIndexReadCallbackArgs = base;

    DEVICE.mIndexWriteCallback = write_to_ram;
    DEVICE.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref DEVICE. */
    for(int i = 0; i < 26; i++)
    {
        DEVICE.reserved_0[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_0[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousHostControl. */
    DEVICE.MiscellaneousHostControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MiscellaneousHostControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_108[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_108[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.PciState. */
    DEVICE.PciState.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciState.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_116[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_116[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.RegisterBase. */
    DEVICE.RegisterBase.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RegisterBase.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MemoryBase. */
    DEVICE.MemoryBase.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MemoryBase.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RegisterData. */
    DEVICE.RegisterData.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RegisterData.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_132[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_132[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndex. */
    DEVICE.UndiReceiveReturnRingConsumerIndex.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.UndiReceiveReturnRingConsumerIndex.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndexLow. */
    DEVICE.UndiReceiveReturnRingConsumerIndexLow.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.UndiReceiveReturnRingConsumerIndexLow.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 11; i++)
    {
        DEVICE.reserved_144[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_144[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.LinkStatusControl. */
    DEVICE.LinkStatusControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.LinkStatusControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 14; i++)
    {
        DEVICE.reserved_192[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_192[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.ApeMemoryBase. */
    DEVICE.ApeMemoryBase.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ApeMemoryBase.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ApeMemoryData. */
    DEVICE.ApeMemoryData.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ApeMemoryData.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 24; i++)
    {
        DEVICE.reserved_256[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_256[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.160. */
    DEVICE._160.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._160.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 167; i++)
    {
        DEVICE.reserved_356[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_356[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.EmacMode. */
    DEVICE.EmacMode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacMode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacStatus. */
    DEVICE.EmacStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacEvent. */
    DEVICE.EmacEvent.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacEvent.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.LedControl. */
    DEVICE.LedControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.LedControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0High. */
    DEVICE.EmacMacAddresses0High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacMacAddresses0High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0Low. */
    DEVICE.EmacMacAddresses0Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacMacAddresses0Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1High. */
    DEVICE.EmacMacAddresses1High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacMacAddresses1High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1Low. */
    DEVICE.EmacMacAddresses1Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacMacAddresses1Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2High. */
    DEVICE.EmacMacAddresses2High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacMacAddresses2High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2Low. */
    DEVICE.EmacMacAddresses2Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacMacAddresses2Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3High. */
    DEVICE.EmacMacAddresses3High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacMacAddresses3High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3Low. */
    DEVICE.EmacMacAddresses3Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EmacMacAddresses3Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.WolPatternPointer. */
    DEVICE.WolPatternPointer.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.WolPatternPointer.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.WolPatternCfg. */
    DEVICE.WolPatternCfg.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.WolPatternCfg.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.438. */
    DEVICE._438.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._438.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MtuSize. */
    DEVICE.MtuSize.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MtuSize.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 3; i++)
    {
        DEVICE.reserved_1088[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_1088[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.MiiCommunication. */
    DEVICE.MiiCommunication.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MiiCommunication.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_1104[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_1104[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.MiiMode. */
    DEVICE.MiiMode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MiiMode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_1112[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_1112[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.TransmitMacMode. */
    DEVICE.TransmitMacMode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.TransmitMacMode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.TransmitMacStatus. */
    DEVICE.TransmitMacStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.TransmitMacStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.TransmitMacLengths. */
    DEVICE.TransmitMacLengths.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.TransmitMacLengths.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ReceiveMacMode. */
    DEVICE.ReceiveMacMode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ReceiveMacMode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ReceiveMacStatus. */
    DEVICE.ReceiveMacStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ReceiveMacStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 52; i++)
    {
        DEVICE.reserved_1136[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_1136[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch1High. */
    DEVICE.PerfectMatch1High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PerfectMatch1High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch1Low. */
    DEVICE.PerfectMatch1Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PerfectMatch1Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch2High. */
    DEVICE.PerfectMatch2High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PerfectMatch2High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch2Low. */
    DEVICE.PerfectMatch2Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PerfectMatch2Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch3High. */
    DEVICE.PerfectMatch3High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PerfectMatch3High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch3Low. */
    DEVICE.PerfectMatch3Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PerfectMatch3Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch4High. */
    DEVICE.PerfectMatch4High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PerfectMatch4High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch4Low. */
    DEVICE.PerfectMatch4Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PerfectMatch4Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 21; i++)
    {
        DEVICE.reserved_1376[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_1376[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.SgmiiStatus. */
    DEVICE.SgmiiStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.SgmiiStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1682; i++)
    {
        DEVICE.reserved_1464[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_1464[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.ReceiveListPlacementMode. */
    DEVICE.ReceiveListPlacementMode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ReceiveListPlacementMode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ReceiveListPlacementStatus. */
    DEVICE.ReceiveListPlacementStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ReceiveListPlacementStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1406; i++)
    {
        DEVICE.reserved_8200[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_8200[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.CpmuControl. */
    DEVICE.CpmuControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.CpmuControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.NoLinkPowerModeClockPolicy. */
    DEVICE.NoLinkPowerModeClockPolicy.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.NoLinkPowerModeClockPolicy.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        DEVICE.reserved_13832[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_13832[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.LinkAwarePowerModeClockPolicy. */
    DEVICE.LinkAwarePowerModeClockPolicy.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.LinkAwarePowerModeClockPolicy.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.D0uClockPolicy. */
    DEVICE.D0uClockPolicy.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.D0uClockPolicy.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_13848[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_13848[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.ApeClkPolicy. */
    DEVICE.ApeClkPolicy.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ApeClkPolicy.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ApeSleepStateClockPolicy. */
    DEVICE.ApeSleepStateClockPolicy.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ApeSleepStateClockPolicy.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ClockSpeedOverridePolicy. */
    DEVICE.ClockSpeedOverridePolicy.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ClockSpeedOverridePolicy.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_13864[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_13864[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.Status. */
    DEVICE.Status.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.Status.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ClockStatus. */
    DEVICE.ClockStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ClockStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_13876[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_13876[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.GphyControlStatus. */
    DEVICE.GphyControlStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.GphyControlStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 7; i++)
    {
        DEVICE.reserved_13884[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_13884[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.ChipId. */
    DEVICE.ChipId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ChipId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MutexRequest. */
    DEVICE.MutexRequest.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MutexRequest.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MutexGrant. */
    DEVICE.MutexGrant.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MutexGrant.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.GphyStrap. */
    DEVICE.GphyStrap.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.GphyStrap.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_13928[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_13928[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.FlashClockControlPolicy. */
    DEVICE.FlashClockControlPolicy.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.FlashClockControlPolicy.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 3; i++)
    {
        DEVICE.reserved_13936[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_13936[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.TopLevelMiscellaneousControl1. */
    DEVICE.TopLevelMiscellaneousControl1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.TopLevelMiscellaneousControl1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 12; i++)
    {
        DEVICE.reserved_13952[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_13952[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.EeeMode. */
    DEVICE.EeeMode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EeeMode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        DEVICE.reserved_14004[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_14004[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.EeeLinkIdleControl. */
    DEVICE.EeeLinkIdleControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EeeLinkIdleControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 4; i++)
    {
        DEVICE.reserved_14016[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_14016[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.EeeControl. */
    DEVICE.EeeControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EeeControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 7; i++)
    {
        DEVICE.reserved_14036[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_14036[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexRequest. */
    DEVICE.GlobalMutexRequest.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.GlobalMutexRequest.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexGrant. */
    DEVICE.GlobalMutexGrant.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.GlobalMutexGrant.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_14072[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_14072[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.TemperatureMonitorControl. */
    DEVICE.TemperatureMonitorControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.TemperatureMonitorControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 576; i++)
    {
        DEVICE.reserved_14080[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_14080[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.MemoryArbiterMode. */
    DEVICE.MemoryArbiterMode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MemoryArbiterMode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 255; i++)
    {
        DEVICE.reserved_16388[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_16388[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.BufferManagerMode. */
    DEVICE.BufferManagerMode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.BufferManagerMode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 323; i++)
    {
        DEVICE.reserved_17412[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_17412[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 443; i++)
    {
        DEVICE.reserved_18708[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_18708[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.RxRiscMode. */
    DEVICE.RxRiscMode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscMode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscStatus. */
    DEVICE.RxRiscStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscEventMask. */
    DEVICE.RxRiscEventMask.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscEventMask.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 4; i++)
    {
        DEVICE.reserved_20492[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_20492[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.RxRiscProgramCounter. */
    DEVICE.RxRiscProgramCounter.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscProgramCounter.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscCurrentInstruction. */
    DEVICE.RxRiscCurrentInstruction.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscCurrentInstruction.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_20516[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_20516[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.RxRiscInterruptEnable. */
    DEVICE.RxRiscInterruptEnable.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscInterruptEnable.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscInterruptVector. */
    DEVICE.RxRiscInterruptVector.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscInterruptVector.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_20528[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_20528[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.RxRiscHardwareBreakpoint. */
    DEVICE.RxRiscHardwareBreakpoint.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscHardwareBreakpoint.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 4; i++)
    {
        DEVICE.reserved_20536[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_20536[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.RxRiscLastBranchAddress. */
    DEVICE.RxRiscLastBranchAddress.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscLastBranchAddress.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 109; i++)
    {
        DEVICE.reserved_20556[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_20556[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister0. */
    DEVICE.RxRiscRegister0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister1. */
    DEVICE.RxRiscRegister1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister2. */
    DEVICE.RxRiscRegister2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister3. */
    DEVICE.RxRiscRegister3.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister3.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister4. */
    DEVICE.RxRiscRegister4.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister4.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister5. */
    DEVICE.RxRiscRegister5.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister5.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister6. */
    DEVICE.RxRiscRegister6.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister6.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister7. */
    DEVICE.RxRiscRegister7.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister7.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister8. */
    DEVICE.RxRiscRegister8.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister8.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister9. */
    DEVICE.RxRiscRegister9.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister9.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister10. */
    DEVICE.RxRiscRegister10.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister10.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister11. */
    DEVICE.RxRiscRegister11.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister11.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister12. */
    DEVICE.RxRiscRegister12.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister12.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister13. */
    DEVICE.RxRiscRegister13.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister13.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister14. */
    DEVICE.RxRiscRegister14.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister14.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister15. */
    DEVICE.RxRiscRegister15.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister15.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister16. */
    DEVICE.RxRiscRegister16.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister16.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister17. */
    DEVICE.RxRiscRegister17.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister17.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister18. */
    DEVICE.RxRiscRegister18.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister18.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister19. */
    DEVICE.RxRiscRegister19.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister19.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister20. */
    DEVICE.RxRiscRegister20.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister20.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister21. */
    DEVICE.RxRiscRegister21.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister21.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister22. */
    DEVICE.RxRiscRegister22.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister22.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister23. */
    DEVICE.RxRiscRegister23.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister23.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister24. */
    DEVICE.RxRiscRegister24.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister24.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister25. */
    DEVICE.RxRiscRegister25.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister25.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister26. */
    DEVICE.RxRiscRegister26.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister26.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister27. */
    DEVICE.RxRiscRegister27.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister27.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister28. */
    DEVICE.RxRiscRegister28.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister28.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister29. */
    DEVICE.RxRiscRegister29.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister29.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister30. */
    DEVICE.RxRiscRegister30.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister30.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister31. */
    DEVICE.RxRiscRegister31.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxRiscRegister31.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1122; i++)
    {
        DEVICE.reserved_21120[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_21120[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.6408. */
    DEVICE._6408.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._6408.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_25612[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_25612[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.PciPowerConsumptionInfo. */
    DEVICE.PciPowerConsumptionInfo.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerConsumptionInfo.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerDissipatedInfo. */
    DEVICE.PciPowerDissipatedInfo.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerDissipatedInfo.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 5; i++)
    {
        DEVICE.reserved_25624[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_25624[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.PciVpdRequest. */
    DEVICE.PciVpdRequest.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciVpdRequest.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciVpdResponse. */
    DEVICE.PciVpdResponse.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciVpdResponse.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciVendorDeviceId. */
    DEVICE.PciVendorDeviceId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciVendorDeviceId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciSubsystemId. */
    DEVICE.PciSubsystemId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciSubsystemId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciClassCodeRevision. */
    DEVICE.PciClassCodeRevision.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciClassCodeRevision.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 32; i++)
    {
        DEVICE.reserved_25664[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_25664[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.64c0. */
    DEVICE._64c0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._64c0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.64c4. */
    DEVICE._64c4.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._64c4.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.64c8. */
    DEVICE._64c8.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._64c8.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 4; i++)
    {
        DEVICE.reserved_25804[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_25804[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.64dc. */
    DEVICE._64dc.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._64dc.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 9; i++)
    {
        DEVICE.reserved_25824[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_25824[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberLow. */
    DEVICE.PciSerialNumberLow.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciSerialNumberLow.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberHigh. */
    DEVICE.PciSerialNumberHigh.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciSerialNumberHigh.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_25868[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_25868[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget0. */
    DEVICE.PciPowerBudget0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerBudget0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget1. */
    DEVICE.PciPowerBudget1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerBudget1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget2. */
    DEVICE.PciPowerBudget2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerBudget2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget3. */
    DEVICE.PciPowerBudget3.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerBudget3.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget4. */
    DEVICE.PciPowerBudget4.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerBudget4.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget5. */
    DEVICE.PciPowerBudget5.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerBudget5.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget6. */
    DEVICE.PciPowerBudget6.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerBudget6.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget7. */
    DEVICE.PciPowerBudget7.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.PciPowerBudget7.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.6530. */
    DEVICE._6530.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._6530.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 7; i++)
    {
        DEVICE.reserved_25908[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_25908[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.6550. */
    DEVICE._6550.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._6550.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 40; i++)
    {
        DEVICE.reserved_25940[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_25940[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.65f4. */
    DEVICE._65f4.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._65f4.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 130; i++)
    {
        DEVICE.reserved_26104[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_26104[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.GrcModeControl. */
    DEVICE.GrcModeControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.GrcModeControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousConfig. */
    DEVICE.MiscellaneousConfig.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MiscellaneousConfig.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousLocalControl. */
    DEVICE.MiscellaneousLocalControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MiscellaneousLocalControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.Timer. */
    DEVICE.Timer.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.Timer.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxCpuEvent. */
    DEVICE.RxCpuEvent.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxCpuEvent.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 9; i++)
    {
        DEVICE.reserved_26644[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_26644[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.6838. */
    DEVICE._6838.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._6838.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        DEVICE.reserved_26684[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_26684[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.MdiControl. */
    DEVICE.MdiControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.MdiControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        DEVICE.reserved_26696[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_26696[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.RxCpuEventEnable. */
    DEVICE.RxCpuEventEnable.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.RxCpuEventEnable.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 17; i++)
    {
        DEVICE.reserved_26704[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_26704[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.FastBootProgramCounter. */
    DEVICE.FastBootProgramCounter.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.FastBootProgramCounter.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 21; i++)
    {
        DEVICE.reserved_26776[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_26776[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.ExpansionRomAddr. */
    DEVICE.ExpansionRomAddr.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.ExpansionRomAddr.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.68f0. */
    DEVICE._68f0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._68f0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 5; i++)
    {
        DEVICE.reserved_26868[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_26868[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.EavRefClockControl. */
    DEVICE.EavRefClockControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE.EavRefClockControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1214; i++)
    {
        DEVICE.reserved_26892[i].installReadCallback(read_from_ram, (uint8_t *)base);
        DEVICE.reserved_26892[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref DEVICE_t.7c04. */
    DEVICE._7c04.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    DEVICE._7c04.r32.installWriteCallback(write_to_ram, (uint8_t *)base);


}
