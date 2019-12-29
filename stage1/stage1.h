////////////////////////////////////////////////////////////////////////////////
///
/// @file       stage1.h
///
/// @project
///
/// @brief      Functions provided by stage1.
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018, Evan Lojewski
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

#ifndef STAGE1_H
#define STAGE1_H

#include <em100_putchar.h>
#ifndef CXX_SIMULATOR
#include <printf.h>
#else
#include <stdio.h>
#endif

#include <bcm5719_GEN.h>
#include <bcm5719_eeprom.h>
#if CXX_SIMULATOR
#include <APE_DEVICE.h>
#define volatile
#else
#include <bcm5719_DEVICE.h>
#endif

void early_init_hw(void);
void load_nvm_config(volatile DEVICE_t* device, NVRAMContents_t *nvram);
void init_hw(volatile DEVICE_t* device, NVRAMContents_t *nvram);

#define STATUS_MAIN         (0x8234700u)
#define STATUS_EARLY_INIT   (0x8234800u)
#define STATUS_NVM_CONFIG   (0x8234900u)
#define STATUS_INIT_HW      (0x8234A00u)

void reportStatus(uint32_t code, uint8_t step);

#endif /* STAGE1_H */
