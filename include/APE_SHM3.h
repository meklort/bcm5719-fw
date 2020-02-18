////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_SHM3.h
///
/// @project    ape
///
/// @brief      APE_SHM3
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

/** @defgroup APE_SHM3_H    APE_SHM3 */
/** @addtogroup APE_SHM3_H
 * @{
 */
#ifndef APE_SHM3_H
#define APE_SHM3_H

#include <types.h>
#include "APE_SHM.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_SHM3_sim(void* base);
void init_APE_SHM3(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_SHM3_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_SHM3_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_SHM3_H_uint32_t;
#define APE_SHM3_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_SHM3_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_SHM3_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_SHM3_H_uint8_t;
typedef uint16_t APE_SHM3_H_uint16_t;
typedef uint32_t APE_SHM3_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM3_BASE ((volatile void*)0x60223000) /* Device SHM Registers, function 3 */
#define REG_SHM3_SIZE (sizeof(SHM_t))

#define REG_SHM3_SEG_SIG ((volatile APE_SHM3_H_uint32_t*)0x60223000) /* APE_APE_MAGIC ('APE!') when all is well. */
#define REG_SHM3_APE_SEG_LENGTH ((volatile APE_SHM3_H_uint32_t*)0x60223004) /* Set to 0x34. */
#define REG_SHM3_FW_STATUS ((volatile APE_SHM3_H_uint32_t*)0x6022300c) /*  */
#define REG_SHM3_FW_FEATURES ((volatile APE_SHM3_H_uint32_t*)0x60223010) /*  */
#define REG_SHM3_4014 ((volatile APE_SHM3_H_uint32_t*)0x60223014) /* Unknown. */
#define REG_SHM3_FW_VERSION ((volatile APE_SHM3_H_uint32_t*)0x60223018) /*  */
#define REG_SHM3_SEG_MESSAGE_BUFFER_OFFSET ((volatile APE_SHM3_H_uint32_t*)0x6022301c) /* Specifies the offset of a scratchpad area, relative to the  start of the APE SHM area (i.e., relative to APE_REG(0x4000)). */
#define REG_SHM3_SEG_MESSAGE_BUFFER_LENGTH ((volatile APE_SHM3_H_uint32_t*)0x60223020) /* Specifies the size of the scratchpad area in bytes. */
#define REG_SHM3_4024 ((volatile APE_SHM3_H_uint32_t*)0x60223024) /* Unknown. Bootcode related. */
#define REG_SHM3_4028 ((volatile APE_SHM3_H_uint32_t*)0x60223028) /* Unknown. Bootcode related. */
#define REG_SHM3_LOADER_COMMAND ((volatile APE_SHM3_H_uint32_t*)0x60223038) /* Command sent when using the the APE loader. Zero once handled. */
#define REG_SHM3_LOADER_ARG0 ((volatile APE_SHM3_H_uint32_t*)0x6022303c) /* Argument 0 for the APE loader. */
#define REG_SHM3_LOADER_ARG1 ((volatile APE_SHM3_H_uint32_t*)0x60223040) /* Argument 1 for the APE loader. */
#define REG_SHM3_RCPU_SEG_SIG ((volatile APE_SHM3_H_uint32_t*)0x60223100) /* Set to APE_RCPU_MAGIC ('RCPU') by RX CPU. */
#define REG_SHM3_RCPU_SEG_LENGTH ((volatile APE_SHM3_H_uint32_t*)0x60223104) /* Set to 0x34. */
#define REG_SHM3_RCPU_INIT_COUNT ((volatile APE_SHM3_H_uint32_t*)0x60223108) /* Incremented by RX CPU every boot. */
#define REG_SHM3_RCPU_FW_VERSION ((volatile APE_SHM3_H_uint32_t*)0x6022310c) /* Set to the bootcode version. e.g. 0x0127 -> v1.39. */
#define REG_SHM3_RCPU_CFG_FEATURE ((volatile APE_SHM3_H_uint32_t*)0x60223110) /* Set to  */
#define REG_SHM3_RCPU_PCI_VENDOR_DEVICE_ID ((volatile APE_SHM3_H_uint32_t*)0x60223114) /* Set to PCI Vendor/Device ID by S2. */
#define REG_SHM3_RCPU_PCI_SUBSYSTEM_ID ((volatile APE_SHM3_H_uint32_t*)0x60223118) /* Set to PCI Subsystem Vendor/Subsystem ID by S2. */
#define REG_SHM3_RCPU_APE_RESET_COUNT ((volatile APE_SHM3_H_uint32_t*)0x6022311c) /* Unknown. Incremented by frobnicating routine. */
#define REG_SHM3_RCPU_LAST_APE_STATUS ((volatile APE_SHM3_H_uint32_t*)0x60223120) /* Unknown. Written by frobnicating routine. */
#define REG_SHM3_RCPU_LAST_APE_FW_STATUS ((volatile APE_SHM3_H_uint32_t*)0x60223124) /* Unknown.  */
#define REG_SHM3_RCPU_CFG_HW ((volatile APE_SHM3_H_uint32_t*)0x60223128) /* Set from  */
#define REG_SHM3_RCPU_CFG_HW_2 ((volatile APE_SHM3_H_uint32_t*)0x6022312c) /* Set from  */
#define REG_SHM3_RCPU_CPMU_STATUS ((volatile APE_SHM3_H_uint32_t*)0x60223130) /* Set from  */
#define REG_SHM3_HOST_SEG_SIG ((volatile APE_SHM3_H_uint32_t*)0x60223200) /* Set to APE_HOST_MAGIC ('HOST') to indicate the section is valid. */
#define REG_SHM3_HOST_SEG_LEN ((volatile APE_SHM3_H_uint32_t*)0x60223204) /* Set to 0x20. */
#define REG_SHM3_HOST_INIT_COUNT ((volatile APE_SHM3_H_uint32_t*)0x60223208) /* Incremented by host on every initialization. */
#define REG_SHM3_HOST_DRIVER_ID ((volatile APE_SHM3_H_uint32_t*)0x6022320c) /* Linux sets this to 0xF0MM_mm00, where M is the major version  of Linux and m is the minor version. */
#define REG_SHM3_HOST_BEHAVIOR ((volatile APE_SHM3_H_uint32_t*)0x60223210) /*  */
#define REG_SHM3_HEARTBEAT_INTERVAL ((volatile APE_SHM3_H_uint32_t*)0x60223214) /* In milliseconds. Set to 0 to disable heartbeating. */
#define REG_SHM3_HEARTBEAT_COUNT ((volatile APE_SHM3_H_uint32_t*)0x60223218) /*  */
#define REG_SHM3_HOST_DRIVER_STATE ((volatile APE_SHM3_H_uint32_t*)0x6022321c) /*  */
#define REG_SHM3_WOL_SPEED ((volatile APE_SHM3_H_uint32_t*)0x60223224) /*  */
#define REG_SHM3_EVENT_STATUS ((volatile APE_SHM3_H_uint32_t*)0x60223300) /*  */
#define REG_SHM3_PROT_MAGIC ((volatile APE_SHM3_H_uint32_t*)0x60223308) /* This is set to APE_PROT_MAGIC ('PROT') on all functions.  If it is 'PROT', the following fields (MAC0_HIGH/LOW) are valid */
#define REG_SHM3_PROT_MAC0_HIGH ((volatile APE_SHM3_H_uint32_t*)0x60223314) /* High 16 bits of MAC address 0. Only valid if  */
#define REG_SHM3_PROT_MAC0_LOW ((volatile APE_SHM3_H_uint32_t*)0x60223318) /* Low 16 bits of MAC address 0. */
#define REG_SHM3_RCPU_WRITE_POINTER ((volatile APE_SHM3_H_uint32_t*)0x60223324) /* Index into the printf buffer for last valid byte. */
#define REG_SHM3_RCPU_HOST_READ_POINTER ((volatile APE_SHM3_H_uint32_t*)0x60223328) /* Index into the printf buffer for last read byte. */
#define REG_SHM3_RCPU_READ_POINTER ((volatile APE_SHM3_H_uint32_t*)0x6022332c) /* Index into the printf buffer for last read byte. */
#define REG_SHM3_RCPU_PRINTF_BUFFER ((volatile APE_SHM3_H_uint32_t*)0x60223330) /* Printf buffer from the APE to the Rcpu for NVRAM printout or the host */
/** @brief Device SHM Registers, function 3 */
extern volatile SHM_t SHM3;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(SHM_t) == 2304, "sizeof(SHM_t) must be 2304");
#endif

#endif /* !APE_SHM3_H */

/** @} */
