////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.cpp
///
/// @project    bcm5719-fw
///
/// @brief      Main bcmflash tool for parsing BCM5179 flash images.
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
/// SUBSTITUTE GOODS OR SERVICES, LOSS OF USE, DATA, OR PROFITS, OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
/// POSSIBILITY OF SUCH DAMAGE.
/// @endcond
////////////////////////////////////////////////////////////////////////////////

#include "create_header.h"

#include <NVRam.h>
#include <bcm5719-endian.h>
#include <bcm5719_eeprom.h>
#include <string.h>

static struct
{
    const char *name;
    NVRAMInfo_t *info;
    NVRAMInfo2_t *info2;
    unsigned char *vpd;
    size_t vpd_length;
} devices[] = {
    { .name = "blackbird", .info = &gBlackbirdNVRAMInfo, .info2 = &gBlackbirdNVRAMInfo2, .vpd = gBlackbirdVPD, .vpd_length = gBlackbirdVPDLength },
    { .name = "talos2", .info = &gTalosIINVRAMInfo, .info2 = &gTalosIINVRAMInfo2, .vpd = gTalosIIVPD, .vpd_length = gTalosIIVPDLength },
    { .name = "kh08p", .info = &gKH08PNVRAMInfo, .info2 = &gKH08PNVRAMInfo2, .vpd = gKH08PVPD, .vpd_length = gKH08PVPDLength },
};

void init_firmware_header(NVRAMContents_t *nvram, const char *type)
{
    for (size_t i = 0; i < ARRAY_ELEMENTS(devices); i++)
    {
        if (0 == strncmp(type, devices[i].name, strlen(devices[i].name) + 1))
        {
            // Found the right device to use.
            memcpy(&nvram->info, devices[i].info, sizeof(NVRAMInfo_t));
            memcpy(&nvram->info2, devices[i].info2, sizeof(NVRAMInfo2_t));
            if (devices[i].vpd_length <= sizeof(vpd_t))
            {
                memcpy(&nvram->vpd, devices[i].vpd, devices[i].vpd_length);
            }
            break;
        }
    }

    nvram->header.magic = htobe32(BCM_NVRAM_MAGIC);
    nvram->header.bootstrapPhysAddr = htobe32(0x08003800);
    nvram->header.bootstrapOffset = htobe32(sizeof(NVRAMContents_t));
    nvram->header.bootstrapWords = 0;
    nvram->header.crc = 0;
}

void fixup_firmware_header(NVRAMContents_t *nvram)
{
    // CRC fixup
    nvram->info.mfrCRC = ~NVRam_crc((uint8_t *)&nvram->info, sizeof(NVRAMInfo_t) - 4, 0xffffffff);
    nvram->header.crc = ~NVRam_crc((uint8_t *)&nvram->header, sizeof(nvram->header) - 4, 0xffffffff);
}
