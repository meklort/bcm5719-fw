////////////////////////////////////////////////////////////////////////////////
///
/// @file       tx.c
///
/// @project
///
/// @brief      Network transmission routines
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

#include <APE_APE.h>
#include <APE_SHM.h>
#include <APE_TX_PORT0.h>
#include <Ethernet.h>
#include <Network.h>

#ifdef CXX_SIMULATOR
#include <stdio.h>
#else
#include <printf.h>
#endif

#define FIRST_FRAME_MAX ((TX_PORT_OUT_ALL_BLOCK_WORDS - TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD) * sizeof(uint32_t))
#define ADDITIONAL_FRAME_MAX ((TX_PORT_OUT_ALL_BLOCK_WORDS - TX_PORT_OUT_ALL_ADDITIONAL_PAYLOAD_WORD) * sizeof(uint32_t))

uint32_t Network_TX_numBlocksNeeded(uint32_t frame_size)
{
    uint32_t blocks = 1;

    if (frame_size > FIRST_FRAME_MAX)
    {
        frame_size -= FIRST_FRAME_MAX;

        blocks += DIVIDE_RND_UP(frame_size, ADDITIONAL_FRAME_MAX);
    }

    return blocks;
}

int32_t __attribute__((noinline)) Network_TX_allocateBlock(NetworkPort_t *port)
{
    int32_t block;

    // Set the alloc bit.
    RegAPETxToNetBufferAllocator_t alloc;
    alloc.r32 = 0;
    alloc.bits.RequestAllocation = 1;
    *((RegAPETxToNetBufferAllocator_t *)port->tx_allocator) = alloc;

    // Wait for state machine to finish
    RegAPETxToNetBufferAllocator_t status;
    do
    {
        status = *port->tx_allocator;
    } while (APE_TX_TO_NET_BUFFER_ALLOCATOR_STATE_PROCESSING == status.bits.State);

    if (APE_TX_TO_NET_BUFFER_ALLOCATOR_STATE_ALLOCATION_OK != status.bits.State)
    {
        block = -1;
        printf("TX Alloc Error.\n");
    }
    else
    {
        block = status.bits.Index;
    }

    return block;
} //lint !e818

static uint32_t inline Network_TX_initFirstBlock(RegTX_PORTOut_t *block, uint32_t length, int32_t blocks, int32_t next_block, uint32_t *packet, bool big_endian)
{
    network_control_t control;
    int copy_length;
    int i;

    control.r32 = 0;
    control.bits.next_block = next_block >= 0 ? next_block : 0;
    control.bits.first = 1;

    if (length > FIRST_FRAME_MAX)
    {
        copy_length = FIRST_FRAME_MAX;
        control.bits.not_last = 1;
    }
    else
    {
        // Last.
        copy_length = length;
        control.bits.not_last = 0;
    }

    // block[1] = uninitialized;
    block[2].r32 = 0;
    block[TX_PORT_OUT_ALL_FRAME_LEN_WORD].r32 = length;
    block[4].r32 = 0;
    block[5].r32 = 0;
    block[6].r32 = 0;
    block[7].r32 = 0;
    block[8].r32 = 0;
    block[TX_PORT_OUT_ALL_NUM_BLOCKS_WORD].r32 = blocks;
    // block[10] = uninitialized;
    // block[11] = uninitialized;

    // Copy Payload Data.
    int num_words = (copy_length + sizeof(uint32_t) - 1) / sizeof(uint32_t);
    for (i = 0; i < num_words; i++)
    {
        if (big_endian)
        {
#ifdef CXX_SIMULATOR
            printf("1st[%d] = 0x%08X\n", i, be32toh(packet[i]));
#endif
            block[TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD + i].r32 = be32toh(packet[i]);
        }
        else
        {
#ifdef CXX_SIMULATOR
            printf("1LE[%d] = 0x%08X\n", i, (packet[i]));
#endif
            block[TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD + i].r32 = (packet[i]);
        }
    }

    // Pad if too small.
    if (copy_length < ETHERNET_FRAME_MIN)
    {
        copy_length = ETHERNET_FRAME_MIN;

        num_words = DIVIDE_RND_UP(copy_length, sizeof(uint32_t));
        for (; i < num_words; i++)
        {
            // Pad remaining with 0's
            block[TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD + i].r32 = 0;
        }
    }

    control.bits.payload_length = copy_length;

    block[TX_PORT_OUT_ALL_CONTROL_WORD].r32 = control.r32;

    return copy_length;
}

static uint32_t inline Network_TX_initAdditionalBlock(RegTX_PORTOut_t *block, int32_t next_block, uint32_t length, uint32_t *packet, bool big_endian)
{
    int i;
    network_control_t control;

    control.r32 = 0;
    control.bits.first = 0;
    control.bits.next_block = next_block;

    if (length > ADDITIONAL_FRAME_MAX)
    {
        length = ADDITIONAL_FRAME_MAX;
        control.bits.payload_length = ADDITIONAL_FRAME_MAX;
        control.bits.not_last = 1;
    }
    else
    {
        // Last
        control.bits.payload_length = length;
        control.bits.not_last = 0;
    }

    // block[1] = uninitialized;

    // Copy payload data.
    int num_words = DIVIDE_RND_UP(length, sizeof(uint32_t));
    for (i = 0; i < num_words; i++)
    {
        if (big_endian)
        {
            block[TX_PORT_OUT_ALL_ADDITIONAL_PAYLOAD_WORD + i].r32 = be32toh(packet[i]);
        }
        else
        {
            block[TX_PORT_OUT_ALL_ADDITIONAL_PAYLOAD_WORD + i].r32 = (packet[i]);
        }
    }

    block[TX_PORT_OUT_ALL_CONTROL_WORD].r32 = control.r32;

    return control.bits.payload_length;
}

static inline bool Network_TX_transmitPacket_internal(uint8_t *packet, uint32_t length, bool big_endian, NetworkPort_t *port)
{
    if (!length)
    {
        return false;
    }

    uint32_t *packet_32 = (uint32_t *)packet;
    uint32_t consumed = 0;
    uint32_t blocks = Network_TX_numBlocksNeeded(length);
    int total_blocks = blocks;

    // First block
    int32_t tail;
    int32_t first = tail = Network_TX_allocateBlock(port);
    if (first < 0)
    {
        // Error
        return false;
    }
    int32_t next_block = -1;
    if (blocks > 1)
    {
        next_block = Network_TX_allocateBlock(port);
        if (next_block < 0)
        {
            // TODO: Cleanup allocated blocks.
            return false;
        }
    }
    RegTX_PORTOut_t *block = (RegTX_PORTOut_t *)&port->tx_port->Out[TX_PORT_OUT_ALL_BLOCK_WORDS * first];

    consumed += Network_TX_initFirstBlock(block, length, blocks, next_block, &packet_32[consumed / 4], big_endian);
    blocks -= 1;
    while (blocks--)
    {

        block = (RegTX_PORTOut_t *)&port->tx_port->Out[TX_PORT_OUT_ALL_BLOCK_WORDS * next_block];
        if (blocks)
        {
            next_block = Network_TX_allocateBlock(port);
            consumed += Network_TX_initAdditionalBlock(block, next_block, length - consumed, &packet_32[consumed / 4], big_endian);
        }
        else
        {
            Network_TX_initAdditionalBlock(block, 0, length - consumed, &packet_32[consumed / 4], big_endian);
        }

        tail = next_block;
    }

    RegAPETxToNetDoorbell_t doorbell;
    doorbell.r32 = 0;
    doorbell.bits.Head = first;
    doorbell.bits.Tail = tail;
    doorbell.bits.Length = total_blocks;

    *((RegAPETxToNetDoorbell_t *)port->tx_doorbell) = doorbell;

    // Packet Transmitted.
    ++port->shm_channel->NcsiChannelNetworkTx.r32;

    return true;
}

bool Network_TX_transmitBePacket(uint8_t *packet, uint32_t length, NetworkPort_t *port)
{
    return Network_TX_transmitPacket_internal(packet, length, true, port);
}

bool Network_TX_transmitLePacket(uint8_t *packet, uint32_t length, NetworkPort_t *port)
{
    return Network_TX_transmitPacket_internal(packet, length, false, port);
}

static uint32_t inline Network_TX_initFirstPassthroughBlock(RegTX_PORTOut_t *block, uint32_t length, int32_t blocks, int32_t next_block)
{
    network_control_t control;
    int copy_length;
    int i;

    control.r32 = 0;
    control.bits.next_block = next_block >= 0 ? next_block : 0;
    control.bits.first = 1;

    if (length > FIRST_FRAME_MAX)
    {
        copy_length = FIRST_FRAME_MAX;
        control.bits.not_last = 1;
    }
    else
    {
        // Last.
        copy_length = length;
        control.bits.not_last = 0;
    }

    // block[1] = uninitialized;
    block[2].r32 = 0;
    block[TX_PORT_OUT_ALL_FRAME_LEN_WORD].r32 = length;
    block[4].r32 = 0;
    block[5].r32 = 0;
    block[6].r32 = 0;
    block[7].r32 = 0;
    block[8].r32 = 0;
    block[TX_PORT_OUT_ALL_NUM_BLOCKS_WORD].r32 = blocks;
    // block[10] = uninitialized;
    // block[11] = uninitialized;

    // Copy Payload Data.
    int num_words = DIVIDE_RND_UP(copy_length, sizeof(uint32_t));
    for (i = 0; i < num_words; i++)
    {
        block[TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD + i].r32 = APE_PERI.BmcToNcReadBuffer.r32;
    }

    // Pad if too small.
    if (copy_length < ETHERNET_FRAME_MIN)
    {
        copy_length = ETHERNET_FRAME_MIN;

        num_words = DIVIDE_RND_UP(copy_length, sizeof(uint32_t));
        for (; i < num_words; i++)
        {
            // Pad remaining with 0's
            block[TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD + i].r32 = 0;
        }
    }

    control.bits.payload_length = copy_length;

    block[TX_PORT_OUT_ALL_CONTROL_WORD].r32 = control.r32;

    return copy_length;
}

static uint32_t inline Network_TX_initAdditionalPassthroughBlock(RegTX_PORTOut_t *block, int32_t next_block, uint32_t length)
{
    int i;
    network_control_t control;

    control.r32 = 0;
    control.bits.first = 0;
    control.bits.next_block = next_block;

    if (length > ADDITIONAL_FRAME_MAX)
    {
        length = ADDITIONAL_FRAME_MAX;
        control.bits.payload_length = ADDITIONAL_FRAME_MAX;
        control.bits.not_last = 1;
    }
    else
    {
        // Last
        control.bits.payload_length = length;
        control.bits.not_last = 0;
    }

    // block[1] = uninitialized;

    // Copy payload data.
    int num_words = DIVIDE_RND_UP(length, sizeof(uint32_t));
    for (i = 0; i < num_words; i++)
    {
        block[TX_PORT_OUT_ALL_ADDITIONAL_PAYLOAD_WORD + i].r32 = APE_PERI.BmcToNcReadBuffer.r32;
    }

    block[TX_PORT_OUT_ALL_CONTROL_WORD].r32 = control.r32;

    return control.bits.payload_length;
}

static void drainPassthroughBytes(uint32_t bytes)
{
    printf("Dropping %u bytes\n", bytes);
    // Drain any passthrough bytes to ensure that the NCSI input buffers are not locked up.
    int num_words = DIVIDE_RND_UP(bytes, sizeof(uint32_t)) + 1; // +1 for FCS word.
    for (int i = 0; i < num_words; i++)
    {
        uint32_t word = APE_PERI.BmcToNcReadBuffer.r32;
        (void)word;
    }
}

bool Network_TX_transmitPassthroughPacket(uint32_t length, NetworkPort_t *port)
{
    if (!length)
    {
        return false;
    }
    // Drop the FCS word. It will be generated by hardware.
    length -= 4;

    int32_t tail;
    int32_t first = tail = Network_TX_allocateBlock(port);
    if (first < 0)
    {
        // Unable to allocate block.
        drainPassthroughBytes(length);
        return false;
    }
    int32_t next_block = -1;
    uint32_t blocks = Network_TX_numBlocksNeeded(length);
    int total_blocks = blocks;

    if (blocks > 1)
    {
        next_block = Network_TX_allocateBlock(port);
        if (next_block < 0)
        {
            drainPassthroughBytes(length);
            return false;
        }
    }
    RegTX_PORTOut_t *block = (RegTX_PORTOut_t *)&port->tx_port->Out[TX_PORT_OUT_ALL_BLOCK_WORDS * first];

    length -= Network_TX_initFirstPassthroughBlock(block, length, blocks, next_block);
    blocks -= 1;

    while (blocks--)
    {
        block = (RegTX_PORTOut_t *)&port->tx_port->Out[TX_PORT_OUT_ALL_BLOCK_WORDS * next_block];
        if (blocks)
        {
            next_block = Network_TX_allocateBlock(port);
            if (next_block < 0)
            {
                drainPassthroughBytes(length);
                return false;
            }
            length -= Network_TX_initAdditionalPassthroughBlock(block, next_block, length);
        }
        else
        {
            Network_TX_initAdditionalPassthroughBlock(block, 0, length);
        }

        tail = next_block;
    }

    RegAPETxToNetDoorbell_t doorbell;
    doorbell.r32 = 0;
    doorbell.bits.Head = first;
    doorbell.bits.Tail = tail;
    doorbell.bits.Length = total_blocks;

    *((RegAPETxToNetDoorbell_t *)port->tx_doorbell) = doorbell;

    // Read last RX word (FCS) to clear the buffer
    uint32_t data = APE_PERI.BmcToNcReadBuffer.r32;
    (void)data;

    // Packet transmitted.
    ++port->shm_channel->NcsiChannelNetworkTx.r32;

    return true;
}
