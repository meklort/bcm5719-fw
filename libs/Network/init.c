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

#include <APE_APE.h>
#include <Network.h>

void Network_InitTxRx(void)
{
    // REG_APE_PERFECT_MATCH1_{HIGH,LOW}. For non-broadcast/multicast traffic, the hardware uses this register to match MACs and pass traffic to the APE.
    // The first two bytes of a MAC are put in the HIGH register, and the remaining four bytes in the LOW.
    // Note that this is a device (PCI) register, not an APE register. Set it to the BMC MAC.

    // REG_APE__BMC_NC_RX_SRC_MAC_MATCHN_{HIGH,LOW}.
    // This appears to relate to the RMU, not network RX, but its exact purpose is unknown.
    // Set it to the BMC MAC. Unlike the "perfect match" register above, it takes a different format:
    // for an example MAC AABB.CCDD.EEFF, set HIGH=0xAABBCCDD, LOW=0xEEFF0000.
    // *** NOTE: set to 0 in rmu.c ***

    // Ensure REG_EMAC_MODE__ENABLE_APE_{TX,RX}_PATH are set.
    // *** NOTE: Both bits are set in rmu.c ***/

    // Enable APE channel 0, 1, 2, 3
    RegAPEMode_t mode;
    mode = APE.Mode;
    mode.bits.Event1 = 1;
    mode.bits.Channel0Enable = 1;
    mode.bits.Channel1Enable = 1;
    mode.bits.Channel2Enable = 1;
    mode.bits.Channel3Enable = 1;
    APE.Mode = mode;

    Network_InitPort(&gPort0);
    Network_InitPort(&gPort1);
    Network_InitPort(&gPort2);
    Network_InitPort(&gPort3);
}
