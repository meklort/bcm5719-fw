////////////////////////////////////////////////////////////////////////////////
///
/// @file       compress.c
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
#include <assert.h>

// Original implementation from
// https://github.com/hlandau/ortega/blob/master/apestamp.c

#define N 2048
#define F 34
#define THRESHOLD 2
#define NIL N

typedef struct
{
    uint8_t dict[N + F - 1];

    // Describes longest match. Set by _InsertNode.
    int matchPos, matchLen;
    // Left and right children and parents. Makes up a binary search tree.
    int lson[N + 1], rson[N + 257], parent[N + 1];
} compressor_state;

// Inserts a string of length F, text_buf[r..r+F-1] into one of the trees
// (dict[r]'th tree) and returns the longest-match position and length via the
// state variables matchPosition and matchLength. If matchLength == F, then
// removes the old node in favour of the new one, because the old one will be
// deleted sooner. Note that r plays a double role, as the tree node index and
// the position in the buffer.
static void _InsertNode(compressor_state *st, int r)
{
    int p, cmp;
    uint8_t *key;

    uint8_t *dict = st->dict;
    int *lson = st->lson, *rson = st->rson, *parent = st->parent;

    cmp = 1;
    key = &dict[r];
    p = N + 1 + key[0];
    rson[r] = lson[r] = NIL;
    st->matchLen = 0;
    for (;;)
    {
        if (cmp >= 0)
        {
            if (rson[p] != NIL)
            {
                p = rson[p];
            }
            else
            {
                rson[p] = r;
                parent[r] = p;
                return;
            }
        }
        else
        {
            if (lson[p] != NIL)
            {
                p = lson[p];
            }
            else
            {
                lson[p] = r;
                parent[r] = p;
                return;
            }
        }

        // Compare.
        int i;
        for (i = 1; i < F; ++i)
        {
            cmp = key[i] - dict[p + i];
            if (cmp)
            {
                break;
            }
        }

        if (i > st->matchLen)
        {
            // We have found a longer match.
            st->matchPos = p;
            st->matchLen = i;
            if (i >= F)
            {
                // Maximum match length, stop looking.
                break;
            }
        }
    }

    parent[r] = parent[p];
    lson[r] = lson[p];
    rson[r] = rson[p];
    parent[lson[p]] = r;
    parent[rson[p]] = r;
    if (rson[parent[p]] == p)
    {
        rson[parent[p]] = r;
    }
    else
    {
        lson[parent[p]] = r;
    }
    parent[p] = NIL;
}

// Deletes node p from the tree.
static void _DeleteNode(compressor_state *st, int p)
{
    int q;

    int *lson = st->lson, *rson = st->rson, *parent = st->parent;

    if (parent[p] == NIL)
    {
        // Not in tree.
        return;
    }

    if (rson[p] == NIL)
    {
        q = lson[p];
    }
    else if (lson[p] == NIL)
    {
        q = rson[p];
    }
    else
    {
        {
            q = lson[p];
        }
        if (rson[q] != NIL)
        {
            do
            {
                q = rson[q];
            } while (rson[q] != NIL);

            rson[parent[q]] = lson[q];
            parent[lson[q]] = parent[q];
            lson[q] = lson[p];
            parent[lson[p]] = q;
        }

        rson[q] = rson[p];
        parent[rson[p]] = q;
    }

    parent[q] = parent[p];
    if (rson[parent[p]] == p)
    {
        rson[parent[p]] = q;
    }
    else
    {
        lson[parent[p]] = q;
    }
    parent[p] = NIL;
}

// int32_t decompress(uint8_t* outBuffer, int32_t outBytes,
//                    uint8_t* inBuffer,  int32_t inBytes)

// Compression routine adapted from original 1989 LZSS.C by Haruhiko Okumura.
// "Use, distribute, and modify this program freely."
int32_t compress(uint8_t *outBuffer, int32_t outBytes, const uint8_t *inBuffer,
                 int32_t inBytes)
{
    const uint8_t *inEnd = inBuffer + inBytes;
    uint32_t bytesWritten_ = 0;

    compressor_state st;

    if (!inBytes)
    {
        return -1;
    }

    // Initialize tree.
    for (int i = N + 1; i <= N + 256; ++i)
    {
        st.rson[i] = NIL;
    }
    for (int i = 0; i < N; ++i)
    {
        st.parent[i] = NIL;
    }

    int i, c, len, r = N - F, s = 0, lastMatchLen, codeBufPtr = 1;
    uint8_t codeBuf[17], mask = 1;
    codeBuf[0] = 0;

    // Clear the buffer.
    for (i = 0; i < r; ++i)
    {
        st.dict[i] = 0x20;
    }

    // Read F bytes into the last F bytes of the buffer.
    for (len = 0; len < F && inBuffer < inEnd; ++len)
    {
        st.dict[r + len] = *inBuffer++;
    }

    // Insert the F strings, each of which begins with one or more 'space'
    // characters. Note the order in which these strings are inserted. This way,
    // degenerate trees will be less likely to occur.
    for (i = 1; i <= F; ++i)
    {
        _InsertNode(&st, r - i);
    }

    // Finally, insert the whole string just read. matchLength and matchPosition
    // are set.
    _InsertNode(&st, r);

    do
    {
        // matchLen may be spuriously long near the end of text.
        if (st.matchLen >= len)
        {
            st.matchLen = len;
        }

        if (st.matchLen <= THRESHOLD)
        {
            // Not long enough match. Send one byte.
            st.matchLen = 1;
            codeBuf[0] |= mask;                 // "Send one byte" flag.
            codeBuf[codeBufPtr++] = st.dict[r]; // Send uncoded.
            // printf("  LIT 0x%02x\n", st.dict[r]);
        }
        else
        {
            // Send position and length pair. Note that matchLen > THRESHOLD.
            // printf("  REF off=%4u  len=%4u\n", st.matchPos, st.matchLen);
            // printf("    ");
            // for (uint32_t j=0; j<st.matchLen; ++j)
            //  printf("%02x ", st.dict[st.matchPos+j]);
            // printf("\n");
            codeBuf[codeBufPtr++] = (uint8_t)st.matchPos;
            assert(st.matchLen - (THRESHOLD + 1) < 0x20);
            codeBuf[codeBufPtr++] = (uint8_t)(((st.matchPos >> 3) & 0xE0) |
                                              (st.matchLen - (THRESHOLD + 1)));
        }

        mask <<= 1;
        if (!mask)
        {
            // Send at most eight units of code together.
            for (i = 0; i < codeBufPtr; ++i)
            {
                *outBuffer++ = codeBuf[i];
                outBytes--;
            }
            bytesWritten_ += codeBufPtr;
            codeBuf[0] = 0;
            codeBufPtr = mask = 1;
        }

        lastMatchLen = st.matchLen;
        for (i = 0; i < lastMatchLen && inBuffer < inEnd; ++i)
        {
            // Delete old strings and read new bytes.
            c = *inBuffer++;
            _DeleteNode(&st, s);
            st.dict[s] = c;
            // If the position is near the end of the buffer, extend the buffer
            // to make string comparison easier.
            if (s < F - 1)
            {
                st.dict[s + N] = c;
            }
            // Since this is a ring buffer, increment the position modulo N.
            s = (s + 1) % N;
            r = (r + 1) % N;
            // Register the string in dict[r..r+F-1].
            _InsertNode(&st, r);
        }

        while (i++ < lastMatchLen)
        {
            // After the end of text, no need to read, but buffer may not be
            // empty.
            _DeleteNode(&st, s);
            s = (s + 1) % N;
            r = (r + 1) % N;
            if (--len)
            {
                _InsertNode(&st, r);
            }
        }
    } while (len > 0);

    // Send remaining code.
    if (codeBufPtr > 1)
    {
        for (i = 0; i < codeBufPtr; ++i)
        {
            *outBuffer++ = codeBuf[i];
            outBytes--;
        }
        bytesWritten_ += codeBufPtr;
    }

    // *bytesRead = inBuffer - inStart;
    // *bytesWritten = bytesWritten_;

    return bytesWritten_;
}