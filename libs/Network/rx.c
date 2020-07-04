////////////////////////////////////////////////////////////////////////////////
///
/// @file       rx.c
///
/// @project
///
/// @brief      Network reception routines
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
#include <APE_APE_PERI.h>
#include <APE_RX_PORT0.h>
#include <Ethernet.h>
#include <Network.h>
#include <types.h>

#ifdef CXX_SIMULATOR
#include <stdio.h>
#else
#include <printf.h>
#endif

bool Network_RxLePatcket(uint32_t *buffer, uint32_t *bytes, NetworkPort_t *port)
{
    RegAPERxbufoffset_t rxbuf;
    rxbuf = *((RegAPERxbufoffset_t *)port->rx_offset);
    if ((int)rxbuf.bits.Valid)
    {
        uint32_t rx_bytes = 0;
        network_control_t control;
        int count = rxbuf.bits.Count;
        // int tailid = rxbuf.bits.Tail;
        int blockid = rxbuf.bits.Head;
        // printf("Valid packet at offset %x\n", blockid);
        uint32_t buffer_pos = 0;

        do
        {
            // printf("Block at %x\n", blockid);
            RegRX_PORTIn_t *block = (RegRX_PORTIn_t *)&port->rx_port->In[RX_PORT_IN_ALL_BLOCK_WORDS * blockid];
            // printf("Control %x\n", (uint32_t)block[0].r32);
            control.r32 = block[0].r32;
            // printf(" Payload Len %d\n", control.bits.payload_length);
            // printf(" Next Block %d\n", control.bits.next_block);
            // printf(" First %d\n", control.bits.first);
            // printf(" Not Last %d\n", control.bits.not_last);
            int32_t words = DIVIDE_RND_UP(control.bits.payload_length, sizeof(uint32_t));
            rx_bytes += control.bits.payload_length;
            int32_t offset;
            if (control.bits.first)
            {
                offset = RX_PORT_IN_ALL_FIRST_PAYLOAD_WORD;
            }
            else
            {
                offset = RX_PORT_IN_ALL_ADDITIONAL_PAYLOAD_WORD;
            }
            // printf("Using offset %d\n", offset);
            for (int i = 0; i < words; i++)
            {
                uint32_t data = block[i + offset].r32;
                buffer[buffer_pos++] = data;
                // printf(" word %d: 0x%08X\n", i, data);
            }

            blockid = control.bits.next_block;
            count--;
        } while (count);

        // Transmit to NC
        // disableNCSIHandling();
        // enableNCSIHandling();

        RegAPERxPoolRetire_t retire;
        retire.r32 = 0;
        retire.bits.Head = rxbuf.bits.Head;
        retire.bits.Tail = rxbuf.bits.Tail;
        retire.bits.Count = rxbuf.bits.Count;
        retire.bits.Retire = 1;
        *((RegAPERxPoolRetire_t *)port->rx_retire) = retire;

        rxbuf.bits.Finished = 1;
        *((RegAPERxbufoffset_t *)port->rx_offset) = rxbuf;

        *bytes = rx_bytes;

        return true;
    }
    else
    {
        return false;
    }
}

bool Network_PassthroughRxPatcket(NetworkPort_t *port)
{
    RegAPERxbufoffset_t rxbuf;
    rxbuf = *((RegAPERxbufoffset_t *)port->rx_offset);
    if ((int)rxbuf.bits.Valid)
    {
#if CXX_SIMULATOR
        rxbuf.print();
#endif

        VOLATILE RX_PORT_t *rx_port = port->rx_port;
        network_control_t control;
        int count = rxbuf.bits.Count;
        // int tailid = rxbuf.bits.Tail;
        int blockid = rxbuf.bits.Head;

        RegAPERxPoolRetire_t retire;
        retire.r32 = (1 << 24);
        retire.bits.Count = 1;

        while (count--)
        {
            // printf("Block at %x\n", blockid);
            RegRX_PORTIn_t *block = (RegRX_PORTIn_t *)&rx_port->In[RX_PORT_IN_ALL_BLOCK_WORDS * blockid];
            // printf("Control %x\n", (uint32_t)block[0].r32);
            control.r32 = block[0].r32;
            // printf(" Payload Len %d\n", control.bits.payload_length);
            // printf(" Next Block %d\n", control.bits.next_block);
            // printf(" First %d\n", control.bits.first);
            // printf(" Not Last %d\n", control.bits.not_last);
#if CXX_SIMULATOR
            printf("%d bytes in block.\n", control.bits.payload_length);
#endif
            int i;
            int32_t offset;
            int32_t words = DIVIDE_RND_UP(control.bits.payload_length, sizeof(uint32_t));

            if (control.bits.first)
            {
                offset = RX_PORT_IN_ALL_FIRST_PAYLOAD_WORD;
            }
            else
            {
                offset = RX_PORT_IN_ALL_ADDITIONAL_PAYLOAD_WORD;
            }

            if (!control.bits.not_last)
            {
                // Ignore last word - drop the FCS
                words--;
            }

            if (control.bits.not_last)
            {
                for (i = 0; i < words; i++)
                {
                    while (0 == APE_PERI.BmcToNcTxStatus.bits.InFifo)
                        ;
                    APE_PERI.BmcToNcTxBuffer.r32 = block[i + offset].r32;
                }
            }
            else
            {
                RegAPE_PERIBmcToNcTxControl_t ctrl;
                ctrl.r32 = 0;
                ctrl.bits.LastByteCount = control.bits.payload_length % sizeof(uint32_t);
                APE_PERI.BmcToNcTxControl.r32 = ctrl.r32;

                for (i = 0; i < words - 1; i++)
                {
                    while (0 == APE_PERI.BmcToNcTxStatus.bits.InFifo)
                        ;
                    APE_PERI.BmcToNcTxBuffer.r32 = block[i + offset].r32;
                }

                // Last word to send.
                while (0 == APE_PERI.BmcToNcTxStatus.bits.InFifo)
                    ;
                if (0 == control.bits.payload_length % sizeof(uint32_t))
                {
                    // Last word
                    APE_PERI.BmcToNcTxBuffer.r32 = block[i + offset].r32;
                    APE_PERI.BmcToNcTxBufferLast.r32 = 0;
                }
                else
                {
                    APE_PERI.BmcToNcTxBufferLast.r32 = block[i + offset].r32;
                }

                // Ignore last word - drop the FCS.
                // data = block[i + offset + 1].r32;
                // (void)data;
            }

            // Retire this block.
            retire.bits.Head = blockid;
            retire.bits.Tail = blockid;
            *((RegAPERxPoolRetire_t *)port->rx_retire) = retire;

            blockid = control.bits.next_block;
        }

        // Mark the frame as read.
        rxbuf.bits.Finished = 1;
        *((RegAPERxbufoffset_t *)port->rx_offset) = rxbuf;

        // Packet recieved.
        ++port->shm_channel->NcsiChannelCtrlstatAllRx.r32;

        return true;
    }
    else
    {
        return false;
    }
}
