////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_DEVICE.cpp
///
/// @project    <PROJECT>
///
/// @brief      bcm5719_DEVICE simulation support
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

#include <bcm5719_DEVICE.h>

DEVICE_t DEVICE;

void init_bcm5719_DEVICE(void)
{
    /** @brief Component Registers for @ref DEVICE. */ 
    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousHostControl. */ 
    DEVICE.MiscellaneousHostControl.bits.ClearInterrupt.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.MaskInterrupt.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.EnableEndianByteSwap.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.EnableEndianWordSwap.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.EnablePCIStateRegisterRead_DIV_WriteCapability.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.EnableClockControlRegisterRead_DIV_WriteCapability.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.EnableRegisterWordSwap.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.EnableIndirectAccess.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.MaskInterruptMode.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.EnableTaggedStatusMode.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.RCBCheck.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.InterruptCheck.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.ByteEnableRuleCheck.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.BoundaryCheck.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.LogHeaderOverflow.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.EnableTLPMinorErrorTolerance.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.MetalRevID.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.ProductID.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);
    DEVICE.MiscellaneousHostControl.bits.AllLayerID.setBaseRegister(&DEVICE.MiscellaneousHostControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.PciState. */ 
    DEVICE.PciState.bits.PCIExpansionROMDesired.setBaseRegister(&DEVICE.PciState.r32);
    DEVICE.PciState.bits.PCIExpansionROMRetry.setBaseRegister(&DEVICE.PciState.r32);
    DEVICE.PciState.bits.VPDAvailable.setBaseRegister(&DEVICE.PciState.r32);
    DEVICE.PciState.bits.FlatView.setBaseRegister(&DEVICE.PciState.r32);
    DEVICE.PciState.bits.MaxPCITargetRetry.setBaseRegister(&DEVICE.PciState.r32);
    DEVICE.PciState.bits.ConfigRetry.setBaseRegister(&DEVICE.PciState.r32);
    DEVICE.PciState.bits.APEControlRegisterWriteEnable.setBaseRegister(&DEVICE.PciState.r32);
    DEVICE.PciState.bits.APESharedMemoryWriteEnable.setBaseRegister(&DEVICE.PciState.r32);
    DEVICE.PciState.bits.APEProgramSpaceWriteEnable.setBaseRegister(&DEVICE.PciState.r32);
    DEVICE.PciState.bits.GenerateResetPlus.setBaseRegister(&DEVICE.PciState.r32);

    /** @brief Bitmap for @ref DEVICE_t.RegisterBase. */ 

    /** @brief Bitmap for @ref DEVICE_t.MemoryBase. */ 

    /** @brief Bitmap for @ref DEVICE_t.RegisterData. */ 

    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndex. */ 

    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndexLow. */ 

    /** @brief Bitmap for @ref DEVICE_t.LinkStatusControl. */ 
    DEVICE.LinkStatusControl.bits.NegotiatedLinkSpeed.setBaseRegister(&DEVICE.LinkStatusControl.r32);
    DEVICE.LinkStatusControl.bits.NegotiatedLinkWidth.setBaseRegister(&DEVICE.LinkStatusControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMode. */ 
    DEVICE.EmacMode.bits.GlobalReset.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.HalfDuplex.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.PortMode.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.LoopbackMode.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.TaggedMACControl.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.EnableTXBursting.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.MaxDefer.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.EnableRXStatistics.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.ClearRXStatistics.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.FlushRXStatistics.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.EnableTXStatistics.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.ClearTXStatistics.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.FlushTXStatistics.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.SendConfigCommand.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.MagicPacketDetectionEnable.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.ACPIPowerOnEnable.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.EnableTCE.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.EnableRDE.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.EnableFHDE.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.KeepFrameInWOL.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.HaltInterestingPacketPME.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.Free_RunningACPI.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.EnableAPERXPath.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.EnableAPETXPath.setBaseRegister(&DEVICE.EmacMode.r32);
    DEVICE.EmacMode.bits.MACLoopbackModeControl.setBaseRegister(&DEVICE.EmacMode.r32);

    /** @brief Bitmap for @ref DEVICE_t.LedControl. */ 
    DEVICE.LedControl.bits.OverrideLink.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LED1000.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LED100.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LED10.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.OverrideTraffic.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LEDTrafficBlink.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LEDTraffic.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LEDStatus1000.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LEDStatus100.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LEDStatus10.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LEDStatusTraffic.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.LEDMode.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.MACMode.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.SharedTraffic_DIV_LinkLEDMode.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.BlinkPeriod.setBaseRegister(&DEVICE.LedControl.r32);
    DEVICE.LedControl.bits.OverrideBlinkRate.setBaseRegister(&DEVICE.LedControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0High. */ 

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0Low. */ 

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1High. */ 

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1Low. */ 

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2High. */ 

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2Low. */ 

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3High. */ 

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3Low. */ 

    /** @brief Bitmap for @ref DEVICE_t.WolPatternPointer. */ 

    /** @brief Bitmap for @ref DEVICE_t.WolPatternCfg. */ 

    /** @brief Bitmap for @ref DEVICE_t.MtuSize. */ 
    DEVICE.MtuSize.bits.MTU.setBaseRegister(&DEVICE.MtuSize.r32);

    /** @brief Bitmap for @ref DEVICE_t.MiiCommunication. */ 
    DEVICE.MiiCommunication.bits.TransactionData.setBaseRegister(&DEVICE.MiiCommunication.r32);
    DEVICE.MiiCommunication.bits.RegisterAddress.setBaseRegister(&DEVICE.MiiCommunication.r32);
    DEVICE.MiiCommunication.bits.PHYAddress.setBaseRegister(&DEVICE.MiiCommunication.r32);
    DEVICE.MiiCommunication.bits.Command.setBaseRegister(&DEVICE.MiiCommunication.r32);
    DEVICE.MiiCommunication.bits.ReadFailed.setBaseRegister(&DEVICE.MiiCommunication.r32);
    DEVICE.MiiCommunication.bits.Start_DIV_Busy.setBaseRegister(&DEVICE.MiiCommunication.r32);

    /** @brief Bitmap for @ref DEVICE_t.MiiMode. */ 
    DEVICE.MiiMode.bits.ConstantMDIO_DIV_MDCClockSpeed.setBaseRegister(&DEVICE.MiiMode.r32);

    /** @brief Bitmap for @ref DEVICE_t.ReceiveMacMode. */ 
    DEVICE.ReceiveMacMode.bits.Reset.setBaseRegister(&DEVICE.ReceiveMacMode.r32);
    DEVICE.ReceiveMacMode.bits.Enable.setBaseRegister(&DEVICE.ReceiveMacMode.r32);
    DEVICE.ReceiveMacMode.bits.PromiscuousMode.setBaseRegister(&DEVICE.ReceiveMacMode.r32);
    DEVICE.ReceiveMacMode.bits.APEPromiscuousMode.setBaseRegister(&DEVICE.ReceiveMacMode.r32);

    /** @brief Bitmap for @ref DEVICE_t.SgmiiStatus. */ 
    DEVICE.SgmiiStatus.bits.AutonegotiationComplete.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.LinkStatus.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.DuplexStatus.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.Speed1000.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.Speed100.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.NextPageRX.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.PauseRX.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.PauseTX.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.MediaSelectionMode.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.PCSCRSDetect.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.ExternalCRSDetect.setBaseRegister(&DEVICE.SgmiiStatus.r32);
    DEVICE.SgmiiStatus.bits.LinkPartnerAutonegotiationCapability.setBaseRegister(&DEVICE.SgmiiStatus.r32);

    /** @brief Bitmap for @ref DEVICE_t.CpmuControl. */ 
    DEVICE.CpmuControl.bits.CPMUSoftwareReset.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.CPMURegisterSoftwareReset.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.PowerDown.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.APESleepModeEnable.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.APEDeepSleepModeEnable.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.LinkIdlePowerModeEnable.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.LinkAwarePowerModeEnable.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.LinkSpeedPowerModeEnable.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.GPHY10MBReceiveOnlyModeEnable.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.LegacyTimerEnable.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.SGMII_DIV_PCSPowerDown.setBaseRegister(&DEVICE.CpmuControl.r32);
    DEVICE.CpmuControl.bits.SoftwareControlledGPHYForceDLLOn.setBaseRegister(&DEVICE.CpmuControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.LinkAwarePowerModeClockPolicy. */ 
    DEVICE.LinkAwarePowerModeClockPolicy.bits.MACClockSwitch.setBaseRegister(&DEVICE.LinkAwarePowerModeClockPolicy.r32);

    /** @brief Bitmap for @ref DEVICE_t.ClockSpeedOverridePolicy. */ 
    DEVICE.ClockSpeedOverridePolicy.bits.MACClockSwitch.setBaseRegister(&DEVICE.ClockSpeedOverridePolicy.r32);
    DEVICE.ClockSpeedOverridePolicy.bits.MACClockSpeedOverrideEnabled.setBaseRegister(&DEVICE.ClockSpeedOverridePolicy.r32);

    /** @brief Bitmap for @ref DEVICE_t.Status. */ 
    DEVICE.Status.bits.PowerManagementStateMachineState.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.CPMUPowerState.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.EnergyDetectStatus.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.PowerState.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.VMAINPowerStatus.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.WOLMagicPacketDetectionEnablePort0.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.WOLACPIDetectionEnablePort0.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.NCSIDLLLockStatus.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.GPHYDLLLockStatus.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.LinkIdleStatus.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.EthernetLinkStatus.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.WOLMagicPacketDetectionEnablePort1.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.WOLACPIDetectionEnablePort1.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.APEStatus.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.FunctionEnable.setBaseRegister(&DEVICE.Status.r32);
    DEVICE.Status.bits.FunctionNumber.setBaseRegister(&DEVICE.Status.r32);

    /** @brief Bitmap for @ref DEVICE_t.ClockStatus. */ 

    /** @brief Bitmap for @ref DEVICE_t.GphyControlStatus. */ 
    DEVICE.GphyControlStatus.bits.GPHYIDDQ.setBaseRegister(&DEVICE.GphyControlStatus.r32);
    DEVICE.GphyControlStatus.bits.BIASIDDQ.setBaseRegister(&DEVICE.GphyControlStatus.r32);
    DEVICE.GphyControlStatus.bits.CPMUSoftwareReset.setBaseRegister(&DEVICE.GphyControlStatus.r32);
    DEVICE.GphyControlStatus.bits.CPMURegisterSoftwareReset.setBaseRegister(&DEVICE.GphyControlStatus.r32);
    DEVICE.GphyControlStatus.bits.PowerDown.setBaseRegister(&DEVICE.GphyControlStatus.r32);
    DEVICE.GphyControlStatus.bits.SGMII_DIV_PCSPowerDown.setBaseRegister(&DEVICE.GphyControlStatus.r32);
    DEVICE.GphyControlStatus.bits.NCSIPLLLockStatus.setBaseRegister(&DEVICE.GphyControlStatus.r32);
    DEVICE.GphyControlStatus.bits.TLPClockSource.setBaseRegister(&DEVICE.GphyControlStatus.r32);
    DEVICE.GphyControlStatus.bits.SwitchingRegulatorPowerDown.setBaseRegister(&DEVICE.GphyControlStatus.r32);

    /** @brief Bitmap for @ref DEVICE_t.ChipId. */ 

    /** @brief Bitmap for @ref DEVICE_t.MutexRequest. */ 

    /** @brief Bitmap for @ref DEVICE_t.MutexGrant. */ 

    /** @brief Bitmap for @ref DEVICE_t.GphyStrap. */ 
    DEVICE.GphyStrap.bits.TXMBUFECCEnable.setBaseRegister(&DEVICE.GphyStrap.r32);
    DEVICE.GphyStrap.bits.RXMBUFECCEnable.setBaseRegister(&DEVICE.GphyStrap.r32);
    DEVICE.GphyStrap.bits.RXCPUSPADECCEnable.setBaseRegister(&DEVICE.GphyStrap.r32);

    /** @brief Bitmap for @ref DEVICE_t.TopLevelMiscellaneousControl1. */ 
    DEVICE.TopLevelMiscellaneousControl1.bits.NCSIClockOutputDisable.setBaseRegister(&DEVICE.TopLevelMiscellaneousControl1.r32);
    DEVICE.TopLevelMiscellaneousControl1.bits.LowPowerIDDQMode.setBaseRegister(&DEVICE.TopLevelMiscellaneousControl1.r32);

    /** @brief Bitmap for @ref DEVICE_t.EeeMode. */ 
    DEVICE.EeeMode.bits.RXCPUAllowLPI.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.DriveAllowLPI.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.APETXDetectionEnable.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.EEELinkIdleDetectionEnable.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.PCIeL1ExitDetectionEnable.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.RXCPUAllowLPIEnable.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.SendIndexDetectionEnable.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.UserLPIEnable.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.TXLPIEnable.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.RXLPIEnable.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.AutoWakeEnable.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.BlockTime.setBaseRegister(&DEVICE.EeeMode.r32);
    DEVICE.EeeMode.bits.DriveAllowLPIEnable.setBaseRegister(&DEVICE.EeeMode.r32);

    /** @brief Bitmap for @ref DEVICE_t.EeeLinkIdleControl. */ 
    DEVICE.EeeLinkIdleControl.bits.DebugUARTIdle.setBaseRegister(&DEVICE.EeeLinkIdleControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.EeeControl. */ 
    DEVICE.EeeControl.bits.ExitTime.setBaseRegister(&DEVICE.EeeControl.r32);
    DEVICE.EeeControl.bits.MinimumAssert.setBaseRegister(&DEVICE.EeeControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexRequest. */ 

    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexGrant. */ 

    /** @brief Bitmap for @ref DEVICE_t.MemoryArbiterMode. */ 
    DEVICE.MemoryArbiterMode.bits.Enable.setBaseRegister(&DEVICE.MemoryArbiterMode.r32);

    /** @brief Bitmap for @ref DEVICE_t.BufferManagerMode. */ 
    DEVICE.BufferManagerMode.bits.Enable.setBaseRegister(&DEVICE.BufferManagerMode.r32);
    DEVICE.BufferManagerMode.bits.AttentionEnable.setBaseRegister(&DEVICE.BufferManagerMode.r32);
    DEVICE.BufferManagerMode.bits.ResetRXMBUFPointer.setBaseRegister(&DEVICE.BufferManagerMode.r32);

    /** @brief Bitmap for @ref DEVICE_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */ 
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.bits.PCIRequestBurstLengthforBDRDMAEngine.setBaseRegister(&DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32);
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.bits.PCIRequestBurstLengthforNonLSORDMAEngine.setBaseRegister(&DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscMode. */ 
    DEVICE.RxRiscMode.bits.Reset.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.SingleStep.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.Page0DataHalt.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.Page0InstrHalt.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.EnableDataCache.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.ROMFail.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.EnableWatchdog.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.EnableInstructionCache.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.FlushInstructionCache.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.Halt.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.InvalidDataAccessHalt.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.InvalidInstructionAccessHalt.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.EnableMemoryAddressTrapHalt.setBaseRegister(&DEVICE.RxRiscMode.r32);
    DEVICE.RxRiscMode.bits.EnableRegisterAddressTrapHalt.setBaseRegister(&DEVICE.RxRiscMode.r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscStatus. */ 
    DEVICE.RxRiscStatus.bits.HardwareBreakpoint.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.HaltInstructionExecuted.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.InvalidInstruction.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.Page0DataRefeence.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.Page0InstructionReference.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.InvalidDataAccess.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.InvalidInstructionFetch.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.BadMemoryAlignment.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.MemoryAddressTrap.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.RegisterAddressTrap.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.Halted.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.Unknown.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.DataAccessStall.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.InstructionFetchStall.setBaseRegister(&DEVICE.RxRiscStatus.r32);
    DEVICE.RxRiscStatus.bits.BlockingRead.setBaseRegister(&DEVICE.RxRiscStatus.r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscProgramCounter. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscCurrentInstruction. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscHardwareBreakpoint. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister0. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister1. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister2. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister3. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister4. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister5. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister6. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister7. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister8. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister9. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister10. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister11. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister12. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister13. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister14. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister15. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister16. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister17. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister18. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister19. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister20. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister21. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister22. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister23. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister24. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister25. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister26. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister27. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister28. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister29. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister30. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister31. */ 

    /** @brief Bitmap for @ref DEVICE_t.6408. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciPowerConsumptionInfo. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciPowerDissipatedInfo. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciVpdRequest. */ 
    DEVICE.PciVpdRequest.bits.RequestedVPDOffset.setBaseRegister(&DEVICE.PciVpdRequest.r32);

    /** @brief Bitmap for @ref DEVICE_t.PciVpdResponse. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciVendorDeviceId. */ 
    DEVICE.PciVendorDeviceId.bits.DeviceID.setBaseRegister(&DEVICE.PciVendorDeviceId.r32);
    DEVICE.PciVendorDeviceId.bits.VendorID.setBaseRegister(&DEVICE.PciVendorDeviceId.r32);

    /** @brief Bitmap for @ref DEVICE_t.PciSubsystemId. */ 
    DEVICE.PciSubsystemId.bits.SubsystemVendorID.setBaseRegister(&DEVICE.PciSubsystemId.r32);
    DEVICE.PciSubsystemId.bits.SubsystemID.setBaseRegister(&DEVICE.PciSubsystemId.r32);

    /** @brief Bitmap for @ref DEVICE_t.PciClassCodeRevision. */ 

    /** @brief Bitmap for @ref DEVICE_t.64c0. */ 

    /** @brief Bitmap for @ref DEVICE_t.64c8. */ 

    /** @brief Bitmap for @ref DEVICE_t.64dc. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberLow. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberHigh. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget0. */ 
    DEVICE.PciPowerBudget0.bits.PowerBudgetValue.setBaseRegister(&DEVICE.PciPowerBudget0.r32);
    DEVICE.PciPowerBudget0.bits.Unknown.setBaseRegister(&DEVICE.PciPowerBudget0.r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget1. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget2. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget3. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget4. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget5. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget6. */ 

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget7. */ 

    /** @brief Bitmap for @ref DEVICE_t.6530. */ 

    /** @brief Bitmap for @ref DEVICE_t.6550. */ 

    /** @brief Bitmap for @ref DEVICE_t.65f4. */ 

    /** @brief Bitmap for @ref DEVICE_t.GrcModeControl. */ 
    DEVICE.GrcModeControl.bits.TimeSyncModeEnable.setBaseRegister(&DEVICE.GrcModeControl.r32);
    DEVICE.GrcModeControl.bits.NVRAMWriteEnable.setBaseRegister(&DEVICE.GrcModeControl.r32);
    DEVICE.GrcModeControl.bits.PCIeTL_DIV_DL_DIV_PLMapping1.setBaseRegister(&DEVICE.GrcModeControl.r32);
    DEVICE.GrcModeControl.bits.PCIeTL_DIV_DL_DIV_PLMapping2.setBaseRegister(&DEVICE.GrcModeControl.r32);
    DEVICE.GrcModeControl.bits.PCIeTL_DIV_DL_DIV_PLMapping3.setBaseRegister(&DEVICE.GrcModeControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousLocalControl. */ 
    DEVICE.MiscellaneousLocalControl.bits.GPIO0Input.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);
    DEVICE.MiscellaneousLocalControl.bits.GPIO1Input.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);
    DEVICE.MiscellaneousLocalControl.bits.GPIO2Input.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);
    DEVICE.MiscellaneousLocalControl.bits.GPIO0OutputEnable.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);
    DEVICE.MiscellaneousLocalControl.bits.GPIO1OutputEnable.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);
    DEVICE.MiscellaneousLocalControl.bits.GPIO2OutputEnable.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);
    DEVICE.MiscellaneousLocalControl.bits.GPIO0Output.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);
    DEVICE.MiscellaneousLocalControl.bits.GPIO1Output.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);
    DEVICE.MiscellaneousLocalControl.bits.GPIO2Output.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);
    DEVICE.MiscellaneousLocalControl.bits.AutoSEEPROMAccess.setBaseRegister(&DEVICE.MiscellaneousLocalControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.Timer. */ 

    /** @brief Bitmap for @ref DEVICE_t.RxCpuEvent. */ 
    DEVICE.RxCpuEvent.bits.VPDAttention.setBaseRegister(&DEVICE.RxCpuEvent.r32);

    /** @brief Bitmap for @ref DEVICE_t.6838. */ 

    /** @brief Bitmap for @ref DEVICE_t.MdiControl. */ 

    /** @brief Bitmap for @ref DEVICE_t.FastBootProgramCounter. */ 
    DEVICE.FastBootProgramCounter.bits.ProgramCounter.setBaseRegister(&DEVICE.FastBootProgramCounter.r32);
    DEVICE.FastBootProgramCounter.bits.Enable.setBaseRegister(&DEVICE.FastBootProgramCounter.r32);

    /** @brief Bitmap for @ref DEVICE_t.ExpansionRomAddr. */ 

    /** @brief Bitmap for @ref DEVICE_t.68f0. */ 

    /** @brief Bitmap for @ref DEVICE_t.EavRefClockControl. */ 
    DEVICE.EavRefClockControl.bits.TimesyncGPIOMapping.setBaseRegister(&DEVICE.EavRefClockControl.r32);
    DEVICE.EavRefClockControl.bits.APEGPIO0Mapping.setBaseRegister(&DEVICE.EavRefClockControl.r32);
    DEVICE.EavRefClockControl.bits.APEGPIO1Mapping.setBaseRegister(&DEVICE.EavRefClockControl.r32);
    DEVICE.EavRefClockControl.bits.APEGPIO2Mapping.setBaseRegister(&DEVICE.EavRefClockControl.r32);
    DEVICE.EavRefClockControl.bits.APEGPIO3Mapping.setBaseRegister(&DEVICE.EavRefClockControl.r32);

    /** @brief Bitmap for @ref DEVICE_t.7c04. */ 


}
