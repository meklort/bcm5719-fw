////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_MII.cpp
///
/// @project    <PROJECT>
///
/// @brief      bcm5719_MII simulation support
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

#include <bcm5719_MII.h>

MII_t MII;

void init_bcm5719_MII(void)
{
    /** @brief Component Registers for @ref MII. */ 
    /** @brief Bitmap for @ref MII_t.Control. */ 
    MII.Control.bits.UnidirectionalMode_GPHYonly_.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.SpeedSelectMSB.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.CollisionTestMode.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.FullDuplexMode.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.RestartAutonegotiation.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.Isolate_GPHYonly_.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.PowerDown.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.AutoNegotiationEnable.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.SpeedSelectLSB.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.LoopbackMode.setBaseRegister(&MII.Control.r16);
    MII.Control.bits.Reset.setBaseRegister(&MII.Control.r16);

    /** @brief Bitmap for @ref MII_t.Status. */ 
    MII.Status.bits.ExtendedCapabilitiesSupported.setBaseRegister(&MII.Status.r16);
    MII.Status.bits.JabberDetected.setBaseRegister(&MII.Status.r16);
    MII.Status.bits.LinkOK.setBaseRegister(&MII.Status.r16);
    MII.Status.bits.AutoNegotiationCapable.setBaseRegister(&MII.Status.r16);
    MII.Status.bits.RemoteFaultDetected.setBaseRegister(&MII.Status.r16);
    MII.Status.bits.AutoNegotiationComplete.setBaseRegister(&MII.Status.r16);
    MII.Status.bits.MFPreambleSuppression.setBaseRegister(&MII.Status.r16);
    MII.Status.bits.UnidirectionalCapable_GPHYonly_.setBaseRegister(&MII.Status.r16);
    MII.Status.bits.ExtendedStatusSupported.setBaseRegister(&MII.Status.r16);
    MII.Status.bits._100BASE_T2HalfDuplexCapable.setBaseRegister(&MII.Status.r16);
    MII.Status.bits._100BASE_T2FullDuplexCapable.setBaseRegister(&MII.Status.r16);
    MII.Status.bits._10BASE_THalfDuplexCapable.setBaseRegister(&MII.Status.r16);
    MII.Status.bits._10BASE_TFullDuplexCapable.setBaseRegister(&MII.Status.r16);
    MII.Status.bits._100BASE_XHalfDuplexCapable.setBaseRegister(&MII.Status.r16);
    MII.Status.bits._100BASE_XFullDuplexCapable.setBaseRegister(&MII.Status.r16);
    MII.Status.bits._100BASE_T4Capable.setBaseRegister(&MII.Status.r16);

    /** @brief Bitmap for @ref MII_t.PhyIdHigh. */ 
    MII.PhyIdHigh.bits.OUIHigh.setBaseRegister(&MII.PhyIdHigh.r16);

    /** @brief Bitmap for @ref MII_t.PhyIdLow. */ 
    MII.PhyIdLow.bits.Revision.setBaseRegister(&MII.PhyIdLow.r16);
    MII.PhyIdLow.bits.Model.setBaseRegister(&MII.PhyIdLow.r16);
    MII.PhyIdLow.bits.OUILow.setBaseRegister(&MII.PhyIdLow.r16);

    /** @brief Bitmap for @ref MII_t.AutonegotiationAdvertisement. */ 
    MII.AutonegotiationAdvertisement.bits.ProtocolSelect.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);
    MII.AutonegotiationAdvertisement.bits._10BASE_THalfDuplexCapable.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);
    MII.AutonegotiationAdvertisement.bits._10BASE_TFullDuplexCapable.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);
    MII.AutonegotiationAdvertisement.bits._100BASE_TXHalfDuplexCapable.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);
    MII.AutonegotiationAdvertisement.bits._100BASE_TXFullDuplexCapable.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);
    MII.AutonegotiationAdvertisement.bits._100BASE_T4Capable.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);
    MII.AutonegotiationAdvertisement.bits.PauseCapable.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);
    MII.AutonegotiationAdvertisement.bits.AsymmetricPauseCapable.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);
    MII.AutonegotiationAdvertisement.bits.RemoteFault.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);
    MII.AutonegotiationAdvertisement.bits.NextPage.setBaseRegister(&MII.AutonegotiationAdvertisement.r16);

    /** @brief Bitmap for @ref MII_t.AutonegotiationLinkPartnerAbilityBasePage. */ 
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits.ProtocolSelector.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits._10BASE_THalfDuplexCapable.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits._10BASE_TFullDuplexCapable.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits._100BASE_TXHalfDuplexCapable.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits._100BASE_TXFullDuplexCapable.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits._100BASE_T4Capable.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits.PauseCapable.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits.AsymmetricPauseCapable.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits.RemoteFault.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits.Acknowledge.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);
    MII.AutonegotiationLinkPartnerAbilityBasePage.bits.NextPage.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityBasePage.r16);

    /** @brief Bitmap for @ref MII_t.AutonegotiationExpansion. */ 
    MII.AutonegotiationExpansion.bits.LinkPartnerAutonegotiationCapable.setBaseRegister(&MII.AutonegotiationExpansion.r16);
    MII.AutonegotiationExpansion.bits.PageReceived.setBaseRegister(&MII.AutonegotiationExpansion.r16);
    MII.AutonegotiationExpansion.bits.NextPageCapable.setBaseRegister(&MII.AutonegotiationExpansion.r16);
    MII.AutonegotiationExpansion.bits.LinkPartnerNextPageCapable.setBaseRegister(&MII.AutonegotiationExpansion.r16);
    MII.AutonegotiationExpansion.bits.ParallelDetectionFault.setBaseRegister(&MII.AutonegotiationExpansion.r16);
    MII.AutonegotiationExpansion.bits.NextPageReceiveLocation.setBaseRegister(&MII.AutonegotiationExpansion.r16);
    MII.AutonegotiationExpansion.bits.NextPageReceiveLocationCapable.setBaseRegister(&MII.AutonegotiationExpansion.r16);

    /** @brief Bitmap for @ref MII_t.AutonegotiationNextPageTransmit. */ 
    MII.AutonegotiationNextPageTransmit.bits.CodeField.setBaseRegister(&MII.AutonegotiationNextPageTransmit.r16);
    MII.AutonegotiationNextPageTransmit.bits.Toggle.setBaseRegister(&MII.AutonegotiationNextPageTransmit.r16);
    MII.AutonegotiationNextPageTransmit.bits.Acknowledge2.setBaseRegister(&MII.AutonegotiationNextPageTransmit.r16);
    MII.AutonegotiationNextPageTransmit.bits.MessagePage.setBaseRegister(&MII.AutonegotiationNextPageTransmit.r16);
    MII.AutonegotiationNextPageTransmit.bits.NextPage.setBaseRegister(&MII.AutonegotiationNextPageTransmit.r16);

    /** @brief Bitmap for @ref MII_t.AutonegotiationLinkPartnerAbilityNextPage. */ 
    MII.AutonegotiationLinkPartnerAbilityNextPage.bits.CodeField.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityNextPage.r16);
    MII.AutonegotiationLinkPartnerAbilityNextPage.bits.Toggle2.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityNextPage.r16);
    MII.AutonegotiationLinkPartnerAbilityNextPage.bits.Acknowledge2.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityNextPage.r16);
    MII.AutonegotiationLinkPartnerAbilityNextPage.bits.MessagePage.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityNextPage.r16);
    MII.AutonegotiationLinkPartnerAbilityNextPage.bits.Acknowledge3.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityNextPage.r16);
    MII.AutonegotiationLinkPartnerAbilityNextPage.bits.NextPage.setBaseRegister(&MII.AutonegotiationLinkPartnerAbilityNextPage.r16);

    /** @brief Bitmap for @ref MII_t.1000baseTControl. */ 
    MII._1000baseTControl.bits.Advertise1000BASE_THalfDuplex.setBaseRegister(&MII._1000baseTControl.r16);
    MII._1000baseTControl.bits.Advertise1000BASE_TFullDuplex.setBaseRegister(&MII._1000baseTControl.r16);
    MII._1000baseTControl.bits.RepeaterDTE.setBaseRegister(&MII._1000baseTControl.r16);
    MII._1000baseTControl.bits.MasterSlaveConfigValue.setBaseRegister(&MII._1000baseTControl.r16);
    MII._1000baseTControl.bits.MasterSlaveConfigEnable.setBaseRegister(&MII._1000baseTControl.r16);
    MII._1000baseTControl.bits.TestMode.setBaseRegister(&MII._1000baseTControl.r16);

    /** @brief Bitmap for @ref MII_t.1000baseTStatus. */ 
    MII._1000baseTStatus.bits.IdleErrorCount.setBaseRegister(&MII._1000baseTStatus.r16);
    MII._1000baseTStatus.bits.LinkPartner1000BASE_THalfDuplexCapable.setBaseRegister(&MII._1000baseTStatus.r16);
    MII._1000baseTStatus.bits.LinkPartner1000BASE_TFullDuplexCapable.setBaseRegister(&MII._1000baseTStatus.r16);
    MII._1000baseTStatus.bits.RemoteReceiverStatus.setBaseRegister(&MII._1000baseTStatus.r16);
    MII._1000baseTStatus.bits.LocalReceiverStatus.setBaseRegister(&MII._1000baseTStatus.r16);
    MII._1000baseTStatus.bits.MasterSlaveConfigResolution.setBaseRegister(&MII._1000baseTStatus.r16);
    MII._1000baseTStatus.bits.MasterSlaveConfigFault.setBaseRegister(&MII._1000baseTStatus.r16);

    /** @brief Bitmap for @ref MII_t.BroadreachLreAccess. */ 
    MII.BroadreachLreAccess.bits.LRERegisterAccessStatus.setBaseRegister(&MII.BroadreachLreAccess.r16);
    MII.BroadreachLreAccess.bits.LRERegisterOverrideValue.setBaseRegister(&MII.BroadreachLreAccess.r16);
    MII.BroadreachLreAccess.bits.EnableLRERegisterAccessOverride.setBaseRegister(&MII.BroadreachLreAccess.r16);

    /** @brief Bitmap for @ref MII_t.IeeeExtendedStatus. */ 
    MII.IeeeExtendedStatus.bits._1000BASE_THalfDuplexCapable.setBaseRegister(&MII.IeeeExtendedStatus.r16);
    MII.IeeeExtendedStatus.bits._1000BASE_TFullDuplexCapable.setBaseRegister(&MII.IeeeExtendedStatus.r16);
    MII.IeeeExtendedStatus.bits._1000BASE_XHalfDuplexCapable.setBaseRegister(&MII.IeeeExtendedStatus.r16);

    /** @brief Bitmap for @ref MII_t.PhyExtendedStatus. */ 
    MII.PhyExtendedStatus.bits.MLT3CodeErrorDetected.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.LockErrorDetected.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.TransmitErrorDetected.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.ReceiveErrorDetected.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.BadESDDetected.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.BadSSDDetected.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.CarrierExtensionErrorDetected.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.CRCErrorDetected.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.LinkStatus.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.Locked.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.LocalReceiverStatus.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.RemoteReceiverStatus.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.InterruptStatus.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.MDICrossoverState.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.WirespeedDowngrade.setBaseRegister(&MII.PhyExtendedStatus.r16);
    MII.PhyExtendedStatus.bits.AutonegotiationBasePageSelectorFieldMismatch.setBaseRegister(&MII.PhyExtendedStatus.r16);

    /** @brief Bitmap for @ref MII_t.ReceiveErrorCounter. */ 
    MII.ReceiveErrorCounter.bits.ReceiveErrorCounter.setBaseRegister(&MII.ReceiveErrorCounter.r16);

    /** @brief Bitmap for @ref MII_t.FalseCarrierSenseCounter. */ 
    MII.FalseCarrierSenseCounter.bits.FalseCarrierSenseCounter.setBaseRegister(&MII.FalseCarrierSenseCounter.r16);
    MII.FalseCarrierSenseCounter.bits.SERDESBERCounter.setBaseRegister(&MII.FalseCarrierSenseCounter.r16);

    /** @brief Bitmap for @ref MII_t.LocalRemoteReceiverNotOkCounter. */ 
    MII.LocalRemoteReceiverNotOkCounter.bits.RemoteReceiverNotOKCounter.setBaseRegister(&MII.LocalRemoteReceiverNotOkCounter.r16);
    MII.LocalRemoteReceiverNotOkCounter.bits.LocalReceiverNotOKCounter.setBaseRegister(&MII.LocalRemoteReceiverNotOkCounter.r16);

    /** @brief Bitmap for @ref MII_t.AuxillaryStatusSummary. */ 
    MII.AuxillaryStatusSummary.bits.PauseResolution_TransmitDirection.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.PauseResolution_ReceiveDirection.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.LinkStatus.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.LinkPartnerNextPageCapable.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.LinkPartnerAutonegotiationCapable.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.PageReceived.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.RemoteFault.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.ParallelDetectionFault.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.AutonegotiationHCD.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.AutonegotiationNextPageWait.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.AutonegotiationAbilityDetect.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.AutonegotiationACKDetect.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.AutonegotiationCompleteACK.setBaseRegister(&MII.AuxillaryStatusSummary.r16);
    MII.AuxillaryStatusSummary.bits.AutonegotiationComplete.setBaseRegister(&MII.AuxillaryStatusSummary.r16);

    /** @brief Bitmap for @ref MII_t.InterruptStatus. */ 
    MII.InterruptStatus.bits.CRCError.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.LinkStatusChange.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.LinkSpeedChange.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.DuplexModeChange.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.LocalReceiverStatusChange.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.RemoteReceiverStatusChange.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.ScramblerSyncError.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.NegotiatedUnsupportedHCD.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.NoHCD.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.HCDNoLink.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.AutonegotiationPageRX.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.ExceededLowCounterThreshold.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.MDIXStatusChange.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.IllegalPairSwap.setBaseRegister(&MII.InterruptStatus.r16);
    MII.InterruptStatus.bits.IPStatusChange.setBaseRegister(&MII.InterruptStatus.r16);

    /** @brief Bitmap for @ref MII_t.InterruptMask. */ 
    MII.InterruptMask.bits.InterruptMaskVector.setBaseRegister(&MII.InterruptMask.r16);

    /** @brief Bitmap for @ref MII_t.Test1. */ 
    MII.Test1.bits.MainDACTrim.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.MainDACEnableSoftwareTrimSetting.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.DisablePolarityEncode.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.ReceiveWatchdogTimerDisable.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.ManualSwapMDIState.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.FastTimers.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.ExternalLink.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.ScramblerTest.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.ForceLock.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.ForceLink.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.CounterTestMode.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.TransmitErrorCodeVisibility.setBaseRegister(&MII.Test1.r16);
    MII.Test1.bits.CRCErrorCountVisibility.setBaseRegister(&MII.Test1.r16);


}
