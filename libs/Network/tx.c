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

#include <APE_APE.h>
#include <APE_TX_PORT.h>
#include <Ethernet.h>
#include <Network.h>
#include <stdbool.h>
#include <types.h>

#ifdef CXX_SIMULATOR
#include <endian.h>
#include <stdio.h>
#else
/* ARM */
static inline uint32_t be32toh(uint32_t be32)
{
    uint32_t he32 = ((be32 & 0xFF000000) >> 24) |
                    ((be32 & 0x00FF0000) >> 8) |
                    ((be32 & 0x0000FF00) << 8) |
                    ((be32 & 0x000000FF) << 24);

    return he32;
}
#endif

#define FIRST_FRAME_MAX         ((TX_PORT_OUT_ALL_BLOCK_WORDS - TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD) * sizeof(uint32_t))
#define ADDITIONAL_FRAME_MAX    ((TX_PORT_OUT_ALL_BLOCK_WORDS - TX_PORT_OUT_ALL_ADDITIONAL_PAYLOAD_WORD) * sizeof(uint32_t))

typedef union {
    uint32_t r32;
    struct
    {
        uint32_t payload_length:7;
        uint32_t next_block:23;
        uint32_t first:1;
        uint32_t not_last:1;
    } bits;
} control_t;

uint32_t Network_TX_numBlocksNeeded(uint32_t frame_size)
{
    uint32_t blocks = 1;

    if (frame_size > FIRST_FRAME_MAX)
    {
        frame_size -= FIRST_FRAME_MAX;

        blocks += DIVIDE_RND_UP(frame_size, ADDITIONAL_FRAME_MAX);
    }

#ifdef CXX_SIMULATOR
    printf("%d blocks needed for packet with frame size %d\n", blocks,
           frame_size);
#endif
    return blocks;
}

int32_t __attribute__((noinline)) Network_TX_allocateBlock(void)
{
    int32_t block;

    // Set the alloc bit.
    RegAPETxToNetBufferAllocator0_t alloc;
    alloc.r32 = 0;
    alloc.bits.RequestAllocation = 1;
    APE.TxToNetBufferAllocator0 = alloc;

    // Wait for state machine to finish
    RegAPETxToNetBufferAllocator0_t status;
    do
    {
        status = APE.TxToNetBufferAllocator0;
    } while (APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_PROCESSING == status.bits.State);

    if (APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_ALLOCATION_OK != status.bits.State)
    {
        block = -1;
#if CXX_SIMULATOR
        printf("Error: Failed to allocate TX block.\n");
#endif
    }
    else
    {
        block = status.bits.Index;
#if CXX_SIMULATOR
        printf("Allocated TX block %d\n", block);
#endif
    }

    return block;
}

static uint32_t inline Network_TX_initFirstBlock(RegTX_PORTOut_t *block,
                                                 uint32_t length,
                                                 int32_t blocks,
                                                 int32_t next_block,
                                                 uint32_t *packet,
                                                 bool big_endian)
{
    control_t control;
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
#if CXX_SIMULATOR
            printf("1st[%d] = 0x%08X\n", i, be32toh(packet[i]));
#endif
            block[TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD + i].r32 = be32toh(packet[i]);
        }
        else
        {
#if CXX_SIMULATOR
            printf("1LE[%d] = 0x%08X\n", i, (packet[i]));
#endif
            block[TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD + i].r32 = (packet[i]);
        }
    }

    length -= control.bits.payload_length;

    // Pad if too small.
    if (copy_length < ETHERNET_FRAME_MIN)
    {
        copy_length = ETHERNET_FRAME_MIN;
        length = ETHERNET_FRAME_MIN;

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

static uint32_t inline Network_TX_initAdditionalBlock(RegTX_PORTOut_t *block,
                                                      int32_t next_block,
                                                      uint32_t length,
                                                      uint32_t *packet,
                                                      bool big_endian)
{
    int i;
    control_t control;

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

    length -= control.bits.payload_length;

    return control.bits.payload_length;
}

static inline void Network_TX_transmitPacket_internal(uint8_t *packet,
                                                      uint32_t length,
                                                      bool big_endian)
{
    if (!length)
    {
        return;
    }

    uint32_t *packet_32 = (uint32_t *)packet;
    uint32_t consumed = 0;
    uint32_t blocks = Network_TX_numBlocksNeeded(length);
    int total_blocks = blocks;
    ;

    // First block
    int32_t tail;
    int32_t first = tail = Network_TX_allocateBlock();
    if (first <= 0)
    {
        // Error
        return;
    }
    int32_t next_block = -1;
    if (blocks > 1)
    {
        next_block = Network_TX_allocateBlock();
    }
    RegTX_PORTOut_t *block = (RegTX_PORTOut_t *)&TX_PORT.Out[TX_PORT_OUT_ALL_BLOCK_WORDS * first];

    consumed += Network_TX_initFirstBlock(block, length, blocks, next_block,
                                          &packet_32[consumed / 4], big_endian);
    blocks -= 1;
    while (blocks--)
    {

        block = (RegTX_PORTOut_t *)&TX_PORT
                    .Out[TX_PORT_OUT_ALL_BLOCK_WORDS * next_block];
        if (blocks)
        {
            next_block = Network_TX_allocateBlock();
            consumed += Network_TX_initAdditionalBlock(
                block, next_block, length - consumed, &packet_32[consumed / 4],
                big_endian);
        }
        else
        {
            Network_TX_initAdditionalBlock(block, 0, length - consumed,
                                           &packet_32[consumed / 4],
                                           big_endian);
        }

        tail = next_block;
    }

    RegAPETxToNetDoorbellFunc0_t doorbell;
    doorbell.r32 = 0;
    doorbell.bits.Head = first;
    doorbell.bits.Tail = tail;
    doorbell.bits.Length = total_blocks;

    APE.TxToNetDoorbellFunc0 = doorbell;
}

void Network_TX_transmitBePacket(uint8_t *packet, uint32_t length)
{
    Network_TX_transmitPacket_internal(packet, length, true);
}

void Network_TX_transmitLePacket(uint8_t *packet, uint32_t length)
{
    Network_TX_transmitPacket_internal(packet, length, false);
}

static uint32_t inline Network_TX_initFirstPassthroughBlock(
    RegTX_PORTOut_t *block, uint32_t length, int32_t blocks, int32_t next_block)
{
    control_t control;
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

    length -= control.bits.payload_length;

    // Pad if too small.
    if (copy_length < ETHERNET_FRAME_MIN)
    {
        copy_length = ETHERNET_FRAME_MIN;
        length = ETHERNET_FRAME_MIN;

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

static uint32_t inline Network_TX_initAdditionalPassthroughBlock(
    RegTX_PORTOut_t *block, int32_t next_block, uint32_t length)
{
    int i;
    control_t control;

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

    length -= control.bits.payload_length;

    return control.bits.payload_length;
}

void Network_TX_transmitPassthroughPacket(uint32_t length)
{
    if (!length)
    {
        return;
    }

    // Drop the FCS word. It will be generated by hardware.
    length -= 4;

    int32_t tail;
    int32_t first = tail = Network_TX_allocateBlock();
    int32_t next_block = -1;
    uint32_t blocks = Network_TX_numBlocksNeeded(length);
    int total_blocks = blocks;
    ;

    if (blocks > 1)
    {
        next_block = Network_TX_allocateBlock();
    }
    RegTX_PORTOut_t *block = (RegTX_PORTOut_t *)&TX_PORT.Out[TX_PORT_OUT_ALL_BLOCK_WORDS * first];

    length -= Network_TX_initFirstPassthroughBlock(block, length, blocks, next_block);
    blocks -= 1;
    while (blocks--)
    {

        block = (RegTX_PORTOut_t *)&TX_PORT.Out[TX_PORT_OUT_ALL_BLOCK_WORDS * next_block];
        if (blocks)
        {
            next_block = Network_TX_allocateBlock();
            length -= Network_TX_initAdditionalPassthroughBlock(
                block, next_block, length);
        }
        else
        {
            Network_TX_initAdditionalPassthroughBlock(block, 0, length);
        }

        tail = next_block;
    }

    RegAPETxToNetDoorbellFunc0_t doorbell;
    doorbell.r32 = 0;
    doorbell.bits.Head = first;
    doorbell.bits.Tail = tail;
    doorbell.bits.Length = total_blocks;

    APE.TxToNetDoorbellFunc0 = doorbell;

    // Read last RX word (FCS) to clear the buffer
    uint32_t data = APE_PERI.BmcToNcReadBuffer.r32;
    (void)data;
}
