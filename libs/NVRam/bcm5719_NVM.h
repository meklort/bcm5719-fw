////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_NVM.h
///
/// @project    <PROJECT>
///
/// @brief      bcm5719_NVM registers
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

/** @defgroup BCM5719_NVM_H    bcm5719_NVM registers */
/** @addtogroup BCM5719_NVM_H
 * @{
 */
#ifndef BCM5719_NVM_H
#define BCM5719_NVM_H

#include <stdint.h>
#include <bitfields.h>

#ifdef __cplusplus /* Compiling c++ code - uses register wrappers */
#include <CXXRegister.h>
// Redefine standard types and keywords
#define uint8_t  CXXRegister<unsigned char, 0, 8>
#define uint16_t CXXRegister<unsigned short, 0, 16>
#define uint32_t CXXRegister<unsigned int, 0, 32>
#define uint8_t_bitfield(__pos__, __width__)  CXXRegister<unsigned char, __pos__, __width__>
#define uint16_t_bitfield(__pos__, __width__) CXXRegister<unsigned short, __pos__, __width__>
#define uint32_t_bitfield(__pos__, __width__) CXXRegister<unsigned int, __pos__, __width__>
#define union struct
#define volatile
#endif /* __cplusplus */

#define REG_NVM_BASE ((volatile void*)0xc0007000) /* Device Registers */

#define REG_NVM_COMMAND ((volatile uint32_t*)0xc0007000) /*  */
#define     NVM_COMMAND_DONE_SHIFT 3u
#define     NVM_COMMAND_DONE_MASK  0x8u
#define GET_NVM_COMMAND_DONE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVM_COMMAND_DONE(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVM_COMMAND_DOIT_SHIFT 4u
#define     NVM_COMMAND_DOIT_MASK  0x10u
#define GET_NVM_COMMAND_DOIT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVM_COMMAND_DOIT(__val__)  (((__val__) << 4u) & 0x10u)
#define     NVM_COMMAND_WR_SHIFT 5u
#define     NVM_COMMAND_WR_MASK  0x20u
#define GET_NVM_COMMAND_WR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_NVM_COMMAND_WR(__val__)  (((__val__) << 5u) & 0x20u)
#define     NVM_COMMAND_ERASE_SHIFT 6u
#define     NVM_COMMAND_ERASE_MASK  0x40u
#define GET_NVM_COMMAND_ERASE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_NVM_COMMAND_ERASE(__val__)  (((__val__) << 6u) & 0x40u)
#define     NVM_COMMAND_FIRST_SHIFT 7u
#define     NVM_COMMAND_FIRST_MASK  0x80u
#define GET_NVM_COMMAND_FIRST(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_NVM_COMMAND_FIRST(__val__)  (((__val__) << 7u) & 0x80u)
#define     NVM_COMMAND_LAST_SHIFT 8u
#define     NVM_COMMAND_LAST_MASK  0x100u
#define GET_NVM_COMMAND_LAST(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_NVM_COMMAND_LAST(__val__)  (((__val__) << 8u) & 0x100u)
#define     NVM_COMMAND_WRITE_ENABLE_COMMAND_SHIFT 16u
#define     NVM_COMMAND_WRITE_ENABLE_COMMAND_MASK  0x10000u
#define GET_NVM_COMMAND_WRITE_ENABLE_COMMAND(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_NVM_COMMAND_WRITE_ENABLE_COMMAND(__val__)  (((__val__) << 16u) & 0x10000u)
#define     NVM_COMMAND_WRITE_DISABLE_COMMAND_SHIFT 17u
#define     NVM_COMMAND_WRITE_DISABLE_COMMAND_MASK  0x20000u
#define GET_NVM_COMMAND_WRITE_DISABLE_COMMAND(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_NVM_COMMAND_WRITE_DISABLE_COMMAND(__val__)  (((__val__) << 17u) & 0x20000u)

/** @brief Register definition for @ref NVM_t.Command. */ 
 typedef union {
    /** @brief 32bit direct register access. */ 
    uint32_t r32;

    BITFIELD_BEGIN(u, bits)
        /** @brief Padding */ 
        BITFIELD_MEMBER(uint32_t, reserved_2_0, 0, 3)
        /** @brief Sequence completion bit that is asserted when the command requested by assertion of the doit bit has completed. */ 
        BITFIELD_MEMBER(uint32_t, Done, 3, 1)
        /** @brief Command from software to start the defined command. The done bit must be clear before setting this bit. This bit is self clearing and will remain set while the command is active. */ 
        BITFIELD_MEMBER(uint32_t, Doit, 4, 1)
        /** @brief The write/not read command bit. Set to execute write or erase. */ 
        BITFIELD_MEMBER(uint32_t, Wr, 5, 1)
        /** @brief The erase command bit. Set high to execute an erase. This bit is ignored if the wr is clear. */ 
        BITFIELD_MEMBER(uint32_t, Erase, 6, 1)
        /** @brief This bit is passed to the SEE_FSM or SPI_FSM if the pass_mode bit is set */ 
        BITFIELD_MEMBER(uint32_t, First, 7, 1)
        /** @brief When this bit is set, the next command sequence is interpreted as the last one of a burst and any cleanup work is done. */ 
        BITFIELD_MEMBER(uint32_t, Last, 8, 1)
        /** @brief Padding */ 
        BITFIELD_MEMBER(uint32_t, reserved_15_9, 9, 7)
        /** @brief The write enable command bit. Set '1' will make the flash interface state machine generate a write enable command cycle to the flash device to set the write enable bit in the device status register. This command is used for devices with a write protection function. */ 
        BITFIELD_MEMBER(uint32_t, WriteEnableCommand, 16, 1)
        /** @brief The write disable command bit. Set '1' will make the flash interface state machine generate a write disable command cycle to the flash device to clear the write enable bit in the device status register. This command is used for devices with a write protection function. */ 
        BITFIELD_MEMBER(uint32_t, WriteDisableCommand, 17, 1)
    BITFIELD_END(u, bits)
} RegNVMCommand_t;

#define REG_NVM_WRITE ((volatile uint32_t*)0xc0007008) /* 32bits of write data are used when write commands are executed. */
/** @brief Register definition for @ref NVM_t.Write. */ 
 typedef union {
    /** @brief 32bit direct register access. */ 
    uint32_t r32;
} RegNVMWrite_t;

#define REG_NVM_ADDR ((volatile uint32_t*)0xc000700c) /* The 24 bit address for a read or write operation (must be 4 byte aligned). */
/** @brief Register definition for @ref NVM_t.Addr. */ 
 typedef union {
    /** @brief 32bit direct register access. */ 
    uint32_t r32;
} RegNVMAddr_t;

#define REG_NVM_READ ((volatile uint32_t*)0xc0007010) /* 32bits of read data are used when read commands are executed. */
/** @brief Register definition for @ref NVM_t.Read. */ 
 typedef union {
    /** @brief 32bit direct register access. */ 
    uint32_t r32;
} RegNVMRead_t;

#define REG_NVM_NVM_CFG_1 ((volatile uint32_t*)0xc0007014) /*  */
#define     NVM_NVM_CFG_1_FLASH_MODE_SHIFT 0u
#define     NVM_NVM_CFG_1_FLASH_MODE_MASK  0x1u
#define GET_NVM_NVM_CFG_1_FLASH_MODE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVM_NVM_CFG_1_FLASH_MODE(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVM_NVM_CFG_1_BUFFER_MODE_SHIFT 1u
#define     NVM_NVM_CFG_1_BUFFER_MODE_MASK  0x2u
#define GET_NVM_NVM_CFG_1_BUFFER_MODE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVM_NVM_CFG_1_BUFFER_MODE(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVM_NVM_CFG_1_SPI_CLK_DIV_SHIFT 7u
#define     NVM_NVM_CFG_1_SPI_CLK_DIV_MASK  0x780u
#define GET_NVM_NVM_CFG_1_SPI_CLK_DIV(__reg__)  (((__reg__) & 0x780) >> 7u)
#define SET_NVM_NVM_CFG_1_SPI_CLK_DIV(__val__)  (((__val__) << 7u) & 0x780u)
#define     NVM_NVM_CFG_1_PROTECT_MODE_SHIFT 24u
#define     NVM_NVM_CFG_1_PROTECT_MODE_MASK  0x1000000u
#define GET_NVM_NVM_CFG_1_PROTECT_MODE(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_NVM_NVM_CFG_1_PROTECT_MODE(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     NVM_NVM_CFG_1_FLASH_SIZE_SHIFT 25u
#define     NVM_NVM_CFG_1_FLASH_SIZE_MASK  0x2000000u
#define GET_NVM_NVM_CFG_1_FLASH_SIZE(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_NVM_NVM_CFG_1_FLASH_SIZE(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     NVM_NVM_CFG_1_PAGE_SIZE_SHIFT 28u
#define     NVM_NVM_CFG_1_PAGE_SIZE_MASK  0x70000000u
#define GET_NVM_NVM_CFG_1_PAGE_SIZE(__reg__)  (((__reg__) & 0x70000000) >> 28u)
#define SET_NVM_NVM_CFG_1_PAGE_SIZE(__val__)  (((__val__) << 28u) & 0x70000000u)
#define     NVM_NVM_CFG_1_PAGE_SIZE_256_BYTES 0x0u
#define     NVM_NVM_CFG_1_PAGE_SIZE_512_BYTES 0x1u
#define     NVM_NVM_CFG_1_PAGE_SIZE_1024_BYTES 0x2u
#define     NVM_NVM_CFG_1_PAGE_SIZE_2048_BYTES 0x3u
#define     NVM_NVM_CFG_1_PAGE_SIZE_4096_BYTES 0x4u
#define     NVM_NVM_CFG_1_PAGE_SIZE_264_BYTES 0x5u


/** @brief Register definition for @ref NVM_t.NvmCfg1. */ 
 typedef union {
    /** @brief 32bit direct register access. */ 
    uint32_t r32;

    BITFIELD_BEGIN(u, bits)
        /** @brief Enable Flash Interface mode. */ 
        BITFIELD_MEMBER(uint32_t, FlashMode, 0, 1)
        /** @brief Enable SSRAM Buffered Interface mode. */ 
        BITFIELD_MEMBER(uint32_t, BufferMode, 1, 1)
        /** @brief Padding */ 
        BITFIELD_MEMBER(uint32_t, reserved_6_2, 2, 5)
        /** @brief The equation to calculate the clock freq. for SCK is: CORE_CLK / ((SPI_CLK_DIV + 1) * 2) */ 
        BITFIELD_MEMBER(uint32_t, SPICLKDIV, 7, 4)
        /** @brief Padding */ 
        BITFIELD_MEMBER(uint32_t, reserved_23_11, 11, 13)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ProtectMode, 24, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, FlashSize, 25, 1)
        /** @brief Padding */ 
        BITFIELD_MEMBER(uint32_t, reserved_27_26, 26, 2)
        /** @brief These bits indicate the page size of the attached flash device. They are set automatically depending on the chosen flash as indicated by the strapping option pins. */ 
        BITFIELD_MEMBER(uint32_t, PageSize, 28, 3)
    BITFIELD_END(u, bits)
} RegNVMNvmCfg1_t;

#define REG_NVM_SOFTWARE_ARBITRATION ((volatile uint32_t*)0xc0007020) /*  */
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET0_SHIFT 0u
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET0_MASK  0x1u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_SET0(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_SET0(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET1_SHIFT 1u
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET1_MASK  0x2u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_SET1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_SET1(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET2_SHIFT 2u
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET2_MASK  0x4u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_SET2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_SET2(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET3_SHIFT 3u
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET3_MASK  0x8u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_SET3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_SET3(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR0_SHIFT 4u
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR0_MASK  0x10u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_CLR0(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_CLR0(__val__)  (((__val__) << 4u) & 0x10u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR1_SHIFT 5u
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR1_MASK  0x20u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_CLR1(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_CLR1(__val__)  (((__val__) << 5u) & 0x20u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR2_SHIFT 6u
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR2_MASK  0x40u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_CLR2(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_CLR2(__val__)  (((__val__) << 6u) & 0x40u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR3_SHIFT 7u
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR3_MASK  0x80u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_CLR3(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_CLR3(__val__)  (((__val__) << 7u) & 0x80u)
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON0_SHIFT 8u
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK  0x100u
#define GET_NVM_SOFTWARE_ARBITRATION_ARB_WON0(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_NVM_SOFTWARE_ARBITRATION_ARB_WON0(__val__)  (((__val__) << 8u) & 0x100u)
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON1_SHIFT 9u
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK  0x200u
#define GET_NVM_SOFTWARE_ARBITRATION_ARB_WON1(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_NVM_SOFTWARE_ARBITRATION_ARB_WON1(__val__)  (((__val__) << 9u) & 0x200u)
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON2_SHIFT 10u
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK  0x400u
#define GET_NVM_SOFTWARE_ARBITRATION_ARB_WON2(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_NVM_SOFTWARE_ARBITRATION_ARB_WON2(__val__)  (((__val__) << 10u) & 0x400u)
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON3_SHIFT 11u
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK  0x800u
#define GET_NVM_SOFTWARE_ARBITRATION_ARB_WON3(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_NVM_SOFTWARE_ARBITRATION_ARB_WON3(__val__)  (((__val__) << 11u) & 0x800u)

/** @brief Register definition for @ref NVM_t.SoftwareArbitration. */ 
 typedef union {
    /** @brief 32bit direct register access. */ 
    uint32_t r32;

    BITFIELD_BEGIN(u, bits)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ReqSet0, 0, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ReqSet1, 1, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ReqSet2, 2, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ReqSet3, 3, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ReqClr0, 4, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ReqClr1, 5, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ReqClr2, 6, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ReqClr3, 7, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ArbWon0, 8, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ArbWon1, 9, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ArbWon2, 10, 1)
        /** @brief  */ 
        BITFIELD_MEMBER(uint32_t, ArbWon3, 11, 1)
    BITFIELD_END(u, bits)
} RegNVMSoftwareArbitration_t;

#define REG_NVM_ACCESS ((volatile uint32_t*)0xc0007024) /*  */
#define     NVM_ACCESS_ENABLE_SHIFT 0u
#define     NVM_ACCESS_ENABLE_MASK  0x1u
#define GET_NVM_ACCESS_ENABLE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVM_ACCESS_ENABLE(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVM_ACCESS_WRITE_ENABLE_SHIFT 1u
#define     NVM_ACCESS_WRITE_ENABLE_MASK  0x2u
#define GET_NVM_ACCESS_WRITE_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVM_ACCESS_WRITE_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)

/** @brief Register definition for @ref NVM_t.Access. */ 
 typedef union {
    /** @brief 32bit direct register access. */ 
    uint32_t r32;

    BITFIELD_BEGIN(u, bits)
        /** @brief When 1, allows the NVRAM write command to be issued even if the NVRAM write enable bit 21 of the mode control register 0x6800. */ 
        BITFIELD_MEMBER(uint32_t, Enable, 0, 1)
        /** @brief When 0, prevents write access to all other NVRAM registers, except for the Software arbitration register. */ 
        BITFIELD_MEMBER(uint32_t, WriteEnable, 1, 1)
    BITFIELD_END(u, bits)
} RegNVMAccess_t;

/** @brief Component definition for @ref NVM. */ 
typedef struct {
    /** @brief  */ 
    RegNVMCommand_t Command;

    /** @brief Reserved bytes to pad out data structure. */ 
    uint32_t reserved_4[1];

    /** @brief 32bits of write data are used when write commands are executed. */ 
    RegNVMWrite_t Write;

    /** @brief The 24 bit address for a read or write operation (must be 4 byte aligned). */ 
    RegNVMAddr_t Addr;

    /** @brief 32bits of read data are used when read commands are executed. */ 
    RegNVMRead_t Read;

    /** @brief  */ 
    RegNVMNvmCfg1_t NvmCfg1;

    /** @brief Reserved bytes to pad out data structure. */ 
    uint32_t reserved_24[2];

    /** @brief  */ 
    RegNVMSoftwareArbitration_t SoftwareArbitration;

    /** @brief  */ 
    RegNVMAccess_t Access;

} NVM_t;

/** @brief Device Registers */ 
extern volatile NVM_t NVM;


#ifdef __cplusplus /* Compiling c++ code - uses register wrappers */
#undef uint8_t
#undef uint16_t
#undef uint32_t
#undef union
#undef volatile
#endif /* __cplusplus */

#endif /* !BCM5719_NVM_H */

/** @} */
