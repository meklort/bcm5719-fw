////////////////////////////////////////////////////////////////////////////////
///
/// @file       NCSI.h
///
/// @project
///
/// @brief      NCSI Support Routines
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2019, Evan Lojewski
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
/// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
/// POSSIBILITY OF SUCH DAMAGE.
/// @endcond
////////////////////////////////////////////////////////////////////////////////

#ifndef NCSI_H
#define NCSI_H

#include <types.h>
#include <Ethernet.h>
#include <Network.h>

//lint -sem(handleNCSIFrame, 1p) Warn if frame is NULL
void handleNCSIFrame(const NetworkFrame_t* frame);


#define NCSI_RESPONSE_CODE_COMMAND_COMPLETE     (0)
#define NCSI_RESPONSE_CODE_COMMAND_FAILED       (1)
#define NCSI_RESPONSE_CODE_COMMAND_UNAVAILABLE  (2)
#define NCSI_RESPONSE_CODE_COMMAND_UNSUPPORTED  (3)

#define NCSI_REASON_CODE_NONE                       (0) /* When used with the Command Completed response code, indicates that the command completed normally. Otherwise this value indicates that no additional reason code information is being provided. */
#define NCSI_REASON_CODE_INITIALIZATION_REQUIRED    (1) /* Returned for all commands when the channel is in the Initial State, until the channel receives a Clear Initial State command */
#define NCSI_REASON_CODE_INVALID_PARAM              (2) /* Returned when a received parameter value is outside of the acceptable values for that parameter */
#define NCSI_REASON_CODE_CHANNEL_NOT_READY          (3) /* May be returned when the channel is in a transient state in which it is unable to process commands normally */
#define NCSI_REASON_CODE_PACKAGE_NOT_READY          (4) /* May be returned when the package and channels within the package are in a transient state in which normal command processing cannot be done */
#define NCSI_REASON_CODE_INVALID_PAYLOAD_LENGTH     (5) /* The payload length in the command is incorrect for the given command */
#define NCSI_REASON_CODE_UNKNOWN_UNSUPPORTED        (0x7FFF) /* Returned when the command type is unknown or unsupported */


//lint -sem(NCSI_TxPacket, 1p) Warn if packet is NULL
//lint -sem(NCSI_TxPacket, 2n >= 1P) Warn if packet is smaller than packet_len
void NCSI_TxPacket(const uint32_t* packet, uint32_t packet_len);

//lint -sem(NCSI_TxBePacket, 1p) Warn if packet is NULL
//lint -sem(NCSI_TxBePacket, 2n >= 1P) Warn if packet is smaller than packet_len
void NCSI_TxBePacket(const uint32_t* packet, uint32_t packet_len);

void NCSI_handlePassthrough(void);

void NCSI_init(void);

void NCSI_reload(reload_type_t reset_phy);

//lint -sem(NCSI_usePort, 1p) Warn if port is NULL
void NCSI_usePort(NetworkPort_t *port);

#endif /* NCSI_H */
