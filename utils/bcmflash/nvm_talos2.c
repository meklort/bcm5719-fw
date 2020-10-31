////////////////////////////////////////////////////////////////////////////////
///
/// @file       talos2.c
///
/// @project    bcm5719-fw
///
/// @brief      NVRAM configuration for use with the Talos II.
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2020, Evan Lojewski
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

#include <bcm5719_eeprom.h>

#ifdef __LITTLE_ENDIAN__
#define htobe32(__x__) ((((__x__)&0x000000FF) << 24) | (((__x__)&0x0000FF00) << 8) | (((__x__)&0x00FF0000) >> 8) | (((__x__)&0xFF000000) >> 24))
#define htobe16(__x__) ((((__x__)&0x00FF) << 8) | (((__x__)&0xFF00) >> 8))
#elif __BIG_ENDIAN__
#define htobe32(__x__) (__x__)
#define htobe16(__x__) (__x__)
#else
#error Unknown endianness
#endif

NVRAMInfo2_t gTalosIINVRAMInfo2 = {
    .mfr2Unk = 0,                             //   [200] 00 00          -- Unknown, probably unused.
    .mfr2Len = htobe16(sizeof(NVRAMInfo2_t)), //   [202] 00 8C          -- Length of manufacturing section 2.
    .UNKNOWN0 = 0,                            //   [204] 00 00 00 00    -- Could be reserved.

    .macAddr2 = { 0 }, // 1  [208] Upper 16 bits are zero/unused.

    .UNKNOWN1 = 0, //   [210] 0
    .UNKNOWN2 = 0, //   [214] 0
    .UNKNOWN3 = 0, //   [218] 0
    .cfg5 = 0,     // 1  [21C] 0   - GEN_CFG_5. g_unknownInitWord3
    .UNKNOWN4 = 0, //   [220] 0
    .UNKNOWN5 = 0, //   [224] 0

    .func3PXEVLAN = htobe16(0),
    .func2PXEVLAN = htobe16(0),

    .pciSubsystemF0GPHY = htobe16(0x1981),
    .pciSubsystemF1GPHY = htobe16(0x1981),
    .pciSubsystemF2GPHY = htobe16(0x1981),
    .pciSubsystemF3GPHY = htobe16(0x1981),
    .pciSubsystemF0SERDES = htobe16(0x1657),
    .pciSubsystemF1SERDES = htobe16(0x1657),
    .pciSubsystemF2SERDES = htobe16(0x1657),
    .pciSubsystemF3SERDES = htobe16(0x1657),

    .UNKNOWN7 = 0,                          //   [23C] 0
    .UNKNOWN8 = 0,                          //   [240] 0
    .UNKNOWN9 = 0,                          //   [244] 0
    .UNKNOWN10 = 0,                         //   [248] 0
    .UNKNOWN11 = 0,                         //   [24C] 0
    .func2CfgFeature = htobe32(0xC5C00000), // 1  [250] C5 C0 00 00 - Function 2 GEN_CFG_1E4.
    .func2CfgHW = htobe32(0x00004014),      // 1  [254] 00 00 40 14 - Function 2 GEN_CFG_2.

    .macAddr3 = { 0 }, // 1  [258] Upper 16 bits are zero/unused.

    .func3CfgFeature = htobe32(0xC5C00000), // 1  [260] C5 C0 00 00 - Function 3 GEN_CFG_1E4.
    .func3CfgHW = htobe32(0x00004014),      // 1  [264] 00 00 40 14 - Function 3 GEN_CFG_2.
    .UNKNOWN12 = 0,                         //   [268] 0a
    .UNKNOWN13 = 0,                         //   [26C] 0a
    .UNKNOWN14 = 0,                         //   [270] 0a
    .UNKNOWN15 = 0,                         //   [274] 0a
    .func0CfgHW2 = htobe32(0x00000040),     // 1  [278] 00 00 00 40 - Function 0 GEN_CFG_2A8.a
    .func1CfgHW2 = htobe32(0x00000040),     // 1  [27C] 00 00 00 40 - Function 1 GEN_CFG_2A8.a
    .func2CfgHW2 = htobe32(0x00000040),     // 1  [280] 00 00 00 40 - Function 2 GEN_CFG_2A8.a
    .func3CfgHW2 = htobe32(0x00000040),     // 1  [284] 00 00 00 40 - Function 3 GEN_CFG_2A8.a
    .mfr2CRC = 0,                           //   [288] 1A AC 41 A6 // could be CRC
};

NVRAMInfo_t gTalosIINVRAMInfo = {
    .macAddr0 = { 0 }, /* Placeholder*/
    .partNumber = "BCM95719",
    .partRevision = { 'A', '0' },
    .firmwareRevision = 0, /* Placeholder*/
    .mfrData = { 0 },
    .func1PXEVLAN = 0,
    .func0PXEVLAN = 0,
    .vendorID = htobe16(0x1657),          /*< PCI Vendor ID. */
    .deviceID = htobe16(0x14E4),          /*< PCI Device ID. */
    .subsystemVendorID = htobe16(0x1657), /*< PCI Subsystem Vendor ID. */
    .subsystemDeviceID = htobe16(0x14E4), /*< PCI Subsystem Device ID. */

    .cpuClock = htobe16(66), /*< 66MHz, Legacy */

    .SMBusAddr = 0,
    .SMBusAddrBMC = 0,

    .macAddr0Backup = { 0 },
    .macAddr1Backup = { 0 },

    .powerDissipatedD0 = 0x64,
    .powerDissipatedD1 = 0x00,
    .powerDissipatedD2 = 0x00,
    .powerDissipatedD3 = 0x0A,

    .powerConsumedD0 = 0x64, /*< Power consumed in the D0 state. Note: The data scale is hard coded at 0.1. */
    .powerConsumedD1 = 0x00, /*< Power consumed in the D1 state. The NetXtreme II family does not support the D1 state. */
    .powerConsumedD2 = 0x00, /*< Power consumed in the D2 state. The NetXtreme II family does not support the D2 state. */
    .powerConsumedD3 = 0x0A, /*< Power consumed in the D3 state. Note: The data scale is hard coded at 0.1. */

    .func0CfgFeature = htobe32(0xC5C00080),
    .func0CfgHW = htobe32(0x00004014),

    .macAddr1 = { 0 },
    .func1CfgFeature = htobe32(0xC5C00000),
    .func1CfgHW = htobe32(0x00004014),

    .cfgShared = htobe32(0x00C2AA38),
    .powerBudget0 = htobe32(0x2C163C2C),
    .powerBudget1 = htobe32(0x0000230A),
    .serworksUse = 0,
    .func1SERDESOverride = 0,
    .func0SERDESOverride = 0,
    .tpmNVMSize = 0,
    .macNVMSize = htobe16(4),
    .powerBudget2 = htobe32(0x00000000),
    .powerBudget3 = htobe32(0x00000000),
    .mfrCRC = 0,
};
