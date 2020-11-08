////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719-endian.h
///
/// @project    Endianness wrapper header
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

#ifndef BCM5719_ENDIAN_H
#define BCM5719_ENDIAN_H

#if defined(ENDIANNESS_CONFIG_HAVE_ENDIAN_H)
#include <endian.h>
#elif defined(ENDIANNESS_CONFIG_HAVE_SYS_ENDIAN_H)
#include <sys/endian.h>
#endif

#ifdef __LITTLE_ENDIAN__
#define swap32(__x__) ((((__x__)&0x000000FF) << 24) | (((__x__)&0x0000FF00) << 8) | (((__x__)&0x00FF0000) >> 8) | (((__x__)&0xFF000000) >> 24))
#define swap16(__x__) ((((__x__)&0x00FF) << 8) | (((__x__)&0xFF00) >> 8))
#elif __BIG_ENDIAN__
#define swap32(__x__) (__x__)
#define swap16(__x__) (__x__)
#else
#error Unknown endianness
#endif

#endif /* !BCM5719_ENDIAN_H */
