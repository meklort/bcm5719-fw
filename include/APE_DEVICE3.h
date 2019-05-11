////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_DEVICE3.h
///
/// @project    ape
///
/// @brief      APE_DEVICE3
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

/** @defgroup APE_DEVICE3_H    APE_DEVICE3 */
/** @addtogroup APE_DEVICE3_H
 * @{
 */
#ifndef APE_DEVICE3_H
#define APE_DEVICE3_H

#include <types.h>
#include "APE_DEVICE.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_DEVICE3_sim(void* base);
void init_APE_DEVICE3(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_DEVICE3_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_DEVICE3_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_DEVICE3_H_uint32_t;
#define APE_DEVICE3_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_DEVICE3_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_DEVICE3_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_DEVICE3_H_uint8_t;
typedef uint16_t APE_DEVICE3_H_uint16_t;
typedef uint32_t APE_DEVICE3_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_DEVICE3_BASE ((volatile void*)0xa0070000) /* Device Registers, function 3 */
#define REG_DEVICE3_SIZE (sizeof(DEVICE_t))

#define REG_DEVICE3_MISCELLANEOUS_HOST_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa0070068) /*  */
#define REG_DEVICE3_PCI_STATE ((volatile APE_DEVICE3_H_uint32_t*)0xa0070070) /*  */
#define REG_DEVICE3_REGISTER_BASE ((volatile APE_DEVICE3_H_uint32_t*)0xa0070078) /* Local controller memory address of a register than can be written or read by writing to the register data register. */
#define REG_DEVICE3_MEMORY_BASE ((volatile APE_DEVICE3_H_uint32_t*)0xa007007c) /* Local controller memory address of the NIC memory region that can be accessed via Memory Window data register. */
#define REG_DEVICE3_REGISTER_DATA ((volatile APE_DEVICE3_H_uint32_t*)0xa0070080) /* Register Data at the location pointed by the Register Base Register. */
#define REG_DEVICE3_UNDI_RECEIVE_RETURN_RING_CONSUMER_INDEX ((volatile APE_DEVICE3_H_uint32_t*)0xa0070088) /* UNDI Receive Return Ring Consumer Index Mailbox */
#define REG_DEVICE3_UNDI_RECEIVE_RETURN_RING_CONSUMER_INDEX_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa007008c) /* UNDI Receive Return Ring Consumer Index Mailbox */
#define REG_DEVICE3_LINK_STATUS_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa00700bc) /* PCIe standard register. */
#define REG_DEVICE3_APE_MEMORY_BASE ((volatile APE_DEVICE3_H_uint32_t*)0xa00700f8) /* APE Memory address to read/write using the APE Memory Data register.. */
#define REG_DEVICE3_APE_MEMORY_DATA ((volatile APE_DEVICE3_H_uint32_t*)0xa00700fc) /* APE Memory value at the location pointed by the Memory Base Register. */
#define REG_DEVICE3_EMAC_MODE ((volatile APE_DEVICE3_H_uint32_t*)0xa0070400) /*  */
#define REG_DEVICE3_LED_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa007040c) /*  */
#define REG_DEVICE3_EMAC_MAC_ADDRESSES_0_HIGH ((volatile APE_DEVICE3_H_uint32_t*)0xa0070410) /* Upper 2-bytes of this node's MAC address. */
#define REG_DEVICE3_EMAC_MAC_ADDRESSES_0_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa0070414) /* Lower 4-byte of this node's MAC address. */
#define REG_DEVICE3_EMAC_MAC_ADDRESSES_1_HIGH ((volatile APE_DEVICE3_H_uint32_t*)0xa0070418) /* Upper 2-bytes of this node's MAC address. */
#define REG_DEVICE3_EMAC_MAC_ADDRESSES_1_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa007041c) /* Lower 4-byte of this node's MAC address. */
#define REG_DEVICE3_EMAC_MAC_ADDRESSES_2_HIGH ((volatile APE_DEVICE3_H_uint32_t*)0xa0070420) /* Upper 2-bytes of this node's MAC address. */
#define REG_DEVICE3_EMAC_MAC_ADDRESSES_2_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa0070424) /* Lower 4-byte of this node's MAC address. */
#define REG_DEVICE3_EMAC_MAC_ADDRESSES_3_HIGH ((volatile APE_DEVICE3_H_uint32_t*)0xa0070428) /* Upper 2-bytes of this node's MAC address. */
#define REG_DEVICE3_EMAC_MAC_ADDRESSES_3_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa007042c) /* Lower 4-byte of this node's MAC address. */
#define REG_DEVICE3_WOL_PATTERN_POINTER ((volatile APE_DEVICE3_H_uint32_t*)0xa0070430) /* Specifies the offset into the 6KB BD memory for frame comparison. (Bits 3:0 are ignored to align the memory address to a natural 128-bit boundary). */
#define REG_DEVICE3_WOL_PATTERN_CFG ((volatile APE_DEVICE3_H_uint32_t*)0xa0070434) /*  */
#define REG_DEVICE3_MTU_SIZE ((volatile APE_DEVICE3_H_uint32_t*)0xa007043c) /* 2-byte field which is the largest size frame that will be accepted without being marked as oversize. */
#define REG_DEVICE3_MII_COMMUNICATION ((volatile APE_DEVICE3_H_uint32_t*)0xa007044c) /*  */
#define REG_DEVICE3_MII_MODE ((volatile APE_DEVICE3_H_uint32_t*)0xa0070454) /*  */
#define REG_DEVICE3_TRANSMIT_MAC_MODE ((volatile APE_DEVICE3_H_uint32_t*)0xa007045c) /*  */
#define REG_DEVICE3_RECEIVE_MAC_MODE ((volatile APE_DEVICE3_H_uint32_t*)0xa0070468) /*  */
#define REG_DEVICE3_PERFECT_MATCH1_HIGH ((volatile APE_DEVICE3_H_uint32_t*)0xa0070540) /*  */
#define REG_DEVICE3_PERFECT_MATCH1_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa0070544) /*  */
#define REG_DEVICE3_PERFECT_MATCH2_HIGH ((volatile APE_DEVICE3_H_uint32_t*)0xa0070548) /*  */
#define REG_DEVICE3_PERFECT_MATCH2_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa007054c) /*  */
#define REG_DEVICE3_PERFECT_MATCH3_HIGH ((volatile APE_DEVICE3_H_uint32_t*)0xa0070550) /*  */
#define REG_DEVICE3_PERFECT_MATCH3_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa0070554) /*  */
#define REG_DEVICE3_PERFECT_MATCH4_HIGH ((volatile APE_DEVICE3_H_uint32_t*)0xa0070558) /*  */
#define REG_DEVICE3_PERFECT_MATCH4_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa007055c) /*  */
#define REG_DEVICE3_SGMII_STATUS ((volatile APE_DEVICE3_H_uint32_t*)0xa00705b4) /* This register reflects various status of the respective SGMII port when enabled. */
#define REG_DEVICE3_CPMU_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa0073600) /*  */
#define REG_DEVICE3_LINK_AWARE_POWER_MODE_CLOCK_POLICY ((volatile APE_DEVICE3_H_uint32_t*)0xa0073610) /*  */
#define REG_DEVICE3_CLOCK_SPEED_OVERRIDE_POLICY ((volatile APE_DEVICE3_H_uint32_t*)0xa0073624) /*  */
#define REG_DEVICE3_STATUS ((volatile APE_DEVICE3_H_uint32_t*)0xa007362c) /*  */
#define REG_DEVICE3_CLOCK_STATUS ((volatile APE_DEVICE3_H_uint32_t*)0xa0073630) /*  */
#define REG_DEVICE3_GPHY_CONTROL_STATUS ((volatile APE_DEVICE3_H_uint32_t*)0xa0073638) /*  */
#define REG_DEVICE3_CHIP_ID ((volatile APE_DEVICE3_H_uint32_t*)0xa0073658) /*  */
#define REG_DEVICE3_MUTEX_REQUEST ((volatile APE_DEVICE3_H_uint32_t*)0xa007365c) /* Writing a 1 to any of these bits pends a Mutex lock request on behalf of a software agent. The bit is subsequently latched by hardware and shall read 1 as long as the request is pending. Writing a 0 to a bit shall have no effect. */
#define REG_DEVICE3_MUTEX_GRANT ((volatile APE_DEVICE3_H_uint32_t*)0xa0073660) /* Reading this field shall return a maximum of one set bit at any time. The set bit shall point to the lock owner. If the Mutex is not locked, then a read shall return a value 0x0000. Writing a 1 to the already set bit shall relinquish the lock and the set bit shall be cleared. Writing a 1 to an unset bit shall cancel the corresponding pending request if there was one, and the pairing bit in the Mutex_Request_Reg shall be cleared. */
#define REG_DEVICE3_GPHY_STRAP ((volatile APE_DEVICE3_H_uint32_t*)0xa0073664) /*  */
#define REG_DEVICE3_TOP_LEVEL_MISCELLANEOUS_CONTROL_1 ((volatile APE_DEVICE3_H_uint32_t*)0xa007367c) /*  */
#define REG_DEVICE3_EEE_MODE ((volatile APE_DEVICE3_H_uint32_t*)0xa00736b0) /*  */
#define REG_DEVICE3_EEE_LINK_IDLE_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa00736bc) /*  */
#define REG_DEVICE3_EEE_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa00736d0) /*  */
#define REG_DEVICE3_GLOBAL_MUTEX_REQUEST ((volatile APE_DEVICE3_H_uint32_t*)0xa00736f0) /*  */
#define REG_DEVICE3_GLOBAL_MUTEX_GRANT ((volatile APE_DEVICE3_H_uint32_t*)0xa00736f4) /*  */
#define REG_DEVICE3_MEMORY_ARBITER_MODE ((volatile APE_DEVICE3_H_uint32_t*)0xa0074000) /*  */
#define REG_DEVICE3_BUFFER_MANAGER_MODE ((volatile APE_DEVICE3_H_uint32_t*)0xa0074400) /*  */
#define REG_DEVICE3_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa0074910) /*  */
#define REG_DEVICE3_RX_RISC_MODE ((volatile APE_DEVICE3_H_uint32_t*)0xa0075000) /*  */
#define REG_DEVICE3_RX_RISC_STATUS ((volatile APE_DEVICE3_H_uint32_t*)0xa0075004) /*  */
#define REG_DEVICE3_RX_RISC_PROGRAM_COUNTER ((volatile APE_DEVICE3_H_uint32_t*)0xa007501c) /* The program counter register can be used to read or write the current Program Counter of the each CPU. Reads can occur at any time, however writes can only be performed when the CPU is halted. Writes will also clear any pending instruction in the decode stage of the pipeline. Bits 31-2 are implemented. 1s written to bits 1-0 are ignored. */
#define REG_DEVICE3_RX_RISC_CURRENT_INSTRUCTION ((volatile APE_DEVICE3_H_uint32_t*)0xa0075020) /* This undocumented register contains the current word located at the program counter address loaded in  */
#define REG_DEVICE3_RX_RISC_HARDWARE_BREAKPOINT ((volatile APE_DEVICE3_H_uint32_t*)0xa0075034) /* This register is used to set a hardware breakpoint based on the RISC's program counter (PC). If the PC equals the value in this register, and the hardware breakpoint is enabled, the RISC is halted and the appropriate stopping condition is indicated in the RISC State Register. To enable the hardware breakpoint, simply write the byte address of the instruction to break on and clear the Disable Hardware Breakpoint bit. */
#define REG_DEVICE3_RX_RISC_REGISTER_0 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075200) /* $zero (R0) */
#define REG_DEVICE3_RX_RISC_REGISTER_1 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075204) /* $at (R1) */
#define REG_DEVICE3_RX_RISC_REGISTER_2 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075208) /* $v0 (R2) */
#define REG_DEVICE3_RX_RISC_REGISTER_3 ((volatile APE_DEVICE3_H_uint32_t*)0xa007520c) /* $v1 (R3) */
#define REG_DEVICE3_RX_RISC_REGISTER_4 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075210) /* $a0 (R4) */
#define REG_DEVICE3_RX_RISC_REGISTER_5 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075214) /* $a1 (R5) */
#define REG_DEVICE3_RX_RISC_REGISTER_6 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075218) /* $a2 (R6) */
#define REG_DEVICE3_RX_RISC_REGISTER_7 ((volatile APE_DEVICE3_H_uint32_t*)0xa007521c) /* $a3 (R7) */
#define REG_DEVICE3_RX_RISC_REGISTER_8 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075220) /* $t0 (R8) */
#define REG_DEVICE3_RX_RISC_REGISTER_9 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075224) /* $t1 (R9) */
#define REG_DEVICE3_RX_RISC_REGISTER_10 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075228) /* $t2 (R10) */
#define REG_DEVICE3_RX_RISC_REGISTER_11 ((volatile APE_DEVICE3_H_uint32_t*)0xa007522c) /* $t3 (R11) */
#define REG_DEVICE3_RX_RISC_REGISTER_12 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075230) /* $t4 (R12) */
#define REG_DEVICE3_RX_RISC_REGISTER_13 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075234) /* $t5 (R13) */
#define REG_DEVICE3_RX_RISC_REGISTER_14 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075238) /* $t6 (R14) */
#define REG_DEVICE3_RX_RISC_REGISTER_15 ((volatile APE_DEVICE3_H_uint32_t*)0xa007523c) /* $t7 (R15) */
#define REG_DEVICE3_RX_RISC_REGISTER_16 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075240) /* $s0 (R16) */
#define REG_DEVICE3_RX_RISC_REGISTER_17 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075244) /* $s1 (R17) */
#define REG_DEVICE3_RX_RISC_REGISTER_18 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075248) /* $s2 (R18) */
#define REG_DEVICE3_RX_RISC_REGISTER_19 ((volatile APE_DEVICE3_H_uint32_t*)0xa007524c) /* $s3 (R19) */
#define REG_DEVICE3_RX_RISC_REGISTER_20 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075250) /* $s4 (R20) */
#define REG_DEVICE3_RX_RISC_REGISTER_21 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075254) /* $s5 (R21) */
#define REG_DEVICE3_RX_RISC_REGISTER_22 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075258) /* $s6 (R22) */
#define REG_DEVICE3_RX_RISC_REGISTER_23 ((volatile APE_DEVICE3_H_uint32_t*)0xa007525c) /* $s7 (R23) */
#define REG_DEVICE3_RX_RISC_REGISTER_24 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075260) /* $t8 (R24) */
#define REG_DEVICE3_RX_RISC_REGISTER_25 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075264) /* $t9 (R25) */
#define REG_DEVICE3_RX_RISC_REGISTER_26 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075268) /* $k0 (R26) */
#define REG_DEVICE3_RX_RISC_REGISTER_27 ((volatile APE_DEVICE3_H_uint32_t*)0xa007526c) /* $k1 (R27) */
#define REG_DEVICE3_RX_RISC_REGISTER_28 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075270) /* $gp (R28) */
#define REG_DEVICE3_RX_RISC_REGISTER_29 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075274) /* $sp (R29) */
#define REG_DEVICE3_RX_RISC_REGISTER_30 ((volatile APE_DEVICE3_H_uint32_t*)0xa0075278) /* $fp (R30) */
#define REG_DEVICE3_RX_RISC_REGISTER_31 ((volatile APE_DEVICE3_H_uint32_t*)0xa007527c) /* $ra (R31) */
#define REG_DEVICE3_6408 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076408) /*  */
#define REG_DEVICE3_PCI_POWER_CONSUMPTION_INFO ((volatile APE_DEVICE3_H_uint32_t*)0xa0076410) /* This undocumented register is used to set PCIe Power Consumption information as reported in configuration space. It is loaded from NVM configuration data. */
#define REG_DEVICE3_PCI_POWER_DISSIPATED_INFO ((volatile APE_DEVICE3_H_uint32_t*)0xa0076414) /* This undocumented register is used to set PCIe Power Dissipated information as reported in configuration space. It is loaded from NVM configuration data. */
#define REG_DEVICE3_PCI_VPD_REQUEST ((volatile APE_DEVICE3_H_uint32_t*)0xa007642c) /* This undocumented register appears to be used to implement the PCI VPD capability. It is set to the VPD offset which was requested by the host by writing to the VPD register. */
#define REG_DEVICE3_PCI_VPD_RESPONSE ((volatile APE_DEVICE3_H_uint32_t*)0xa0076430) /* This undocumented register appears to be used to implement the PCI VPD capability. Bootcode writes the 32 bits of data loaded from the word requested by  */
#define REG_DEVICE3_PCI_VENDOR_DEVICE_ID ((volatile APE_DEVICE3_H_uint32_t*)0xa0076434) /* This is the undocumented register used to set the PCI Vendor/Device ID, which is configurable from NVM. */
#define REG_DEVICE3_PCI_SUBSYSTEM_ID ((volatile APE_DEVICE3_H_uint32_t*)0xa0076438) /* This is the undocumented register used to set the PCI Subsystem/Subsystem Vendor ID, which is configurable from NVM. */
#define REG_DEVICE3_PCI_CLASS_CODE_REVISION ((volatile APE_DEVICE3_H_uint32_t*)0xa007643c) /* This undocumented register is suspected to set the class code and device revision in PCI configuration space. Unconfirmed. */
#define REG_DEVICE3_64C0 ((volatile APE_DEVICE3_H_uint32_t*)0xa00764c0) /*  */
#define REG_DEVICE3_64C8 ((volatile APE_DEVICE3_H_uint32_t*)0xa00764c8) /*  */
#define REG_DEVICE3_64DC ((volatile APE_DEVICE3_H_uint32_t*)0xa00764dc) /*  */
#define REG_DEVICE3_PCI_SERIAL_NUMBER_LOW ((volatile APE_DEVICE3_H_uint32_t*)0xa0076504) /* This sets the low 32 bits of the 64-bit device serial number, which isexposed as a PCIe capability in configuration space. */
#define REG_DEVICE3_PCI_SERIAL_NUMBER_HIGH ((volatile APE_DEVICE3_H_uint32_t*)0xa0076508) /* This sets the high 32 bits of the 64-bit device serial number, which isexposed as a PCIe capability in configuration space. */
#define REG_DEVICE3_PCI_POWER_BUDGET_0 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076510) /* Used to report power budget capability data to the host. The values are loaded from NVM, and up to eight values may be specified.  */
#define REG_DEVICE3_PCI_POWER_BUDGET_1 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076514) /* See  */
#define REG_DEVICE3_PCI_POWER_BUDGET_2 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076518) /* See  */
#define REG_DEVICE3_PCI_POWER_BUDGET_3 ((volatile APE_DEVICE3_H_uint32_t*)0xa007651c) /* See  */
#define REG_DEVICE3_PCI_POWER_BUDGET_4 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076520) /* See  */
#define REG_DEVICE3_PCI_POWER_BUDGET_5 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076524) /* See  */
#define REG_DEVICE3_PCI_POWER_BUDGET_6 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076528) /* See  */
#define REG_DEVICE3_PCI_POWER_BUDGET_7 ((volatile APE_DEVICE3_H_uint32_t*)0xa007652c) /* See  */
#define REG_DEVICE3_6530 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076530) /*  */
#define REG_DEVICE3_6550 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076550) /* The LSB in this undocumented and unknown register is set if the device is a LOM (LAN-on-Motherboard) design (i.e., builtin to a system and not an expansion card). */
#define REG_DEVICE3_65F4 ((volatile APE_DEVICE3_H_uint32_t*)0xa00765f4) /*  */
#define REG_DEVICE3_GRC_MODE_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa0076800) /*  */
#define REG_DEVICE3_MISCELLANEOUS_CONFIG ((volatile APE_DEVICE3_H_uint32_t*)0xa0076804) /*  */
#define REG_DEVICE3_MISCELLANEOUS_LOCAL_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa0076808) /*  */
#define REG_DEVICE3_TIMER ((volatile APE_DEVICE3_H_uint32_t*)0xa007680c) /* 32-bit free-running counter */
#define REG_DEVICE3_RX_CPU_EVENT ((volatile APE_DEVICE3_H_uint32_t*)0xa0076810) /*  */
#define REG_DEVICE3_6838 ((volatile APE_DEVICE3_H_uint32_t*)0xa0076838) /* Unknown. Used by PXE agent. */
#define REG_DEVICE3_MDI_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa0076844) /* The register manual only mentions this in the changelog; it was removed from the manual in a previous revision. :| */
#define REG_DEVICE3_RX_CPU_EVENT_ENABLE ((volatile APE_DEVICE3_H_uint32_t*)0xa007684c) /*  */
#define REG_DEVICE3_FAST_BOOT_PROGRAM_COUNTER ((volatile APE_DEVICE3_H_uint32_t*)0xa0076894) /*  */
#define REG_DEVICE3_EXPANSION_ROM_ADDR ((volatile APE_DEVICE3_H_uint32_t*)0xa00768ec) /* Expansion ROM base address, expect to be d- word aligned. */
#define REG_DEVICE3_68F0 ((volatile APE_DEVICE3_H_uint32_t*)0xa00768f0) /*  */
#define REG_DEVICE3_EAV_REF_CLOCK_CONTROL ((volatile APE_DEVICE3_H_uint32_t*)0xa0076908) /*  */
#define REG_DEVICE3_7C04 ((volatile APE_DEVICE3_H_uint32_t*)0xa0077c04) /* PCIe-related. tg3 driver calls this  */
/** @brief Device Registers, function 3 */
extern volatile DEVICE_t DEVICE3;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_DEVICE3_H */

/** @} */
