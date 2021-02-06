////////////////////////////////////////////////////////////////////////////////
///
/// @file       decompress.c
///
/// @project
///
/// @brief      Decompression Routines
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

#include <Compress.h>
#include <stdio.h>

#define DICTIONARY_INIT_0x20    (0x20)
#define DICTIONARY_INIT_0x00    (0x00)
#define DICTIONARY_INIT_INDEX   (2014)
#define DICTIONARY_SIZE         (2048)

#define LITERAL_TYPE    (1)
#define REFERENCE_TYPE  (0)

static struct
{
    uint8_t dictionary[DICTIONARY_SIZE];
    uint32_t cursor;
    const uint8_t *inBuffer;
    int32_t inBytes;

    uint8_t *outBuffer;
    int32_t outRemaining;
    int32_t outSent;
} g_DecompressorState;

static void state_init(const uint8_t *inBuffer, int32_t inBytes)
{
    g_DecompressorState.cursor = DICTIONARY_INIT_INDEX;
    uint32_t i = 0;
    for (; i < g_DecompressorState.cursor; i++)
    {
        g_DecompressorState.dictionary[i] = DICTIONARY_INIT_0x20;
    }

    for (; i < DICTIONARY_SIZE; i++)
    {
        g_DecompressorState.dictionary[i] = DICTIONARY_INIT_0x00;
    }

    g_DecompressorState.inBuffer = inBuffer;
    g_DecompressorState.inBytes = inBytes;
}

static void state_insert(uint8_t byte)
{
    g_DecompressorState.dictionary[g_DecompressorState.cursor] = byte;
    // Increment and wrap.
    g_DecompressorState.cursor =
        (g_DecompressorState.cursor + 1) % DICTIONARY_SIZE;
}

static uint8_t state_get_dictionary(uint16_t offset)
{
    offset = offset % DICTIONARY_SIZE;
    return g_DecompressorState.dictionary[offset];
}

static uint8_t state_get_byte(void)
{
    // uint8_t bytesLeft = g_DecompressorState.inBytes;
    uint8_t byte = 0;
    // if(bytesLeft > 0)
    // {
    byte = *g_DecompressorState.inBuffer;
    g_DecompressorState.inBuffer++;
    g_DecompressorState.inBytes--;
    // }

    return byte;
}

int32_t state_bytes_left(void)
{
    return g_DecompressorState.inBytes;
}

int32_t decompress(uint8_t *outBuffer, int32_t outBytes,
                   const uint8_t *inBuffer, int32_t inBytes)
{
    int32_t actualSize = 0;
    state_init(inBuffer, inBytes);

    while (state_bytes_left() > 0)
    {
        uint8_t control = state_get_byte();
        for (int i = 0; i < 8; i++)
        {
            if (actualSize >= outBytes || !state_bytes_left())
            {
                // We have no bytes left, or we've filled up the output buffer
                break;
            }

            if ((control & (1 << i)) == REFERENCE_TYPE)
            {
                // Read in two reference bytes
                uint8_t B0 = state_get_byte();
                uint8_t B1 = state_get_byte();

                uint16_t offset = (((uint16_t)B1 & 0xE0u) << 3u) | B0;
                uint16_t length = (B1 & 0x1Fu) + 3u;

                while (length && actualSize < outBytes)
                {
                    uint8_t literal = state_get_dictionary(offset);
                    state_insert(literal);

                    offset++;
                    length--;
                    outBuffer[actualSize++] = literal;
                }
            }
            else /* LITERAL_TYPE */
            {
                uint8_t literal = state_get_byte();
                ;
                state_insert(literal);

                // Output
                outBuffer[actualSize++] = literal;
            }
        }
    }

    return actualSize;
}
