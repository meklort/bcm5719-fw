////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_MII_mmap.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_MII_mmap
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
#include <bcm5719_MII.h>

#ifdef __ppc64__
#define BARRIER()    do { asm volatile ("sync 0\neieio\n" ::: "memory"); } while(0)
#else
#define BARRIER()    do { asm volatile ("" ::: "memory"); } while(0)
#endif

typedef std::pair<uint8_t *, uint32_t> ram_offset_t;

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

void init_bcm5719_MII_mmap(void *base)
{
    MII.mIndexReadCallback = read_from_ram;
    MII.mIndexReadCallbackArgs = base;

    MII.mIndexWriteCallback = write_to_ram;
    MII.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref MII. */
    /** @brief Bitmap for @ref MII_t.Control. */
    MII.Control.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.Control.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.Status. */
    MII.Status.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.Status.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.PhyIdHigh. */
    MII.PhyIdHigh.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.PhyIdHigh.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.PhyIdLow. */
    MII.PhyIdLow.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.PhyIdLow.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.AutonegotiationAdvertisement. */
    MII.AutonegotiationAdvertisement.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.AutonegotiationAdvertisement.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.AutonegotiationLinkPartnerAbilityBasePage. */
    MII.AutonegotiationLinkPartnerAbilityBasePage.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.AutonegotiationLinkPartnerAbilityBasePage.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.AutonegotiationExpansion. */
    MII.AutonegotiationExpansion.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.AutonegotiationExpansion.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.AutonegotiationNextPageTransmit. */
    MII.AutonegotiationNextPageTransmit.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.AutonegotiationNextPageTransmit.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.AutonegotiationLinkPartnerAbilityNextPage. */
    MII.AutonegotiationLinkPartnerAbilityNextPage.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.AutonegotiationLinkPartnerAbilityNextPage.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.1000baseTControl. */
    MII._1000baseTControl.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII._1000baseTControl.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.1000baseTStatus. */
    MII._1000baseTStatus.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII._1000baseTStatus.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.BroadreachLreAccess. */
    MII.BroadreachLreAccess.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.BroadreachLreAccess.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.IeeeExtendedStatus. */
    MII.IeeeExtendedStatus.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.IeeeExtendedStatus.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.PhyExtendedControl. */
    MII.PhyExtendedControl.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.PhyExtendedControl.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.PhyExtendedStatus. */
    MII.PhyExtendedStatus.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.PhyExtendedStatus.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.ReceiveErrorCounter. */
    MII.ReceiveErrorCounter.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.ReceiveErrorCounter.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.FalseCarrierSenseCounter. */
    MII.FalseCarrierSenseCounter.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.FalseCarrierSenseCounter.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.LocalRemoteReceiverNotOkCounter. */
    MII.LocalRemoteReceiverNotOkCounter.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.LocalRemoteReceiverNotOkCounter.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.AuxiliaryControl. */
    MII.AuxiliaryControl.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.AuxiliaryControl.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.AuxiliaryStatusSummary. */
    MII.AuxiliaryStatusSummary.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.AuxiliaryStatusSummary.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.InterruptStatus. */
    MII.InterruptStatus.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.InterruptStatus.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.InterruptMask. */
    MII.InterruptMask.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.InterruptMask.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.CabletronLed. */
    MII.CabletronLed.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.CabletronLed.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.Test1. */
    MII.Test1.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.Test1.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.BlockSelect. */
    MII.BlockSelect.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.BlockSelect.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.10baseT. */
    MII._10baseT.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII._10baseT.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.DllSelection. */
    MII.DllSelection.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.DllSelection.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.PowerAndMiiControl. */
    MII.PowerAndMiiControl.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.PowerAndMiiControl.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.SpareControl1. */
    MII.SpareControl1.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.SpareControl1.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.ClockAlignmentControl. */
    MII.ClockAlignmentControl.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.ClockAlignmentControl.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.MiscTest1. */
    MII.MiscTest1.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.MiscTest1.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.SpareControl2. */
    MII.SpareControl2.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.SpareControl2.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.MiscTest2. */
    MII.MiscTest2.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.MiscTest2.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.SpareControl3. */
    MII.SpareControl3.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.SpareControl3.r16.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref MII_t.MiscellaneousControl. */
    MII.MiscellaneousControl.r16.installReadCallback(read_from_ram, (uint8_t *)base);
    MII.MiscellaneousControl.r16.installWriteCallback(write_to_ram, (uint8_t *)base);


}
