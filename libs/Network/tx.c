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


#include <Network.h>
#include <Ethernet.h>
#include <APE_APE.h>
#include <APE_TX_PORT.h>

#ifdef CXX_SIMULATOR
#include <stdio.h>
#include <endian.h>
#else
/* ARM */
static inline uint32_t be32toh(uint32_t be32)
{
    uint32_t le32 = ((be32 & 0xFF000000) >> 24) |
                    ((be32 & 0x00FF0000) >> 8) |
                    ((be32 & 0x0000FF00) << 8) |
                    ((be32 & 0x000000FF) << 24);

    return le32;
}
#endif

uint32_t Network_TX_numBlocksNeeded(uint32_t frame_size)
{
    static const uint32_t first_size = 20 * sizeof(uint32_t);
    static const uint32_t remaining_size = 30 * sizeof(uint32_t);
    uint32_t blocks = 1;
    // Block size is 128 bytes, first one has 12 words used, so 20 words available.
    if(frame_size > first_size)
    {
        frame_size -= 20 * sizeof(uint32_t);

        // Remaining blocks can hold 30 words;
        blocks += ((frame_size + remaining_size - 1) / remaining_size);
    }

#ifdef CXX_SIMULATOR
    printf("%d blocks needed for packet\n", blocks);
#endif
    return blocks;
}



int32_t __attribute__((noinline)) Network_TX_allocateBlock(void)
{
    int32_t block = -1;

    // Wait for allocator state machine to finish.
    // while(APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_PROCESSING == APE.TxToNetBufferAllocator0.bits.State);

    // Set the alloc bit.
    RegAPETxToNetBufferAllocator0_t alloc;
    alloc.r32 = 0;
    alloc.bits.RequestAllocation = 1;
    APE.TxToNetBufferAllocator0 = alloc;

    // Wait for state machine to finish
    RegAPETxToNetBufferAllocator0_t status;
    do {
        status = APE.TxToNetBufferAllocator0;
    } while(APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_PROCESSING == status.bits.State);

    if(APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_ALLOCATION_OK != status.bits.State)
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

uint32_t __attribute__((noinline)) Network_TX_initFirstBlockBe(RegTX_PORTOut_t* block, uint32_t length, int32_t blocks, int32_t next_block, uint32_t* packet)
{
    int copy_length;
    int i;
    union {
        uint32_t r32;
        struct {
            uint32_t payload_length:7;
            uint32_t next_block:23;
            uint32_t first:1;
            uint32_t not_last:1;
        } bits;
    } control;

    control.r32 = 0;
    control.bits.next_block = next_block >= 0 ? next_block : 0;
    control.bits.first = 1;

    if(length > ((TX_PORT_OUT_ALL_BLOCK_WORDS - TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD)*4))
    {
        copy_length = (TX_PORT_OUT_ALL_BLOCK_WORDS - TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD)*4;
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
    block[3].r32 = 0;
    block[4].r32 = 0;
    block[5].r32 = 0;
    block[6].r32 = 0;
    block[7].r32 = 0;
    block[8].r32 = 0;
    block[9].r32 = 0;
    // block[10] = uninitialized;
    // block[11] = uninitialized;
    block[TX_PORT_OUT_ALL_FRAME_LEN_WORD].r32 = length;
    block[TX_PORT_OUT_ALL_NUM_BLOCKS_WORD].r32 = blocks;

    // Copy Payload Data.
    int num_words = (copy_length + sizeof(uint32_t) - 1)/sizeof(uint32_t);
    for(i = 0; i < num_words; i++)
    {
        block[TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD + i].r32 = be32toh(packet[i]);
    }

    // Pad if too small.
    if(copy_length < ETHERNET_FRAME_MIN)
    {
        copy_length = ETHERNET_FRAME_MIN;
        length = ETHERNET_FRAME_MIN;
    }
    num_words = (copy_length + sizeof(uint32_t) - 1)/sizeof(uint32_t);
    for(; i < num_words; i++)
    {
        // Pad remaining with 0's
        block[TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD + i].r32 = 0;
    }

    control.bits.payload_length = copy_length;

    block[TX_PORT_OUT_ALL_CONTROL_WORD].r32 = control.r32;

    length -= control.bits.payload_length;

    return copy_length;
}


uint32_t __attribute__((noinline)) Network_TX_initAdditionalBlockBe(RegTX_PORTOut_t* block, int32_t next_block, uint32_t length, uint32_t* packet)
{
    int i;   
    union {
        uint32_t r32;
        struct {
            uint32_t payload_length:7;
            uint32_t next_block:23;
            uint32_t first:1;
            uint32_t not_last:1;
        } bits;
    } control;

    control.r32 = 0;
    control.bits.first = 0;
    control.bits.next_block = next_block;

    if(length > ((TX_PORT_OUT_ALL_BLOCK_WORDS - TX_PORT_OUT_ALL_ADDITIONAL_PAYLOAD_WORD)*4))
    {
        control.bits.payload_length = (TX_PORT_OUT_ALL_BLOCK_WORDS - TX_PORT_OUT_ALL_ADDITIONAL_PAYLOAD_WORD)*4;
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
    int num_words = (length + sizeof(uint32_t) - 1)/sizeof(uint32_t);
    for(i = 0; i < num_words; i++)
    {
        block[TX_PORT_OUT_ALL_ADDITIONAL_PAYLOAD_WORD + i].r32 = be32toh(packet[i]);

    }

    block[TX_PORT_OUT_ALL_CONTROL_WORD].r32 = control.r32;

    length -= control.bits.payload_length;

    return length;
}

void Network_TX_transmitBePacket(uint8_t* packet, uint32_t length)
{
    uint32_t* packet_32 = (uint32_t*)packet;
    uint32_t consumed = 0;
    uint32_t blocks = Network_TX_numBlocksNeeded(length);
    int total_blocks = blocks;;

    // First block
    int32_t first = Network_TX_allocateBlock();
    int32_t next_block = -1;
    if(blocks > 1)
    {
        next_block = Network_TX_allocateBlock();
    }
    RegTX_PORTOut_t* block = (RegTX_PORTOut_t*)&TX_PORT.Out[TX_PORT_OUT_ALL_BLOCK_WORDS * first];

    consumed += Network_TX_initFirstBlockBe(block, length, blocks, next_block, &packet_32[consumed/4]);
    blocks -= 1;
    while(blocks)
    {

        block = (RegTX_PORTOut_t*)&TX_PORT.Out[TX_PORT_OUT_ALL_BLOCK_WORDS * next_block];
        blocks--;
        if(blocks)
        {
            next_block = Network_TX_allocateBlock();
            consumed += Network_TX_initAdditionalBlockBe(block, next_block, length-consumed, &packet_32[consumed/4]);
        }
        else
        {
            Network_TX_initAdditionalBlockBe(block, 0, length - consumed, &packet_32[consumed/4]);
        }
    }

    int tail = next_block;
    if(next_block == -1)
    {
        tail = first;
    }

    RegAPETxToNetDoorbellFunc0_t doorbell;
    doorbell.r32 = 0;
    doorbell.bits.Head = first;
    doorbell.bits.Tail = tail;
    doorbell.bits.Length = total_blocks;

    APE.TxToNetDoorbellFunc0 = doorbell;
}
