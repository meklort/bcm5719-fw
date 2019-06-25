////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_DEVICE2.h
///
/// @project    ape
///
/// @brief      APE_DEVICE2
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

/** @defgroup APE_DEVICE2_H    APE_DEVICE2 */
/** @addtogroup APE_DEVICE2_H
 * @{
 */
#ifndef APE_DEVICE2_H
#define APE_DEVICE2_H

#include <types.h>
#include "APE_DEVICE.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_DEVICE2_sim(void* base);
void init_APE_DEVICE2(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_DEVICE2_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_DEVICE2_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_DEVICE2_H_uint32_t;
#define APE_DEVICE2_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_DEVICE2_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_DEVICE2_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_DEVICE2_H_uint8_t;
typedef uint16_t APE_DEVICE2_H_uint16_t;
typedef uint32_t APE_DEVICE2_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_DEVICE2_BASE ((volatile void*)0xa0060000) /* Device Registers, function 2 */
#define REG_DEVICE2_SIZE (sizeof(DEVICE_t))

#define REG_DEVICE2_MISCELLANEOUS_HOST_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa0060068) /*  */
#define REG_DEVICE2_PCI_STATE ((volatile APE_DEVICE2_H_uint32_t*)0xa0060070) /*  */
#define REG_DEVICE2_REGISTER_BASE ((volatile APE_DEVICE2_H_uint32_t*)0xa0060078) /* Local controller memory address of a register than can be written or read by writing to the register data register. */
#define REG_DEVICE2_MEMORY_BASE ((volatile APE_DEVICE2_H_uint32_t*)0xa006007c) /* Local controller memory address of the NIC memory region that can be accessed via Memory Window data register. */
#define REG_DEVICE2_REGISTER_DATA ((volatile APE_DEVICE2_H_uint32_t*)0xa0060080) /* Register Data at the location pointed by the Register Base Register. */
#define REG_DEVICE2_UNDI_RECEIVE_RETURN_RING_CONSUMER_INDEX ((volatile APE_DEVICE2_H_uint32_t*)0xa0060088) /* UNDI Receive Return Ring Consumer Index Mailbox */
#define REG_DEVICE2_UNDI_RECEIVE_RETURN_RING_CONSUMER_INDEX_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa006008c) /* UNDI Receive Return Ring Consumer Index Mailbox */
#define REG_DEVICE2_LINK_STATUS_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa00600bc) /* PCIe standard register. */
#define REG_DEVICE2_APE_MEMORY_BASE ((volatile APE_DEVICE2_H_uint32_t*)0xa00600f8) /* APE Memory address to read/write using the APE Memory Data register.. */
#define REG_DEVICE2_APE_MEMORY_DATA ((volatile APE_DEVICE2_H_uint32_t*)0xa00600fc) /* APE Memory value at the location pointed by the Memory Base Register. */
#define REG_DEVICE2_EMAC_MODE ((volatile APE_DEVICE2_H_uint32_t*)0xa0060400) /*  */
#define REG_DEVICE2_EMAC_STATUS ((volatile APE_DEVICE2_H_uint32_t*)0xa0060404) /*  */
#define REG_DEVICE2_EMAC_EVENT ((volatile APE_DEVICE2_H_uint32_t*)0xa0060408) /*  */
#define REG_DEVICE2_LED_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa006040c) /*  */
#define REG_DEVICE2_EMAC_MAC_ADDRESSES_0_HIGH ((volatile APE_DEVICE2_H_uint32_t*)0xa0060410) /* Upper 2-bytes of this node's MAC address. */
#define REG_DEVICE2_EMAC_MAC_ADDRESSES_0_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa0060414) /* Lower 4-byte of this node's MAC address. */
#define REG_DEVICE2_EMAC_MAC_ADDRESSES_1_HIGH ((volatile APE_DEVICE2_H_uint32_t*)0xa0060418) /* Upper 2-bytes of this node's MAC address. */
#define REG_DEVICE2_EMAC_MAC_ADDRESSES_1_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa006041c) /* Lower 4-byte of this node's MAC address. */
#define REG_DEVICE2_EMAC_MAC_ADDRESSES_2_HIGH ((volatile APE_DEVICE2_H_uint32_t*)0xa0060420) /* Upper 2-bytes of this node's MAC address. */
#define REG_DEVICE2_EMAC_MAC_ADDRESSES_2_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa0060424) /* Lower 4-byte of this node's MAC address. */
#define REG_DEVICE2_EMAC_MAC_ADDRESSES_3_HIGH ((volatile APE_DEVICE2_H_uint32_t*)0xa0060428) /* Upper 2-bytes of this node's MAC address. */
#define REG_DEVICE2_EMAC_MAC_ADDRESSES_3_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa006042c) /* Lower 4-byte of this node's MAC address. */
#define REG_DEVICE2_WOL_PATTERN_POINTER ((volatile APE_DEVICE2_H_uint32_t*)0xa0060430) /* Specifies the offset into the 6KB BD memory for frame comparison. (Bits 3:0 are ignored to align the memory address to a natural 128-bit boundary). */
#define REG_DEVICE2_WOL_PATTERN_CFG ((volatile APE_DEVICE2_H_uint32_t*)0xa0060434) /*  */
#define REG_DEVICE2_MTU_SIZE ((volatile APE_DEVICE2_H_uint32_t*)0xa006043c) /* 2-byte field which is the largest size frame that will be accepted without being marked as oversize. */
#define REG_DEVICE2_MII_COMMUNICATION ((volatile APE_DEVICE2_H_uint32_t*)0xa006044c) /*  */
#define REG_DEVICE2_MII_MODE ((volatile APE_DEVICE2_H_uint32_t*)0xa0060454) /*  */
#define REG_DEVICE2_TRANSMIT_MAC_MODE ((volatile APE_DEVICE2_H_uint32_t*)0xa006045c) /*  */
#define REG_DEVICE2_RECEIVE_MAC_MODE ((volatile APE_DEVICE2_H_uint32_t*)0xa0060468) /*  */
#define REG_DEVICE2_PERFECT_MATCH1_HIGH ((volatile APE_DEVICE2_H_uint32_t*)0xa0060540) /*  */
#define REG_DEVICE2_PERFECT_MATCH1_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa0060544) /*  */
#define REG_DEVICE2_PERFECT_MATCH2_HIGH ((volatile APE_DEVICE2_H_uint32_t*)0xa0060548) /*  */
#define REG_DEVICE2_PERFECT_MATCH2_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa006054c) /*  */
#define REG_DEVICE2_PERFECT_MATCH3_HIGH ((volatile APE_DEVICE2_H_uint32_t*)0xa0060550) /*  */
#define REG_DEVICE2_PERFECT_MATCH3_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa0060554) /*  */
#define REG_DEVICE2_PERFECT_MATCH4_HIGH ((volatile APE_DEVICE2_H_uint32_t*)0xa0060558) /*  */
#define REG_DEVICE2_PERFECT_MATCH4_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa006055c) /*  */
#define REG_DEVICE2_SGMII_STATUS ((volatile APE_DEVICE2_H_uint32_t*)0xa00605b4) /* This register reflects various status of the respective SGMII port when enabled. */
#define REG_DEVICE2_CPMU_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa0063600) /*  */
#define REG_DEVICE2_LINK_AWARE_POWER_MODE_CLOCK_POLICY ((volatile APE_DEVICE2_H_uint32_t*)0xa0063610) /*  */
#define REG_DEVICE2_CLOCK_SPEED_OVERRIDE_POLICY ((volatile APE_DEVICE2_H_uint32_t*)0xa0063624) /*  */
#define REG_DEVICE2_STATUS ((volatile APE_DEVICE2_H_uint32_t*)0xa006362c) /*  */
#define REG_DEVICE2_CLOCK_STATUS ((volatile APE_DEVICE2_H_uint32_t*)0xa0063630) /*  */
#define REG_DEVICE2_GPHY_CONTROL_STATUS ((volatile APE_DEVICE2_H_uint32_t*)0xa0063638) /*  */
#define REG_DEVICE2_CHIP_ID ((volatile APE_DEVICE2_H_uint32_t*)0xa0063658) /*  */
#define REG_DEVICE2_MUTEX_REQUEST ((volatile APE_DEVICE2_H_uint32_t*)0xa006365c) /* Writing a 1 to any of these bits pends a Mutex lock request on behalf of a software agent. The bit is subsequently latched by hardware and shall read 1 as long as the request is pending. Writing a 0 to a bit shall have no effect. */
#define REG_DEVICE2_MUTEX_GRANT ((volatile APE_DEVICE2_H_uint32_t*)0xa0063660) /* Reading this field shall return a maximum of one set bit at any time. The set bit shall point to the lock owner. If the Mutex is not locked, then a read shall return a value 0x0000. Writing a 1 to the already set bit shall relinquish the lock and the set bit shall be cleared. Writing a 1 to an unset bit shall cancel the corresponding pending request if there was one, and the pairing bit in the Mutex_Request_Reg shall be cleared. */
#define REG_DEVICE2_GPHY_STRAP ((volatile APE_DEVICE2_H_uint32_t*)0xa0063664) /*  */
#define REG_DEVICE2_TOP_LEVEL_MISCELLANEOUS_CONTROL_1 ((volatile APE_DEVICE2_H_uint32_t*)0xa006367c) /*  */
#define REG_DEVICE2_EEE_MODE ((volatile APE_DEVICE2_H_uint32_t*)0xa00636b0) /*  */
#define REG_DEVICE2_EEE_LINK_IDLE_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa00636bc) /*  */
#define REG_DEVICE2_EEE_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa00636d0) /*  */
#define REG_DEVICE2_GLOBAL_MUTEX_REQUEST ((volatile APE_DEVICE2_H_uint32_t*)0xa00636f0) /*  */
#define REG_DEVICE2_GLOBAL_MUTEX_GRANT ((volatile APE_DEVICE2_H_uint32_t*)0xa00636f4) /*  */
#define REG_DEVICE2_MEMORY_ARBITER_MODE ((volatile APE_DEVICE2_H_uint32_t*)0xa0064000) /*  */
#define REG_DEVICE2_BUFFER_MANAGER_MODE ((volatile APE_DEVICE2_H_uint32_t*)0xa0064400) /*  */
#define REG_DEVICE2_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa0064910) /*  */
#define REG_DEVICE2_RX_RISC_MODE ((volatile APE_DEVICE2_H_uint32_t*)0xa0065000) /*  */
#define REG_DEVICE2_RX_RISC_STATUS ((volatile APE_DEVICE2_H_uint32_t*)0xa0065004) /*  */
#define REG_DEVICE2_RX_RISC_PROGRAM_COUNTER ((volatile APE_DEVICE2_H_uint32_t*)0xa006501c) /* The program counter register can be used to read or write the current Program Counter of the each CPU. Reads can occur at any time, however writes can only be performed when the CPU is halted. Writes will also clear any pending instruction in the decode stage of the pipeline. Bits 31-2 are implemented. 1s written to bits 1-0 are ignored. */
#define REG_DEVICE2_RX_RISC_CURRENT_INSTRUCTION ((volatile APE_DEVICE2_H_uint32_t*)0xa0065020) /* This undocumented register contains the current word located at the program counter address loaded in  */
#define REG_DEVICE2_RX_RISC_HARDWARE_BREAKPOINT ((volatile APE_DEVICE2_H_uint32_t*)0xa0065034) /* This register is used to set a hardware breakpoint based on the RISC's program counter (PC). If the PC equals the value in this register, and the hardware breakpoint is enabled, the RISC is halted and the appropriate stopping condition is indicated in the RISC State Register. To enable the hardware breakpoint, simply write the byte address of the instruction to break on and clear the Disable Hardware Breakpoint bit. */
#define REG_DEVICE2_RX_RISC_REGISTER_0 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065200) /* $zero (R0) */
#define REG_DEVICE2_RX_RISC_REGISTER_1 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065204) /* $at (R1) */
#define REG_DEVICE2_RX_RISC_REGISTER_2 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065208) /* $v0 (R2) */
#define REG_DEVICE2_RX_RISC_REGISTER_3 ((volatile APE_DEVICE2_H_uint32_t*)0xa006520c) /* $v1 (R3) */
#define REG_DEVICE2_RX_RISC_REGISTER_4 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065210) /* $a0 (R4) */
#define REG_DEVICE2_RX_RISC_REGISTER_5 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065214) /* $a1 (R5) */
#define REG_DEVICE2_RX_RISC_REGISTER_6 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065218) /* $a2 (R6) */
#define REG_DEVICE2_RX_RISC_REGISTER_7 ((volatile APE_DEVICE2_H_uint32_t*)0xa006521c) /* $a3 (R7) */
#define REG_DEVICE2_RX_RISC_REGISTER_8 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065220) /* $t0 (R8) */
#define REG_DEVICE2_RX_RISC_REGISTER_9 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065224) /* $t1 (R9) */
#define REG_DEVICE2_RX_RISC_REGISTER_10 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065228) /* $t2 (R10) */
#define REG_DEVICE2_RX_RISC_REGISTER_11 ((volatile APE_DEVICE2_H_uint32_t*)0xa006522c) /* $t3 (R11) */
#define REG_DEVICE2_RX_RISC_REGISTER_12 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065230) /* $t4 (R12) */
#define REG_DEVICE2_RX_RISC_REGISTER_13 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065234) /* $t5 (R13) */
#define REG_DEVICE2_RX_RISC_REGISTER_14 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065238) /* $t6 (R14) */
#define REG_DEVICE2_RX_RISC_REGISTER_15 ((volatile APE_DEVICE2_H_uint32_t*)0xa006523c) /* $t7 (R15) */
#define REG_DEVICE2_RX_RISC_REGISTER_16 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065240) /* $s0 (R16) */
#define REG_DEVICE2_RX_RISC_REGISTER_17 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065244) /* $s1 (R17) */
#define REG_DEVICE2_RX_RISC_REGISTER_18 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065248) /* $s2 (R18) */
#define REG_DEVICE2_RX_RISC_REGISTER_19 ((volatile APE_DEVICE2_H_uint32_t*)0xa006524c) /* $s3 (R19) */
#define REG_DEVICE2_RX_RISC_REGISTER_20 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065250) /* $s4 (R20) */
#define REG_DEVICE2_RX_RISC_REGISTER_21 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065254) /* $s5 (R21) */
#define REG_DEVICE2_RX_RISC_REGISTER_22 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065258) /* $s6 (R22) */
#define REG_DEVICE2_RX_RISC_REGISTER_23 ((volatile APE_DEVICE2_H_uint32_t*)0xa006525c) /* $s7 (R23) */
#define REG_DEVICE2_RX_RISC_REGISTER_24 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065260) /* $t8 (R24) */
#define REG_DEVICE2_RX_RISC_REGISTER_25 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065264) /* $t9 (R25) */
#define REG_DEVICE2_RX_RISC_REGISTER_26 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065268) /* $k0 (R26) */
#define REG_DEVICE2_RX_RISC_REGISTER_27 ((volatile APE_DEVICE2_H_uint32_t*)0xa006526c) /* $k1 (R27) */
#define REG_DEVICE2_RX_RISC_REGISTER_28 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065270) /* $gp (R28) */
#define REG_DEVICE2_RX_RISC_REGISTER_29 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065274) /* $sp (R29) */
#define REG_DEVICE2_RX_RISC_REGISTER_30 ((volatile APE_DEVICE2_H_uint32_t*)0xa0065278) /* $fp (R30) */
#define REG_DEVICE2_RX_RISC_REGISTER_31 ((volatile APE_DEVICE2_H_uint32_t*)0xa006527c) /* $ra (R31) */
#define REG_DEVICE2_6408 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066408) /*  */
#define REG_DEVICE2_PCI_POWER_CONSUMPTION_INFO ((volatile APE_DEVICE2_H_uint32_t*)0xa0066410) /* This undocumented register is used to set PCIe Power Consumption information as reported in configuration space. It is loaded from NVM configuration data. */
#define REG_DEVICE2_PCI_POWER_DISSIPATED_INFO ((volatile APE_DEVICE2_H_uint32_t*)0xa0066414) /* This undocumented register is used to set PCIe Power Dissipated information as reported in configuration space. It is loaded from NVM configuration data. */
#define REG_DEVICE2_PCI_VPD_REQUEST ((volatile APE_DEVICE2_H_uint32_t*)0xa006642c) /* This undocumented register appears to be used to implement the PCI VPD capability. It is set to the VPD offset which was requested by the host by writing to the VPD register. */
#define REG_DEVICE2_PCI_VPD_RESPONSE ((volatile APE_DEVICE2_H_uint32_t*)0xa0066430) /* This undocumented register appears to be used to implement the PCI VPD capability. Bootcode writes the 32 bits of data loaded from the word requested by  */
#define REG_DEVICE2_PCI_VENDOR_DEVICE_ID ((volatile APE_DEVICE2_H_uint32_t*)0xa0066434) /* This is the undocumented register used to set the PCI Vendor/Device ID, which is configurable from NVM. */
#define REG_DEVICE2_PCI_SUBSYSTEM_ID ((volatile APE_DEVICE2_H_uint32_t*)0xa0066438) /* This is the undocumented register used to set the PCI Subsystem/Subsystem Vendor ID, which is configurable from NVM. */
#define REG_DEVICE2_PCI_CLASS_CODE_REVISION ((volatile APE_DEVICE2_H_uint32_t*)0xa006643c) /* This undocumented register is suspected to set the class code and device revision in PCI configuration space. Unconfirmed. */
#define REG_DEVICE2_64C0 ((volatile APE_DEVICE2_H_uint32_t*)0xa00664c0) /*  */
#define REG_DEVICE2_64C8 ((volatile APE_DEVICE2_H_uint32_t*)0xa00664c8) /*  */
#define REG_DEVICE2_64DC ((volatile APE_DEVICE2_H_uint32_t*)0xa00664dc) /*  */
#define REG_DEVICE2_PCI_SERIAL_NUMBER_LOW ((volatile APE_DEVICE2_H_uint32_t*)0xa0066504) /* This sets the low 32 bits of the 64-bit device serial number, which isexposed as a PCIe capability in configuration space. */
#define REG_DEVICE2_PCI_SERIAL_NUMBER_HIGH ((volatile APE_DEVICE2_H_uint32_t*)0xa0066508) /* This sets the high 32 bits of the 64-bit device serial number, which isexposed as a PCIe capability in configuration space. */
#define REG_DEVICE2_PCI_POWER_BUDGET_0 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066510) /* Used to report power budget capability data to the host. The values are loaded from NVM, and up to eight values may be specified.  */
#define REG_DEVICE2_PCI_POWER_BUDGET_1 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066514) /* See  */
#define REG_DEVICE2_PCI_POWER_BUDGET_2 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066518) /* See  */
#define REG_DEVICE2_PCI_POWER_BUDGET_3 ((volatile APE_DEVICE2_H_uint32_t*)0xa006651c) /* See  */
#define REG_DEVICE2_PCI_POWER_BUDGET_4 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066520) /* See  */
#define REG_DEVICE2_PCI_POWER_BUDGET_5 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066524) /* See  */
#define REG_DEVICE2_PCI_POWER_BUDGET_6 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066528) /* See  */
#define REG_DEVICE2_PCI_POWER_BUDGET_7 ((volatile APE_DEVICE2_H_uint32_t*)0xa006652c) /* See  */
#define REG_DEVICE2_6530 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066530) /*  */
#define REG_DEVICE2_6550 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066550) /* The LSB in this undocumented and unknown register is set if the device is a LOM (LAN-on-Motherboard) design (i.e., builtin to a system and not an expansion card). */
#define REG_DEVICE2_65F4 ((volatile APE_DEVICE2_H_uint32_t*)0xa00665f4) /*  */
#define REG_DEVICE2_GRC_MODE_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa0066800) /*  */
#define REG_DEVICE2_MISCELLANEOUS_CONFIG ((volatile APE_DEVICE2_H_uint32_t*)0xa0066804) /*  */
#define REG_DEVICE2_MISCELLANEOUS_LOCAL_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa0066808) /*  */
#define REG_DEVICE2_TIMER ((volatile APE_DEVICE2_H_uint32_t*)0xa006680c) /* 32-bit free-running counter */
#define REG_DEVICE2_RX_CPU_EVENT ((volatile APE_DEVICE2_H_uint32_t*)0xa0066810) /*  */
#define REG_DEVICE2_6838 ((volatile APE_DEVICE2_H_uint32_t*)0xa0066838) /* Unknown. Used by PXE agent. */
#define REG_DEVICE2_MDI_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa0066844) /* The register manual only mentions this in the changelog; it was removed from the manual in a previous revision. :| */
#define REG_DEVICE2_RX_CPU_EVENT_ENABLE ((volatile APE_DEVICE2_H_uint32_t*)0xa006684c) /*  */
#define REG_DEVICE2_FAST_BOOT_PROGRAM_COUNTER ((volatile APE_DEVICE2_H_uint32_t*)0xa0066894) /*  */
#define REG_DEVICE2_EXPANSION_ROM_ADDR ((volatile APE_DEVICE2_H_uint32_t*)0xa00668ec) /* Expansion ROM base address, expect to be d- word aligned. */
#define REG_DEVICE2_68F0 ((volatile APE_DEVICE2_H_uint32_t*)0xa00668f0) /*  */
#define REG_DEVICE2_EAV_REF_CLOCK_CONTROL ((volatile APE_DEVICE2_H_uint32_t*)0xa0066908) /*  */
#define REG_DEVICE2_7C04 ((volatile APE_DEVICE2_H_uint32_t*)0xa0067c04) /* PCIe-related. tg3 driver calls this  */
/** @brief Device Registers, function 2 */
extern volatile DEVICE_t DEVICE2;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_DEVICE2_H */

/** @} */
