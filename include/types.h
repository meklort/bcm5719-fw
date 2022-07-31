////////////////////////////////////////////////////////////////////////////////
///
/// @file       types.h
///
/// @project
///
/// @brief      Type and macro definitions
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018-2020, Evan Lojewski
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

#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

#ifdef CXX_SIMULATOR
#include <stdint.h>
#include <bcm5719-endian.h>
#elif defined(__arm__) || defined(__mips__)
typedef signed char     int8_t;
typedef unsigned char  uint8_t;

typedef signed short     int16_t;
typedef unsigned short  uint16_t;

typedef signed int     int32_t;
typedef unsigned int  uint32_t;

typedef long long unsigned int uint64_t;
typedef long long signed int int64_t;

typedef uint32_t size_t;

static inline uint32_t swap32(uint32_t val)
{
    uint32_t swapped = ((val & 0xFF000000) >> 24) | ((val & 0x00FF0000) >> 8) | ((val & 0x0000FF00) << 8) | ((val & 0x000000FF) << 24);

    return swapped;
}

static inline uint32_t be32toh(uint32_t be32)
{
    return swap32(be32);
}

static inline uint32_t le32toh(uint32_t le32)
{
    return le32;
}

static inline uint32_t htobe32(uint32_t be32)
{
    return swap32(be32);
}

static inline uint32_t htole32(uint32_t le32)
{
    return le32;
}

#else
#error Unknown target architechture
#endif

#define SECTION(__section__) __attribute__((section, __section__))

#define ARRAY_ELEMENTS(__array__) (sizeof(__array__) / sizeof(__array__[0]))

#define DIVIDE_RND_UP(__value__, __round__)     (((__value__) + (__round__) - 1) / (__round__))
#define DIVIDE_RND_DOWN(__value__, __round__)   ((__value__) / (__round__))

#define MIN(__x__, __y__)       ((__x__) < (__y__)) ? (__x__) : (__y__)
#define MAX(__x__, __y__)       ((__x__) > (__y__)) ? (__x__) : (__y__)

typedef union {
    uint64_t u64;

    struct
    {
        uint8_t pad[2];
        uint8_t u8[6];
    } oct;

    struct
    {
        uint32_t u32[2];
    } word;
} mac_t;


#define _STRINGIFY(__STR__)   #__STR__
#define STRINGIFY(__STR__)    _STRINGIFY(__STR__)

#ifdef CXX_SIMULATOR
#define VOLATILE
#else
#define VOLATILE volatile
#endif

#endif /* !TYPES_H */
