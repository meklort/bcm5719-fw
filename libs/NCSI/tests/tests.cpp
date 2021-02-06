#include "gtest/gtest.h"
// #include <APE_APE.h>
#include <APE_APE_PERI.h>
#include <Ethernet.h>
#include <NCSI.h>
#include <bcm5719-endian.h>

uint32_t *gPacket;
uint32_t gPacketLen;

uint32_t gTXPacket[0x300 / 4];
uint32_t gTXPacketPos;

extern uint8_t select_package1[];
extern uint8_t clear_initial_state[];
extern uint8_t disable_vlan[];
extern uint8_t set_mac_addr[];
extern uint8_t enable_bcast_filter[];
extern uint8_t enable_network_tx[];
extern uint8_t enable_channel[];
extern uint8_t aen_enable[];
extern uint8_t get_link_status_ch0[];
extern uint8_t select_package2[];
extern uint8_t get_link_status_ch1[];
extern uint8_t get_link_status_ch2[];
extern uint8_t get_link_status_ch3[];
extern uint8_t disable_network_tx[];
extern uint8_t disable_channel[];
extern uint8_t deselect_package[];
extern uint8_t get_capabilities[];
extern uint8_t get_version_id[];

extern uint32_t select_package1_len;
extern uint32_t clear_initial_state_len;
extern uint32_t disable_vlan_len;
extern uint32_t set_mac_addr_len;
extern uint32_t enable_bcast_filter_len;
extern uint32_t enable_network_tx_len;
extern uint32_t enable_channel_len;
extern uint32_t aen_enable_len;
extern uint32_t get_link_status_ch0_len;
extern uint32_t select_package2_len;
extern uint32_t get_link_status_ch1_len;
extern uint32_t get_link_status_ch2_len;
extern uint32_t get_link_status_ch3_len;
extern uint32_t disable_network_tx_len;
extern uint32_t disable_channel_len;
extern uint32_t deselect_package_len;
extern uint32_t get_capabilities_len;
extern uint32_t get_version_id_len;

static uint32_t read_packet(uint32_t val, uint32_t offset, void *args)
{
    uint32_t data = 0;
    if (gPacketLen > 0)
    {
        data = *gPacket;
        gPacket++;
        if (gPacketLen > 4)
        {
            gPacketLen -= 4;
        }
        else
        {
            gPacketLen = 0;
        }
    }
    return htobe32(data);
}

static uint32_t write_packet(uint32_t val, uint32_t offset, void *args)
{
    val = htobe32(le32toh(val));
    // printf("Writing packet %x\n", val);
    gTXPacket[gTXPacketPos++] = le32toh(val); // Value from APE fw is in LE
    return val;
}

static uint32_t read_rx_status(uint32_t val, uint32_t offset, void *args)
{
    RegAPE_PERIBmcToNcRxStatus_t stat;
    stat.r32 = 0;
    stat.bits.New = gPacketLen ? 1 : 0;
    stat.bits.PacketLength = gPacketLen;

    return stat.r32;
}

static uint32_t read_tx_status(uint32_t val, uint32_t offset, void *args)
{
    RegAPE_PERIBmcToNcTxStatus_t stat;
    stat.r32 = 0;
    stat.bits.InFifo = sizeof(gTXPacket) - (gTXPacketPos * 4);

    return stat.r32;
}

void print_version(uint8_t* packet)
{
    printf("========== Version ================\n");
    printf("NCSI Version: %d.%d.%d %c%c\n", packet[20], packet[21], packet[22], packet[23], packet[27]);

    printf("Firmware Name: %.12s\n", (char*)&packet[28]);

    printf("Firmware Version: %02X.%02X.%02X.%02X\n", packet[40], packet[41], packet[42], packet[43]);
    printf("PCI Vendor:             0x%04X\n", packet[44] << 8 | packet[45]);
    printf("PCI Device:             0x%04X\n", packet[46] << 8 | packet[47]);
    printf("PCI Subsystem Vendor:   0x%04X\n", packet[48] << 8 | packet[49]);
    printf("PCI Subsystem Device:   0x%04X\n", packet[50] << 8 | packet[51]);
    printf("Manufacturer ID:        0x%08X\n", packet[52] << 24 | packet[53] << 16 | packet[54] << 8 | packet[55]);
    printf("Checksum:               0x%08X\n", packet[56] << 24 | packet[57] << 16 | packet[58] << 8 | packet[59]);
}

void print_capabilities(uint8_t* packet)
{
    printf("========== Capabilities ================\n");
    printf("Capabilities:           0x%08X\n", packet[20] << 24 | packet[21] << 16 | packet[22] << 8 | packet[23]);
    printf("Broadcast Capabilities: 0x%08X\n", packet[24] << 24 | packet[25] << 16 | packet[26] << 8 | packet[27]);
    printf("Multicast Capabilities: 0x%08X\n", packet[28] << 24 | packet[29] << 16 | packet[30] << 8 | packet[31]);
    printf("Buffering Capabilities: 0x%08X\n", packet[32] << 24 | packet[33] << 16 | packet[34] << 8 | packet[35]);
    printf("AEN Control Support:    0x%08X\n", packet[36] << 24 | packet[37] << 16 | packet[38] << 8 | packet[39]);
    printf("VLAN Filter Count:      %d\n", packet[40]);
    printf("Mixed Filter Count:     %d\n", packet[41]);
    printf("Multicast Filter Count: %d\n", packet[42]);
    printf("Unicast Filter Count:   %d\n", packet[43]);
    printf("Reserved[44-45]:        0x%02X 0x%02X\n", packet[44], packet[45]);
    printf("VLAN Mode Support:      %d\n", packet[46]);
    printf("Channel Count:          %d\n", packet[47]);
    printf("Checksum:               0x%08X\n", packet[48] << 24 | packet[49] << 16 | packet[50] << 8 | packet[51]);
}

void print_packet(uint32_t *packet_u32, size_t len)
{
    // Correct endian
    for(size_t i = 0; i < len; i++)
    {
        printf("0x%08X\n", packet_u32[i]);
    }
    uint8_t* packet = (uint8_t*)packet_u32;

    /** Ethernet Header **/
    printf("========= Ethernet Header ==============\n");
    printf("DA MAC:    %02x:%02x:%02x:%02x:%02x:%02x\n",
        packet[0], packet[1], packet[2],packet[3], packet[4], packet[5]);
    printf("SA MAC:    %02x:%02x:%02x:%02x:%02x:%02x\n",
        packet[6], packet[7], packet[8],packet[9], packet[10], packet[11]);

    printf("Ethertype: 0x%04X\n", packet[12] << 8 | packet[13]);
    packet += 14;
    /* NCSI Header */
    printf("=========== NCSI Header ================\n");
    printf("MC ID:              0x%02X\n", packet[0]);
    printf("Header Revision:    0x%02X\n", packet[1]);
    printf("Reserved[2]:        0x%02X\n", packet[2]);
    printf("IID:                0x%02X\n", packet[3]);
    printf("Command Type:       0x%02X\n", packet[4]);
    std::string type = "";
    if(packet[5] == 0x1f)
    {
        type = "(Package)";
    }
    printf("Channel:            0x%02X %s\n", packet[5], type.c_str());
    printf("Reserved[6]:        0x%02X\n", packet[6]);
    printf("Payload Length:     0x%02X\n", packet[7]);
    printf("Total Length:       0x%02lX\n", len * 4);
    printf("Reserved[8-15]:     0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\n",
        packet[8], packet[9], packet[10], packet[11], packet[12], packet[13], packet[14], packet[15]);

    uint8_t command = packet[4];
    uint8_t payload_len = packet[7];
    printf("=========== NCSI Command ===============\n");
    if(command & 0x80)
    {
        printf("Response Code:      0x%04X\n", packet[16] << 8 | packet[17]);
        printf("Reason Code:        0x%04X\n", packet[18] << 8 | packet[19]);
        printf("Checksum:           0x%08X\n",  packet[16 + payload_len] << 24 |
                                                packet[17 + payload_len] << 16 |
                                                packet[18 + payload_len] << 8 |
                                                packet[19 + payload_len]);
    }

    if(payload_len <= 4)
    {
        // No more data.
        return;
    }

    switch (command)
    {
        case 0x96:
            print_capabilities(packet);
            break;

        case 0x95:
            print_version(packet);
            break;
    }


}

void send_packet(uint8_t *packet, uint32_t len)
{
    gTXPacketPos = 0; // reset response position.
    gPacket = (uint32_t *)packet;
    gPacketLen = len;

    uint32_t buffer[1024];

    RegAPE_PERIBmcToNcRxStatus_t stat;
    stat.r32 = APE_PERI.BmcToNcRxStatus.r32;
    // stat.print();

    if (stat.bits.New)
    {
        int32_t bytes = stat.bits.PacketLength;
        int i = 0;
        while (bytes > 0)
        {
            uint32_t word = (APE_PERI.BmcToNcReadBuffer.r32);
            buffer[i] = word;
            // printf("Word %d: 0x%08X\n", i, word);
            i++;
            bytes -= 4;
        }

        NetworkFrame_t *frame = ((NetworkFrame_t *)buffer);

        if (stat.bits.Bad)
        {
            // TODO: ACK bad packet.
            APE_PERI.BmcToNcRxControl.bits.ResetBad = 1;
            while (APE_PERI.BmcToNcRxControl.bits.ResetBad)
                ;
        }
        else if (!stat.bits.Passthru)
        {
            handleNCSIFrame(frame);
            EXPECT_EQ(gTXPacket[0], 0xffffffff); // Source MAC
            EXPECT_EQ(gTXPacket[1], 0xffffffff); // Source/Dest MAC
            EXPECT_EQ(gTXPacket[2], 0xffffffff); // Dest MAC
            EXPECT_EQ(be32toh(gTXPacket[3]), 0x88f80001); // NCSI Type, Revision 1.
            EXPECT_EQ(be32toh(gTXPacket[4]),
                      buffer[4] |0x8000); // IID, Channel, Package, Command | 0x80

            print_packet((uint32_t*)gTXPacket, gTXPacketPos);
        }
        else
        {
            // Pass through to network
        }
    }
}

namespace
{



TEST(Packet, SelectPackage)
{
    NCSI_usePort(Network_getPort(0));
    APE_PERI.BmcToNcRxStatus.r32.installReadCallback(read_rx_status, NULL);
    APE_PERI.BmcToNcReadBuffer.r32.installReadCallback(read_packet, NULL);
    APE_PERI.BmcToNcTxStatus.r32.installReadCallback(read_tx_status, NULL);

    APE_PERI.BmcToNcTxBuffer.r32.installWriteCallback(write_packet, NULL);
    APE_PERI.BmcToNcTxBufferLast.r32.installWriteCallback(write_packet, NULL);

    send_packet(deselect_package, deselect_package_len);
    // send_packet(select_package1, select_package1_len);
    // send_packet(clear_initial_state, clear_initial_state_len);
    // send_packet(get_version_id, get_version_id_len);
    // send_packet(get_capabilities, get_capabilities_len);
}

// TEST(Packet, GetCapabilities)
// {
//     // APE_PERI.BmcToNcRxStatus.r32.installReadCallback(read_rx_status, NULL);
//     // APE_PERI.BmcToNcReadBuffer.r32.installReadCallback(read_packet, NULL);
//     // APE_PERI.BmcToNcTxStatus.r32.installReadCallback(read_tx_status, NULL);

//     // APE_PERI.BmcToNcTxBuffer.r32.installWriteCallback(write_packet, NULL);
//     // APE_PERI.BmcToNcTxBufferLast.r32.installWriteCallback(write_packet, NULL);
//     send_packet(clear_initial_state, clear_initial_state_len);

//     send_packet(get_capabilities, get_capabilities_len);

//     uint32_t buffer[clear_initial_state_len];
//     memcpy(buffer, clear_initial_state, clear_initial_state_len);
//     print_packet(buffer, clear_initial_state_len);
// }

// TEST(Packet, GetVersionID)
// {
//     // APE_PERI.BmcToNcRxStatus.r32.installReadCallback(read_rx_status, NULL);
//     // APE_PERI.BmcToNcReadBuffer.r32.installReadCallback(read_packet, NULL);
//     // APE_PERI.BmcToNcTxStatus.r32.installReadCallback(read_tx_status, NULL);

//     // APE_PERI.BmcToNcTxBuffer.r32.installWriteCallback(write_packet, NULL);
//     // APE_PERI.BmcToNcTxBufferLast.r32.installWriteCallback(write_packet, NULL);
//     send_packet(clear_initial_state, clear_initial_state_len);

//     send_packet(get_version_id, get_version_id_len);
// }


} // namespace
