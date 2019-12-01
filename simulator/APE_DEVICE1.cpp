////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_DEVICE1.cpp
///
/// @project    ape
///
/// @brief      APE_DEVICE1
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

#include <APE_DEVICE1.h>

DEVICE_t DEVICE1;

void init_APE_DEVICE1(void)
{
    /** @brief Component Registers for @ref DEVICE1. */
    /** @brief Bitmap for @ref DEVICE1_t.MiscellaneousHostControl. */

    /** @brief Bitmap for @ref DEVICE1_t.PciState. */

    /** @brief Bitmap for @ref DEVICE1_t.RegisterBase. */

    /** @brief Bitmap for @ref DEVICE1_t.MemoryBase. */

    /** @brief Bitmap for @ref DEVICE1_t.RegisterData. */

    /** @brief Bitmap for @ref DEVICE1_t.UndiReceiveReturnRingConsumerIndex. */

    /** @brief Bitmap for @ref DEVICE1_t.UndiReceiveReturnRingConsumerIndexLow. */

    /** @brief Bitmap for @ref DEVICE1_t.LinkStatusControl. */

    /** @brief Bitmap for @ref DEVICE1_t.ApeMemoryBase. */

    /** @brief Bitmap for @ref DEVICE1_t.ApeMemoryData. */

    /** @brief Bitmap for @ref DEVICE1_t.160. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacMode. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacStatus. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacEvent. */

    /** @brief Bitmap for @ref DEVICE1_t.LedControl. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses0High. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses0Low. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses1High. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses1Low. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses2High. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses2Low. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses3High. */

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses3Low. */

    /** @brief Bitmap for @ref DEVICE1_t.WolPatternPointer. */

    /** @brief Bitmap for @ref DEVICE1_t.WolPatternCfg. */

    /** @brief Bitmap for @ref DEVICE1_t.438. */

    /** @brief Bitmap for @ref DEVICE1_t.MtuSize. */

    /** @brief Bitmap for @ref DEVICE1_t.MiiCommunication. */

    /** @brief Bitmap for @ref DEVICE1_t.MiiMode. */

    /** @brief Bitmap for @ref DEVICE1_t.TransmitMacMode. */

    /** @brief Bitmap for @ref DEVICE1_t.TransmitMacStatus. */

    /** @brief Bitmap for @ref DEVICE1_t.ReceiveMacMode. */

    /** @brief Bitmap for @ref DEVICE1_t.ReceiveMacStatus. */

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch1High. */

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch1Low. */

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch2High. */

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch2Low. */

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch3High. */

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch3Low. */

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch4High. */

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch4Low. */

    /** @brief Bitmap for @ref DEVICE1_t.SgmiiStatus. */

    /** @brief Bitmap for @ref DEVICE1_t.CpmuControl. */

    /** @brief Bitmap for @ref DEVICE1_t.NoLinkPowerModeClockPolicy. */

    /** @brief Bitmap for @ref DEVICE1_t.LinkAwarePowerModeClockPolicy. */

    /** @brief Bitmap for @ref DEVICE1_t.ClockSpeedOverridePolicy. */

    /** @brief Bitmap for @ref DEVICE1_t.Status. */

    /** @brief Bitmap for @ref DEVICE1_t.ClockStatus. */

    /** @brief Bitmap for @ref DEVICE1_t.GphyControlStatus. */

    /** @brief Bitmap for @ref DEVICE1_t.ChipId. */

    /** @brief Bitmap for @ref DEVICE1_t.MutexRequest. */

    /** @brief Bitmap for @ref DEVICE1_t.MutexGrant. */

    /** @brief Bitmap for @ref DEVICE1_t.GphyStrap. */

    /** @brief Bitmap for @ref DEVICE1_t.FlashClockControlPolicy. */

    /** @brief Bitmap for @ref DEVICE1_t.TopLevelMiscellaneousControl1. */

    /** @brief Bitmap for @ref DEVICE1_t.EeeMode. */

    /** @brief Bitmap for @ref DEVICE1_t.EeeLinkIdleControl. */

    /** @brief Bitmap for @ref DEVICE1_t.EeeControl. */

    /** @brief Bitmap for @ref DEVICE1_t.GlobalMutexRequest. */

    /** @brief Bitmap for @ref DEVICE1_t.GlobalMutexGrant. */

    /** @brief Bitmap for @ref DEVICE1_t.TemperatureMonitorControl. */

    /** @brief Bitmap for @ref DEVICE1_t.MemoryArbiterMode. */

    /** @brief Bitmap for @ref DEVICE1_t.BufferManagerMode. */

    /** @brief Bitmap for @ref DEVICE1_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscMode. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscStatus. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscProgramCounter. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscCurrentInstruction. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscHardwareBreakpoint. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister0. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister1. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister2. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister3. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister4. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister5. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister6. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister7. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister8. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister9. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister10. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister11. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister12. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister13. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister14. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister15. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister16. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister17. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister18. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister19. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister20. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister21. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister22. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister23. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister24. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister25. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister26. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister27. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister28. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister29. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister30. */

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister31. */

    /** @brief Bitmap for @ref DEVICE1_t.6408. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerConsumptionInfo. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerDissipatedInfo. */

    /** @brief Bitmap for @ref DEVICE1_t.PciVpdRequest. */

    /** @brief Bitmap for @ref DEVICE1_t.PciVpdResponse. */

    /** @brief Bitmap for @ref DEVICE1_t.PciVendorDeviceId. */

    /** @brief Bitmap for @ref DEVICE1_t.PciSubsystemId. */

    /** @brief Bitmap for @ref DEVICE1_t.PciClassCodeRevision. */

    /** @brief Bitmap for @ref DEVICE1_t.64c0. */

    /** @brief Bitmap for @ref DEVICE1_t.64c4. */

    /** @brief Bitmap for @ref DEVICE1_t.64c8. */

    /** @brief Bitmap for @ref DEVICE1_t.64dc. */

    /** @brief Bitmap for @ref DEVICE1_t.PciSerialNumberLow. */

    /** @brief Bitmap for @ref DEVICE1_t.PciSerialNumberHigh. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget0. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget1. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget2. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget3. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget4. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget5. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget6. */

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget7. */

    /** @brief Bitmap for @ref DEVICE1_t.6530. */

    /** @brief Bitmap for @ref DEVICE1_t.6550. */

    /** @brief Bitmap for @ref DEVICE1_t.65f4. */

    /** @brief Bitmap for @ref DEVICE1_t.GrcModeControl. */

    /** @brief Bitmap for @ref DEVICE1_t.MiscellaneousConfig. */

    /** @brief Bitmap for @ref DEVICE1_t.MiscellaneousLocalControl. */

    /** @brief Bitmap for @ref DEVICE1_t.Timer. */

    /** @brief Bitmap for @ref DEVICE1_t.RxCpuEvent. */

    /** @brief Bitmap for @ref DEVICE1_t.6838. */

    /** @brief Bitmap for @ref DEVICE1_t.MdiControl. */

    /** @brief Bitmap for @ref DEVICE1_t.RxCpuEventEnable. */

    /** @brief Bitmap for @ref DEVICE1_t.FastBootProgramCounter. */

    /** @brief Bitmap for @ref DEVICE1_t.ExpansionRomAddr. */

    /** @brief Bitmap for @ref DEVICE1_t.68f0. */

    /** @brief Bitmap for @ref DEVICE1_t.EavRefClockControl. */

    /** @brief Bitmap for @ref DEVICE1_t.7c04. */


}
