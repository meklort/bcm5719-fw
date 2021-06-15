////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_SHM_sim.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_SHM_sim
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2021, Evan Lojewski
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

#include <stdint.h>
#include <utility>
#include <bcm5719_SHM.h>

#ifdef __ppc64__
#define BARRIER()    do { asm volatile ("sync 0\neieio\n" ::: "memory"); } while(0)
#else
#define BARRIER()    do { asm volatile ("" ::: "memory"); } while(0)
#endif

static uint32_t read_from_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    return *(uint32_t *)base;
}

static uint32_t write_to_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    *(uint32_t *)base = val;
    BARRIER();
    return val;
}

void init_bcm5719_SHM_sim(void *base)
{
    SHM.mIndexReadCallback = read_from_ram;
    SHM.mIndexReadCallbackArgs = base;

    SHM.mIndexWriteCallback = write_to_ram;
    SHM.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref SHM. */
    /** @brief Bitmap for @ref SHM_t.SegSig. */
    SHM.SegSig.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.SegSig.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.ApeSegLength. */
    SHM.ApeSegLength.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.ApeSegLength.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM.reserved_8[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.reserved_8[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_t.FwStatus. */
    SHM.FwStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.FwStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.FwFeatures. */
    SHM.FwFeatures.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.FwFeatures.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.4014. */
    SHM._4014.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM._4014.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.FwVersion. */
    SHM.FwVersion.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.FwVersion.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.SegMessageBufferOffset. */
    SHM.SegMessageBufferOffset.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.SegMessageBufferOffset.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.SegMessageBufferLength. */
    SHM.SegMessageBufferLength.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.SegMessageBufferLength.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.4024. */
    SHM._4024.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM._4024.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.4028. */
    SHM._4028.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM._4028.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM.reserved_44[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.reserved_44[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_t.DriverBuffer. */
    for(int i = 0; i < 2; i++)
    {
        SHM.DriverBuffer[i].r32.installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.DriverBuffer[i].r32.installWriteCallback(write_to_ram, (uint8_t *)base);
    }

    /** @brief Bitmap for @ref SHM_t.LoaderCommand. */
    SHM.LoaderCommand.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.LoaderCommand.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.LoaderArg0. */
    SHM.LoaderArg0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.LoaderArg0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.LoaderArg1. */
    SHM.LoaderArg1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.LoaderArg1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 47; i++)
    {
        SHM.reserved_68[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.reserved_68[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_t.RcpuSegSig. */
    SHM.RcpuSegSig.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuSegSig.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuSegLength. */
    SHM.RcpuSegLength.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuSegLength.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuInitCount. */
    SHM.RcpuInitCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuInitCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuFwVersion. */
    SHM.RcpuFwVersion.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuFwVersion.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuCfgFeature. */
    SHM.RcpuCfgFeature.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuCfgFeature.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuPciVendorDeviceId. */
    SHM.RcpuPciVendorDeviceId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuPciVendorDeviceId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuPciSubsystemId. */
    SHM.RcpuPciSubsystemId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuPciSubsystemId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuApeResetCount. */
    SHM.RcpuApeResetCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuApeResetCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuLastApeStatus. */
    SHM.RcpuLastApeStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuLastApeStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuLastApeFwStatus. */
    SHM.RcpuLastApeFwStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuLastApeFwStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuCfgHw. */
    SHM.RcpuCfgHw.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuCfgHw.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuCfgHw2. */
    SHM.RcpuCfgHw2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuCfgHw2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuCpmuStatus. */
    SHM.RcpuCpmuStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuCpmuStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 51; i++)
    {
        SHM.reserved_308[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.reserved_308[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_t.HostSegSig. */
    SHM.HostSegSig.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostSegSig.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostSegLen. */
    SHM.HostSegLen.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostSegLen.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostInitCount. */
    SHM.HostInitCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostInitCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostDriverId. */
    SHM.HostDriverId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostDriverId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostBehavior. */
    SHM.HostBehavior.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostBehavior.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HeartbeatInterval. */
    SHM.HeartbeatInterval.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HeartbeatInterval.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HeartbeatCount. */
    SHM.HeartbeatCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HeartbeatCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostDriverState. */
    SHM.HostDriverState.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostDriverState.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM.reserved_544[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.reserved_544[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_t.WolSpeed. */
    SHM.WolSpeed.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.WolSpeed.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 54; i++)
    {
        SHM.reserved_552[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.reserved_552[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_t.EventStatus. */
    SHM.EventStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.EventStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        SHM.reserved_772[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.reserved_772[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_t.ProtMagic. */
    SHM.ProtMagic.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.ProtMagic.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        SHM.reserved_780[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.reserved_780[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_t.ProtMac0High. */
    SHM.ProtMac0High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.ProtMac0High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.ProtMac0Low. */
    SHM.ProtMac0Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.ProtMac0Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        SHM.reserved_796[i].installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.reserved_796[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref SHM_t.RcpuWritePointer. */
    SHM.RcpuWritePointer.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuWritePointer.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuHostReadPointer. */
    SHM.RcpuHostReadPointer.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuHostReadPointer.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuReadPointer. */
    SHM.RcpuReadPointer.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuReadPointer.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuPrintfBuffer. */
    for(int i = 0; i < 372; i++)
    {
        SHM.RcpuPrintfBuffer[i].r32.installReadCallback(read_from_ram, (uint8_t *)base);
        SHM.RcpuPrintfBuffer[i].r32.installWriteCallback(write_to_ram, (uint8_t *)base);
    }


}
