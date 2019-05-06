#include "gtest/gtest.h"
// #include <APE_APE.h>
#include <APE_APE_PERI.h>
#include <Ethernet.h>
#include <NCSI.h>
#include <endian.h>

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
    val = le32toh(val);
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
            EXPECT_EQ(gTXPacket[3], 0x88f80001); // NCSI Type, Revision 1.
            EXPECT_EQ(gTXPacket[4],
                      buffer[4] |
                          0x8000); // IID, Channel, Package, Command | 0x80
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
    APE_PERI.BmcToNcRxStatus.r32.installReadCallback(read_rx_status, NULL);
    APE_PERI.BmcToNcReadBuffer.r32.installReadCallback(read_packet, NULL);
    APE_PERI.BmcToNcTxStatus.r32.installReadCallback(read_tx_status, NULL);

    APE_PERI.BmcToNcTxBuffer.r32.installWriteCallback(write_packet, NULL);
    APE_PERI.BmcToNcTxBufferLast.r32.installWriteCallback(write_packet, NULL);

    send_packet(select_package1, select_package1_len);
}

} // namespace
