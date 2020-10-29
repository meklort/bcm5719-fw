////////////////////////////////////////////////////////////////////////////////
///
/// @file       Timer.h
///
/// @project
///
/// @brief      Timer Support Routines
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
#ifndef TIMER_H
#define TIMER_H

#include <types.h>

/**
 * @fn uint32_t Timer_getCurrentTime10Hz(void);
 *
 * @brief Returns the current time for the 10Hz timer.
 *
 * @returns The current 10Hz time
 */
uint32_t Timer_getCurrentTime10Hz(void);

/**
 * @fn bool Timer_didTimeElapsed10Hz(uint32_t startTime, uint32_t checkTime);
 *
 * @brief DEtermines if the specified time has elapsed.
 *
 * @param startTime The start time to compare with
 * @param checkTime The delta minimum time required to elapse.
 *
 * @returns true if the time has elapsed, false otherwise.
 */
bool Timer_didTimeElapsed10Hz(uint32_t startTime, uint32_t checkTime);

/**
 * @fn uint32_t Timer_getCurrentTime1KHz(void);
 *
 * @brief Returns the current time for the 1KHz timer.
 *
 * @returns The current 1KHz time
 */
uint32_t Timer_getCurrentTime1KHz(void);

/**
 * @fn bool Timer_didTimeElapsed1KHz(uint32_t startTime, uint32_t checkTime);
 *
 * @brief DEtermines if the specified time has elapsed.
 *
 * @param startTime The start time to compare with
 * @param checkTime The delta minimum time required to elapse.
 *
 * @returns true if the time has elapsed, false otherwise.
 */
bool Timer_didTimeElapsed1KHz(uint32_t startTime, uint32_t checkTime);

/**
 * @fn uint32_t Timer_getCurrentTime1MHz(void);
 *
 * @brief Returns the current time for the 1MHz timer.
 *
 * @returns The current 1MHz time
 */
uint32_t Timer_getCurrentTime1MHz(void);

/**
 * @fn bool Timer_didTimeElapsed1MHz(uint32_t startTime, uint32_t checkTime);
 *
 * @brief DEtermines if the specified time has elapsed.
 *
 * @param startTime The start time to compare with
 * @param checkTime The delta minimum time required to elapse.
 *
 * @returns true if the time has elapsed, false otherwise.
 */
bool Timer_didTimeElapsed1MHz(uint32_t startTime, uint32_t checkTime);

#endif /* TIMER_H */
