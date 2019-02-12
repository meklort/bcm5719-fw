#ifndef BCMNVRAM
#define BCMNVRAM

#include <stdint.h>
#include <stddef.h>     /* offsetof */
#include <types.h>
#include <vpd.h>

#define ELEMENT_OFFSET(__struct__, __elememnt__)        offsetof(__struct__, __elememnt__)
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

} NVRAMCodeDirectory;

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
    uint8_t             MACAddr[8];  /*< Primary Port MAC address. The upper 2 bytes are not used and must be 0. */
    struct {
        uint32_t        driverValues:16;    /*< Pre-emphasis and current driver values (BCM5808S and BCM5709S only). */

        uint32_t        defaultLinkSettings:4; /*< Default Link Setting (BCM5708S and BCM5709S only) */
        uint32_t        LEDMode:4;          /*< LED Mode (BCM5709 only) */ // TODO
        uint32_t        rsvd:5;
    } PortConfig;

    uint16_t            PortVendorID; /*< Primary Port PCI Vendor ID (BCM5709 and BCM5716 only) */
    uint16_t            PortDeviceID; /*< Primary Port PCI Device ID (BCM5709) */
    uint16_t            PortSubsystemDeviceID;
    uint16_t            PortSubsystemVendorID;

    uint8_t             PortiSCSIMac[8]; /* Primary Port iSCSI MAC address. The upper 2 bytes are not used and must be 0. */
    uint8_t             PortBackupL2MAC[8]; /*< Primary Port Backup permanent L2 MAC address. The upper 2 bytes are not used and must be 0.*/
    uint8_t             rsvd3[28];
} NVRAMManufacturingPortInformation;

typedef struct {
    uint8_t             revision;           /*< Manufacturing Information table revision in ASCII. The current version is 'A.' */
    uint8_t             rsvd0;
    uint16_t            length;             /*< Length of manufacturing information (currently 0x100 for a revision 'A' manufacturing table). */

    uint16_t            vendorID;           /*< PCI Vendor ID (BCM5706 and BCM5708 only). */
    uint16_t            deviceID;           /*< PCI Device ID (BCM5706 and BCM5708 only). */

    uint16_t            subsystemDeviceID;  /*< PCI Subsystem Device ID (BCM5706 and BCM5708 only). */
    uint16_t            subsystemVendorID;  /*< PCI Subsystem Vendor ID (BCM5706 and BCM5708 only). */

    uint8_t             partNumber[16];      /*< NULL-terminated part number of the device. This field is identical to the PN field in the VPD-R region. */

    uint8_t             powerDissipatedD3;  /*< Power dissipated in the D3 state. Note: The data scale is hard coded at 0.1. */
    uint8_t             powerDissipatedD2;  /*< Power dissipated in the D2 state. The NetXtreme II family does not support the D2 state. */
    uint8_t             powerDissipatedD1;  /*< Power dissipated in the D1 state. The NetXtreme II family does not support the D1 state. */
    uint8_t             powerDissipatedD0;  /*< Power dissipated in the D0 state. Note: The data scale is hard coded at 0.1. */

    uint8_t             powerConsumedD3;    /*< Power consumed in the D3 state. Note: The data scale is hard coded at 0.1. */
    uint8_t             powerConsumedD2;    /*< Power consumed in the D2 state. The NetXtreme II family does not support the D2 state. */
    uint8_t             powerConsumedD1;    /*< Power consumed in the D1 state. The NetXtreme II family does not support the D1 state. */
    uint8_t             powerConsumedD0;    /*< Power consumed in the D0 state. Note: The data scale is hard coded at 0.1. */

    struct {
        uint32_t        designType:1;       /*< Design Type */
        uint32_t        portSwap:1;         /*< Port Swap */
        uint32_t        highPower:1;        /*< Allow power consumption to exceed 375 mA in VAUX Current Overdraw—Enabling this setting allows the power consumption to exceed 375 mA in VAUX. This setting must be enabled to allow proper operation of management firmware such as IPMI and UMP. */
        uint32_t        UMPMode:1;          /*< UMP Interface mode (BCM5708, BCM5709 and BCM5716 only) */

        uint32_t        WOLbeacon:1;        /*< PCIe beacon in WOL state (BCM5708 and BCM5709S only) */
        uint32_t        enable2G5:1;        /*< Enable 2.5G support (BCM5708S and BCM5709S only). */
        uint32_t        backplaneApp:1;     /*< Backplane application (BCM5708S and BCM5709S only) */
        uint32_t        CRS_RXDVn:1;        /*< CRS/RXDV UMP Selection (BCM5708 B0 and later) */  

        uint32_t        LEDMode:3;          /*< PHY LED mode */
        uint32_t        UMPTiming:1;        /*< Enable UMP PHY Timing (BCM5708 B0 and later, BCM5709 and BCM5716))—This setting is hardware design dependent and should be enabled when the UMP's MII/RMII interface is directly connected to a PHY. In this mode the TX_CLK and RX_CLK are driven as outputs and are synchronized to the CK25 output. This option should be disabled when connected directly to another MAC. In this mode the TX_CLK and RX_CLK pins are selected as inputs and are driven by the CK25 output. */

        uint32_t        firmwareLoad:3;     /*< Firmware load SPIO/GPIO toggle—If management firmware is enabled, and both IPMI and UMP firmware are present, the value of this GPIO is sampled after reset to determine which management firmware to load. If the GPIO is sampled as 0, UMP is loaded; otherwise, IPMI is loaded. */
        uint32_t        gigabitLinkVAUX:1;  /*< Allow Gigabit Link in VAUX. Note: This setting also requires that “VAUX Current Overdraw” (bit 2) also be enabled. */

        uint32_t        LEDApplication:2;   /*< LED Application (BCM5708S A0 and B0 only) OR Dual MAC mode (BCM5709 and BCM5716 only) */
        uint32_t        PCIeGen2:2;         /*< PCIe Gen 2 Support (BCM5709 and BCM5716 only) */

        uint32_t        SMBusTiming:1;      /*< SMBus timing (BCM5709 and BCM5716 only) */
        uint32_t        rsvd_bits:11;
    } shareConfig1;

    struct {
        uint32_t        NVRAMSize:24;       /*< The size of the NVRAM in bytes (bits 11 to 0 must be 0). */
        uint32_t        rsvd_bits:8;
    } sharedConfig2;

    uint32_t            ECOConfig;          /*< ECO Configuration (BCM5708 B2 and later only). The value of this location is written to offset 0x7c of the EPB to enable specific hardware fixes. */
    
    uint32_t            rsvd1;

    NVRAMManufacturingPortInformation   PrimaryPort;
    NVRAMManufacturingPortInformation   SecondaryPort;
    uint8_t             powerBudget[32];
    uint32_t            crc;                /*< CRC-32 of the Manufacturing Information (offset 0x100 to 0x1fb inclusive). */
} NVRAMManufacturingInformation;
//_Static_assert(sizeof(NVRAMManufacturingInformation) == MANUFACTURING_INFORMATION_LENGTH, "NVRAMManufacturingInformation is not the correct size.");

#define FEATURE_CONFIG_REVISION     ('A')
typedef struct {
    uint32_t            rsvd:28;
    uint32_t            revision:4;         /*< Feature configuration Information table revision in ASCII. The current version is 'A.' */
    uint32_t            config;             /*< Enable */
} NVRAMFeatureConfig;




typedef struct {
    uint32_t    magic;
    uint32_t    bootstrapPhysAddr;
    uint32_t    bootstrapWords;
    uint32_t    bootstrapOffset;
    uint32_t    crc;
} __attribute__((packed)) NVRAMHeader;


typedef struct {
    uint64_t    macAddr0; // FIXME
    uint8_t     partNumber[16];

    uint32_t    unknown1;
    uint32_t    unknown2;
    uint32_t    unknown3;

    uint16_t    deviceID;           /*< PCI Device ID. */
    uint16_t    vendorID;           /*< PCI Vendor ID. */

    uint16_t    subsystemDeviceID;  /*< PCI Subsystem Device ID. */
    uint16_t    subsystemVendorID;  /*< PCI Subsystem Vendor ID. */

    uint8_t     pad[88];
} __attribute__((packed)) NVRAMInfo;

typedef struct {
    NVRAMHeader         header;
    NVRAMCodeDirectory  directory[8];
    uint8_t             pad[0x80 - sizeof(NVRAMHeader) - 4 - sizeof(NVRAMCodeDirectory) * 8];
    NVRAMInfo           info;
    vpd_t               vpd;

// CRC from 0x00000000 to 0x00000010: 0x252333D4 // Header
//     from 0x00000100 to 0x000001FF: VPD
// CRC from 0x00000200 to 0x00000288: 0x1AAC41A6 // Feature Configuration Information??
// CRC from 0x0000028C to 0x00001DA8: 0x0AA649A4 // Bootstrap code.

// 6699 55aa is located again at 0x00001DAC (magic number. Secondary payload?)
// CRC from 0x00004C14 to 0x0001097C: 0x518A1ECC // Code directory 0 payload ??? 


    // uint8_t            pad[(0x14 - sizeof(NVRAMHeader))];
    // uint32_t            unknown[1024];

    // NVRAMCodeDirectory  directory[16];
    // uint8_t             padding[20];
    // uint8_t             sparePartNumber[20];  /*< Spare part number (similar to the PN field in the VPD), reserved for OEM use */
    // uint32_t            crc;                  /*< CRC-32 of the code directory (NVRAMContents.directory to NVRAMContents.sparePartNumber inclusive) */
    // NVRAMManufacturingInformation   manuf;
    // NVRAMFeatureConfig  features;
} __attribute__((packed)) NVRAMContents;


_Static_assert(ELEMENT_OFFSET(NVRAMContents, info) == 0x7C, "NVRAM Info must be located at address 0x80.");
_Static_assert(ELEMENT_OFFSET(NVRAMContents, vpd) == 0x100, "VPD must be located at address 0x100.");



#endif
