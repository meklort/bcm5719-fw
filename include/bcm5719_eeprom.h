////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_eeprom.h
///
/// @project    bcm5719
///
/// @brief      EEPROM definition for the BCM5719
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018-2019, Evan Lojewski
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
/// 3. Neither the name of the <organization> nor the
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

#ifndef BCMNVRAM
#define BCMNVRAM

#ifdef CXX_SIMULATOR
#include <stddef.h>     /* offsetof */
#define ELEMENT_OFFSET(__struct__, __elememnt__)        offsetof(__struct__, __elememnt__)
#else
#define _Static_assert(...)
#define ELEMENT_OFFSET(__struct__, __elememnt__)        
#endif

#if !defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)
#error Unknown endianness
#endif

#include <types.h>
#include <vpd.h>

#define BCM_NVRAM_MAGIC	(0x669955AAu)

#define BCM_CODE_DIRECTORY_TYPE_BC2             (0x00u)  /*< Second-phase bootcode */
#define BCM_CODE_DIRECTORY_TYPE_MBA             (0x01u)  /*< Multiple boot agent host software */
#define BCM_CODE_DIRECTORY_TYPE_L2_RXP          (0x02u)  /*< L2 receive processor firmware, required for VAUX operation of management firmware */
#define BCM_CODE_DIRECTORY_TYPE_UMP             (0x03u)
#define BCM_CODE_DIRECTORY_TYPE_IPMI_CFG        (0x07u)  /*< IPMI configuration data */
#define BCM_CODE_DIRECTORY_TYPE_IPMI_INIT       (0x08u)  /*< IPMI initialization firmware */
#define BCM_CODE_DIRECTORY_TYPE_IPMI_SERV       (0x09u)  /*< IPMI service firmware */
#define BCM_CODE_DIRECTORY_TYPE_USER_BLOCK      (0x0Au)
#define BCM_CODE_DIRECTORY_TYPE_ISCSI_BOOT_CPRG (0x0Bu)  /*< iSCSI boot configuration program */
#define BCM_CODE_DIRECTORY_TYPE_ISCSI_BOOT_CFG  (0x0Cu)  /*< iSCSI boot configuration data */
#define BCM_CODE_DIRECTORY_TYPE_ISCSI_BOOT      (0x0Du)  /*< iSCSI boot driver */

#define BCM_CODE_DIRECTORY_CPU_NONE             (0x00)
#define BCM_CODE_DIRECTORY_CPU_HOST             (0x01)
#define BCM_CODE_DIRECTORY_CPU_TXP              (0x02)
#define BCM_CODE_DIRECTORY_CPU_TPAT             (0x03)
#define BCM_CODE_DIRECTORY_CPU_COM              (0x04)
#define BCM_CODE_DIRECTORY_CPU_RXP              (0x05)
#define BCM_CODE_DIRECTORY_CPU_CP               (0x06)
#define BCM_CODE_DIRECTORY_CPU_MCP              (0x07)
#define BCM_CODE_DIRECTORY_CPU_APE              (0x0D)

#define BCM_CODE_DIRECTORY_ADDR_APE             (0x07)

#define BCM_CODE_DIRECTORY_GET_LENGTH(__x__)   ((__x__) & (0x00FFFFFFu))
#define BCM_CODE_DIRECTORY_GET_CPU(__x__)      (((__x__) & (0x0F000000u)) >> 24) /* FIXME: spec shows bit 27 as reserved. */
#define BCM_CODE_DIRECTORY_GET_TYPE(__x__)     (((__x__) & (0xF0000000u)) >> 28)
typedef struct {
    uint32_t    codeAddress;        /*< Code SRAM address, relative to the designated CPU */
    uint32_t    codeInfo;
    #if 0
    struct {
        uint32_t    rsvd0:2;
        uint32_t    words:22;       /*< Indicates the length of the image (plus the 4-byte CRC-32) in DWORD. It implies that the maximum size per directory entry is 16 MB. */

        uint32_t    targetCPU:3;    /*< Target CPU */
        uint32_t    rsvd1:1;
        uint32_t    imageType:4;    /*< Image Type */
    };
    #endif
    uint32_t    directoryOffset;    /*< NVRAM Offset to image */

} NVRAMCodeDirectory_t;

#define MANUFACTURING_INFORMATION_REVISION  ('A')
#define MANUFACTURING_INFORMATION_LENGTH    (0x100u)
#define MANUFACTURING_INFORMATION_DESIGN_TYPE_NIC   (0x00)
#define MANUFACTURING_INFORMATION_DESIGN_TYPE_LOM   (0x01)

#define MANUFACTURING_INFORMATION_PORT_SWAP_DISABLED   (0x00)
#define MANUFACTURING_INFORMATION_PORT_SWAP_ENABLED    (0x01)

#define MANUFACTURING_INFORMATION_UPM_MODE_MII     (0x00)
#define MANUFACTURING_INFORMATION_UPM_MODE_RMII    (0x01)

#define MANUFACTURING_INFORMATION_LED_MODE_MAC    (0x00)
#define MANUFACTURING_INFORMATION_LED_MODE_PHY_1    (0x01)
#define MANUFACTURING_INFORMATION_LED_MODE_PHY_2    (0x02)
#define MANUFACTURING_INFORMATION_LED_MODE_PHY_3    (0x03)  /*< (BCM5708 only) */
#define MANUFACTURING_INFORMATION_LED_MODE_PHY_4    (0x04)  /*< (BCM5708 only) */
#define MANUFACTURING_INFORMATION_LED_MODE_PHY_5    (0x05)  /*< (BCM5708 only) */
#define MANUFACTURING_INFORMATION_LED_MODE_PHY_6    (0x06)  /*< (BCM5708 only) */
#define MANUFACTURING_INFORMATION_LED_MODE_PHY_7    (0x07)  /*< (BCM5708 only) */

#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_GPIO_DISABLED   (0x00)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_GPIO_3   (0x03)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_GPIO_4   (0x04)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_GPIO_5   (0x05)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_GPIO_6   (0x06)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_GPIO_7   (0x07)

#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_ANY      (0x00)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_NC_SI    (0x01)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_UMP      (0x02)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_IPMI     (0x03)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_SPIO_4   (0x04)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_SPIO_5   (0x05)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_SPIO_6   (0x06)
#define MANUFACTURING_INFORMATION_FIRMWARE_LOAD_SPIO_7   (0x07)

#define MANUFACTURING_INFORMATION_SMBUS_100KHZ           (0x00)
#define MANUFACTURING_INFORMATION_SMBUS_400KHZ           (0x01)


typedef struct {
    uint32_t    magic;
    uint32_t    bootstrapPhysAddr;
    uint32_t    bootstrapWords;
    uint32_t    bootstrapOffset;
    uint32_t    crc;
} __attribute__((packed)) NVRAMHeader_t;


typedef struct {
    uint32_t    macAddr0[2];
    uint8_t     partNumber[16];
    uint8_t     partRevision[2];
    uint16_t    firmwareRevision;

    uint8_t     mfrData[4];

#ifdef __LITTLE_ENDIAN__
    uint16_t    func0PXEVLAN;
    uint16_t    func1PXEVLAN;
#else
    uint16_t    func1PXEVLAN;
    uint16_t    func0PXEVLAN;
#endif

#ifdef __LITTLE_ENDIAN__
    uint16_t    vendorID;           /*< PCI Vendor ID. */
    uint16_t    deviceID;           /*< PCI Device ID. */
#else
    uint16_t    deviceID;           /*< PCI Device ID. */
    uint16_t    vendorID;           /*< PCI Vendor ID. */
#endif

#ifdef __LITTLE_ENDIAN__
    uint16_t    subsystemVendorID;  /*< PCI Subsystem Vendor ID. */
    uint16_t    subsystemDeviceID;  /*< PCI Subsystem Device ID. */
#else
    uint16_t    subsystemDeviceID;  /*< PCI Subsystem Device ID. */
    uint16_t    subsystemVendorID;  /*< PCI Subsystem Vendor ID. */
#endif

#ifdef __LITTLE_ENDIAN__
    uint8_t     SMBusAddrBMC;
    uint8_t     SMBusAddr;

    uint16_t    cpuClock;           /*< 66MHz, Legacy */
#else
    uint16_t    cpuClock;           /*< 66MHz, Legacy */

    uint8_t     SMBusAddr;
    uint8_t     SMBusAddrBMC;
#endif

    uint32_t    macAddr0Backup[2];
    uint32_t    macAddr1Backup[2];

    union {
        struct {
#ifdef __LITTLE_ENDIAN__
            uint8_t     powerDissipatedD0;  /*< Power dissipated in the D0 state. Note: The data scale is hard coded at 0.1. */
            uint8_t     powerDissipatedD1;  /*< Power dissipated in the D1 state. The NetXtreme II family does not support the D1 state. */
            uint8_t     powerDissipatedD2;  /*< Power dissipated in the D2 state. The NetXtreme II family does not support the D2 state. */
            uint8_t     powerDissipatedD3;  /*< Power dissipated in the D3 state. Note: The data scale is hard coded at 0.1. */
#else
            uint8_t     powerDissipatedD3;  /*< Power dissipated in the D3 state. Note: The data scale is hard coded at 0.1. */
            uint8_t     powerDissipatedD2;  /*< Power dissipated in the D2 state. The NetXtreme II family does not support the D2 state. */
            uint8_t     powerDissipatedD1;  /*< Power dissipated in the D1 state. The NetXtreme II family does not support the D1 state. */
            uint8_t     powerDissipatedD0;  /*< Power dissipated in the D0 state. Note: The data scale is hard coded at 0.1. */
#endif
        };
        uint32_t     powerDissipated;
    };

    union {
        struct {
#ifdef __LITTLE_ENDIAN__
            uint8_t     powerConsumedD0;    /*< Power consumed in the D0 state. Note: The data scale is hard coded at 0.1. */
            uint8_t     powerConsumedD1;    /*< Power consumed in the D1 state. The NetXtreme II family does not support the D1 state. */
            uint8_t     powerConsumedD2;    /*< Power consumed in the D2 state. The NetXtreme II family does not support the D2 state. */
            uint8_t     powerConsumedD3;    /*< Power consumed in the D3 state. Note: The data scale is hard coded at 0.1. */
#else
            uint8_t     powerConsumedD3;    /*< Power consumed in the D3 state. Note: The data scale is hard coded at 0.1. */
            uint8_t     powerConsumedD2;    /*< Power consumed in the D2 state. The NetXtreme II family does not support the D2 state. */
            uint8_t     powerConsumedD1;    /*< Power consumed in the D1 state. The NetXtreme II family does not support the D1 state. */
            uint8_t     powerConsumedD0;    /*< Power consumed in the D0 state. Note: The data scale is hard coded at 0.1. */
#endif
        };
        uint32_t     powerConsumed;
    };

    uint32_t    func0CfgFeature;
    uint32_t    func0CfgHW;

    uint32_t    macAddr1[2];


    uint32_t    func1CfgFeature;
    uint32_t    func1CfgHW;
    uint32_t    cfgShared;
    uint32_t    powerBudget0;
    uint32_t    powerBudget1;
    uint32_t    serworksUse;
#ifdef __LITTLE_ENDIAN__
    uint16_t    func0SERDESOverride;
    uint16_t    func1SERDESOverride;
#else
    uint16_t    func1SERDESOverride;
    uint16_t    func0SERDESOverride;
#endif
#ifdef __LITTLE_ENDIAN__
    uint16_t    macNVMSize;
    uint16_t    tpmNVMSize;
#else
    uint16_t    tpmNVMSize;
    uint16_t    macNVMSize;
#endif
    uint32_t    powerBudget2;
    uint32_t    powerBudget3;
    uint32_t    mfrCRC;
} NVRAMInfo_t;

typedef struct {
#ifdef __LITTLE_ENDIAN__
    uint16_t    mfr2Len;                //   [202] 00 8C          -- Length of manufacturing section 2.
    uint16_t    mfr2Unk;                //   [200] 00 00          -- Unknown, probably unused.
#else
    uint16_t    mfr2Unk;                //   [200] 00 00          -- Unknown, probably unused.
    uint16_t    mfr2Len;                //   [202] 00 8C          -- Length of manufacturing section 2.
#endif
    uint32_t    UNKNOWN0;               //   [204] 00 00 00 00    -- Could be reserved.

    uint32_t    macAddr2[2];            //1  [208] Upper 16 bits are zero/unused.

    uint32_t    UNKNOWN1;               //   [210] 0
    uint32_t    UNKNOWN2;               //   [214] 0
    uint32_t    UNKNOWN3;               //   [218] 0
    uint32_t    cfg5;                   //1  [21C] 0   - GEN_CFG_5. g_unknownInitWord3
    uint32_t    UNKNOWN4;               //   [220] 0
    uint32_t    UNKNOWN5;               //   [224] 0
    uint32_t    UNKNOWN6;               //   [228] 0

#ifdef __LITTLE_ENDIAN__
    uint16_t    pciSubsystemF0GPHY;
    uint16_t    pciSubsystemF1GPHY;
#else
    uint16_t    pciSubsystemF1GPHY;
    uint16_t    pciSubsystemF0GPHY;
#endif
#ifdef __LITTLE_ENDIAN__
    uint16_t    pciSubsystemF2GPHY;
    uint16_t    pciSubsystemF3GPHY;
#else
    uint16_t    pciSubsystemF3GPHY;
    uint16_t    pciSubsystemF2GPHY;
#endif
#ifdef __LITTLE_ENDIAN__
    uint16_t    pciSubsystemF0SERDES;
    uint16_t    pciSubsystemF1SERDES;
#else
    uint16_t    pciSubsystemF1SERDES;
    uint16_t    pciSubsystemF0SERDES;
#endif
#ifdef __LITTLE_ENDIAN__
    uint16_t    pciSubsystemF2SERDES;
    uint16_t    pciSubsystemF3SERDES;
#else
    uint16_t    pciSubsystemF3SERDES;
    uint16_t    pciSubsystemF2SERDES;
#endif

    uint32_t    UNKNOWN7;               //   [23C] 0
    uint32_t    UNKNOWN8;               //   [240] 0
    uint32_t    UNKNOWN9;               //   [244] 0
    uint32_t    UNKNOWN10;              //   [248] 0
    uint32_t    UNKNOWN11;              //   [24C] 0
    uint32_t    func2CfgFeature;        //1  [250] C5 C0 00 00 - Function 2 GEN_CFG_1E4.
    uint32_t    func2CfgHW;             //1  [254] 00 00 40 14 - Function 2 GEN_CFG_2.

    uint32_t    macAddr3[2];            //1  [258] Upper 16 bits are zero/unused.

    uint32_t    func3CfgFeature;        //1  [260] C5 C0 00 00 - Function 3 GEN_CFG_1E4.
    uint32_t    func3CfgHW;             //1  [264] 00 00 40 14 - Function 3 GEN_CFG_2.
    uint32_t    UNKNOWN12;              //   [268] 0
    uint32_t    UNKNOWN13;              //   [26C] 0
    uint32_t    UNKNOWN14;              //   [270] 0
    uint32_t    UNKNOWN15;              //   [274] 0
    uint32_t    func0CfgHW2;            //1  [278] 00 00 00 40 - Function 0 GEN_CFG_2A8.
    uint32_t    func1CfgHW2;            //1  [27C] 00 00 00 40 - Function 1 GEN_CFG_2A8.
    uint32_t    func2CfgHW2;            //1  [280] 00 00 00 40 - Function 2 GEN_CFG_2A8.
    uint32_t    func3CfgHW2;            //1  [284] 00 00 00 40 - Function 3 GEN_CFG_2A8.
    uint32_t    mfr2CRC;                //   [288] 1A AC 41 A6 // could be CRC
} NVRAMInfo2_t;

typedef struct {
    NVRAMHeader_t           header;
    NVRAMCodeDirectory_t    directory[8];
    uint8_t                 pad[0x80 - sizeof(NVRAMHeader_t) - 4 - sizeof(NVRAMCodeDirectory_t) * 8];
    NVRAMInfo_t             info;
    vpd_t                   vpd;
    NVRAMInfo2_t            info2;
} NVRAMContents_t;


_Static_assert(ELEMENT_OFFSET(NVRAMContents_t, info) == 0x7C, "NVRAM Info must be located at address 0x7C.");
_Static_assert(ELEMENT_OFFSET(NVRAMContents_t, info2) == 0x200, "NVRAM Info2 must be located at address 0x200.");
_Static_assert(ELEMENT_OFFSET(NVRAMContents_t, vpd) == 0x100, "VPD must be located at address 0x100.");
_Static_assert(sizeof(NVRAMContents_t) == 0x28C, "sizeof(NVRAMContents_t) must be 0x28C.");


typedef struct {
    uint32_t magic; // BCM_NVRAM_MAGIC
    uint32_t length;
} NVRAMStage2Header_t;

typedef struct {
    NVRAMStage2Header_t header;
    uint32_t words[];
    // uint32_t crc;
} NVRAMStage2_t;


#define APE_SECTION_FLAG_COMPRESSED         (1U<<0)
#define APE_SECTION_FLAG_CHECKSUM_IS_CRC32  (1U<<1)
#define APE_SECTION_FLAG_CODE               (1U<<2)
#define APE_SECTION_FLAG_UNK0               (1U<<3)
#define APE_SECTION_FLAG_ZERO_ON_FAST_BOOT  (1U<<4)
typedef struct {
    uint32_t    loadAddr;
    uint32_t    offset:24;
    uint32_t    flags:8;
    uint32_t    decompressedSize;
    uint32_t    compressedSize;
    uint32_t    crc;
} APESection_t;
_Static_assert(sizeof(APESection_t) == 0x14, "sizeof(APESection_t) must be 0x14.");

#define APE_HEADER_MAGIC    0x1A4D4342
#define APE_HEADER_UNK0     0x03070700
#define APE_HEADER_UNK1     0x00
#define APE_HEADER_UNK2     0x04
typedef struct {
    uint32_t        magic;
    uint32_t        unk0;   // 0x03070700
    uint8_t         name[16];
    uint32_t        version;
    uint32_t        entrypoint;

    uint8_t         unk1;   // 0x00
    uint8_t         words;  // 0x1E
    uint8_t         unk2;   // 0x04
    uint8_t         sections; // 4?

    uint32_t        crc;
    APESection_t    section[];
} APEHeader_t;
_Static_assert(sizeof(APEHeader_t) == 40, "sizeof(APESection_t) must be 40.");

#endif
