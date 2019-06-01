////////////////////////////////////////////////////////////////////////////////
///
/// @file       ports.c
///
/// @project
///
/// @brief      Port specific initialization and data structures.
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

#include <Network.h>

#include <APE_DEVICE1.h>
#include <APE_DEVICE2.h>
#include <APE_DEVICE3.h>

NetworkPort_t gPort0 = {
    .device = &DEVICE,

    .tx_port = &TX_PORT0,
    .tx_allocator = &APE.TxToNetBufferAllocator0,
    .tx_doorbell = &APE.TxToNetDoorbellFunc0,
    .tx_mode = &APE.TxToNetPoolModeStatus0,

    .rx_port = &RX_PORT0,
    .rx_offset = &APE.RxbufoffsetFunc0,
    .rx_retire = &APE.RxPoolRetire0,
    .rx_mode = &APE.RxPoolModeStatus0,
};

NetworkPort_t gPort1  = {
    .device = &DEVICE1,

    .tx_port = &TX_PORT1,
    .tx_allocator = &APE.TxToNetBufferAllocator1,
    .tx_doorbell = &APE.TxToNetDoorbellFunc1,
    .tx_mode = &APE.TxToNetPoolModeStatus1,

    .rx_port = &RX_PORT1,
    .rx_offset = &APE.RxbufoffsetFunc1,
    .rx_retire = &APE.RxPoolRetire1,
    .rx_mode = &APE.RxPoolModeStatus1,
};

NetworkPort_t gPort2 = {
    .device = &DEVICE2,

    .tx_port = &TX_PORT2,
    .tx_allocator = &APE.TxToNetBufferAllocator2,
    .tx_doorbell = &APE.TxToNetDoorbellFunc2,
    .tx_mode = &APE.TxToNetPoolModeStatus2,

    .rx_port = &RX_PORT2,
    .rx_offset = &APE.RxbufoffsetFunc2,
    .rx_retire = &APE.RxPoolRetire2,
    .rx_mode = &APE.RxPoolModeStatus2,
};

NetworkPort_t gPort3 = {
    .device = &DEVICE3,

    .tx_port = &TX_PORT3,
    .tx_allocator = &APE.TxToNetBufferAllocator3,
    .tx_doorbell = &APE.TxToNetDoorbellFunc3,
    .tx_mode = &APE.TxToNetPoolModeStatus3,

    .rx_port = &RX_PORT3,
    .rx_offset = &APE.RxbufoffsetFunc3,
    .rx_retire = &APE.RxPoolRetire3,
    .rx_mode = &APE.RxPoolModeStatus3,
};


void Network_InitPort(NetworkPort_t *port)
{
    // Enable RX
    RegAPERxPoolModeStatus_t rxMode;
    rxMode.r32 = 0;
    rxMode.bits.Reset = 1;
    *(port->rx_mode) = rxMode;

    rxMode.bits.Reset = 0;
    rxMode.bits.Enable = 1;
    *(port->rx_mode) = rxMode;

    // Enable TX
    RegAPETxToNetPoolModeStatus_t txMode;
    txMode.r32 = 0;
    txMode.bits.Reset = 1;
    *(port->tx_mode) = txMode;

    txMode.bits.Reset = 0;
    txMode.bits.Enable = 1;
    *(port->tx_mode) = txMode;

    // Ensure REG_RECEIVE_MAC_MODE has ENABLE set.
    // I recommend also setting APE_PROMISCUOUS_MODE and PROMISCUOUS_MODE,
    // as these will cause you less headaches during development.
    RegDEVICEReceiveMacMode_t macMode;
    macMode = port->device->ReceiveMacMode;
    macMode.bits.Enable = 1;
    macMode.bits.APEPromiscuousMode = 0;
    port->device->ReceiveMacMode = macMode;

    Network_SetMACAddr(port, 0, 0, 1, true);
}
