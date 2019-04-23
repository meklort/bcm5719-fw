////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_DEVICE.h
///
/// @project    ape
///
/// @brief      APE_DEVICE
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

/** @defgroup APE_DEVICE_H    APE_DEVICE */
/** @addtogroup APE_DEVICE_H
 * @{
 */
#ifndef APE_DEVICE_H
#define APE_DEVICE_H

#include <stdint.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_DEVICE_sim(void* base);
void init_APE_DEVICE(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_DEVICE_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_DEVICE_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_DEVICE_H_uint32_t;
#define APE_DEVICE_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_DEVICE_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_DEVICE_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_DEVICE_H_uint8_t;
typedef uint16_t APE_DEVICE_H_uint16_t;
typedef uint32_t APE_DEVICE_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_DEVICE_BASE ((volatile void*)0xa0040000) /* Device Registers, function 0 */
#define REG_DEVICE_SIZE (sizeof(DEVICE_t))

#define REG_DEVICE_MISCELLANEOUS_HOST_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa0040068) /*  */
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_CLEAR_INTERRUPT_SHIFT 0u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_CLEAR_INTERRUPT_MASK  0x1u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_CLEAR_INTERRUPT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_CLEAR_INTERRUPT(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_MASK_INTERRUPT_SHIFT 1u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_MASK_INTERRUPT_MASK  0x2u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_MASK_INTERRUPT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_MASK_INTERRUPT(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_ENDIAN_BYTE_SWAP_SHIFT 2u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_ENDIAN_BYTE_SWAP_MASK  0x4u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_ENDIAN_BYTE_SWAP(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_ENDIAN_BYTE_SWAP(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_ENDIAN_WORD_SWAP_SHIFT 3u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_ENDIAN_WORD_SWAP_MASK  0x8u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_ENDIAN_WORD_SWAP(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_ENDIAN_WORD_SWAP(__val__)  (((__val__) << 3u) & 0x8u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_PCI_STATE_REGISTER_READ_DIV_WRITE_CAPABILITY_SHIFT 4u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_PCI_STATE_REGISTER_READ_DIV_WRITE_CAPABILITY_MASK  0x10u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_PCI_STATE_REGISTER_READ_DIV_WRITE_CAPABILITY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_PCI_STATE_REGISTER_READ_DIV_WRITE_CAPABILITY(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_CLOCK_CONTROL_REGISTER_READ_DIV_WRITE_CAPABILITY_SHIFT 5u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_CLOCK_CONTROL_REGISTER_READ_DIV_WRITE_CAPABILITY_MASK  0x20u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_CLOCK_CONTROL_REGISTER_READ_DIV_WRITE_CAPABILITY(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_CLOCK_CONTROL_REGISTER_READ_DIV_WRITE_CAPABILITY(__val__)  (((__val__) << 5u) & 0x20u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_REGISTER_WORD_SWAP_SHIFT 6u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_REGISTER_WORD_SWAP_MASK  0x40u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_REGISTER_WORD_SWAP(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_REGISTER_WORD_SWAP(__val__)  (((__val__) << 6u) & 0x40u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_INDIRECT_ACCESS_SHIFT 7u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_INDIRECT_ACCESS_MASK  0x80u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_INDIRECT_ACCESS(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_INDIRECT_ACCESS(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_MASK_INTERRUPT_MODE_SHIFT 8u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_MASK_INTERRUPT_MODE_MASK  0x100u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_MASK_INTERRUPT_MODE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_MASK_INTERRUPT_MODE(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_TAGGED_STATUS_MODE_SHIFT 9u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_TAGGED_STATUS_MODE_MASK  0x200u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_TAGGED_STATUS_MODE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_TAGGED_STATUS_MODE(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_RCB_CHECK_SHIFT 10u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_RCB_CHECK_MASK  0x400u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_RCB_CHECK(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_RCB_CHECK(__val__)  (((__val__) << 10u) & 0x400u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_INTERRUPT_CHECK_SHIFT 11u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_INTERRUPT_CHECK_MASK  0x800u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_INTERRUPT_CHECK(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_INTERRUPT_CHECK(__val__)  (((__val__) << 11u) & 0x800u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_BYTE_ENABLE_RULE_CHECK_SHIFT 12u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_BYTE_ENABLE_RULE_CHECK_MASK  0x1000u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_BYTE_ENABLE_RULE_CHECK(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_BYTE_ENABLE_RULE_CHECK(__val__)  (((__val__) << 12u) & 0x1000u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_BOUNDARY_CHECK_SHIFT 13u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_BOUNDARY_CHECK_MASK  0x2000u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_BOUNDARY_CHECK(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_BOUNDARY_CHECK(__val__)  (((__val__) << 13u) & 0x2000u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_LOG_HEADER_OVERFLOW_SHIFT 14u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_LOG_HEADER_OVERFLOW_MASK  0x4000u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_LOG_HEADER_OVERFLOW(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_LOG_HEADER_OVERFLOW(__val__)  (((__val__) << 14u) & 0x4000u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_TLP_MINOR_ERROR_TOLERANCE_SHIFT 15u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_TLP_MINOR_ERROR_TOLERANCE_MASK  0x8000u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_TLP_MINOR_ERROR_TOLERANCE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ENABLE_TLP_MINOR_ERROR_TOLERANCE(__val__)  (((__val__) << 15u) & 0x8000u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_METAL_REV_ID_SHIFT 16u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_METAL_REV_ID_MASK  0xff0000u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_METAL_REV_ID(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_METAL_REV_ID(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_METAL_REV_ID_0 0x0u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_METAL_REV_ID_1 0x1u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_METAL_REV_ID_2 0x2u

#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ALL_LAYER_ID_SHIFT 24u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ALL_LAYER_ID_MASK  0xf000000u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ALL_LAYER_ID(__reg__)  (((__reg__) & 0xf000000) >> 24u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_ALL_LAYER_ID(__val__)  (((__val__) << 24u) & 0xf000000u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ALL_LAYER_ID_A 0x0u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ALL_LAYER_ID_B 0x1u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_ALL_LAYER_ID_C 0x2u

#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_PRODUCT_ID_SHIFT 28u
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_PRODUCT_ID_MASK  0xf0000000u
#define GET_DEVICE_MISCELLANEOUS_HOST_CONTROL_PRODUCT_ID(__reg__)  (((__reg__) & 0xf0000000) >> 28u)
#define SET_DEVICE_MISCELLANEOUS_HOST_CONTROL_PRODUCT_ID(__val__)  (((__val__) << 28u) & 0xf0000000u)
#define     DEVICE_MISCELLANEOUS_HOST_CONTROL_PRODUCT_ID_NEW_PRODUCT_MAPPING 0xfu


/** @brief Register definition for @ref DEVICE_t.MiscellaneousHostControl. */
typedef register_container RegDEVICEMiscellaneousHostControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Setting this bit will clear interrupt as long as the mask interrupt bit is not set. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ClearInterrupt, 0, 1)
        /** @brief Setting this bit will mask future interrupt events from being generated. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MaskInterrupt, 1, 1)
        /** @brief Set this bit to enable endian byte swapping when accessing through PCIE target interface. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableEndianByteSwap, 2, 1)
        /** @brief Set this bit to enable endian word swapping when accessing through PCIE target interface. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableEndianWordSwap, 3, 1)
        /** @brief Set this bit to enable PCI state register read/ write capability, otherwise the register is read only. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnablePCIStateRegisterRead_DIV_WriteCapability, 4, 1)
        /** @brief Set this bit enable clock control register read/ write capability, otherwise, the clock control register is read only. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableClockControlRegisterRead_DIV_WriteCapability, 5, 1)
        /** @brief Set this bit to enable word swapping when accessing registers through the PCI target device. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableRegisterWordSwap, 6, 1)
        /** @brief Set this bit to enable indirect addressing mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableIndirectAccess, 7, 1)
        /** @brief When set, the interrupt is masked. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MaskInterruptMode, 8, 1)
        /** @brief When set, an unique 8-bit tag value will be inserted into the Status block status tag. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTaggedStatusMode, 9, 1)
        /** @brief Set this bit to enable RCB check. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RCBCheck, 10, 1)
        /** @brief Set this bit to enable the interrupt check. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InterruptCheck, 11, 1)
        /** @brief Set this bit to enable the byte enable rule check. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ByteEnableRuleCheck, 12, 1)
        /** @brief Set this bit to enable crossing 4 KB boundary check. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BoundaryCheck, 13, 1)
        /** @brief Set this bit to enable log header due to overflow. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LogHeaderOverflow, 14, 1)
        /** @brief Set this bit to enable TLP minor error tolerance (ATTR/TC/LOCK command). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTLPMinorErrorTolerance, 15, 1)
        /** @brief Metal Rev Number */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MetalRevID, 16, 8)
        /** @brief External All Layer Revision ID. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AllLayerID, 24, 4)
        /** @brief Product ID. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ProductID, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief Product ID. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ProductID, 28, 4)
        /** @brief External All Layer Revision ID. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AllLayerID, 24, 4)
        /** @brief Metal Rev Number */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MetalRevID, 16, 8)
        /** @brief Set this bit to enable TLP minor error tolerance (ATTR/TC/LOCK command). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTLPMinorErrorTolerance, 15, 1)
        /** @brief Set this bit to enable log header due to overflow. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LogHeaderOverflow, 14, 1)
        /** @brief Set this bit to enable crossing 4 KB boundary check. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BoundaryCheck, 13, 1)
        /** @brief Set this bit to enable the byte enable rule check. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ByteEnableRuleCheck, 12, 1)
        /** @brief Set this bit to enable the interrupt check. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InterruptCheck, 11, 1)
        /** @brief Set this bit to enable RCB check. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RCBCheck, 10, 1)
        /** @brief When set, an unique 8-bit tag value will be inserted into the Status block status tag. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTaggedStatusMode, 9, 1)
        /** @brief When set, the interrupt is masked. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MaskInterruptMode, 8, 1)
        /** @brief Set this bit to enable indirect addressing mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableIndirectAccess, 7, 1)
        /** @brief Set this bit to enable word swapping when accessing registers through the PCI target device. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableRegisterWordSwap, 6, 1)
        /** @brief Set this bit enable clock control register read/ write capability, otherwise, the clock control register is read only. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableClockControlRegisterRead_DIV_WriteCapability, 5, 1)
        /** @brief Set this bit to enable PCI state register read/ write capability, otherwise the register is read only. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnablePCIStateRegisterRead_DIV_WriteCapability, 4, 1)
        /** @brief Set this bit to enable endian word swapping when accessing through PCIE target interface. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableEndianWordSwap, 3, 1)
        /** @brief Set this bit to enable endian byte swapping when accessing through PCIE target interface. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableEndianByteSwap, 2, 1)
        /** @brief Setting this bit will mask future interrupt events from being generated. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MaskInterrupt, 1, 1)
        /** @brief Setting this bit will clear interrupt as long as the mask interrupt bit is not set. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ClearInterrupt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MiscellaneousHostControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMiscellaneousHostControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.MiscellaneousHostControl. */
        r32.setName("MiscellaneousHostControl");
        bits.ClearInterrupt.setBaseRegister(&r32);
        bits.ClearInterrupt.setName("ClearInterrupt");
        bits.MaskInterrupt.setBaseRegister(&r32);
        bits.MaskInterrupt.setName("MaskInterrupt");
        bits.EnableEndianByteSwap.setBaseRegister(&r32);
        bits.EnableEndianByteSwap.setName("EnableEndianByteSwap");
        bits.EnableEndianWordSwap.setBaseRegister(&r32);
        bits.EnableEndianWordSwap.setName("EnableEndianWordSwap");
        bits.EnablePCIStateRegisterRead_DIV_WriteCapability.setBaseRegister(&r32);
        bits.EnablePCIStateRegisterRead_DIV_WriteCapability.setName("EnablePCIStateRegisterRead_DIV_WriteCapability");
        bits.EnableClockControlRegisterRead_DIV_WriteCapability.setBaseRegister(&r32);
        bits.EnableClockControlRegisterRead_DIV_WriteCapability.setName("EnableClockControlRegisterRead_DIV_WriteCapability");
        bits.EnableRegisterWordSwap.setBaseRegister(&r32);
        bits.EnableRegisterWordSwap.setName("EnableRegisterWordSwap");
        bits.EnableIndirectAccess.setBaseRegister(&r32);
        bits.EnableIndirectAccess.setName("EnableIndirectAccess");
        bits.MaskInterruptMode.setBaseRegister(&r32);
        bits.MaskInterruptMode.setName("MaskInterruptMode");
        bits.EnableTaggedStatusMode.setBaseRegister(&r32);
        bits.EnableTaggedStatusMode.setName("EnableTaggedStatusMode");
        bits.RCBCheck.setBaseRegister(&r32);
        bits.RCBCheck.setName("RCBCheck");
        bits.InterruptCheck.setBaseRegister(&r32);
        bits.InterruptCheck.setName("InterruptCheck");
        bits.ByteEnableRuleCheck.setBaseRegister(&r32);
        bits.ByteEnableRuleCheck.setName("ByteEnableRuleCheck");
        bits.BoundaryCheck.setBaseRegister(&r32);
        bits.BoundaryCheck.setName("BoundaryCheck");
        bits.LogHeaderOverflow.setBaseRegister(&r32);
        bits.LogHeaderOverflow.setName("LogHeaderOverflow");
        bits.EnableTLPMinorErrorTolerance.setBaseRegister(&r32);
        bits.EnableTLPMinorErrorTolerance.setName("EnableTLPMinorErrorTolerance");
        bits.MetalRevID.setBaseRegister(&r32);
        bits.MetalRevID.setName("MetalRevID");
        bits.AllLayerID.setBaseRegister(&r32);
        bits.AllLayerID.setName("AllLayerID");
        bits.ProductID.setBaseRegister(&r32);
        bits.ProductID.setName("ProductID");
    }
    RegDEVICEMiscellaneousHostControl_t& operator=(const RegDEVICEMiscellaneousHostControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMiscellaneousHostControl_t;

#define REG_DEVICE_PCI_STATE ((volatile APE_DEVICE_H_uint32_t*)0xa0040070) /*  */
#define     DEVICE_PCI_STATE_PCI_EXPANSION_ROM_DESIRED_SHIFT 5u
#define     DEVICE_PCI_STATE_PCI_EXPANSION_ROM_DESIRED_MASK  0x20u
#define GET_DEVICE_PCI_STATE_PCI_EXPANSION_ROM_DESIRED(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_PCI_STATE_PCI_EXPANSION_ROM_DESIRED(__val__)  (((__val__) << 5u) & 0x20u)
#define     DEVICE_PCI_STATE_PCI_EXPANSION_ROM_RETRY_SHIFT 6u
#define     DEVICE_PCI_STATE_PCI_EXPANSION_ROM_RETRY_MASK  0x40u
#define GET_DEVICE_PCI_STATE_PCI_EXPANSION_ROM_RETRY(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_DEVICE_PCI_STATE_PCI_EXPANSION_ROM_RETRY(__val__)  (((__val__) << 6u) & 0x40u)
#define     DEVICE_PCI_STATE_VPD_AVAILABLE_SHIFT 7u
#define     DEVICE_PCI_STATE_VPD_AVAILABLE_MASK  0x80u
#define GET_DEVICE_PCI_STATE_VPD_AVAILABLE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_PCI_STATE_VPD_AVAILABLE(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_PCI_STATE_FLAT_VIEW_SHIFT 8u
#define     DEVICE_PCI_STATE_FLAT_VIEW_MASK  0x100u
#define GET_DEVICE_PCI_STATE_FLAT_VIEW(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_PCI_STATE_FLAT_VIEW(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_PCI_STATE_MAX_PCI_TARGET_RETRY_SHIFT 9u
#define     DEVICE_PCI_STATE_MAX_PCI_TARGET_RETRY_MASK  0xe00u
#define GET_DEVICE_PCI_STATE_MAX_PCI_TARGET_RETRY(__reg__)  (((__reg__) & 0xe00) >> 9u)
#define SET_DEVICE_PCI_STATE_MAX_PCI_TARGET_RETRY(__val__)  (((__val__) << 9u) & 0xe00u)
#define     DEVICE_PCI_STATE_CONFIG_RETRY_SHIFT 15u
#define     DEVICE_PCI_STATE_CONFIG_RETRY_MASK  0x8000u
#define GET_DEVICE_PCI_STATE_CONFIG_RETRY(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_DEVICE_PCI_STATE_CONFIG_RETRY(__val__)  (((__val__) << 15u) & 0x8000u)
#define     DEVICE_PCI_STATE_APE_CONTROL_REGISTER_WRITE_ENABLE_SHIFT 16u
#define     DEVICE_PCI_STATE_APE_CONTROL_REGISTER_WRITE_ENABLE_MASK  0x10000u
#define GET_DEVICE_PCI_STATE_APE_CONTROL_REGISTER_WRITE_ENABLE(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_DEVICE_PCI_STATE_APE_CONTROL_REGISTER_WRITE_ENABLE(__val__)  (((__val__) << 16u) & 0x10000u)
#define     DEVICE_PCI_STATE_APE_SHARED_MEMORY_WRITE_ENABLE_SHIFT 17u
#define     DEVICE_PCI_STATE_APE_SHARED_MEMORY_WRITE_ENABLE_MASK  0x20000u
#define GET_DEVICE_PCI_STATE_APE_SHARED_MEMORY_WRITE_ENABLE(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_DEVICE_PCI_STATE_APE_SHARED_MEMORY_WRITE_ENABLE(__val__)  (((__val__) << 17u) & 0x20000u)
#define     DEVICE_PCI_STATE_APE_PROGRAM_SPACE_WRITE_ENABLE_SHIFT 18u
#define     DEVICE_PCI_STATE_APE_PROGRAM_SPACE_WRITE_ENABLE_MASK  0x40000u
#define GET_DEVICE_PCI_STATE_APE_PROGRAM_SPACE_WRITE_ENABLE(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_DEVICE_PCI_STATE_APE_PROGRAM_SPACE_WRITE_ENABLE(__val__)  (((__val__) << 18u) & 0x40000u)
#define     DEVICE_PCI_STATE_GENERATE_RESET_PLUS_SHIFT 19u
#define     DEVICE_PCI_STATE_GENERATE_RESET_PLUS_MASK  0x80000u
#define GET_DEVICE_PCI_STATE_GENERATE_RESET_PLUS(__reg__)  (((__reg__) & 0x80000) >> 19u)
#define SET_DEVICE_PCI_STATE_GENERATE_RESET_PLUS(__val__)  (((__val__) << 19u) & 0x80000u)

/** @brief Register definition for @ref DEVICE_t.PciState. */
typedef register_container RegDEVICEPciState_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_4_0, 0, 5)
        /** @brief Enable PCI ROM base address register to be visible to the PCI host */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIExpansionROMDesired, 5, 1)
        /** @brief Force PCI Retry for accesses to Expansion ROM region if enabled */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIExpansionROMRetry, 6, 1)
        /** @brief This bit reads as 1 if the VPD region of the NVRAM can be accessed by the host */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VPDAvailable, 7, 1)
        /** @brief Asserted if the Base Address register presents a 32 MB PCI Address map flat view, otherwise, indicates a 64 KB PCI Address map in standard view */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FlatView, 8, 1)
        /** @brief Indicates the number of PCI clock cycles before Retry occurs, in multiple of 8. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MaxPCITargetRetry, 9, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_14_12, 12, 3)
        /** @brief When asserted, forces all config access to be retried. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ConfigRetry, 15, 1)
        /** @brief When this bit is set the APE control registers may be written. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEControlRegisterWriteEnable, 16, 1)
        /** @brief When this bit is set the APE shared memory region may be written. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APESharedMemoryWriteEnable, 17, 1)
        /** @brief When this bit is set the APE program space may be written. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEProgramSpaceWriteEnable, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GenerateResetPlus, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_20, 20, 12)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_20, 20, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GenerateResetPlus, 19, 1)
        /** @brief When this bit is set the APE program space may be written. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEProgramSpaceWriteEnable, 18, 1)
        /** @brief When this bit is set the APE shared memory region may be written. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APESharedMemoryWriteEnable, 17, 1)
        /** @brief When this bit is set the APE control registers may be written. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEControlRegisterWriteEnable, 16, 1)
        /** @brief When asserted, forces all config access to be retried. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ConfigRetry, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_14_12, 12, 3)
        /** @brief Indicates the number of PCI clock cycles before Retry occurs, in multiple of 8. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MaxPCITargetRetry, 9, 3)
        /** @brief Asserted if the Base Address register presents a 32 MB PCI Address map flat view, otherwise, indicates a 64 KB PCI Address map in standard view */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FlatView, 8, 1)
        /** @brief This bit reads as 1 if the VPD region of the NVRAM can be accessed by the host */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VPDAvailable, 7, 1)
        /** @brief Force PCI Retry for accesses to Expansion ROM region if enabled */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIExpansionROMRetry, 6, 1)
        /** @brief Enable PCI ROM base address register to be visible to the PCI host */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIExpansionROMDesired, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_4_0, 0, 5)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciState"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciState_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciState. */
        r32.setName("PciState");
        bits.PCIExpansionROMDesired.setBaseRegister(&r32);
        bits.PCIExpansionROMDesired.setName("PCIExpansionROMDesired");
        bits.PCIExpansionROMRetry.setBaseRegister(&r32);
        bits.PCIExpansionROMRetry.setName("PCIExpansionROMRetry");
        bits.VPDAvailable.setBaseRegister(&r32);
        bits.VPDAvailable.setName("VPDAvailable");
        bits.FlatView.setBaseRegister(&r32);
        bits.FlatView.setName("FlatView");
        bits.MaxPCITargetRetry.setBaseRegister(&r32);
        bits.MaxPCITargetRetry.setName("MaxPCITargetRetry");
        bits.ConfigRetry.setBaseRegister(&r32);
        bits.ConfigRetry.setName("ConfigRetry");
        bits.APEControlRegisterWriteEnable.setBaseRegister(&r32);
        bits.APEControlRegisterWriteEnable.setName("APEControlRegisterWriteEnable");
        bits.APESharedMemoryWriteEnable.setBaseRegister(&r32);
        bits.APESharedMemoryWriteEnable.setName("APESharedMemoryWriteEnable");
        bits.APEProgramSpaceWriteEnable.setBaseRegister(&r32);
        bits.APEProgramSpaceWriteEnable.setName("APEProgramSpaceWriteEnable");
        bits.GenerateResetPlus.setBaseRegister(&r32);
        bits.GenerateResetPlus.setName("GenerateResetPlus");
    }
    RegDEVICEPciState_t& operator=(const RegDEVICEPciState_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciState_t;

#define REG_DEVICE_REGISTER_BASE ((volatile APE_DEVICE_H_uint32_t*)0xa0040078) /* Local controller memory address of a register than can be written or read by writing to the register data register. */
/** @brief Register definition for @ref DEVICE_t.RegisterBase. */
typedef register_container RegDEVICERegisterBase_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RegisterBase"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERegisterBase_t()
    {
        /** @brief constructor for @ref DEVICE_t.RegisterBase. */
        r32.setName("RegisterBase");
    }
    RegDEVICERegisterBase_t& operator=(const RegDEVICERegisterBase_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERegisterBase_t;

#define REG_DEVICE_MEMORY_BASE ((volatile APE_DEVICE_H_uint32_t*)0xa004007c) /* Local controller memory address of the NIC memory region that can be accessed via Memory Window data register. */
/** @brief Register definition for @ref DEVICE_t.MemoryBase. */
typedef register_container RegDEVICEMemoryBase_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MemoryBase"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMemoryBase_t()
    {
        /** @brief constructor for @ref DEVICE_t.MemoryBase. */
        r32.setName("MemoryBase");
    }
    RegDEVICEMemoryBase_t& operator=(const RegDEVICEMemoryBase_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMemoryBase_t;

#define REG_DEVICE_REGISTER_DATA ((volatile APE_DEVICE_H_uint32_t*)0xa0040080) /* Register Data at the location pointed by the Register Base Register. */
/** @brief Register definition for @ref DEVICE_t.RegisterData. */
typedef register_container RegDEVICERegisterData_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RegisterData"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERegisterData_t()
    {
        /** @brief constructor for @ref DEVICE_t.RegisterData. */
        r32.setName("RegisterData");
    }
    RegDEVICERegisterData_t& operator=(const RegDEVICERegisterData_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERegisterData_t;

#define REG_DEVICE_UNDI_RECEIVE_RETURN_RING_CONSUMER_INDEX ((volatile APE_DEVICE_H_uint32_t*)0xa0040088) /* UNDI Receive Return Ring Consumer Index Mailbox */
/** @brief Register definition for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndex. */
typedef register_container RegDEVICEUndiReceiveReturnRingConsumerIndex_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "UndiReceiveReturnRingConsumerIndex"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEUndiReceiveReturnRingConsumerIndex_t()
    {
        /** @brief constructor for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndex. */
        r32.setName("UndiReceiveReturnRingConsumerIndex");
    }
    RegDEVICEUndiReceiveReturnRingConsumerIndex_t& operator=(const RegDEVICEUndiReceiveReturnRingConsumerIndex_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEUndiReceiveReturnRingConsumerIndex_t;

#define REG_DEVICE_UNDI_RECEIVE_RETURN_RING_CONSUMER_INDEX_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa004008c) /* UNDI Receive Return Ring Consumer Index Mailbox */
/** @brief Register definition for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndexLow. */
typedef register_container RegDEVICEUndiReceiveReturnRingConsumerIndexLow_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "UndiReceiveReturnRingConsumerIndexLow"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEUndiReceiveReturnRingConsumerIndexLow_t()
    {
        /** @brief constructor for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndexLow. */
        r32.setName("UndiReceiveReturnRingConsumerIndexLow");
    }
    RegDEVICEUndiReceiveReturnRingConsumerIndexLow_t& operator=(const RegDEVICEUndiReceiveReturnRingConsumerIndexLow_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEUndiReceiveReturnRingConsumerIndexLow_t;

#define REG_DEVICE_LINK_STATUS_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa00400bc) /* PCIe standard register. */
#define     DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_SPEED_SHIFT 16u
#define     DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_SPEED_MASK  0xf0000u
#define GET_DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_SPEED(__reg__)  (((__reg__) & 0xf0000) >> 16u)
#define SET_DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_SPEED(__val__)  (((__val__) << 16u) & 0xf0000u)
#define     DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_SPEED_PCIE_1_0 0x1u
#define     DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_SPEED_PCIE_2_0 0x2u

#define     DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_WIDTH_SHIFT 20u
#define     DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_WIDTH_MASK  0x3f00000u
#define GET_DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_WIDTH(__reg__)  (((__reg__) & 0x3f00000) >> 20u)
#define SET_DEVICE_LINK_STATUS_CONTROL_NEGOTIATED_LINK_WIDTH(__val__)  (((__val__) << 20u) & 0x3f00000u)

/** @brief Register definition for @ref DEVICE_t.LinkStatusControl. */
typedef register_container RegDEVICELinkStatusControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NegotiatedLinkSpeed, 16, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NegotiatedLinkWidth, 20, 6)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_26, 26, 6)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_26, 26, 6)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NegotiatedLinkWidth, 20, 6)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NegotiatedLinkSpeed, 16, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LinkStatusControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICELinkStatusControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.LinkStatusControl. */
        r32.setName("LinkStatusControl");
        bits.NegotiatedLinkSpeed.setBaseRegister(&r32);
        bits.NegotiatedLinkSpeed.setName("NegotiatedLinkSpeed");
        bits.NegotiatedLinkWidth.setBaseRegister(&r32);
        bits.NegotiatedLinkWidth.setName("NegotiatedLinkWidth");
    }
    RegDEVICELinkStatusControl_t& operator=(const RegDEVICELinkStatusControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICELinkStatusControl_t;

#define REG_DEVICE_APE_MEMORY_BASE ((volatile APE_DEVICE_H_uint32_t*)0xa00400f8) /* APE Memory address to read/write using the APE Memory Data register.. */
/** @brief Register definition for @ref DEVICE_t.ApeMemoryBase. */
typedef register_container RegDEVICEApeMemoryBase_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ApeMemoryBase"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEApeMemoryBase_t()
    {
        /** @brief constructor for @ref DEVICE_t.ApeMemoryBase. */
        r32.setName("ApeMemoryBase");
    }
    RegDEVICEApeMemoryBase_t& operator=(const RegDEVICEApeMemoryBase_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEApeMemoryBase_t;

#define REG_DEVICE_APE_MEMORY_DATA ((volatile APE_DEVICE_H_uint32_t*)0xa00400fc) /* APE Memory value at the location pointed by the Memory Base Register. */
/** @brief Register definition for @ref DEVICE_t.ApeMemoryData. */
typedef register_container RegDEVICEApeMemoryData_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ApeMemoryData"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEApeMemoryData_t()
    {
        /** @brief constructor for @ref DEVICE_t.ApeMemoryData. */
        r32.setName("ApeMemoryData");
    }
    RegDEVICEApeMemoryData_t& operator=(const RegDEVICEApeMemoryData_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEApeMemoryData_t;

#define REG_DEVICE_EMAC_MODE ((volatile APE_DEVICE_H_uint32_t*)0xa0040400) /*  */
#define     DEVICE_EMAC_MODE_GLOBAL_RESET_SHIFT 0u
#define     DEVICE_EMAC_MODE_GLOBAL_RESET_MASK  0x1u
#define GET_DEVICE_EMAC_MODE_GLOBAL_RESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_EMAC_MODE_GLOBAL_RESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_EMAC_MODE_HALF_DUPLEX_SHIFT 1u
#define     DEVICE_EMAC_MODE_HALF_DUPLEX_MASK  0x2u
#define GET_DEVICE_EMAC_MODE_HALF_DUPLEX(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_EMAC_MODE_HALF_DUPLEX(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_EMAC_MODE_PORT_MODE_SHIFT 2u
#define     DEVICE_EMAC_MODE_PORT_MODE_MASK  0xcu
#define GET_DEVICE_EMAC_MODE_PORT_MODE(__reg__)  (((__reg__) & 0xc) >> 2u)
#define SET_DEVICE_EMAC_MODE_PORT_MODE(__val__)  (((__val__) << 2u) & 0xcu)
#define     DEVICE_EMAC_MODE_PORT_MODE_NONE 0x0u
#define     DEVICE_EMAC_MODE_PORT_MODE_10_DIV_100 0x1u
#define     DEVICE_EMAC_MODE_PORT_MODE_1000 0x2u
#define     DEVICE_EMAC_MODE_PORT_MODE_TBI 0x3u

#define     DEVICE_EMAC_MODE_LOOPBACK_MODE_SHIFT 4u
#define     DEVICE_EMAC_MODE_LOOPBACK_MODE_MASK  0x10u
#define GET_DEVICE_EMAC_MODE_LOOPBACK_MODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_EMAC_MODE_LOOPBACK_MODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_EMAC_MODE_TAGGED_MAC_CONTROL_SHIFT 7u
#define     DEVICE_EMAC_MODE_TAGGED_MAC_CONTROL_MASK  0x80u
#define GET_DEVICE_EMAC_MODE_TAGGED_MAC_CONTROL(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_EMAC_MODE_TAGGED_MAC_CONTROL(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_EMAC_MODE_ENABLE_TX_BURSTING_SHIFT 8u
#define     DEVICE_EMAC_MODE_ENABLE_TX_BURSTING_MASK  0x100u
#define GET_DEVICE_EMAC_MODE_ENABLE_TX_BURSTING(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_EMAC_MODE_ENABLE_TX_BURSTING(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_EMAC_MODE_MAX_DEFER_SHIFT 9u
#define     DEVICE_EMAC_MODE_MAX_DEFER_MASK  0x200u
#define GET_DEVICE_EMAC_MODE_MAX_DEFER(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_EMAC_MODE_MAX_DEFER(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_EMAC_MODE_ENABLE_RX_STATISTICS_SHIFT 11u
#define     DEVICE_EMAC_MODE_ENABLE_RX_STATISTICS_MASK  0x800u
#define GET_DEVICE_EMAC_MODE_ENABLE_RX_STATISTICS(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_DEVICE_EMAC_MODE_ENABLE_RX_STATISTICS(__val__)  (((__val__) << 11u) & 0x800u)
#define     DEVICE_EMAC_MODE_CLEAR_RX_STATISTICS_SHIFT 12u
#define     DEVICE_EMAC_MODE_CLEAR_RX_STATISTICS_MASK  0x1000u
#define GET_DEVICE_EMAC_MODE_CLEAR_RX_STATISTICS(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_DEVICE_EMAC_MODE_CLEAR_RX_STATISTICS(__val__)  (((__val__) << 12u) & 0x1000u)
#define     DEVICE_EMAC_MODE_FLUSH_RX_STATISTICS_SHIFT 13u
#define     DEVICE_EMAC_MODE_FLUSH_RX_STATISTICS_MASK  0x2000u
#define GET_DEVICE_EMAC_MODE_FLUSH_RX_STATISTICS(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_DEVICE_EMAC_MODE_FLUSH_RX_STATISTICS(__val__)  (((__val__) << 13u) & 0x2000u)
#define     DEVICE_EMAC_MODE_ENABLE_TX_STATISTICS_SHIFT 14u
#define     DEVICE_EMAC_MODE_ENABLE_TX_STATISTICS_MASK  0x4000u
#define GET_DEVICE_EMAC_MODE_ENABLE_TX_STATISTICS(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_DEVICE_EMAC_MODE_ENABLE_TX_STATISTICS(__val__)  (((__val__) << 14u) & 0x4000u)
#define     DEVICE_EMAC_MODE_CLEAR_TX_STATISTICS_SHIFT 15u
#define     DEVICE_EMAC_MODE_CLEAR_TX_STATISTICS_MASK  0x8000u
#define GET_DEVICE_EMAC_MODE_CLEAR_TX_STATISTICS(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_DEVICE_EMAC_MODE_CLEAR_TX_STATISTICS(__val__)  (((__val__) << 15u) & 0x8000u)
#define     DEVICE_EMAC_MODE_FLUSH_TX_STATISTICS_SHIFT 16u
#define     DEVICE_EMAC_MODE_FLUSH_TX_STATISTICS_MASK  0x10000u
#define GET_DEVICE_EMAC_MODE_FLUSH_TX_STATISTICS(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_DEVICE_EMAC_MODE_FLUSH_TX_STATISTICS(__val__)  (((__val__) << 16u) & 0x10000u)
#define     DEVICE_EMAC_MODE_SEND_CONFIG_COMMAND_SHIFT 17u
#define     DEVICE_EMAC_MODE_SEND_CONFIG_COMMAND_MASK  0x20000u
#define GET_DEVICE_EMAC_MODE_SEND_CONFIG_COMMAND(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_DEVICE_EMAC_MODE_SEND_CONFIG_COMMAND(__val__)  (((__val__) << 17u) & 0x20000u)
#define     DEVICE_EMAC_MODE_MAGIC_PACKET_DETECTION_ENABLE_SHIFT 18u
#define     DEVICE_EMAC_MODE_MAGIC_PACKET_DETECTION_ENABLE_MASK  0x40000u
#define GET_DEVICE_EMAC_MODE_MAGIC_PACKET_DETECTION_ENABLE(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_DEVICE_EMAC_MODE_MAGIC_PACKET_DETECTION_ENABLE(__val__)  (((__val__) << 18u) & 0x40000u)
#define     DEVICE_EMAC_MODE_ACPI_POWER_ON_ENABLE_SHIFT 19u
#define     DEVICE_EMAC_MODE_ACPI_POWER_ON_ENABLE_MASK  0x80000u
#define GET_DEVICE_EMAC_MODE_ACPI_POWER_ON_ENABLE(__reg__)  (((__reg__) & 0x80000) >> 19u)
#define SET_DEVICE_EMAC_MODE_ACPI_POWER_ON_ENABLE(__val__)  (((__val__) << 19u) & 0x80000u)
#define     DEVICE_EMAC_MODE_ENABLE_TCE_SHIFT 21u
#define     DEVICE_EMAC_MODE_ENABLE_TCE_MASK  0x200000u
#define GET_DEVICE_EMAC_MODE_ENABLE_TCE(__reg__)  (((__reg__) & 0x200000) >> 21u)
#define SET_DEVICE_EMAC_MODE_ENABLE_TCE(__val__)  (((__val__) << 21u) & 0x200000u)
#define     DEVICE_EMAC_MODE_ENABLE_RDE_SHIFT 22u
#define     DEVICE_EMAC_MODE_ENABLE_RDE_MASK  0x400000u
#define GET_DEVICE_EMAC_MODE_ENABLE_RDE(__reg__)  (((__reg__) & 0x400000) >> 22u)
#define SET_DEVICE_EMAC_MODE_ENABLE_RDE(__val__)  (((__val__) << 22u) & 0x400000u)
#define     DEVICE_EMAC_MODE_ENABLE_FHDE_SHIFT 23u
#define     DEVICE_EMAC_MODE_ENABLE_FHDE_MASK  0x800000u
#define GET_DEVICE_EMAC_MODE_ENABLE_FHDE(__reg__)  (((__reg__) & 0x800000) >> 23u)
#define SET_DEVICE_EMAC_MODE_ENABLE_FHDE(__val__)  (((__val__) << 23u) & 0x800000u)
#define     DEVICE_EMAC_MODE_KEEP_FRAME_IN_WOL_SHIFT 24u
#define     DEVICE_EMAC_MODE_KEEP_FRAME_IN_WOL_MASK  0x1000000u
#define GET_DEVICE_EMAC_MODE_KEEP_FRAME_IN_WOL(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_DEVICE_EMAC_MODE_KEEP_FRAME_IN_WOL(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     DEVICE_EMAC_MODE_HALT_INTERESTING_PACKET_PME_SHIFT 25u
#define     DEVICE_EMAC_MODE_HALT_INTERESTING_PACKET_PME_MASK  0x2000000u
#define GET_DEVICE_EMAC_MODE_HALT_INTERESTING_PACKET_PME(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_DEVICE_EMAC_MODE_HALT_INTERESTING_PACKET_PME(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     DEVICE_EMAC_MODE_FREE_RUNNING_ACPI_SHIFT 26u
#define     DEVICE_EMAC_MODE_FREE_RUNNING_ACPI_MASK  0x4000000u
#define GET_DEVICE_EMAC_MODE_FREE_RUNNING_ACPI(__reg__)  (((__reg__) & 0x4000000) >> 26u)
#define SET_DEVICE_EMAC_MODE_FREE_RUNNING_ACPI(__val__)  (((__val__) << 26u) & 0x4000000u)
#define     DEVICE_EMAC_MODE_ENABLE_APE_RX_PATH_SHIFT 27u
#define     DEVICE_EMAC_MODE_ENABLE_APE_RX_PATH_MASK  0x8000000u
#define GET_DEVICE_EMAC_MODE_ENABLE_APE_RX_PATH(__reg__)  (((__reg__) & 0x8000000) >> 27u)
#define SET_DEVICE_EMAC_MODE_ENABLE_APE_RX_PATH(__val__)  (((__val__) << 27u) & 0x8000000u)
#define     DEVICE_EMAC_MODE_ENABLE_APE_TX_PATH_SHIFT 28u
#define     DEVICE_EMAC_MODE_ENABLE_APE_TX_PATH_MASK  0x10000000u
#define GET_DEVICE_EMAC_MODE_ENABLE_APE_TX_PATH(__reg__)  (((__reg__) & 0x10000000) >> 28u)
#define SET_DEVICE_EMAC_MODE_ENABLE_APE_TX_PATH(__val__)  (((__val__) << 28u) & 0x10000000u)
#define     DEVICE_EMAC_MODE_MAC_LOOPBACK_MODE_CONTROL_SHIFT 29u
#define     DEVICE_EMAC_MODE_MAC_LOOPBACK_MODE_CONTROL_MASK  0x20000000u
#define GET_DEVICE_EMAC_MODE_MAC_LOOPBACK_MODE_CONTROL(__reg__)  (((__reg__) & 0x20000000) >> 29u)
#define SET_DEVICE_EMAC_MODE_MAC_LOOPBACK_MODE_CONTROL(__val__)  (((__val__) << 29u) & 0x20000000u)

/** @brief Register definition for @ref DEVICE_t.EmacMode. */
typedef register_container RegDEVICEEmacMode_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief When this bit is set to 1, the MAC state machine is reset. This is a self-clearing bit. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GlobalReset, 0, 1)
        /** @brief When set, the MII/GMII interface is configured to operate in half-duplex mode and the CSMA/ CD state machines in the MAC are set to half-duplex mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, HalfDuplex, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PortMode, 2, 2)
        /** @brief When set, an internal loopback path is enabled from the transmit MAC to the receive MAC. This bit is provided for diagnostic purposes only. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LoopbackMode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_6_5, 5, 2)
        /** @brief Allow the MAC to receive tagged MAC control packets. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TaggedMACControl, 7, 1)
        /** @brief Enable transmit bursting in gigabit half-duplex mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTXBursting, 8, 1)
        /** @brief Enable Max Deferral checking statistic. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MaxDefer, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_10_10, 10, 1)
        /** @brief Enable receive statistics external updates. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableRXStatistics, 11, 1)
        /** @brief Clear receive statistics internal RAM. This bit is self-clearing. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ClearRXStatistics, 12, 1)
        /** @brief Write receive statistics to external memory. This bit is self-clearing. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FlushRXStatistics, 13, 1)
        /** @brief Enable transmit statistics external updates. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTXStatistics, 14, 1)
        /** @brief Clear transmit statistics internal RAM. This bit is self-clearing. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ClearTXStatistics, 15, 1)
        /** @brief Write transmit statistics to external memory. This bit is self-clearing. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FlushTXStatistics, 16, 1)
        /** @brief Send config commands when in TBI mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SendConfigCommand, 17, 1)
        /** @brief Enable Magic Packet detection. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MagicPacketDetectionEnable, 18, 1)
        /** @brief Enable Wake on LAN filters when in powerdown mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ACPIPowerOnEnable, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_20_20, 20, 1)
        /** @brief Enable Transmit DMA engine. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTCE, 21, 1)
        /** @brief Enable RDMA engine. Must be set for normal operation. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableRDE, 22, 1)
        /** @brief Enable receive Frame Header DMA engine. Must be set for normal operation. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableFHDE, 23, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, KeepFrameInWOL, 24, 1)
        /** @brief When this bit is set, the WOL signal will not be asserted on an interesting packet match. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, HaltInterestingPacketPME, 25, 1)
        /** @brief When this bit is set, the ACPI state machine will continue running when a match is found. When this bit is clear, the ACPI state machine will halt when a match is found. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Free_RunningACPI, 26, 1)
        /** @brief This bit must be written a 1 for APE subsystem to receive packets from the EMAC. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableAPERXPath, 27, 1)
        /** @brief This bit must be written a 1 for the EMAC to transmit APE packets. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableAPETXPath, 28, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACLoopbackModeControl, 29, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_30, 30, 2)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_30, 30, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACLoopbackModeControl, 29, 1)
        /** @brief This bit must be written a 1 for the EMAC to transmit APE packets. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableAPETXPath, 28, 1)
        /** @brief This bit must be written a 1 for APE subsystem to receive packets from the EMAC. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableAPERXPath, 27, 1)
        /** @brief When this bit is set, the ACPI state machine will continue running when a match is found. When this bit is clear, the ACPI state machine will halt when a match is found. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Free_RunningACPI, 26, 1)
        /** @brief When this bit is set, the WOL signal will not be asserted on an interesting packet match. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, HaltInterestingPacketPME, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, KeepFrameInWOL, 24, 1)
        /** @brief Enable receive Frame Header DMA engine. Must be set for normal operation. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableFHDE, 23, 1)
        /** @brief Enable RDMA engine. Must be set for normal operation. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableRDE, 22, 1)
        /** @brief Enable Transmit DMA engine. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTCE, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_20_20, 20, 1)
        /** @brief Enable Wake on LAN filters when in powerdown mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ACPIPowerOnEnable, 19, 1)
        /** @brief Enable Magic Packet detection. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MagicPacketDetectionEnable, 18, 1)
        /** @brief Send config commands when in TBI mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SendConfigCommand, 17, 1)
        /** @brief Write transmit statistics to external memory. This bit is self-clearing. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FlushTXStatistics, 16, 1)
        /** @brief Clear transmit statistics internal RAM. This bit is self-clearing. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ClearTXStatistics, 15, 1)
        /** @brief Enable transmit statistics external updates. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTXStatistics, 14, 1)
        /** @brief Write receive statistics to external memory. This bit is self-clearing. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FlushRXStatistics, 13, 1)
        /** @brief Clear receive statistics internal RAM. This bit is self-clearing. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ClearRXStatistics, 12, 1)
        /** @brief Enable receive statistics external updates. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableRXStatistics, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_10_10, 10, 1)
        /** @brief Enable Max Deferral checking statistic. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MaxDefer, 9, 1)
        /** @brief Enable transmit bursting in gigabit half-duplex mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTXBursting, 8, 1)
        /** @brief Allow the MAC to receive tagged MAC control packets. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TaggedMACControl, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_6_5, 5, 2)
        /** @brief When set, an internal loopback path is enabled from the transmit MAC to the receive MAC. This bit is provided for diagnostic purposes only. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LoopbackMode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PortMode, 2, 2)
        /** @brief When set, the MII/GMII interface is configured to operate in half-duplex mode and the CSMA/ CD state machines in the MAC are set to half-duplex mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, HalfDuplex, 1, 1)
        /** @brief When this bit is set to 1, the MAC state machine is reset. This is a self-clearing bit. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GlobalReset, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EmacMode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEmacMode_t()
    {
        /** @brief constructor for @ref DEVICE_t.EmacMode. */
        r32.setName("EmacMode");
        bits.GlobalReset.setBaseRegister(&r32);
        bits.GlobalReset.setName("GlobalReset");
        bits.HalfDuplex.setBaseRegister(&r32);
        bits.HalfDuplex.setName("HalfDuplex");
        bits.PortMode.setBaseRegister(&r32);
        bits.PortMode.setName("PortMode");
        bits.LoopbackMode.setBaseRegister(&r32);
        bits.LoopbackMode.setName("LoopbackMode");
        bits.TaggedMACControl.setBaseRegister(&r32);
        bits.TaggedMACControl.setName("TaggedMACControl");
        bits.EnableTXBursting.setBaseRegister(&r32);
        bits.EnableTXBursting.setName("EnableTXBursting");
        bits.MaxDefer.setBaseRegister(&r32);
        bits.MaxDefer.setName("MaxDefer");
        bits.EnableRXStatistics.setBaseRegister(&r32);
        bits.EnableRXStatistics.setName("EnableRXStatistics");
        bits.ClearRXStatistics.setBaseRegister(&r32);
        bits.ClearRXStatistics.setName("ClearRXStatistics");
        bits.FlushRXStatistics.setBaseRegister(&r32);
        bits.FlushRXStatistics.setName("FlushRXStatistics");
        bits.EnableTXStatistics.setBaseRegister(&r32);
        bits.EnableTXStatistics.setName("EnableTXStatistics");
        bits.ClearTXStatistics.setBaseRegister(&r32);
        bits.ClearTXStatistics.setName("ClearTXStatistics");
        bits.FlushTXStatistics.setBaseRegister(&r32);
        bits.FlushTXStatistics.setName("FlushTXStatistics");
        bits.SendConfigCommand.setBaseRegister(&r32);
        bits.SendConfigCommand.setName("SendConfigCommand");
        bits.MagicPacketDetectionEnable.setBaseRegister(&r32);
        bits.MagicPacketDetectionEnable.setName("MagicPacketDetectionEnable");
        bits.ACPIPowerOnEnable.setBaseRegister(&r32);
        bits.ACPIPowerOnEnable.setName("ACPIPowerOnEnable");
        bits.EnableTCE.setBaseRegister(&r32);
        bits.EnableTCE.setName("EnableTCE");
        bits.EnableRDE.setBaseRegister(&r32);
        bits.EnableRDE.setName("EnableRDE");
        bits.EnableFHDE.setBaseRegister(&r32);
        bits.EnableFHDE.setName("EnableFHDE");
        bits.KeepFrameInWOL.setBaseRegister(&r32);
        bits.KeepFrameInWOL.setName("KeepFrameInWOL");
        bits.HaltInterestingPacketPME.setBaseRegister(&r32);
        bits.HaltInterestingPacketPME.setName("HaltInterestingPacketPME");
        bits.Free_RunningACPI.setBaseRegister(&r32);
        bits.Free_RunningACPI.setName("Free_RunningACPI");
        bits.EnableAPERXPath.setBaseRegister(&r32);
        bits.EnableAPERXPath.setName("EnableAPERXPath");
        bits.EnableAPETXPath.setBaseRegister(&r32);
        bits.EnableAPETXPath.setName("EnableAPETXPath");
        bits.MACLoopbackModeControl.setBaseRegister(&r32);
        bits.MACLoopbackModeControl.setName("MACLoopbackModeControl");
    }
    RegDEVICEEmacMode_t& operator=(const RegDEVICEEmacMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEmacMode_t;

#define REG_DEVICE_LED_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa004040c) /*  */
#define     DEVICE_LED_CONTROL_OVERRIDE_LINK_SHIFT 0u
#define     DEVICE_LED_CONTROL_OVERRIDE_LINK_MASK  0x1u
#define GET_DEVICE_LED_CONTROL_OVERRIDE_LINK(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_LED_CONTROL_OVERRIDE_LINK(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_LED_CONTROL_LED_1000_SHIFT 1u
#define     DEVICE_LED_CONTROL_LED_1000_MASK  0x2u
#define GET_DEVICE_LED_CONTROL_LED_1000(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_LED_CONTROL_LED_1000(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_LED_CONTROL_LED_100_SHIFT 2u
#define     DEVICE_LED_CONTROL_LED_100_MASK  0x4u
#define GET_DEVICE_LED_CONTROL_LED_100(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_LED_CONTROL_LED_100(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_LED_CONTROL_LED_10_SHIFT 3u
#define     DEVICE_LED_CONTROL_LED_10_MASK  0x8u
#define GET_DEVICE_LED_CONTROL_LED_10(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_DEVICE_LED_CONTROL_LED_10(__val__)  (((__val__) << 3u) & 0x8u)
#define     DEVICE_LED_CONTROL_OVERRIDE_TRAFFIC_SHIFT 4u
#define     DEVICE_LED_CONTROL_OVERRIDE_TRAFFIC_MASK  0x10u
#define GET_DEVICE_LED_CONTROL_OVERRIDE_TRAFFIC(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_LED_CONTROL_OVERRIDE_TRAFFIC(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_LED_CONTROL_LED_TRAFFIC_BLINK_SHIFT 5u
#define     DEVICE_LED_CONTROL_LED_TRAFFIC_BLINK_MASK  0x20u
#define GET_DEVICE_LED_CONTROL_LED_TRAFFIC_BLINK(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_LED_CONTROL_LED_TRAFFIC_BLINK(__val__)  (((__val__) << 5u) & 0x20u)
#define     DEVICE_LED_CONTROL_LED_TRAFFIC_SHIFT 6u
#define     DEVICE_LED_CONTROL_LED_TRAFFIC_MASK  0x40u
#define GET_DEVICE_LED_CONTROL_LED_TRAFFIC(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_DEVICE_LED_CONTROL_LED_TRAFFIC(__val__)  (((__val__) << 6u) & 0x40u)
#define     DEVICE_LED_CONTROL_LED_STATUS_1000_SHIFT 7u
#define     DEVICE_LED_CONTROL_LED_STATUS_1000_MASK  0x80u
#define GET_DEVICE_LED_CONTROL_LED_STATUS_1000(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_LED_CONTROL_LED_STATUS_1000(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_LED_CONTROL_LED_STATUS_100_SHIFT 8u
#define     DEVICE_LED_CONTROL_LED_STATUS_100_MASK  0x100u
#define GET_DEVICE_LED_CONTROL_LED_STATUS_100(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_LED_CONTROL_LED_STATUS_100(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_LED_CONTROL_LED_STATUS_10_SHIFT 9u
#define     DEVICE_LED_CONTROL_LED_STATUS_10_MASK  0x200u
#define GET_DEVICE_LED_CONTROL_LED_STATUS_10(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_LED_CONTROL_LED_STATUS_10(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_LED_CONTROL_LED_STATUS_TRAFFIC_SHIFT 10u
#define     DEVICE_LED_CONTROL_LED_STATUS_TRAFFIC_MASK  0x400u
#define GET_DEVICE_LED_CONTROL_LED_STATUS_TRAFFIC(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_DEVICE_LED_CONTROL_LED_STATUS_TRAFFIC(__val__)  (((__val__) << 10u) & 0x400u)
#define     DEVICE_LED_CONTROL_LED_MODE_SHIFT 11u
#define     DEVICE_LED_CONTROL_LED_MODE_MASK  0x1800u
#define GET_DEVICE_LED_CONTROL_LED_MODE(__reg__)  (((__reg__) & 0x1800) >> 11u)
#define SET_DEVICE_LED_CONTROL_LED_MODE(__val__)  (((__val__) << 11u) & 0x1800u)
#define     DEVICE_LED_CONTROL_LED_MODE_MAC 0x0u
#define     DEVICE_LED_CONTROL_LED_MODE_PHY_MODE_1 0x1u
#define     DEVICE_LED_CONTROL_LED_MODE_PHY_MODE_2 0x2u
#define     DEVICE_LED_CONTROL_LED_MODE_PHY_MODE_1_ 0x3u

#define     DEVICE_LED_CONTROL_MAC_MODE_SHIFT 13u
#define     DEVICE_LED_CONTROL_MAC_MODE_MASK  0x2000u
#define GET_DEVICE_LED_CONTROL_MAC_MODE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_DEVICE_LED_CONTROL_MAC_MODE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     DEVICE_LED_CONTROL_SHARED_TRAFFIC_DIV_LINK_LED_MODE_SHIFT 14u
#define     DEVICE_LED_CONTROL_SHARED_TRAFFIC_DIV_LINK_LED_MODE_MASK  0x4000u
#define GET_DEVICE_LED_CONTROL_SHARED_TRAFFIC_DIV_LINK_LED_MODE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_DEVICE_LED_CONTROL_SHARED_TRAFFIC_DIV_LINK_LED_MODE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     DEVICE_LED_CONTROL_BLINK_PERIOD_SHIFT 19u
#define     DEVICE_LED_CONTROL_BLINK_PERIOD_MASK  0x7ff80000u
#define GET_DEVICE_LED_CONTROL_BLINK_PERIOD(__reg__)  (((__reg__) & 0x7ff80000) >> 19u)
#define SET_DEVICE_LED_CONTROL_BLINK_PERIOD(__val__)  (((__val__) << 19u) & 0x7ff80000u)
#define     DEVICE_LED_CONTROL_OVERRIDE_BLINK_RATE_SHIFT 31u
#define     DEVICE_LED_CONTROL_OVERRIDE_BLINK_RATE_MASK  0x80000000u
#define GET_DEVICE_LED_CONTROL_OVERRIDE_BLINK_RATE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_DEVICE_LED_CONTROL_OVERRIDE_BLINK_RATE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref DEVICE_t.LedControl. */
typedef register_container RegDEVICELedControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief If set, overrides hardware control of the three link LEDs. The LEDs will be controlled via bits [3:1]. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, OverrideLink, 0, 1)
        /** @brief If set along with the LED Override bit, turns on the 1000 Mbps LED. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LED1000, 1, 1)
        /** @brief If set along with the LED Override bit, turns on the 100 Mbps LED. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LED100, 2, 1)
        /** @brief If set along with the LED Override bit, turns on the 10 Mbps LED. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LED10, 3, 1)
        /** @brief If set, overrides hardware control of the Traffic LED. The Traffic LED will then be controlled via bits [6:5]. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, OverrideTraffic, 4, 1)
        /** @brief If set along with the Override Traffic bit and Traffic LED bit, the Traffic LED will blink with the blink rate specified in Override Blink Rate (bit 31) and Blink Period (bits [30:19]) fields. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDTrafficBlink, 5, 1)
        /** @brief If set along with the Override Traffic bit, the Traffic LED is turned on. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDTraffic, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDStatus1000, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDStatus100, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDStatus10, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDStatusTraffic, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDMode, 11, 2)
        /** @brief When this bit is set, the traffic LED blinks only when traffic is addressed for the device (The LED_MODE field must be set to 00 before enabling this bit). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACMode, 13, 1)
        /** @brief When this bit is set, the Link LED is solid green when there is a link and blinks when there is traffic. (The LED_MODE field must be set to 00 before enabling this bit). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SharedTraffic_DIV_LinkLEDMode, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_18_15, 15, 4)
        /** @brief Specifies the period of each blink cycle (on+off) for Traffic LED in milliseconds. Must be a nonzero value. This 12-bit field is reset to 0x040, giving a default blink period of approximately 15.9Hz. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BlinkPeriod, 19, 12)
        /** @brief If set, the blink rate for the Traffic LED is determined by the Blink Period field (bit 30 to bit 19). This bit is rest to 1. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, OverrideBlinkRate, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief If set, the blink rate for the Traffic LED is determined by the Blink Period field (bit 30 to bit 19). This bit is rest to 1. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, OverrideBlinkRate, 31, 1)
        /** @brief Specifies the period of each blink cycle (on+off) for Traffic LED in milliseconds. Must be a nonzero value. This 12-bit field is reset to 0x040, giving a default blink period of approximately 15.9Hz. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BlinkPeriod, 19, 12)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_18_15, 15, 4)
        /** @brief When this bit is set, the Link LED is solid green when there is a link and blinks when there is traffic. (The LED_MODE field must be set to 00 before enabling this bit). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SharedTraffic_DIV_LinkLEDMode, 14, 1)
        /** @brief When this bit is set, the traffic LED blinks only when traffic is addressed for the device (The LED_MODE field must be set to 00 before enabling this bit). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACMode, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDMode, 11, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDStatusTraffic, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDStatus10, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDStatus100, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDStatus1000, 7, 1)
        /** @brief If set along with the Override Traffic bit, the Traffic LED is turned on. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDTraffic, 6, 1)
        /** @brief If set along with the Override Traffic bit and Traffic LED bit, the Traffic LED will blink with the blink rate specified in Override Blink Rate (bit 31) and Blink Period (bits [30:19]) fields. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LEDTrafficBlink, 5, 1)
        /** @brief If set, overrides hardware control of the Traffic LED. The Traffic LED will then be controlled via bits [6:5]. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, OverrideTraffic, 4, 1)
        /** @brief If set along with the LED Override bit, turns on the 10 Mbps LED. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LED10, 3, 1)
        /** @brief If set along with the LED Override bit, turns on the 100 Mbps LED. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LED100, 2, 1)
        /** @brief If set along with the LED Override bit, turns on the 1000 Mbps LED. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LED1000, 1, 1)
        /** @brief If set, overrides hardware control of the three link LEDs. The LEDs will be controlled via bits [3:1]. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, OverrideLink, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LedControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICELedControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.LedControl. */
        r32.setName("LedControl");
        bits.OverrideLink.setBaseRegister(&r32);
        bits.OverrideLink.setName("OverrideLink");
        bits.LED1000.setBaseRegister(&r32);
        bits.LED1000.setName("LED1000");
        bits.LED100.setBaseRegister(&r32);
        bits.LED100.setName("LED100");
        bits.LED10.setBaseRegister(&r32);
        bits.LED10.setName("LED10");
        bits.OverrideTraffic.setBaseRegister(&r32);
        bits.OverrideTraffic.setName("OverrideTraffic");
        bits.LEDTrafficBlink.setBaseRegister(&r32);
        bits.LEDTrafficBlink.setName("LEDTrafficBlink");
        bits.LEDTraffic.setBaseRegister(&r32);
        bits.LEDTraffic.setName("LEDTraffic");
        bits.LEDStatus1000.setBaseRegister(&r32);
        bits.LEDStatus1000.setName("LEDStatus1000");
        bits.LEDStatus100.setBaseRegister(&r32);
        bits.LEDStatus100.setName("LEDStatus100");
        bits.LEDStatus10.setBaseRegister(&r32);
        bits.LEDStatus10.setName("LEDStatus10");
        bits.LEDStatusTraffic.setBaseRegister(&r32);
        bits.LEDStatusTraffic.setName("LEDStatusTraffic");
        bits.LEDMode.setBaseRegister(&r32);
        bits.LEDMode.setName("LEDMode");
        bits.MACMode.setBaseRegister(&r32);
        bits.MACMode.setName("MACMode");
        bits.SharedTraffic_DIV_LinkLEDMode.setBaseRegister(&r32);
        bits.SharedTraffic_DIV_LinkLEDMode.setName("SharedTraffic_DIV_LinkLEDMode");
        bits.BlinkPeriod.setBaseRegister(&r32);
        bits.BlinkPeriod.setName("BlinkPeriod");
        bits.OverrideBlinkRate.setBaseRegister(&r32);
        bits.OverrideBlinkRate.setName("OverrideBlinkRate");
    }
    RegDEVICELedControl_t& operator=(const RegDEVICELedControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICELedControl_t;

#define REG_DEVICE_EMAC_MAC_ADDRESSES_0_HIGH ((volatile APE_DEVICE_H_uint32_t*)0xa0040410) /* Upper 2-bytes of this node's MAC address. */
/** @brief Register definition for @ref DEVICE_t.EmacMacAddresses0High. */
typedef register_container RegDEVICEEmacMacAddresses0High_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EmacMacAddresses0High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEmacMacAddresses0High_t()
    {
        /** @brief constructor for @ref DEVICE_t.EmacMacAddresses0High. */
        r32.setName("EmacMacAddresses0High");
    }
    RegDEVICEEmacMacAddresses0High_t& operator=(const RegDEVICEEmacMacAddresses0High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEmacMacAddresses0High_t;

#define REG_DEVICE_EMAC_MAC_ADDRESSES_0_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa0040414) /* Lower 4-byte of this node's MAC address. */
/** @brief Register definition for @ref DEVICE_t.EmacMacAddresses0Low. */
typedef register_container RegDEVICEEmacMacAddresses0Low_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EmacMacAddresses0Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEmacMacAddresses0Low_t()
    {
        /** @brief constructor for @ref DEVICE_t.EmacMacAddresses0Low. */
        r32.setName("EmacMacAddresses0Low");
    }
    RegDEVICEEmacMacAddresses0Low_t& operator=(const RegDEVICEEmacMacAddresses0Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEmacMacAddresses0Low_t;

#define REG_DEVICE_EMAC_MAC_ADDRESSES_1_HIGH ((volatile APE_DEVICE_H_uint32_t*)0xa0040418) /* Upper 2-bytes of this node's MAC address. */
/** @brief Register definition for @ref DEVICE_t.EmacMacAddresses1High. */
typedef register_container RegDEVICEEmacMacAddresses1High_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EmacMacAddresses1High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEmacMacAddresses1High_t()
    {
        /** @brief constructor for @ref DEVICE_t.EmacMacAddresses1High. */
        r32.setName("EmacMacAddresses1High");
    }
    RegDEVICEEmacMacAddresses1High_t& operator=(const RegDEVICEEmacMacAddresses1High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEmacMacAddresses1High_t;

#define REG_DEVICE_EMAC_MAC_ADDRESSES_1_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa004041c) /* Lower 4-byte of this node's MAC address. */
/** @brief Register definition for @ref DEVICE_t.EmacMacAddresses1Low. */
typedef register_container RegDEVICEEmacMacAddresses1Low_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EmacMacAddresses1Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEmacMacAddresses1Low_t()
    {
        /** @brief constructor for @ref DEVICE_t.EmacMacAddresses1Low. */
        r32.setName("EmacMacAddresses1Low");
    }
    RegDEVICEEmacMacAddresses1Low_t& operator=(const RegDEVICEEmacMacAddresses1Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEmacMacAddresses1Low_t;

#define REG_DEVICE_EMAC_MAC_ADDRESSES_2_HIGH ((volatile APE_DEVICE_H_uint32_t*)0xa0040420) /* Upper 2-bytes of this node's MAC address. */
/** @brief Register definition for @ref DEVICE_t.EmacMacAddresses2High. */
typedef register_container RegDEVICEEmacMacAddresses2High_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EmacMacAddresses2High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEmacMacAddresses2High_t()
    {
        /** @brief constructor for @ref DEVICE_t.EmacMacAddresses2High. */
        r32.setName("EmacMacAddresses2High");
    }
    RegDEVICEEmacMacAddresses2High_t& operator=(const RegDEVICEEmacMacAddresses2High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEmacMacAddresses2High_t;

#define REG_DEVICE_EMAC_MAC_ADDRESSES_2_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa0040424) /* Lower 4-byte of this node's MAC address. */
/** @brief Register definition for @ref DEVICE_t.EmacMacAddresses2Low. */
typedef register_container RegDEVICEEmacMacAddresses2Low_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EmacMacAddresses2Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEmacMacAddresses2Low_t()
    {
        /** @brief constructor for @ref DEVICE_t.EmacMacAddresses2Low. */
        r32.setName("EmacMacAddresses2Low");
    }
    RegDEVICEEmacMacAddresses2Low_t& operator=(const RegDEVICEEmacMacAddresses2Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEmacMacAddresses2Low_t;

#define REG_DEVICE_EMAC_MAC_ADDRESSES_3_HIGH ((volatile APE_DEVICE_H_uint32_t*)0xa0040428) /* Upper 2-bytes of this node's MAC address. */
/** @brief Register definition for @ref DEVICE_t.EmacMacAddresses3High. */
typedef register_container RegDEVICEEmacMacAddresses3High_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EmacMacAddresses3High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEmacMacAddresses3High_t()
    {
        /** @brief constructor for @ref DEVICE_t.EmacMacAddresses3High. */
        r32.setName("EmacMacAddresses3High");
    }
    RegDEVICEEmacMacAddresses3High_t& operator=(const RegDEVICEEmacMacAddresses3High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEmacMacAddresses3High_t;

#define REG_DEVICE_EMAC_MAC_ADDRESSES_3_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa004042c) /* Lower 4-byte of this node's MAC address. */
/** @brief Register definition for @ref DEVICE_t.EmacMacAddresses3Low. */
typedef register_container RegDEVICEEmacMacAddresses3Low_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EmacMacAddresses3Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEmacMacAddresses3Low_t()
    {
        /** @brief constructor for @ref DEVICE_t.EmacMacAddresses3Low. */
        r32.setName("EmacMacAddresses3Low");
    }
    RegDEVICEEmacMacAddresses3Low_t& operator=(const RegDEVICEEmacMacAddresses3Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEmacMacAddresses3Low_t;

#define REG_DEVICE_WOL_PATTERN_POINTER ((volatile APE_DEVICE_H_uint32_t*)0xa0040430) /* Specifies the offset into the 6KB BD memory for frame comparison. (Bits 3:0 are ignored to align the memory address to a natural 128-bit boundary). */
/** @brief Register definition for @ref DEVICE_t.WolPatternPointer. */
typedef register_container RegDEVICEWolPatternPointer_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "WolPatternPointer"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEWolPatternPointer_t()
    {
        /** @brief constructor for @ref DEVICE_t.WolPatternPointer. */
        r32.setName("WolPatternPointer");
    }
    RegDEVICEWolPatternPointer_t& operator=(const RegDEVICEWolPatternPointer_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEWolPatternPointer_t;

#define REG_DEVICE_WOL_PATTERN_CFG ((volatile APE_DEVICE_H_uint32_t*)0xa0040434) /*  */
/** @brief Register definition for @ref DEVICE_t.WolPatternCfg. */
typedef register_container RegDEVICEWolPatternCfg_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "WolPatternCfg"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEWolPatternCfg_t()
    {
        /** @brief constructor for @ref DEVICE_t.WolPatternCfg. */
        r32.setName("WolPatternCfg");
    }
    RegDEVICEWolPatternCfg_t& operator=(const RegDEVICEWolPatternCfg_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEWolPatternCfg_t;

#define REG_DEVICE_MTU_SIZE ((volatile APE_DEVICE_H_uint32_t*)0xa004043c) /* 2-byte field which is the largest size frame that will be accepted without being marked as oversize. */
#define     DEVICE_MTU_SIZE_MTU_SHIFT 0u
#define     DEVICE_MTU_SIZE_MTU_MASK  0xffffu
#define GET_DEVICE_MTU_SIZE_MTU(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_DEVICE_MTU_SIZE_MTU(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref DEVICE_t.MtuSize. */
typedef register_container RegDEVICEMtuSize_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief 2-byte field which is the largest size frame that will be accepted without being marked as oversize. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MTU, 0, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
        /** @brief 2-byte field which is the largest size frame that will be accepted without being marked as oversize. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MTU, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MtuSize"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMtuSize_t()
    {
        /** @brief constructor for @ref DEVICE_t.MtuSize. */
        r32.setName("MtuSize");
        bits.MTU.setBaseRegister(&r32);
        bits.MTU.setName("MTU");
    }
    RegDEVICEMtuSize_t& operator=(const RegDEVICEMtuSize_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMtuSize_t;

#define REG_DEVICE_MII_COMMUNICATION ((volatile APE_DEVICE_H_uint32_t*)0xa004044c) /*  */
#define     DEVICE_MII_COMMUNICATION_TRANSACTION_DATA_SHIFT 0u
#define     DEVICE_MII_COMMUNICATION_TRANSACTION_DATA_MASK  0xffffu
#define GET_DEVICE_MII_COMMUNICATION_TRANSACTION_DATA(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_DEVICE_MII_COMMUNICATION_TRANSACTION_DATA(__val__)  (((__val__) << 0u) & 0xffffu)
#define     DEVICE_MII_COMMUNICATION_REGISTER_ADDRESS_SHIFT 16u
#define     DEVICE_MII_COMMUNICATION_REGISTER_ADDRESS_MASK  0x1f0000u
#define GET_DEVICE_MII_COMMUNICATION_REGISTER_ADDRESS(__reg__)  (((__reg__) & 0x1f0000) >> 16u)
#define SET_DEVICE_MII_COMMUNICATION_REGISTER_ADDRESS(__val__)  (((__val__) << 16u) & 0x1f0000u)
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SHIFT 21u
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_MASK  0x3e00000u
#define GET_DEVICE_MII_COMMUNICATION_PHY_ADDRESS(__reg__)  (((__reg__) & 0x3e00000) >> 21u)
#define SET_DEVICE_MII_COMMUNICATION_PHY_ADDRESS(__val__)  (((__val__) << 21u) & 0x3e00000u)
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_0 0x1u
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_1 0x2u
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_2 0x3u
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_3 0x4u
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_0 0x8u
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_1 0x9u
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_2 0xau
#define     DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_3 0xbu

#define     DEVICE_MII_COMMUNICATION_COMMAND_SHIFT 26u
#define     DEVICE_MII_COMMUNICATION_COMMAND_MASK  0xc000000u
#define GET_DEVICE_MII_COMMUNICATION_COMMAND(__reg__)  (((__reg__) & 0xc000000) >> 26u)
#define SET_DEVICE_MII_COMMUNICATION_COMMAND(__val__)  (((__val__) << 26u) & 0xc000000u)
#define     DEVICE_MII_COMMUNICATION_COMMAND_WRITE 0x1u
#define     DEVICE_MII_COMMUNICATION_COMMAND_READ 0x2u

#define     DEVICE_MII_COMMUNICATION_READ_FAILED_SHIFT 28u
#define     DEVICE_MII_COMMUNICATION_READ_FAILED_MASK  0x10000000u
#define GET_DEVICE_MII_COMMUNICATION_READ_FAILED(__reg__)  (((__reg__) & 0x10000000) >> 28u)
#define SET_DEVICE_MII_COMMUNICATION_READ_FAILED(__val__)  (((__val__) << 28u) & 0x10000000u)
#define     DEVICE_MII_COMMUNICATION_START_DIV_BUSY_SHIFT 29u
#define     DEVICE_MII_COMMUNICATION_START_DIV_BUSY_MASK  0x20000000u
#define GET_DEVICE_MII_COMMUNICATION_START_DIV_BUSY(__reg__)  (((__reg__) & 0x20000000) >> 29u)
#define SET_DEVICE_MII_COMMUNICATION_START_DIV_BUSY(__val__)  (((__val__) << 29u) & 0x20000000u)

/** @brief Register definition for @ref DEVICE_t.MiiCommunication. */
typedef register_container RegDEVICEMiiCommunication_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief When configured for a write command, the data stored at this location is written to the PHY at the specified PHY and register address. During a read command, the data returned by the PHY is stored at this location. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TransactionData, 0, 16)
        /** @brief Address of the register to be read or written. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RegisterAddress, 16, 5)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PHYAddress, 21, 5)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Command, 26, 2)
        /** @brief When set, the transceiver device did not drive the bus during the attempted read transaction. Valid after the Start/Busy bit is cleared. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ReadFailed, 28, 1)
        /** @brief Set this bit to start a transaction. While it is high, it indicates that the current transaction is still ongoing. If enabled, generates an attention via EMAC Status Register MI Completion bit (bit 22). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Start_DIV_Busy, 29, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_30, 30, 2)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_30, 30, 2)
        /** @brief Set this bit to start a transaction. While it is high, it indicates that the current transaction is still ongoing. If enabled, generates an attention via EMAC Status Register MI Completion bit (bit 22). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Start_DIV_Busy, 29, 1)
        /** @brief When set, the transceiver device did not drive the bus during the attempted read transaction. Valid after the Start/Busy bit is cleared. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ReadFailed, 28, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Command, 26, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PHYAddress, 21, 5)
        /** @brief Address of the register to be read or written. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RegisterAddress, 16, 5)
        /** @brief When configured for a write command, the data stored at this location is written to the PHY at the specified PHY and register address. During a read command, the data returned by the PHY is stored at this location. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TransactionData, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MiiCommunication"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMiiCommunication_t()
    {
        /** @brief constructor for @ref DEVICE_t.MiiCommunication. */
        r32.setName("MiiCommunication");
        bits.TransactionData.setBaseRegister(&r32);
        bits.TransactionData.setName("TransactionData");
        bits.RegisterAddress.setBaseRegister(&r32);
        bits.RegisterAddress.setName("RegisterAddress");
        bits.PHYAddress.setBaseRegister(&r32);
        bits.PHYAddress.setName("PHYAddress");
        bits.Command.setBaseRegister(&r32);
        bits.Command.setName("Command");
        bits.ReadFailed.setBaseRegister(&r32);
        bits.ReadFailed.setName("ReadFailed");
        bits.Start_DIV_Busy.setBaseRegister(&r32);
        bits.Start_DIV_Busy.setName("Start_DIV_Busy");
    }
    RegDEVICEMiiCommunication_t& operator=(const RegDEVICEMiiCommunication_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMiiCommunication_t;

#define REG_DEVICE_MII_MODE ((volatile APE_DEVICE_H_uint32_t*)0xa0040454) /*  */
#define     DEVICE_MII_MODE_PHY_ADDRESS_SHIFT 5u
#define     DEVICE_MII_MODE_PHY_ADDRESS_MASK  0x3e0u
#define GET_DEVICE_MII_MODE_PHY_ADDRESS(__reg__)  (((__reg__) & 0x3e0) >> 5u)
#define SET_DEVICE_MII_MODE_PHY_ADDRESS(__val__)  (((__val__) << 5u) & 0x3e0u)
#define     DEVICE_MII_MODE_CONSTANT_MDIO_DIV_MDC_CLOCK_SPEED_SHIFT 15u
#define     DEVICE_MII_MODE_CONSTANT_MDIO_DIV_MDC_CLOCK_SPEED_MASK  0x8000u
#define GET_DEVICE_MII_MODE_CONSTANT_MDIO_DIV_MDC_CLOCK_SPEED(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_DEVICE_MII_MODE_CONSTANT_MDIO_DIV_MDC_CLOCK_SPEED(__val__)  (((__val__) << 15u) & 0x8000u)
#define     DEVICE_MII_MODE_MII_CLOCK_COUNT_SHIFT 16u
#define     DEVICE_MII_MODE_MII_CLOCK_COUNT_MASK  0x1f0000u
#define GET_DEVICE_MII_MODE_MII_CLOCK_COUNT(__reg__)  (((__reg__) & 0x1f0000) >> 16u)
#define SET_DEVICE_MII_MODE_MII_CLOCK_COUNT(__val__)  (((__val__) << 16u) & 0x1f0000u)

/** @brief Register definition for @ref DEVICE_t.MiiMode. */
typedef register_container RegDEVICEMiiMode_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_4_0, 0, 5)
        /** @brief This field specifies the PHY Address. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PHYAddress, 5, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_14_10, 10, 5)
        /** @brief Enable ~500Khz constant MII management interface (MDIO/MDC) frequency regardless core clock frequency. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ConstantMDIO_DIV_MDCClockSpeed, 15, 1)
        /** @brief Counter to divide CORE_CLK (62.5 MHz) to generate the MI clock. CORE_CLK/2/(MII Clock Count + 1). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MIIClockCount, 16, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Counter to divide CORE_CLK (62.5 MHz) to generate the MI clock. CORE_CLK/2/(MII Clock Count + 1). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MIIClockCount, 16, 5)
        /** @brief Enable ~500Khz constant MII management interface (MDIO/MDC) frequency regardless core clock frequency. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ConstantMDIO_DIV_MDCClockSpeed, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_14_10, 10, 5)
        /** @brief This field specifies the PHY Address. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PHYAddress, 5, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_4_0, 0, 5)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MiiMode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMiiMode_t()
    {
        /** @brief constructor for @ref DEVICE_t.MiiMode. */
        r32.setName("MiiMode");
        bits.PHYAddress.setBaseRegister(&r32);
        bits.PHYAddress.setName("PHYAddress");
        bits.ConstantMDIO_DIV_MDCClockSpeed.setBaseRegister(&r32);
        bits.ConstantMDIO_DIV_MDCClockSpeed.setName("ConstantMDIO_DIV_MDCClockSpeed");
        bits.MIIClockCount.setBaseRegister(&r32);
        bits.MIIClockCount.setName("MIIClockCount");
    }
    RegDEVICEMiiMode_t& operator=(const RegDEVICEMiiMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMiiMode_t;

#define REG_DEVICE_TRANSMIT_MAC_MODE ((volatile APE_DEVICE_H_uint32_t*)0xa004045c) /*  */
#define     DEVICE_TRANSMIT_MAC_MODE_RESET_SHIFT 0u
#define     DEVICE_TRANSMIT_MAC_MODE_RESET_MASK  0x1u
#define GET_DEVICE_TRANSMIT_MAC_MODE_RESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_TRANSMIT_MAC_MODE_RESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_TCE_SHIFT 1u
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_TCE_MASK  0x2u
#define GET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_TCE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_TCE(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_FLOW_CONTROL_SHIFT 4u
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_FLOW_CONTROL_MASK  0x10u
#define GET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_FLOW_CONTROL(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_FLOW_CONTROL(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_BIG_BACKOFF_SHIFT 5u
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_BIG_BACKOFF_MASK  0x20u
#define GET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_BIG_BACKOFF(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_BIG_BACKOFF(__val__)  (((__val__) << 5u) & 0x20u)
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_LONG_PAUSE_SHIFT 6u
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_LONG_PAUSE_MASK  0x40u
#define GET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_LONG_PAUSE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_LONG_PAUSE(__val__)  (((__val__) << 6u) & 0x40u)
#define     DEVICE_TRANSMIT_MAC_MODE_LINK_AWARE_ENABLE_SHIFT 7u
#define     DEVICE_TRANSMIT_MAC_MODE_LINK_AWARE_ENABLE_MASK  0x80u
#define GET_DEVICE_TRANSMIT_MAC_MODE_LINK_AWARE_ENABLE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_TRANSMIT_MAC_MODE_LINK_AWARE_ENABLE(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_TRANSMIT_MAC_MODE_TXMBUF_CORRUPTION_LOCKUP_FIX_ENABLE_SHIFT 8u
#define     DEVICE_TRANSMIT_MAC_MODE_TXMBUF_CORRUPTION_LOCKUP_FIX_ENABLE_MASK  0x100u
#define GET_DEVICE_TRANSMIT_MAC_MODE_TXMBUF_CORRUPTION_LOCKUP_FIX_ENABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_TRANSMIT_MAC_MODE_TXMBUF_CORRUPTION_LOCKUP_FIX_ENABLE(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_TX_ESP_OFFLOAD_SHIFT 9u
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_TX_ESP_OFFLOAD_MASK  0x200u
#define GET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_TX_ESP_OFFLOAD(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_TX_ESP_OFFLOAD(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_TX_AH_OFFLOAD_SHIFT 10u
#define     DEVICE_TRANSMIT_MAC_MODE_ENABLE_TX_AH_OFFLOAD_MASK  0x400u
#define GET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_TX_AH_OFFLOAD(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_DEVICE_TRANSMIT_MAC_MODE_ENABLE_TX_AH_OFFLOAD(__val__)  (((__val__) << 10u) & 0x400u)

/** @brief Register definition for @ref DEVICE_t.TransmitMacMode. */
typedef register_container RegDEVICETransmitMacMode_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief When this bit is set to 1, the Transmit MAC state machine will be reset. This is a self-clearing bit. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Reset, 0, 1)
        /** @brief Used to be enable TDE in legacy-same purpose. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTCE, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_3_2, 2, 2)
        /** @brief MAC will send 802.3x flow control frames. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableFlowControl, 4, 1)
        /** @brief MAC will use larger than normal back-off algorithm. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableBigBackoff, 5, 1)
        /** @brief When set, the Pause time value set in the transmitted PAUSE frames is 0xFFFF. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableLongPause, 6, 1)
        /** @brief When set, transmission of packets by the MAC is enabled only when link is up. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkAwareEnable, 7, 1)
        /** @brief When set, TXMBUF corruption lockup fix is enabled. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TxMBUFCorruptionLockupFixEnable, 8, 1)
        /** @brief A value 1 enables the TX ESP offload feature. When 0, offloaded ESP packet gets dropped. This value must be static. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTXESPOffload, 9, 1)
        /** @brief A value 1 enables the TX AH offload feature. When 0, offloaded AH packet gets dropped. This value must be static. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTXAHOffload, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_11, 11, 21)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_11, 11, 21)
        /** @brief A value 1 enables the TX AH offload feature. When 0, offloaded AH packet gets dropped. This value must be static. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTXAHOffload, 10, 1)
        /** @brief A value 1 enables the TX ESP offload feature. When 0, offloaded ESP packet gets dropped. This value must be static. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTXESPOffload, 9, 1)
        /** @brief When set, TXMBUF corruption lockup fix is enabled. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TxMBUFCorruptionLockupFixEnable, 8, 1)
        /** @brief When set, transmission of packets by the MAC is enabled only when link is up. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkAwareEnable, 7, 1)
        /** @brief When set, the Pause time value set in the transmitted PAUSE frames is 0xFFFF. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableLongPause, 6, 1)
        /** @brief MAC will use larger than normal back-off algorithm. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableBigBackoff, 5, 1)
        /** @brief MAC will send 802.3x flow control frames. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableFlowControl, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_3_2, 2, 2)
        /** @brief Used to be enable TDE in legacy-same purpose. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableTCE, 1, 1)
        /** @brief When this bit is set to 1, the Transmit MAC state machine will be reset. This is a self-clearing bit. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Reset, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TransmitMacMode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICETransmitMacMode_t()
    {
        /** @brief constructor for @ref DEVICE_t.TransmitMacMode. */
        r32.setName("TransmitMacMode");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.EnableTCE.setBaseRegister(&r32);
        bits.EnableTCE.setName("EnableTCE");
        bits.EnableFlowControl.setBaseRegister(&r32);
        bits.EnableFlowControl.setName("EnableFlowControl");
        bits.EnableBigBackoff.setBaseRegister(&r32);
        bits.EnableBigBackoff.setName("EnableBigBackoff");
        bits.EnableLongPause.setBaseRegister(&r32);
        bits.EnableLongPause.setName("EnableLongPause");
        bits.LinkAwareEnable.setBaseRegister(&r32);
        bits.LinkAwareEnable.setName("LinkAwareEnable");
        bits.TxMBUFCorruptionLockupFixEnable.setBaseRegister(&r32);
        bits.TxMBUFCorruptionLockupFixEnable.setName("TxMBUFCorruptionLockupFixEnable");
        bits.EnableTXESPOffload.setBaseRegister(&r32);
        bits.EnableTXESPOffload.setName("EnableTXESPOffload");
        bits.EnableTXAHOffload.setBaseRegister(&r32);
        bits.EnableTXAHOffload.setName("EnableTXAHOffload");
    }
    RegDEVICETransmitMacMode_t& operator=(const RegDEVICETransmitMacMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICETransmitMacMode_t;

#define REG_DEVICE_RECEIVE_MAC_MODE ((volatile APE_DEVICE_H_uint32_t*)0xa0040468) /*  */
#define     DEVICE_RECEIVE_MAC_MODE_RESET_SHIFT 0u
#define     DEVICE_RECEIVE_MAC_MODE_RESET_MASK  0x1u
#define GET_DEVICE_RECEIVE_MAC_MODE_RESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_RECEIVE_MAC_MODE_RESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_RECEIVE_MAC_MODE_ENABLE_SHIFT 1u
#define     DEVICE_RECEIVE_MAC_MODE_ENABLE_MASK  0x2u
#define GET_DEVICE_RECEIVE_MAC_MODE_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_RECEIVE_MAC_MODE_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_RECEIVE_MAC_MODE_PROMISCUOUS_MODE_SHIFT 8u
#define     DEVICE_RECEIVE_MAC_MODE_PROMISCUOUS_MODE_MASK  0x100u
#define GET_DEVICE_RECEIVE_MAC_MODE_PROMISCUOUS_MODE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_RECEIVE_MAC_MODE_PROMISCUOUS_MODE(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_RECEIVE_MAC_MODE_APE_PROMISCUOUS_MODE_SHIFT 25u
#define     DEVICE_RECEIVE_MAC_MODE_APE_PROMISCUOUS_MODE_MASK  0x2000000u
#define GET_DEVICE_RECEIVE_MAC_MODE_APE_PROMISCUOUS_MODE(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_DEVICE_RECEIVE_MAC_MODE_APE_PROMISCUOUS_MODE(__val__)  (((__val__) << 25u) & 0x2000000u)

/** @brief Register definition for @ref DEVICE_t.ReceiveMacMode. */
typedef register_container RegDEVICEReceiveMacMode_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief When this bit is set to 1, the Receive MAC state machine will be reset. This is a self-clearing bit. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Reset, 0, 1)
        /** @brief This bit controls whether the Receive MAC state machine is active or not. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Enable, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_7_2, 2, 6)
        /** @brief When set, no source address or MC hashing checking will be performed on incoming frames. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PromiscuousMode, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_24_9, 9, 16)
        /** @brief When set, no source address or MC hashing checking will be performed on incoming frames on APE filter path. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEPromiscuousMode, 25, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_26, 26, 6)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_26, 26, 6)
        /** @brief When set, no source address or MC hashing checking will be performed on incoming frames on APE filter path. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEPromiscuousMode, 25, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_24_9, 9, 16)
        /** @brief When set, no source address or MC hashing checking will be performed on incoming frames. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PromiscuousMode, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_7_2, 2, 6)
        /** @brief This bit controls whether the Receive MAC state machine is active or not. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Enable, 1, 1)
        /** @brief When this bit is set to 1, the Receive MAC state machine will be reset. This is a self-clearing bit. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Reset, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ReceiveMacMode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEReceiveMacMode_t()
    {
        /** @brief constructor for @ref DEVICE_t.ReceiveMacMode. */
        r32.setName("ReceiveMacMode");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.PromiscuousMode.setBaseRegister(&r32);
        bits.PromiscuousMode.setName("PromiscuousMode");
        bits.APEPromiscuousMode.setBaseRegister(&r32);
        bits.APEPromiscuousMode.setName("APEPromiscuousMode");
    }
    RegDEVICEReceiveMacMode_t& operator=(const RegDEVICEReceiveMacMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEReceiveMacMode_t;

#define REG_DEVICE_PERFECT_MATCH1_HIGH ((volatile APE_DEVICE_H_uint32_t*)0xa0040540) /*  */
#define     DEVICE_PERFECT_MATCH1_HIGH_HIGH_SHIFT 0u
#define     DEVICE_PERFECT_MATCH1_HIGH_HIGH_MASK  0xffffu
#define GET_DEVICE_PERFECT_MATCH1_HIGH_HIGH(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_DEVICE_PERFECT_MATCH1_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref DEVICE_t.PerfectMatch1High. */
typedef register_container RegDEVICEPerfectMatch1High_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper two bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, High, 0, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
        /** @brief Upper two bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, High, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerfectMatch1High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPerfectMatch1High_t()
    {
        /** @brief constructor for @ref DEVICE_t.PerfectMatch1High. */
        r32.setName("PerfectMatch1High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegDEVICEPerfectMatch1High_t& operator=(const RegDEVICEPerfectMatch1High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPerfectMatch1High_t;

#define REG_DEVICE_PERFECT_MATCH1_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa0040544) /*  */
#define     DEVICE_PERFECT_MATCH1_LOW_LOW_SHIFT 0u
#define     DEVICE_PERFECT_MATCH1_LOW_LOW_MASK  0xffffffffu
#define GET_DEVICE_PERFECT_MATCH1_LOW_LOW(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_DEVICE_PERFECT_MATCH1_LOW_LOW(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref DEVICE_t.PerfectMatch1Low. */
typedef register_container RegDEVICEPerfectMatch1Low_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Lower four bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Low, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower four bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Low, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerfectMatch1Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPerfectMatch1Low_t()
    {
        /** @brief constructor for @ref DEVICE_t.PerfectMatch1Low. */
        r32.setName("PerfectMatch1Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegDEVICEPerfectMatch1Low_t& operator=(const RegDEVICEPerfectMatch1Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPerfectMatch1Low_t;

#define REG_DEVICE_PERFECT_MATCH2_HIGH ((volatile APE_DEVICE_H_uint32_t*)0xa0040548) /*  */
#define     DEVICE_PERFECT_MATCH2_HIGH_HIGH_SHIFT 0u
#define     DEVICE_PERFECT_MATCH2_HIGH_HIGH_MASK  0xffffu
#define GET_DEVICE_PERFECT_MATCH2_HIGH_HIGH(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_DEVICE_PERFECT_MATCH2_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref DEVICE_t.PerfectMatch2High. */
typedef register_container RegDEVICEPerfectMatch2High_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper two bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, High, 0, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
        /** @brief Upper two bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, High, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerfectMatch2High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPerfectMatch2High_t()
    {
        /** @brief constructor for @ref DEVICE_t.PerfectMatch2High. */
        r32.setName("PerfectMatch2High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegDEVICEPerfectMatch2High_t& operator=(const RegDEVICEPerfectMatch2High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPerfectMatch2High_t;

#define REG_DEVICE_PERFECT_MATCH2_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa004054c) /*  */
#define     DEVICE_PERFECT_MATCH2_LOW_LOW_SHIFT 0u
#define     DEVICE_PERFECT_MATCH2_LOW_LOW_MASK  0xffffffffu
#define GET_DEVICE_PERFECT_MATCH2_LOW_LOW(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_DEVICE_PERFECT_MATCH2_LOW_LOW(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref DEVICE_t.PerfectMatch2Low. */
typedef register_container RegDEVICEPerfectMatch2Low_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Lower four bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Low, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower four bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Low, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerfectMatch2Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPerfectMatch2Low_t()
    {
        /** @brief constructor for @ref DEVICE_t.PerfectMatch2Low. */
        r32.setName("PerfectMatch2Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegDEVICEPerfectMatch2Low_t& operator=(const RegDEVICEPerfectMatch2Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPerfectMatch2Low_t;

#define REG_DEVICE_PERFECT_MATCH3_HIGH ((volatile APE_DEVICE_H_uint32_t*)0xa0040550) /*  */
#define     DEVICE_PERFECT_MATCH3_HIGH_HIGH_SHIFT 0u
#define     DEVICE_PERFECT_MATCH3_HIGH_HIGH_MASK  0xffffu
#define GET_DEVICE_PERFECT_MATCH3_HIGH_HIGH(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_DEVICE_PERFECT_MATCH3_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref DEVICE_t.PerfectMatch3High. */
typedef register_container RegDEVICEPerfectMatch3High_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper two bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, High, 0, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
        /** @brief Upper two bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, High, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerfectMatch3High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPerfectMatch3High_t()
    {
        /** @brief constructor for @ref DEVICE_t.PerfectMatch3High. */
        r32.setName("PerfectMatch3High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegDEVICEPerfectMatch3High_t& operator=(const RegDEVICEPerfectMatch3High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPerfectMatch3High_t;

#define REG_DEVICE_PERFECT_MATCH3_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa0040554) /*  */
#define     DEVICE_PERFECT_MATCH3_LOW_LOW_SHIFT 0u
#define     DEVICE_PERFECT_MATCH3_LOW_LOW_MASK  0xffffffffu
#define GET_DEVICE_PERFECT_MATCH3_LOW_LOW(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_DEVICE_PERFECT_MATCH3_LOW_LOW(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref DEVICE_t.PerfectMatch3Low. */
typedef register_container RegDEVICEPerfectMatch3Low_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Lower four bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Low, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower four bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Low, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerfectMatch3Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPerfectMatch3Low_t()
    {
        /** @brief constructor for @ref DEVICE_t.PerfectMatch3Low. */
        r32.setName("PerfectMatch3Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegDEVICEPerfectMatch3Low_t& operator=(const RegDEVICEPerfectMatch3Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPerfectMatch3Low_t;

#define REG_DEVICE_PERFECT_MATCH4_HIGH ((volatile APE_DEVICE_H_uint32_t*)0xa0040558) /*  */
#define     DEVICE_PERFECT_MATCH4_HIGH_HIGH_SHIFT 0u
#define     DEVICE_PERFECT_MATCH4_HIGH_HIGH_MASK  0xffffu
#define GET_DEVICE_PERFECT_MATCH4_HIGH_HIGH(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_DEVICE_PERFECT_MATCH4_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref DEVICE_t.PerfectMatch4High. */
typedef register_container RegDEVICEPerfectMatch4High_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper two bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, High, 0, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_16, 16, 16)
        /** @brief Upper two bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, High, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerfectMatch4High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPerfectMatch4High_t()
    {
        /** @brief constructor for @ref DEVICE_t.PerfectMatch4High. */
        r32.setName("PerfectMatch4High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegDEVICEPerfectMatch4High_t& operator=(const RegDEVICEPerfectMatch4High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPerfectMatch4High_t;

#define REG_DEVICE_PERFECT_MATCH4_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa004055c) /*  */
#define     DEVICE_PERFECT_MATCH4_LOW_LOW_SHIFT 0u
#define     DEVICE_PERFECT_MATCH4_LOW_LOW_MASK  0xffffffffu
#define GET_DEVICE_PERFECT_MATCH4_LOW_LOW(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_DEVICE_PERFECT_MATCH4_LOW_LOW(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref DEVICE_t.PerfectMatch4Low. */
typedef register_container RegDEVICEPerfectMatch4Low_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Lower four bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Low, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower four bytes of the MAC */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Low, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerfectMatch4Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPerfectMatch4Low_t()
    {
        /** @brief constructor for @ref DEVICE_t.PerfectMatch4Low. */
        r32.setName("PerfectMatch4Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegDEVICEPerfectMatch4Low_t& operator=(const RegDEVICEPerfectMatch4Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPerfectMatch4Low_t;

#define REG_DEVICE_SGMII_STATUS ((volatile APE_DEVICE_H_uint32_t*)0xa00405b4) /* This register reflects various status of the respective SGMII port when enabled. */
#define     DEVICE_SGMII_STATUS_AUTONEGOTIATION_COMPLETE_SHIFT 0u
#define     DEVICE_SGMII_STATUS_AUTONEGOTIATION_COMPLETE_MASK  0x1u
#define GET_DEVICE_SGMII_STATUS_AUTONEGOTIATION_COMPLETE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_SGMII_STATUS_AUTONEGOTIATION_COMPLETE(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_SGMII_STATUS_LINK_STATUS_SHIFT 1u
#define     DEVICE_SGMII_STATUS_LINK_STATUS_MASK  0x2u
#define GET_DEVICE_SGMII_STATUS_LINK_STATUS(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_SGMII_STATUS_LINK_STATUS(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_SGMII_STATUS_DUPLEX_STATUS_SHIFT 2u
#define     DEVICE_SGMII_STATUS_DUPLEX_STATUS_MASK  0x4u
#define GET_DEVICE_SGMII_STATUS_DUPLEX_STATUS(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_SGMII_STATUS_DUPLEX_STATUS(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_SGMII_STATUS_SPEED_1000_SHIFT 3u
#define     DEVICE_SGMII_STATUS_SPEED_1000_MASK  0x8u
#define GET_DEVICE_SGMII_STATUS_SPEED_1000(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_DEVICE_SGMII_STATUS_SPEED_1000(__val__)  (((__val__) << 3u) & 0x8u)
#define     DEVICE_SGMII_STATUS_SPEED_100_SHIFT 4u
#define     DEVICE_SGMII_STATUS_SPEED_100_MASK  0x10u
#define GET_DEVICE_SGMII_STATUS_SPEED_100(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_SGMII_STATUS_SPEED_100(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_SGMII_STATUS_NEXT_PAGE_RX_SHIFT 5u
#define     DEVICE_SGMII_STATUS_NEXT_PAGE_RX_MASK  0x20u
#define GET_DEVICE_SGMII_STATUS_NEXT_PAGE_RX(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_SGMII_STATUS_NEXT_PAGE_RX(__val__)  (((__val__) << 5u) & 0x20u)
#define     DEVICE_SGMII_STATUS_PAUSE_RX_SHIFT 6u
#define     DEVICE_SGMII_STATUS_PAUSE_RX_MASK  0x40u
#define GET_DEVICE_SGMII_STATUS_PAUSE_RX(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_DEVICE_SGMII_STATUS_PAUSE_RX(__val__)  (((__val__) << 6u) & 0x40u)
#define     DEVICE_SGMII_STATUS_PAUSE_TX_SHIFT 7u
#define     DEVICE_SGMII_STATUS_PAUSE_TX_MASK  0x80u
#define GET_DEVICE_SGMII_STATUS_PAUSE_TX(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_SGMII_STATUS_PAUSE_TX(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_SGMII_STATUS_MEDIA_SELECTION_MODE_SHIFT 8u
#define     DEVICE_SGMII_STATUS_MEDIA_SELECTION_MODE_MASK  0x100u
#define GET_DEVICE_SGMII_STATUS_MEDIA_SELECTION_MODE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_SGMII_STATUS_MEDIA_SELECTION_MODE(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_SGMII_STATUS_MEDIA_SELECTION_MODE_COPPER 0x0u
#define     DEVICE_SGMII_STATUS_MEDIA_SELECTION_MODE_SGMII 0x1u

#define     DEVICE_SGMII_STATUS_PCS_CRS_DETECT_SHIFT 9u
#define     DEVICE_SGMII_STATUS_PCS_CRS_DETECT_MASK  0x200u
#define GET_DEVICE_SGMII_STATUS_PCS_CRS_DETECT(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_SGMII_STATUS_PCS_CRS_DETECT(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_SGMII_STATUS_EXTERNAL_CRS_DETECT_SHIFT 10u
#define     DEVICE_SGMII_STATUS_EXTERNAL_CRS_DETECT_MASK  0x400u
#define GET_DEVICE_SGMII_STATUS_EXTERNAL_CRS_DETECT(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_DEVICE_SGMII_STATUS_EXTERNAL_CRS_DETECT(__val__)  (((__val__) << 10u) & 0x400u)
#define     DEVICE_SGMII_STATUS_LINK_PARTNER_AUTONEGOTIATION_CAPABILITY_SHIFT 16u
#define     DEVICE_SGMII_STATUS_LINK_PARTNER_AUTONEGOTIATION_CAPABILITY_MASK  0xffff0000u
#define GET_DEVICE_SGMII_STATUS_LINK_PARTNER_AUTONEGOTIATION_CAPABILITY(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_DEVICE_SGMII_STATUS_LINK_PARTNER_AUTONEGOTIATION_CAPABILITY(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref DEVICE_t.SgmiiStatus. */
typedef register_container RegDEVICESgmiiStatus_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Auto-negotiation process has completed. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AutonegotiationComplete, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkStatus, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DuplexStatus, 2, 1)
        /** @brief The SGMII Link currently operable at 1 Gbps data speed. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Speed1000, 3, 1)
        /** @brief The SGMII Link currently operable at 100mbps data speed. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Speed100, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NextPageRX, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PauseRX, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PauseTX, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MediaSelectionMode, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCSCRSDetect, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ExternalCRSDetect, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_11, 11, 5)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkPartnerAutonegotiationCapability, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkPartnerAutonegotiationCapability, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_11, 11, 5)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ExternalCRSDetect, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCSCRSDetect, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MediaSelectionMode, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PauseTX, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PauseRX, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NextPageRX, 5, 1)
        /** @brief The SGMII Link currently operable at 100mbps data speed. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Speed100, 4, 1)
        /** @brief The SGMII Link currently operable at 1 Gbps data speed. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Speed1000, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DuplexStatus, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkStatus, 1, 1)
        /** @brief Auto-negotiation process has completed. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AutonegotiationComplete, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SgmiiStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICESgmiiStatus_t()
    {
        /** @brief constructor for @ref DEVICE_t.SgmiiStatus. */
        r32.setName("SgmiiStatus");
        bits.AutonegotiationComplete.setBaseRegister(&r32);
        bits.AutonegotiationComplete.setName("AutonegotiationComplete");
        bits.LinkStatus.setBaseRegister(&r32);
        bits.LinkStatus.setName("LinkStatus");
        bits.DuplexStatus.setBaseRegister(&r32);
        bits.DuplexStatus.setName("DuplexStatus");
        bits.Speed1000.setBaseRegister(&r32);
        bits.Speed1000.setName("Speed1000");
        bits.Speed100.setBaseRegister(&r32);
        bits.Speed100.setName("Speed100");
        bits.NextPageRX.setBaseRegister(&r32);
        bits.NextPageRX.setName("NextPageRX");
        bits.PauseRX.setBaseRegister(&r32);
        bits.PauseRX.setName("PauseRX");
        bits.PauseTX.setBaseRegister(&r32);
        bits.PauseTX.setName("PauseTX");
        bits.MediaSelectionMode.setBaseRegister(&r32);
        bits.MediaSelectionMode.setName("MediaSelectionMode");
        bits.PCSCRSDetect.setBaseRegister(&r32);
        bits.PCSCRSDetect.setName("PCSCRSDetect");
        bits.ExternalCRSDetect.setBaseRegister(&r32);
        bits.ExternalCRSDetect.setName("ExternalCRSDetect");
        bits.LinkPartnerAutonegotiationCapability.setBaseRegister(&r32);
        bits.LinkPartnerAutonegotiationCapability.setName("LinkPartnerAutonegotiationCapability");
    }
    RegDEVICESgmiiStatus_t& operator=(const RegDEVICESgmiiStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICESgmiiStatus_t;

#define REG_DEVICE_CPMU_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa0043600) /*  */
#define     DEVICE_CPMU_CONTROL_CPMU_SOFTWARE_RESET_SHIFT 0u
#define     DEVICE_CPMU_CONTROL_CPMU_SOFTWARE_RESET_MASK  0x1u
#define GET_DEVICE_CPMU_CONTROL_CPMU_SOFTWARE_RESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_CPMU_CONTROL_CPMU_SOFTWARE_RESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_CPMU_CONTROL_CPMU_REGISTER_SOFTWARE_RESET_SHIFT 1u
#define     DEVICE_CPMU_CONTROL_CPMU_REGISTER_SOFTWARE_RESET_MASK  0x2u
#define GET_DEVICE_CPMU_CONTROL_CPMU_REGISTER_SOFTWARE_RESET(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_CPMU_CONTROL_CPMU_REGISTER_SOFTWARE_RESET(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_CPMU_CONTROL_POWER_DOWN_SHIFT 2u
#define     DEVICE_CPMU_CONTROL_POWER_DOWN_MASK  0x4u
#define GET_DEVICE_CPMU_CONTROL_POWER_DOWN(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_CPMU_CONTROL_POWER_DOWN(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_CPMU_CONTROL_APE_SLEEP_MODE_ENABLE_SHIFT 4u
#define     DEVICE_CPMU_CONTROL_APE_SLEEP_MODE_ENABLE_MASK  0x10u
#define GET_DEVICE_CPMU_CONTROL_APE_SLEEP_MODE_ENABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_CPMU_CONTROL_APE_SLEEP_MODE_ENABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_CPMU_CONTROL_APE_DEEP_SLEEP_MODE_ENABLE_SHIFT 5u
#define     DEVICE_CPMU_CONTROL_APE_DEEP_SLEEP_MODE_ENABLE_MASK  0x20u
#define GET_DEVICE_CPMU_CONTROL_APE_DEEP_SLEEP_MODE_ENABLE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_CPMU_CONTROL_APE_DEEP_SLEEP_MODE_ENABLE(__val__)  (((__val__) << 5u) & 0x20u)
#define     DEVICE_CPMU_CONTROL_LINK_IDLE_POWER_MODE_ENABLE_SHIFT 9u
#define     DEVICE_CPMU_CONTROL_LINK_IDLE_POWER_MODE_ENABLE_MASK  0x200u
#define GET_DEVICE_CPMU_CONTROL_LINK_IDLE_POWER_MODE_ENABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_CPMU_CONTROL_LINK_IDLE_POWER_MODE_ENABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_CPMU_CONTROL_LINK_AWARE_POWER_MODE_ENABLE_SHIFT 10u
#define     DEVICE_CPMU_CONTROL_LINK_AWARE_POWER_MODE_ENABLE_MASK  0x400u
#define GET_DEVICE_CPMU_CONTROL_LINK_AWARE_POWER_MODE_ENABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_DEVICE_CPMU_CONTROL_LINK_AWARE_POWER_MODE_ENABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     DEVICE_CPMU_CONTROL_LINK_SPEED_POWER_MODE_ENABLE_SHIFT 14u
#define     DEVICE_CPMU_CONTROL_LINK_SPEED_POWER_MODE_ENABLE_MASK  0x4000u
#define GET_DEVICE_CPMU_CONTROL_LINK_SPEED_POWER_MODE_ENABLE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_DEVICE_CPMU_CONTROL_LINK_SPEED_POWER_MODE_ENABLE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     DEVICE_CPMU_CONTROL_GPHY_10MB_RECEIVE_ONLY_MODE_ENABLE_SHIFT 16u
#define     DEVICE_CPMU_CONTROL_GPHY_10MB_RECEIVE_ONLY_MODE_ENABLE_MASK  0x10000u
#define GET_DEVICE_CPMU_CONTROL_GPHY_10MB_RECEIVE_ONLY_MODE_ENABLE(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_DEVICE_CPMU_CONTROL_GPHY_10MB_RECEIVE_ONLY_MODE_ENABLE(__val__)  (((__val__) << 16u) & 0x10000u)
#define     DEVICE_CPMU_CONTROL_LEGACY_TIMER_ENABLE_SHIFT 18u
#define     DEVICE_CPMU_CONTROL_LEGACY_TIMER_ENABLE_MASK  0x40000u
#define GET_DEVICE_CPMU_CONTROL_LEGACY_TIMER_ENABLE(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_DEVICE_CPMU_CONTROL_LEGACY_TIMER_ENABLE(__val__)  (((__val__) << 18u) & 0x40000u)
#define     DEVICE_CPMU_CONTROL_SGMII_DIV_PCS_POWER_DOWN_SHIFT 19u
#define     DEVICE_CPMU_CONTROL_SGMII_DIV_PCS_POWER_DOWN_MASK  0x80000u
#define GET_DEVICE_CPMU_CONTROL_SGMII_DIV_PCS_POWER_DOWN(__reg__)  (((__reg__) & 0x80000) >> 19u)
#define SET_DEVICE_CPMU_CONTROL_SGMII_DIV_PCS_POWER_DOWN(__val__)  (((__val__) << 19u) & 0x80000u)
#define     DEVICE_CPMU_CONTROL_SOFTWARE_CONTROLLED_GPHY_FORCE_DLL_ON_SHIFT 28u
#define     DEVICE_CPMU_CONTROL_SOFTWARE_CONTROLLED_GPHY_FORCE_DLL_ON_MASK  0x10000000u
#define GET_DEVICE_CPMU_CONTROL_SOFTWARE_CONTROLLED_GPHY_FORCE_DLL_ON(__reg__)  (((__reg__) & 0x10000000) >> 28u)
#define SET_DEVICE_CPMU_CONTROL_SOFTWARE_CONTROLLED_GPHY_FORCE_DLL_ON(__val__)  (((__val__) << 28u) & 0x10000000u)

/** @brief Register definition for @ref DEVICE_t.CpmuControl. */
typedef register_container RegDEVICECpmuControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMUSoftwareReset, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMURegisterSoftwareReset, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerDown, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APESleepModeEnable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEDeepSleepModeEnable, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_8_6, 6, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkIdlePowerModeEnable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkAwarePowerModeEnable, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_13_11, 11, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkSpeedPowerModeEnable, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_15, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPHY10MBReceiveOnlyModeEnable, 16, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_17_17, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LegacyTimerEnable, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SGMII_DIV_PCSPowerDown, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_27_20, 20, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SoftwareControlledGPHYForceDLLOn, 28, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_29, 29, 3)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_29, 29, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SoftwareControlledGPHYForceDLLOn, 28, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_27_20, 20, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SGMII_DIV_PCSPowerDown, 19, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LegacyTimerEnable, 18, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_17_17, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPHY10MBReceiveOnlyModeEnable, 16, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_15, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkSpeedPowerModeEnable, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_13_11, 11, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkAwarePowerModeEnable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkIdlePowerModeEnable, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_8_6, 6, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEDeepSleepModeEnable, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APESleepModeEnable, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerDown, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMURegisterSoftwareReset, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMUSoftwareReset, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "CpmuControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICECpmuControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.CpmuControl. */
        r32.setName("CpmuControl");
        bits.CPMUSoftwareReset.setBaseRegister(&r32);
        bits.CPMUSoftwareReset.setName("CPMUSoftwareReset");
        bits.CPMURegisterSoftwareReset.setBaseRegister(&r32);
        bits.CPMURegisterSoftwareReset.setName("CPMURegisterSoftwareReset");
        bits.PowerDown.setBaseRegister(&r32);
        bits.PowerDown.setName("PowerDown");
        bits.APESleepModeEnable.setBaseRegister(&r32);
        bits.APESleepModeEnable.setName("APESleepModeEnable");
        bits.APEDeepSleepModeEnable.setBaseRegister(&r32);
        bits.APEDeepSleepModeEnable.setName("APEDeepSleepModeEnable");
        bits.LinkIdlePowerModeEnable.setBaseRegister(&r32);
        bits.LinkIdlePowerModeEnable.setName("LinkIdlePowerModeEnable");
        bits.LinkAwarePowerModeEnable.setBaseRegister(&r32);
        bits.LinkAwarePowerModeEnable.setName("LinkAwarePowerModeEnable");
        bits.LinkSpeedPowerModeEnable.setBaseRegister(&r32);
        bits.LinkSpeedPowerModeEnable.setName("LinkSpeedPowerModeEnable");
        bits.GPHY10MBReceiveOnlyModeEnable.setBaseRegister(&r32);
        bits.GPHY10MBReceiveOnlyModeEnable.setName("GPHY10MBReceiveOnlyModeEnable");
        bits.LegacyTimerEnable.setBaseRegister(&r32);
        bits.LegacyTimerEnable.setName("LegacyTimerEnable");
        bits.SGMII_DIV_PCSPowerDown.setBaseRegister(&r32);
        bits.SGMII_DIV_PCSPowerDown.setName("SGMII_DIV_PCSPowerDown");
        bits.SoftwareControlledGPHYForceDLLOn.setBaseRegister(&r32);
        bits.SoftwareControlledGPHYForceDLLOn.setName("SoftwareControlledGPHYForceDLLOn");
    }
    RegDEVICECpmuControl_t& operator=(const RegDEVICECpmuControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICECpmuControl_t;

#define REG_DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY ((volatile APE_DEVICE_H_uint32_t*)0xa0043610) /*  */
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_SHIFT 16u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_MASK  0x1f0000u
#define GET_DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH(__reg__)  (((__reg__) & 0x1f0000) >> 16u)
#define SET_DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH(__val__)  (((__val__) << 16u) & 0x1f0000u)
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_60_0MHZ 0x1u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_30_0MHZ 0x3u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_15_0MHZ 0x5u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_7_5MHZ 0x7u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_3_75MHZ 0x9u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_12_5MHZ 0x11u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_6_25MHZ 0x13u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_3_125MHZ 0x15u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_1_563MHZ 0x17u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_781KHZ 0x19u
#define     DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_12_5MHZ_DIV_1_25MHZ 0x1fu


/** @brief Register definition for @ref DEVICE_t.LinkAwarePowerModeClockPolicy. */
typedef register_container RegDEVICELinkAwarePowerModeClockPolicy_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Software Controlled MAC Core Clock Speed Select. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACClockSwitch, 16, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Software Controlled MAC Core Clock Speed Select. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACClockSwitch, 16, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LinkAwarePowerModeClockPolicy"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICELinkAwarePowerModeClockPolicy_t()
    {
        /** @brief constructor for @ref DEVICE_t.LinkAwarePowerModeClockPolicy. */
        r32.setName("LinkAwarePowerModeClockPolicy");
        bits.MACClockSwitch.setBaseRegister(&r32);
        bits.MACClockSwitch.setName("MACClockSwitch");
    }
    RegDEVICELinkAwarePowerModeClockPolicy_t& operator=(const RegDEVICELinkAwarePowerModeClockPolicy_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICELinkAwarePowerModeClockPolicy_t;

#define REG_DEVICE_CLOCK_SPEED_OVERRIDE_POLICY ((volatile APE_DEVICE_H_uint32_t*)0xa0043624) /*  */
#define     DEVICE_CLOCK_SPEED_OVERRIDE_POLICY_MAC_CLOCK_SWITCH_SHIFT 16u
#define     DEVICE_CLOCK_SPEED_OVERRIDE_POLICY_MAC_CLOCK_SWITCH_MASK  0x1f0000u
#define GET_DEVICE_CLOCK_SPEED_OVERRIDE_POLICY_MAC_CLOCK_SWITCH(__reg__)  (((__reg__) & 0x1f0000) >> 16u)
#define SET_DEVICE_CLOCK_SPEED_OVERRIDE_POLICY_MAC_CLOCK_SWITCH(__val__)  (((__val__) << 16u) & 0x1f0000u)
#define     DEVICE_CLOCK_SPEED_OVERRIDE_POLICY_MAC_CLOCK_SPEED_OVERRIDE_ENABLED_SHIFT 31u
#define     DEVICE_CLOCK_SPEED_OVERRIDE_POLICY_MAC_CLOCK_SPEED_OVERRIDE_ENABLED_MASK  0x80000000u
#define GET_DEVICE_CLOCK_SPEED_OVERRIDE_POLICY_MAC_CLOCK_SPEED_OVERRIDE_ENABLED(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_DEVICE_CLOCK_SPEED_OVERRIDE_POLICY_MAC_CLOCK_SPEED_OVERRIDE_ENABLED(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref DEVICE_t.ClockSpeedOverridePolicy. */
typedef register_container RegDEVICEClockSpeedOverridePolicy_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Software Controlled MAC Core Clock Speed Select */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACClockSwitch, 16, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_30_21, 21, 10)
        /** @brief Enable MAC clock speed override */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACClockSpeedOverrideEnabled, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Enable MAC clock speed override */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACClockSpeedOverrideEnabled, 31, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_30_21, 21, 10)
        /** @brief Software Controlled MAC Core Clock Speed Select */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACClockSwitch, 16, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ClockSpeedOverridePolicy"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEClockSpeedOverridePolicy_t()
    {
        /** @brief constructor for @ref DEVICE_t.ClockSpeedOverridePolicy. */
        r32.setName("ClockSpeedOverridePolicy");
        bits.MACClockSwitch.setBaseRegister(&r32);
        bits.MACClockSwitch.setName("MACClockSwitch");
        bits.MACClockSpeedOverrideEnabled.setBaseRegister(&r32);
        bits.MACClockSpeedOverrideEnabled.setName("MACClockSpeedOverrideEnabled");
    }
    RegDEVICEClockSpeedOverridePolicy_t& operator=(const RegDEVICEClockSpeedOverridePolicy_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEClockSpeedOverridePolicy_t;

#define REG_DEVICE_STATUS ((volatile APE_DEVICE_H_uint32_t*)0xa004362c) /*  */
#define     DEVICE_STATUS_POWER_MANAGEMENT_STATE_MACHINE_STATE_SHIFT 0u
#define     DEVICE_STATUS_POWER_MANAGEMENT_STATE_MACHINE_STATE_MASK  0xfu
#define GET_DEVICE_STATUS_POWER_MANAGEMENT_STATE_MACHINE_STATE(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_DEVICE_STATUS_POWER_MANAGEMENT_STATE_MACHINE_STATE(__val__)  (((__val__) << 0u) & 0xfu)
#define     DEVICE_STATUS_CPMU_POWER_STATE_SHIFT 4u
#define     DEVICE_STATUS_CPMU_POWER_STATE_MASK  0x70u
#define GET_DEVICE_STATUS_CPMU_POWER_STATE(__reg__)  (((__reg__) & 0x70) >> 4u)
#define SET_DEVICE_STATUS_CPMU_POWER_STATE(__val__)  (((__val__) << 4u) & 0x70u)
#define     DEVICE_STATUS_ENERGY_DETECT_STATUS_SHIFT 7u
#define     DEVICE_STATUS_ENERGY_DETECT_STATUS_MASK  0x80u
#define GET_DEVICE_STATUS_ENERGY_DETECT_STATUS(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_STATUS_ENERGY_DETECT_STATUS(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_STATUS_POWER_STATE_SHIFT 8u
#define     DEVICE_STATUS_POWER_STATE_MASK  0x300u
#define GET_DEVICE_STATUS_POWER_STATE(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_DEVICE_STATUS_POWER_STATE(__val__)  (((__val__) << 8u) & 0x300u)
#define     DEVICE_STATUS_VMAIN_POWER_STATUS_SHIFT 13u
#define     DEVICE_STATUS_VMAIN_POWER_STATUS_MASK  0x2000u
#define GET_DEVICE_STATUS_VMAIN_POWER_STATUS(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_DEVICE_STATUS_VMAIN_POWER_STATUS(__val__)  (((__val__) << 13u) & 0x2000u)
#define     DEVICE_STATUS_WOL_MAGIC_PACKET_DETECTION_ENABLE_PORT_0_SHIFT 14u
#define     DEVICE_STATUS_WOL_MAGIC_PACKET_DETECTION_ENABLE_PORT_0_MASK  0x4000u
#define GET_DEVICE_STATUS_WOL_MAGIC_PACKET_DETECTION_ENABLE_PORT_0(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_DEVICE_STATUS_WOL_MAGIC_PACKET_DETECTION_ENABLE_PORT_0(__val__)  (((__val__) << 14u) & 0x4000u)
#define     DEVICE_STATUS_WOL_ACPI_DETECTION_ENABLE_PORT_0_SHIFT 15u
#define     DEVICE_STATUS_WOL_ACPI_DETECTION_ENABLE_PORT_0_MASK  0x8000u
#define GET_DEVICE_STATUS_WOL_ACPI_DETECTION_ENABLE_PORT_0(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_DEVICE_STATUS_WOL_ACPI_DETECTION_ENABLE_PORT_0(__val__)  (((__val__) << 15u) & 0x8000u)
#define     DEVICE_STATUS_NCSI_DLL_LOCK_STATUS_SHIFT 16u
#define     DEVICE_STATUS_NCSI_DLL_LOCK_STATUS_MASK  0x10000u
#define GET_DEVICE_STATUS_NCSI_DLL_LOCK_STATUS(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_DEVICE_STATUS_NCSI_DLL_LOCK_STATUS(__val__)  (((__val__) << 16u) & 0x10000u)
#define     DEVICE_STATUS_GPHY_DLL_LOCK_STATUS_SHIFT 17u
#define     DEVICE_STATUS_GPHY_DLL_LOCK_STATUS_MASK  0x20000u
#define GET_DEVICE_STATUS_GPHY_DLL_LOCK_STATUS(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_DEVICE_STATUS_GPHY_DLL_LOCK_STATUS(__val__)  (((__val__) << 17u) & 0x20000u)
#define     DEVICE_STATUS_LINK_IDLE_STATUS_SHIFT 18u
#define     DEVICE_STATUS_LINK_IDLE_STATUS_MASK  0x40000u
#define GET_DEVICE_STATUS_LINK_IDLE_STATUS(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_DEVICE_STATUS_LINK_IDLE_STATUS(__val__)  (((__val__) << 18u) & 0x40000u)
#define     DEVICE_STATUS_ETHERNET_LINK_STATUS_SHIFT 19u
#define     DEVICE_STATUS_ETHERNET_LINK_STATUS_MASK  0x180000u
#define GET_DEVICE_STATUS_ETHERNET_LINK_STATUS(__reg__)  (((__reg__) & 0x180000) >> 19u)
#define SET_DEVICE_STATUS_ETHERNET_LINK_STATUS(__val__)  (((__val__) << 19u) & 0x180000u)
#define     DEVICE_STATUS_ETHERNET_LINK_STATUS_1000_MB 0x0u
#define     DEVICE_STATUS_ETHERNET_LINK_STATUS_100_MB 0x1u
#define     DEVICE_STATUS_ETHERNET_LINK_STATUS_10_MB 0x2u
#define     DEVICE_STATUS_ETHERNET_LINK_STATUS_NO_LINK 0x3u

#define     DEVICE_STATUS_WOL_MAGIC_PACKET_DETECTION_ENABLE_PORT_1_SHIFT 21u
#define     DEVICE_STATUS_WOL_MAGIC_PACKET_DETECTION_ENABLE_PORT_1_MASK  0x200000u
#define GET_DEVICE_STATUS_WOL_MAGIC_PACKET_DETECTION_ENABLE_PORT_1(__reg__)  (((__reg__) & 0x200000) >> 21u)
#define SET_DEVICE_STATUS_WOL_MAGIC_PACKET_DETECTION_ENABLE_PORT_1(__val__)  (((__val__) << 21u) & 0x200000u)
#define     DEVICE_STATUS_WOL_ACPI_DETECTION_ENABLE_PORT_1_SHIFT 22u
#define     DEVICE_STATUS_WOL_ACPI_DETECTION_ENABLE_PORT_1_MASK  0x400000u
#define GET_DEVICE_STATUS_WOL_ACPI_DETECTION_ENABLE_PORT_1(__reg__)  (((__reg__) & 0x400000) >> 22u)
#define SET_DEVICE_STATUS_WOL_ACPI_DETECTION_ENABLE_PORT_1(__val__)  (((__val__) << 22u) & 0x400000u)
#define     DEVICE_STATUS_APE_STATUS_SHIFT 23u
#define     DEVICE_STATUS_APE_STATUS_MASK  0x1800000u
#define GET_DEVICE_STATUS_APE_STATUS(__reg__)  (((__reg__) & 0x1800000) >> 23u)
#define SET_DEVICE_STATUS_APE_STATUS(__val__)  (((__val__) << 23u) & 0x1800000u)
#define     DEVICE_STATUS_APE_STATUS_ACTIVE 0x0u
#define     DEVICE_STATUS_APE_STATUS_SLEEP 0x1u
#define     DEVICE_STATUS_APE_STATUS_DEEP_SLEEP 0x2u

#define     DEVICE_STATUS_FUNCTION_ENABLE_SHIFT 25u
#define     DEVICE_STATUS_FUNCTION_ENABLE_MASK  0x3e000000u
#define GET_DEVICE_STATUS_FUNCTION_ENABLE(__reg__)  (((__reg__) & 0x3e000000) >> 25u)
#define SET_DEVICE_STATUS_FUNCTION_ENABLE(__val__)  (((__val__) << 25u) & 0x3e000000u)
#define     DEVICE_STATUS_FUNCTION_NUMBER_SHIFT 30u
#define     DEVICE_STATUS_FUNCTION_NUMBER_MASK  0xc0000000u
#define GET_DEVICE_STATUS_FUNCTION_NUMBER(__reg__)  (((__reg__) & 0xc0000000) >> 30u)
#define SET_DEVICE_STATUS_FUNCTION_NUMBER(__val__)  (((__val__) << 30u) & 0xc0000000u)

/** @brief Register definition for @ref DEVICE_t.Status. */
typedef register_container RegDEVICEStatus_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerManagementStateMachineState, 0, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMUPowerState, 4, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnergyDetectStatus, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerState, 8, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_12_10, 10, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VMAINPowerStatus, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, WOLMagicPacketDetectionEnablePort0, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, WOLACPIDetectionEnablePort0, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NCSIDLLLockStatus, 16, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPHYDLLLockStatus, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkIdleStatus, 18, 1)
        /** @brief EthernetLink Status */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EthernetLinkStatus, 19, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, WOLMagicPacketDetectionEnablePort1, 21, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, WOLACPIDetectionEnablePort1, 22, 1)
        /** @brief APE Engine Status */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEStatus, 23, 2)
        /** @brief Function Enable input from System BIOS */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FunctionEnable, 25, 5)
        /** @brief PCIE function number */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FunctionNumber, 30, 2)
#elif defined(__BIG_ENDIAN__)
        /** @brief PCIE function number */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FunctionNumber, 30, 2)
        /** @brief Function Enable input from System BIOS */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FunctionEnable, 25, 5)
        /** @brief APE Engine Status */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEStatus, 23, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, WOLACPIDetectionEnablePort1, 22, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, WOLMagicPacketDetectionEnablePort1, 21, 1)
        /** @brief EthernetLink Status */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EthernetLinkStatus, 19, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LinkIdleStatus, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPHYDLLLockStatus, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NCSIDLLLockStatus, 16, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, WOLACPIDetectionEnablePort0, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, WOLMagicPacketDetectionEnablePort0, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VMAINPowerStatus, 13, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_12_10, 10, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerState, 8, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnergyDetectStatus, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMUPowerState, 4, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerManagementStateMachineState, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Status"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEStatus_t()
    {
        /** @brief constructor for @ref DEVICE_t.Status. */
        r32.setName("Status");
        bits.PowerManagementStateMachineState.setBaseRegister(&r32);
        bits.PowerManagementStateMachineState.setName("PowerManagementStateMachineState");
        bits.CPMUPowerState.setBaseRegister(&r32);
        bits.CPMUPowerState.setName("CPMUPowerState");
        bits.EnergyDetectStatus.setBaseRegister(&r32);
        bits.EnergyDetectStatus.setName("EnergyDetectStatus");
        bits.PowerState.setBaseRegister(&r32);
        bits.PowerState.setName("PowerState");
        bits.VMAINPowerStatus.setBaseRegister(&r32);
        bits.VMAINPowerStatus.setName("VMAINPowerStatus");
        bits.WOLMagicPacketDetectionEnablePort0.setBaseRegister(&r32);
        bits.WOLMagicPacketDetectionEnablePort0.setName("WOLMagicPacketDetectionEnablePort0");
        bits.WOLACPIDetectionEnablePort0.setBaseRegister(&r32);
        bits.WOLACPIDetectionEnablePort0.setName("WOLACPIDetectionEnablePort0");
        bits.NCSIDLLLockStatus.setBaseRegister(&r32);
        bits.NCSIDLLLockStatus.setName("NCSIDLLLockStatus");
        bits.GPHYDLLLockStatus.setBaseRegister(&r32);
        bits.GPHYDLLLockStatus.setName("GPHYDLLLockStatus");
        bits.LinkIdleStatus.setBaseRegister(&r32);
        bits.LinkIdleStatus.setName("LinkIdleStatus");
        bits.EthernetLinkStatus.setBaseRegister(&r32);
        bits.EthernetLinkStatus.setName("EthernetLinkStatus");
        bits.WOLMagicPacketDetectionEnablePort1.setBaseRegister(&r32);
        bits.WOLMagicPacketDetectionEnablePort1.setName("WOLMagicPacketDetectionEnablePort1");
        bits.WOLACPIDetectionEnablePort1.setBaseRegister(&r32);
        bits.WOLACPIDetectionEnablePort1.setName("WOLACPIDetectionEnablePort1");
        bits.APEStatus.setBaseRegister(&r32);
        bits.APEStatus.setName("APEStatus");
        bits.FunctionEnable.setBaseRegister(&r32);
        bits.FunctionEnable.setName("FunctionEnable");
        bits.FunctionNumber.setBaseRegister(&r32);
        bits.FunctionNumber.setName("FunctionNumber");
    }
    RegDEVICEStatus_t& operator=(const RegDEVICEStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEStatus_t;

#define REG_DEVICE_CLOCK_STATUS ((volatile APE_DEVICE_H_uint32_t*)0xa0043630) /*  */
/** @brief Register definition for @ref DEVICE_t.ClockStatus. */
typedef register_container RegDEVICEClockStatus_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ClockStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEClockStatus_t()
    {
        /** @brief constructor for @ref DEVICE_t.ClockStatus. */
        r32.setName("ClockStatus");
    }
    RegDEVICEClockStatus_t& operator=(const RegDEVICEClockStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEClockStatus_t;

#define REG_DEVICE_GPHY_CONTROL_STATUS ((volatile APE_DEVICE_H_uint32_t*)0xa0043638) /*  */
#define     DEVICE_GPHY_CONTROL_STATUS_GPHY_IDDQ_SHIFT 0u
#define     DEVICE_GPHY_CONTROL_STATUS_GPHY_IDDQ_MASK  0x1u
#define GET_DEVICE_GPHY_CONTROL_STATUS_GPHY_IDDQ(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_GPHY_CONTROL_STATUS_GPHY_IDDQ(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_GPHY_CONTROL_STATUS_BIAS_IDDQ_SHIFT 1u
#define     DEVICE_GPHY_CONTROL_STATUS_BIAS_IDDQ_MASK  0x2u
#define GET_DEVICE_GPHY_CONTROL_STATUS_BIAS_IDDQ(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_GPHY_CONTROL_STATUS_BIAS_IDDQ(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_GPHY_CONTROL_STATUS_CPMU_SOFTWARE_RESET_SHIFT 2u
#define     DEVICE_GPHY_CONTROL_STATUS_CPMU_SOFTWARE_RESET_MASK  0x4u
#define GET_DEVICE_GPHY_CONTROL_STATUS_CPMU_SOFTWARE_RESET(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_GPHY_CONTROL_STATUS_CPMU_SOFTWARE_RESET(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_GPHY_CONTROL_STATUS_CPMU_REGISTER_SOFTWARE_RESET_SHIFT 3u
#define     DEVICE_GPHY_CONTROL_STATUS_CPMU_REGISTER_SOFTWARE_RESET_MASK  0x8u
#define GET_DEVICE_GPHY_CONTROL_STATUS_CPMU_REGISTER_SOFTWARE_RESET(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_DEVICE_GPHY_CONTROL_STATUS_CPMU_REGISTER_SOFTWARE_RESET(__val__)  (((__val__) << 3u) & 0x8u)
#define     DEVICE_GPHY_CONTROL_STATUS_POWER_DOWN_SHIFT 4u
#define     DEVICE_GPHY_CONTROL_STATUS_POWER_DOWN_MASK  0x10u
#define GET_DEVICE_GPHY_CONTROL_STATUS_POWER_DOWN(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_GPHY_CONTROL_STATUS_POWER_DOWN(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_GPHY_CONTROL_STATUS_SGMII_DIV_PCS_POWER_DOWN_SHIFT 15u
#define     DEVICE_GPHY_CONTROL_STATUS_SGMII_DIV_PCS_POWER_DOWN_MASK  0x8000u
#define GET_DEVICE_GPHY_CONTROL_STATUS_SGMII_DIV_PCS_POWER_DOWN(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_DEVICE_GPHY_CONTROL_STATUS_SGMII_DIV_PCS_POWER_DOWN(__val__)  (((__val__) << 15u) & 0x8000u)
#define     DEVICE_GPHY_CONTROL_STATUS_NCSI_PLL_LOCK_STATUS_SHIFT 25u
#define     DEVICE_GPHY_CONTROL_STATUS_NCSI_PLL_LOCK_STATUS_MASK  0x2000000u
#define GET_DEVICE_GPHY_CONTROL_STATUS_NCSI_PLL_LOCK_STATUS(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_DEVICE_GPHY_CONTROL_STATUS_NCSI_PLL_LOCK_STATUS(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     DEVICE_GPHY_CONTROL_STATUS_TLP_CLOCK_SOURCE_SHIFT 26u
#define     DEVICE_GPHY_CONTROL_STATUS_TLP_CLOCK_SOURCE_MASK  0x4000000u
#define GET_DEVICE_GPHY_CONTROL_STATUS_TLP_CLOCK_SOURCE(__reg__)  (((__reg__) & 0x4000000) >> 26u)
#define SET_DEVICE_GPHY_CONTROL_STATUS_TLP_CLOCK_SOURCE(__val__)  (((__val__) << 26u) & 0x4000000u)
#define     DEVICE_GPHY_CONTROL_STATUS_SWITCHING_REGULATOR_POWER_DOWN_SHIFT 27u
#define     DEVICE_GPHY_CONTROL_STATUS_SWITCHING_REGULATOR_POWER_DOWN_MASK  0x8000000u
#define GET_DEVICE_GPHY_CONTROL_STATUS_SWITCHING_REGULATOR_POWER_DOWN(__reg__)  (((__reg__) & 0x8000000) >> 27u)
#define SET_DEVICE_GPHY_CONTROL_STATUS_SWITCHING_REGULATOR_POWER_DOWN(__val__)  (((__val__) << 27u) & 0x8000000u)

/** @brief Register definition for @ref DEVICE_t.GphyControlStatus. */
typedef register_container RegDEVICEGphyControlStatus_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief When this bit is set, GPHY will be powered down. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPHYIDDQ, 0, 1)
        /** @brief When this bit is set, BIAS will be powered down. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BIASIDDQ, 1, 1)
        /** @brief Software reset for all the CPMU logic expect for registers. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMUSoftwareReset, 2, 1)
        /** @brief Software reset for resetting all the registers to default. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMURegisterSoftwareReset, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerDown, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_14_5, 5, 10)
        /** @brief Setting this bit will powerdown SGMII-PCS module. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SGMII_DIV_PCSPowerDown, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_24_16, 16, 9)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NCSIPLLLockStatus, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TLPClockSource, 26, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SwitchingRegulatorPowerDown, 27, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_28, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_28, 28, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SwitchingRegulatorPowerDown, 27, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TLPClockSource, 26, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NCSIPLLLockStatus, 25, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_24_16, 16, 9)
        /** @brief Setting this bit will powerdown SGMII-PCS module. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SGMII_DIV_PCSPowerDown, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_14_5, 5, 10)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerDown, 4, 1)
        /** @brief Software reset for resetting all the registers to default. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMURegisterSoftwareReset, 3, 1)
        /** @brief Software reset for all the CPMU logic expect for registers. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, CPMUSoftwareReset, 2, 1)
        /** @brief When this bit is set, BIAS will be powered down. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BIASIDDQ, 1, 1)
        /** @brief When this bit is set, GPHY will be powered down. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPHYIDDQ, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GphyControlStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEGphyControlStatus_t()
    {
        /** @brief constructor for @ref DEVICE_t.GphyControlStatus. */
        r32.setName("GphyControlStatus");
        bits.GPHYIDDQ.setBaseRegister(&r32);
        bits.GPHYIDDQ.setName("GPHYIDDQ");
        bits.BIASIDDQ.setBaseRegister(&r32);
        bits.BIASIDDQ.setName("BIASIDDQ");
        bits.CPMUSoftwareReset.setBaseRegister(&r32);
        bits.CPMUSoftwareReset.setName("CPMUSoftwareReset");
        bits.CPMURegisterSoftwareReset.setBaseRegister(&r32);
        bits.CPMURegisterSoftwareReset.setName("CPMURegisterSoftwareReset");
        bits.PowerDown.setBaseRegister(&r32);
        bits.PowerDown.setName("PowerDown");
        bits.SGMII_DIV_PCSPowerDown.setBaseRegister(&r32);
        bits.SGMII_DIV_PCSPowerDown.setName("SGMII_DIV_PCSPowerDown");
        bits.NCSIPLLLockStatus.setBaseRegister(&r32);
        bits.NCSIPLLLockStatus.setName("NCSIPLLLockStatus");
        bits.TLPClockSource.setBaseRegister(&r32);
        bits.TLPClockSource.setName("TLPClockSource");
        bits.SwitchingRegulatorPowerDown.setBaseRegister(&r32);
        bits.SwitchingRegulatorPowerDown.setName("SwitchingRegulatorPowerDown");
    }
    RegDEVICEGphyControlStatus_t& operator=(const RegDEVICEGphyControlStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEGphyControlStatus_t;

#define REG_DEVICE_CHIP_ID ((volatile APE_DEVICE_H_uint32_t*)0xa0043658) /*  */
/** @brief Register definition for @ref DEVICE_t.ChipId. */
typedef register_container RegDEVICEChipId_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ChipId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEChipId_t()
    {
        /** @brief constructor for @ref DEVICE_t.ChipId. */
        r32.setName("ChipId");
    }
    RegDEVICEChipId_t& operator=(const RegDEVICEChipId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEChipId_t;

#define REG_DEVICE_MUTEX_REQUEST ((volatile APE_DEVICE_H_uint32_t*)0xa004365c) /* Writing a 1 to any of these bits pends a Mutex lock request on behalf of a software agent. The bit is subsequently latched by hardware and shall read 1 as long as the request is pending. Writing a 0 to a bit shall have no effect. */
/** @brief Register definition for @ref DEVICE_t.MutexRequest. */
typedef register_container RegDEVICEMutexRequest_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MutexRequest"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMutexRequest_t()
    {
        /** @brief constructor for @ref DEVICE_t.MutexRequest. */
        r32.setName("MutexRequest");
    }
    RegDEVICEMutexRequest_t& operator=(const RegDEVICEMutexRequest_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMutexRequest_t;

#define REG_DEVICE_MUTEX_GRANT ((volatile APE_DEVICE_H_uint32_t*)0xa0043660) /* Reading this field shall return a maximum of one set bit at any time. The set bit shall point to the lock owner. If the Mutex is not locked, then a read shall return a value 0x0000. Writing a 1 to the already set bit shall relinquish the lock and the set bit shall be cleared. Writing a 1 to an unset bit shall cancel the corresponding pending request if there was one, and the pairing bit in the Mutex_Request_Reg shall be cleared. */
/** @brief Register definition for @ref DEVICE_t.MutexGrant. */
typedef register_container RegDEVICEMutexGrant_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MutexGrant"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMutexGrant_t()
    {
        /** @brief constructor for @ref DEVICE_t.MutexGrant. */
        r32.setName("MutexGrant");
    }
    RegDEVICEMutexGrant_t& operator=(const RegDEVICEMutexGrant_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMutexGrant_t;

#define REG_DEVICE_GPHY_STRAP ((volatile APE_DEVICE_H_uint32_t*)0xa0043664) /*  */
#define     DEVICE_GPHY_STRAP_TXMBUF_ECC_ENABLE_SHIFT 2u
#define     DEVICE_GPHY_STRAP_TXMBUF_ECC_ENABLE_MASK  0x4u
#define GET_DEVICE_GPHY_STRAP_TXMBUF_ECC_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_GPHY_STRAP_TXMBUF_ECC_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_GPHY_STRAP_RXMBUF_ECC_ENABLE_SHIFT 3u
#define     DEVICE_GPHY_STRAP_RXMBUF_ECC_ENABLE_MASK  0x8u
#define GET_DEVICE_GPHY_STRAP_RXMBUF_ECC_ENABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_DEVICE_GPHY_STRAP_RXMBUF_ECC_ENABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     DEVICE_GPHY_STRAP_RXCPU_SPAD_ECC_ENABLE_SHIFT 4u
#define     DEVICE_GPHY_STRAP_RXCPU_SPAD_ECC_ENABLE_MASK  0x10u
#define GET_DEVICE_GPHY_STRAP_RXCPU_SPAD_ECC_ENABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_GPHY_STRAP_RXCPU_SPAD_ECC_ENABLE(__val__)  (((__val__) << 4u) & 0x10u)

/** @brief Register definition for @ref DEVICE_t.GphyStrap. */
typedef register_container RegDEVICEGphyStrap_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_1_0, 0, 2)
        /** @brief Enable TXMBUF ECC. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TXMBUFECCEnable, 2, 1)
        /** @brief Enable RXMBUF ECC. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXMBUFECCEnable, 3, 1)
        /** @brief Enable ECC for rxcpu scratchpad. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXCPUSPADECCEnable, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_5, 5, 27)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_5, 5, 27)
        /** @brief Enable ECC for rxcpu scratchpad. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXCPUSPADECCEnable, 4, 1)
        /** @brief Enable RXMBUF ECC. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXMBUFECCEnable, 3, 1)
        /** @brief Enable TXMBUF ECC. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TXMBUFECCEnable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_1_0, 0, 2)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GphyStrap"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEGphyStrap_t()
    {
        /** @brief constructor for @ref DEVICE_t.GphyStrap. */
        r32.setName("GphyStrap");
        bits.TXMBUFECCEnable.setBaseRegister(&r32);
        bits.TXMBUFECCEnable.setName("TXMBUFECCEnable");
        bits.RXMBUFECCEnable.setBaseRegister(&r32);
        bits.RXMBUFECCEnable.setName("RXMBUFECCEnable");
        bits.RXCPUSPADECCEnable.setBaseRegister(&r32);
        bits.RXCPUSPADECCEnable.setName("RXCPUSPADECCEnable");
    }
    RegDEVICEGphyStrap_t& operator=(const RegDEVICEGphyStrap_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEGphyStrap_t;

#define REG_DEVICE_TOP_LEVEL_MISCELLANEOUS_CONTROL_1 ((volatile APE_DEVICE_H_uint32_t*)0xa004367c) /*  */
#define     DEVICE_TOP_LEVEL_MISCELLANEOUS_CONTROL_1_NCSI_CLOCK_OUTPUT_DISABLE_SHIFT 4u
#define     DEVICE_TOP_LEVEL_MISCELLANEOUS_CONTROL_1_NCSI_CLOCK_OUTPUT_DISABLE_MASK  0x10u
#define GET_DEVICE_TOP_LEVEL_MISCELLANEOUS_CONTROL_1_NCSI_CLOCK_OUTPUT_DISABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_TOP_LEVEL_MISCELLANEOUS_CONTROL_1_NCSI_CLOCK_OUTPUT_DISABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_TOP_LEVEL_MISCELLANEOUS_CONTROL_1_LOW_POWER_IDDQ_MODE_SHIFT 5u
#define     DEVICE_TOP_LEVEL_MISCELLANEOUS_CONTROL_1_LOW_POWER_IDDQ_MODE_MASK  0x20u
#define GET_DEVICE_TOP_LEVEL_MISCELLANEOUS_CONTROL_1_LOW_POWER_IDDQ_MODE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_TOP_LEVEL_MISCELLANEOUS_CONTROL_1_LOW_POWER_IDDQ_MODE(__val__)  (((__val__) << 5u) & 0x20u)

/** @brief Register definition for @ref DEVICE_t.TopLevelMiscellaneousControl1. */
typedef register_container RegDEVICETopLevelMiscellaneousControl1_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_3_0, 0, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NCSIClockOutputDisable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LowPowerIDDQMode, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_6, 6, 26)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_6, 6, 26)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, LowPowerIDDQMode, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NCSIClockOutputDisable, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_3_0, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TopLevelMiscellaneousControl1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICETopLevelMiscellaneousControl1_t()
    {
        /** @brief constructor for @ref DEVICE_t.TopLevelMiscellaneousControl1. */
        r32.setName("TopLevelMiscellaneousControl1");
        bits.NCSIClockOutputDisable.setBaseRegister(&r32);
        bits.NCSIClockOutputDisable.setName("NCSIClockOutputDisable");
        bits.LowPowerIDDQMode.setBaseRegister(&r32);
        bits.LowPowerIDDQMode.setName("LowPowerIDDQMode");
    }
    RegDEVICETopLevelMiscellaneousControl1_t& operator=(const RegDEVICETopLevelMiscellaneousControl1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICETopLevelMiscellaneousControl1_t;

#define REG_DEVICE_EEE_MODE ((volatile APE_DEVICE_H_uint32_t*)0xa00436b0) /*  */
#define     DEVICE_EEE_MODE_RX_CPU_ALLOW_LPI_SHIFT 0u
#define     DEVICE_EEE_MODE_RX_CPU_ALLOW_LPI_MASK  0x1u
#define GET_DEVICE_EEE_MODE_RX_CPU_ALLOW_LPI(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_EEE_MODE_RX_CPU_ALLOW_LPI(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_EEE_MODE_DRIVE_ALLOW_LPI_SHIFT 1u
#define     DEVICE_EEE_MODE_DRIVE_ALLOW_LPI_MASK  0x2u
#define GET_DEVICE_EEE_MODE_DRIVE_ALLOW_LPI(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_EEE_MODE_DRIVE_ALLOW_LPI(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_EEE_MODE_APE_TX_DETECTION_ENABLE_SHIFT 2u
#define     DEVICE_EEE_MODE_APE_TX_DETECTION_ENABLE_MASK  0x4u
#define GET_DEVICE_EEE_MODE_APE_TX_DETECTION_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_EEE_MODE_APE_TX_DETECTION_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_EEE_MODE_EEE_LINK_IDLE_DETECTION_ENABLE_SHIFT 3u
#define     DEVICE_EEE_MODE_EEE_LINK_IDLE_DETECTION_ENABLE_MASK  0x8u
#define GET_DEVICE_EEE_MODE_EEE_LINK_IDLE_DETECTION_ENABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_DEVICE_EEE_MODE_EEE_LINK_IDLE_DETECTION_ENABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     DEVICE_EEE_MODE_PCIE_L1_EXIT_DETECTION_ENABLE_SHIFT 4u
#define     DEVICE_EEE_MODE_PCIE_L1_EXIT_DETECTION_ENABLE_MASK  0x10u
#define GET_DEVICE_EEE_MODE_PCIE_L1_EXIT_DETECTION_ENABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_EEE_MODE_PCIE_L1_EXIT_DETECTION_ENABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_EEE_MODE_RX_CPU_ALLOW_LPI_ENABLE_SHIFT 5u
#define     DEVICE_EEE_MODE_RX_CPU_ALLOW_LPI_ENABLE_MASK  0x20u
#define GET_DEVICE_EEE_MODE_RX_CPU_ALLOW_LPI_ENABLE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_EEE_MODE_RX_CPU_ALLOW_LPI_ENABLE(__val__)  (((__val__) << 5u) & 0x20u)
#define     DEVICE_EEE_MODE_SEND_INDEX_DETECTION_ENABLE_SHIFT 6u
#define     DEVICE_EEE_MODE_SEND_INDEX_DETECTION_ENABLE_MASK  0x40u
#define GET_DEVICE_EEE_MODE_SEND_INDEX_DETECTION_ENABLE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_DEVICE_EEE_MODE_SEND_INDEX_DETECTION_ENABLE(__val__)  (((__val__) << 6u) & 0x40u)
#define     DEVICE_EEE_MODE_USER_LPI_ENABLE_SHIFT 7u
#define     DEVICE_EEE_MODE_USER_LPI_ENABLE_MASK  0x80u
#define GET_DEVICE_EEE_MODE_USER_LPI_ENABLE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_EEE_MODE_USER_LPI_ENABLE(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_EEE_MODE_TX_LPI_ENABLE_SHIFT 8u
#define     DEVICE_EEE_MODE_TX_LPI_ENABLE_MASK  0x100u
#define GET_DEVICE_EEE_MODE_TX_LPI_ENABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_EEE_MODE_TX_LPI_ENABLE(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_EEE_MODE_RX_LPI_ENABLE_SHIFT 9u
#define     DEVICE_EEE_MODE_RX_LPI_ENABLE_MASK  0x200u
#define GET_DEVICE_EEE_MODE_RX_LPI_ENABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_EEE_MODE_RX_LPI_ENABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_EEE_MODE_AUTO_WAKE_ENABLE_SHIFT 10u
#define     DEVICE_EEE_MODE_AUTO_WAKE_ENABLE_MASK  0x400u
#define GET_DEVICE_EEE_MODE_AUTO_WAKE_ENABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_DEVICE_EEE_MODE_AUTO_WAKE_ENABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     DEVICE_EEE_MODE_BLOCK_TIME_SHIFT 11u
#define     DEVICE_EEE_MODE_BLOCK_TIME_MASK  0x7f800u
#define GET_DEVICE_EEE_MODE_BLOCK_TIME(__reg__)  (((__reg__) & 0x7f800) >> 11u)
#define SET_DEVICE_EEE_MODE_BLOCK_TIME(__val__)  (((__val__) << 11u) & 0x7f800u)
#define     DEVICE_EEE_MODE_DRIVE_ALLOW_LPI_ENABLE_SHIFT 19u
#define     DEVICE_EEE_MODE_DRIVE_ALLOW_LPI_ENABLE_MASK  0x80000u
#define GET_DEVICE_EEE_MODE_DRIVE_ALLOW_LPI_ENABLE(__reg__)  (((__reg__) & 0x80000) >> 19u)
#define SET_DEVICE_EEE_MODE_DRIVE_ALLOW_LPI_ENABLE(__val__)  (((__val__) << 19u) & 0x80000u)

/** @brief Register definition for @ref DEVICE_t.EeeMode. */
typedef register_container RegDEVICEEeeMode_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXCPUAllowLPI, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DriveAllowLPI, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APETXDetectionEnable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EEELinkIdleDetectionEnable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIeL1ExitDetectionEnable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXCPUAllowLPIEnable, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SendIndexDetectionEnable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, UserLPIEnable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TXLPIEnable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXLPIEnable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AutoWakeEnable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BlockTime, 11, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DriveAllowLPIEnable, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_20, 20, 12)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_20, 20, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DriveAllowLPIEnable, 19, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BlockTime, 11, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AutoWakeEnable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXLPIEnable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TXLPIEnable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, UserLPIEnable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SendIndexDetectionEnable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXCPUAllowLPIEnable, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIeL1ExitDetectionEnable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EEELinkIdleDetectionEnable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APETXDetectionEnable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DriveAllowLPI, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXCPUAllowLPI, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EeeMode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEeeMode_t()
    {
        /** @brief constructor for @ref DEVICE_t.EeeMode. */
        r32.setName("EeeMode");
        bits.RXCPUAllowLPI.setBaseRegister(&r32);
        bits.RXCPUAllowLPI.setName("RXCPUAllowLPI");
        bits.DriveAllowLPI.setBaseRegister(&r32);
        bits.DriveAllowLPI.setName("DriveAllowLPI");
        bits.APETXDetectionEnable.setBaseRegister(&r32);
        bits.APETXDetectionEnable.setName("APETXDetectionEnable");
        bits.EEELinkIdleDetectionEnable.setBaseRegister(&r32);
        bits.EEELinkIdleDetectionEnable.setName("EEELinkIdleDetectionEnable");
        bits.PCIeL1ExitDetectionEnable.setBaseRegister(&r32);
        bits.PCIeL1ExitDetectionEnable.setName("PCIeL1ExitDetectionEnable");
        bits.RXCPUAllowLPIEnable.setBaseRegister(&r32);
        bits.RXCPUAllowLPIEnable.setName("RXCPUAllowLPIEnable");
        bits.SendIndexDetectionEnable.setBaseRegister(&r32);
        bits.SendIndexDetectionEnable.setName("SendIndexDetectionEnable");
        bits.UserLPIEnable.setBaseRegister(&r32);
        bits.UserLPIEnable.setName("UserLPIEnable");
        bits.TXLPIEnable.setBaseRegister(&r32);
        bits.TXLPIEnable.setName("TXLPIEnable");
        bits.RXLPIEnable.setBaseRegister(&r32);
        bits.RXLPIEnable.setName("RXLPIEnable");
        bits.AutoWakeEnable.setBaseRegister(&r32);
        bits.AutoWakeEnable.setName("AutoWakeEnable");
        bits.BlockTime.setBaseRegister(&r32);
        bits.BlockTime.setName("BlockTime");
        bits.DriveAllowLPIEnable.setBaseRegister(&r32);
        bits.DriveAllowLPIEnable.setName("DriveAllowLPIEnable");
    }
    RegDEVICEEeeMode_t& operator=(const RegDEVICEEeeMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEeeMode_t;

#define REG_DEVICE_EEE_LINK_IDLE_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa00436bc) /*  */
#define     DEVICE_EEE_LINK_IDLE_CONTROL_DEBUG_UART_IDLE_SHIFT 2u
#define     DEVICE_EEE_LINK_IDLE_CONTROL_DEBUG_UART_IDLE_MASK  0x4u
#define GET_DEVICE_EEE_LINK_IDLE_CONTROL_DEBUG_UART_IDLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_EEE_LINK_IDLE_CONTROL_DEBUG_UART_IDLE(__val__)  (((__val__) << 2u) & 0x4u)

/** @brief Register definition for @ref DEVICE_t.EeeLinkIdleControl. */
typedef register_container RegDEVICEEeeLinkIdleControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_1_0, 0, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DebugUARTIdle, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_3, 3, 29)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_3, 3, 29)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DebugUARTIdle, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_1_0, 0, 2)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EeeLinkIdleControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEeeLinkIdleControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.EeeLinkIdleControl. */
        r32.setName("EeeLinkIdleControl");
        bits.DebugUARTIdle.setBaseRegister(&r32);
        bits.DebugUARTIdle.setName("DebugUARTIdle");
    }
    RegDEVICEEeeLinkIdleControl_t& operator=(const RegDEVICEEeeLinkIdleControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEeeLinkIdleControl_t;

#define REG_DEVICE_EEE_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa00436d0) /*  */
#define     DEVICE_EEE_CONTROL_EXIT_TIME_SHIFT 0u
#define     DEVICE_EEE_CONTROL_EXIT_TIME_MASK  0xffffu
#define GET_DEVICE_EEE_CONTROL_EXIT_TIME(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_DEVICE_EEE_CONTROL_EXIT_TIME(__val__)  (((__val__) << 0u) & 0xffffu)
#define     DEVICE_EEE_CONTROL_MINIMUM_ASSERT_SHIFT 16u
#define     DEVICE_EEE_CONTROL_MINIMUM_ASSERT_MASK  0xffff0000u
#define GET_DEVICE_EEE_CONTROL_MINIMUM_ASSERT(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_DEVICE_EEE_CONTROL_MINIMUM_ASSERT(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref DEVICE_t.EeeControl. */
typedef register_container RegDEVICEEeeControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ExitTime, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MinimumAssert, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MinimumAssert, 16, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ExitTime, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EeeControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEeeControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.EeeControl. */
        r32.setName("EeeControl");
        bits.ExitTime.setBaseRegister(&r32);
        bits.ExitTime.setName("ExitTime");
        bits.MinimumAssert.setBaseRegister(&r32);
        bits.MinimumAssert.setName("MinimumAssert");
    }
    RegDEVICEEeeControl_t& operator=(const RegDEVICEEeeControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEeeControl_t;

#define REG_DEVICE_GLOBAL_MUTEX_REQUEST ((volatile APE_DEVICE_H_uint32_t*)0xa00436f0) /*  */
/** @brief Register definition for @ref DEVICE_t.GlobalMutexRequest. */
typedef register_container RegDEVICEGlobalMutexRequest_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GlobalMutexRequest"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEGlobalMutexRequest_t()
    {
        /** @brief constructor for @ref DEVICE_t.GlobalMutexRequest. */
        r32.setName("GlobalMutexRequest");
    }
    RegDEVICEGlobalMutexRequest_t& operator=(const RegDEVICEGlobalMutexRequest_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEGlobalMutexRequest_t;

#define REG_DEVICE_GLOBAL_MUTEX_GRANT ((volatile APE_DEVICE_H_uint32_t*)0xa00436f4) /*  */
/** @brief Register definition for @ref DEVICE_t.GlobalMutexGrant. */
typedef register_container RegDEVICEGlobalMutexGrant_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GlobalMutexGrant"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEGlobalMutexGrant_t()
    {
        /** @brief constructor for @ref DEVICE_t.GlobalMutexGrant. */
        r32.setName("GlobalMutexGrant");
    }
    RegDEVICEGlobalMutexGrant_t& operator=(const RegDEVICEGlobalMutexGrant_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEGlobalMutexGrant_t;

#define REG_DEVICE_MEMORY_ARBITER_MODE ((volatile APE_DEVICE_H_uint32_t*)0xa0044000) /*  */
#define     DEVICE_MEMORY_ARBITER_MODE_ENABLE_SHIFT 1u
#define     DEVICE_MEMORY_ARBITER_MODE_ENABLE_MASK  0x2u
#define GET_DEVICE_MEMORY_ARBITER_MODE_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_MEMORY_ARBITER_MODE_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)

/** @brief Register definition for @ref DEVICE_t.MemoryArbiterMode. */
typedef register_container RegDEVICEMemoryArbiterMode_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_0_0, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Enable, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_2, 2, 30)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_2, 2, 30)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Enable, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_0_0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MemoryArbiterMode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMemoryArbiterMode_t()
    {
        /** @brief constructor for @ref DEVICE_t.MemoryArbiterMode. */
        r32.setName("MemoryArbiterMode");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
    }
    RegDEVICEMemoryArbiterMode_t& operator=(const RegDEVICEMemoryArbiterMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMemoryArbiterMode_t;

#define REG_DEVICE_BUFFER_MANAGER_MODE ((volatile APE_DEVICE_H_uint32_t*)0xa0044400) /*  */
#define     DEVICE_BUFFER_MANAGER_MODE_ENABLE_SHIFT 1u
#define     DEVICE_BUFFER_MANAGER_MODE_ENABLE_MASK  0x2u
#define GET_DEVICE_BUFFER_MANAGER_MODE_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_BUFFER_MANAGER_MODE_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_BUFFER_MANAGER_MODE_ATTENTION_ENABLE_SHIFT 2u
#define     DEVICE_BUFFER_MANAGER_MODE_ATTENTION_ENABLE_MASK  0x4u
#define GET_DEVICE_BUFFER_MANAGER_MODE_ATTENTION_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_BUFFER_MANAGER_MODE_ATTENTION_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_BUFFER_MANAGER_MODE_RESET_RXMBUF_POINTER_SHIFT 5u
#define     DEVICE_BUFFER_MANAGER_MODE_RESET_RXMBUF_POINTER_MASK  0x20u
#define GET_DEVICE_BUFFER_MANAGER_MODE_RESET_RXMBUF_POINTER(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_BUFFER_MANAGER_MODE_RESET_RXMBUF_POINTER(__val__)  (((__val__) << 5u) & 0x20u)

/** @brief Register definition for @ref DEVICE_t.BufferManagerMode. */
typedef register_container RegDEVICEBufferManagerMode_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_0_0, 0, 1)
        /** @brief This bit controls whether the Buffer Manager is active or not. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Enable, 1, 1)
        /** @brief When this bit is set to 1, an internal attention is generated when an error occurs. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AttentionEnable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_4_3, 3, 2)
        /** @brief When this bit is set, it will cause the RXMBUF allocation and deallocation pointer to reset back to the RXMBUF base. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ResetRXMBUFPointer, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_6, 6, 26)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_6, 6, 26)
        /** @brief When this bit is set, it will cause the RXMBUF allocation and deallocation pointer to reset back to the RXMBUF base. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ResetRXMBUFPointer, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_4_3, 3, 2)
        /** @brief When this bit is set to 1, an internal attention is generated when an error occurs. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AttentionEnable, 2, 1)
        /** @brief This bit controls whether the Buffer Manager is active or not. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Enable, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_0_0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BufferManagerMode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEBufferManagerMode_t()
    {
        /** @brief constructor for @ref DEVICE_t.BufferManagerMode. */
        r32.setName("BufferManagerMode");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.AttentionEnable.setBaseRegister(&r32);
        bits.AttentionEnable.setName("AttentionEnable");
        bits.ResetRXMBUFPointer.setBaseRegister(&r32);
        bits.ResetRXMBUFPointer.setName("ResetRXMBUFPointer");
    }
    RegDEVICEBufferManagerMode_t& operator=(const RegDEVICEBufferManagerMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEBufferManagerMode_t;

#define REG_DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa0044910) /*  */
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_BD_RDMA_ENGINE_SHIFT 16u
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_BD_RDMA_ENGINE_MASK  0x30000u
#define GET_DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_BD_RDMA_ENGINE(__reg__)  (((__reg__) & 0x30000) >> 16u)
#define SET_DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_BD_RDMA_ENGINE(__val__)  (((__val__) << 16u) & 0x30000u)
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_BD_RDMA_ENGINE_128B 0x0u
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_BD_RDMA_ENGINE_256B 0x1u
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_BD_RDMA_ENGINE_512B 0x2u
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_BD_RDMA_ENGINE_4K 0x3u

#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_NONLSO_RDMA_ENGINE_SHIFT 18u
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_NONLSO_RDMA_ENGINE_MASK  0xc0000u
#define GET_DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_NONLSO_RDMA_ENGINE(__reg__)  (((__reg__) & 0xc0000) >> 18u)
#define SET_DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_NONLSO_RDMA_ENGINE(__val__)  (((__val__) << 18u) & 0xc0000u)
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_NONLSO_RDMA_ENGINE_128B 0x0u
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_NONLSO_RDMA_ENGINE_256B 0x1u
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_NONLSO_RDMA_ENGINE_512B 0x2u
#define     DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_NONLSO_RDMA_ENGINE_4K 0x3u


/** @brief Register definition for @ref DEVICE_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */
typedef register_container RegDEVICELsoNonlsoBdReadDmaCorruptionEnableControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIRequestBurstLengthforBDRDMAEngine, 16, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIRequestBurstLengthforNonLSORDMAEngine, 18, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_20, 20, 12)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_20, 20, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIRequestBurstLengthforNonLSORDMAEngine, 18, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIRequestBurstLengthforBDRDMAEngine, 16, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LsoNonlsoBdReadDmaCorruptionEnableControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICELsoNonlsoBdReadDmaCorruptionEnableControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */
        r32.setName("LsoNonlsoBdReadDmaCorruptionEnableControl");
        bits.PCIRequestBurstLengthforBDRDMAEngine.setBaseRegister(&r32);
        bits.PCIRequestBurstLengthforBDRDMAEngine.setName("PCIRequestBurstLengthforBDRDMAEngine");
        bits.PCIRequestBurstLengthforNonLSORDMAEngine.setBaseRegister(&r32);
        bits.PCIRequestBurstLengthforNonLSORDMAEngine.setName("PCIRequestBurstLengthforNonLSORDMAEngine");
    }
    RegDEVICELsoNonlsoBdReadDmaCorruptionEnableControl_t& operator=(const RegDEVICELsoNonlsoBdReadDmaCorruptionEnableControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICELsoNonlsoBdReadDmaCorruptionEnableControl_t;

#define REG_DEVICE_RX_RISC_MODE ((volatile APE_DEVICE_H_uint32_t*)0xa0045000) /*  */
#define     DEVICE_RX_RISC_MODE_RESET_SHIFT 0u
#define     DEVICE_RX_RISC_MODE_RESET_MASK  0x1u
#define GET_DEVICE_RX_RISC_MODE_RESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_RX_RISC_MODE_RESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_RX_RISC_MODE_SINGLE_STEP_SHIFT 1u
#define     DEVICE_RX_RISC_MODE_SINGLE_STEP_MASK  0x2u
#define GET_DEVICE_RX_RISC_MODE_SINGLE_STEP(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_RX_RISC_MODE_SINGLE_STEP(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_RX_RISC_MODE_PAGE_0_DATA_HALT_SHIFT 2u
#define     DEVICE_RX_RISC_MODE_PAGE_0_DATA_HALT_MASK  0x4u
#define GET_DEVICE_RX_RISC_MODE_PAGE_0_DATA_HALT(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_RX_RISC_MODE_PAGE_0_DATA_HALT(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_RX_RISC_MODE_PAGE_0_INSTR_HALT_SHIFT 3u
#define     DEVICE_RX_RISC_MODE_PAGE_0_INSTR_HALT_MASK  0x8u
#define GET_DEVICE_RX_RISC_MODE_PAGE_0_INSTR_HALT(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_DEVICE_RX_RISC_MODE_PAGE_0_INSTR_HALT(__val__)  (((__val__) << 3u) & 0x8u)
#define     DEVICE_RX_RISC_MODE_ENABLE_DATA_CACHE_SHIFT 5u
#define     DEVICE_RX_RISC_MODE_ENABLE_DATA_CACHE_MASK  0x20u
#define GET_DEVICE_RX_RISC_MODE_ENABLE_DATA_CACHE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_RX_RISC_MODE_ENABLE_DATA_CACHE(__val__)  (((__val__) << 5u) & 0x20u)
#define     DEVICE_RX_RISC_MODE_ROM_FAIL_SHIFT 6u
#define     DEVICE_RX_RISC_MODE_ROM_FAIL_MASK  0x40u
#define GET_DEVICE_RX_RISC_MODE_ROM_FAIL(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_DEVICE_RX_RISC_MODE_ROM_FAIL(__val__)  (((__val__) << 6u) & 0x40u)
#define     DEVICE_RX_RISC_MODE_ENABLE_WATCHDOG_SHIFT 7u
#define     DEVICE_RX_RISC_MODE_ENABLE_WATCHDOG_MASK  0x80u
#define GET_DEVICE_RX_RISC_MODE_ENABLE_WATCHDOG(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_RX_RISC_MODE_ENABLE_WATCHDOG(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_RX_RISC_MODE_ENABLE_INSTRUCTION_CACHE_SHIFT 8u
#define     DEVICE_RX_RISC_MODE_ENABLE_INSTRUCTION_CACHE_MASK  0x100u
#define GET_DEVICE_RX_RISC_MODE_ENABLE_INSTRUCTION_CACHE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_RX_RISC_MODE_ENABLE_INSTRUCTION_CACHE(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_RX_RISC_MODE_FLUSH_INSTRUCTION_CACHE_SHIFT 9u
#define     DEVICE_RX_RISC_MODE_FLUSH_INSTRUCTION_CACHE_MASK  0x200u
#define GET_DEVICE_RX_RISC_MODE_FLUSH_INSTRUCTION_CACHE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_RX_RISC_MODE_FLUSH_INSTRUCTION_CACHE(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_RX_RISC_MODE_HALT_SHIFT 10u
#define     DEVICE_RX_RISC_MODE_HALT_MASK  0x400u
#define GET_DEVICE_RX_RISC_MODE_HALT(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_DEVICE_RX_RISC_MODE_HALT(__val__)  (((__val__) << 10u) & 0x400u)
#define     DEVICE_RX_RISC_MODE_INVALID_DATA_ACCESS_HALT_SHIFT 11u
#define     DEVICE_RX_RISC_MODE_INVALID_DATA_ACCESS_HALT_MASK  0x800u
#define GET_DEVICE_RX_RISC_MODE_INVALID_DATA_ACCESS_HALT(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_DEVICE_RX_RISC_MODE_INVALID_DATA_ACCESS_HALT(__val__)  (((__val__) << 11u) & 0x800u)
#define     DEVICE_RX_RISC_MODE_INVALID_INSTRUCTION_ACCESS_HALT_SHIFT 12u
#define     DEVICE_RX_RISC_MODE_INVALID_INSTRUCTION_ACCESS_HALT_MASK  0x1000u
#define GET_DEVICE_RX_RISC_MODE_INVALID_INSTRUCTION_ACCESS_HALT(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_DEVICE_RX_RISC_MODE_INVALID_INSTRUCTION_ACCESS_HALT(__val__)  (((__val__) << 12u) & 0x1000u)
#define     DEVICE_RX_RISC_MODE_ENABLE_MEMORY_ADDRESS_TRAP_HALT_SHIFT 13u
#define     DEVICE_RX_RISC_MODE_ENABLE_MEMORY_ADDRESS_TRAP_HALT_MASK  0x2000u
#define GET_DEVICE_RX_RISC_MODE_ENABLE_MEMORY_ADDRESS_TRAP_HALT(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_DEVICE_RX_RISC_MODE_ENABLE_MEMORY_ADDRESS_TRAP_HALT(__val__)  (((__val__) << 13u) & 0x2000u)
#define     DEVICE_RX_RISC_MODE_ENABLE_REGISTER_ADDRESS_TRAP_HALT_SHIFT 14u
#define     DEVICE_RX_RISC_MODE_ENABLE_REGISTER_ADDRESS_TRAP_HALT_MASK  0x4000u
#define GET_DEVICE_RX_RISC_MODE_ENABLE_REGISTER_ADDRESS_TRAP_HALT(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_DEVICE_RX_RISC_MODE_ENABLE_REGISTER_ADDRESS_TRAP_HALT(__val__)  (((__val__) << 14u) & 0x4000u)

/** @brief Register definition for @ref DEVICE_t.RxRiscMode. */
typedef register_container RegDEVICERxRiscMode_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Self-clearing bit which resets only the RX RISC. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Reset, 0, 1)
        /** @brief Advances the RX RISC's PC for one cycle. If halting condition still exists, the RX RISC will again halt; otherwise, it will resume normal operation. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SingleStep, 1, 1)
        /** @brief When set, data references to the first 256 bytes of SRAM force the RX RISC to halt and cause bit 3 in the RX RISC state register to be latched. Cleared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Page0DataHalt, 2, 1)
        /** @brief When set, instruction references to the first 256 bytes of SRAM force the RX RISC to halt and cause bit 4 in the RX RISC state register to be latched. Cleared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Page0InstrHalt, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_4_4, 4, 1)
        /** @brief Enables the data cache. Cleared on reset. Note: Firmware developers should take care to clear this bit before polling internal SRAM memory locations, because the RX RISC processor uses a two-element LRU caching algorithm, which is not affected by writes from the PCI interface. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableDataCache, 5, 1)
        /** @brief Asserted on reset. Cleared by ROM code after it successfully loads code from NVRAM. Afterwards, this bit can be used by software for any purpose. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ROMFail, 6, 1)
        /** @brief Enables watchdog interrupt state machine. Used in conjunction with Watchdog Clear register, Watchdog Saved PC register and Watchdog Vector register. Cleared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableWatchdog, 7, 1)
        /** @brief Enables prefetch logic within the instruction cache. When disabled only a single cache line is read on a cache miss. Cleared on reset. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableInstructionCache, 8, 1)
        /** @brief Self-clearing bit which forces the instruction cache to flush. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FlushInstructionCache, 9, 1)
        /** @brief Set by TX RISC or the host to halt the RX RISC. Cleared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Halt, 10, 1)
        /** @brief When set, the condition that causes RX RISC state bit 5 to be set, also halts the RX RISC. Set by reset. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidDataAccessHalt, 11, 1)
        /** @brief When set, the condition that causes RX RISC state bit 6 to be set, also halts the RX RISC. Set by reset. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidInstructionAccessHalt, 12, 1)
        /** @brief When set, if the MA raises the trap signal to this processor, it will halt. CLeared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableMemoryAddressTrapHalt, 13, 1)
        /** @brief When set, if the GRC raises the trap signal to this processor, it will halt. CLeared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableRegisterAddressTrapHalt, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_15, 15, 17)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_15, 15, 17)
        /** @brief When set, if the GRC raises the trap signal to this processor, it will halt. CLeared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableRegisterAddressTrapHalt, 14, 1)
        /** @brief When set, if the MA raises the trap signal to this processor, it will halt. CLeared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableMemoryAddressTrapHalt, 13, 1)
        /** @brief When set, the condition that causes RX RISC state bit 6 to be set, also halts the RX RISC. Set by reset. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidInstructionAccessHalt, 12, 1)
        /** @brief When set, the condition that causes RX RISC state bit 5 to be set, also halts the RX RISC. Set by reset. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidDataAccessHalt, 11, 1)
        /** @brief Set by TX RISC or the host to halt the RX RISC. Cleared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Halt, 10, 1)
        /** @brief Self-clearing bit which forces the instruction cache to flush. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, FlushInstructionCache, 9, 1)
        /** @brief Enables prefetch logic within the instruction cache. When disabled only a single cache line is read on a cache miss. Cleared on reset. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableInstructionCache, 8, 1)
        /** @brief Enables watchdog interrupt state machine. Used in conjunction with Watchdog Clear register, Watchdog Saved PC register and Watchdog Vector register. Cleared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableWatchdog, 7, 1)
        /** @brief Asserted on reset. Cleared by ROM code after it successfully loads code from NVRAM. Afterwards, this bit can be used by software for any purpose. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ROMFail, 6, 1)
        /** @brief Enables the data cache. Cleared on reset. Note: Firmware developers should take care to clear this bit before polling internal SRAM memory locations, because the RX RISC processor uses a two-element LRU caching algorithm, which is not affected by writes from the PCI interface. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, EnableDataCache, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_4_4, 4, 1)
        /** @brief When set, instruction references to the first 256 bytes of SRAM force the RX RISC to halt and cause bit 4 in the RX RISC state register to be latched. Cleared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Page0InstrHalt, 3, 1)
        /** @brief When set, data references to the first 256 bytes of SRAM force the RX RISC to halt and cause bit 3 in the RX RISC state register to be latched. Cleared on reset and Watchdog interrupt. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Page0DataHalt, 2, 1)
        /** @brief Advances the RX RISC's PC for one cycle. If halting condition still exists, the RX RISC will again halt; otherwise, it will resume normal operation. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SingleStep, 1, 1)
        /** @brief Self-clearing bit which resets only the RX RISC. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Reset, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscMode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscMode_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscMode. */
        r32.setName("RxRiscMode");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.SingleStep.setBaseRegister(&r32);
        bits.SingleStep.setName("SingleStep");
        bits.Page0DataHalt.setBaseRegister(&r32);
        bits.Page0DataHalt.setName("Page0DataHalt");
        bits.Page0InstrHalt.setBaseRegister(&r32);
        bits.Page0InstrHalt.setName("Page0InstrHalt");
        bits.EnableDataCache.setBaseRegister(&r32);
        bits.EnableDataCache.setName("EnableDataCache");
        bits.ROMFail.setBaseRegister(&r32);
        bits.ROMFail.setName("ROMFail");
        bits.EnableWatchdog.setBaseRegister(&r32);
        bits.EnableWatchdog.setName("EnableWatchdog");
        bits.EnableInstructionCache.setBaseRegister(&r32);
        bits.EnableInstructionCache.setName("EnableInstructionCache");
        bits.FlushInstructionCache.setBaseRegister(&r32);
        bits.FlushInstructionCache.setName("FlushInstructionCache");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.InvalidDataAccessHalt.setBaseRegister(&r32);
        bits.InvalidDataAccessHalt.setName("InvalidDataAccessHalt");
        bits.InvalidInstructionAccessHalt.setBaseRegister(&r32);
        bits.InvalidInstructionAccessHalt.setName("InvalidInstructionAccessHalt");
        bits.EnableMemoryAddressTrapHalt.setBaseRegister(&r32);
        bits.EnableMemoryAddressTrapHalt.setName("EnableMemoryAddressTrapHalt");
        bits.EnableRegisterAddressTrapHalt.setBaseRegister(&r32);
        bits.EnableRegisterAddressTrapHalt.setName("EnableRegisterAddressTrapHalt");
    }
    RegDEVICERxRiscMode_t& operator=(const RegDEVICERxRiscMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscMode_t;

#define REG_DEVICE_RX_RISC_STATUS ((volatile APE_DEVICE_H_uint32_t*)0xa0045004) /*  */
#define     DEVICE_RX_RISC_STATUS_HARDWARE_BREAKPOINT_SHIFT 0u
#define     DEVICE_RX_RISC_STATUS_HARDWARE_BREAKPOINT_MASK  0x1u
#define GET_DEVICE_RX_RISC_STATUS_HARDWARE_BREAKPOINT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_DEVICE_RX_RISC_STATUS_HARDWARE_BREAKPOINT(__val__)  (((__val__) << 0u) & 0x1u)
#define     DEVICE_RX_RISC_STATUS_HALT_INSTRUCTION_EXECUTED_SHIFT 1u
#define     DEVICE_RX_RISC_STATUS_HALT_INSTRUCTION_EXECUTED_MASK  0x2u
#define GET_DEVICE_RX_RISC_STATUS_HALT_INSTRUCTION_EXECUTED(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_DEVICE_RX_RISC_STATUS_HALT_INSTRUCTION_EXECUTED(__val__)  (((__val__) << 1u) & 0x2u)
#define     DEVICE_RX_RISC_STATUS_INVALID_INSTRUCTION_SHIFT 2u
#define     DEVICE_RX_RISC_STATUS_INVALID_INSTRUCTION_MASK  0x4u
#define GET_DEVICE_RX_RISC_STATUS_INVALID_INSTRUCTION(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_DEVICE_RX_RISC_STATUS_INVALID_INSTRUCTION(__val__)  (((__val__) << 2u) & 0x4u)
#define     DEVICE_RX_RISC_STATUS_PAGE_0_DATA_REFEENCE_SHIFT 3u
#define     DEVICE_RX_RISC_STATUS_PAGE_0_DATA_REFEENCE_MASK  0x8u
#define GET_DEVICE_RX_RISC_STATUS_PAGE_0_DATA_REFEENCE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_DEVICE_RX_RISC_STATUS_PAGE_0_DATA_REFEENCE(__val__)  (((__val__) << 3u) & 0x8u)
#define     DEVICE_RX_RISC_STATUS_PAGE_0_INSTRUCTION_REFERENCE_SHIFT 4u
#define     DEVICE_RX_RISC_STATUS_PAGE_0_INSTRUCTION_REFERENCE_MASK  0x10u
#define GET_DEVICE_RX_RISC_STATUS_PAGE_0_INSTRUCTION_REFERENCE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_DEVICE_RX_RISC_STATUS_PAGE_0_INSTRUCTION_REFERENCE(__val__)  (((__val__) << 4u) & 0x10u)
#define     DEVICE_RX_RISC_STATUS_INVALID_DATA_ACCESS_SHIFT 5u
#define     DEVICE_RX_RISC_STATUS_INVALID_DATA_ACCESS_MASK  0x20u
#define GET_DEVICE_RX_RISC_STATUS_INVALID_DATA_ACCESS(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_DEVICE_RX_RISC_STATUS_INVALID_DATA_ACCESS(__val__)  (((__val__) << 5u) & 0x20u)
#define     DEVICE_RX_RISC_STATUS_INVALID_INSTRUCTION_FETCH_SHIFT 6u
#define     DEVICE_RX_RISC_STATUS_INVALID_INSTRUCTION_FETCH_MASK  0x40u
#define GET_DEVICE_RX_RISC_STATUS_INVALID_INSTRUCTION_FETCH(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_DEVICE_RX_RISC_STATUS_INVALID_INSTRUCTION_FETCH(__val__)  (((__val__) << 6u) & 0x40u)
#define     DEVICE_RX_RISC_STATUS_BAD_MEMORY_ALIGNMENT_SHIFT 7u
#define     DEVICE_RX_RISC_STATUS_BAD_MEMORY_ALIGNMENT_MASK  0x80u
#define GET_DEVICE_RX_RISC_STATUS_BAD_MEMORY_ALIGNMENT(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_DEVICE_RX_RISC_STATUS_BAD_MEMORY_ALIGNMENT(__val__)  (((__val__) << 7u) & 0x80u)
#define     DEVICE_RX_RISC_STATUS_MEMORY_ADDRESS_TRAP_SHIFT 8u
#define     DEVICE_RX_RISC_STATUS_MEMORY_ADDRESS_TRAP_MASK  0x100u
#define GET_DEVICE_RX_RISC_STATUS_MEMORY_ADDRESS_TRAP(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_RX_RISC_STATUS_MEMORY_ADDRESS_TRAP(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_RX_RISC_STATUS_REGISTER_ADDRESS_TRAP_SHIFT 9u
#define     DEVICE_RX_RISC_STATUS_REGISTER_ADDRESS_TRAP_MASK  0x200u
#define GET_DEVICE_RX_RISC_STATUS_REGISTER_ADDRESS_TRAP(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_RX_RISC_STATUS_REGISTER_ADDRESS_TRAP(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_RX_RISC_STATUS_HALTED_SHIFT 10u
#define     DEVICE_RX_RISC_STATUS_HALTED_MASK  0x400u
#define GET_DEVICE_RX_RISC_STATUS_HALTED(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_DEVICE_RX_RISC_STATUS_HALTED(__val__)  (((__val__) << 10u) & 0x400u)
#define     DEVICE_RX_RISC_STATUS_UNKNOWN_SHIFT 11u
#define     DEVICE_RX_RISC_STATUS_UNKNOWN_MASK  0x800u
#define GET_DEVICE_RX_RISC_STATUS_UNKNOWN(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_DEVICE_RX_RISC_STATUS_UNKNOWN(__val__)  (((__val__) << 11u) & 0x800u)
#define     DEVICE_RX_RISC_STATUS_DATA_ACCESS_STALL_SHIFT 14u
#define     DEVICE_RX_RISC_STATUS_DATA_ACCESS_STALL_MASK  0x4000u
#define GET_DEVICE_RX_RISC_STATUS_DATA_ACCESS_STALL(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_DEVICE_RX_RISC_STATUS_DATA_ACCESS_STALL(__val__)  (((__val__) << 14u) & 0x4000u)
#define     DEVICE_RX_RISC_STATUS_INSTRUCTION_FETCH_STALL_SHIFT 15u
#define     DEVICE_RX_RISC_STATUS_INSTRUCTION_FETCH_STALL_MASK  0x8000u
#define GET_DEVICE_RX_RISC_STATUS_INSTRUCTION_FETCH_STALL(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_DEVICE_RX_RISC_STATUS_INSTRUCTION_FETCH_STALL(__val__)  (((__val__) << 15u) & 0x8000u)
#define     DEVICE_RX_RISC_STATUS_BLOCKING_READ_SHIFT 31u
#define     DEVICE_RX_RISC_STATUS_BLOCKING_READ_MASK  0x80000000u
#define GET_DEVICE_RX_RISC_STATUS_BLOCKING_READ(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_DEVICE_RX_RISC_STATUS_BLOCKING_READ(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref DEVICE_t.RxRiscStatus. */
typedef register_container RegDEVICERxRiscStatus_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief When enabled in mode register, indicates hardware breakpoint has been reached. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, HardwareBreakpoint, 0, 1)
        /** @brief When enabled in mode register, indicates hardware breakpoint has been reached. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, HaltInstructionExecuted, 1, 1)
        /** @brief Invalid instruction fetched. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidInstruction, 2, 1)
        /** @brief When enabled in mode register, indicates data reference within lower 256 bytes of SRAM. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Page0DataRefeence, 3, 1)
        /** @brief When enabled in mode register, indicates the address in the PC is within the lower 256 bytes of SRAM. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Page0InstructionReference, 4, 1)
        /** @brief Data reference to illegal location. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidDataAccess, 5, 1)
        /** @brief Program Counter (PC) is set to invalid location in processor address space. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidInstructionFetch, 6, 1)
        /** @brief Load or Store instruction was executed with the least significant two address bits not valid for the width of the operation (e.g., Load word or Load Half-word from an odd byte address). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BadMemoryAlignment, 7, 1)
        /** @brief A signal was received from the Memory Arbiter indicating that some BCM5700 block, possibly this processor, accessed a memory location that triggered a software trap. The MA registers are used to configure memory address trapping. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MemoryAddressTrap, 8, 1)
        /** @brief A signal was received from the Global Resources block indicating that this processor accessed a register location that triggered a software trap. The GRC registers are used to configure register address trapping. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RegisterAddressTrap, 9, 1)
        /** @brief The RX RISC was explicitly halted via bit 10 in the RX RISC Mode register. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Halted, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Unknown, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_13_12, 12, 2)
        /** @brief The processor is currently stalled due to a data access. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataAccessStall, 14, 1)
        /** @brief The processor is currently stalled due to an instruction fetch. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InstructionFetchStall, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_30_16, 16, 15)
        /** @brief A blocking data cache miss occurred, causing the RX RISC to stall while data is fetched from external (to the RX RISC) memory. This is intended as a debugging tool. No state is saved other than the fact that the miss occurred. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BlockingRead, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief A blocking data cache miss occurred, causing the RX RISC to stall while data is fetched from external (to the RX RISC) memory. This is intended as a debugging tool. No state is saved other than the fact that the miss occurred. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BlockingRead, 31, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_30_16, 16, 15)
        /** @brief The processor is currently stalled due to an instruction fetch. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InstructionFetchStall, 15, 1)
        /** @brief The processor is currently stalled due to a data access. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataAccessStall, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_13_12, 12, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Unknown, 11, 1)
        /** @brief The RX RISC was explicitly halted via bit 10 in the RX RISC Mode register. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Halted, 10, 1)
        /** @brief A signal was received from the Global Resources block indicating that this processor accessed a register location that triggered a software trap. The GRC registers are used to configure register address trapping. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RegisterAddressTrap, 9, 1)
        /** @brief A signal was received from the Memory Arbiter indicating that some BCM5700 block, possibly this processor, accessed a memory location that triggered a software trap. The MA registers are used to configure memory address trapping. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MemoryAddressTrap, 8, 1)
        /** @brief Load or Store instruction was executed with the least significant two address bits not valid for the width of the operation (e.g., Load word or Load Half-word from an odd byte address). */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BadMemoryAlignment, 7, 1)
        /** @brief Program Counter (PC) is set to invalid location in processor address space. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidInstructionFetch, 6, 1)
        /** @brief Data reference to illegal location. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidDataAccess, 5, 1)
        /** @brief When enabled in mode register, indicates the address in the PC is within the lower 256 bytes of SRAM. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Page0InstructionReference, 4, 1)
        /** @brief When enabled in mode register, indicates data reference within lower 256 bytes of SRAM. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Page0DataRefeence, 3, 1)
        /** @brief Invalid instruction fetched. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, InvalidInstruction, 2, 1)
        /** @brief When enabled in mode register, indicates hardware breakpoint has been reached. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, HaltInstructionExecuted, 1, 1)
        /** @brief When enabled in mode register, indicates hardware breakpoint has been reached. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, HardwareBreakpoint, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscStatus_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscStatus. */
        r32.setName("RxRiscStatus");
        bits.HardwareBreakpoint.setBaseRegister(&r32);
        bits.HardwareBreakpoint.setName("HardwareBreakpoint");
        bits.HaltInstructionExecuted.setBaseRegister(&r32);
        bits.HaltInstructionExecuted.setName("HaltInstructionExecuted");
        bits.InvalidInstruction.setBaseRegister(&r32);
        bits.InvalidInstruction.setName("InvalidInstruction");
        bits.Page0DataRefeence.setBaseRegister(&r32);
        bits.Page0DataRefeence.setName("Page0DataRefeence");
        bits.Page0InstructionReference.setBaseRegister(&r32);
        bits.Page0InstructionReference.setName("Page0InstructionReference");
        bits.InvalidDataAccess.setBaseRegister(&r32);
        bits.InvalidDataAccess.setName("InvalidDataAccess");
        bits.InvalidInstructionFetch.setBaseRegister(&r32);
        bits.InvalidInstructionFetch.setName("InvalidInstructionFetch");
        bits.BadMemoryAlignment.setBaseRegister(&r32);
        bits.BadMemoryAlignment.setName("BadMemoryAlignment");
        bits.MemoryAddressTrap.setBaseRegister(&r32);
        bits.MemoryAddressTrap.setName("MemoryAddressTrap");
        bits.RegisterAddressTrap.setBaseRegister(&r32);
        bits.RegisterAddressTrap.setName("RegisterAddressTrap");
        bits.Halted.setBaseRegister(&r32);
        bits.Halted.setName("Halted");
        bits.Unknown.setBaseRegister(&r32);
        bits.Unknown.setName("Unknown");
        bits.DataAccessStall.setBaseRegister(&r32);
        bits.DataAccessStall.setName("DataAccessStall");
        bits.InstructionFetchStall.setBaseRegister(&r32);
        bits.InstructionFetchStall.setName("InstructionFetchStall");
        bits.BlockingRead.setBaseRegister(&r32);
        bits.BlockingRead.setName("BlockingRead");
    }
    RegDEVICERxRiscStatus_t& operator=(const RegDEVICERxRiscStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscStatus_t;

#define REG_DEVICE_RX_RISC_PROGRAM_COUNTER ((volatile APE_DEVICE_H_uint32_t*)0xa004501c) /* The program counter register can be used to read or write the current Program Counter of the each CPU. Reads can occur at any time, however writes can only be performed when the CPU is halted. Writes will also clear any pending instruction in the decode stage of the pipeline. Bits 31-2 are implemented. 1s written to bits 1-0 are ignored. */
/** @brief Register definition for @ref DEVICE_t.RxRiscProgramCounter. */
typedef register_container RegDEVICERxRiscProgramCounter_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscProgramCounter"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscProgramCounter_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscProgramCounter. */
        r32.setName("RxRiscProgramCounter");
    }
    RegDEVICERxRiscProgramCounter_t& operator=(const RegDEVICERxRiscProgramCounter_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscProgramCounter_t;

#define REG_DEVICE_RX_RISC_CURRENT_INSTRUCTION ((volatile APE_DEVICE_H_uint32_t*)0xa0045020) /* This undocumented register contains the current word located at the program counter address loaded in  */
/** @brief Register definition for @ref DEVICE_t.RxRiscCurrentInstruction. */
typedef register_container RegDEVICERxRiscCurrentInstruction_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscCurrentInstruction"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscCurrentInstruction_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscCurrentInstruction. */
        r32.setName("RxRiscCurrentInstruction");
    }
    RegDEVICERxRiscCurrentInstruction_t& operator=(const RegDEVICERxRiscCurrentInstruction_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscCurrentInstruction_t;

#define REG_DEVICE_RX_RISC_HARDWARE_BREAKPOINT ((volatile APE_DEVICE_H_uint32_t*)0xa0045034) /* This register is used to set a hardware breakpoint based on the RISC's program counter (PC). If the PC equals the value in this register, and the hardware breakpoint is enabled, the RISC is halted and the appropriate stopping condition is indicated in the RISC State Register. To enable the hardware breakpoint, simply write the byte address of the instruction to break on and clear the Disable Hardware Breakpoint bit. */
/** @brief Register definition for @ref DEVICE_t.RxRiscHardwareBreakpoint. */
typedef register_container RegDEVICERxRiscHardwareBreakpoint_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscHardwareBreakpoint"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscHardwareBreakpoint_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscHardwareBreakpoint. */
        r32.setName("RxRiscHardwareBreakpoint");
    }
    RegDEVICERxRiscHardwareBreakpoint_t& operator=(const RegDEVICERxRiscHardwareBreakpoint_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscHardwareBreakpoint_t;

#define REG_DEVICE_RX_RISC_REGISTER_0 ((volatile APE_DEVICE_H_uint32_t*)0xa0045200) /* $zero (R0) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister0. */
typedef register_container RegDEVICERxRiscRegister0_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister0_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister0. */
        r32.setName("RxRiscRegister0");
    }
    RegDEVICERxRiscRegister0_t& operator=(const RegDEVICERxRiscRegister0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister0_t;

#define REG_DEVICE_RX_RISC_REGISTER_1 ((volatile APE_DEVICE_H_uint32_t*)0xa0045204) /* $at (R1) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister1. */
typedef register_container RegDEVICERxRiscRegister1_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister1_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister1. */
        r32.setName("RxRiscRegister1");
    }
    RegDEVICERxRiscRegister1_t& operator=(const RegDEVICERxRiscRegister1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister1_t;

#define REG_DEVICE_RX_RISC_REGISTER_2 ((volatile APE_DEVICE_H_uint32_t*)0xa0045208) /* $v0 (R2) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister2. */
typedef register_container RegDEVICERxRiscRegister2_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister2_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister2. */
        r32.setName("RxRiscRegister2");
    }
    RegDEVICERxRiscRegister2_t& operator=(const RegDEVICERxRiscRegister2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister2_t;

#define REG_DEVICE_RX_RISC_REGISTER_3 ((volatile APE_DEVICE_H_uint32_t*)0xa004520c) /* $v1 (R3) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister3. */
typedef register_container RegDEVICERxRiscRegister3_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister3_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister3. */
        r32.setName("RxRiscRegister3");
    }
    RegDEVICERxRiscRegister3_t& operator=(const RegDEVICERxRiscRegister3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister3_t;

#define REG_DEVICE_RX_RISC_REGISTER_4 ((volatile APE_DEVICE_H_uint32_t*)0xa0045210) /* $a0 (R4) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister4. */
typedef register_container RegDEVICERxRiscRegister4_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister4"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister4_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister4. */
        r32.setName("RxRiscRegister4");
    }
    RegDEVICERxRiscRegister4_t& operator=(const RegDEVICERxRiscRegister4_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister4_t;

#define REG_DEVICE_RX_RISC_REGISTER_5 ((volatile APE_DEVICE_H_uint32_t*)0xa0045214) /* $a1 (R5) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister5. */
typedef register_container RegDEVICERxRiscRegister5_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister5"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister5_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister5. */
        r32.setName("RxRiscRegister5");
    }
    RegDEVICERxRiscRegister5_t& operator=(const RegDEVICERxRiscRegister5_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister5_t;

#define REG_DEVICE_RX_RISC_REGISTER_6 ((volatile APE_DEVICE_H_uint32_t*)0xa0045218) /* $a2 (R6) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister6. */
typedef register_container RegDEVICERxRiscRegister6_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister6"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister6_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister6. */
        r32.setName("RxRiscRegister6");
    }
    RegDEVICERxRiscRegister6_t& operator=(const RegDEVICERxRiscRegister6_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister6_t;

#define REG_DEVICE_RX_RISC_REGISTER_7 ((volatile APE_DEVICE_H_uint32_t*)0xa004521c) /* $a3 (R7) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister7. */
typedef register_container RegDEVICERxRiscRegister7_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister7"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister7_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister7. */
        r32.setName("RxRiscRegister7");
    }
    RegDEVICERxRiscRegister7_t& operator=(const RegDEVICERxRiscRegister7_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister7_t;

#define REG_DEVICE_RX_RISC_REGISTER_8 ((volatile APE_DEVICE_H_uint32_t*)0xa0045220) /* $t0 (R8) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister8. */
typedef register_container RegDEVICERxRiscRegister8_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister8"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister8_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister8. */
        r32.setName("RxRiscRegister8");
    }
    RegDEVICERxRiscRegister8_t& operator=(const RegDEVICERxRiscRegister8_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister8_t;

#define REG_DEVICE_RX_RISC_REGISTER_9 ((volatile APE_DEVICE_H_uint32_t*)0xa0045224) /* $t1 (R9) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister9. */
typedef register_container RegDEVICERxRiscRegister9_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister9"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister9_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister9. */
        r32.setName("RxRiscRegister9");
    }
    RegDEVICERxRiscRegister9_t& operator=(const RegDEVICERxRiscRegister9_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister9_t;

#define REG_DEVICE_RX_RISC_REGISTER_10 ((volatile APE_DEVICE_H_uint32_t*)0xa0045228) /* $t2 (R10) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister10. */
typedef register_container RegDEVICERxRiscRegister10_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister10"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister10_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister10. */
        r32.setName("RxRiscRegister10");
    }
    RegDEVICERxRiscRegister10_t& operator=(const RegDEVICERxRiscRegister10_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister10_t;

#define REG_DEVICE_RX_RISC_REGISTER_11 ((volatile APE_DEVICE_H_uint32_t*)0xa004522c) /* $t3 (R11) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister11. */
typedef register_container RegDEVICERxRiscRegister11_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister11"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister11_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister11. */
        r32.setName("RxRiscRegister11");
    }
    RegDEVICERxRiscRegister11_t& operator=(const RegDEVICERxRiscRegister11_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister11_t;

#define REG_DEVICE_RX_RISC_REGISTER_12 ((volatile APE_DEVICE_H_uint32_t*)0xa0045230) /* $t4 (R12) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister12. */
typedef register_container RegDEVICERxRiscRegister12_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister12"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister12_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister12. */
        r32.setName("RxRiscRegister12");
    }
    RegDEVICERxRiscRegister12_t& operator=(const RegDEVICERxRiscRegister12_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister12_t;

#define REG_DEVICE_RX_RISC_REGISTER_13 ((volatile APE_DEVICE_H_uint32_t*)0xa0045234) /* $t5 (R13) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister13. */
typedef register_container RegDEVICERxRiscRegister13_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister13"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister13_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister13. */
        r32.setName("RxRiscRegister13");
    }
    RegDEVICERxRiscRegister13_t& operator=(const RegDEVICERxRiscRegister13_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister13_t;

#define REG_DEVICE_RX_RISC_REGISTER_14 ((volatile APE_DEVICE_H_uint32_t*)0xa0045238) /* $t6 (R14) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister14. */
typedef register_container RegDEVICERxRiscRegister14_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister14"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister14_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister14. */
        r32.setName("RxRiscRegister14");
    }
    RegDEVICERxRiscRegister14_t& operator=(const RegDEVICERxRiscRegister14_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister14_t;

#define REG_DEVICE_RX_RISC_REGISTER_15 ((volatile APE_DEVICE_H_uint32_t*)0xa004523c) /* $t7 (R15) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister15. */
typedef register_container RegDEVICERxRiscRegister15_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister15"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister15_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister15. */
        r32.setName("RxRiscRegister15");
    }
    RegDEVICERxRiscRegister15_t& operator=(const RegDEVICERxRiscRegister15_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister15_t;

#define REG_DEVICE_RX_RISC_REGISTER_16 ((volatile APE_DEVICE_H_uint32_t*)0xa0045240) /* $s0 (R16) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister16. */
typedef register_container RegDEVICERxRiscRegister16_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister16"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister16_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister16. */
        r32.setName("RxRiscRegister16");
    }
    RegDEVICERxRiscRegister16_t& operator=(const RegDEVICERxRiscRegister16_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister16_t;

#define REG_DEVICE_RX_RISC_REGISTER_17 ((volatile APE_DEVICE_H_uint32_t*)0xa0045244) /* $s1 (R17) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister17. */
typedef register_container RegDEVICERxRiscRegister17_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister17"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister17_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister17. */
        r32.setName("RxRiscRegister17");
    }
    RegDEVICERxRiscRegister17_t& operator=(const RegDEVICERxRiscRegister17_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister17_t;

#define REG_DEVICE_RX_RISC_REGISTER_18 ((volatile APE_DEVICE_H_uint32_t*)0xa0045248) /* $s2 (R18) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister18. */
typedef register_container RegDEVICERxRiscRegister18_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister18"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister18_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister18. */
        r32.setName("RxRiscRegister18");
    }
    RegDEVICERxRiscRegister18_t& operator=(const RegDEVICERxRiscRegister18_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister18_t;

#define REG_DEVICE_RX_RISC_REGISTER_19 ((volatile APE_DEVICE_H_uint32_t*)0xa004524c) /* $s3 (R19) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister19. */
typedef register_container RegDEVICERxRiscRegister19_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister19"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister19_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister19. */
        r32.setName("RxRiscRegister19");
    }
    RegDEVICERxRiscRegister19_t& operator=(const RegDEVICERxRiscRegister19_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister19_t;

#define REG_DEVICE_RX_RISC_REGISTER_20 ((volatile APE_DEVICE_H_uint32_t*)0xa0045250) /* $s4 (R20) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister20. */
typedef register_container RegDEVICERxRiscRegister20_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister20"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister20_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister20. */
        r32.setName("RxRiscRegister20");
    }
    RegDEVICERxRiscRegister20_t& operator=(const RegDEVICERxRiscRegister20_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister20_t;

#define REG_DEVICE_RX_RISC_REGISTER_21 ((volatile APE_DEVICE_H_uint32_t*)0xa0045254) /* $s5 (R21) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister21. */
typedef register_container RegDEVICERxRiscRegister21_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister21"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister21_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister21. */
        r32.setName("RxRiscRegister21");
    }
    RegDEVICERxRiscRegister21_t& operator=(const RegDEVICERxRiscRegister21_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister21_t;

#define REG_DEVICE_RX_RISC_REGISTER_22 ((volatile APE_DEVICE_H_uint32_t*)0xa0045258) /* $s6 (R22) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister22. */
typedef register_container RegDEVICERxRiscRegister22_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister22"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister22_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister22. */
        r32.setName("RxRiscRegister22");
    }
    RegDEVICERxRiscRegister22_t& operator=(const RegDEVICERxRiscRegister22_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister22_t;

#define REG_DEVICE_RX_RISC_REGISTER_23 ((volatile APE_DEVICE_H_uint32_t*)0xa004525c) /* $s7 (R23) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister23. */
typedef register_container RegDEVICERxRiscRegister23_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister23"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister23_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister23. */
        r32.setName("RxRiscRegister23");
    }
    RegDEVICERxRiscRegister23_t& operator=(const RegDEVICERxRiscRegister23_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister23_t;

#define REG_DEVICE_RX_RISC_REGISTER_24 ((volatile APE_DEVICE_H_uint32_t*)0xa0045260) /* $t8 (R24) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister24. */
typedef register_container RegDEVICERxRiscRegister24_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister24"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister24_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister24. */
        r32.setName("RxRiscRegister24");
    }
    RegDEVICERxRiscRegister24_t& operator=(const RegDEVICERxRiscRegister24_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister24_t;

#define REG_DEVICE_RX_RISC_REGISTER_25 ((volatile APE_DEVICE_H_uint32_t*)0xa0045264) /* $t9 (R25) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister25. */
typedef register_container RegDEVICERxRiscRegister25_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister25"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister25_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister25. */
        r32.setName("RxRiscRegister25");
    }
    RegDEVICERxRiscRegister25_t& operator=(const RegDEVICERxRiscRegister25_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister25_t;

#define REG_DEVICE_RX_RISC_REGISTER_26 ((volatile APE_DEVICE_H_uint32_t*)0xa0045268) /* $k0 (R26) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister26. */
typedef register_container RegDEVICERxRiscRegister26_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister26"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister26_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister26. */
        r32.setName("RxRiscRegister26");
    }
    RegDEVICERxRiscRegister26_t& operator=(const RegDEVICERxRiscRegister26_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister26_t;

#define REG_DEVICE_RX_RISC_REGISTER_27 ((volatile APE_DEVICE_H_uint32_t*)0xa004526c) /* $k1 (R27) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister27. */
typedef register_container RegDEVICERxRiscRegister27_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister27"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister27_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister27. */
        r32.setName("RxRiscRegister27");
    }
    RegDEVICERxRiscRegister27_t& operator=(const RegDEVICERxRiscRegister27_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister27_t;

#define REG_DEVICE_RX_RISC_REGISTER_28 ((volatile APE_DEVICE_H_uint32_t*)0xa0045270) /* $gp (R28) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister28. */
typedef register_container RegDEVICERxRiscRegister28_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister28"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister28_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister28. */
        r32.setName("RxRiscRegister28");
    }
    RegDEVICERxRiscRegister28_t& operator=(const RegDEVICERxRiscRegister28_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister28_t;

#define REG_DEVICE_RX_RISC_REGISTER_29 ((volatile APE_DEVICE_H_uint32_t*)0xa0045274) /* $sp (R29) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister29. */
typedef register_container RegDEVICERxRiscRegister29_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister29"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister29_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister29. */
        r32.setName("RxRiscRegister29");
    }
    RegDEVICERxRiscRegister29_t& operator=(const RegDEVICERxRiscRegister29_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister29_t;

#define REG_DEVICE_RX_RISC_REGISTER_30 ((volatile APE_DEVICE_H_uint32_t*)0xa0045278) /* $fp (R30) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister30. */
typedef register_container RegDEVICERxRiscRegister30_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister30"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister30_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister30. */
        r32.setName("RxRiscRegister30");
    }
    RegDEVICERxRiscRegister30_t& operator=(const RegDEVICERxRiscRegister30_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister30_t;

#define REG_DEVICE_RX_RISC_REGISTER_31 ((volatile APE_DEVICE_H_uint32_t*)0xa004527c) /* $ra (R31) */
/** @brief Register definition for @ref DEVICE_t.RxRiscRegister31. */
typedef register_container RegDEVICERxRiscRegister31_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxRiscRegister31"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxRiscRegister31_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxRiscRegister31. */
        r32.setName("RxRiscRegister31");
    }
    RegDEVICERxRiscRegister31_t& operator=(const RegDEVICERxRiscRegister31_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxRiscRegister31_t;

#define REG_DEVICE_6408 ((volatile APE_DEVICE_H_uint32_t*)0xa0046408) /*  */
/** @brief Register definition for @ref DEVICE_t.6408. */
typedef register_container RegDEVICE6408_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "6408"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE6408_t()
    {
        /** @brief constructor for @ref DEVICE_t.6408. */
        r32.setName("6408");
    }
    RegDEVICE6408_t& operator=(const RegDEVICE6408_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE6408_t;

#define REG_DEVICE_PCI_POWER_CONSUMPTION_INFO ((volatile APE_DEVICE_H_uint32_t*)0xa0046410) /* This undocumented register is used to set PCIe Power Consumption information as reported in configuration space. It is loaded from NVM configuration data. */
/** @brief Register definition for @ref DEVICE_t.PciPowerConsumptionInfo. */
typedef register_container RegDEVICEPciPowerConsumptionInfo_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerConsumptionInfo"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerConsumptionInfo_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerConsumptionInfo. */
        r32.setName("PciPowerConsumptionInfo");
    }
    RegDEVICEPciPowerConsumptionInfo_t& operator=(const RegDEVICEPciPowerConsumptionInfo_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerConsumptionInfo_t;

#define REG_DEVICE_PCI_POWER_DISSIPATED_INFO ((volatile APE_DEVICE_H_uint32_t*)0xa0046414) /* This undocumented register is used to set PCIe Power Dissipated information as reported in configuration space. It is loaded from NVM configuration data. */
/** @brief Register definition for @ref DEVICE_t.PciPowerDissipatedInfo. */
typedef register_container RegDEVICEPciPowerDissipatedInfo_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerDissipatedInfo"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerDissipatedInfo_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerDissipatedInfo. */
        r32.setName("PciPowerDissipatedInfo");
    }
    RegDEVICEPciPowerDissipatedInfo_t& operator=(const RegDEVICEPciPowerDissipatedInfo_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerDissipatedInfo_t;

#define REG_DEVICE_PCI_VPD_REQUEST ((volatile APE_DEVICE_H_uint32_t*)0xa004642c) /* This undocumented register appears to be used to implement the PCI VPD capability. It is set to the VPD offset which was requested by the host by writing to the VPD register. */
#define     DEVICE_PCI_VPD_REQUEST_REQUESTED_VPD_OFFSET_SHIFT 16u
#define     DEVICE_PCI_VPD_REQUEST_REQUESTED_VPD_OFFSET_MASK  0x7fff0000u
#define GET_DEVICE_PCI_VPD_REQUEST_REQUESTED_VPD_OFFSET(__reg__)  (((__reg__) & 0x7fff0000) >> 16u)
#define SET_DEVICE_PCI_VPD_REQUEST_REQUESTED_VPD_OFFSET(__val__)  (((__val__) << 16u) & 0x7fff0000u)

/** @brief Register definition for @ref DEVICE_t.PciVpdRequest. */
typedef register_container RegDEVICEPciVpdRequest_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RequestedVPDOffset, 16, 15)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RequestedVPDOffset, 16, 15)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciVpdRequest"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciVpdRequest_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciVpdRequest. */
        r32.setName("PciVpdRequest");
        bits.RequestedVPDOffset.setBaseRegister(&r32);
        bits.RequestedVPDOffset.setName("RequestedVPDOffset");
    }
    RegDEVICEPciVpdRequest_t& operator=(const RegDEVICEPciVpdRequest_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciVpdRequest_t;

#define REG_DEVICE_PCI_VPD_RESPONSE ((volatile APE_DEVICE_H_uint32_t*)0xa0046430) /* This undocumented register appears to be used to implement the PCI VPD capability. Bootcode writes the 32 bits of data loaded from the word requested by  */
/** @brief Register definition for @ref DEVICE_t.PciVpdResponse. */
typedef register_container RegDEVICEPciVpdResponse_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciVpdResponse"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciVpdResponse_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciVpdResponse. */
        r32.setName("PciVpdResponse");
    }
    RegDEVICEPciVpdResponse_t& operator=(const RegDEVICEPciVpdResponse_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciVpdResponse_t;

#define REG_DEVICE_PCI_VENDOR_DEVICE_ID ((volatile APE_DEVICE_H_uint32_t*)0xa0046434) /* This is the undocumented register used to set the PCI Vendor/Device ID, which is configurable from NVM. */
#define     DEVICE_PCI_VENDOR_DEVICE_ID_DEVICE_ID_SHIFT 0u
#define     DEVICE_PCI_VENDOR_DEVICE_ID_DEVICE_ID_MASK  0xffffu
#define GET_DEVICE_PCI_VENDOR_DEVICE_ID_DEVICE_ID(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_DEVICE_PCI_VENDOR_DEVICE_ID_DEVICE_ID(__val__)  (((__val__) << 0u) & 0xffffu)
#define     DEVICE_PCI_VENDOR_DEVICE_ID_VENDOR_ID_SHIFT 16u
#define     DEVICE_PCI_VENDOR_DEVICE_ID_VENDOR_ID_MASK  0xffff0000u
#define GET_DEVICE_PCI_VENDOR_DEVICE_ID_VENDOR_ID(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_DEVICE_PCI_VENDOR_DEVICE_ID_VENDOR_ID(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref DEVICE_t.PciVendorDeviceId. */
typedef register_container RegDEVICEPciVendorDeviceId_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DeviceID, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VendorID, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VendorID, 16, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DeviceID, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciVendorDeviceId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciVendorDeviceId_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciVendorDeviceId. */
        r32.setName("PciVendorDeviceId");
        bits.DeviceID.setBaseRegister(&r32);
        bits.DeviceID.setName("DeviceID");
        bits.VendorID.setBaseRegister(&r32);
        bits.VendorID.setName("VendorID");
    }
    RegDEVICEPciVendorDeviceId_t& operator=(const RegDEVICEPciVendorDeviceId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciVendorDeviceId_t;

#define REG_DEVICE_PCI_SUBSYSTEM_ID ((volatile APE_DEVICE_H_uint32_t*)0xa0046438) /* This is the undocumented register used to set the PCI Subsystem/Subsystem Vendor ID, which is configurable from NVM. */
#define     DEVICE_PCI_SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_SHIFT 0u
#define     DEVICE_PCI_SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_MASK  0xffffu
#define GET_DEVICE_PCI_SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_DEVICE_PCI_SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID(__val__)  (((__val__) << 0u) & 0xffffu)
#define     DEVICE_PCI_SUBSYSTEM_ID_SUBSYSTEM_ID_SHIFT 16u
#define     DEVICE_PCI_SUBSYSTEM_ID_SUBSYSTEM_ID_MASK  0xffff0000u
#define GET_DEVICE_PCI_SUBSYSTEM_ID_SUBSYSTEM_ID(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_DEVICE_PCI_SUBSYSTEM_ID_SUBSYSTEM_ID(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref DEVICE_t.PciSubsystemId. */
typedef register_container RegDEVICEPciSubsystemId_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SubsystemVendorID, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SubsystemID, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SubsystemID, 16, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, SubsystemVendorID, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciSubsystemId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciSubsystemId_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciSubsystemId. */
        r32.setName("PciSubsystemId");
        bits.SubsystemVendorID.setBaseRegister(&r32);
        bits.SubsystemVendorID.setName("SubsystemVendorID");
        bits.SubsystemID.setBaseRegister(&r32);
        bits.SubsystemID.setName("SubsystemID");
    }
    RegDEVICEPciSubsystemId_t& operator=(const RegDEVICEPciSubsystemId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciSubsystemId_t;

#define REG_DEVICE_PCI_CLASS_CODE_REVISION ((volatile APE_DEVICE_H_uint32_t*)0xa004643c) /* This undocumented register is suspected to set the class code and device revision in PCI configuration space. Unconfirmed. */
/** @brief Register definition for @ref DEVICE_t.PciClassCodeRevision. */
typedef register_container RegDEVICEPciClassCodeRevision_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciClassCodeRevision"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciClassCodeRevision_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciClassCodeRevision. */
        r32.setName("PciClassCodeRevision");
    }
    RegDEVICEPciClassCodeRevision_t& operator=(const RegDEVICEPciClassCodeRevision_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciClassCodeRevision_t;

#define REG_DEVICE_64C0 ((volatile APE_DEVICE_H_uint32_t*)0xa00464c0) /*  */
/** @brief Register definition for @ref DEVICE_t.64c0. */
typedef register_container RegDEVICE64c0_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "64c0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE64c0_t()
    {
        /** @brief constructor for @ref DEVICE_t.64c0. */
        r32.setName("64c0");
    }
    RegDEVICE64c0_t& operator=(const RegDEVICE64c0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE64c0_t;

#define REG_DEVICE_64C8 ((volatile APE_DEVICE_H_uint32_t*)0xa00464c8) /*  */
/** @brief Register definition for @ref DEVICE_t.64c8. */
typedef register_container RegDEVICE64c8_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "64c8"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE64c8_t()
    {
        /** @brief constructor for @ref DEVICE_t.64c8. */
        r32.setName("64c8");
    }
    RegDEVICE64c8_t& operator=(const RegDEVICE64c8_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE64c8_t;

#define REG_DEVICE_64DC ((volatile APE_DEVICE_H_uint32_t*)0xa00464dc) /*  */
/** @brief Register definition for @ref DEVICE_t.64dc. */
typedef register_container RegDEVICE64dc_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "64dc"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE64dc_t()
    {
        /** @brief constructor for @ref DEVICE_t.64dc. */
        r32.setName("64dc");
    }
    RegDEVICE64dc_t& operator=(const RegDEVICE64dc_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE64dc_t;

#define REG_DEVICE_PCI_SERIAL_NUMBER_LOW ((volatile APE_DEVICE_H_uint32_t*)0xa0046504) /* This sets the low 32 bits of the 64-bit device serial number, which isexposed as a PCIe capability in configuration space. */
/** @brief Register definition for @ref DEVICE_t.PciSerialNumberLow. */
typedef register_container RegDEVICEPciSerialNumberLow_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciSerialNumberLow"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciSerialNumberLow_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciSerialNumberLow. */
        r32.setName("PciSerialNumberLow");
    }
    RegDEVICEPciSerialNumberLow_t& operator=(const RegDEVICEPciSerialNumberLow_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciSerialNumberLow_t;

#define REG_DEVICE_PCI_SERIAL_NUMBER_HIGH ((volatile APE_DEVICE_H_uint32_t*)0xa0046508) /* This sets the high 32 bits of the 64-bit device serial number, which isexposed as a PCIe capability in configuration space. */
/** @brief Register definition for @ref DEVICE_t.PciSerialNumberHigh. */
typedef register_container RegDEVICEPciSerialNumberHigh_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciSerialNumberHigh"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciSerialNumberHigh_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciSerialNumberHigh. */
        r32.setName("PciSerialNumberHigh");
    }
    RegDEVICEPciSerialNumberHigh_t& operator=(const RegDEVICEPciSerialNumberHigh_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciSerialNumberHigh_t;

#define REG_DEVICE_PCI_POWER_BUDGET_0 ((volatile APE_DEVICE_H_uint32_t*)0xa0046510) /* Used to report power budget capability data to the host. The values are loaded from NVM, and up to eight values may be specified.  */
#define     DEVICE_PCI_POWER_BUDGET_0_BASE_POWER_SHIFT 0u
#define     DEVICE_PCI_POWER_BUDGET_0_BASE_POWER_MASK  0xffu
#define GET_DEVICE_PCI_POWER_BUDGET_0_BASE_POWER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_DEVICE_PCI_POWER_BUDGET_0_BASE_POWER(__val__)  (((__val__) << 0u) & 0xffu)
#define     DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE_SHIFT 8u
#define     DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE_MASK  0x300u
#define GET_DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE(__val__)  (((__val__) << 8u) & 0x300u)
#define     DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE_1_0X 0x0u
#define     DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE_0_1X 0x1u
#define     DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE_0_01X 0x2u
#define     DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE_0_001X 0x3u

#define     DEVICE_PCI_POWER_BUDGET_0_PM_SUB_STATE_SHIFT 10u
#define     DEVICE_PCI_POWER_BUDGET_0_PM_SUB_STATE_MASK  0x1c00u
#define GET_DEVICE_PCI_POWER_BUDGET_0_PM_SUB_STATE(__reg__)  (((__reg__) & 0x1c00) >> 10u)
#define SET_DEVICE_PCI_POWER_BUDGET_0_PM_SUB_STATE(__val__)  (((__val__) << 10u) & 0x1c00u)
#define     DEVICE_PCI_POWER_BUDGET_0_PM_STATE_SHIFT 13u
#define     DEVICE_PCI_POWER_BUDGET_0_PM_STATE_MASK  0x6000u
#define GET_DEVICE_PCI_POWER_BUDGET_0_PM_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_DEVICE_PCI_POWER_BUDGET_0_PM_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     DEVICE_PCI_POWER_BUDGET_0_PM_STATE_D0 0x0u
#define     DEVICE_PCI_POWER_BUDGET_0_PM_STATE_D1 0x1u
#define     DEVICE_PCI_POWER_BUDGET_0_PM_STATE_D2 0x2u
#define     DEVICE_PCI_POWER_BUDGET_0_PM_STATE_D3 0x3u

#define     DEVICE_PCI_POWER_BUDGET_0_TYPE_SHIFT 15u
#define     DEVICE_PCI_POWER_BUDGET_0_TYPE_MASK  0x38000u
#define GET_DEVICE_PCI_POWER_BUDGET_0_TYPE(__reg__)  (((__reg__) & 0x38000) >> 15u)
#define SET_DEVICE_PCI_POWER_BUDGET_0_TYPE(__val__)  (((__val__) << 15u) & 0x38000u)
#define     DEVICE_PCI_POWER_BUDGET_0_TYPE_PME_AUX 0x0u
#define     DEVICE_PCI_POWER_BUDGET_0_TYPE_AUXILIARY 0x1u
#define     DEVICE_PCI_POWER_BUDGET_0_TYPE_IDLE 0x2u
#define     DEVICE_PCI_POWER_BUDGET_0_TYPE_SUSTAINED 0x3u
#define     DEVICE_PCI_POWER_BUDGET_0_TYPE_MAXIMUM 0x7u

#define     DEVICE_PCI_POWER_BUDGET_0_POWER_RAIL_SHIFT 18u
#define     DEVICE_PCI_POWER_BUDGET_0_POWER_RAIL_MASK  0x1c0000u
#define GET_DEVICE_PCI_POWER_BUDGET_0_POWER_RAIL(__reg__)  (((__reg__) & 0x1c0000) >> 18u)
#define SET_DEVICE_PCI_POWER_BUDGET_0_POWER_RAIL(__val__)  (((__val__) << 18u) & 0x1c0000u)
#define     DEVICE_PCI_POWER_BUDGET_0_POWER_RAIL_POWER_12V 0x0u
#define     DEVICE_PCI_POWER_BUDGET_0_POWER_RAIL_POWER_3_3V 0x1u
#define     DEVICE_PCI_POWER_BUDGET_0_POWER_RAIL_POWER_1_5V_OR_1_8V 0x2u
#define     DEVICE_PCI_POWER_BUDGET_0_POWER_RAIL_THERMAL 0x7u


/** @brief Register definition for @ref DEVICE_t.PciPowerBudget0. */
typedef register_container RegDEVICEPciPowerBudget0_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerBudget0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerBudget0_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerBudget0. */
        r32.setName("PciPowerBudget0");
        bits.BasePower.setBaseRegister(&r32);
        bits.BasePower.setName("BasePower");
        bits.DataScale.setBaseRegister(&r32);
        bits.DataScale.setName("DataScale");
        bits.PMSubState.setBaseRegister(&r32);
        bits.PMSubState.setName("PMSubState");
        bits.PMState.setBaseRegister(&r32);
        bits.PMState.setName("PMState");
        bits.Type.setBaseRegister(&r32);
        bits.Type.setName("Type");
        bits.PowerRail.setBaseRegister(&r32);
        bits.PowerRail.setName("PowerRail");
    }
    RegDEVICEPciPowerBudget0_t& operator=(const RegDEVICEPciPowerBudget0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerBudget0_t;

#define REG_DEVICE_PCI_POWER_BUDGET_1 ((volatile APE_DEVICE_H_uint32_t*)0xa0046514) /* See  */
#define     DEVICE_PCI_POWER_BUDGET_1_BASE_POWER_SHIFT 0u
#define     DEVICE_PCI_POWER_BUDGET_1_BASE_POWER_MASK  0xffu
#define GET_DEVICE_PCI_POWER_BUDGET_1_BASE_POWER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_DEVICE_PCI_POWER_BUDGET_1_BASE_POWER(__val__)  (((__val__) << 0u) & 0xffu)
#define     DEVICE_PCI_POWER_BUDGET_1_DATA_SCALE_SHIFT 8u
#define     DEVICE_PCI_POWER_BUDGET_1_DATA_SCALE_MASK  0x300u
#define GET_DEVICE_PCI_POWER_BUDGET_1_DATA_SCALE(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_DEVICE_PCI_POWER_BUDGET_1_DATA_SCALE(__val__)  (((__val__) << 8u) & 0x300u)
#define     DEVICE_PCI_POWER_BUDGET_1_DATA_SCALE_1_0X 0x0u
#define     DEVICE_PCI_POWER_BUDGET_1_DATA_SCALE_0_1X 0x1u
#define     DEVICE_PCI_POWER_BUDGET_1_DATA_SCALE_0_01X 0x2u
#define     DEVICE_PCI_POWER_BUDGET_1_DATA_SCALE_0_001X 0x3u

#define     DEVICE_PCI_POWER_BUDGET_1_PM_SUB_STATE_SHIFT 10u
#define     DEVICE_PCI_POWER_BUDGET_1_PM_SUB_STATE_MASK  0x1c00u
#define GET_DEVICE_PCI_POWER_BUDGET_1_PM_SUB_STATE(__reg__)  (((__reg__) & 0x1c00) >> 10u)
#define SET_DEVICE_PCI_POWER_BUDGET_1_PM_SUB_STATE(__val__)  (((__val__) << 10u) & 0x1c00u)
#define     DEVICE_PCI_POWER_BUDGET_1_PM_STATE_SHIFT 13u
#define     DEVICE_PCI_POWER_BUDGET_1_PM_STATE_MASK  0x6000u
#define GET_DEVICE_PCI_POWER_BUDGET_1_PM_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_DEVICE_PCI_POWER_BUDGET_1_PM_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     DEVICE_PCI_POWER_BUDGET_1_PM_STATE_D0 0x0u
#define     DEVICE_PCI_POWER_BUDGET_1_PM_STATE_D1 0x1u
#define     DEVICE_PCI_POWER_BUDGET_1_PM_STATE_D2 0x2u
#define     DEVICE_PCI_POWER_BUDGET_1_PM_STATE_D3 0x3u

#define     DEVICE_PCI_POWER_BUDGET_1_TYPE_SHIFT 15u
#define     DEVICE_PCI_POWER_BUDGET_1_TYPE_MASK  0x38000u
#define GET_DEVICE_PCI_POWER_BUDGET_1_TYPE(__reg__)  (((__reg__) & 0x38000) >> 15u)
#define SET_DEVICE_PCI_POWER_BUDGET_1_TYPE(__val__)  (((__val__) << 15u) & 0x38000u)
#define     DEVICE_PCI_POWER_BUDGET_1_TYPE_PME_AUX 0x0u
#define     DEVICE_PCI_POWER_BUDGET_1_TYPE_AUXILIARY 0x1u
#define     DEVICE_PCI_POWER_BUDGET_1_TYPE_IDLE 0x2u
#define     DEVICE_PCI_POWER_BUDGET_1_TYPE_SUSTAINED 0x3u
#define     DEVICE_PCI_POWER_BUDGET_1_TYPE_MAXIMUM 0x7u

#define     DEVICE_PCI_POWER_BUDGET_1_POWER_RAIL_SHIFT 18u
#define     DEVICE_PCI_POWER_BUDGET_1_POWER_RAIL_MASK  0x1c0000u
#define GET_DEVICE_PCI_POWER_BUDGET_1_POWER_RAIL(__reg__)  (((__reg__) & 0x1c0000) >> 18u)
#define SET_DEVICE_PCI_POWER_BUDGET_1_POWER_RAIL(__val__)  (((__val__) << 18u) & 0x1c0000u)
#define     DEVICE_PCI_POWER_BUDGET_1_POWER_RAIL_POWER_12V 0x0u
#define     DEVICE_PCI_POWER_BUDGET_1_POWER_RAIL_POWER_3_3V 0x1u
#define     DEVICE_PCI_POWER_BUDGET_1_POWER_RAIL_POWER_1_5V_OR_1_8V 0x2u
#define     DEVICE_PCI_POWER_BUDGET_1_POWER_RAIL_THERMAL 0x7u


/** @brief Register definition for @ref DEVICE_t.PciPowerBudget1. */
typedef register_container RegDEVICEPciPowerBudget1_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerBudget1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerBudget1_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerBudget1. */
        r32.setName("PciPowerBudget1");
        bits.BasePower.setBaseRegister(&r32);
        bits.BasePower.setName("BasePower");
        bits.DataScale.setBaseRegister(&r32);
        bits.DataScale.setName("DataScale");
        bits.PMSubState.setBaseRegister(&r32);
        bits.PMSubState.setName("PMSubState");
        bits.PMState.setBaseRegister(&r32);
        bits.PMState.setName("PMState");
        bits.Type.setBaseRegister(&r32);
        bits.Type.setName("Type");
        bits.PowerRail.setBaseRegister(&r32);
        bits.PowerRail.setName("PowerRail");
    }
    RegDEVICEPciPowerBudget1_t& operator=(const RegDEVICEPciPowerBudget1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerBudget1_t;

#define REG_DEVICE_PCI_POWER_BUDGET_2 ((volatile APE_DEVICE_H_uint32_t*)0xa0046518) /* See  */
#define     DEVICE_PCI_POWER_BUDGET_2_BASE_POWER_SHIFT 0u
#define     DEVICE_PCI_POWER_BUDGET_2_BASE_POWER_MASK  0xffu
#define GET_DEVICE_PCI_POWER_BUDGET_2_BASE_POWER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_DEVICE_PCI_POWER_BUDGET_2_BASE_POWER(__val__)  (((__val__) << 0u) & 0xffu)
#define     DEVICE_PCI_POWER_BUDGET_2_DATA_SCALE_SHIFT 8u
#define     DEVICE_PCI_POWER_BUDGET_2_DATA_SCALE_MASK  0x300u
#define GET_DEVICE_PCI_POWER_BUDGET_2_DATA_SCALE(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_DEVICE_PCI_POWER_BUDGET_2_DATA_SCALE(__val__)  (((__val__) << 8u) & 0x300u)
#define     DEVICE_PCI_POWER_BUDGET_2_DATA_SCALE_1_0X 0x0u
#define     DEVICE_PCI_POWER_BUDGET_2_DATA_SCALE_0_1X 0x1u
#define     DEVICE_PCI_POWER_BUDGET_2_DATA_SCALE_0_01X 0x2u
#define     DEVICE_PCI_POWER_BUDGET_2_DATA_SCALE_0_001X 0x3u

#define     DEVICE_PCI_POWER_BUDGET_2_PM_SUB_STATE_SHIFT 10u
#define     DEVICE_PCI_POWER_BUDGET_2_PM_SUB_STATE_MASK  0x1c00u
#define GET_DEVICE_PCI_POWER_BUDGET_2_PM_SUB_STATE(__reg__)  (((__reg__) & 0x1c00) >> 10u)
#define SET_DEVICE_PCI_POWER_BUDGET_2_PM_SUB_STATE(__val__)  (((__val__) << 10u) & 0x1c00u)
#define     DEVICE_PCI_POWER_BUDGET_2_PM_STATE_SHIFT 13u
#define     DEVICE_PCI_POWER_BUDGET_2_PM_STATE_MASK  0x6000u
#define GET_DEVICE_PCI_POWER_BUDGET_2_PM_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_DEVICE_PCI_POWER_BUDGET_2_PM_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     DEVICE_PCI_POWER_BUDGET_2_PM_STATE_D0 0x0u
#define     DEVICE_PCI_POWER_BUDGET_2_PM_STATE_D1 0x1u
#define     DEVICE_PCI_POWER_BUDGET_2_PM_STATE_D2 0x2u
#define     DEVICE_PCI_POWER_BUDGET_2_PM_STATE_D3 0x3u

#define     DEVICE_PCI_POWER_BUDGET_2_TYPE_SHIFT 15u
#define     DEVICE_PCI_POWER_BUDGET_2_TYPE_MASK  0x38000u
#define GET_DEVICE_PCI_POWER_BUDGET_2_TYPE(__reg__)  (((__reg__) & 0x38000) >> 15u)
#define SET_DEVICE_PCI_POWER_BUDGET_2_TYPE(__val__)  (((__val__) << 15u) & 0x38000u)
#define     DEVICE_PCI_POWER_BUDGET_2_TYPE_PME_AUX 0x0u
#define     DEVICE_PCI_POWER_BUDGET_2_TYPE_AUXILIARY 0x1u
#define     DEVICE_PCI_POWER_BUDGET_2_TYPE_IDLE 0x2u
#define     DEVICE_PCI_POWER_BUDGET_2_TYPE_SUSTAINED 0x3u
#define     DEVICE_PCI_POWER_BUDGET_2_TYPE_MAXIMUM 0x7u

#define     DEVICE_PCI_POWER_BUDGET_2_POWER_RAIL_SHIFT 18u
#define     DEVICE_PCI_POWER_BUDGET_2_POWER_RAIL_MASK  0x1c0000u
#define GET_DEVICE_PCI_POWER_BUDGET_2_POWER_RAIL(__reg__)  (((__reg__) & 0x1c0000) >> 18u)
#define SET_DEVICE_PCI_POWER_BUDGET_2_POWER_RAIL(__val__)  (((__val__) << 18u) & 0x1c0000u)
#define     DEVICE_PCI_POWER_BUDGET_2_POWER_RAIL_POWER_12V 0x0u
#define     DEVICE_PCI_POWER_BUDGET_2_POWER_RAIL_POWER_3_3V 0x1u
#define     DEVICE_PCI_POWER_BUDGET_2_POWER_RAIL_POWER_1_5V_OR_1_8V 0x2u
#define     DEVICE_PCI_POWER_BUDGET_2_POWER_RAIL_THERMAL 0x7u


/** @brief Register definition for @ref DEVICE_t.PciPowerBudget2. */
typedef register_container RegDEVICEPciPowerBudget2_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerBudget2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerBudget2_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerBudget2. */
        r32.setName("PciPowerBudget2");
        bits.BasePower.setBaseRegister(&r32);
        bits.BasePower.setName("BasePower");
        bits.DataScale.setBaseRegister(&r32);
        bits.DataScale.setName("DataScale");
        bits.PMSubState.setBaseRegister(&r32);
        bits.PMSubState.setName("PMSubState");
        bits.PMState.setBaseRegister(&r32);
        bits.PMState.setName("PMState");
        bits.Type.setBaseRegister(&r32);
        bits.Type.setName("Type");
        bits.PowerRail.setBaseRegister(&r32);
        bits.PowerRail.setName("PowerRail");
    }
    RegDEVICEPciPowerBudget2_t& operator=(const RegDEVICEPciPowerBudget2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerBudget2_t;

#define REG_DEVICE_PCI_POWER_BUDGET_3 ((volatile APE_DEVICE_H_uint32_t*)0xa004651c) /* See  */
#define     DEVICE_PCI_POWER_BUDGET_3_BASE_POWER_SHIFT 0u
#define     DEVICE_PCI_POWER_BUDGET_3_BASE_POWER_MASK  0xffu
#define GET_DEVICE_PCI_POWER_BUDGET_3_BASE_POWER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_DEVICE_PCI_POWER_BUDGET_3_BASE_POWER(__val__)  (((__val__) << 0u) & 0xffu)
#define     DEVICE_PCI_POWER_BUDGET_3_DATA_SCALE_SHIFT 8u
#define     DEVICE_PCI_POWER_BUDGET_3_DATA_SCALE_MASK  0x300u
#define GET_DEVICE_PCI_POWER_BUDGET_3_DATA_SCALE(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_DEVICE_PCI_POWER_BUDGET_3_DATA_SCALE(__val__)  (((__val__) << 8u) & 0x300u)
#define     DEVICE_PCI_POWER_BUDGET_3_DATA_SCALE_1_0X 0x0u
#define     DEVICE_PCI_POWER_BUDGET_3_DATA_SCALE_0_1X 0x1u
#define     DEVICE_PCI_POWER_BUDGET_3_DATA_SCALE_0_01X 0x2u
#define     DEVICE_PCI_POWER_BUDGET_3_DATA_SCALE_0_001X 0x3u

#define     DEVICE_PCI_POWER_BUDGET_3_PM_SUB_STATE_SHIFT 10u
#define     DEVICE_PCI_POWER_BUDGET_3_PM_SUB_STATE_MASK  0x1c00u
#define GET_DEVICE_PCI_POWER_BUDGET_3_PM_SUB_STATE(__reg__)  (((__reg__) & 0x1c00) >> 10u)
#define SET_DEVICE_PCI_POWER_BUDGET_3_PM_SUB_STATE(__val__)  (((__val__) << 10u) & 0x1c00u)
#define     DEVICE_PCI_POWER_BUDGET_3_PM_STATE_SHIFT 13u
#define     DEVICE_PCI_POWER_BUDGET_3_PM_STATE_MASK  0x6000u
#define GET_DEVICE_PCI_POWER_BUDGET_3_PM_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_DEVICE_PCI_POWER_BUDGET_3_PM_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     DEVICE_PCI_POWER_BUDGET_3_PM_STATE_D0 0x0u
#define     DEVICE_PCI_POWER_BUDGET_3_PM_STATE_D1 0x1u
#define     DEVICE_PCI_POWER_BUDGET_3_PM_STATE_D2 0x2u
#define     DEVICE_PCI_POWER_BUDGET_3_PM_STATE_D3 0x3u

#define     DEVICE_PCI_POWER_BUDGET_3_TYPE_SHIFT 15u
#define     DEVICE_PCI_POWER_BUDGET_3_TYPE_MASK  0x38000u
#define GET_DEVICE_PCI_POWER_BUDGET_3_TYPE(__reg__)  (((__reg__) & 0x38000) >> 15u)
#define SET_DEVICE_PCI_POWER_BUDGET_3_TYPE(__val__)  (((__val__) << 15u) & 0x38000u)
#define     DEVICE_PCI_POWER_BUDGET_3_TYPE_PME_AUX 0x0u
#define     DEVICE_PCI_POWER_BUDGET_3_TYPE_AUXILIARY 0x1u
#define     DEVICE_PCI_POWER_BUDGET_3_TYPE_IDLE 0x2u
#define     DEVICE_PCI_POWER_BUDGET_3_TYPE_SUSTAINED 0x3u
#define     DEVICE_PCI_POWER_BUDGET_3_TYPE_MAXIMUM 0x7u

#define     DEVICE_PCI_POWER_BUDGET_3_POWER_RAIL_SHIFT 18u
#define     DEVICE_PCI_POWER_BUDGET_3_POWER_RAIL_MASK  0x1c0000u
#define GET_DEVICE_PCI_POWER_BUDGET_3_POWER_RAIL(__reg__)  (((__reg__) & 0x1c0000) >> 18u)
#define SET_DEVICE_PCI_POWER_BUDGET_3_POWER_RAIL(__val__)  (((__val__) << 18u) & 0x1c0000u)
#define     DEVICE_PCI_POWER_BUDGET_3_POWER_RAIL_POWER_12V 0x0u
#define     DEVICE_PCI_POWER_BUDGET_3_POWER_RAIL_POWER_3_3V 0x1u
#define     DEVICE_PCI_POWER_BUDGET_3_POWER_RAIL_POWER_1_5V_OR_1_8V 0x2u
#define     DEVICE_PCI_POWER_BUDGET_3_POWER_RAIL_THERMAL 0x7u


/** @brief Register definition for @ref DEVICE_t.PciPowerBudget3. */
typedef register_container RegDEVICEPciPowerBudget3_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerBudget3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerBudget3_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerBudget3. */
        r32.setName("PciPowerBudget3");
        bits.BasePower.setBaseRegister(&r32);
        bits.BasePower.setName("BasePower");
        bits.DataScale.setBaseRegister(&r32);
        bits.DataScale.setName("DataScale");
        bits.PMSubState.setBaseRegister(&r32);
        bits.PMSubState.setName("PMSubState");
        bits.PMState.setBaseRegister(&r32);
        bits.PMState.setName("PMState");
        bits.Type.setBaseRegister(&r32);
        bits.Type.setName("Type");
        bits.PowerRail.setBaseRegister(&r32);
        bits.PowerRail.setName("PowerRail");
    }
    RegDEVICEPciPowerBudget3_t& operator=(const RegDEVICEPciPowerBudget3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerBudget3_t;

#define REG_DEVICE_PCI_POWER_BUDGET_4 ((volatile APE_DEVICE_H_uint32_t*)0xa0046520) /* See  */
#define     DEVICE_PCI_POWER_BUDGET_4_BASE_POWER_SHIFT 0u
#define     DEVICE_PCI_POWER_BUDGET_4_BASE_POWER_MASK  0xffu
#define GET_DEVICE_PCI_POWER_BUDGET_4_BASE_POWER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_DEVICE_PCI_POWER_BUDGET_4_BASE_POWER(__val__)  (((__val__) << 0u) & 0xffu)
#define     DEVICE_PCI_POWER_BUDGET_4_DATA_SCALE_SHIFT 8u
#define     DEVICE_PCI_POWER_BUDGET_4_DATA_SCALE_MASK  0x300u
#define GET_DEVICE_PCI_POWER_BUDGET_4_DATA_SCALE(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_DEVICE_PCI_POWER_BUDGET_4_DATA_SCALE(__val__)  (((__val__) << 8u) & 0x300u)
#define     DEVICE_PCI_POWER_BUDGET_4_DATA_SCALE_1_0X 0x0u
#define     DEVICE_PCI_POWER_BUDGET_4_DATA_SCALE_0_1X 0x1u
#define     DEVICE_PCI_POWER_BUDGET_4_DATA_SCALE_0_01X 0x2u
#define     DEVICE_PCI_POWER_BUDGET_4_DATA_SCALE_0_001X 0x3u

#define     DEVICE_PCI_POWER_BUDGET_4_PM_SUB_STATE_SHIFT 10u
#define     DEVICE_PCI_POWER_BUDGET_4_PM_SUB_STATE_MASK  0x1c00u
#define GET_DEVICE_PCI_POWER_BUDGET_4_PM_SUB_STATE(__reg__)  (((__reg__) & 0x1c00) >> 10u)
#define SET_DEVICE_PCI_POWER_BUDGET_4_PM_SUB_STATE(__val__)  (((__val__) << 10u) & 0x1c00u)
#define     DEVICE_PCI_POWER_BUDGET_4_PM_STATE_SHIFT 13u
#define     DEVICE_PCI_POWER_BUDGET_4_PM_STATE_MASK  0x6000u
#define GET_DEVICE_PCI_POWER_BUDGET_4_PM_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_DEVICE_PCI_POWER_BUDGET_4_PM_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     DEVICE_PCI_POWER_BUDGET_4_PM_STATE_D0 0x0u
#define     DEVICE_PCI_POWER_BUDGET_4_PM_STATE_D1 0x1u
#define     DEVICE_PCI_POWER_BUDGET_4_PM_STATE_D2 0x2u
#define     DEVICE_PCI_POWER_BUDGET_4_PM_STATE_D3 0x3u

#define     DEVICE_PCI_POWER_BUDGET_4_TYPE_SHIFT 15u
#define     DEVICE_PCI_POWER_BUDGET_4_TYPE_MASK  0x38000u
#define GET_DEVICE_PCI_POWER_BUDGET_4_TYPE(__reg__)  (((__reg__) & 0x38000) >> 15u)
#define SET_DEVICE_PCI_POWER_BUDGET_4_TYPE(__val__)  (((__val__) << 15u) & 0x38000u)
#define     DEVICE_PCI_POWER_BUDGET_4_TYPE_PME_AUX 0x0u
#define     DEVICE_PCI_POWER_BUDGET_4_TYPE_AUXILIARY 0x1u
#define     DEVICE_PCI_POWER_BUDGET_4_TYPE_IDLE 0x2u
#define     DEVICE_PCI_POWER_BUDGET_4_TYPE_SUSTAINED 0x3u
#define     DEVICE_PCI_POWER_BUDGET_4_TYPE_MAXIMUM 0x7u

#define     DEVICE_PCI_POWER_BUDGET_4_POWER_RAIL_SHIFT 18u
#define     DEVICE_PCI_POWER_BUDGET_4_POWER_RAIL_MASK  0x1c0000u
#define GET_DEVICE_PCI_POWER_BUDGET_4_POWER_RAIL(__reg__)  (((__reg__) & 0x1c0000) >> 18u)
#define SET_DEVICE_PCI_POWER_BUDGET_4_POWER_RAIL(__val__)  (((__val__) << 18u) & 0x1c0000u)
#define     DEVICE_PCI_POWER_BUDGET_4_POWER_RAIL_POWER_12V 0x0u
#define     DEVICE_PCI_POWER_BUDGET_4_POWER_RAIL_POWER_3_3V 0x1u
#define     DEVICE_PCI_POWER_BUDGET_4_POWER_RAIL_POWER_1_5V_OR_1_8V 0x2u
#define     DEVICE_PCI_POWER_BUDGET_4_POWER_RAIL_THERMAL 0x7u


/** @brief Register definition for @ref DEVICE_t.PciPowerBudget4. */
typedef register_container RegDEVICEPciPowerBudget4_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerBudget4"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerBudget4_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerBudget4. */
        r32.setName("PciPowerBudget4");
        bits.BasePower.setBaseRegister(&r32);
        bits.BasePower.setName("BasePower");
        bits.DataScale.setBaseRegister(&r32);
        bits.DataScale.setName("DataScale");
        bits.PMSubState.setBaseRegister(&r32);
        bits.PMSubState.setName("PMSubState");
        bits.PMState.setBaseRegister(&r32);
        bits.PMState.setName("PMState");
        bits.Type.setBaseRegister(&r32);
        bits.Type.setName("Type");
        bits.PowerRail.setBaseRegister(&r32);
        bits.PowerRail.setName("PowerRail");
    }
    RegDEVICEPciPowerBudget4_t& operator=(const RegDEVICEPciPowerBudget4_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerBudget4_t;

#define REG_DEVICE_PCI_POWER_BUDGET_5 ((volatile APE_DEVICE_H_uint32_t*)0xa0046524) /* See  */
#define     DEVICE_PCI_POWER_BUDGET_5_BASE_POWER_SHIFT 0u
#define     DEVICE_PCI_POWER_BUDGET_5_BASE_POWER_MASK  0xffu
#define GET_DEVICE_PCI_POWER_BUDGET_5_BASE_POWER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_DEVICE_PCI_POWER_BUDGET_5_BASE_POWER(__val__)  (((__val__) << 0u) & 0xffu)
#define     DEVICE_PCI_POWER_BUDGET_5_DATA_SCALE_SHIFT 8u
#define     DEVICE_PCI_POWER_BUDGET_5_DATA_SCALE_MASK  0x300u
#define GET_DEVICE_PCI_POWER_BUDGET_5_DATA_SCALE(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_DEVICE_PCI_POWER_BUDGET_5_DATA_SCALE(__val__)  (((__val__) << 8u) & 0x300u)
#define     DEVICE_PCI_POWER_BUDGET_5_DATA_SCALE_1_0X 0x0u
#define     DEVICE_PCI_POWER_BUDGET_5_DATA_SCALE_0_1X 0x1u
#define     DEVICE_PCI_POWER_BUDGET_5_DATA_SCALE_0_01X 0x2u
#define     DEVICE_PCI_POWER_BUDGET_5_DATA_SCALE_0_001X 0x3u

#define     DEVICE_PCI_POWER_BUDGET_5_PM_SUB_STATE_SHIFT 10u
#define     DEVICE_PCI_POWER_BUDGET_5_PM_SUB_STATE_MASK  0x1c00u
#define GET_DEVICE_PCI_POWER_BUDGET_5_PM_SUB_STATE(__reg__)  (((__reg__) & 0x1c00) >> 10u)
#define SET_DEVICE_PCI_POWER_BUDGET_5_PM_SUB_STATE(__val__)  (((__val__) << 10u) & 0x1c00u)
#define     DEVICE_PCI_POWER_BUDGET_5_PM_STATE_SHIFT 13u
#define     DEVICE_PCI_POWER_BUDGET_5_PM_STATE_MASK  0x6000u
#define GET_DEVICE_PCI_POWER_BUDGET_5_PM_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_DEVICE_PCI_POWER_BUDGET_5_PM_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     DEVICE_PCI_POWER_BUDGET_5_PM_STATE_D0 0x0u
#define     DEVICE_PCI_POWER_BUDGET_5_PM_STATE_D1 0x1u
#define     DEVICE_PCI_POWER_BUDGET_5_PM_STATE_D2 0x2u
#define     DEVICE_PCI_POWER_BUDGET_5_PM_STATE_D3 0x3u

#define     DEVICE_PCI_POWER_BUDGET_5_TYPE_SHIFT 15u
#define     DEVICE_PCI_POWER_BUDGET_5_TYPE_MASK  0x38000u
#define GET_DEVICE_PCI_POWER_BUDGET_5_TYPE(__reg__)  (((__reg__) & 0x38000) >> 15u)
#define SET_DEVICE_PCI_POWER_BUDGET_5_TYPE(__val__)  (((__val__) << 15u) & 0x38000u)
#define     DEVICE_PCI_POWER_BUDGET_5_TYPE_PME_AUX 0x0u
#define     DEVICE_PCI_POWER_BUDGET_5_TYPE_AUXILIARY 0x1u
#define     DEVICE_PCI_POWER_BUDGET_5_TYPE_IDLE 0x2u
#define     DEVICE_PCI_POWER_BUDGET_5_TYPE_SUSTAINED 0x3u
#define     DEVICE_PCI_POWER_BUDGET_5_TYPE_MAXIMUM 0x7u

#define     DEVICE_PCI_POWER_BUDGET_5_POWER_RAIL_SHIFT 18u
#define     DEVICE_PCI_POWER_BUDGET_5_POWER_RAIL_MASK  0x1c0000u
#define GET_DEVICE_PCI_POWER_BUDGET_5_POWER_RAIL(__reg__)  (((__reg__) & 0x1c0000) >> 18u)
#define SET_DEVICE_PCI_POWER_BUDGET_5_POWER_RAIL(__val__)  (((__val__) << 18u) & 0x1c0000u)
#define     DEVICE_PCI_POWER_BUDGET_5_POWER_RAIL_POWER_12V 0x0u
#define     DEVICE_PCI_POWER_BUDGET_5_POWER_RAIL_POWER_3_3V 0x1u
#define     DEVICE_PCI_POWER_BUDGET_5_POWER_RAIL_POWER_1_5V_OR_1_8V 0x2u
#define     DEVICE_PCI_POWER_BUDGET_5_POWER_RAIL_THERMAL 0x7u


/** @brief Register definition for @ref DEVICE_t.PciPowerBudget5. */
typedef register_container RegDEVICEPciPowerBudget5_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerBudget5"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerBudget5_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerBudget5. */
        r32.setName("PciPowerBudget5");
        bits.BasePower.setBaseRegister(&r32);
        bits.BasePower.setName("BasePower");
        bits.DataScale.setBaseRegister(&r32);
        bits.DataScale.setName("DataScale");
        bits.PMSubState.setBaseRegister(&r32);
        bits.PMSubState.setName("PMSubState");
        bits.PMState.setBaseRegister(&r32);
        bits.PMState.setName("PMState");
        bits.Type.setBaseRegister(&r32);
        bits.Type.setName("Type");
        bits.PowerRail.setBaseRegister(&r32);
        bits.PowerRail.setName("PowerRail");
    }
    RegDEVICEPciPowerBudget5_t& operator=(const RegDEVICEPciPowerBudget5_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerBudget5_t;

#define REG_DEVICE_PCI_POWER_BUDGET_6 ((volatile APE_DEVICE_H_uint32_t*)0xa0046528) /* See  */
#define     DEVICE_PCI_POWER_BUDGET_6_BASE_POWER_SHIFT 0u
#define     DEVICE_PCI_POWER_BUDGET_6_BASE_POWER_MASK  0xffu
#define GET_DEVICE_PCI_POWER_BUDGET_6_BASE_POWER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_DEVICE_PCI_POWER_BUDGET_6_BASE_POWER(__val__)  (((__val__) << 0u) & 0xffu)
#define     DEVICE_PCI_POWER_BUDGET_6_DATA_SCALE_SHIFT 8u
#define     DEVICE_PCI_POWER_BUDGET_6_DATA_SCALE_MASK  0x300u
#define GET_DEVICE_PCI_POWER_BUDGET_6_DATA_SCALE(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_DEVICE_PCI_POWER_BUDGET_6_DATA_SCALE(__val__)  (((__val__) << 8u) & 0x300u)
#define     DEVICE_PCI_POWER_BUDGET_6_DATA_SCALE_1_0X 0x0u
#define     DEVICE_PCI_POWER_BUDGET_6_DATA_SCALE_0_1X 0x1u
#define     DEVICE_PCI_POWER_BUDGET_6_DATA_SCALE_0_01X 0x2u
#define     DEVICE_PCI_POWER_BUDGET_6_DATA_SCALE_0_001X 0x3u

#define     DEVICE_PCI_POWER_BUDGET_6_PM_SUB_STATE_SHIFT 10u
#define     DEVICE_PCI_POWER_BUDGET_6_PM_SUB_STATE_MASK  0x1c00u
#define GET_DEVICE_PCI_POWER_BUDGET_6_PM_SUB_STATE(__reg__)  (((__reg__) & 0x1c00) >> 10u)
#define SET_DEVICE_PCI_POWER_BUDGET_6_PM_SUB_STATE(__val__)  (((__val__) << 10u) & 0x1c00u)
#define     DEVICE_PCI_POWER_BUDGET_6_PM_STATE_SHIFT 13u
#define     DEVICE_PCI_POWER_BUDGET_6_PM_STATE_MASK  0x6000u
#define GET_DEVICE_PCI_POWER_BUDGET_6_PM_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_DEVICE_PCI_POWER_BUDGET_6_PM_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     DEVICE_PCI_POWER_BUDGET_6_PM_STATE_D0 0x0u
#define     DEVICE_PCI_POWER_BUDGET_6_PM_STATE_D1 0x1u
#define     DEVICE_PCI_POWER_BUDGET_6_PM_STATE_D2 0x2u
#define     DEVICE_PCI_POWER_BUDGET_6_PM_STATE_D3 0x3u

#define     DEVICE_PCI_POWER_BUDGET_6_TYPE_SHIFT 15u
#define     DEVICE_PCI_POWER_BUDGET_6_TYPE_MASK  0x38000u
#define GET_DEVICE_PCI_POWER_BUDGET_6_TYPE(__reg__)  (((__reg__) & 0x38000) >> 15u)
#define SET_DEVICE_PCI_POWER_BUDGET_6_TYPE(__val__)  (((__val__) << 15u) & 0x38000u)
#define     DEVICE_PCI_POWER_BUDGET_6_TYPE_PME_AUX 0x0u
#define     DEVICE_PCI_POWER_BUDGET_6_TYPE_AUXILIARY 0x1u
#define     DEVICE_PCI_POWER_BUDGET_6_TYPE_IDLE 0x2u
#define     DEVICE_PCI_POWER_BUDGET_6_TYPE_SUSTAINED 0x3u
#define     DEVICE_PCI_POWER_BUDGET_6_TYPE_MAXIMUM 0x7u

#define     DEVICE_PCI_POWER_BUDGET_6_POWER_RAIL_SHIFT 18u
#define     DEVICE_PCI_POWER_BUDGET_6_POWER_RAIL_MASK  0x1c0000u
#define GET_DEVICE_PCI_POWER_BUDGET_6_POWER_RAIL(__reg__)  (((__reg__) & 0x1c0000) >> 18u)
#define SET_DEVICE_PCI_POWER_BUDGET_6_POWER_RAIL(__val__)  (((__val__) << 18u) & 0x1c0000u)
#define     DEVICE_PCI_POWER_BUDGET_6_POWER_RAIL_POWER_12V 0x0u
#define     DEVICE_PCI_POWER_BUDGET_6_POWER_RAIL_POWER_3_3V 0x1u
#define     DEVICE_PCI_POWER_BUDGET_6_POWER_RAIL_POWER_1_5V_OR_1_8V 0x2u
#define     DEVICE_PCI_POWER_BUDGET_6_POWER_RAIL_THERMAL 0x7u


/** @brief Register definition for @ref DEVICE_t.PciPowerBudget6. */
typedef register_container RegDEVICEPciPowerBudget6_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerBudget6"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerBudget6_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerBudget6. */
        r32.setName("PciPowerBudget6");
        bits.BasePower.setBaseRegister(&r32);
        bits.BasePower.setName("BasePower");
        bits.DataScale.setBaseRegister(&r32);
        bits.DataScale.setName("DataScale");
        bits.PMSubState.setBaseRegister(&r32);
        bits.PMSubState.setName("PMSubState");
        bits.PMState.setBaseRegister(&r32);
        bits.PMState.setName("PMState");
        bits.Type.setBaseRegister(&r32);
        bits.Type.setName("Type");
        bits.PowerRail.setBaseRegister(&r32);
        bits.PowerRail.setName("PowerRail");
    }
    RegDEVICEPciPowerBudget6_t& operator=(const RegDEVICEPciPowerBudget6_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerBudget6_t;

#define REG_DEVICE_PCI_POWER_BUDGET_7 ((volatile APE_DEVICE_H_uint32_t*)0xa004652c) /* See  */
#define     DEVICE_PCI_POWER_BUDGET_7_BASE_POWER_SHIFT 0u
#define     DEVICE_PCI_POWER_BUDGET_7_BASE_POWER_MASK  0xffu
#define GET_DEVICE_PCI_POWER_BUDGET_7_BASE_POWER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_DEVICE_PCI_POWER_BUDGET_7_BASE_POWER(__val__)  (((__val__) << 0u) & 0xffu)
#define     DEVICE_PCI_POWER_BUDGET_7_DATA_SCALE_SHIFT 8u
#define     DEVICE_PCI_POWER_BUDGET_7_DATA_SCALE_MASK  0x300u
#define GET_DEVICE_PCI_POWER_BUDGET_7_DATA_SCALE(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_DEVICE_PCI_POWER_BUDGET_7_DATA_SCALE(__val__)  (((__val__) << 8u) & 0x300u)
#define     DEVICE_PCI_POWER_BUDGET_7_DATA_SCALE_1_0X 0x0u
#define     DEVICE_PCI_POWER_BUDGET_7_DATA_SCALE_0_1X 0x1u
#define     DEVICE_PCI_POWER_BUDGET_7_DATA_SCALE_0_01X 0x2u
#define     DEVICE_PCI_POWER_BUDGET_7_DATA_SCALE_0_001X 0x3u

#define     DEVICE_PCI_POWER_BUDGET_7_PM_SUB_STATE_SHIFT 10u
#define     DEVICE_PCI_POWER_BUDGET_7_PM_SUB_STATE_MASK  0x1c00u
#define GET_DEVICE_PCI_POWER_BUDGET_7_PM_SUB_STATE(__reg__)  (((__reg__) & 0x1c00) >> 10u)
#define SET_DEVICE_PCI_POWER_BUDGET_7_PM_SUB_STATE(__val__)  (((__val__) << 10u) & 0x1c00u)
#define     DEVICE_PCI_POWER_BUDGET_7_PM_STATE_SHIFT 13u
#define     DEVICE_PCI_POWER_BUDGET_7_PM_STATE_MASK  0x6000u
#define GET_DEVICE_PCI_POWER_BUDGET_7_PM_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_DEVICE_PCI_POWER_BUDGET_7_PM_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     DEVICE_PCI_POWER_BUDGET_7_PM_STATE_D0 0x0u
#define     DEVICE_PCI_POWER_BUDGET_7_PM_STATE_D1 0x1u
#define     DEVICE_PCI_POWER_BUDGET_7_PM_STATE_D2 0x2u
#define     DEVICE_PCI_POWER_BUDGET_7_PM_STATE_D3 0x3u

#define     DEVICE_PCI_POWER_BUDGET_7_TYPE_SHIFT 15u
#define     DEVICE_PCI_POWER_BUDGET_7_TYPE_MASK  0x38000u
#define GET_DEVICE_PCI_POWER_BUDGET_7_TYPE(__reg__)  (((__reg__) & 0x38000) >> 15u)
#define SET_DEVICE_PCI_POWER_BUDGET_7_TYPE(__val__)  (((__val__) << 15u) & 0x38000u)
#define     DEVICE_PCI_POWER_BUDGET_7_TYPE_PME_AUX 0x0u
#define     DEVICE_PCI_POWER_BUDGET_7_TYPE_AUXILIARY 0x1u
#define     DEVICE_PCI_POWER_BUDGET_7_TYPE_IDLE 0x2u
#define     DEVICE_PCI_POWER_BUDGET_7_TYPE_SUSTAINED 0x3u
#define     DEVICE_PCI_POWER_BUDGET_7_TYPE_MAXIMUM 0x7u

#define     DEVICE_PCI_POWER_BUDGET_7_POWER_RAIL_SHIFT 18u
#define     DEVICE_PCI_POWER_BUDGET_7_POWER_RAIL_MASK  0x1c0000u
#define GET_DEVICE_PCI_POWER_BUDGET_7_POWER_RAIL(__reg__)  (((__reg__) & 0x1c0000) >> 18u)
#define SET_DEVICE_PCI_POWER_BUDGET_7_POWER_RAIL(__val__)  (((__val__) << 18u) & 0x1c0000u)
#define     DEVICE_PCI_POWER_BUDGET_7_POWER_RAIL_POWER_12V 0x0u
#define     DEVICE_PCI_POWER_BUDGET_7_POWER_RAIL_POWER_3_3V 0x1u
#define     DEVICE_PCI_POWER_BUDGET_7_POWER_RAIL_POWER_1_5V_OR_1_8V 0x2u
#define     DEVICE_PCI_POWER_BUDGET_7_POWER_RAIL_THERMAL 0x7u


/** @brief Register definition for @ref DEVICE_t.PciPowerBudget7. */
typedef register_container RegDEVICEPciPowerBudget7_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Specifies the thermal load or power rail of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PowerRail, 18, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Type, 15, 3)
        /** @brief Specifies the power management state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMState, 13, 2)
        /** @brief Specifies the power management sub state of the operating condition being described. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PMSubState, 10, 3)
        /** @brief Specifies the scale to apply to the Base Power value. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, DataScale, 8, 2)
        /** @brief Specifies in watts the base power value in the given operating condition. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, BasePower, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PciPowerBudget7"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEPciPowerBudget7_t()
    {
        /** @brief constructor for @ref DEVICE_t.PciPowerBudget7. */
        r32.setName("PciPowerBudget7");
        bits.BasePower.setBaseRegister(&r32);
        bits.BasePower.setName("BasePower");
        bits.DataScale.setBaseRegister(&r32);
        bits.DataScale.setName("DataScale");
        bits.PMSubState.setBaseRegister(&r32);
        bits.PMSubState.setName("PMSubState");
        bits.PMState.setBaseRegister(&r32);
        bits.PMState.setName("PMState");
        bits.Type.setBaseRegister(&r32);
        bits.Type.setName("Type");
        bits.PowerRail.setBaseRegister(&r32);
        bits.PowerRail.setName("PowerRail");
    }
    RegDEVICEPciPowerBudget7_t& operator=(const RegDEVICEPciPowerBudget7_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEPciPowerBudget7_t;

#define REG_DEVICE_6530 ((volatile APE_DEVICE_H_uint32_t*)0xa0046530) /*  */
/** @brief Register definition for @ref DEVICE_t.6530. */
typedef register_container RegDEVICE6530_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "6530"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE6530_t()
    {
        /** @brief constructor for @ref DEVICE_t.6530. */
        r32.setName("6530");
    }
    RegDEVICE6530_t& operator=(const RegDEVICE6530_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE6530_t;

#define REG_DEVICE_6550 ((volatile APE_DEVICE_H_uint32_t*)0xa0046550) /* The LSB in this undocumented and unknown register is set if the device is a LOM (LAN-on-Motherboard) design (i.e., builtin to a system and not an expansion card). */
/** @brief Register definition for @ref DEVICE_t.6550. */
typedef register_container RegDEVICE6550_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "6550"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE6550_t()
    {
        /** @brief constructor for @ref DEVICE_t.6550. */
        r32.setName("6550");
    }
    RegDEVICE6550_t& operator=(const RegDEVICE6550_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE6550_t;

#define REG_DEVICE_65F4 ((volatile APE_DEVICE_H_uint32_t*)0xa00465f4) /*  */
/** @brief Register definition for @ref DEVICE_t.65f4. */
typedef register_container RegDEVICE65f4_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "65f4"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE65f4_t()
    {
        /** @brief constructor for @ref DEVICE_t.65f4. */
        r32.setName("65f4");
    }
    RegDEVICE65f4_t& operator=(const RegDEVICE65f4_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE65f4_t;

#define REG_DEVICE_GRC_MODE_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa0046800) /*  */
#define     DEVICE_GRC_MODE_CONTROL_TIME_SYNC_MODE_ENABLE_SHIFT 19u
#define     DEVICE_GRC_MODE_CONTROL_TIME_SYNC_MODE_ENABLE_MASK  0x80000u
#define GET_DEVICE_GRC_MODE_CONTROL_TIME_SYNC_MODE_ENABLE(__reg__)  (((__reg__) & 0x80000) >> 19u)
#define SET_DEVICE_GRC_MODE_CONTROL_TIME_SYNC_MODE_ENABLE(__val__)  (((__val__) << 19u) & 0x80000u)
#define     DEVICE_GRC_MODE_CONTROL_NVRAM_WRITE_ENABLE_SHIFT 21u
#define     DEVICE_GRC_MODE_CONTROL_NVRAM_WRITE_ENABLE_MASK  0x200000u
#define GET_DEVICE_GRC_MODE_CONTROL_NVRAM_WRITE_ENABLE(__reg__)  (((__reg__) & 0x200000) >> 21u)
#define SET_DEVICE_GRC_MODE_CONTROL_NVRAM_WRITE_ENABLE(__val__)  (((__val__) << 21u) & 0x200000u)
#define     DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_1_SHIFT 22u
#define     DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_1_MASK  0x400000u
#define GET_DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_1(__reg__)  (((__reg__) & 0x400000) >> 22u)
#define SET_DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_1(__val__)  (((__val__) << 22u) & 0x400000u)
#define     DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_2_SHIFT 29u
#define     DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_2_MASK  0x20000000u
#define GET_DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_2(__reg__)  (((__reg__) & 0x20000000) >> 29u)
#define SET_DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_2(__val__)  (((__val__) << 29u) & 0x20000000u)
#define     DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_3_SHIFT 31u
#define     DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_3_MASK  0x80000000u
#define GET_DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_3(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_DEVICE_GRC_MODE_CONTROL_PCIE_TL_DIV_DL_DIV_PL_MAPPING_3(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref DEVICE_t.GrcModeControl. */
typedef register_container RegDEVICEGrcModeControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_18_0, 0, 19)
        /** @brief Write 1 to this bit to enable Time Sync Mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TimeSyncModeEnable, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_20_20, 20, 1)
        /** @brief The host must set this bit before attempting to update the Flash or SEEPROM. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NVRAMWriteEnable, 21, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIeTL_DIV_DL_DIV_PLMapping1, 22, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_28_23, 23, 6)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIeTL_DIV_DL_DIV_PLMapping2, 29, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_30_30, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIeTL_DIV_DL_DIV_PLMapping3, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIeTL_DIV_DL_DIV_PLMapping3, 31, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_30_30, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIeTL_DIV_DL_DIV_PLMapping2, 29, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_28_23, 23, 6)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, PCIeTL_DIV_DL_DIV_PLMapping1, 22, 1)
        /** @brief The host must set this bit before attempting to update the Flash or SEEPROM. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, NVRAMWriteEnable, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_20_20, 20, 1)
        /** @brief Write 1 to this bit to enable Time Sync Mode. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TimeSyncModeEnable, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_18_0, 0, 19)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GrcModeControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEGrcModeControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.GrcModeControl. */
        r32.setName("GrcModeControl");
        bits.TimeSyncModeEnable.setBaseRegister(&r32);
        bits.TimeSyncModeEnable.setName("TimeSyncModeEnable");
        bits.NVRAMWriteEnable.setBaseRegister(&r32);
        bits.NVRAMWriteEnable.setName("NVRAMWriteEnable");
        bits.PCIeTL_DIV_DL_DIV_PLMapping1.setBaseRegister(&r32);
        bits.PCIeTL_DIV_DL_DIV_PLMapping1.setName("PCIeTL_DIV_DL_DIV_PLMapping1");
        bits.PCIeTL_DIV_DL_DIV_PLMapping2.setBaseRegister(&r32);
        bits.PCIeTL_DIV_DL_DIV_PLMapping2.setName("PCIeTL_DIV_DL_DIV_PLMapping2");
        bits.PCIeTL_DIV_DL_DIV_PLMapping3.setBaseRegister(&r32);
        bits.PCIeTL_DIV_DL_DIV_PLMapping3.setName("PCIeTL_DIV_DL_DIV_PLMapping3");
    }
    RegDEVICEGrcModeControl_t& operator=(const RegDEVICEGrcModeControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEGrcModeControl_t;

#define REG_DEVICE_MISCELLANEOUS_CONFIG ((volatile APE_DEVICE_H_uint32_t*)0xa0046804) /*  */
#define     DEVICE_MISCELLANEOUS_CONFIG_ALL_SHIFT 0u
#define     DEVICE_MISCELLANEOUS_CONFIG_ALL_MASK  0xffffffffu
#define GET_DEVICE_MISCELLANEOUS_CONFIG_ALL(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_DEVICE_MISCELLANEOUS_CONFIG_ALL(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref DEVICE_t.MiscellaneousConfig. */
typedef register_container RegDEVICEMiscellaneousConfig_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, all, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, all, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MiscellaneousConfig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMiscellaneousConfig_t()
    {
        /** @brief constructor for @ref DEVICE_t.MiscellaneousConfig. */
        r32.setName("MiscellaneousConfig");
        bits.all.setBaseRegister(&r32);
        bits.all.setName("all");
    }
    RegDEVICEMiscellaneousConfig_t& operator=(const RegDEVICEMiscellaneousConfig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMiscellaneousConfig_t;

#define REG_DEVICE_MISCELLANEOUS_LOCAL_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa0046808) /*  */
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_INPUT_SHIFT 8u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_INPUT_MASK  0x100u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_INPUT(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_INPUT(__val__)  (((__val__) << 8u) & 0x100u)
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_INPUT_SHIFT 9u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_INPUT_MASK  0x200u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_INPUT(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_INPUT(__val__)  (((__val__) << 9u) & 0x200u)
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_INPUT_SHIFT 10u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_INPUT_MASK  0x400u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_INPUT(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_INPUT(__val__)  (((__val__) << 10u) & 0x400u)
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_OUTPUT_ENABLE_SHIFT 11u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_OUTPUT_ENABLE_MASK  0x800u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_OUTPUT_ENABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_OUTPUT_ENABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_OUTPUT_ENABLE_SHIFT 12u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_OUTPUT_ENABLE_MASK  0x1000u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_OUTPUT_ENABLE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_OUTPUT_ENABLE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_OUTPUT_ENABLE_SHIFT 13u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_OUTPUT_ENABLE_MASK  0x2000u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_OUTPUT_ENABLE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_OUTPUT_ENABLE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_OUTPUT_SHIFT 14u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_OUTPUT_MASK  0x4000u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_OUTPUT(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_0_OUTPUT(__val__)  (((__val__) << 14u) & 0x4000u)
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_OUTPUT_SHIFT 15u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_OUTPUT_MASK  0x8000u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_OUTPUT(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_1_OUTPUT(__val__)  (((__val__) << 15u) & 0x8000u)
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_OUTPUT_SHIFT 16u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_OUTPUT_MASK  0x10000u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_OUTPUT(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_GPIO_2_OUTPUT(__val__)  (((__val__) << 16u) & 0x10000u)
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_AUTO_SEEPROM_ACCESS_SHIFT 24u
#define     DEVICE_MISCELLANEOUS_LOCAL_CONTROL_AUTO_SEEPROM_ACCESS_MASK  0x1000000u
#define GET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_AUTO_SEEPROM_ACCESS(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_DEVICE_MISCELLANEOUS_LOCAL_CONTROL_AUTO_SEEPROM_ACCESS(__val__)  (((__val__) << 24u) & 0x1000000u)

/** @brief Register definition for @ref DEVICE_t.MiscellaneousLocalControl. */
typedef register_container RegDEVICEMiscellaneousLocalControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_7_0, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO0Input, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO1Input, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO2Input, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO0OutputEnable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO1OutputEnable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO2OutputEnable, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO0Output, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO1Output, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO2Output, 16, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_23_17, 17, 7)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AutoSEEPROMAccess, 24, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_25, 25, 7)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_25, 25, 7)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, AutoSEEPROMAccess, 24, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_23_17, 17, 7)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO2Output, 16, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO1Output, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO0Output, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO2OutputEnable, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO1OutputEnable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO0OutputEnable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO2Input, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO1Input, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, GPIO0Input, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_7_0, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MiscellaneousLocalControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMiscellaneousLocalControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.MiscellaneousLocalControl. */
        r32.setName("MiscellaneousLocalControl");
        bits.GPIO0Input.setBaseRegister(&r32);
        bits.GPIO0Input.setName("GPIO0Input");
        bits.GPIO1Input.setBaseRegister(&r32);
        bits.GPIO1Input.setName("GPIO1Input");
        bits.GPIO2Input.setBaseRegister(&r32);
        bits.GPIO2Input.setName("GPIO2Input");
        bits.GPIO0OutputEnable.setBaseRegister(&r32);
        bits.GPIO0OutputEnable.setName("GPIO0OutputEnable");
        bits.GPIO1OutputEnable.setBaseRegister(&r32);
        bits.GPIO1OutputEnable.setName("GPIO1OutputEnable");
        bits.GPIO2OutputEnable.setBaseRegister(&r32);
        bits.GPIO2OutputEnable.setName("GPIO2OutputEnable");
        bits.GPIO0Output.setBaseRegister(&r32);
        bits.GPIO0Output.setName("GPIO0Output");
        bits.GPIO1Output.setBaseRegister(&r32);
        bits.GPIO1Output.setName("GPIO1Output");
        bits.GPIO2Output.setBaseRegister(&r32);
        bits.GPIO2Output.setName("GPIO2Output");
        bits.AutoSEEPROMAccess.setBaseRegister(&r32);
        bits.AutoSEEPROMAccess.setName("AutoSEEPROMAccess");
    }
    RegDEVICEMiscellaneousLocalControl_t& operator=(const RegDEVICEMiscellaneousLocalControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMiscellaneousLocalControl_t;

#define REG_DEVICE_TIMER ((volatile APE_DEVICE_H_uint32_t*)0xa004680c) /* 32-bit free-running counter */
/** @brief Register definition for @ref DEVICE_t.Timer. */
typedef register_container RegDEVICETimer_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Timer"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICETimer_t()
    {
        /** @brief constructor for @ref DEVICE_t.Timer. */
        r32.setName("Timer");
    }
    RegDEVICETimer_t& operator=(const RegDEVICETimer_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICETimer_t;

#define REG_DEVICE_RX_CPU_EVENT ((volatile APE_DEVICE_H_uint32_t*)0xa0046810) /*  */
#define     DEVICE_RX_CPU_EVENT_MAC_ATTENTION_SHIFT 25u
#define     DEVICE_RX_CPU_EVENT_MAC_ATTENTION_MASK  0x2000000u
#define GET_DEVICE_RX_CPU_EVENT_MAC_ATTENTION(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_DEVICE_RX_CPU_EVENT_MAC_ATTENTION(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     DEVICE_RX_CPU_EVENT_RX_CPU_ATTENTION_SHIFT 26u
#define     DEVICE_RX_CPU_EVENT_RX_CPU_ATTENTION_MASK  0x4000000u
#define GET_DEVICE_RX_CPU_EVENT_RX_CPU_ATTENTION(__reg__)  (((__reg__) & 0x4000000) >> 26u)
#define SET_DEVICE_RX_CPU_EVENT_RX_CPU_ATTENTION(__val__)  (((__val__) << 26u) & 0x4000000u)
#define     DEVICE_RX_CPU_EVENT_TIMER_SHIFT 29u
#define     DEVICE_RX_CPU_EVENT_TIMER_MASK  0x20000000u
#define GET_DEVICE_RX_CPU_EVENT_TIMER(__reg__)  (((__reg__) & 0x20000000) >> 29u)
#define SET_DEVICE_RX_CPU_EVENT_TIMER(__val__)  (((__val__) << 29u) & 0x20000000u)
#define     DEVICE_RX_CPU_EVENT_VPD_ATTENTION_SHIFT 30u
#define     DEVICE_RX_CPU_EVENT_VPD_ATTENTION_MASK  0x40000000u
#define GET_DEVICE_RX_CPU_EVENT_VPD_ATTENTION(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_DEVICE_RX_CPU_EVENT_VPD_ATTENTION(__val__)  (((__val__) << 30u) & 0x40000000u)

/** @brief Register definition for @ref DEVICE_t.RxCpuEvent. */
typedef register_container RegDEVICERxCpuEvent_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_24_0, 0, 25)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACAttention, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXCPUAttention, 26, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_28_27, 27, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Timer, 29, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VPDAttention, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VPDAttention, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Timer, 29, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_28_27, 27, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, RXCPUAttention, 26, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, MACAttention, 25, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_24_0, 0, 25)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxCpuEvent"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxCpuEvent_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxCpuEvent. */
        r32.setName("RxCpuEvent");
        bits.MACAttention.setBaseRegister(&r32);
        bits.MACAttention.setName("MACAttention");
        bits.RXCPUAttention.setBaseRegister(&r32);
        bits.RXCPUAttention.setName("RXCPUAttention");
        bits.Timer.setBaseRegister(&r32);
        bits.Timer.setName("Timer");
        bits.VPDAttention.setBaseRegister(&r32);
        bits.VPDAttention.setName("VPDAttention");
    }
    RegDEVICERxCpuEvent_t& operator=(const RegDEVICERxCpuEvent_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxCpuEvent_t;

#define REG_DEVICE_6838 ((volatile APE_DEVICE_H_uint32_t*)0xa0046838) /* Unknown. Used by PXE agent. */
/** @brief Register definition for @ref DEVICE_t.6838. */
typedef register_container RegDEVICE6838_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "6838"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE6838_t()
    {
        /** @brief constructor for @ref DEVICE_t.6838. */
        r32.setName("6838");
    }
    RegDEVICE6838_t& operator=(const RegDEVICE6838_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE6838_t;

#define REG_DEVICE_MDI_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa0046844) /* The register manual only mentions this in the changelog; it was removed from the manual in a previous revision. :| */
/** @brief Register definition for @ref DEVICE_t.MdiControl. */
typedef register_container RegDEVICEMdiControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MdiControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEMdiControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.MdiControl. */
        r32.setName("MdiControl");
    }
    RegDEVICEMdiControl_t& operator=(const RegDEVICEMdiControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEMdiControl_t;

#define REG_DEVICE_RX_CPU_EVENT_ENABLE ((volatile APE_DEVICE_H_uint32_t*)0xa004684c) /*  */
#define     DEVICE_RX_CPU_EVENT_ENABLE_VPD_ATTENTION_SHIFT 30u
#define     DEVICE_RX_CPU_EVENT_ENABLE_VPD_ATTENTION_MASK  0x40000000u
#define GET_DEVICE_RX_CPU_EVENT_ENABLE_VPD_ATTENTION(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_DEVICE_RX_CPU_EVENT_ENABLE_VPD_ATTENTION(__val__)  (((__val__) << 30u) & 0x40000000u)

/** @brief Register definition for @ref DEVICE_t.RxCpuEventEnable. */
typedef register_container RegDEVICERxCpuEventEnable_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_29_0, 0, 30)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VPDAttention, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, VPDAttention, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_29_0, 0, 30)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxCpuEventEnable"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICERxCpuEventEnable_t()
    {
        /** @brief constructor for @ref DEVICE_t.RxCpuEventEnable. */
        r32.setName("RxCpuEventEnable");
        bits.VPDAttention.setBaseRegister(&r32);
        bits.VPDAttention.setName("VPDAttention");
    }
    RegDEVICERxCpuEventEnable_t& operator=(const RegDEVICERxCpuEventEnable_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICERxCpuEventEnable_t;

#define REG_DEVICE_FAST_BOOT_PROGRAM_COUNTER ((volatile APE_DEVICE_H_uint32_t*)0xa0046894) /*  */
#define     DEVICE_FAST_BOOT_PROGRAM_COUNTER_PROGRAM_COUNTER_SHIFT 0u
#define     DEVICE_FAST_BOOT_PROGRAM_COUNTER_PROGRAM_COUNTER_MASK  0x7fffffffu
#define GET_DEVICE_FAST_BOOT_PROGRAM_COUNTER_PROGRAM_COUNTER(__reg__)  (((__reg__) & 0x7fffffff) >> 0u)
#define SET_DEVICE_FAST_BOOT_PROGRAM_COUNTER_PROGRAM_COUNTER(__val__)  (((__val__) << 0u) & 0x7fffffffu)
#define     DEVICE_FAST_BOOT_PROGRAM_COUNTER_ENABLE_SHIFT 31u
#define     DEVICE_FAST_BOOT_PROGRAM_COUNTER_ENABLE_MASK  0x80000000u
#define GET_DEVICE_FAST_BOOT_PROGRAM_COUNTER_ENABLE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_DEVICE_FAST_BOOT_PROGRAM_COUNTER_ENABLE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref DEVICE_t.FastBootProgramCounter. */
typedef register_container RegDEVICEFastBootProgramCounter_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief This field is used by the CPU to keep track of the location of the phase 1 boot code in RX MBUF. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ProgramCounter, 0, 31)
        /** @brief This bit is used by the CPU to keep track of whether or not there is valid phase 1 boot code stored in the RX MBUF. If the bit is set, then RXMBUF contains valid boot code. Otherwise, it is assumed that RXMBUF does not contain valid boot code. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Enable, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief This bit is used by the CPU to keep track of whether or not there is valid phase 1 boot code stored in the RX MBUF. If the bit is set, then RXMBUF contains valid boot code. Otherwise, it is assumed that RXMBUF does not contain valid boot code. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, Enable, 31, 1)
        /** @brief This field is used by the CPU to keep track of the location of the phase 1 boot code in RX MBUF. */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, ProgramCounter, 0, 31)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FastBootProgramCounter"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEFastBootProgramCounter_t()
    {
        /** @brief constructor for @ref DEVICE_t.FastBootProgramCounter. */
        r32.setName("FastBootProgramCounter");
        bits.ProgramCounter.setBaseRegister(&r32);
        bits.ProgramCounter.setName("ProgramCounter");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
    }
    RegDEVICEFastBootProgramCounter_t& operator=(const RegDEVICEFastBootProgramCounter_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEFastBootProgramCounter_t;

#define REG_DEVICE_EXPANSION_ROM_ADDR ((volatile APE_DEVICE_H_uint32_t*)0xa00468ec) /* Expansion ROM base address, expect to be d- word aligned. */
/** @brief Register definition for @ref DEVICE_t.ExpansionRomAddr. */
typedef register_container RegDEVICEExpansionRomAddr_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ExpansionRomAddr"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEExpansionRomAddr_t()
    {
        /** @brief constructor for @ref DEVICE_t.ExpansionRomAddr. */
        r32.setName("ExpansionRomAddr");
    }
    RegDEVICEExpansionRomAddr_t& operator=(const RegDEVICEExpansionRomAddr_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEExpansionRomAddr_t;

#define REG_DEVICE_68F0 ((volatile APE_DEVICE_H_uint32_t*)0xa00468f0) /*  */
/** @brief Register definition for @ref DEVICE_t.68f0. */
typedef register_container RegDEVICE68f0_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "68f0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE68f0_t()
    {
        /** @brief constructor for @ref DEVICE_t.68f0. */
        r32.setName("68f0");
    }
    RegDEVICE68f0_t& operator=(const RegDEVICE68f0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE68f0_t;

#define REG_DEVICE_EAV_REF_CLOCK_CONTROL ((volatile APE_DEVICE_H_uint32_t*)0xa0046908) /*  */
#define     DEVICE_EAV_REF_CLOCK_CONTROL_TIMESYNC_GPIO_MAPPING_SHIFT 16u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_TIMESYNC_GPIO_MAPPING_MASK  0x30000u
#define GET_DEVICE_EAV_REF_CLOCK_CONTROL_TIMESYNC_GPIO_MAPPING(__reg__)  (((__reg__) & 0x30000) >> 16u)
#define SET_DEVICE_EAV_REF_CLOCK_CONTROL_TIMESYNC_GPIO_MAPPING(__val__)  (((__val__) << 16u) & 0x30000u)
#define     DEVICE_EAV_REF_CLOCK_CONTROL_TIMESYNC_GPIO_MAPPING_SNAP_SHOT_0_ 0x0u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_TIMESYNC_GPIO_MAPPING_SNAP_SHOT_1_ 0x1u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_TIMESYNC_GPIO_MAPPING_TIME_WATCHDOG_0_ 0x2u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_TIMESYNC_GPIO_MAPPING_TIME_WATCHDOG_1_ 0x3u

#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_0_MAPPING_SHIFT 18u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_0_MAPPING_MASK  0x1c0000u
#define GET_DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_0_MAPPING(__reg__)  (((__reg__) & 0x1c0000) >> 18u)
#define SET_DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_0_MAPPING(__val__)  (((__val__) << 18u) & 0x1c0000u)
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_0_MAPPING_NOT_USED 0x0u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_0_MAPPING_SNAP_SHOT_0_ 0x4u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_0_MAPPING_SNAP_SHOT_1_ 0x5u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_0_MAPPING_TIME_WATCHDOG_0_ 0x6u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_0_MAPPING_TIME_WATCHDOG_1_ 0x7u

#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_1_MAPPING_SHIFT 21u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_1_MAPPING_MASK  0xe00000u
#define GET_DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_1_MAPPING(__reg__)  (((__reg__) & 0xe00000) >> 21u)
#define SET_DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_1_MAPPING(__val__)  (((__val__) << 21u) & 0xe00000u)
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_1_MAPPING_NOT_USED 0x0u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_1_MAPPING_SNAP_SHOT_0_ 0x4u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_1_MAPPING_SNAP_SHOT_1_ 0x5u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_1_MAPPING_TIME_WATCHDOG_0_ 0x6u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_1_MAPPING_TIME_WATCHDOG_1_ 0x7u

#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_2_MAPPING_SHIFT 24u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_2_MAPPING_MASK  0x7000000u
#define GET_DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_2_MAPPING(__reg__)  (((__reg__) & 0x7000000) >> 24u)
#define SET_DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_2_MAPPING(__val__)  (((__val__) << 24u) & 0x7000000u)
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_2_MAPPING_NOT_USED 0x0u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_2_MAPPING_SNAP_SHOT_0_ 0x4u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_2_MAPPING_SNAP_SHOT_1_ 0x5u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_2_MAPPING_TIME_WATCHDOG_0_ 0x6u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_2_MAPPING_TIME_WATCHDOG_1_ 0x7u

#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_3_MAPPING_SHIFT 27u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_3_MAPPING_MASK  0x38000000u
#define GET_DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_3_MAPPING(__reg__)  (((__reg__) & 0x38000000) >> 27u)
#define SET_DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_3_MAPPING(__val__)  (((__val__) << 27u) & 0x38000000u)
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_3_MAPPING_NOT_USED 0x0u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_3_MAPPING_SNAP_SHOT_0_ 0x4u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_3_MAPPING_SNAP_SHOT_1_ 0x5u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_3_MAPPING_TIME_WATCHDOG_0_ 0x6u
#define     DEVICE_EAV_REF_CLOCK_CONTROL_APE_GPIO_3_MAPPING_TIME_WATCHDOG_1_ 0x7u


/** @brief Register definition for @ref DEVICE_t.EavRefClockControl. */
typedef register_container RegDEVICEEavRefClockControl_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEVICE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief The MAC/Port dedicated TimeSync_GPIO pin is mapped via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TimesyncGPIOMapping, 16, 2)
        /** @brief APE_GPIO[0] pin is mapped to 1588 input/ output via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEGPIO0Mapping, 18, 3)
        /** @brief APE_GPIO[1] pin is mapped to 1588 input/ output via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEGPIO1Mapping, 21, 3)
        /** @brief APE_GPIO[2] pin is mapped to 1588 input/ output via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEGPIO2Mapping, 24, 3)
        /** @brief APE_GPIO[3] pin is mapped to 1588 input/ output via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEGPIO3Mapping, 27, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_30, 30, 2)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_31_30, 30, 2)
        /** @brief APE_GPIO[3] pin is mapped to 1588 input/ output via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEGPIO3Mapping, 27, 3)
        /** @brief APE_GPIO[2] pin is mapped to 1588 input/ output via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEGPIO2Mapping, 24, 3)
        /** @brief APE_GPIO[1] pin is mapped to 1588 input/ output via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEGPIO1Mapping, 21, 3)
        /** @brief APE_GPIO[0] pin is mapped to 1588 input/ output via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, APEGPIO0Mapping, 18, 3)
        /** @brief The MAC/Port dedicated TimeSync_GPIO pin is mapped via this field */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, TimesyncGPIOMapping, 16, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_DEVICE_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEVICE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EavRefClockControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICEEavRefClockControl_t()
    {
        /** @brief constructor for @ref DEVICE_t.EavRefClockControl. */
        r32.setName("EavRefClockControl");
        bits.TimesyncGPIOMapping.setBaseRegister(&r32);
        bits.TimesyncGPIOMapping.setName("TimesyncGPIOMapping");
        bits.APEGPIO0Mapping.setBaseRegister(&r32);
        bits.APEGPIO0Mapping.setName("APEGPIO0Mapping");
        bits.APEGPIO1Mapping.setBaseRegister(&r32);
        bits.APEGPIO1Mapping.setName("APEGPIO1Mapping");
        bits.APEGPIO2Mapping.setBaseRegister(&r32);
        bits.APEGPIO2Mapping.setName("APEGPIO2Mapping");
        bits.APEGPIO3Mapping.setBaseRegister(&r32);
        bits.APEGPIO3Mapping.setName("APEGPIO3Mapping");
    }
    RegDEVICEEavRefClockControl_t& operator=(const RegDEVICEEavRefClockControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICEEavRefClockControl_t;

#define REG_DEVICE_7C04 ((volatile APE_DEVICE_H_uint32_t*)0xa0047c04) /* PCIe-related. tg3 driver calls this  */
/** @brief Register definition for @ref DEVICE_t.7c04. */
typedef register_container RegDEVICE7c04_t {
    /** @brief 32bit direct register access. */
    APE_DEVICE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "7c04"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEVICE7c04_t()
    {
        /** @brief constructor for @ref DEVICE_t.7c04. */
        r32.setName("7c04");
    }
    RegDEVICE7c04_t& operator=(const RegDEVICE7c04_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEVICE7c04_t;

/** @brief Component definition for @ref DEVICE. */
typedef struct DEVICE_t {
    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_0[26];

    /** @brief  */
    RegDEVICEMiscellaneousHostControl_t MiscellaneousHostControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_108[1];

    /** @brief  */
    RegDEVICEPciState_t PciState;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_116[1];

    /** @brief Local controller memory address of a register than can be written or read by writing to the register data register. */
    RegDEVICERegisterBase_t RegisterBase;

    /** @brief Local controller memory address of the NIC memory region that can be accessed via Memory Window data register. */
    RegDEVICEMemoryBase_t MemoryBase;

    /** @brief Register Data at the location pointed by the Register Base Register. */
    RegDEVICERegisterData_t RegisterData;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_132[1];

    /** @brief UNDI Receive Return Ring Consumer Index Mailbox */
    RegDEVICEUndiReceiveReturnRingConsumerIndex_t UndiReceiveReturnRingConsumerIndex;

    /** @brief UNDI Receive Return Ring Consumer Index Mailbox */
    RegDEVICEUndiReceiveReturnRingConsumerIndexLow_t UndiReceiveReturnRingConsumerIndexLow;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_144[11];

    /** @brief PCIe standard register. */
    RegDEVICELinkStatusControl_t LinkStatusControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_192[14];

    /** @brief APE Memory address to read/write using the APE Memory Data register.. */
    RegDEVICEApeMemoryBase_t ApeMemoryBase;

    /** @brief APE Memory value at the location pointed by the Memory Base Register. */
    RegDEVICEApeMemoryData_t ApeMemoryData;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_256[192];

    /** @brief  */
    RegDEVICEEmacMode_t EmacMode;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_1028[2];

    /** @brief  */
    RegDEVICELedControl_t LedControl;

    /** @brief Upper 2-bytes of this node's MAC address. */
    RegDEVICEEmacMacAddresses0High_t EmacMacAddresses0High;

    /** @brief Lower 4-byte of this node's MAC address. */
    RegDEVICEEmacMacAddresses0Low_t EmacMacAddresses0Low;

    /** @brief Upper 2-bytes of this node's MAC address. */
    RegDEVICEEmacMacAddresses1High_t EmacMacAddresses1High;

    /** @brief Lower 4-byte of this node's MAC address. */
    RegDEVICEEmacMacAddresses1Low_t EmacMacAddresses1Low;

    /** @brief Upper 2-bytes of this node's MAC address. */
    RegDEVICEEmacMacAddresses2High_t EmacMacAddresses2High;

    /** @brief Lower 4-byte of this node's MAC address. */
    RegDEVICEEmacMacAddresses2Low_t EmacMacAddresses2Low;

    /** @brief Upper 2-bytes of this node's MAC address. */
    RegDEVICEEmacMacAddresses3High_t EmacMacAddresses3High;

    /** @brief Lower 4-byte of this node's MAC address. */
    RegDEVICEEmacMacAddresses3Low_t EmacMacAddresses3Low;

    /** @brief Specifies the offset into the 6KB BD memory for frame comparison. (Bits 3:0 are ignored to align the memory address to a natural 128-bit boundary). */
    RegDEVICEWolPatternPointer_t WolPatternPointer;

    /** @brief  */
    RegDEVICEWolPatternCfg_t WolPatternCfg;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_1080[1];

    /** @brief 2-byte field which is the largest size frame that will be accepted without being marked as oversize. */
    RegDEVICEMtuSize_t MtuSize;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_1088[3];

    /** @brief  */
    RegDEVICEMiiCommunication_t MiiCommunication;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_1104[1];

    /** @brief  */
    RegDEVICEMiiMode_t MiiMode;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_1112[1];

    /** @brief  */
    RegDEVICETransmitMacMode_t TransmitMacMode;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_1120[2];

    /** @brief  */
    RegDEVICEReceiveMacMode_t ReceiveMacMode;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_1132[53];

    /** @brief  */
    RegDEVICEPerfectMatch1High_t PerfectMatch1High;

    /** @brief  */
    RegDEVICEPerfectMatch1Low_t PerfectMatch1Low;

    /** @brief  */
    RegDEVICEPerfectMatch2High_t PerfectMatch2High;

    /** @brief  */
    RegDEVICEPerfectMatch2Low_t PerfectMatch2Low;

    /** @brief  */
    RegDEVICEPerfectMatch3High_t PerfectMatch3High;

    /** @brief  */
    RegDEVICEPerfectMatch3Low_t PerfectMatch3Low;

    /** @brief  */
    RegDEVICEPerfectMatch4High_t PerfectMatch4High;

    /** @brief  */
    RegDEVICEPerfectMatch4Low_t PerfectMatch4Low;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_1376[21];

    /** @brief This register reflects various status of the respective SGMII port when enabled. */
    RegDEVICESgmiiStatus_t SgmiiStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_1464[3090];

    /** @brief  */
    RegDEVICECpmuControl_t CpmuControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_13828[3];

    /** @brief  */
    RegDEVICELinkAwarePowerModeClockPolicy_t LinkAwarePowerModeClockPolicy;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_13844[4];

    /** @brief  */
    RegDEVICEClockSpeedOverridePolicy_t ClockSpeedOverridePolicy;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_13864[1];

    /** @brief  */
    RegDEVICEStatus_t Status;

    /** @brief  */
    RegDEVICEClockStatus_t ClockStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_13876[1];

    /** @brief  */
    RegDEVICEGphyControlStatus_t GphyControlStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_13884[7];

    /** @brief  */
    RegDEVICEChipId_t ChipId;

    /** @brief Writing a 1 to any of these bits pends a Mutex lock request on behalf of a software agent. The bit is subsequently latched by hardware and shall read 1 as long as the request is pending. Writing a 0 to a bit shall have no effect. */
    RegDEVICEMutexRequest_t MutexRequest;

    /** @brief Reading this field shall return a maximum of one set bit at any time. The set bit shall point to the lock owner. If the Mutex is not locked, then a read shall return a value 0x0000. Writing a 1 to the already set bit shall relinquish the lock and the set bit shall be cleared. Writing a 1 to an unset bit shall cancel the corresponding pending request if there was one, and the pairing bit in the Mutex_Request_Reg shall be cleared. */
    RegDEVICEMutexGrant_t MutexGrant;

    /** @brief  */
    RegDEVICEGphyStrap_t GphyStrap;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_13928[5];

    /** @brief  */
    RegDEVICETopLevelMiscellaneousControl1_t TopLevelMiscellaneousControl1;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_13952[12];

    /** @brief  */
    RegDEVICEEeeMode_t EeeMode;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_14004[2];

    /** @brief  */
    RegDEVICEEeeLinkIdleControl_t EeeLinkIdleControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_14016[4];

    /** @brief  */
    RegDEVICEEeeControl_t EeeControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_14036[7];

    /** @brief  */
    RegDEVICEGlobalMutexRequest_t GlobalMutexRequest;

    /** @brief  */
    RegDEVICEGlobalMutexGrant_t GlobalMutexGrant;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_14072[578];

    /** @brief  */
    RegDEVICEMemoryArbiterMode_t MemoryArbiterMode;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_16388[255];

    /** @brief  */
    RegDEVICEBufferManagerMode_t BufferManagerMode;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_17412[323];

    /** @brief  */
    RegDEVICELsoNonlsoBdReadDmaCorruptionEnableControl_t LsoNonlsoBdReadDmaCorruptionEnableControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_18708[443];

    /** @brief  */
    RegDEVICERxRiscMode_t RxRiscMode;

    /** @brief  */
    RegDEVICERxRiscStatus_t RxRiscStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_20488[5];

    /** @brief The program counter register can be used to read or write the current Program Counter of the each CPU. Reads can occur at any time, however writes can only be performed when the CPU is halted. Writes will also clear any pending instruction in the decode stage of the pipeline. Bits 31-2 are implemented. 1s written to bits 1-0 are ignored. */
    RegDEVICERxRiscProgramCounter_t RxRiscProgramCounter;

    /** @brief This undocumented register contains the current word located at the program counter address loaded in  */
    RegDEVICERxRiscCurrentInstruction_t RxRiscCurrentInstruction;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_20516[4];

    /** @brief This register is used to set a hardware breakpoint based on the RISC's program counter (PC). If the PC equals the value in this register, and the hardware breakpoint is enabled, the RISC is halted and the appropriate stopping condition is indicated in the RISC State Register. To enable the hardware breakpoint, simply write the byte address of the instruction to break on and clear the Disable Hardware Breakpoint bit. */
    RegDEVICERxRiscHardwareBreakpoint_t RxRiscHardwareBreakpoint;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_20536[114];

    /** @brief $zero (R0) */
    RegDEVICERxRiscRegister0_t RxRiscRegister0;

    /** @brief $at (R1) */
    RegDEVICERxRiscRegister1_t RxRiscRegister1;

    /** @brief $v0 (R2) */
    RegDEVICERxRiscRegister2_t RxRiscRegister2;

    /** @brief $v1 (R3) */
    RegDEVICERxRiscRegister3_t RxRiscRegister3;

    /** @brief $a0 (R4) */
    RegDEVICERxRiscRegister4_t RxRiscRegister4;

    /** @brief $a1 (R5) */
    RegDEVICERxRiscRegister5_t RxRiscRegister5;

    /** @brief $a2 (R6) */
    RegDEVICERxRiscRegister6_t RxRiscRegister6;

    /** @brief $a3 (R7) */
    RegDEVICERxRiscRegister7_t RxRiscRegister7;

    /** @brief $t0 (R8) */
    RegDEVICERxRiscRegister8_t RxRiscRegister8;

    /** @brief $t1 (R9) */
    RegDEVICERxRiscRegister9_t RxRiscRegister9;

    /** @brief $t2 (R10) */
    RegDEVICERxRiscRegister10_t RxRiscRegister10;

    /** @brief $t3 (R11) */
    RegDEVICERxRiscRegister11_t RxRiscRegister11;

    /** @brief $t4 (R12) */
    RegDEVICERxRiscRegister12_t RxRiscRegister12;

    /** @brief $t5 (R13) */
    RegDEVICERxRiscRegister13_t RxRiscRegister13;

    /** @brief $t6 (R14) */
    RegDEVICERxRiscRegister14_t RxRiscRegister14;

    /** @brief $t7 (R15) */
    RegDEVICERxRiscRegister15_t RxRiscRegister15;

    /** @brief $s0 (R16) */
    RegDEVICERxRiscRegister16_t RxRiscRegister16;

    /** @brief $s1 (R17) */
    RegDEVICERxRiscRegister17_t RxRiscRegister17;

    /** @brief $s2 (R18) */
    RegDEVICERxRiscRegister18_t RxRiscRegister18;

    /** @brief $s3 (R19) */
    RegDEVICERxRiscRegister19_t RxRiscRegister19;

    /** @brief $s4 (R20) */
    RegDEVICERxRiscRegister20_t RxRiscRegister20;

    /** @brief $s5 (R21) */
    RegDEVICERxRiscRegister21_t RxRiscRegister21;

    /** @brief $s6 (R22) */
    RegDEVICERxRiscRegister22_t RxRiscRegister22;

    /** @brief $s7 (R23) */
    RegDEVICERxRiscRegister23_t RxRiscRegister23;

    /** @brief $t8 (R24) */
    RegDEVICERxRiscRegister24_t RxRiscRegister24;

    /** @brief $t9 (R25) */
    RegDEVICERxRiscRegister25_t RxRiscRegister25;

    /** @brief $k0 (R26) */
    RegDEVICERxRiscRegister26_t RxRiscRegister26;

    /** @brief $k1 (R27) */
    RegDEVICERxRiscRegister27_t RxRiscRegister27;

    /** @brief $gp (R28) */
    RegDEVICERxRiscRegister28_t RxRiscRegister28;

    /** @brief $sp (R29) */
    RegDEVICERxRiscRegister29_t RxRiscRegister29;

    /** @brief $fp (R30) */
    RegDEVICERxRiscRegister30_t RxRiscRegister30;

    /** @brief $ra (R31) */
    RegDEVICERxRiscRegister31_t RxRiscRegister31;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_21120[1122];

    /** @brief  */
    RegDEVICE6408_t _6408;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_25612[1];

    /** @brief This undocumented register is used to set PCIe Power Consumption information as reported in configuration space. It is loaded from NVM configuration data. */
    RegDEVICEPciPowerConsumptionInfo_t PciPowerConsumptionInfo;

    /** @brief This undocumented register is used to set PCIe Power Dissipated information as reported in configuration space. It is loaded from NVM configuration data. */
    RegDEVICEPciPowerDissipatedInfo_t PciPowerDissipatedInfo;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_25624[5];

    /** @brief This undocumented register appears to be used to implement the PCI VPD capability. It is set to the VPD offset which was requested by the host by writing to the VPD register. */
    RegDEVICEPciVpdRequest_t PciVpdRequest;

    /** @brief This undocumented register appears to be used to implement the PCI VPD capability. Bootcode writes the 32 bits of data loaded from the word requested by  */
    RegDEVICEPciVpdResponse_t PciVpdResponse;

    /** @brief This is the undocumented register used to set the PCI Vendor/Device ID, which is configurable from NVM. */
    RegDEVICEPciVendorDeviceId_t PciVendorDeviceId;

    /** @brief This is the undocumented register used to set the PCI Subsystem/Subsystem Vendor ID, which is configurable from NVM. */
    RegDEVICEPciSubsystemId_t PciSubsystemId;

    /** @brief This undocumented register is suspected to set the class code and device revision in PCI configuration space. Unconfirmed. */
    RegDEVICEPciClassCodeRevision_t PciClassCodeRevision;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_25664[32];

    /** @brief  */
    RegDEVICE64c0_t _64c0;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_25796[1];

    /** @brief  */
    RegDEVICE64c8_t _64c8;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_25804[4];

    /** @brief  */
    RegDEVICE64dc_t _64dc;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_25824[9];

    /** @brief This sets the low 32 bits of the 64-bit device serial number, which isexposed as a PCIe capability in configuration space. */
    RegDEVICEPciSerialNumberLow_t PciSerialNumberLow;

    /** @brief This sets the high 32 bits of the 64-bit device serial number, which isexposed as a PCIe capability in configuration space. */
    RegDEVICEPciSerialNumberHigh_t PciSerialNumberHigh;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_25868[1];

    /** @brief Used to report power budget capability data to the host. The values are loaded from NVM, and up to eight values may be specified.  */
    RegDEVICEPciPowerBudget0_t PciPowerBudget0;

    /** @brief See  */
    RegDEVICEPciPowerBudget1_t PciPowerBudget1;

    /** @brief See  */
    RegDEVICEPciPowerBudget2_t PciPowerBudget2;

    /** @brief See  */
    RegDEVICEPciPowerBudget3_t PciPowerBudget3;

    /** @brief See  */
    RegDEVICEPciPowerBudget4_t PciPowerBudget4;

    /** @brief See  */
    RegDEVICEPciPowerBudget5_t PciPowerBudget5;

    /** @brief See  */
    RegDEVICEPciPowerBudget6_t PciPowerBudget6;

    /** @brief See  */
    RegDEVICEPciPowerBudget7_t PciPowerBudget7;

    /** @brief  */
    RegDEVICE6530_t _6530;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_25908[7];

    /** @brief The LSB in this undocumented and unknown register is set if the device is a LOM (LAN-on-Motherboard) design (i.e., builtin to a system and not an expansion card). */
    RegDEVICE6550_t _6550;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_25940[40];

    /** @brief  */
    RegDEVICE65f4_t _65f4;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_26104[130];

    /** @brief  */
    RegDEVICEGrcModeControl_t GrcModeControl;

    /** @brief  */
    RegDEVICEMiscellaneousConfig_t MiscellaneousConfig;

    /** @brief  */
    RegDEVICEMiscellaneousLocalControl_t MiscellaneousLocalControl;

    /** @brief 32-bit free-running counter */
    RegDEVICETimer_t Timer;

    /** @brief  */
    RegDEVICERxCpuEvent_t RxCpuEvent;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_26644[9];

    /** @brief Unknown. Used by PXE agent. */
    RegDEVICE6838_t _6838;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_26684[2];

    /** @brief The register manual only mentions this in the changelog; it was removed from the manual in a previous revision. :| */
    RegDEVICEMdiControl_t MdiControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_26696[1];

    /** @brief  */
    RegDEVICERxCpuEventEnable_t RxCpuEventEnable;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_26704[17];

    /** @brief  */
    RegDEVICEFastBootProgramCounter_t FastBootProgramCounter;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_26776[21];

    /** @brief Expansion ROM base address, expect to be d- word aligned. */
    RegDEVICEExpansionRomAddr_t ExpansionRomAddr;

    /** @brief  */
    RegDEVICE68f0_t _68f0;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_26868[5];

    /** @brief  */
    RegDEVICEEavRefClockControl_t EavRefClockControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_DEVICE_H_uint32_t reserved_26892[1214];

    /** @brief PCIe-related. tg3 driver calls this  */
    RegDEVICE7c04_t _7c04;

#ifdef CXX_SIMULATOR
    DEVICE_t()
    {
        MiscellaneousHostControl.r32.setComponentOffset(0x68);
        PciState.r32.setComponentOffset(0x70);
        RegisterBase.r32.setComponentOffset(0x78);
        MemoryBase.r32.setComponentOffset(0x7c);
        RegisterData.r32.setComponentOffset(0x80);
        UndiReceiveReturnRingConsumerIndex.r32.setComponentOffset(0x88);
        UndiReceiveReturnRingConsumerIndexLow.r32.setComponentOffset(0x8c);
        LinkStatusControl.r32.setComponentOffset(0xbc);
        ApeMemoryBase.r32.setComponentOffset(0xf8);
        ApeMemoryData.r32.setComponentOffset(0xfc);
        EmacMode.r32.setComponentOffset(0x400);
        LedControl.r32.setComponentOffset(0x40c);
        EmacMacAddresses0High.r32.setComponentOffset(0x410);
        EmacMacAddresses0Low.r32.setComponentOffset(0x414);
        EmacMacAddresses1High.r32.setComponentOffset(0x418);
        EmacMacAddresses1Low.r32.setComponentOffset(0x41c);
        EmacMacAddresses2High.r32.setComponentOffset(0x420);
        EmacMacAddresses2Low.r32.setComponentOffset(0x424);
        EmacMacAddresses3High.r32.setComponentOffset(0x428);
        EmacMacAddresses3Low.r32.setComponentOffset(0x42c);
        WolPatternPointer.r32.setComponentOffset(0x430);
        WolPatternCfg.r32.setComponentOffset(0x434);
        MtuSize.r32.setComponentOffset(0x43c);
        MiiCommunication.r32.setComponentOffset(0x44c);
        MiiMode.r32.setComponentOffset(0x454);
        TransmitMacMode.r32.setComponentOffset(0x45c);
        ReceiveMacMode.r32.setComponentOffset(0x468);
        PerfectMatch1High.r32.setComponentOffset(0x540);
        PerfectMatch1Low.r32.setComponentOffset(0x544);
        PerfectMatch2High.r32.setComponentOffset(0x548);
        PerfectMatch2Low.r32.setComponentOffset(0x54c);
        PerfectMatch3High.r32.setComponentOffset(0x550);
        PerfectMatch3Low.r32.setComponentOffset(0x554);
        PerfectMatch4High.r32.setComponentOffset(0x558);
        PerfectMatch4Low.r32.setComponentOffset(0x55c);
        SgmiiStatus.r32.setComponentOffset(0x5b4);
        CpmuControl.r32.setComponentOffset(0x3600);
        LinkAwarePowerModeClockPolicy.r32.setComponentOffset(0x3610);
        ClockSpeedOverridePolicy.r32.setComponentOffset(0x3624);
        Status.r32.setComponentOffset(0x362c);
        ClockStatus.r32.setComponentOffset(0x3630);
        GphyControlStatus.r32.setComponentOffset(0x3638);
        ChipId.r32.setComponentOffset(0x3658);
        MutexRequest.r32.setComponentOffset(0x365c);
        MutexGrant.r32.setComponentOffset(0x3660);
        GphyStrap.r32.setComponentOffset(0x3664);
        TopLevelMiscellaneousControl1.r32.setComponentOffset(0x367c);
        EeeMode.r32.setComponentOffset(0x36b0);
        EeeLinkIdleControl.r32.setComponentOffset(0x36bc);
        EeeControl.r32.setComponentOffset(0x36d0);
        GlobalMutexRequest.r32.setComponentOffset(0x36f0);
        GlobalMutexGrant.r32.setComponentOffset(0x36f4);
        MemoryArbiterMode.r32.setComponentOffset(0x4000);
        BufferManagerMode.r32.setComponentOffset(0x4400);
        LsoNonlsoBdReadDmaCorruptionEnableControl.r32.setComponentOffset(0x4910);
        RxRiscMode.r32.setComponentOffset(0x5000);
        RxRiscStatus.r32.setComponentOffset(0x5004);
        RxRiscProgramCounter.r32.setComponentOffset(0x501c);
        RxRiscCurrentInstruction.r32.setComponentOffset(0x5020);
        RxRiscHardwareBreakpoint.r32.setComponentOffset(0x5034);
        RxRiscRegister0.r32.setComponentOffset(0x5200);
        RxRiscRegister1.r32.setComponentOffset(0x5204);
        RxRiscRegister2.r32.setComponentOffset(0x5208);
        RxRiscRegister3.r32.setComponentOffset(0x520c);
        RxRiscRegister4.r32.setComponentOffset(0x5210);
        RxRiscRegister5.r32.setComponentOffset(0x5214);
        RxRiscRegister6.r32.setComponentOffset(0x5218);
        RxRiscRegister7.r32.setComponentOffset(0x521c);
        RxRiscRegister8.r32.setComponentOffset(0x5220);
        RxRiscRegister9.r32.setComponentOffset(0x5224);
        RxRiscRegister10.r32.setComponentOffset(0x5228);
        RxRiscRegister11.r32.setComponentOffset(0x522c);
        RxRiscRegister12.r32.setComponentOffset(0x5230);
        RxRiscRegister13.r32.setComponentOffset(0x5234);
        RxRiscRegister14.r32.setComponentOffset(0x5238);
        RxRiscRegister15.r32.setComponentOffset(0x523c);
        RxRiscRegister16.r32.setComponentOffset(0x5240);
        RxRiscRegister17.r32.setComponentOffset(0x5244);
        RxRiscRegister18.r32.setComponentOffset(0x5248);
        RxRiscRegister19.r32.setComponentOffset(0x524c);
        RxRiscRegister20.r32.setComponentOffset(0x5250);
        RxRiscRegister21.r32.setComponentOffset(0x5254);
        RxRiscRegister22.r32.setComponentOffset(0x5258);
        RxRiscRegister23.r32.setComponentOffset(0x525c);
        RxRiscRegister24.r32.setComponentOffset(0x5260);
        RxRiscRegister25.r32.setComponentOffset(0x5264);
        RxRiscRegister26.r32.setComponentOffset(0x5268);
        RxRiscRegister27.r32.setComponentOffset(0x526c);
        RxRiscRegister28.r32.setComponentOffset(0x5270);
        RxRiscRegister29.r32.setComponentOffset(0x5274);
        RxRiscRegister30.r32.setComponentOffset(0x5278);
        RxRiscRegister31.r32.setComponentOffset(0x527c);
        _6408.r32.setComponentOffset(0x6408);
        PciPowerConsumptionInfo.r32.setComponentOffset(0x6410);
        PciPowerDissipatedInfo.r32.setComponentOffset(0x6414);
        PciVpdRequest.r32.setComponentOffset(0x642c);
        PciVpdResponse.r32.setComponentOffset(0x6430);
        PciVendorDeviceId.r32.setComponentOffset(0x6434);
        PciSubsystemId.r32.setComponentOffset(0x6438);
        PciClassCodeRevision.r32.setComponentOffset(0x643c);
        _64c0.r32.setComponentOffset(0x64c0);
        _64c8.r32.setComponentOffset(0x64c8);
        _64dc.r32.setComponentOffset(0x64dc);
        PciSerialNumberLow.r32.setComponentOffset(0x6504);
        PciSerialNumberHigh.r32.setComponentOffset(0x6508);
        PciPowerBudget0.r32.setComponentOffset(0x6510);
        PciPowerBudget1.r32.setComponentOffset(0x6514);
        PciPowerBudget2.r32.setComponentOffset(0x6518);
        PciPowerBudget3.r32.setComponentOffset(0x651c);
        PciPowerBudget4.r32.setComponentOffset(0x6520);
        PciPowerBudget5.r32.setComponentOffset(0x6524);
        PciPowerBudget6.r32.setComponentOffset(0x6528);
        PciPowerBudget7.r32.setComponentOffset(0x652c);
        _6530.r32.setComponentOffset(0x6530);
        _6550.r32.setComponentOffset(0x6550);
        _65f4.r32.setComponentOffset(0x65f4);
        GrcModeControl.r32.setComponentOffset(0x6800);
        MiscellaneousConfig.r32.setComponentOffset(0x6804);
        MiscellaneousLocalControl.r32.setComponentOffset(0x6808);
        Timer.r32.setComponentOffset(0x680c);
        RxCpuEvent.r32.setComponentOffset(0x6810);
        _6838.r32.setComponentOffset(0x6838);
        MdiControl.r32.setComponentOffset(0x6844);
        RxCpuEventEnable.r32.setComponentOffset(0x684c);
        FastBootProgramCounter.r32.setComponentOffset(0x6894);
        ExpansionRomAddr.r32.setComponentOffset(0x68ec);
        _68f0.r32.setComponentOffset(0x68f0);
        EavRefClockControl.r32.setComponentOffset(0x6908);
        _7c04.r32.setComponentOffset(0x7c04);
    }
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} DEVICE_t;

/** @brief Device Registers, function 0 */
extern volatile DEVICE_t DEVICE;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_DEVICE_H */

/** @} */
