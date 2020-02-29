////////////////////////////////////////////////////////////////////////////////
///
/// @file       Network.h
///
/// @project
///
/// @brief      Network TX/RX Support Routines
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2019, Evan Lojewski
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

#ifndef NETWORK_H
#define NETWORK_H

#include <APE_APE.h>
#include <APE_APE_PERI.h>
#include <APE_DEVICE.h>
#include <APE_FILTERS0.h>
#include <APE_RX_PORT0.h>
#include <APE_TX_PORT0.h>
#include <APE_SHM_CHANNEL0.h>
#include <types.h>

#ifdef CXX_SIMULATOR
#define VOLATILE
#else
#define VOLATILE volatile
#endif

typedef struct
{
    /* TX Registers */
    VOLATILE RegAPETxToNetPoolModeStatus_t *tx_mode;
    VOLATILE TX_PORT_t *tx_port;
    VOLATILE RegAPETxToNetBufferAllocator_t *tx_allocator;
    VOLATILE RegAPETxToNetDoorbell_t *tx_doorbell;

    /* RX Registers */
    VOLATILE RegAPERxPoolModeStatus_t *rx_mode;
    VOLATILE RX_PORT_t *rx_port;
    VOLATILE RegAPERxbufoffset_t *rx_offset;
    VOLATILE RegAPERxPoolRetire_t *rx_retire;

    /* Port Registers */
    VOLATILE DEVICE_t *device;
    VOLATILE FILTERS_t *filters;
    VOLATILE SHM_CHANNEL_t* shm_channel;

    /* APE Registers */
    VOLATILE RegAPEMode_t APEModeEnable;
} NetworkPort_t;

typedef union
{
    uint32_t r32;
    struct
    {
        uint32_t payload_length:7;
        uint32_t next_block:23;
        uint32_t first:1;
        uint32_t not_last:1;
    } bits;
} network_control_t;

extern NetworkPort_t gPort0;
extern NetworkPort_t gPort1;
extern NetworkPort_t gPort2;
extern NetworkPort_t gPort3;

void Network_InitPort(NetworkPort_t *port);

void Network_resetTX(NetworkPort_t *port);
void Network_resetRX(NetworkPort_t *port);

void Network_checkPortState(NetworkPort_t *port);
bool Network_updatePortState(NetworkPort_t *port);

bool Network_isLinkUp(NetworkPort_t *port);


uint32_t Network_TX_numBlocksNeeded(uint32_t frame_size);
int32_t Network_TX_allocateBlock(NetworkPort_t *port);
void Network_TX_releaseBlock(NetworkPort_t *port, int32_t block);

bool Network_TX_transmitBePacket(uint8_t *packet, uint32_t length, NetworkPort_t *port);
bool Network_TX_transmitLePacket(uint8_t *packet, uint32_t length, NetworkPort_t *port);

bool Network_TX_transmitPassthroughPacket(uint32_t length, NetworkPort_t *port);

// void Network_TX_transmitPassthroughPacket(RegAPE_PERIBmcToNcRxStatus_t
// rx_status);

bool Network_RxLePatcket(uint32_t *buffer, uint32_t *length, NetworkPort_t *port);
bool Network_PassthroughRxPatcket(NetworkPort_t *port);

void Network_SetMACAddr(NetworkPort_t *port, uint16_t high, uint32_t low, uint32_t index, bool enabled);

#endif /* NETWORK_H */
