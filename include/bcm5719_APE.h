////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_APE.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_APE
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

/** @defgroup BCM5719_APE_H    bcm5719_APE */
/** @addtogroup BCM5719_APE_H
 * @{
 */
#ifndef BCM5719_APE_H
#define BCM5719_APE_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_APE_sim(void* base);
void init_bcm5719_APE(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_APE_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_APE_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_APE_H_uint32_t;
#define BCM5719_APE_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_APE_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_APE_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_APE_H_uint8_t;
typedef uint16_t BCM5719_APE_H_uint16_t;
typedef uint32_t BCM5719_APE_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_APE_BASE ((volatile void*)0xc0010000) /* Device APE Registers */
#define REG_APE_SIZE (sizeof(APE_t))

#define REG_APE_MODE ((volatile BCM5719_APE_H_uint32_t*)0xc0010000) /* More of these bits can be found in diagnostic utilities, but they don't seem too interesting. */
#define     APE_MODE_RESET_SHIFT 0u
#define     APE_MODE_RESET_MASK  0x1u
#define GET_APE_MODE_RESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_MODE_RESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_MODE_HALT_SHIFT 1u
#define     APE_MODE_HALT_MASK  0x2u
#define GET_APE_MODE_HALT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_MODE_HALT(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_MODE_FAST_BOOT_SHIFT 2u
#define     APE_MODE_FAST_BOOT_MASK  0x4u
#define GET_APE_MODE_FAST_BOOT(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_MODE_FAST_BOOT(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_MODE_HOST_DIAG_SHIFT 3u
#define     APE_MODE_HOST_DIAG_MASK  0x8u
#define GET_APE_MODE_HOST_DIAG(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_MODE_HOST_DIAG(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_MODE_EVENT_1_SHIFT 5u
#define     APE_MODE_EVENT_1_MASK  0x20u
#define GET_APE_MODE_EVENT_1(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_MODE_EVENT_1(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_MODE_EVENT_2_SHIFT 6u
#define     APE_MODE_EVENT_2_MASK  0x40u
#define GET_APE_MODE_EVENT_2(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_MODE_EVENT_2(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_MODE_GRCINT_SHIFT 7u
#define     APE_MODE_GRCINT_MASK  0x80u
#define GET_APE_MODE_GRCINT(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_APE_MODE_GRCINT(__val__)  (((__val__) << 7u) & 0x80u)
#define     APE_MODE_SWAP_ATB_DWORD_SHIFT 9u
#define     APE_MODE_SWAP_ATB_DWORD_MASK  0x200u
#define GET_APE_MODE_SWAP_ATB_DWORD(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_MODE_SWAP_ATB_DWORD(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_MODE_SWAP_ARB_DWORD_SHIFT 11u
#define     APE_MODE_SWAP_ARB_DWORD_MASK  0x800u
#define GET_APE_MODE_SWAP_ARB_DWORD(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_APE_MODE_SWAP_ARB_DWORD(__val__)  (((__val__) << 11u) & 0x800u)
#define     APE_MODE_CHANNEL_0_ENABLE_SHIFT 14u
#define     APE_MODE_CHANNEL_0_ENABLE_MASK  0x4000u
#define GET_APE_MODE_CHANNEL_0_ENABLE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_APE_MODE_CHANNEL_0_ENABLE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     APE_MODE_CHANNEL_2_ENABLE_SHIFT 15u
#define     APE_MODE_CHANNEL_2_ENABLE_MASK  0x8000u
#define GET_APE_MODE_CHANNEL_2_ENABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_APE_MODE_CHANNEL_2_ENABLE(__val__)  (((__val__) << 15u) & 0x8000u)
#define     APE_MODE_MEMORY_ECC_SHIFT 18u
#define     APE_MODE_MEMORY_ECC_MASK  0x40000u
#define GET_APE_MODE_MEMORY_ECC(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_APE_MODE_MEMORY_ECC(__val__)  (((__val__) << 18u) & 0x40000u)
#define     APE_MODE_ICODE_PIP_RD_DISABLE_SHIFT 19u
#define     APE_MODE_ICODE_PIP_RD_DISABLE_MASK  0x80000u
#define GET_APE_MODE_ICODE_PIP_RD_DISABLE(__reg__)  (((__reg__) & 0x80000) >> 19u)
#define SET_APE_MODE_ICODE_PIP_RD_DISABLE(__val__)  (((__val__) << 19u) & 0x80000u)
#define     APE_MODE_CHANNEL_1_ENABLE_SHIFT 30u
#define     APE_MODE_CHANNEL_1_ENABLE_MASK  0x40000000u
#define GET_APE_MODE_CHANNEL_1_ENABLE(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_APE_MODE_CHANNEL_1_ENABLE(__val__)  (((__val__) << 30u) & 0x40000000u)
#define     APE_MODE_CHANNEL_3_ENABLE_SHIFT 31u
#define     APE_MODE_CHANNEL_3_ENABLE_MASK  0x80000000u
#define GET_APE_MODE_CHANNEL_3_ENABLE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_APE_MODE_CHANNEL_3_ENABLE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref APE_t.Mode. */
typedef register_container RegAPEMode_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Used to reset the APE block. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Reset, 0, 1)
        /** @brief APE is halted if set. Setting then unsetting this bit resets the APE to its reset vector, etc. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halt, 1, 1)
        /** @brief Can be used to boot from RAM instead of NVM. Takes a full APE image with section headers, etc. so you still need to form a proper image. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FastBoot, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, HostDiag, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_4_4, 4, 1)
        /** @brief Used to signal the APE that an event from the host is ready for processing in SHM. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Event1, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Event2, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, GRCint, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_8_8, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, SwapATBdword, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_10_10, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, SwapARBdword, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_13_12, 12, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel0Enable, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel2Enable, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_17_16, 16, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, MemoryECC, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ICodePIPRdDisable, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_29_20, 20, 10)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel1Enable, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel3Enable, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel3Enable, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel1Enable, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_29_20, 20, 10)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ICodePIPRdDisable, 19, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, MemoryECC, 18, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_17_16, 16, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel2Enable, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel0Enable, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_13_12, 12, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, SwapARBdword, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_10_10, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, SwapATBdword, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_8_8, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, GRCint, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Event2, 6, 1)
        /** @brief Used to signal the APE that an event from the host is ready for processing in SHM. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Event1, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_4_4, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, HostDiag, 3, 1)
        /** @brief Can be used to boot from RAM instead of NVM. Takes a full APE image with section headers, etc. so you still need to form a proper image. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FastBoot, 2, 1)
        /** @brief APE is halted if set. Setting then unsetting this bit resets the APE to its reset vector, etc. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halt, 1, 1)
        /** @brief Used to reset the APE block. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Reset, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Mode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEMode_t()
    {
        /** @brief constructor for @ref APE_t.Mode. */
        r32.setName("Mode");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.FastBoot.setBaseRegister(&r32);
        bits.FastBoot.setName("FastBoot");
        bits.HostDiag.setBaseRegister(&r32);
        bits.HostDiag.setName("HostDiag");
        bits.Event1.setBaseRegister(&r32);
        bits.Event1.setName("Event1");
        bits.Event2.setBaseRegister(&r32);
        bits.Event2.setName("Event2");
        bits.GRCint.setBaseRegister(&r32);
        bits.GRCint.setName("GRCint");
        bits.SwapATBdword.setBaseRegister(&r32);
        bits.SwapATBdword.setName("SwapATBdword");
        bits.SwapARBdword.setBaseRegister(&r32);
        bits.SwapARBdword.setName("SwapARBdword");
        bits.Channel0Enable.setBaseRegister(&r32);
        bits.Channel0Enable.setName("Channel0Enable");
        bits.Channel2Enable.setBaseRegister(&r32);
        bits.Channel2Enable.setName("Channel2Enable");
        bits.MemoryECC.setBaseRegister(&r32);
        bits.MemoryECC.setName("MemoryECC");
        bits.ICodePIPRdDisable.setBaseRegister(&r32);
        bits.ICodePIPRdDisable.setName("ICodePIPRdDisable");
        bits.Channel1Enable.setBaseRegister(&r32);
        bits.Channel1Enable.setName("Channel1Enable");
        bits.Channel3Enable.setBaseRegister(&r32);
        bits.Channel3Enable.setName("Channel3Enable");
    }
    RegAPEMode_t& operator=(const RegAPEMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEMode_t;

#define REG_APE_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc0010004) /*  */
#define     APE_STATUS_PCIE_RESET_SHIFT 0u
#define     APE_STATUS_PCIE_RESET_MASK  0x1u
#define GET_APE_STATUS_PCIE_RESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_STATUS_PCIE_RESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_STATUS_NVRAM_CONTROL_RESET_SHIFT 3u
#define     APE_STATUS_NVRAM_CONTROL_RESET_MASK  0x8u
#define GET_APE_STATUS_NVRAM_CONTROL_RESET(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_STATUS_NVRAM_CONTROL_RESET(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_STATUS_LAN_0_DSTATE_SHIFT 4u
#define     APE_STATUS_LAN_0_DSTATE_MASK  0x10u
#define GET_APE_STATUS_LAN_0_DSTATE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_STATUS_LAN_0_DSTATE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_STATUS_BOOT_MODE_SHIFT 5u
#define     APE_STATUS_BOOT_MODE_MASK  0x20u
#define GET_APE_STATUS_BOOT_MODE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_STATUS_BOOT_MODE(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_STATUS_BOOT_MODE_NVRAM 0x0u
#define     APE_STATUS_BOOT_MODE_FAST 0x1u

#define     APE_STATUS_LAN_1_DSTATE_SHIFT 9u
#define     APE_STATUS_LAN_1_DSTATE_MASK  0x200u
#define GET_APE_STATUS_LAN_1_DSTATE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_STATUS_LAN_1_DSTATE(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_STATUS_BOOT_STATUS_B_SHIFT 24u
#define     APE_STATUS_BOOT_STATUS_B_MASK  0xf000000u
#define GET_APE_STATUS_BOOT_STATUS_B(__reg__)  (((__reg__) & 0xf000000) >> 24u)
#define SET_APE_STATUS_BOOT_STATUS_B(__val__)  (((__val__) << 24u) & 0xf000000u)
#define     APE_STATUS_BOOT_STATUS_B_PROG_0 0x0u
#define     APE_STATUS_BOOT_STATUS_B_PROG_1 0x1u
#define     APE_STATUS_BOOT_STATUS_B_BPC_ENTER 0x2u
#define     APE_STATUS_BOOT_STATUS_B_DECODE 0x3u
#define     APE_STATUS_BOOT_STATUS_B_READ_NVRAM_HEADER 0x4u
#define     APE_STATUS_BOOT_STATUS_B_READ_CODE 0x5u
#define     APE_STATUS_BOOT_STATUS_B_JUMP 0x6u
#define     APE_STATUS_BOOT_STATUS_B_PROG_7 0x7u
#define     APE_STATUS_BOOT_STATUS_B_BPC_SUCCESS 0x8u

#define     APE_STATUS_BOOT_STATUS_A_SHIFT 28u
#define     APE_STATUS_BOOT_STATUS_A_MASK  0xf0000000u
#define GET_APE_STATUS_BOOT_STATUS_A(__reg__)  (((__reg__) & 0xf0000000) >> 28u)
#define SET_APE_STATUS_BOOT_STATUS_A(__val__)  (((__val__) << 28u) & 0xf0000000u)
#define     APE_STATUS_BOOT_STATUS_A_NONE 0x0u
#define     APE_STATUS_BOOT_STATUS_A_NMI_EXCEPTION 0x1u
#define     APE_STATUS_BOOT_STATUS_A_FAULT_EXCEPTION 0x2u
#define     APE_STATUS_BOOT_STATUS_A_MEMORY_CHECK 0x3u
#define     APE_STATUS_BOOT_STATUS_A_UNKNOWN_4 0x4u
#define     APE_STATUS_BOOT_STATUS_A_ROMLOADER_DISABLED 0x5u
#define     APE_STATUS_BOOT_STATUS_A_MAGIC_NUMBER 0x6u
#define     APE_STATUS_BOOT_STATUS_A_APE_INIT_CODE 0x7u
#define     APE_STATUS_BOOT_STATUS_A_HEADER_CHECKSUM 0x8u
#define     APE_STATUS_BOOT_STATUS_A_APE_HEADER 0x9u
#define     APE_STATUS_BOOT_STATUS_A_IMAGE_CHECKSUM 0xau
#define     APE_STATUS_BOOT_STATUS_A_NVRAM_CHECKSUM 0xbu
#define     APE_STATUS_BOOT_STATUS_A_INVALID_TYPE 0xcu
#define     APE_STATUS_BOOT_STATUS_A_ROM_LOADER_CHECKSUM 0xdu
#define     APE_STATUS_BOOT_STATUS_A_INVALID_UNZIP_LEN 0xeu
#define     APE_STATUS_BOOT_STATUS_A_UNKNOWN_F 0xfu


/** @brief Register definition for @ref APE_t.Status. */
typedef register_container RegAPEStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PCIeReset, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_2_1, 1, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NVRAMControlReset, 3, 1)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN0Dstate, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootMode, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_8_6, 6, 3)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN1Dstate, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_23_10, 10, 14)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusB, 24, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusA, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusA, 28, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusB, 24, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_23_10, 10, 14)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN1Dstate, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_8_6, 6, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootMode, 5, 1)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN0Dstate, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NVRAMControlReset, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_2_1, 1, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PCIeReset, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Status"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEStatus_t()
    {
        /** @brief constructor for @ref APE_t.Status. */
        r32.setName("Status");
        bits.PCIeReset.setBaseRegister(&r32);
        bits.PCIeReset.setName("PCIeReset");
        bits.NVRAMControlReset.setBaseRegister(&r32);
        bits.NVRAMControlReset.setName("NVRAMControlReset");
        bits.LAN0Dstate.setBaseRegister(&r32);
        bits.LAN0Dstate.setName("LAN0Dstate");
        bits.BootMode.setBaseRegister(&r32);
        bits.BootMode.setName("BootMode");
        bits.BootMode.addEnum("NVRAM", 0x0);
        bits.BootMode.addEnum("Fast", 0x1);

        bits.LAN1Dstate.setBaseRegister(&r32);
        bits.LAN1Dstate.setName("LAN1Dstate");
        bits.BootStatusB.setBaseRegister(&r32);
        bits.BootStatusB.setName("BootStatusB");
        bits.BootStatusB.addEnum("Prog 0", 0x0);
        bits.BootStatusB.addEnum("Prog 1", 0x1);
        bits.BootStatusB.addEnum("BPC Enter", 0x2);
        bits.BootStatusB.addEnum("Decode", 0x3);
        bits.BootStatusB.addEnum("Read NVRAM Header", 0x4);
        bits.BootStatusB.addEnum("Read Code", 0x5);
        bits.BootStatusB.addEnum("Jump", 0x6);
        bits.BootStatusB.addEnum("Prog 7", 0x7);
        bits.BootStatusB.addEnum("BPC Success", 0x8);

        bits.BootStatusA.setBaseRegister(&r32);
        bits.BootStatusA.setName("BootStatusA");
        bits.BootStatusA.addEnum("None", 0x0);
        bits.BootStatusA.addEnum("NMI Exception", 0x1);
        bits.BootStatusA.addEnum("Fault Exception", 0x2);
        bits.BootStatusA.addEnum("Memory Check", 0x3);
        bits.BootStatusA.addEnum("Unknown 4", 0x4);
        bits.BootStatusA.addEnum("Romloader Disabled", 0x5);
        bits.BootStatusA.addEnum("Magic Number", 0x6);
        bits.BootStatusA.addEnum("APE Init Code", 0x7);
        bits.BootStatusA.addEnum("Header Checksum", 0x8);
        bits.BootStatusA.addEnum("APE Header", 0x9);
        bits.BootStatusA.addEnum("Image Checksum", 0xa);
        bits.BootStatusA.addEnum("NVRAM Checksum", 0xb);
        bits.BootStatusA.addEnum("Invalid Type", 0xc);
        bits.BootStatusA.addEnum("ROM Loader Checksum", 0xd);
        bits.BootStatusA.addEnum("Invalid Unzip Len", 0xe);
        bits.BootStatusA.addEnum("Unknown F", 0xf);

    }
    RegAPEStatus_t& operator=(const RegAPEStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEStatus_t;

#define REG_APE_GPIO_MESSAGE ((volatile BCM5719_APE_H_uint32_t*)0xc0010008) /* Related to APE fastboot. In that case the value of it is an APE memory address in the code region. If Fast Boot is set, and the low two bits of this are not 0b10, ROM hangs (you have to OR 0x2 into the address). Otherwise, they are masked off and the resulting value is used as the reset vector. The resulting value is also stored in this register (i.e., the low two bits are cleared).  */
/** @brief Register definition for @ref APE_t.GpioMessage. */
typedef register_container RegAPEGpioMessage_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GpioMessage"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEGpioMessage_t()
    {
        /** @brief constructor for @ref APE_t.GpioMessage. */
        r32.setName("GpioMessage");
    }
    RegAPEGpioMessage_t& operator=(const RegAPEGpioMessage_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEGpioMessage_t;

#define REG_APE_EVENT ((volatile BCM5719_APE_H_uint32_t*)0xc001000c) /*  */
#define     APE_EVENT_1_SHIFT 0u
#define     APE_EVENT_1_MASK  0x1u
#define GET_APE_EVENT_1(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_EVENT_1(__val__)  (((__val__) << 0u) & 0x1u)

/** @brief Register definition for @ref APE_t.Event. */
typedef register_container RegAPEEvent_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Event 1 */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, _1, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
        /** @brief Event 1 */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, _1, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Event"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEEvent_t()
    {
        /** @brief constructor for @ref APE_t.Event. */
        r32.setName("Event");
        bits._1.setBaseRegister(&r32);
        bits._1.setName("_1");
    }
    RegAPEEvent_t& operator=(const RegAPEEvent_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEEvent_t;

#define REG_APE_RXBUFOFFSET_FUNC0 ((volatile BCM5719_APE_H_uint32_t*)0xc0010014) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. The fields are block numbers (block size 128 bytes). */
#define     APE_RXBUFOFFSET_FUNC0_TAIL_SHIFT 0u
#define     APE_RXBUFOFFSET_FUNC0_TAIL_MASK  0xfffu
#define GET_APE_RXBUFOFFSET_FUNC0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RXBUFOFFSET_FUNC0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RXBUFOFFSET_FUNC0_HEAD_SHIFT 12u
#define     APE_RXBUFOFFSET_FUNC0_HEAD_MASK  0xfff000u
#define GET_APE_RXBUFOFFSET_FUNC0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RXBUFOFFSET_FUNC0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RXBUFOFFSET_FUNC0_TO_HOST_SHIFT 24u
#define     APE_RXBUFOFFSET_FUNC0_TO_HOST_MASK  0x1000000u
#define GET_APE_RXBUFOFFSET_FUNC0_TO_HOST(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_APE_RXBUFOFFSET_FUNC0_TO_HOST(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     APE_RXBUFOFFSET_FUNC0_IP_FRAG_SHIFT 25u
#define     APE_RXBUFOFFSET_FUNC0_IP_FRAG_MASK  0x2000000u
#define GET_APE_RXBUFOFFSET_FUNC0_IP_FRAG(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_APE_RXBUFOFFSET_FUNC0_IP_FRAG(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     APE_RXBUFOFFSET_FUNC0_COUNT_SHIFT 26u
#define     APE_RXBUFOFFSET_FUNC0_COUNT_MASK  0x3c000000u
#define GET_APE_RXBUFOFFSET_FUNC0_COUNT(__reg__)  (((__reg__) & 0x3c000000) >> 26u)
#define SET_APE_RXBUFOFFSET_FUNC0_COUNT(__val__)  (((__val__) << 26u) & 0x3c000000u)
#define     APE_RXBUFOFFSET_FUNC0_VALID_SHIFT 30u
#define     APE_RXBUFOFFSET_FUNC0_VALID_MASK  0x40000000u
#define GET_APE_RXBUFOFFSET_FUNC0_VALID(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_APE_RXBUFOFFSET_FUNC0_VALID(__val__)  (((__val__) << 30u) & 0x40000000u)
#define     APE_RXBUFOFFSET_FUNC0_FINISHED_SHIFT 31u
#define     APE_RXBUFOFFSET_FUNC0_FINISHED_MASK  0x80000000u
#define GET_APE_RXBUFOFFSET_FUNC0_FINISHED(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_APE_RXBUFOFFSET_FUNC0_FINISHED(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref APE_t.RxbufoffsetFunc0. */
typedef register_container RegAPERxbufoffset_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Valid, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Finished, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Finished, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Valid, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxbufoffsetFunc0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxbufoffset_t()
    {
        /** @brief constructor for @ref APE_t.RxbufoffsetFunc0. */
        r32.setName("RxbufoffsetFunc0");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.ToHost.setBaseRegister(&r32);
        bits.ToHost.setName("ToHost");
        bits.IPFrag.setBaseRegister(&r32);
        bits.IPFrag.setName("IPFrag");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
        bits.Valid.setBaseRegister(&r32);
        bits.Valid.setName("Valid");
        bits.Finished.setBaseRegister(&r32);
        bits.Finished.setName("Finished");
    }
    RegAPERxbufoffset_t& operator=(const RegAPERxbufoffset_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxbufoffset_t;

#define REG_APE_RXBUFOFFSET_FUNC1 ((volatile BCM5719_APE_H_uint32_t*)0xc0010018) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
#define REG_APE_TX_TO_NET_DOORBELL_FUNC0 ((volatile BCM5719_APE_H_uint32_t*)0xc001001c) /* Written on APE TX to network after filling 0xA002 buffer with packet. */
#define     APE_TX_TO_NET_DOORBELL_FUNC0_TAIL_SHIFT 0u
#define     APE_TX_TO_NET_DOORBELL_FUNC0_TAIL_MASK  0xfffu
#define GET_APE_TX_TO_NET_DOORBELL_FUNC0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_DOORBELL_FUNC0_HEAD_SHIFT 12u
#define     APE_TX_TO_NET_DOORBELL_FUNC0_HEAD_MASK  0xfff000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_TX_TO_NET_DOORBELL_FUNC0_LENGTH_SHIFT 24u
#define     APE_TX_TO_NET_DOORBELL_FUNC0_LENGTH_MASK  0xf000000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC0_LENGTH(__reg__)  (((__reg__) & 0xf000000) >> 24u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC0_LENGTH(__val__)  (((__val__) << 24u) & 0xf000000u)
#define     APE_TX_TO_NET_DOORBELL_FUNC0_TX_QUEUE_FULL_SHIFT 28u
#define     APE_TX_TO_NET_DOORBELL_FUNC0_TX_QUEUE_FULL_MASK  0x10000000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC0_TX_QUEUE_FULL(__reg__)  (((__reg__) & 0x10000000) >> 28u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC0_TX_QUEUE_FULL(__val__)  (((__val__) << 28u) & 0x10000000u)

/** @brief Register definition for @ref APE_t.TxToNetDoorbellFunc0. */
typedef register_container RegAPETxToNetDoorbell_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Length, 24, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, TXQueueFull, 28, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_29, 29, 3)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_29, 29, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, TXQueueFull, 28, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Length, 24, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetDoorbellFunc0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetDoorbell_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetDoorbellFunc0. */
        r32.setName("TxToNetDoorbellFunc0");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Length.setBaseRegister(&r32);
        bits.Length.setName("Length");
        bits.TXQueueFull.setBaseRegister(&r32);
        bits.TXQueueFull.setName("TXQueueFull");
    }
    RegAPETxToNetDoorbell_t& operator=(const RegAPETxToNetDoorbell_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetDoorbell_t;

#define REG_APE_TX_STATE0 ((volatile BCM5719_APE_H_uint32_t*)0xc0010020) /* APE TX Status. */
#define     APE_TX_STATE0_TAIL_SHIFT 0u
#define     APE_TX_STATE0_TAIL_MASK  0xfffu
#define GET_APE_TX_STATE0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_STATE0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_STATE0_HEAD_SHIFT 12u
#define     APE_TX_STATE0_HEAD_MASK  0xfff000u
#define GET_APE_TX_STATE0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_TX_STATE0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_TX_STATE0_TXERROR_SHIFT 24u
#define     APE_TX_STATE0_TXERROR_MASK  0x1000000u
#define GET_APE_TX_STATE0_TXERROR(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_APE_TX_STATE0_TXERROR(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     APE_TX_STATE0_ERROR_CODE_SHIFT 25u
#define     APE_TX_STATE0_ERROR_CODE_MASK  0xe000000u
#define GET_APE_TX_STATE0_ERROR_CODE(__reg__)  (((__reg__) & 0xe000000) >> 25u)
#define SET_APE_TX_STATE0_ERROR_CODE(__val__)  (((__val__) << 25u) & 0xe000000u)

/** @brief Register definition for @ref APE_t.TxState0. */
typedef register_container RegAPETxState0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, TXError, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ErrorCode, 25, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_28, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_28, 28, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ErrorCode, 25, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, TXError, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxState0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxState0_t()
    {
        /** @brief constructor for @ref APE_t.TxState0. */
        r32.setName("TxState0");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.TXError.setBaseRegister(&r32);
        bits.TXError.setName("TXError");
        bits.ErrorCode.setBaseRegister(&r32);
        bits.ErrorCode.setName("ErrorCode");
    }
    RegAPETxState0_t& operator=(const RegAPETxState0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxState0_t;

#define REG_APE_MODE_2 ((volatile BCM5719_APE_H_uint32_t*)0xc001002c) /* Expansion for MODE */
#define     APE_MODE_2_CHANNEL_0_ENABLE_SHIFT 14u
#define     APE_MODE_2_CHANNEL_0_ENABLE_MASK  0x4000u
#define GET_APE_MODE_2_CHANNEL_0_ENABLE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_APE_MODE_2_CHANNEL_0_ENABLE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     APE_MODE_2_CHANNEL_2_ENABLE_SHIFT 15u
#define     APE_MODE_2_CHANNEL_2_ENABLE_MASK  0x8000u
#define GET_APE_MODE_2_CHANNEL_2_ENABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_APE_MODE_2_CHANNEL_2_ENABLE(__val__)  (((__val__) << 15u) & 0x8000u)
#define     APE_MODE_2_CHANNEL_1_ENABLE_SHIFT 30u
#define     APE_MODE_2_CHANNEL_1_ENABLE_MASK  0x40000000u
#define GET_APE_MODE_2_CHANNEL_1_ENABLE(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_APE_MODE_2_CHANNEL_1_ENABLE(__val__)  (((__val__) << 30u) & 0x40000000u)
#define     APE_MODE_2_CHANNEL_3_ENABLE_SHIFT 31u
#define     APE_MODE_2_CHANNEL_3_ENABLE_MASK  0x80000000u
#define GET_APE_MODE_2_CHANNEL_3_ENABLE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_APE_MODE_2_CHANNEL_3_ENABLE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref APE_t.Mode2. */
typedef register_container RegAPEMode2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_13_0, 0, 14)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel0Enable, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel2Enable, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_29_16, 16, 14)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel1Enable, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel3Enable, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel3Enable, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel1Enable, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_29_16, 16, 14)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel2Enable, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Channel0Enable, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_13_0, 0, 14)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Mode2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEMode2_t()
    {
        /** @brief constructor for @ref APE_t.Mode2. */
        r32.setName("Mode2");
        bits.Channel0Enable.setBaseRegister(&r32);
        bits.Channel0Enable.setName("Channel0Enable");
        bits.Channel2Enable.setBaseRegister(&r32);
        bits.Channel2Enable.setName("Channel2Enable");
        bits.Channel1Enable.setBaseRegister(&r32);
        bits.Channel1Enable.setName("Channel1Enable");
        bits.Channel3Enable.setBaseRegister(&r32);
        bits.Channel3Enable.setName("Channel3Enable");
    }
    RegAPEMode2_t& operator=(const RegAPEMode2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEMode2_t;

#define REG_APE_STATUS_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010030) /*  */
/** @brief Register definition for @ref APE_t.Status2. */
typedef register_container RegAPEStatus2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Status2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEStatus2_t()
    {
        /** @brief constructor for @ref APE_t.Status2. */
        r32.setName("Status2");
    }
    RegAPEStatus2_t& operator=(const RegAPEStatus2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEStatus2_t;

#define REG_APE_LOCK_GRANT__OBSOLETE_ ((volatile BCM5719_APE_H_uint32_t*)0xc001004c) /* See  */
/** @brief Register definition for @ref APE_t.LockGrantObsolete. */
typedef register_container RegAPELockGrantObsolete_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LockGrantObsolete"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPELockGrantObsolete_t()
    {
        /** @brief constructor for @ref APE_t.LockGrantObsolete. */
        r32.setName("LockGrantObsolete");
    }
    RegAPELockGrantObsolete_t& operator=(const RegAPELockGrantObsolete_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPELockGrantObsolete_t;

#define REG_APE_RX_POOL_MODE_STATUS_0 ((volatile BCM5719_APE_H_uint32_t*)0xc0010078) /*  */
#define     APE_RX_POOL_MODE_STATUS_0_HALT_SHIFT 0u
#define     APE_RX_POOL_MODE_STATUS_0_HALT_MASK  0x1u
#define GET_APE_RX_POOL_MODE_STATUS_0_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_RX_POOL_MODE_STATUS_0_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_RX_POOL_MODE_STATUS_0_HALT_DONE_SHIFT 1u
#define     APE_RX_POOL_MODE_STATUS_0_HALT_DONE_MASK  0x2u
#define GET_APE_RX_POOL_MODE_STATUS_0_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_RX_POOL_MODE_STATUS_0_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_RX_POOL_MODE_STATUS_0_ENABLE_SHIFT 2u
#define     APE_RX_POOL_MODE_STATUS_0_ENABLE_MASK  0x4u
#define GET_APE_RX_POOL_MODE_STATUS_0_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_RX_POOL_MODE_STATUS_0_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_RX_POOL_MODE_STATUS_0_EMPTY_SHIFT 4u
#define     APE_RX_POOL_MODE_STATUS_0_EMPTY_MASK  0x10u
#define GET_APE_RX_POOL_MODE_STATUS_0_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_RX_POOL_MODE_STATUS_0_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_RX_POOL_MODE_STATUS_0_ERROR_SHIFT 5u
#define     APE_RX_POOL_MODE_STATUS_0_ERROR_MASK  0x20u
#define GET_APE_RX_POOL_MODE_STATUS_0_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_RX_POOL_MODE_STATUS_0_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_RX_POOL_MODE_STATUS_0_RESET_SHIFT 6u
#define     APE_RX_POOL_MODE_STATUS_0_RESET_MASK  0x40u
#define GET_APE_RX_POOL_MODE_STATUS_0_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_RX_POOL_MODE_STATUS_0_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_RX_POOL_MODE_STATUS_0_FULL_COUNT_SHIFT 8u
#define     APE_RX_POOL_MODE_STATUS_0_FULL_COUNT_MASK  0xffff00u
#define GET_APE_RX_POOL_MODE_STATUS_0_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_RX_POOL_MODE_STATUS_0_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.RxPoolModeStatus0. */
typedef register_container RegAPERxPoolModeStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolModeStatus0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolModeStatus_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolModeStatus0. */
        r32.setName("RxPoolModeStatus0");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPERxPoolModeStatus_t& operator=(const RegAPERxPoolModeStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolModeStatus_t;

#define REG_APE_RX_POOL_MODE_STATUS_1 ((volatile BCM5719_APE_H_uint32_t*)0xc001007c) /*  */
#define REG_APE_RX_POOL_RETIRE_0 ((volatile BCM5719_APE_H_uint32_t*)0xc0010080) /* Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
#define     APE_RX_POOL_RETIRE_0_TAIL_SHIFT 0u
#define     APE_RX_POOL_RETIRE_0_TAIL_MASK  0xfffu
#define GET_APE_RX_POOL_RETIRE_0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RX_POOL_RETIRE_0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RX_POOL_RETIRE_0_HEAD_SHIFT 12u
#define     APE_RX_POOL_RETIRE_0_HEAD_MASK  0xfff000u
#define GET_APE_RX_POOL_RETIRE_0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RX_POOL_RETIRE_0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RX_POOL_RETIRE_0_RETIRE_SHIFT 24u
#define     APE_RX_POOL_RETIRE_0_RETIRE_MASK  0x1000000u
#define GET_APE_RX_POOL_RETIRE_0_RETIRE(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_APE_RX_POOL_RETIRE_0_RETIRE(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     APE_RX_POOL_RETIRE_0_STATE_SHIFT 25u
#define     APE_RX_POOL_RETIRE_0_STATE_MASK  0x6000000u
#define GET_APE_RX_POOL_RETIRE_0_STATE(__reg__)  (((__reg__) & 0x6000000) >> 25u)
#define SET_APE_RX_POOL_RETIRE_0_STATE(__val__)  (((__val__) << 25u) & 0x6000000u)
#define     APE_RX_POOL_RETIRE_STATE_PROCESSING 0x0u
#define     APE_RX_POOL_RETIRE_STATE_RETIRED_OK 0x1u
#define     APE_RX_POOL_RETIRE_STATE_ERROR__FULL 0x2u
#define     APE_RX_POOL_RETIRE_STATE_ERROR__IN_HALT 0x3u

#define     APE_RX_POOL_RETIRE_0_COUNT_SHIFT 27u
#define     APE_RX_POOL_RETIRE_0_COUNT_MASK  0x78000000u
#define GET_APE_RX_POOL_RETIRE_0_COUNT(__reg__)  (((__reg__) & 0x78000000) >> 27u)
#define SET_APE_RX_POOL_RETIRE_0_COUNT(__val__)  (((__val__) << 27u) & 0x78000000u)

/** @brief Register definition for @ref APE_t.RxPoolRetire0. */
typedef register_container RegAPERxPoolRetire_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Retire, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, State, 25, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Count, 27, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Count, 27, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, State, 25, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Retire, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolRetire0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolRetire_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolRetire0. */
        r32.setName("RxPoolRetire0");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Retire.setBaseRegister(&r32);
        bits.Retire.setName("Retire");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
        bits.State.addEnum("Processing", 0x0);
        bits.State.addEnum("Retired OK", 0x1);
        bits.State.addEnum("Error: Full", 0x2);
        bits.State.addEnum("Error: In Halt", 0x3);

        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
    }
    RegAPERxPoolRetire_t& operator=(const RegAPERxPoolRetire_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolRetire_t;

#define REG_APE_RX_POOL_FREE_POINTER_0 ((volatile BCM5719_APE_H_uint32_t*)0xc0010084) /*  */
#define     APE_RX_POOL_FREE_POINTER_0_TAIL_SHIFT 0u
#define     APE_RX_POOL_FREE_POINTER_0_TAIL_MASK  0xfffu
#define GET_APE_RX_POOL_FREE_POINTER_0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RX_POOL_FREE_POINTER_0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RX_POOL_FREE_POINTER_0_HEAD_SHIFT 12u
#define     APE_RX_POOL_FREE_POINTER_0_HEAD_MASK  0xfff000u
#define GET_APE_RX_POOL_FREE_POINTER_0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RX_POOL_FREE_POINTER_0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RX_POOL_FREE_POINTER_0_FREE_COUNT_SHIFT 24u
#define     APE_RX_POOL_FREE_POINTER_0_FREE_COUNT_MASK  0x7f000000u
#define GET_APE_RX_POOL_FREE_POINTER_0_FREE_COUNT(__reg__)  (((__reg__) & 0x7f000000) >> 24u)
#define SET_APE_RX_POOL_FREE_POINTER_0_FREE_COUNT(__val__)  (((__val__) << 24u) & 0x7f000000u)
#define     APE_RX_POOL_FREE_POINTER_FREE_COUNT_MAX 0x7fu


/** @brief Register definition for @ref APE_t.RxPoolFreePointer0. */
typedef register_container RegAPERxPoolFreePointer_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FreeCount, 24, 7)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FreeCount, 24, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolFreePointer0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolFreePointer_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolFreePointer0. */
        r32.setName("RxPoolFreePointer0");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.FreeCount.setBaseRegister(&r32);
        bits.FreeCount.setName("FreeCount");
        bits.FreeCount.addEnum("Max", 0x7f);

    }
    RegAPERxPoolFreePointer_t& operator=(const RegAPERxPoolFreePointer_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolFreePointer_t;

#define REG_APE_RX_POOL_RETIRE_1 ((volatile BCM5719_APE_H_uint32_t*)0xc0010088) /* Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
#define REG_APE_TX_TO_NET_POOL_MODE_STATUS_0 ((volatile BCM5719_APE_H_uint32_t*)0xc001008c) /*  */
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_SHIFT 0u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_MASK  0x1u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_DONE_SHIFT 1u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_DONE_MASK  0x2u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_ENABLE_SHIFT 2u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_ENABLE_MASK  0x4u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_EMPTY_SHIFT 4u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_EMPTY_MASK  0x10u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_ERROR_SHIFT 5u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_ERROR_MASK  0x20u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_RESET_SHIFT 6u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_RESET_MASK  0x40u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_FULL_COUNT_SHIFT 8u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_FULL_COUNT_MASK  0xffff00u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.TxToNetPoolModeStatus0. */
typedef register_container RegAPETxToNetPoolModeStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetPoolModeStatus0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetPoolModeStatus_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetPoolModeStatus0. */
        r32.setName("TxToNetPoolModeStatus0");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPETxToNetPoolModeStatus_t& operator=(const RegAPETxToNetPoolModeStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetPoolModeStatus_t;

#define REG_APE_TX_TO_NET_BUFFER_ALLOCATOR_0 ((volatile BCM5719_APE_H_uint32_t*)0xc0010090) /*  */
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_INDEX_SHIFT 0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_INDEX_MASK  0xfffu
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_INDEX(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_INDEX(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_INDEX_BLOCK_SIZE 0x80u

#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_REQUEST_ALLOCATION_SHIFT 12u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_REQUEST_ALLOCATION_MASK  0x1000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_REQUEST_ALLOCATION(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_REQUEST_ALLOCATION(__val__)  (((__val__) << 12u) & 0x1000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_SHIFT 13u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_MASK  0x6000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_STATE_PROCESSING 0x0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_STATE_ALLOCATION_OK 0x1u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_STATE_ERROR__EMPTY 0x2u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_STATE_ERROR__IN_HALT 0x3u


/** @brief Register definition for @ref APE_t.TxToNetBufferAllocator0. */
typedef register_container RegAPETxToNetBufferAllocator_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Index, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, State, 13, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_15, 15, 17)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_15, 15, 17)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, State, 13, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Index, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetBufferAllocator0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetBufferAllocator_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetBufferAllocator0. */
        r32.setName("TxToNetBufferAllocator0");
        bits.Index.setBaseRegister(&r32);
        bits.Index.setName("Index");
        bits.Index.addEnum("Block Size", 0x80);

        bits.RequestAllocation.setBaseRegister(&r32);
        bits.RequestAllocation.setName("RequestAllocation");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
        bits.State.addEnum("Processing", 0x0);
        bits.State.addEnum("Allocation OK", 0x1);
        bits.State.addEnum("Error: Empty", 0x2);
        bits.State.addEnum("Error: In Halt", 0x3);

    }
    RegAPETxToNetBufferAllocator_t& operator=(const RegAPETxToNetBufferAllocator_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetBufferAllocator_t;

#define REG_APE_TX_TO_NET_BUFFER_RETURN_0 ((volatile BCM5719_APE_H_uint32_t*)0xc0010094) /*  */
/** @brief Register definition for @ref APE_t.TxToNetBufferReturn0. */
typedef register_container RegAPETxToNetBufferReturn_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetBufferReturn0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetBufferReturn_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetBufferReturn0. */
        r32.setName("TxToNetBufferReturn0");
    }
    RegAPETxToNetBufferReturn_t& operator=(const RegAPETxToNetBufferReturn_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetBufferReturn_t;

#define REG_APE_TX_TO_NET_BUFFER_RING_0 ((volatile BCM5719_APE_H_uint32_t*)0xc0010098) /*  */
#define     APE_TX_TO_NET_BUFFER_RING_0_TAIL_SHIFT 0u
#define     APE_TX_TO_NET_BUFFER_RING_0_TAIL_MASK  0xfffu
#define GET_APE_TX_TO_NET_BUFFER_RING_0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_BUFFER_RING_0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_BUFFER_RING_0_HEAD_SHIFT 12u
#define     APE_TX_TO_NET_BUFFER_RING_0_HEAD_MASK  0xfff000u
#define GET_APE_TX_TO_NET_BUFFER_RING_0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_TX_TO_NET_BUFFER_RING_0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_TX_TO_NET_BUFFER_RING_0_FREE_SHIFT 24u
#define     APE_TX_TO_NET_BUFFER_RING_0_FREE_MASK  0x3f000000u
#define GET_APE_TX_TO_NET_BUFFER_RING_0_FREE(__reg__)  (((__reg__) & 0x3f000000) >> 24u)
#define SET_APE_TX_TO_NET_BUFFER_RING_0_FREE(__val__)  (((__val__) << 24u) & 0x3f000000u)
#define     APE_TX_TO_NET_BUFFER_RING_FREE_MAX 0x3fu


/** @brief Register definition for @ref APE_t.TxToNetBufferRing0. */
typedef register_container RegAPETxToNetBufferRing_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Free, 24, 6)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_30, 30, 2)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_30, 30, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Free, 24, 6)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetBufferRing0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetBufferRing_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetBufferRing0. */
        r32.setName("TxToNetBufferRing0");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Free.setBaseRegister(&r32);
        bits.Free.setName("Free");
        bits.Free.addEnum("Max", 0x3f);

    }
    RegAPETxToNetBufferRing_t& operator=(const RegAPETxToNetBufferRing_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetBufferRing_t;

#define REG_APE_RX_POOL_FREE_POINTER_1 ((volatile BCM5719_APE_H_uint32_t*)0xc001009c) /*  */
#define REG_APE_TICK_1MHZ ((volatile BCM5719_APE_H_uint32_t*)0xc00100a8) /* Unknown, monotonically increasing value. Increases at a rate of 1MHz. */
/** @brief Register definition for @ref APE_t.Tick1mhz. */
typedef register_container RegAPETick1mhz_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Tick1mhz"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETick1mhz_t()
    {
        /** @brief constructor for @ref APE_t.Tick1mhz. */
        r32.setName("Tick1mhz");
    }
    RegAPETick1mhz_t& operator=(const RegAPETick1mhz_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETick1mhz_t;

#define REG_APE_TICK_1KHZ ((volatile BCM5719_APE_H_uint32_t*)0xc00100ac) /* Unknown, monotonically increasing value. Increases at a rate of 1KHz. */
/** @brief Register definition for @ref APE_t.Tick1khz. */
typedef register_container RegAPETick1khz_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Tick1khz"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETick1khz_t()
    {
        /** @brief constructor for @ref APE_t.Tick1khz. */
        r32.setName("Tick1khz");
    }
    RegAPETick1khz_t& operator=(const RegAPETick1khz_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETick1khz_t;

#define REG_APE_TICK_10HZ ((volatile BCM5719_APE_H_uint32_t*)0xc00100b0) /* Unknown, monotonically increasing value. Increases at a rate of 10Hz. */
/** @brief Register definition for @ref APE_t.Tick10hz. */
typedef register_container RegAPETick10hz_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Tick10hz"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETick10hz_t()
    {
        /** @brief constructor for @ref APE_t.Tick10hz. */
        r32.setName("Tick10hz");
    }
    RegAPETick10hz_t& operator=(const RegAPETick10hz_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETick10hz_t;

#define REG_APE_GPIO ((volatile BCM5719_APE_H_uint32_t*)0xc00100b8) /*  */
#define     APE_GPIO_PIN0_UNKNOWN_SHIFT 0u
#define     APE_GPIO_PIN0_UNKNOWN_MASK  0x1u
#define GET_APE_GPIO_PIN0_UNKNOWN(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_GPIO_PIN0_UNKNOWN(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_GPIO_PIN1_UNKNOWN_SHIFT 1u
#define     APE_GPIO_PIN1_UNKNOWN_MASK  0x2u
#define GET_APE_GPIO_PIN1_UNKNOWN(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_GPIO_PIN1_UNKNOWN(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_GPIO_PIN2_UNKNOWN_SHIFT 2u
#define     APE_GPIO_PIN2_UNKNOWN_MASK  0x4u
#define GET_APE_GPIO_PIN2_UNKNOWN(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_GPIO_PIN2_UNKNOWN(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_GPIO_PIN3_UNKNOWN_SHIFT 3u
#define     APE_GPIO_PIN3_UNKNOWN_MASK  0x8u
#define GET_APE_GPIO_PIN3_UNKNOWN(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_GPIO_PIN3_UNKNOWN(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_GPIO_PIN0_UNKNOWN_OUT_SHIFT 8u
#define     APE_GPIO_PIN0_UNKNOWN_OUT_MASK  0x100u
#define GET_APE_GPIO_PIN0_UNKNOWN_OUT(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_APE_GPIO_PIN0_UNKNOWN_OUT(__val__)  (((__val__) << 8u) & 0x100u)
#define     APE_GPIO_PIN1_UNKNOWN_OUT_SHIFT 9u
#define     APE_GPIO_PIN1_UNKNOWN_OUT_MASK  0x200u
#define GET_APE_GPIO_PIN1_UNKNOWN_OUT(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_GPIO_PIN1_UNKNOWN_OUT(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_GPIO_PIN2_UNKNOWN_OUT_SHIFT 10u
#define     APE_GPIO_PIN2_UNKNOWN_OUT_MASK  0x400u
#define GET_APE_GPIO_PIN2_UNKNOWN_OUT(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_APE_GPIO_PIN2_UNKNOWN_OUT(__val__)  (((__val__) << 10u) & 0x400u)
#define     APE_GPIO_PIN3_UNKNOWN_OUT_SHIFT 11u
#define     APE_GPIO_PIN3_UNKNOWN_OUT_MASK  0x800u
#define GET_APE_GPIO_PIN3_UNKNOWN_OUT(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_APE_GPIO_PIN3_UNKNOWN_OUT(__val__)  (((__val__) << 11u) & 0x800u)
#define     APE_GPIO_PIN0_MODE_OUTPUT_SHIFT 16u
#define     APE_GPIO_PIN0_MODE_OUTPUT_MASK  0x10000u
#define GET_APE_GPIO_PIN0_MODE_OUTPUT(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_APE_GPIO_PIN0_MODE_OUTPUT(__val__)  (((__val__) << 16u) & 0x10000u)
#define     APE_GPIO_PIN1_MODE_OUTPUT_SHIFT 17u
#define     APE_GPIO_PIN1_MODE_OUTPUT_MASK  0x20000u
#define GET_APE_GPIO_PIN1_MODE_OUTPUT(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_APE_GPIO_PIN1_MODE_OUTPUT(__val__)  (((__val__) << 17u) & 0x20000u)
#define     APE_GPIO_PIN2_MODE_OUTPUT_SHIFT 18u
#define     APE_GPIO_PIN2_MODE_OUTPUT_MASK  0x40000u
#define GET_APE_GPIO_PIN2_MODE_OUTPUT(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_APE_GPIO_PIN2_MODE_OUTPUT(__val__)  (((__val__) << 18u) & 0x40000u)
#define     APE_GPIO_PIN3_MODE_OUTPUT_SHIFT 19u
#define     APE_GPIO_PIN3_MODE_OUTPUT_MASK  0x80000u
#define GET_APE_GPIO_PIN3_MODE_OUTPUT(__reg__)  (((__reg__) & 0x80000) >> 19u)
#define SET_APE_GPIO_PIN3_MODE_OUTPUT(__val__)  (((__val__) << 19u) & 0x80000u)

/** @brief Register definition for @ref APE_t.Gpio. */
typedef register_container RegAPEGpio_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0Unknown, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1Unknown, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2Unknown, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3Unknown, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_4, 4, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0UnknownOut, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1UnknownOut, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2UnknownOut, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3UnknownOut, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_15_12, 12, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0ModeOutput, 16, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1ModeOutput, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2ModeOutput, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3ModeOutput, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_20, 20, 12)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_20, 20, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3ModeOutput, 19, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2ModeOutput, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1ModeOutput, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0ModeOutput, 16, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_15_12, 12, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3UnknownOut, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2UnknownOut, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1UnknownOut, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0UnknownOut, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_4, 4, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3Unknown, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2Unknown, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1Unknown, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0Unknown, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Gpio"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEGpio_t()
    {
        /** @brief constructor for @ref APE_t.Gpio. */
        r32.setName("Gpio");
        bits.PIN0Unknown.setBaseRegister(&r32);
        bits.PIN0Unknown.setName("PIN0Unknown");
        bits.PIN1Unknown.setBaseRegister(&r32);
        bits.PIN1Unknown.setName("PIN1Unknown");
        bits.PIN2Unknown.setBaseRegister(&r32);
        bits.PIN2Unknown.setName("PIN2Unknown");
        bits.PIN3Unknown.setBaseRegister(&r32);
        bits.PIN3Unknown.setName("PIN3Unknown");
        bits.PIN0UnknownOut.setBaseRegister(&r32);
        bits.PIN0UnknownOut.setName("PIN0UnknownOut");
        bits.PIN1UnknownOut.setBaseRegister(&r32);
        bits.PIN1UnknownOut.setName("PIN1UnknownOut");
        bits.PIN2UnknownOut.setBaseRegister(&r32);
        bits.PIN2UnknownOut.setName("PIN2UnknownOut");
        bits.PIN3UnknownOut.setBaseRegister(&r32);
        bits.PIN3UnknownOut.setName("PIN3UnknownOut");
        bits.PIN0ModeOutput.setBaseRegister(&r32);
        bits.PIN0ModeOutput.setName("PIN0ModeOutput");
        bits.PIN1ModeOutput.setBaseRegister(&r32);
        bits.PIN1ModeOutput.setName("PIN1ModeOutput");
        bits.PIN2ModeOutput.setBaseRegister(&r32);
        bits.PIN2ModeOutput.setName("PIN2ModeOutput");
        bits.PIN3ModeOutput.setBaseRegister(&r32);
        bits.PIN3ModeOutput.setName("PIN3ModeOutput");
    }
    RegAPEGpio_t& operator=(const RegAPEGpio_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEGpio_t;

#define REG_APE_GINT ((volatile BCM5719_APE_H_uint32_t*)0xc00100bc) /* TODO: See diag for field info. */
/** @brief Register definition for @ref APE_t.Gint. */
typedef register_container RegAPEGint_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Gint"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEGint_t()
    {
        /** @brief constructor for @ref APE_t.Gint. */
        r32.setName("Gint");
    }
    RegAPEGint_t& operator=(const RegAPEGint_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEGint_t;

#define REG_APE_OTP_CONTROL ((volatile BCM5719_APE_H_uint32_t*)0xc00100e8) /*  */
#define     APE_OTP_CONTROL_START_SHIFT 0u
#define     APE_OTP_CONTROL_START_MASK  0x1u
#define GET_APE_OTP_CONTROL_START(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_OTP_CONTROL_START(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_OTP_CONTROL_INIT_SHIFT 3u
#define     APE_OTP_CONTROL_INIT_MASK  0x8u
#define GET_APE_OTP_CONTROL_INIT(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_OTP_CONTROL_INIT(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_OTP_CONTROL_PROG_ENABLE_SHIFT 21u
#define     APE_OTP_CONTROL_PROG_ENABLE_MASK  0x200000u
#define GET_APE_OTP_CONTROL_PROG_ENABLE(__reg__)  (((__reg__) & 0x200000) >> 21u)
#define SET_APE_OTP_CONTROL_PROG_ENABLE(__val__)  (((__val__) << 21u) & 0x200000u)

/** @brief Register definition for @ref APE_t.OtpControl. */
typedef register_container RegAPEOtpControl_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Start, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_2_1, 1, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Init, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_20_4, 4, 17)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ProgEnable, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_22, 22, 10)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_22, 22, 10)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ProgEnable, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_20_4, 4, 17)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Init, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_2_1, 1, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Start, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "OtpControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEOtpControl_t()
    {
        /** @brief constructor for @ref APE_t.OtpControl. */
        r32.setName("OtpControl");
        bits.Start.setBaseRegister(&r32);
        bits.Start.setName("Start");
        bits.Init.setBaseRegister(&r32);
        bits.Init.setName("Init");
        bits.ProgEnable.setBaseRegister(&r32);
        bits.ProgEnable.setName("ProgEnable");
    }
    RegAPEOtpControl_t& operator=(const RegAPEOtpControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEOtpControl_t;

#define REG_APE_OTP_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc00100ec) /*  */
#define     APE_OTP_STATUS_COMMAND_DONE_SHIFT 0u
#define     APE_OTP_STATUS_COMMAND_DONE_MASK  0x1u
#define GET_APE_OTP_STATUS_COMMAND_DONE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_OTP_STATUS_COMMAND_DONE(__val__)  (((__val__) << 0u) & 0x1u)

/** @brief Register definition for @ref APE_t.OtpStatus. */
typedef register_container RegAPEOtpStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CommandDone, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CommandDone, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "OtpStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEOtpStatus_t()
    {
        /** @brief constructor for @ref APE_t.OtpStatus. */
        r32.setName("OtpStatus");
        bits.CommandDone.setBaseRegister(&r32);
        bits.CommandDone.setName("CommandDone");
    }
    RegAPEOtpStatus_t& operator=(const RegAPEOtpStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEOtpStatus_t;

#define REG_APE_OTP_ADDR ((volatile BCM5719_APE_H_uint32_t*)0xc00100f0) /*  */
#define     APE_OTP_ADDR_ADDRESS_SHIFT 0u
#define     APE_OTP_ADDR_ADDRESS_MASK  0x7fffffffu
#define GET_APE_OTP_ADDR_ADDRESS(__reg__)  (((__reg__) & 0x7fffffff) >> 0u)
#define SET_APE_OTP_ADDR_ADDRESS(__val__)  (((__val__) << 0u) & 0x7fffffffu)
#define     APE_OTP_ADDR_CPU_ENABLE_SHIFT 31u
#define     APE_OTP_ADDR_CPU_ENABLE_MASK  0x80000000u
#define GET_APE_OTP_ADDR_CPU_ENABLE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_APE_OTP_ADDR_CPU_ENABLE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref APE_t.OtpAddr. */
typedef register_container RegAPEOtpAddr_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Address, 0, 31)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CPUEnable, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CPUEnable, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Address, 0, 31)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "OtpAddr"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEOtpAddr_t()
    {
        /** @brief constructor for @ref APE_t.OtpAddr. */
        r32.setName("OtpAddr");
        bits.Address.setBaseRegister(&r32);
        bits.Address.setName("Address");
        bits.CPUEnable.setBaseRegister(&r32);
        bits.CPUEnable.setName("CPUEnable");
    }
    RegAPEOtpAddr_t& operator=(const RegAPEOtpAddr_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEOtpAddr_t;

#define REG_APE_OTP_READ_DATA ((volatile BCM5719_APE_H_uint32_t*)0xc00100f8) /*  */
/** @brief Register definition for @ref APE_t.OtpReadData. */
typedef register_container RegAPEOtpReadData_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "OtpReadData"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEOtpReadData_t()
    {
        /** @brief constructor for @ref APE_t.OtpReadData. */
        r32.setName("OtpReadData");
    }
    RegAPEOtpReadData_t& operator=(const RegAPEOtpReadData_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEOtpReadData_t;

#define REG_APE_CPU_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc0010108) /* Seems CPU control related. */
#define     APE_CPU_STATUS_STATUS_SHIFT 0u
#define     APE_CPU_STATUS_STATUS_MASK  0xfu
#define GET_APE_CPU_STATUS_STATUS(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_APE_CPU_STATUS_STATUS(__val__)  (((__val__) << 0u) & 0xfu)
#define     APE_CPU_STATUS_STATUS_RUNNING 0x0u
#define     APE_CPU_STATUS_STATUS_HALTED 0x1u
#define     APE_CPU_STATUS_STATUS_LOCKED_OUT 0x2u
#define     APE_CPU_STATUS_STATUS_SLEEPING 0x3u
#define     APE_CPU_STATUS_STATUS_DEEP_SLEEP 0x4u
#define     APE_CPU_STATUS_STATUS_INTERRUPT_PENDING 0x8u
#define     APE_CPU_STATUS_STATUS_INTERRUPT_ENTRY 0x9u
#define     APE_CPU_STATUS_STATUS_INTERRUPT_EXIT 0xau
#define     APE_CPU_STATUS_STATUS_INTERRUPT_RETURN 0xbu

#define     APE_CPU_STATUS_ACTIVE_INTERRUPT_SHIFT 24u
#define     APE_CPU_STATUS_ACTIVE_INTERRUPT_MASK  0xff000000u
#define GET_APE_CPU_STATUS_ACTIVE_INTERRUPT(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_APE_CPU_STATUS_ACTIVE_INTERRUPT(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref APE_t.CpuStatus. */
typedef register_container RegAPECpuStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Status, 0, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_23_4, 4, 20)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ActiveInterrupt, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ActiveInterrupt, 24, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_23_4, 4, 20)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Status, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "CpuStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPECpuStatus_t()
    {
        /** @brief constructor for @ref APE_t.CpuStatus. */
        r32.setName("CpuStatus");
        bits.Status.setBaseRegister(&r32);
        bits.Status.setName("Status");
        bits.Status.addEnum("Running", 0x0);
        bits.Status.addEnum("Halted", 0x1);
        bits.Status.addEnum("Locked Out", 0x2);
        bits.Status.addEnum("Sleeping", 0x3);
        bits.Status.addEnum("Deep Sleep", 0x4);
        bits.Status.addEnum("Interrupt Pending", 0x8);
        bits.Status.addEnum("Interrupt Entry", 0x9);
        bits.Status.addEnum("Interrupt Exit", 0xa);
        bits.Status.addEnum("Interrupt Return", 0xb);

        bits.ActiveInterrupt.setBaseRegister(&r32);
        bits.ActiveInterrupt.setName("ActiveInterrupt");
    }
    RegAPECpuStatus_t& operator=(const RegAPECpuStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPECpuStatus_t;

#define REG_APE_TX_TO_NET_POOL_MODE_STATUS_1 ((volatile BCM5719_APE_H_uint32_t*)0xc0010110) /*  */
#define REG_APE_TX_TO_NET_BUFFER_ALLOCATOR_1 ((volatile BCM5719_APE_H_uint32_t*)0xc0010114) /*  */
#define REG_APE_TX_TO_NET_BUFFER_RETURN_1 ((volatile BCM5719_APE_H_uint32_t*)0xc0010118) /*  */
#define REG_APE_TX_TO_NET_BUFFER_RING_1 ((volatile BCM5719_APE_H_uint32_t*)0xc001011c) /*  */
#define REG_APE_TX_TO_NET_DOORBELL_FUNC1 ((volatile BCM5719_APE_H_uint32_t*)0xc0010120) /* Written on APE TX to network after filling 0xA002 buffer with packet. */
#define REG_APE_RXBUFOFFSET_FUNC2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010200) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
#define REG_APE_TX_TO_NET_DOORBELL_FUNC2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010204) /* Written on APE TX to network after filling 0xA002 buffer with packet. */
#define REG_APE_RX_POOL_MODE_STATUS_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010214) /*  */
#define REG_APE_RX_POOL_RETIRE_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010218) /* Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
#define REG_APE_RX_POOL_FREE_POINTER_2 ((volatile BCM5719_APE_H_uint32_t*)0xc001021c) /*  */
#define REG_APE_TX_TO_NET_POOL_MODE_STATUS_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010220) /*  */
#define REG_APE_TX_TO_NET_BUFFER_ALLOCATOR_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010224) /*  */
#define REG_APE_TX_TO_NET_BUFFER_RETURN_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010228) /*  */
#define REG_APE_TX_TO_NET_BUFFER_RING_2 ((volatile BCM5719_APE_H_uint32_t*)0xc001022c) /*  */
#define REG_APE_RXBUFOFFSET_FUNC3 ((volatile BCM5719_APE_H_uint32_t*)0xc0010300) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
#define REG_APE_TX_TO_NET_DOORBELL_FUNC3 ((volatile BCM5719_APE_H_uint32_t*)0xc0010304) /* Written on APE TX to network after filling 0xA002 buffer with packet. */
#define REG_APE_RX_POOL_MODE_STATUS_3 ((volatile BCM5719_APE_H_uint32_t*)0xc0010314) /*  */
#define REG_APE_RX_POOL_RETIRE_3 ((volatile BCM5719_APE_H_uint32_t*)0xc0010318) /* Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
#define REG_APE_RX_POOL_FREE_POINTER_3 ((volatile BCM5719_APE_H_uint32_t*)0xc001031c) /*  */
#define REG_APE_TX_TO_NET_POOL_MODE_STATUS_3 ((volatile BCM5719_APE_H_uint32_t*)0xc0010320) /*  */
#define REG_APE_TX_TO_NET_BUFFER_ALLOCATOR_3 ((volatile BCM5719_APE_H_uint32_t*)0xc0010324) /*  */
#define REG_APE_TX_TO_NET_BUFFER_RETURN_3 ((volatile BCM5719_APE_H_uint32_t*)0xc0010328) /*  */
#define REG_APE_TX_TO_NET_BUFFER_RING_3 ((volatile BCM5719_APE_H_uint32_t*)0xc001032c) /*  */
/** @brief Component definition for @ref APE. */
typedef struct APE_t {
    /** @brief More of these bits can be found in diagnostic utilities, but they don't seem too interesting. */
    RegAPEMode_t Mode;

    /** @brief  */
    RegAPEStatus_t Status;

    /** @brief Related to APE fastboot. In that case the value of it is an APE memory address in the code region. If Fast Boot is set, and the low two bits of this are not 0b10, ROM hangs (you have to OR 0x2 into the address). Otherwise, they are masked off and the resulting value is used as the reset vector. The resulting value is also stored in this register (i.e., the low two bits are cleared).  */
    RegAPEGpioMessage_t GpioMessage;

    /** @brief  */
    RegAPEEvent_t Event;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_16[1];

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. The fields are block numbers (block size 128 bytes). */
    RegAPERxbufoffset_t RxbufoffsetFunc0;

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
    RegAPERxbufoffset_t RxbufoffsetFunc1;

    /** @brief Written on APE TX to network after filling 0xA002 buffer with packet. */
    RegAPETxToNetDoorbell_t TxToNetDoorbellFunc0;

    /** @brief APE TX Status. */
    RegAPETxState0_t TxState0;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_36[2];

    /** @brief Expansion for MODE */
    RegAPEMode2_t Mode2;

    /** @brief  */
    RegAPEStatus2_t Status2;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_52[6];

    /** @brief See  */
    RegAPELockGrantObsolete_t LockGrantObsolete;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_80[10];

    /** @brief  */
    RegAPERxPoolModeStatus_t RxPoolModeStatus0;

    /** @brief  */
    RegAPERxPoolModeStatus_t RxPoolModeStatus1;

    /** @brief Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
    RegAPERxPoolRetire_t RxPoolRetire0;

    /** @brief  */
    RegAPERxPoolFreePointer_t RxPoolFreePointer0;

    /** @brief Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
    RegAPERxPoolRetire_t RxPoolRetire1;

    /** @brief  */
    RegAPETxToNetPoolModeStatus_t TxToNetPoolModeStatus0;

    /** @brief  */
    RegAPETxToNetBufferAllocator_t TxToNetBufferAllocator0;

    /** @brief  */
    RegAPETxToNetBufferReturn_t TxToNetBufferReturn0;

    /** @brief  */
    RegAPETxToNetBufferRing_t TxToNetBufferRing0;

    /** @brief  */
    RegAPERxPoolFreePointer_t RxPoolFreePointer1;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_160[2];

    /** @brief Unknown, monotonically increasing value. Increases at a rate of 1MHz. */
    RegAPETick1mhz_t Tick1mhz;

    /** @brief Unknown, monotonically increasing value. Increases at a rate of 1KHz. */
    RegAPETick1khz_t Tick1khz;

    /** @brief Unknown, monotonically increasing value. Increases at a rate of 10Hz. */
    RegAPETick10hz_t Tick10hz;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_180[1];

    /** @brief  */
    RegAPEGpio_t Gpio;

    /** @brief TODO: See diag for field info. */
    RegAPEGint_t Gint;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_192[10];

    /** @brief  */
    RegAPEOtpControl_t OtpControl;

    /** @brief  */
    RegAPEOtpStatus_t OtpStatus;

    /** @brief  */
    RegAPEOtpAddr_t OtpAddr;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_244[1];

    /** @brief  */
    RegAPEOtpReadData_t OtpReadData;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_252[3];

    /** @brief Seems CPU control related. */
    RegAPECpuStatus_t CpuStatus;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_268[1];

    /** @brief  */
    RegAPETxToNetPoolModeStatus_t TxToNetPoolModeStatus1;

    /** @brief  */
    RegAPETxToNetBufferAllocator_t TxToNetBufferAllocator1;

    /** @brief  */
    RegAPETxToNetBufferReturn_t TxToNetBufferReturn1;

    /** @brief  */
    RegAPETxToNetBufferRing_t TxToNetBufferRing1;

    /** @brief Written on APE TX to network after filling 0xA002 buffer with packet. */
    RegAPETxToNetDoorbell_t TxToNetDoorbellFunc1;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_292[55];

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
    RegAPERxbufoffset_t RxbufoffsetFunc2;

    /** @brief Written on APE TX to network after filling 0xA002 buffer with packet. */
    RegAPETxToNetDoorbell_t TxToNetDoorbellFunc2;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_520[3];

    /** @brief  */
    RegAPERxPoolModeStatus_t RxPoolModeStatus2;

    /** @brief Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
    RegAPERxPoolRetire_t RxPoolRetire2;

    /** @brief  */
    RegAPERxPoolFreePointer_t RxPoolFreePointer2;

    /** @brief  */
    RegAPETxToNetPoolModeStatus_t TxToNetPoolModeStatus2;

    /** @brief  */
    RegAPETxToNetBufferAllocator_t TxToNetBufferAllocator2;

    /** @brief  */
    RegAPETxToNetBufferReturn_t TxToNetBufferReturn2;

    /** @brief  */
    RegAPETxToNetBufferRing_t TxToNetBufferRing2;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_560[52];

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
    RegAPERxbufoffset_t RxbufoffsetFunc3;

    /** @brief Written on APE TX to network after filling 0xA002 buffer with packet. */
    RegAPETxToNetDoorbell_t TxToNetDoorbellFunc3;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_776[3];

    /** @brief  */
    RegAPERxPoolModeStatus_t RxPoolModeStatus3;

    /** @brief Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
    RegAPERxPoolRetire_t RxPoolRetire3;

    /** @brief  */
    RegAPERxPoolFreePointer_t RxPoolFreePointer3;

    /** @brief  */
    RegAPETxToNetPoolModeStatus_t TxToNetPoolModeStatus3;

    /** @brief  */
    RegAPETxToNetBufferAllocator_t TxToNetBufferAllocator3;

    /** @brief  */
    RegAPETxToNetBufferReturn_t TxToNetBufferReturn3;

    /** @brief  */
    RegAPETxToNetBufferRing_t TxToNetBufferRing3;

#ifdef CXX_SIMULATOR
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    APE_t() : mIndexReadCallback(0), mIndexReadCallbackArgs(0), mIndexWriteCallback(0), mIndexWriteCallbackArgs(0)
    {
        Mode.r32.setComponentOffset(0x0);
        Status.r32.setComponentOffset(0x4);
        GpioMessage.r32.setComponentOffset(0x8);
        Event.r32.setComponentOffset(0xc);
        for(int i = 0; i < 1; i++)
        {
            reserved_16[i].setComponentOffset(0x10 + (i * 4));
        }
        RxbufoffsetFunc0.r32.setName("RxbufoffsetFunc0");
        RxbufoffsetFunc0.r32.setComponentOffset(0x14);
        RxbufoffsetFunc1.r32.setName("RxbufoffsetFunc1");
        RxbufoffsetFunc1.r32.setComponentOffset(0x18);
        TxToNetDoorbellFunc0.r32.setName("TxToNetDoorbellFunc0");
        TxToNetDoorbellFunc0.r32.setComponentOffset(0x1c);
        TxState0.r32.setComponentOffset(0x20);
        for(int i = 0; i < 2; i++)
        {
            reserved_36[i].setComponentOffset(0x24 + (i * 4));
        }
        Mode2.r32.setComponentOffset(0x2c);
        Status2.r32.setComponentOffset(0x30);
        for(int i = 0; i < 6; i++)
        {
            reserved_52[i].setComponentOffset(0x34 + (i * 4));
        }
        LockGrantObsolete.r32.setComponentOffset(0x4c);
        for(int i = 0; i < 10; i++)
        {
            reserved_80[i].setComponentOffset(0x50 + (i * 4));
        }
        RxPoolModeStatus0.r32.setName("RxPoolModeStatus0");
        RxPoolModeStatus0.r32.setComponentOffset(0x78);
        RxPoolModeStatus1.r32.setName("RxPoolModeStatus1");
        RxPoolModeStatus1.r32.setComponentOffset(0x7c);
        RxPoolRetire0.r32.setName("RxPoolRetire0");
        RxPoolRetire0.r32.setComponentOffset(0x80);
        RxPoolFreePointer0.r32.setName("RxPoolFreePointer0");
        RxPoolFreePointer0.r32.setComponentOffset(0x84);
        RxPoolRetire1.r32.setName("RxPoolRetire1");
        RxPoolRetire1.r32.setComponentOffset(0x88);
        TxToNetPoolModeStatus0.r32.setName("TxToNetPoolModeStatus0");
        TxToNetPoolModeStatus0.r32.setComponentOffset(0x8c);
        TxToNetBufferAllocator0.r32.setName("TxToNetBufferAllocator0");
        TxToNetBufferAllocator0.r32.setComponentOffset(0x90);
        TxToNetBufferReturn0.r32.setName("TxToNetBufferReturn0");
        TxToNetBufferReturn0.r32.setComponentOffset(0x94);
        TxToNetBufferRing0.r32.setName("TxToNetBufferRing0");
        TxToNetBufferRing0.r32.setComponentOffset(0x98);
        RxPoolFreePointer1.r32.setName("RxPoolFreePointer1");
        RxPoolFreePointer1.r32.setComponentOffset(0x9c);
        for(int i = 0; i < 2; i++)
        {
            reserved_160[i].setComponentOffset(0xa0 + (i * 4));
        }
        Tick1mhz.r32.setComponentOffset(0xa8);
        Tick1khz.r32.setComponentOffset(0xac);
        Tick10hz.r32.setComponentOffset(0xb0);
        for(int i = 0; i < 1; i++)
        {
            reserved_180[i].setComponentOffset(0xb4 + (i * 4));
        }
        Gpio.r32.setComponentOffset(0xb8);
        Gint.r32.setComponentOffset(0xbc);
        for(int i = 0; i < 10; i++)
        {
            reserved_192[i].setComponentOffset(0xc0 + (i * 4));
        }
        OtpControl.r32.setComponentOffset(0xe8);
        OtpStatus.r32.setComponentOffset(0xec);
        OtpAddr.r32.setComponentOffset(0xf0);
        for(int i = 0; i < 1; i++)
        {
            reserved_244[i].setComponentOffset(0xf4 + (i * 4));
        }
        OtpReadData.r32.setComponentOffset(0xf8);
        for(int i = 0; i < 3; i++)
        {
            reserved_252[i].setComponentOffset(0xfc + (i * 4));
        }
        CpuStatus.r32.setComponentOffset(0x108);
        for(int i = 0; i < 1; i++)
        {
            reserved_268[i].setComponentOffset(0x10c + (i * 4));
        }
        TxToNetPoolModeStatus1.r32.setName("TxToNetPoolModeStatus1");
        TxToNetPoolModeStatus1.r32.setComponentOffset(0x110);
        TxToNetBufferAllocator1.r32.setName("TxToNetBufferAllocator1");
        TxToNetBufferAllocator1.r32.setComponentOffset(0x114);
        TxToNetBufferReturn1.r32.setName("TxToNetBufferReturn1");
        TxToNetBufferReturn1.r32.setComponentOffset(0x118);
        TxToNetBufferRing1.r32.setName("TxToNetBufferRing1");
        TxToNetBufferRing1.r32.setComponentOffset(0x11c);
        TxToNetDoorbellFunc1.r32.setName("TxToNetDoorbellFunc1");
        TxToNetDoorbellFunc1.r32.setComponentOffset(0x120);
        for(int i = 0; i < 55; i++)
        {
            reserved_292[i].setComponentOffset(0x124 + (i * 4));
        }
        RxbufoffsetFunc2.r32.setName("RxbufoffsetFunc2");
        RxbufoffsetFunc2.r32.setComponentOffset(0x200);
        TxToNetDoorbellFunc2.r32.setName("TxToNetDoorbellFunc2");
        TxToNetDoorbellFunc2.r32.setComponentOffset(0x204);
        for(int i = 0; i < 3; i++)
        {
            reserved_520[i].setComponentOffset(0x208 + (i * 4));
        }
        RxPoolModeStatus2.r32.setName("RxPoolModeStatus2");
        RxPoolModeStatus2.r32.setComponentOffset(0x214);
        RxPoolRetire2.r32.setName("RxPoolRetire2");
        RxPoolRetire2.r32.setComponentOffset(0x218);
        RxPoolFreePointer2.r32.setName("RxPoolFreePointer2");
        RxPoolFreePointer2.r32.setComponentOffset(0x21c);
        TxToNetPoolModeStatus2.r32.setName("TxToNetPoolModeStatus2");
        TxToNetPoolModeStatus2.r32.setComponentOffset(0x220);
        TxToNetBufferAllocator2.r32.setName("TxToNetBufferAllocator2");
        TxToNetBufferAllocator2.r32.setComponentOffset(0x224);
        TxToNetBufferReturn2.r32.setName("TxToNetBufferReturn2");
        TxToNetBufferReturn2.r32.setComponentOffset(0x228);
        TxToNetBufferRing2.r32.setName("TxToNetBufferRing2");
        TxToNetBufferRing2.r32.setComponentOffset(0x22c);
        for(int i = 0; i < 52; i++)
        {
            reserved_560[i].setComponentOffset(0x230 + (i * 4));
        }
        RxbufoffsetFunc3.r32.setName("RxbufoffsetFunc3");
        RxbufoffsetFunc3.r32.setComponentOffset(0x300);
        TxToNetDoorbellFunc3.r32.setName("TxToNetDoorbellFunc3");
        TxToNetDoorbellFunc3.r32.setComponentOffset(0x304);
        for(int i = 0; i < 3; i++)
        {
            reserved_776[i].setComponentOffset(0x308 + (i * 4));
        }
        RxPoolModeStatus3.r32.setName("RxPoolModeStatus3");
        RxPoolModeStatus3.r32.setComponentOffset(0x314);
        RxPoolRetire3.r32.setName("RxPoolRetire3");
        RxPoolRetire3.r32.setComponentOffset(0x318);
        RxPoolFreePointer3.r32.setName("RxPoolFreePointer3");
        RxPoolFreePointer3.r32.setComponentOffset(0x31c);
        TxToNetPoolModeStatus3.r32.setName("TxToNetPoolModeStatus3");
        TxToNetPoolModeStatus3.r32.setComponentOffset(0x320);
        TxToNetBufferAllocator3.r32.setName("TxToNetBufferAllocator3");
        TxToNetBufferAllocator3.r32.setComponentOffset(0x324);
        TxToNetBufferReturn3.r32.setName("TxToNetBufferReturn3");
        TxToNetBufferReturn3.r32.setComponentOffset(0x328);
        TxToNetBufferRing3.r32.setName("TxToNetBufferRing3");
        TxToNetBufferRing3.r32.setComponentOffset(0x32c);
    }
    void print()
    {
        Mode.print();
        Status.print();
        GpioMessage.print();
        Event.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_16[i].print();
        }
        RxbufoffsetFunc0.print();
        RxbufoffsetFunc1.print();
        TxToNetDoorbellFunc0.print();
        TxState0.print();
        for(int i = 0; i < 2; i++)
        {
            reserved_36[i].print();
        }
        Mode2.print();
        Status2.print();
        for(int i = 0; i < 6; i++)
        {
            reserved_52[i].print();
        }
        LockGrantObsolete.print();
        for(int i = 0; i < 10; i++)
        {
            reserved_80[i].print();
        }
        RxPoolModeStatus0.print();
        RxPoolModeStatus1.print();
        RxPoolRetire0.print();
        RxPoolFreePointer0.print();
        RxPoolRetire1.print();
        TxToNetPoolModeStatus0.print();
        TxToNetBufferAllocator0.print();
        TxToNetBufferReturn0.print();
        TxToNetBufferRing0.print();
        RxPoolFreePointer1.print();
        for(int i = 0; i < 2; i++)
        {
            reserved_160[i].print();
        }
        Tick1mhz.print();
        Tick1khz.print();
        Tick10hz.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_180[i].print();
        }
        Gpio.print();
        Gint.print();
        for(int i = 0; i < 10; i++)
        {
            reserved_192[i].print();
        }
        OtpControl.print();
        OtpStatus.print();
        OtpAddr.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_244[i].print();
        }
        OtpReadData.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_252[i].print();
        }
        CpuStatus.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_268[i].print();
        }
        TxToNetPoolModeStatus1.print();
        TxToNetBufferAllocator1.print();
        TxToNetBufferReturn1.print();
        TxToNetBufferRing1.print();
        TxToNetDoorbellFunc1.print();
        for(int i = 0; i < 55; i++)
        {
            reserved_292[i].print();
        }
        RxbufoffsetFunc2.print();
        TxToNetDoorbellFunc2.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_520[i].print();
        }
        RxPoolModeStatus2.print();
        RxPoolRetire2.print();
        RxPoolFreePointer2.print();
        TxToNetPoolModeStatus2.print();
        TxToNetBufferAllocator2.print();
        TxToNetBufferReturn2.print();
        TxToNetBufferRing2.print();
        for(int i = 0; i < 52; i++)
        {
            reserved_560[i].print();
        }
        RxbufoffsetFunc3.print();
        TxToNetDoorbellFunc3.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_776[i].print();
        }
        RxPoolModeStatus3.print();
        RxPoolRetire3.print();
        RxPoolFreePointer3.print();
        TxToNetPoolModeStatus3.print();
        TxToNetBufferAllocator3.print();
        TxToNetBufferReturn3.print();
        TxToNetBufferRing3.print();
    }
    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} APE_t;

/** @brief Device APE Registers */
extern volatile APE_t APE;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(APE_t) == 816, "sizeof(APE_t) must be 816");
#endif

#endif /* !BCM5719_APE_H */

/** @} */
