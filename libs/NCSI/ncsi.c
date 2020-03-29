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

#include <APE.h>
#include <APE_APE_PERI.h>
#include <APE_DEVICE.h>
#include <APE_SHM.h>
#include <MII.h>
#include <NCSI.h>
#include <Network.h>
#include <types.h>

#ifdef CXX_SIMULATOR
#include <stdio.h>
#else
#include <printf.h>
#endif
#define debug(...) printf(__VA_ARGS__)

#define NUM_CHANNELS 1
#define MAX_CHANNELS 4

#define PACKAGE_ID_SHIFT 5
#define PACKAGE_ID_MASK (0xE0)
#define CHANNEL_ID_SHIFT 0
#define CHANNEL_ID_MASK (0x1F)
#define CHANNEL_ID_PACKAGE (0x1F)
uint8_t gPackageID = ((0 << PACKAGE_ID_SHIFT) | CHANNEL_ID_PACKAGE);

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
        .PayloadLength = 4,
        .reserved_1 = 0,

        .ResponseCode = 0,      /* Filled in by appropriate handler. */
        .reserved_4 = 0,
        .reserved_5 = 0,
        .ReasonCode = 0,        /* Filled in by appropriate handler. */
        .Checksum_High = 0,
        .Checksum_Low = 0,
    },
};

NetworkFrame_t gLinkStatusResponseFrame =
{
    .linkStatusResponse = {
        .DestinationAddress = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        .SourceAddress =      {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},

        .HeaderRevision = 1,
        .ManagmentControllerID = 0,
        .EtherType = ETHER_TYPE_NCSI,
        .ChannelID = 0,         /* Filled in by appropriate handler. */
        .ControlPacketType = CONTROL_PACKET_TYPE_RESPONSE | CONTROL_PACKET_TYPE_GET_LINK_STATUS,
        .InstanceID = 0,        /* Filled in by appropriate handler. */
        .reserved_0 = 0,
        .reserved_2 = 0,
        .PayloadLength = 16,
        .reserved_1 = 0,

        .ResponseCode = NCSI_RESPONSE_CODE_COMMAND_COMPLETE,
        .reserved_4 = 0,
        .LinkStatus_High = 0,
        .ReasonCode = NCSI_REASON_CODE_NONE,
        .OtherIndications_High = 0,
        .LinkStatus_Low = 0,
        .OEMLinkStatus_High = 0,
        .OtherIndications_Low = 0,
        .pad = 0,
        .OEMLinkStatus_Low = 0,

        .Checksum_High = 0,
        .Checksum_Low = 0,
    },
};

NetworkFrame_t gCapabilitiesFrame =
{
    .capabilities = {
        .DestinationAddress = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        .SourceAddress =      {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},

        .HeaderRevision = 1,
        .ManagmentControllerID = 0,
        .EtherType = ETHER_TYPE_NCSI,
        .ChannelID = 0,         /* Filled in by appropriate handler. */
        .ControlPacketType = CONTROL_PACKET_TYPE_RESPONSE | CONTROL_PACKET_TYPE_GET_CAPABILITIES,
        .InstanceID = 0,        /* Filled in by appropriate handler. */
        .reserved_0 = 0,
        .reserved_2 = 0,
        .PayloadLength = 32,
        .reserved_1 = 0,

        .ResponseCode = NCSI_RESPONSE_CODE_COMMAND_COMPLETE,
        .reserved_4 = 0,

        .Capabilities_High = 0,
        .ReasonCode = NCSI_REASON_CODE_NONE,
        .BroadcastCapabilities_High = 0,
        .Capabilities_Low = 0,
        .MilticastCapabilities_High = 0,
        .BroadcastCapabilities_Low = 0xF,
        .BufferingCapabilities_High = 0,
        .MilticastCapabilities_Low = 0x7,
        .AENControlSupport_High = 0,
        .BufferingCapabilities_Low = 0x7,
        .VLANFilterCount = 1,
        .MixedFilterCount = 1,
        .AENControlSupport_Low = 0,
        .ChannelCount = NUM_CHANNELS,
        .VLANModeSupport = 0x7,
        .MulticastFilterCount = 1,
        .UnicastFilterCount = 1,

        .Checksum_High = 0,
        .Checksum_Low = 0,
    },
};

NetworkFrame_t gVersionFrame =
{
    .version = {
        .DestinationAddress = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        .SourceAddress =      {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},

        .HeaderRevision = 1,
        .ManagmentControllerID = 0,
        .EtherType = ETHER_TYPE_NCSI,
        .ChannelID = 0,         /* Filled in by appropriate handler. */
        .ControlPacketType = CONTROL_PACKET_TYPE_RESPONSE | CONTROL_PACKET_TYPE_GET_VERSION_ID,
        .InstanceID = 0,        /* Filled in by appropriate handler. */
        .reserved_0 = 0,
        .reserved_2 = 0,
        .PayloadLength = 40,
        .reserved_1 = 0,

        .ResponseCode = NCSI_RESPONSE_CODE_COMMAND_COMPLETE,
        .ReasonCode = NCSI_REASON_CODE_NONE,

        // NCSI Version
        .NCSIMajor = 1,
        .NCSIMinor = 2,
        .NCSIUpdate = 4,
        .NCSIAlpha1 = 'a',
        .NCSIAlpha2 = 'b',

        // Firmware Name
        .name_11 = 'B',
        .name_10 = 'C',
        .name_9 = 'M',
        .name_8 = '5',
        .name_7 = '7',
        .name_6 = '1',
        .name_5 = '9',
        .name_4 = ' ',
        .name_3 = 'N',
        .name_2 = 'C',
        .name_1 = 'S',
        .name_0 = 'I',

        // Firmware Version
        .FWVersion_High = (VERSION_MAJOR << 8) | (VERSION_MINOR),
        .FWVersion_Low = (VERSION_PATCH),

        // Populated based on NVM
        .PCIVendor = 0xFFFF,
        .PCIDevice = 0xFFFF,
        .PCISubsystemVendor = 0xFFFF,
        .PCISubsystemDevice = 0xFFFF,

        // Manufacturer ID
        .ManufacturerID_High = 0x5454,
        .ManufacturerID_Low = 0x3232,

        .Checksum_High = 0,
        .Checksum_Low = 0,
    },
};

typedef struct
{
    bool selected;
    int numChannels;
    NetworkPort_t *port[MAX_CHANNELS];
} package_state_t;

package_state_t gPackageState = {
    .selected = false,
    .numChannels = NUM_CHANNELS,
    .port = {
        [0] = &gPort0,
        [1] = &gPort1,
        [2] = &gPort2,
        [3] = &gPort3,
    },
};

void sendNCSIResponse(uint8_t InstanceID, uint8_t channelID, uint16_t controlID, uint16_t response_code, uint16_t reasons_code);
void sendNCSILinkStatusResponse(uint8_t InstanceID, uint8_t channelID, uint32_t LinkStatus, uint32_t OEMLinkStatus, uint32_t OtherIndications);

void resetChannel(int ch);

#if CXX_SIMULATOR
#include <stdio.h>
#endif

typedef struct
{
    bool ignoreInit;
    bool packageCommand;
    int payloadLength;
    void (*fn)(NetworkFrame_t *);

} ncsi_handler_t;

void unknownHandler(NetworkFrame_t *frame)
{
    debug("Unhandled Packet Type: %x\n", frame->header.EtherType);
    debug("ManagmentControllerID: %x\n", frame->controlPacket.ManagmentControllerID);
    debug("HeaderRevision: %x\n", frame->controlPacket.HeaderRevision);
    debug("Control Packet Type: %x\n", frame->controlPacket.ControlPacketType);
    debug("Channel ID: %x\n", frame->controlPacket.ChannelID);
    debug("Instance ID: %d\n", frame->controlPacket.InstanceID);
    debug("Payload Length: %d\n", frame->controlPacket.PayloadLength);

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_UNSUPPORTED, NCSI_REASON_CODE_UNKNOWN_UNSUPPORTED);
}

static void clearInitialStateHandler(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

    gPackageState.port[ch]->shm_channel->NcsiChannelInfo.bits.Ready = true;
    debug("Clear initial state: channel %x\n", ch);

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void selectPackageHandler(NetworkFrame_t *frame)
{
    debug("Package enabled. Arb: %d\n", !frame->selectPackage.HardwareArbitartionDisabled);
    gPackageState.selected = true;
    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void deselectPackageHandler(NetworkFrame_t *frame)
{
    debug("Package disabled.\n");
    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
    gPackageState.selected = false;
}

static void enableChannelHandler(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

    debug("Enable Channel: %x\n", ch);
    gPackageState.port[ch]->shm_channel->NcsiChannelInfo.bits.Enabled = true;

    Network_InitPort(gPackageState.port[ch], AS_NEEDED);

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void disableChannelHandler(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

    debug("Disable Channel: %x\n", ch);
    gPackageState.port[ch]->shm_channel->NcsiChannelInfo.bits.Enabled = false;

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void resetChannelHandler(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

    debug("Reset Channel: %x\n", ch);
    resetChannel(ch);

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void enableChannelNetworkTXHandler(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

    debug("Enable Channel Network TX: channel %x\n", ch);
    gPackageState.port[ch]->shm_channel->NcsiChannelInfo.bits.TXPassthrough = true;

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void disableChannelNetworkTXHandler(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;

    debug("Disable Channel Network TX: %x\n", ch);
    gPackageState.port[ch]->shm_channel->NcsiChannelInfo.bits.TXPassthrough = false;

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void AENEnableHandler(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    uint32_t AENControl = (frame->AENEnable.AENControl_Low | (frame->AENEnable.AENControl_High << 16));
    debug("AEN Enable: AEN_MC_ID %x\n", frame->AENEnable.AEN_MC_ID);
    debug("AEN Enable: AENControl %x\n", AENControl);

    gPackageState.port[ch]->shm_channel->NcsiChannelMcid.r32 = frame->AENEnable.AEN_MC_ID;
    gPackageState.port[ch]->shm_channel->NcsiChannelAen.r32 = AENControl;

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void setLinkHandler(NetworkFrame_t *frame)
{
    uint32_t LinkSettings = (frame->setLink.LinkSettings_Low | (frame->setLink.LinkSettings_High << 16));
    uint32_t OEMLinkSettings = (frame->setLink.OEMLinkSettings_Low | (frame->setLink.OEMLinkSettings_High << 16));
    debug("Set Link: LinkSettings %x\n", LinkSettings);
    debug("Set Link: OEMLinkSettings %x\n", OEMLinkSettings);

    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    NetworkPort_t *port = gPackageState.port[ch];
    port->shm_channel->NcsiChannelSetting1.r32 = LinkSettings;
    port->shm_channel->NcsiChannelSetting2.r32 = OEMLinkSettings;

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void getLinkStatusHandler(NetworkFrame_t *frame)
{
    RegMIIAuxiliaryStatusSummary_t stat;

    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    NetworkPort_t *port = gPackageState.port[ch];
    uint8_t phy = MII_getPhy(port->device);

    uint32_t rx = port->shm_channel->NcsiChannelCtrlstatAllRx.r32;
    uint32_t tx = port->shm_channel->NcsiChannelCtrlstatAllRx.r32;

    APE_aquireLock();
    stat.r16 = MII_readRegister(port->device, phy, (mii_reg_t)REG_MII_AUXILIARY_STATUS_SUMMARY);
    APE_releaseLock();

    RegSHM_CHANNELNcsiChannelStatus_t linkStatus = port->shm_channel->NcsiChannelStatus;

    uint32_t tx_used = APE_TX_TO_NET_BUFFER_RING_FREE_MAX - port->tx_ring->bits.Free;
    uint32_t rx_avail = APE_RX_POOL_FREE_POINTER_FREE_COUNT_MAX - port->rx_ring->bits.FreeCount;
    debug("Link Status [%d] %s, TX %d [%d used], RX %d [%d avail]\n", frame->controlPacket.ChannelID, stat.bits.LinkStatus ? "up" : "down", tx, tx_used, rx, rx_avail);

    if (!stat.bits.LinkStatus)
    {
        if (!Network_isLinkUp(port))
        {
            printf("Resetting link.\n");
            Network_resetLink(port);
        }
    }

    linkStatus.bits.Linkup = stat.bits.LinkStatus;
    linkStatus.bits.LinkStatus = stat.bits.AutoNegotiationHCD;
    linkStatus.bits.AutonegotiationEnabled = 1;
    linkStatus.bits.AutonegotiationComplete = stat.bits.AutoNegotiationComplete;

    port->shm_channel->NcsiChannelStatus = linkStatus;

    uint32_t LinkStatus = linkStatus.r32;
    uint32_t OEMLinkStatus = 0;
    uint32_t OtherIndications = 0;

    sendNCSILinkStatusResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, LinkStatus, OEMLinkStatus, OtherIndications);
}

static void disableVLANHandler(NetworkFrame_t *frame)
{
    // TODO
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    NetworkPort_t *port = gPackageState.port[ch];
    port->shm_channel->NcsiChannelInfo.bits.VLAN = false;

    debug("Disable VLAN: channel %x\n", ch);

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void getCapabilities(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    // NetworkPort_t *port = gPackageState.port[ch];
    uint32_t packetSize = MAX(sizeof(gCapabilitiesFrame.capabilities), ETHERNET_FRAME_MIN - 4);

    gCapabilitiesFrame.capabilities.ChannelID = ch;
    gCapabilitiesFrame.capabilities.ControlPacketType = frame->controlPacket.ControlPacketType | CONTROL_PACKET_TYPE_RESPONSE;
    gCapabilitiesFrame.capabilities.InstanceID = frame->controlPacket.InstanceID;
    gCapabilitiesFrame.capabilities.ResponseCode = NCSI_RESPONSE_CODE_COMMAND_COMPLETE;
    gCapabilitiesFrame.capabilities.ReasonCode = NCSI_REASON_CODE_NONE;

    NCSI_TxPacket(gCapabilitiesFrame.words, packetSize);
}

static void getVersionID(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    NetworkPort_t *port = gPackageState.port[ch];
    DEVICE_t *device = (DEVICE_t *)port->device;
    uint32_t packetSize = MAX(sizeof(gVersionFrame.version), ETHERNET_FRAME_MIN - 4);

    gVersionFrame.version.ChannelID = ch;
    gVersionFrame.version.ControlPacketType = frame->controlPacket.ControlPacketType | CONTROL_PACKET_TYPE_RESPONSE;
    gVersionFrame.version.InstanceID = frame->controlPacket.InstanceID;
    gVersionFrame.version.ResponseCode = NCSI_RESPONSE_CODE_COMMAND_COMPLETE;
    gVersionFrame.version.ReasonCode = NCSI_REASON_CODE_NONE;

    gVersionFrame.version.PCIVendor = device->PciVendorDeviceId.bits.VendorID;
    gVersionFrame.version.PCIDevice = device->PciVendorDeviceId.bits.DeviceID;
    gVersionFrame.version.PCISubsystemVendor = device->PciSubsystemId.bits.SubsystemVendorID;
    gVersionFrame.version.PCISubsystemDevice = device->PciSubsystemId.bits.SubsystemID;

    NCSI_TxPacket(gVersionFrame.words, packetSize);
}

static void enableVLANHandler(NetworkFrame_t *frame)
{
    // TODO
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    NetworkPort_t *port = gPackageState.port[ch];
    port->shm_channel->NcsiChannelInfo.bits.VLAN = false;

    debug("Enable VLAN: channel %x\n", ch);

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void setVLANFilter(NetworkFrame_t *frame)
{
    // TODO
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    NetworkPort_t *port = gPackageState.port[ch];
    port->shm_channel->NcsiChannelInfo.bits.VLAN = false;

    debug("Set VLAN Filter: channel %x\n", ch);

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void setMACAddressHandler(NetworkFrame_t *frame)
{
    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    NetworkPort_t *port = gPackageState.port[ch];
    // port->shm_channel->NcsiChannelInfo.bits.Enabled = false;

    debug("Set MAC: channel %x\n", ch);
    debug("  MAC: 0x%04x%04x%04x\n", frame->setMACAddr.MAC54, frame->setMACAddr.MAC32, frame->setMACAddr.MAC10);
    debug("  Enable: %d\n", frame->setMACAddr.Enable);
    debug("  AT: %d\n", frame->setMACAddr.AT);
    debug("  MACNumber: %d\n", frame->setMACAddr.MACNumber);

    // TODO: Handle AT.

    // NC-SI has the mac starting at 1, reindex based at 0.
    if (frame->setMACAddr.MACNumber > 0)
    {
        frame->setMACAddr.MACNumber--;
    }

    uint32_t low = (frame->setMACAddr.MAC32 << 16) | frame->setMACAddr.MAC10;
    Network_SetMACAddr(port, frame->setMACAddr.MAC54, low, frame->setMACAddr.MACNumber, frame->setMACAddr.Enable);

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

static void enableBroadcastFilteringHandler(NetworkFrame_t *frame)
{
    // TODO
    // channel_state_t* channel = gPackageState.port[ch];
    // port->shm_channel->NcsiChannelInfo.bits.Enabled = false;

    int ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    debug("Enable Broadcast Filtering: channel %x\n", ch);

    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                     NCSI_RESPONSE_CODE_COMMAND_COMPLETE, NCSI_REASON_CODE_NONE);
}

// CLEAR INITIAL STATE, SELECT PACKAGE, DESELECT PACKAGE, ENABLE CHANNEL, DISABLE CHANNEL, RESET CHANNEL, ENABLE CHANNEL NETWORK TX, DISABLE CHANNEL NETWORK TX,
// AEN ENABLE, SET LINK;   then you need GET LINK STATUS
ncsi_handler_t gNCSIHandlers[] = {
    /* Package / Initialization commands */
    [0x00] = { .ignoreInit = true,  .packageCommand = false, .payloadLength = 0, .fn = clearInitialStateHandler },
    [0x01] = { .ignoreInit = false, .packageCommand = true,  .payloadLength = 4, .fn = selectPackageHandler },
    [0x02] = { .ignoreInit = false, .packageCommand = true,  .payloadLength = 0, .fn = deselectPackageHandler },

    /* Channel Specific commands */
    [0x03] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = enableChannelHandler },
    [0x04] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 4, .fn = disableChannelHandler },
    [0x05] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 4, .fn = resetChannelHandler },
    [0x06] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = enableChannelNetworkTXHandler },
    [0x07] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = disableChannelNetworkTXHandler },
    [0x08] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 8, .fn = AENEnableHandler }, // Conditional
    [0x09] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 8, .fn = setLinkHandler },
    [0x0A] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = getLinkStatusHandler },
    [0x0B] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 8, .fn = setVLANFilter },
    [0x0C] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 4, .fn = enableVLANHandler },
    [0x0D] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = disableVLANHandler },
    [0x0E] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 8, .fn = setMACAddressHandler },
    [0x10] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 4, .fn = enableBroadcastFilteringHandler },
    [0x11] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = unknownHandler },
    [0x12] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 4, .fn = unknownHandler },
    [0x13] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = unknownHandler },
    [0x14] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 4, .fn = unknownHandler }, // Optional
    [0x15] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = getVersionID },
    [0x16] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = getCapabilities },
    [0x17] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = unknownHandler },
    [0x18] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = unknownHandler }, // Optional
    [0x19] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = unknownHandler }, // Optional
    [0x1A] = { .ignoreInit = false, .packageCommand = false, .payloadLength = 0, .fn = unknownHandler }, // Optional
};

void handleNCSIFrame(NetworkFrame_t *frame)
{
    uint8_t package = frame->controlPacket.ChannelID >> PACKAGE_ID_SHIFT;
    if (package != 0)
    {
        // debug("Ignoring command to package %d\n", package);

        // Ignore - not us.
        return;
    }
    uint8_t ch = frame->controlPacket.ChannelID & CHANNEL_ID_MASK;
    uint8_t command = frame->controlPacket.ControlPacketType;
    uint16_t payloadLength = frame->controlPacket.PayloadLength;
    ncsi_handler_t *handler = &gNCSIHandlers[command];
    NetworkPort_t *port = ((ch >= gPackageState.numChannels) ? 0 : gPackageState.port[ch]);

    if (handler->fn)
    {
        if (handler->payloadLength != payloadLength)
        {
#if CXX_SIMULATOR
            debug("[%x] Unexpected payload length: 0x%04x != 0x%04x\n", command, handler->payloadLength, payloadLength);
#endif
            // Unexpected payload length
            sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                             NCSI_RESPONSE_CODE_COMMAND_FAILED, NCSI_REASON_CODE_INVALID_PAYLOAD_LENGTH);
        }
        else if ((handler->packageCommand && ch == CHANNEL_ID_PACKAGE) || // Package commands are always accepted.
                 (handler->ignoreInit && ch < gPackageState.numChannels))
        {
            // Package command. Must handle.
            debug("[%x] packageCommand/ignore init channel: %d\n", command, ch);

            if (port)
            {
                ++port->shm_channel->NcsiChannelCtrlstatRx.r32;
            }
            gPackageState.selected = true;
            SHM.SegSig.r32 |= (1 << command);
            handler->fn(frame);
        }
        else
        {
            if (ch >= gPackageState.numChannels)
            {

                debug("[%x] Invalid channel: %d\n", command, ch);
                // Channel does not exist.
                sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                                 NCSI_RESPONSE_CODE_COMMAND_FAILED, NCSI_REASON_CODE_INVALID_PARAM);
            }
            else
            {
                gPackageState.selected = true;
                if (false == gPackageState.port[ch]->shm_channel->NcsiChannelInfo.bits.Ready)
                {
                    debug("[%x] Channel not initialized: %d\n", command, ch);
                    // Initialization required for the channel
                    sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                                     NCSI_RESPONSE_CODE_COMMAND_FAILED, NCSI_REASON_CODE_INITIALIZATION_REQUIRED);
                }
                else
                {
                    if (port)
                    {
                        ++port->shm_channel->NcsiChannelCtrlstatRx.r32;
                    }
                    SHM.SegSig.r32 |= (1 << command);
                    handler->fn(frame);
                }
            }
        }
    }
    else
    {
        debug("[%x] Unknown command\n", command);

        // Unknown command.
        sendNCSIResponse(frame->controlPacket.InstanceID, frame->controlPacket.ChannelID, frame->controlPacket.ControlPacketType,
                         NCSI_RESPONSE_CODE_COMMAND_UNSUPPORTED, NCSI_REASON_CODE_UNKNOWN_UNSUPPORTED);
    }
}

void resetChannel(int ch)
{
    NetworkPort_t *port = gPackageState.port[ch];

    port->shm_channel->NcsiChannelInfo.r32 = 0;
    port->shm_channel->NcsiChannelCtrlstatRx.r32 = 0;
    port->shm_channel->NcsiChannelCtrlstatAllTx.r32 = 0;
    port->shm_channel->NcsiChannelCtrlstatAllRx.r32 = 0;
    port->shm_channel->NcsiChannelInfo.bits.Ready = false;

    uint8_t phy = MII_getPhy(port->device);
    APE_aquireLock();
    MII_writeRegister(port->device, phy, (mii_reg_t)REG_MII_CONTROL, MII_CONTROL_RESET_MASK);
    APE_releaseLock();
}

void reloadChannel(int ch, reload_type_t reset_phy)
{
    NetworkPort_t *port = gPackageState.port[ch];

    uint32_t low = port->shm_channel->NcsiChannelMac0Mid.r32 << 16 | port->shm_channel->NcsiChannelMac0Low.r32;
    uint16_t high = port->shm_channel->NcsiChannelMac0High.r32;
    Network_SetMACAddr(port, high, low, /* TBD */ 0, 1);

    if (gPackageState.port[ch]->shm_channel->NcsiChannelInfo.bits.Enabled)
    {
        printf("[ch %d] Reusing MAC: 0x%02X%04X\n", ch, high, low);

        Network_InitPort(gPackageState.port[ch], reset_phy);
    }
}

void NCSI_TxPacket(uint32_t *packet, uint32_t packet_len)
{
    uint32_t packetWords = DIVIDE_RND_UP(packet_len, sizeof(uint32_t));

    RegAPE_PERIBmcToNcTxControl_t txControl;
    txControl.r32 = 0;
    txControl.bits.LastByteCount = packet_len; /* 2 bits - automatically rounded. */

    // Wait for enough free space.
    while (APE_PERI.BmcToNcTxStatus.bits.InFifo < packetWords)
    {
    }

    // Transmit.
    for (int i = 0; i < packetWords - 1; i++)
    {
#if CXX_SIMULATOR
        debug("Transmitting word %d: 0x%08x\n", i, packet[i]);
#endif
        APE_PERI.BmcToNcTxBuffer.r32 = packet[i];
    }

    APE_PERI.BmcToNcTxControl = txControl;

#if CXX_SIMULATOR
    debug("Last byte count: %d\n", (int)txControl.bits.LastByteCount);
    debug("Transmitting last word %d: 0x%08x\n", packetWords - 1, packet[packetWords - 1]);
#endif
    APE_PERI.BmcToNcTxBufferLast.r32 = packet[packetWords - 1];
}
void sendNCSILinkStatusResponse(uint8_t InstanceID, uint8_t channelID, uint32_t LinkStatus, uint32_t OEMLinkStatus, uint32_t OtherIndications)
{
    uint32_t packetSize = MAX(sizeof(gLinkStatusResponseFrame.linkStatusResponse), ETHERNET_FRAME_MIN - 4);

    gLinkStatusResponseFrame.linkStatusResponse.ChannelID = channelID;
    gLinkStatusResponseFrame.linkStatusResponse.InstanceID = InstanceID;
    gLinkStatusResponseFrame.linkStatusResponse.ResponseCode = NCSI_RESPONSE_CODE_COMMAND_COMPLETE;
    gLinkStatusResponseFrame.linkStatusResponse.ReasonCode = NCSI_REASON_CODE_NONE;

    gLinkStatusResponseFrame.linkStatusResponse.LinkStatus_High = LinkStatus >> 16;
    gLinkStatusResponseFrame.linkStatusResponse.LinkStatus_Low = LinkStatus & 0xffff;
    gLinkStatusResponseFrame.linkStatusResponse.OEMLinkStatus_High = OEMLinkStatus >> 16;
    gLinkStatusResponseFrame.linkStatusResponse.OEMLinkStatus_Low = OEMLinkStatus & 0xffff;
    gLinkStatusResponseFrame.linkStatusResponse.OtherIndications_High = OtherIndications >> 16;
    gLinkStatusResponseFrame.linkStatusResponse.OtherIndications_Low = OtherIndications & 0xffff;

    NCSI_TxPacket(gLinkStatusResponseFrame.words, packetSize);
}

void sendNCSIResponse(uint8_t InstanceID, uint8_t channelID, uint16_t controlID, uint16_t response_code, uint16_t reasons_code)
{
    uint32_t packetSize = MAX(sizeof(gResponseFrame.responsePacket), ETHERNET_FRAME_MIN - 4);

    gResponseFrame.responsePacket.ChannelID = channelID;
    gResponseFrame.responsePacket.ControlPacketType = controlID | CONTROL_PACKET_TYPE_RESPONSE;
    gResponseFrame.responsePacket.InstanceID = InstanceID;

    gResponseFrame.responsePacket.ResponseCode = response_code;
    gResponseFrame.responsePacket.ReasonCode = reasons_code;

    NCSI_TxPacket(gResponseFrame.words, packetSize);
}

void NCSI_init(void)
{
    debug("Resetting channels...\n");
    for (int i = 0; i < ARRAY_ELEMENTS(gPackageState.port); i++)
    {
        resetChannel(i);
    }
    SHM.SegSig.r32 = 0; // (1 << command);
}

void NCSI_reload(reload_type_t reset_phy)
{
    for (int i = 0; i < ARRAY_ELEMENTS(gPackageState.port); i++)
    {
        reloadChannel(i, reset_phy);
    }
}

void NCSI_handlePassthrough(void)
{
    for (int ch = 0; ch < ARRAY_ELEMENTS(gPackageState.port); ch++)
    {
        NetworkPort_t *port = gPackageState.port[ch];
        VOLATILE SHM_CHANNEL_t *shm_ch = port->shm_channel;
        if (shm_ch->NcsiChannelInfo.bits.Ready)
        {
            Network_PassthroughRxPatcket(port);
            ++shm_ch->NcsiChannelCtrlstatAllTx.r32;
        }
    }
}
