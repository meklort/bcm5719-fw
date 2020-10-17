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
/// @copyright Copyright (c) 2019-2020, Evan Lojewski
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

typedef struct
{
    /* Port Registers */
    VOLATILE DEVICE_t *device;
    VOLATILE FILTERS_t *filters;
    VOLATILE SHM_CHANNEL_t* shm_channel;

    /* TX Registers */
    VOLATILE TX_PORT_t *tx_port;
    VOLATILE RegAPETxToNetBufferAllocator_t *tx_allocator;
    VOLATILE RegAPETxToNetDoorbell_t *tx_doorbell;
    VOLATILE RegAPETxToNetBufferRing_t *tx_ring;
    VOLATILE RegAPETxToNetPoolModeStatus_t *tx_mode;

    /* RX Registers */
    VOLATILE RX_PORT_t *rx_port;
    VOLATILE RegAPERxbufoffset_t *rx_offset;
    VOLATILE RegAPERxPoolRetire_t *rx_retire;
    VOLATILE RegAPERxPoolFreePointer_t *rx_ring;
    VOLATILE RegAPERxPoolModeStatus_t *rx_mode;

    /* APE Registers */
    VOLATILE RegAPEMode_t APEModeEnable;
    VOLATILE RegAPEMode2_t APEMode2Enable;

    /* State Trackking */
    bool link_state_printed;
    bool network_resetting;
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

typedef enum {
    NEVER_RESET, /* Host up, do not reset the PHY */
    AS_NEEDED,   /* Reset the phy if no link */
    ALWAYS_RESET /* Host was just turned off, reset phy */
} reload_type_t;

NetworkPort_t *Network_getPort(int i);

void Network_InitPort(const NetworkPort_t *port, reload_type_t force_reset);

void Network_resetTX(const NetworkPort_t *port, reload_type_t reset_phy);
void Network_resetRX(const NetworkPort_t *port, reload_type_t reset_phy);

void Network_checkPortState(NetworkPort_t *port);
bool Network_updatePortState(const NetworkPort_t *port);

bool Network_isLinkUp(const NetworkPort_t *port);
void Network_resetLink(const NetworkPort_t *port);


uint32_t Network_TX_numBlocksNeeded(uint32_t frame_size);
int32_t Network_TX_allocateBlock(const NetworkPort_t *port);
void Network_TX_releaseBlock(NetworkPort_t *port, int32_t block);

bool Network_TX_transmitBePacket(uint8_t *packet, uint32_t length, NetworkPort_t *port);
bool Network_TX_transmitLePacket(uint8_t *packet, uint32_t length, NetworkPort_t *port);

bool Network_TX_transmitPassthroughPacket(uint32_t length, const NetworkPort_t *port);

// void Network_TX_transmitPassthroughPacket(RegAPE_PERIBmcToNcRxStatus_t
// rx_status);

bool Network_RxLePatcket(uint32_t *buffer, uint32_t *length, NetworkPort_t *port);
bool Network_PassthroughRxPatcket(NetworkPort_t *port);

void Network_SetMACAddr(NetworkPort_t *port, uint16_t high, uint32_t low, uint32_t index, bool enabled);

#endif /* NETWORK_H */
