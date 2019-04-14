////////////////////////////////////////////////////////////////////////////////
///
/// @file       ncsi.c
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

#include <NCSI.h>
#include <APE_APE_PERI.h>
#include <APE_SHM.h>
#include <APE_SHM_CHANNEL0.h>
#include <APE_SHM_CHANNEL1.h>
#include <APE_SHM_CHANNEL2.h>
#include <APE_SHM_CHANNEL3.h>
#include <stdbool.h>

#define MAX_CHANNELS        4

#define PACKAGE_ID_SHIFT    5
#define PACKAGE_ID_MASK     (0xE0)
#define CHANNEL_ID_SHIFT    0
#define CHANNEL_ID_MASK     (0x1F)
#define CHANNEL_ID_PACKAGE  (0x1F)
uint8_t gPackageID = ((0 << PACKAGE_ID_SHIFT) | CHANNEL_ID_PACKAGE);

typedef struct {
    bool initialized;

    uint32_t AENEnables; /* Corresponds to an enable bit for each AEN packet */
    bool AsyncronousTrafficEn; /* When set, AEN and passthrough traffic can be sent from the NC to the MC */
    bool PassthroughTXTrafficEn; /* When set, the NC is allowed to transmit passthrough traffic from the MC to the NC. */
#ifdef CXX_SIMULATOR
    SHM_CHANNEL_t* shm;
#else
    volatile SHM_CHANNEL_t* shm;
#endif
} channel_state_t;

// Response frame - global and usable by one thread at a time only.
NetworkFrame_t gResponseFrame = 
{
    .responsePacket = {
        .DestinationAddress = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        .SourceAddress =      {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},

        .HeaderRevision = 1,
        .ManagmentControllerID = 0,
        .EtherType = ETHER_TYPE_NCSI,
        .ChannelID = 0,         /* Filled in by appropriate handler. */
        .ControlPacketType = 0, /* Filled in by appropriate handler. */
        .InstanceID = 0,        /* Filled in by appropriate handler. */
        .reserved_0 = 0,
        .reserved_2 = 0,
        .PayloadLength = 0,     /* Filled in by appropriate handler. */
        .reserved_1 = 0,

        .ResponseCode = 0,
        .reserved_4 = 0,
        .reserved_5 = 0,
        .ReasonCode = 0,
    }
};


typedef struct {
    bool selected;
    int  numChannels;
    channel_state_t channel[MAX_CHANNELS];
} package_state_t;

package_state_t gPackageState = {
    .numChannels = MAX_CHANNELS,
    .selected = false,
    .channel = {
        [0] = {
            .initialized = false,
            .AENEnables = false,
            .AsyncronousTrafficEn = false,
            .PassthroughTXTrafficEn = false,
            .shm = &SHM_CHANNEL0,
        },
        [1] = {
            .initialized = false,
            .AENEnables = false,
            .AsyncronousTrafficEn = false,
            .PassthroughTXTrafficEn = false,
            .shm = &SHM_CHANNEL1,
        },
        [2] = {
            .initialized = false,
            .AENEnables = false,
            .AsyncronousTrafficEn = false,
            .PassthroughTXTrafficEn = false,
            .shm = &SHM_CHANNEL2,
        },
        [3] = {
            .initialized = false,
            .AENEnables = false,
            .AsyncronousTrafficEn = false,
            .PassthroughTXTrafficEn = false,
            .shm = &SHM_CHANNEL3,
        },
    },
};

void sendNCSIResponse(uint8_t InstanceID, uint8_t channelID, uint16_t controlID,
                    uint16_t response_code, uint16_t reasons_code);
void resetChannel(int ch);

#if CXX_SIMULATOR
#include <stdio.h>
#endif

typedef struct {
    bool ignoreInit;
    bool packageCommand;
    int payloadLength;
    void (*fn)(NetworkFrame_t*);

} ncsi_handler_t;


void unknownHandler(NetworkFrame_t* frame)
{
#if CXX_SIMULATOR
    printf("Unhandled Packet Type: %x\n", frame->header.EtherType);
    printf("ManagmentControllerID: %x\n", frame->controlPacket.ManagmentControllerID);
    printf("HeaderRevision: %x\n", frame->controlPacket.HeaderRevision);
    printf("Control Packet Type: %x\n", frame->controlPacket.ControlPacketType);
    printf("Channel ID: %x\n", frame->controlPacket.ChannelID);
    printf("Instance ID: %d\n", frame->controlPacket.InstanceID);
    printf("Payload Length: %d\n", frame->controlPacket.PayloadLength);
#endif

    sendNCSIResponse(
        frame->controlPacket.InstanceID, 
        frame->controlPacket.ChannelID,
        frame->controlPacket.ControlPacketType,
        NCSI_RESPONSE_CODE_COMMAND_UNSUPPORTED,
        NCSI_REASON_CODE_UNKNOWN_UNSUPPORTED);
}


static void clearInitialStateHandler(NetworkFrame_t* frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

    gPackageState.channel[ch].initialized = true;
#if CXX_SIMULATOR
    printf("Clear initial state: channel %x\n", ch);
    printf("     Initialized: %d\n", gPackageState.channel[ch].initialized);
#endif

    sendNCSIResponse(
        frame->controlPacket.InstanceID, 
        frame->controlPacket.ChannelID,
        frame->controlPacket.ControlPacketType,
        NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void selectPacakgeHandler(NetworkFrame_t* frame)
{
#if CXX_SIMULATOR
    printf("Package enabled.\n");
#endif
    gPackageState.selected = true;
    sendNCSIResponse(
        frame->controlPacket.InstanceID, 
        frame->controlPacket.ChannelID,
        frame->controlPacket.ControlPacketType,
        NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void deselectPacakgeHandler(NetworkFrame_t* frame)
{
#if CXX_SIMULATOR
    printf("Package disabled.\n");
#endif
    gPackageState.selected = false;

    sendNCSIResponse(
        frame->controlPacket.InstanceID, 
        frame->controlPacket.ChannelID,
        frame->controlPacket.ControlPacketType,
        NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void enableChannelHandler(NetworkFrame_t* frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

#if CXX_SIMULATOR
    printf("Enable Channel: channel %x\n", ch);
#endif
    gPackageState.channel[ch].AsyncronousTrafficEn = true;

    sendNCSIResponse(
        frame->controlPacket.InstanceID, 
        frame->controlPacket.ChannelID,
        frame->controlPacket.ControlPacketType,
        NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void disableChannelHandler(NetworkFrame_t* frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

#if CXX_SIMULATOR
    printf("Disable Channel: channel %x\n", ch);
#endif
    gPackageState.channel[ch].AsyncronousTrafficEn = false;

    sendNCSIResponse(
        frame->controlPacket.InstanceID, 
        frame->controlPacket.ChannelID,
        frame->controlPacket.ControlPacketType,
        NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void resetChannelHandler(NetworkFrame_t* frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

#if CXX_SIMULATOR
    printf("Reset Channel: channel %x\n", ch);
#endif
    resetChannel(ch);

    sendNCSIResponse(
        frame->controlPacket.InstanceID, 
        frame->controlPacket.ChannelID,
        frame->controlPacket.ControlPacketType,
        NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void enableChannelNetworkTXHandler(NetworkFrame_t* frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

#if CXX_SIMULATOR
    printf("Enable Channel Network TX: channel %x\n", ch);
#endif
    gPackageState.channel[ch].PassthroughTXTrafficEn = false;

    sendNCSIResponse(
        frame->controlPacket.InstanceID, 
        frame->controlPacket.ChannelID,
        frame->controlPacket.ControlPacketType,
        NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void disableChannelNetworkTXHandler(NetworkFrame_t* frame)
{
    uint16_t response = NCSI_RESPONSE_CODE_COMMAND_COMPLETE;
    uint16_t reason = NCSI_REASON_CODE_NONE;
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

#if CXX_SIMULATOR
    printf("Disable Channel Network TX: channel %x\n", ch);
#endif
    gPackageState.channel[ch].PassthroughTXTrafficEn = true;

    sendNCSIResponse(
        frame->controlPacket.InstanceID, 
        frame->controlPacket.ChannelID,
        frame->controlPacket.ControlPacketType,
        response, reason);
}

static void AENEnableHandler(NetworkFrame_t* frame)
{
#if CXX_SIMULATOR
    printf("AEN Enable: channel %x\n", frame->controlPacket.ChannelID);
#endif
}

static void setLinkHandler(NetworkFrame_t* frame)
{
#if CXX_SIMULATOR
    printf("Set Link: channel %x\n", frame->controlPacket.ChannelID);
#endif
}

static void getLinkStatusHandler(NetworkFrame_t* frame)
{
#if CXX_SIMULATOR
    printf("Get Link Status: channel %x\n", frame->controlPacket.ChannelID);
#endif
}

// CLEAR INITIAL STATE, SELECT PACKAGE, DESELECT PACKAGE, ENABLE CHANNEL, DISABLE CHANNEL, RESET CHANNEL, ENABLE CHANNEL NETWORK TX, DISABLE CHANNEL NETWORK TX,
 // AEN ENABLE, SET LINK;   then you need GET LINK STATUS

ncsi_handler_t gNCSIHandlers[] = 
{
    [0x00] = {.payloadLength = 0, .ignoreInit = true, .packageCommand = false,  .fn = clearInitialStateHandler},
    [0x01] = {.payloadLength = 4, .ignoreInit = true, .packageCommand = true,  .fn = selectPacakgeHandler},
    [0x02] = {.payloadLength = 0, .ignoreInit = true, .packageCommand = true,  .fn = deselectPacakgeHandler},
    [0x03] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = enableChannelHandler},
    [0x04] = {.payloadLength = 4, .ignoreInit = false, .packageCommand = false, .fn = disableChannelHandler},
    [0x05] = {.payloadLength = 4, .ignoreInit = false, .packageCommand = false, .fn = resetChannelHandler},
    [0x06] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = enableChannelNetworkTXHandler},
    [0x07] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = disableChannelNetworkTXHandler},
    [0x08] = {.payloadLength = 8, .ignoreInit = false, .packageCommand = false, .fn = AENEnableHandler}, // Conditional
    [0x09] = {.payloadLength = 8, .ignoreInit = false, .packageCommand = false, .fn = setLinkHandler},
    [0x0A] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = getLinkStatusHandler},
    [0x0B] = {.payloadLength = 8, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x0C] = {.payloadLength = 4, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x0D] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x0E] = {.payloadLength = 8, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x10] = {.payloadLength = 4, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x11] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x12] = {.payloadLength = 4, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x13] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x14] = {.payloadLength = 4, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler}, // Optional
    [0x15] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x16] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x17] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler},
    [0x18] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler}, // Optional
    [0x19] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler}, // Optional
    [0x1A] = {.payloadLength = 0, .ignoreInit = false, .packageCommand = false, .fn = unknownHandler}, // Optional
};

void handleNCSIFrame(NetworkFrame_t* frame)
{
    uint8_t ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    uint8_t command = frame->controlPacket.ControlPacketType;
    uint16_t payloadLength = frame->controlPacket.PayloadLength;
    ncsi_handler_t *handler = &gNCSIHandlers[command];
    channel_state_t *channel = ((ch == CHANNEL_ID_PACKAGE) ? 0 : &gPackageState.channel[ch]);

    if(handler->fn)
    {
        if(ch != CHANNEL_ID_PACKAGE &&
            ch >= gPackageState.numChannels)
        {
            channel = 0;
#if CXX_SIMULATOR
            printf("[%x] Invalid channel: %d\n", command, ch);
#endif
            // Channel does not exist.
            sendNCSIResponse(
                frame->controlPacket.InstanceID, 
                frame->controlPacket.ChannelID,
                frame->controlPacket.ControlPacketType,
                NCSI_RESPONSE_CODE_COMMAND_FAILED,
                NCSI_REASON_CODE_INVALID_PARAM);
        }
        else if( (true  == handler->packageCommand && channel) ||
            (false == handler->packageCommand && !channel))
        {
#if CXX_SIMULATOR
            printf("[%x] Invalid channel for command: %d\n", command, ch);
#endif
            // Command not targeting correct channel/package..
            sendNCSIResponse(
                frame->controlPacket.InstanceID, 
                frame->controlPacket.ChannelID,
                frame->controlPacket.ControlPacketType,
                NCSI_RESPONSE_CODE_COMMAND_FAILED,
                NCSI_REASON_CODE_INVALID_PARAM);
        }
        else if(false == handler->ignoreInit &&
                false == handler->packageCommand && /* Pacakge commands don't target a channel */
                false == gPackageState.channel[ch].initialized)
        {
#if CXX_SIMULATOR
            printf("[%x] Channel not initialized: %d\n", command, ch);
            printf("     Ignore Init: %d\n", handler->ignoreInit);
            printf("     Initialized: %d\n", gPackageState.channel[ch].initialized);
#endif
            // Initialization required for the channel
            sendNCSIResponse(
                frame->controlPacket.InstanceID, 
                frame->controlPacket.ChannelID,
                frame->controlPacket.ControlPacketType,
                NCSI_RESPONSE_CODE_COMMAND_FAILED,
                NCSI_REASON_CODE_INITIALIZATION_REQUIRED);
        }
        else if(handler->payloadLength != payloadLength)
        {
#if CXX_SIMULATOR
            printf("[%x] Unexpected payload length: 0x%04x != 0x%04x\n", command, handler->payloadLength, payloadLength);
#endif
            // Unexpected payload length
            sendNCSIResponse(
                frame->controlPacket.InstanceID, 
                frame->controlPacket.ChannelID,
                frame->controlPacket.ControlPacketType,
                NCSI_RESPONSE_CODE_COMMAND_FAILED,
                NCSI_REASON_CODE_INVALID_PAYLOAD_LENGTH);
        }
        else
        {
            if(channel)
            {
                ++channel->shm->NcsiChannelCtrlstatRx.r32;
            }
            gPackageState.selected = true;
            handler->fn(frame);
        }
    }
    else
    {
#if CXX_SIMULATOR
        printf("[%x] Unknown command\n", command);
#endif
        // Unknown command.
        sendNCSIResponse(
            frame->controlPacket.InstanceID, 
            frame->controlPacket.ChannelID,
            frame->controlPacket.ControlPacketType,
            NCSI_RESPONSE_CODE_COMMAND_UNSUPPORTED,
            NCSI_REASON_CODE_UNKNOWN_UNSUPPORTED);
    }
}

void resetChannel(int ch)
{
#if CXX_SIMULATOR
    printf("Resetting channel: %d\n", ch);
#endif

    channel_state_t* channel = &(gPackageState.channel[ch]);
    channel->initialized = false;
    channel->AENEnables = false;
    channel->AsyncronousTrafficEn = false;
    channel->PassthroughTXTrafficEn = false;

    channel->shm->NcsiChannelCtrlstatRx.r32 = 0;
}

void sendNCSIResponse(uint8_t InstanceID, uint8_t channelID, uint16_t controlID, uint16_t response_code, uint16_t reasons_code)
{
    uint32_t packetSize = ETHERNET_FRAME_MIN - 4;
    uint32_t packetWords = ((packetSize + 3) / 4);
    uint32_t lastBytes = packetSize % 4;

    RegAPE_PERIBmcToNcTxControl_t txControl;
    txControl.r32 = 0;
    txControl.bits.LastByteCount = lastBytes;

    gResponseFrame.responsePacket.ChannelID = channelID;
    gResponseFrame.responsePacket.ControlPacketType = controlID | CONTROL_PACKET_TYPE_RESPONSE;
    gResponseFrame.responsePacket.InstanceID = InstanceID;
    gResponseFrame.responsePacket.PayloadLength = 4; 
    // Payload data - 4 bytes
    gResponseFrame.responsePacket.ResponseCode = response_code;
    gResponseFrame.responsePacket.ReasonCode = reasons_code;
    // NetworkFrame_t frame;
    // frame.

    // Wait for enough free space. 
    while(APE_PERI.BmcToNcTxStatus.bits.InFifo < packetWords);

    // Transmit.
    for(int i = 0; i < packetWords-1; i++)
    {
#if CXX_SIMULATOR
    printf("Transmitting word %d: 0x%08x\n", i, gResponseFrame.words[i]);
#endif
        APE_PERI.BmcToNcTxBuffer.r32 = gResponseFrame.words[i];
    }

    APE_PERI.BmcToNcTxControl = txControl;

#if CXX_SIMULATOR
    printf("Transmitting last word %d: 0x%08x\n", packetWords - 1, gResponseFrame.words[packetWords - 1]);
#endif

    APE_PERI.BmcToNcTxBufferLast.r32 = gResponseFrame.words[packetWords - 1];
}

