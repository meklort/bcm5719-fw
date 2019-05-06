////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_SHM1.h
///
/// @project    ape
///
/// @brief      APE_SHM1
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

/** @defgroup APE_SHM1_H    APE_SHM1 */
/** @addtogroup APE_SHM1_H
 * @{
 */
#ifndef APE_SHM1_H
#define APE_SHM1_H

#include <stdint.h>
#include "APE_SHM.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_SHM1_sim(void* base);
void init_APE_SHM1(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_SHM1_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_SHM1_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_SHM1_H_uint32_t;
#define APE_SHM1_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_SHM1_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_SHM1_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_SHM1_H_uint8_t;
typedef uint16_t APE_SHM1_H_uint16_t;
typedef uint32_t APE_SHM1_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM1_BASE ((volatile void*)0x60221000) /* Device SHM Registers, function 1 */
#define REG_SHM1_SIZE (sizeof(SHM_t))

#define REG_SHM1_SEG_SIG ((volatile APE_SHM1_H_uint32_t*)0x60221000) /* APE_APE_MAGIC ('APE!') when all is well. */
#define     SHM1_SEG_SIG_SIG_SHIFT 0u
#define     SHM1_SEG_SIG_SIG_MASK  0xffffffffu
#define GET_SHM1_SEG_SIG_SIG(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_SHM1_SEG_SIG_SIG(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     SHM1_SEG_SIG_SIG_LOADER 0x10ad10adu


#define REG_SHM1_APE_SEG_LENGTH ((volatile APE_SHM1_H_uint32_t*)0x60221004) /* Set to 0x34. */
#define REG_SHM1_FW_STATUS ((volatile APE_SHM1_H_uint32_t*)0x6022100c) /*  */
#define     SHM1_FW_STATUS_READY_SHIFT 8u
#define     SHM1_FW_STATUS_READY_MASK  0x100u
#define GET_SHM1_FW_STATUS_READY(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_SHM1_FW_STATUS_READY(__val__)  (((__val__) << 8u) & 0x100u)
#define     SHM1_FW_STATUS_UNKNOWN_31_28_SHIFT 28u
#define     SHM1_FW_STATUS_UNKNOWN_31_28_MASK  0xf0000000u
#define GET_SHM1_FW_STATUS_UNKNOWN_31_28(__reg__)  (((__reg__) & 0xf0000000) >> 28u)
#define SET_SHM1_FW_STATUS_UNKNOWN_31_28(__val__)  (((__val__) << 28u) & 0xf0000000u)

#define REG_SHM1_FW_FEATURES ((volatile APE_SHM1_H_uint32_t*)0x60221010) /*  */
#define     SHM1_FW_FEATURES_NCSI_SHIFT 1u
#define     SHM1_FW_FEATURES_NCSI_MASK  0x2u
#define GET_SHM1_FW_FEATURES_NCSI(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM1_FW_FEATURES_NCSI(__val__)  (((__val__) << 1u) & 0x2u)

#define REG_SHM1_4014 ((volatile APE_SHM1_H_uint32_t*)0x60221014) /* Unknown. */
#define REG_SHM1_FW_VERSION ((volatile APE_SHM1_H_uint32_t*)0x60221018) /*  */
#define     SHM1_FW_VERSION_BUILD_SHIFT 0u
#define     SHM1_FW_VERSION_BUILD_MASK  0xffu
#define GET_SHM1_FW_VERSION_BUILD(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_SHM1_FW_VERSION_BUILD(__val__)  (((__val__) << 0u) & 0xffu)
#define     SHM1_FW_VERSION_REVISION_SHIFT 8u
#define     SHM1_FW_VERSION_REVISION_MASK  0xff00u
#define GET_SHM1_FW_VERSION_REVISION(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_SHM1_FW_VERSION_REVISION(__val__)  (((__val__) << 8u) & 0xff00u)
#define     SHM1_FW_VERSION_MINOR_SHIFT 16u
#define     SHM1_FW_VERSION_MINOR_MASK  0xff0000u
#define GET_SHM1_FW_VERSION_MINOR(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_SHM1_FW_VERSION_MINOR(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     SHM1_FW_VERSION_MAJOR_SHIFT 24u
#define     SHM1_FW_VERSION_MAJOR_MASK  0xff000000u
#define GET_SHM1_FW_VERSION_MAJOR(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_SHM1_FW_VERSION_MAJOR(__val__)  (((__val__) << 24u) & 0xff000000u)

#define REG_SHM1_SEG_MESSAGE_BUFFER_OFFSET ((volatile APE_SHM1_H_uint32_t*)0x6022101c) /* Specifies the offset of a scratchpad area, relative to the  start of the APE SHM area (i.e., relative to APE_REG(0x4000)). */
#define REG_SHM1_SEG_MESSAGE_BUFFER_LENGTH ((volatile APE_SHM1_H_uint32_t*)0x60221020) /* Specifies the size of the scratchpad area in bytes. */
#define REG_SHM1_4024 ((volatile APE_SHM1_H_uint32_t*)0x60221024) /* Unknown. Bootcode related. */
#define REG_SHM1_4028 ((volatile APE_SHM1_H_uint32_t*)0x60221028) /* Unknown. Bootcode related. */
#define REG_SHM1_LOADER_COMMAND ((volatile APE_SHM1_H_uint32_t*)0x60221038) /* Command sent when using the the APE loader. Zero once handled. */
#define     SHM1_LOADER_COMMAND_COMMAND_SHIFT 0u
#define     SHM1_LOADER_COMMAND_COMMAND_MASK  0xffffffffu
#define GET_SHM1_LOADER_COMMAND_COMMAND(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_SHM1_LOADER_COMMAND_COMMAND(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     SHM1_LOADER_COMMAND_COMMAND_NOP 0x0u
#define     SHM1_LOADER_COMMAND_COMMAND_READ_MEM 0x1u
#define     SHM1_LOADER_COMMAND_COMMAND_WRITE_MEM 0x2u
#define     SHM1_LOADER_COMMAND_COMMAND_CALL 0x3u


#define REG_SHM1_LOADER_ARG0 ((volatile APE_SHM1_H_uint32_t*)0x6022103c) /* Argument 0 for the APE loader. */
#define REG_SHM1_LOADER_ARG1 ((volatile APE_SHM1_H_uint32_t*)0x60221040) /* Argument 1 for the APE loader. */
#define REG_SHM1_RCPU_SEG_SIG ((volatile APE_SHM1_H_uint32_t*)0x60221100) /* Set to APE_RCPU_MAGIC ('RCPU') by RX CPU. */
#define     SHM1_RCPU_SEG_SIG_SIG_SHIFT 0u
#define     SHM1_RCPU_SEG_SIG_SIG_MASK  0xffffffffu
#define GET_SHM1_RCPU_SEG_SIG_SIG(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_SHM1_RCPU_SEG_SIG_SIG(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     SHM1_RCPU_SEG_SIG_SIG_RCPU_MAGIC 0x52435055u


#define REG_SHM1_RCPU_SEG_LENGTH ((volatile APE_SHM1_H_uint32_t*)0x60221104) /* Set to 0x34. */
#define REG_SHM1_RCPU_INIT_COUNT ((volatile APE_SHM1_H_uint32_t*)0x60221108) /* Incremented by RX CPU every boot. */
#define REG_SHM1_RCPU_FW_VERSION ((volatile APE_SHM1_H_uint32_t*)0x6022110c) /* Set to the bootcode version. e.g. 0x0127 -> v1.39. */
#define REG_SHM1_RCPU_CFG_FEATURE ((volatile APE_SHM1_H_uint32_t*)0x60221110) /* Set to  */
#define REG_SHM1_RCPU_PCI_VENDOR_DEVICE_ID ((volatile APE_SHM1_H_uint32_t*)0x60221114) /* Set to PCI Vendor/Device ID by S2. */
#define REG_SHM1_RCPU_PCI_SUBSYSTEM_ID ((volatile APE_SHM1_H_uint32_t*)0x60221118) /* Set to PCI Subsystem Vendor/Subsystem ID by S2. */
#define REG_SHM1_RCPU_APE_RESET_COUNT ((volatile APE_SHM1_H_uint32_t*)0x6022111c) /* Unknown. Incremented by frobnicating routine. */
#define REG_SHM1_RCPU_LAST_APE_STATUS ((volatile APE_SHM1_H_uint32_t*)0x60221120) /* Unknown. Written by frobnicating routine. */
#define REG_SHM1_RCPU_LAST_APE_FW_STATUS ((volatile APE_SHM1_H_uint32_t*)0x60221124) /* Unknown.  */
#define REG_SHM1_RCPU_CFG_HW ((volatile APE_SHM1_H_uint32_t*)0x60221128) /* Set from  */
#define REG_SHM1_RCPU_CFG_HW_2 ((volatile APE_SHM1_H_uint32_t*)0x6022112c) /* Set from  */
#define REG_SHM1_RCPU_CPMU_STATUS ((volatile APE_SHM1_H_uint32_t*)0x60221130) /* Set from  */
#define     SHM1_RCPU_CPMU_STATUS_ADDRESS_SHIFT 0u
#define     SHM1_RCPU_CPMU_STATUS_ADDRESS_MASK  0xffffu
#define GET_SHM1_RCPU_CPMU_STATUS_ADDRESS(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_SHM1_RCPU_CPMU_STATUS_ADDRESS(__val__)  (((__val__) << 0u) & 0xffffu)
#define     SHM1_RCPU_CPMU_STATUS_ADDRESS_ADDRESS 0x362cu

#define     SHM1_RCPU_CPMU_STATUS_STATUS_SHIFT 16u
#define     SHM1_RCPU_CPMU_STATUS_STATUS_MASK  0xffff0000u
#define GET_SHM1_RCPU_CPMU_STATUS_STATUS(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_SHM1_RCPU_CPMU_STATUS_STATUS(__val__)  (((__val__) << 16u) & 0xffff0000u)

#define REG_SHM1_HOST_SEG_SIG ((volatile APE_SHM1_H_uint32_t*)0x60221200) /* Set to APE_HOST_MAGIC ('HOST') to indicate the section is valid. */
#define REG_SHM1_HOST_SEG_LEN ((volatile APE_SHM1_H_uint32_t*)0x60221204) /* Set to 0x20. */
#define REG_SHM1_HOST_INIT_COUNT ((volatile APE_SHM1_H_uint32_t*)0x60221208) /* Incremented by host on every initialization. */
#define REG_SHM1_HOST_DRIVER_ID ((volatile APE_SHM1_H_uint32_t*)0x6022120c) /* Linux sets this to 0xF0MM_mm00, where M is the major version  of Linux and m is the minor version. */
#define REG_SHM1_HOST_BEHAVIOR ((volatile APE_SHM1_H_uint32_t*)0x60221210) /*  */
#define     SHM1_HOST_BEHAVIOR_NO_PHYLOCK_SHIFT 0u
#define     SHM1_HOST_BEHAVIOR_NO_PHYLOCK_MASK  0x1u
#define GET_SHM1_HOST_BEHAVIOR_NO_PHYLOCK(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM1_HOST_BEHAVIOR_NO_PHYLOCK(__val__)  (((__val__) << 0u) & 0x1u)

#define REG_SHM1_HEARTBEAT_INTERVAL ((volatile APE_SHM1_H_uint32_t*)0x60221214) /* In milliseconds. Set to 0 to disable heartbeating. */
#define REG_SHM1_HEARTBEAT_COUNT ((volatile APE_SHM1_H_uint32_t*)0x60221218) /*  */
#define REG_SHM1_HOST_DRIVER_STATE ((volatile APE_SHM1_H_uint32_t*)0x6022121c) /*  */
#define REG_SHM1_WOL_SPEED ((volatile APE_SHM1_H_uint32_t*)0x60221224) /*  */
#define REG_SHM1_EVENT_STATUS ((volatile APE_SHM1_H_uint32_t*)0x60221300) /*  */
#define     SHM1_EVENT_STATUS_DRIVER_EVENT_SHIFT 4u
#define     SHM1_EVENT_STATUS_DRIVER_EVENT_MASK  0x10u
#define GET_SHM1_EVENT_STATUS_DRIVER_EVENT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_SHM1_EVENT_STATUS_DRIVER_EVENT(__val__)  (((__val__) << 4u) & 0x10u)
#define     SHM1_EVENT_STATUS_COMMAND_SHIFT 8u
#define     SHM1_EVENT_STATUS_COMMAND_MASK  0xff00u
#define GET_SHM1_EVENT_STATUS_COMMAND(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_SHM1_EVENT_STATUS_COMMAND(__val__)  (((__val__) << 8u) & 0xff00u)
#define     SHM1_EVENT_STATUS_COMMAND_STATE_CHANGE 0x5u
#define     SHM1_EVENT_STATUS_COMMAND_SCRATCHPAD_READ 0x16u
#define     SHM1_EVENT_STATUS_COMMAND_SCRATCHPAD_WRITE 0x17u

#define     SHM1_EVENT_STATUS_STATE_SHIFT 16u
#define     SHM1_EVENT_STATUS_STATE_MASK  0x70000u
#define GET_SHM1_EVENT_STATUS_STATE(__reg__)  (((__reg__) & 0x70000) >> 16u)
#define SET_SHM1_EVENT_STATUS_STATE(__val__)  (((__val__) << 16u) & 0x70000u)
#define     SHM1_EVENT_STATUS_STATE_START 0x1u
#define     SHM1_EVENT_STATUS_STATE_UNLOAD 0x2u
#define     SHM1_EVENT_STATUS_STATE_WOL 0x3u
#define     SHM1_EVENT_STATUS_STATE_SUSPEND 0x4u

#define     SHM1_EVENT_STATUS_PENDING_SHIFT 31u
#define     SHM1_EVENT_STATUS_PENDING_MASK  0x80000000u
#define GET_SHM1_EVENT_STATUS_PENDING(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_SHM1_EVENT_STATUS_PENDING(__val__)  (((__val__) << 31u) & 0x80000000u)

#define REG_SHM1_PROT_MAGIC ((volatile APE_SHM1_H_uint32_t*)0x60221308) /* This is set to APE_PROT_MAGIC ('PROT') on all functions.  If it is 'PROT', the following fields (MAC0_HIGH/LOW) are valid */
#define REG_SHM1_PROT_MAC0_HIGH ((volatile APE_SHM1_H_uint32_t*)0x60221314) /* High 16 bits of MAC address 0. Only valid if  */
#define REG_SHM1_PROT_MAC0_LOW ((volatile APE_SHM1_H_uint32_t*)0x60221318) /* Low 16 bits of MAC address 0. */
#define REG_SHM1_NCSI_SIG ((volatile APE_SHM1_H_uint32_t*)0x60221800) /* Set to NCSI_MAGIC ('NCSI') by APE firmware. NOTE: all words in the NCSI section are available in the function 0 SHM area only. */
#define REG_SHM1_NCSI_BUILD_TIME ((volatile APE_SHM1_H_uint32_t*)0x60221810) /* ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
#define REG_SHM1_NCSI_BUILD_TIME_2 ((volatile APE_SHM1_H_uint32_t*)0x60221814) /*  */
#define REG_SHM1_NCSI_BUILD_TIME_3 ((volatile APE_SHM1_H_uint32_t*)0x60221818) /*  */
#define REG_SHM1_NCSI_BUILD_DATE ((volatile APE_SHM1_H_uint32_t*)0x6022181c) /* ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
#define REG_SHM1_NCSI_BUILD_DATE_2 ((volatile APE_SHM1_H_uint32_t*)0x60221820) /*  */
#define REG_SHM1_NCSI_BUILD_DATE_3 ((volatile APE_SHM1_H_uint32_t*)0x60221824) /*  */
#define REG_SHM1_CHIP_ID ((volatile APE_SHM1_H_uint32_t*)0x60221890) /* The APE code copies the contents of Chip ID to this word */
/** @brief Device SHM Registers, function 1 */
extern volatile SHM_t SHM1;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_SHM1_H */

/** @} */
