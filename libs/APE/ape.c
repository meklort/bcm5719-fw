////////////////////////////////////////////////////////////////////////////////
///
/// @file       ape.c
///
/// @project
///
/// @brief      APE Support Routines
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
#include "bcm5719_APE.h"
#include "bcm5719_DEVICE.h"

void APE_aquireLock(void)
{
    RegAPEPerLockRequestPhy0_t lock_req;
    lock_req.r32 = 0;
    lock_req.bits.Bootcode = 1;

    uint8_t function = DEVICE.Status.bits.FunctionNumber;
    switch(function)
    {
        default:
        case 0:
            APE.PerLockRequestPhy0.r32 = lock_req.r32;
            do
            {
                // spin
            } while(lock_req.r32 != APE.PerLockGrantPhy0.r32);
            return;

        case 1:
            APE.PerLockRequestPhy1.r32 = lock_req.r32;
            do
            {
                // spin
            } while(lock_req.r32 != APE.PerLockGrantPhy1.r32);
            return;

        case 2:
            APE.PerLockRequestPhy2.r32 = lock_req.r32;
            do
            {
                // spin
            } while(lock_req.r32 != APE.PerLockGrantPhy2.r32);
            return;

        case 3:
            APE.PerLockRequestPhy3.r32 = lock_req.r32;
            do
            {
                // spin
            } while(lock_req.r32 != APE.PerLockGrantPhy3.r32);
            return;
    }

}

void APE_releaseLock(void)
{
    RegAPEPerLockGrantPhy0_t lock_release;
    lock_release.r32 = 0;
    lock_release.bits.Bootcode = 1;

    uint8_t function = DEVICE.Status.bits.FunctionNumber;
    switch(function)
    {
        default:
        case 0:
            APE.PerLockGrantPhy0.r32 = lock_release.r32;

        case 1:
            APE.PerLockGrantPhy1.r32 = lock_release.r32;

        case 2:
            APE.PerLockGrantPhy2.r32 = lock_release.r32;

        case 3:
            APE.PerLockGrantPhy3.r32 = lock_release.r32;
    }
}

void APE_releaseAllLocks(void)
{
    RegAPEPerLockGrantPhy0_t lock_release;
    lock_release.r32 = 0;
    lock_release.bits.Bootcode = 1;

    APE.PerLockGrantPhy0.r32    = lock_release.r32;
    APE.PerLockGrantGrc.r32     = lock_release.r32;
    APE.PerLockGrantPhy1.r32    = lock_release.r32;
    APE.PerLockGrantPhy2.r32    = lock_release.r32;
    APE.PerLockGrantMem.r32     = lock_release.r32;
    APE.PerLockGrantPhy3.r32    = lock_release.r32;
    APE.PerLockGrantPort6.r32   = lock_release.r32;
    APE.PerLockGrantGpio.r32    = lock_release.r32;
}
