////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_MII_mmap.cpp
///
/// @project    <PROJECT>
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

#include <bcm5719_MII.h>
#include <stdint.h>
#include <utility>

typedef std::pair<uint8_t *, uint32_t> ram_offset_t;

static uint32_t read_from_ram(uint32_t val, void *args)
{
    ram_offset_t *loc = (ram_offset_t *)args;

    uint8_t *base = loc->first;
    base += loc->second;

    return *(uint32_t *)base;
}

static uint32_t write_to_ram(uint32_t val, void *args)
{
    ram_offset_t *loc = (ram_offset_t *)args;

    uint8_t *base = loc->first;
    base += loc->second;

    *(uint32_t *)base = val;
    return val;
}

void init_bcm5719_MII_mmap(void *base)
{
    /** @brief Component Registers for @ref MII. */
    /** @brief Bitmap for @ref MII_t.Control. */
    MII.Control.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)0));
    MII.Control.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)0));

    /** @brief Bitmap for @ref MII_t.Status. */
    MII.Status.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1));
    MII.Status.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1));

    /** @brief Bitmap for @ref MII_t.PhyIdHigh. */
    MII.PhyIdHigh.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)2));
    MII.PhyIdHigh.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)2));

    /** @brief Bitmap for @ref MII_t.PhyIdLow. */
    MII.PhyIdLow.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)3));
    MII.PhyIdLow.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)3));

    /** @brief Bitmap for @ref MII_t.AutonegotiationAdvertisement. */
    MII.AutonegotiationAdvertisement.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)4));
    MII.AutonegotiationAdvertisement.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)4));

    /** @brief Bitmap for @ref MII_t.AutonegotiationLinkPartnerAbilityBasePage.
     */
    MII.AutonegotiationLinkPartnerAbilityBasePage.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)5));
    MII.AutonegotiationLinkPartnerAbilityBasePage.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)5));

    /** @brief Bitmap for @ref MII_t.AutonegotiationExpansion. */
    MII.AutonegotiationExpansion.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)6));
    MII.AutonegotiationExpansion.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)6));

    /** @brief Bitmap for @ref MII_t.AutonegotiationNextPageTransmit. */
    MII.AutonegotiationNextPageTransmit.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)7));
    MII.AutonegotiationNextPageTransmit.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)7));

    /** @brief Bitmap for @ref MII_t.AutonegotiationLinkPartnerAbilityNextPage.
     */
    MII.AutonegotiationLinkPartnerAbilityNextPage.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)8));
    MII.AutonegotiationLinkPartnerAbilityNextPage.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)8));

    /** @brief Bitmap for @ref MII_t.1000baseTControl. */
    MII._1000baseTControl.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)9));
    MII._1000baseTControl.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)9));

    /** @brief Bitmap for @ref MII_t.1000baseTStatus. */
    MII._1000baseTStatus.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)10));
    MII._1000baseTStatus.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)10));

    /** @brief Bitmap for @ref MII_t.BroadreachLreAccess. */
    MII.BroadreachLreAccess.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14));
    MII.BroadreachLreAccess.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14));

    /** @brief Bitmap for @ref MII_t.IeeeExtendedStatus. */
    MII.IeeeExtendedStatus.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)15));
    MII.IeeeExtendedStatus.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)15));

    /** @brief Bitmap for @ref MII_t.PhyExtendedStatus. */
    MII.PhyExtendedStatus.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)17));
    MII.PhyExtendedStatus.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)17));

    /** @brief Bitmap for @ref MII_t.ReceiveErrorCounter. */
    MII.ReceiveErrorCounter.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)18));
    MII.ReceiveErrorCounter.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)18));

    /** @brief Bitmap for @ref MII_t.FalseCarrierSenseCounter. */
    MII.FalseCarrierSenseCounter.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)19));
    MII.FalseCarrierSenseCounter.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)19));

    /** @brief Bitmap for @ref MII_t.LocalRemoteReceiverNotOkCounter. */
    MII.LocalRemoteReceiverNotOkCounter.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20));
    MII.LocalRemoteReceiverNotOkCounter.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20));

    /** @brief Bitmap for @ref MII_t.AuxillaryStatusSummary. */
    MII.AuxillaryStatusSummary.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25));
    MII.AuxillaryStatusSummary.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25));

    /** @brief Bitmap for @ref MII_t.InterruptStatus. */
    MII.InterruptStatus.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26));
    MII.InterruptStatus.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26));

    /** @brief Bitmap for @ref MII_t.InterruptMask. */
    MII.InterruptMask.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)27));
    MII.InterruptMask.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)27));

    /** @brief Bitmap for @ref MII_t.Test1. */
    MII.Test1.r16.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)30));
    MII.Test1.r16.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)30));
}
