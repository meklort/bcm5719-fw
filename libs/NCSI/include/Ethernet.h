////////////////////////////////////////////////////////////////////////////////
///
/// @file       Ethernet.h
///
/// @project
///
/// @brief      Ethernet Support Routines
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

#ifndef ETHERNET_H
#define ETHERNET_H

#include <types.h>

#define ETHERNET_FRAME_MIN      64

typedef struct
{
#ifdef __LITTLE_ENDIAN__
    uint8_t  DestinationAddress[6];
    uint8_t  SourceAddress[6];
    uint16_t reserved; // part of payload
    uint16_t EtherType;
#else
#error Not tested
#endif
} EthernetHeader_t;
_Static_assert(sizeof(EthernetHeader_t) == 16, "sizeof(EthernetHeader_t) must be 16.");
#define ETHER_TYPE_NCSI 0x88f8
#define ETHERNET_HEADER_OFFSET      0

#define PACKET_OFFSET           (12)
typedef struct
{
    // Bytes 0 - 11 - Ethernet Header
    uint8_t  DestinationAddress[6];
    uint8_t  SourceAddress[6];

#ifdef __LITTLE_ENDIAN__
    // Bytes 12 - 15
    uint32_t HeaderRevision:8;         /* Should be 1 */
    uint32_t ManagmentControllerID:8;  /* Should be 0 */
    uint32_t EtherType:16; // part of Ethernet header.

    // Bytes 16 - 19
    uint32_t ChannelID:8;
    uint32_t ControlPacketType:8;
    uint32_t InstanceID:8;
    uint32_t reserved_0:8;

    // Bytes 20 - 23
    uint32_t reserved_2:16;
    uint32_t PayloadLength:12;
    uint32_t reserved_1:4;

    // Bytes 24 - 27
    uint32_t reserved_3;
#else
#error Not tested
#endif
} ControlPacketHeader_t;
_Static_assert(sizeof(ControlPacketHeader_t) == 16 + PACKET_OFFSET, "sizeof(ControlPacketHeader_t) must be 16.");
#define CONTROL_PACKET_PAYLOAD_OFFSET   (PACKET_OFFSET + 16)

#define CONTROL_PACKET_TYPE_RESPONSE                    (0x80)
#define CONTROL_PACKET_TYPE_CLEAR_INITIAL_STATE         (0x00)
#define CONTROL_PACKET_TYPE_SELECT_PACKAGE              (0x01)
#define CONTROL_PACKET_TYPE_DESELECT_PACKAGE            (0x02)
#define CONTROL_PACKET_TYPE_ENABLE_CHANNEL              (0x03)
#define CONTROL_PACKET_TYPE_DISABLE_CHANNEL             (0x04)
#define CONTROL_PACKET_TYPE_RESET_CHANNEL               (0x05)
#define CONTROL_PACKET_TYPE_ENABLE_CHANNEL_NETWORK_TX   (0x06)
#define CONTROL_PACKET_TYPE_DISABLE_CHANNEL_NETWORK_TX  (0x07)
#define CONTROL_PACKET_TYPE_AEN_ENABLE                  (0x08)
#define CONTROL_PACKET_TYPE_SET_LINK                    (0x09)
#define CONTROL_PACKET_TYPE_GET_LINK_STATUS             (0x0A)
#define CONTROL_PACKET_TYPE_SET_VLAN_FILTER             (0x0B)
#define CONTROL_PACKET_TYPE_ENABLE_VLAN                 (0x0C)
#define CONTROL_PACKET_TYPE_DISABLE_VLAN                (0x0D)
#define CONTROL_PACKET_TYPE_SET_MAC_ADDRESS             (0x0E)
// 0x0F
#define CONTROL_PACKET_TYPE_ENABLE_BROADCAST_FILTERING  (0x10)
#define CONTROL_PACKET_TYPE_DISABLE_BROADCAST_FILTERING (0x11)
#define CONTROL_PACKET_TYPE_ENABLE_GLOBAL_MULTICAST_FILTERING  (0x12)
#define CONTROL_PACKET_TYPE_DISABLE_GLOBAL_MULTICAST_FILTERING (0x13)
#define CONTROL_PACKET_TYPE_SET_NCSI_FLOW_CONTROL       (0x14)
#define CONTROL_PACKET_TYPE_GET_VERSION_ID              (0x15)
#define CONTROL_PACKET_TYPE_GET_CAPABILITIES            (0x16)
#define CONTROL_PACKET_TYPE_GET_PARAMETERS              (0x17)
#define CONTROL_PACKET_TYPE_GET_CONTROLLER_PACKET_STATS (0x18)
#define CONTROL_PACKET_TYPE_GET_NCSI_STATS              (0x19)
#define CONTROL_PACKET_TYPE_GET_NCSI_PASSTHRU_STATS     (0x1A)
#define CONTROL_PACKET_OEM_COMMAND                      (0x50)


typedef struct {
    // Bytes 0 - 27
    ControlPacketHeader_t   header;

    // Byte 28 - 31
    uint32_t headerPadding:16;
    uint32_t checksumHigh:16;

    // Bytes 32 - 35
    uint32_t checksumLow;
    uint32_t pad:16;
} ClearInitialState_t;

typedef struct {
    // Bytes 0 - 27
    ControlPacketHeader_t   header;

    // Byte 28 - 31
    uint32_t HardwareArbitartionDisabled:8;
    uint32_t reserved_0:8;
    uint32_t headerPadding:16;

    // Bytes 32 - 35
    uint32_t checksumLow;
    uint32_t pad:16;
} SelectPackage_t;

typedef struct {
    // Bytes 0 - 27
    ControlPacketHeader_t   header;

    // Byte 28 - 31
    uint32_t AEN_MC_ID:8;
    uint32_t reserved_0:8;
    uint32_t headerPadding:16;

    // Bytes 32 - 35
    uint32_t AENControl_High:16;
    uint32_t reserved_1:16;

    // Bytes 36 - 39
    uint32_t pad:16;
    uint32_t AENControl_Low:16;
} AENEnable_t;

typedef struct {
    // Bytes 0 - 27
    ControlPacketHeader_t   header;

    // Byte 28 - 31
    uint32_t LinkSettings_High:16;
    uint32_t headerPadding:16;

    // Bytes 32 - 35
    uint32_t OEMLinkSettings_High:16;
    uint32_t LinkSettings_Low:16;

    // Bytes 36 - 39
    uint32_t pad:16;
    uint32_t OEMLinkSettings_Low:16;
} SetLink_t;

typedef struct {
    // Bytes 0 - 27
    ControlPacketHeader_t   header;

    // Byte 28 - 31
    uint32_t MAC54:16;
    uint32_t headerPadding:16;

    // Bytes 32 - 35
    uint32_t MAC10:16;
    uint32_t MAC32:16;

    // Bytes 36 - 39
    uint32_t pad:16;
    uint32_t Enable:1;
    uint32_t Rsvd:4;
    uint32_t AT:3;
    uint32_t MACNumber:8;
} SetMACAddr_t;


typedef struct
{
    // Bytes 0 - 11
    uint8_t  DestinationAddress[6];
    uint8_t  SourceAddress[6];

#ifdef __LITTLE_ENDIAN__
    // Bytes 12 - 15
    uint32_t HeaderRevision:8;         /* Should be 1 */
    uint32_t ManagmentControllerID:8;  /* Should be 0 */
    uint32_t EtherType:16; // part of Ethernet header.

    // Bytes 16 - 19
    uint32_t ChannelID:8;
    uint32_t ControlPacketType:8;
    uint32_t InstanceID:8;
    uint32_t reserved_0:8;

    // Bytes 20 - 23
    uint32_t reserved_2:16;
    uint32_t PayloadLength:12;
    uint32_t reserved_1:4;

    // Bytes 24 - 27
    uint32_t reserved_3;

    // Bytes 28 - 31
    uint16_t ResponseCode;
    uint16_t reserved_4;

    // Bytes 32 - 35
    uint16_t reserved_5;
    uint16_t ReasonCode;
#else
#error Not tested
#endif
} ResponsePacketHeader_t;

typedef struct
{
    // Bytes 0 - 11
    uint8_t  DestinationAddress[6];
    uint8_t  SourceAddress[6];

#ifdef __LITTLE_ENDIAN__
    // Bytes 12 - 15
    uint32_t HeaderRevision:8;         /* Should be 1 */
    uint32_t ManagmentControllerID:8;  /* Should be 0 */
    uint32_t EtherType:16; // part of Ethernet header.

    // Bytes 16 - 19
    uint32_t ChannelID:8;
    uint32_t ControlPacketType:8;
    uint32_t InstanceID:8;
    uint32_t reserved_0:8;

    // Bytes 20 - 23
    uint32_t reserved_2:16;
    uint32_t PayloadLength:12;
    uint32_t reserved_1:4;

    // Bytes 24 - 27
    uint32_t reserved_3;

    // Bytes 28 - 31
    uint16_t ResponseCode;
    uint16_t reserved_4;

    // Bytes 32 - 35
    uint16_t LinkStatus_High;
    uint16_t ReasonCode;

    // Bytes 36 - 39
    uint16_t OtherIndications_High;
    uint16_t LinkStatus_Low;

    // Bytes 40 - 43
    uint16_t OEMLinkStatus_High;
    uint16_t OtherIndications_Low;

    // Bytes 44 - 47
    uint16_t pad;
    uint16_t OEMLinkStatus_Low;
#else
#error Not tested
#endif
} LinkStatusResponsePacketHeader_t;

typedef union {
    // Ethernet frame must be at least 64 bytes.
    uint32_t words[ETHERNET_FRAME_MIN/4];

    EthernetHeader_t    header;

    /* Control Packets */
    ControlPacketHeader_t controlPacket;

    ClearInitialState_t clearInitialState;

    SelectPackage_t selectPackage;

    AENEnable_t AENEnable;

    SetLink_t setLink;

    SetMACAddr_t setMACAddr;

    /* Response Packets */
    ResponsePacketHeader_t  responsePacket;

    LinkStatusResponsePacketHeader_t    linkStatusResponse;
} NetworkFrame_t;



#endif /* ETHERNET_H */