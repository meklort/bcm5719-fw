////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_GEN.cpp
///
/// @project    <PROJECT>
///
/// @brief      bcm5719_GEN simulation support
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

#include <bcm5719_GEN.h>

GEN_t GEN;

void init_bcm5719_GEN(void)
{
    /** @brief Component Registers for @ref GEN. */ 
    /** @brief Bitmap for @ref GEN_t.GenFwMbox. */ 

    /** @brief Bitmap for @ref GEN_t.GenDataSig. */ 

    /** @brief Bitmap for @ref GEN_t.GenCfg. */ 
    GEN.GenCfg.bits.PHYType_GPHY.setBaseRegister(&GEN.GenCfg.r32);
    GEN.GenCfg.bits.PHYType_SERDES.setBaseRegister(&GEN.GenCfg.r32);
    GEN.GenCfg.bits.WOLEnable.setBaseRegister(&GEN.GenCfg.r32);
    GEN.GenCfg.bits.TODO.setBaseRegister(&GEN.GenCfg.r32);

    /** @brief Bitmap for @ref GEN_t.GenVersion. */ 

    /** @brief Bitmap for @ref GEN_t.GenPhyId. */ 

    /** @brief Bitmap for @ref GEN_t.GenAsfStatusMbox. */ 

    /** @brief Bitmap for @ref GEN_t.GenFwDriverStateMbox. */ 

    /** @brief Bitmap for @ref GEN_t.GenFwResetTypeMbox. */ 

    /** @brief Bitmap for @ref GEN_t.GenBc. */ 

    /** @brief Bitmap for @ref GEN_t.GenMacAddrHighMbox. */ 

    /** @brief Bitmap for @ref GEN_t.GenMacAddrLowMbox. */ 

    /** @brief Bitmap for @ref GEN_t.GenD8. */ 
    GEN.GenD8.bits.SkipMainLoopInit.setBaseRegister(&GEN.GenD8.r32);
    GEN.GenD8.bits.ForceWOL.setBaseRegister(&GEN.GenD8.r32);
    GEN.GenD8.bits.NoModifyMiscellaneousControl.setBaseRegister(&GEN.GenD8.r32);
    GEN.GenD8.bits.unknown_7_7.setBaseRegister(&GEN.GenD8.r32);

    /** @brief Bitmap for @ref GEN_t.Gen1dc. */ 

    /** @brief Bitmap for @ref GEN_t.GenWolMbox. */ 

    /** @brief Bitmap for @ref GEN_t.GenCfgFeature. */ 
    GEN.GenCfgFeature.bits.WOLEnable.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.PXEEnable.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.PXESpeed.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.ASFEnable.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.PXEBARSize.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.DisableSetupMessage.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.HotkeyOption.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.PXEBootstrapType.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.PXEMessageTimeout.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.PXEBootProtocol.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.LOMDesign.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.VAUXCutoffDelay.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.WOLLimit10.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.LinkIdle.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.unknown_27_27.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.CableSense.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.MBAVLANEnable.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.LinkAwarePowerMode.setBaseRegister(&GEN.GenCfgFeature.r32);
    GEN.GenCfgFeature.bits.LinkSpeedPowerMode.setBaseRegister(&GEN.GenCfgFeature.r32);

    /** @brief Bitmap for @ref GEN_t.GenCfgHw. */ 
    GEN.GenCfgHw.bits.LegacyLEDControl.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.ReverseN_Way.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.MiniPCI.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.AutoPowerdownEnable.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.SHASTALEDControl.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.TimeSyncModeEnable.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.TimesyncGPIOMapping.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.APEGPIO0Mapping.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.APEGPIO1Mapping.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.APEGPIO2Mapping.setBaseRegister(&GEN.GenCfgHw.r32);
    GEN.GenCfgHw.bits.APEGPIO3Mapping.setBaseRegister(&GEN.GenCfgHw.r32);

    /** @brief Bitmap for @ref GEN_t.GenCfgShared. */ 
    GEN.GenCfgShared.bits.PortSwap.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.ASPMDebounce.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.FiberWoLCapable.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.DisablePowerSaving.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.unknown_7_7.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.unknown_8_8.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.unknown_10_9.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.unknown_15_15.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.LinkFlapAvoid.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits._1GonVAUXOK.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.unknown_27_26.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.unknown_29_28.setBaseRegister(&GEN.GenCfgShared.r32);
    GEN.GenCfgShared.bits.unknown_31_30.setBaseRegister(&GEN.GenCfgShared.r32);

    /** @brief Bitmap for @ref GEN_t.GenFwVersion. */ 

    /** @brief Bitmap for @ref GEN_t.GenCfgHw2. */ 
    GEN.GenCfgHw2.bits.EnableAutonegotiation.setBaseRegister(&GEN.GenCfgHw2.r32);
    GEN.GenCfgHw2.bits.ExpansionROMEnable.setBaseRegister(&GEN.GenCfgHw2.r32);
    GEN.GenCfgHw2.bits.unknown_2_2.setBaseRegister(&GEN.GenCfgHw2.r32);
    GEN.GenCfgHw2.bits.UnknownSERDES1310.setBaseRegister(&GEN.GenCfgHw2.r32);
    GEN.GenCfgHw2.bits.UnknownSERDES1312.setBaseRegister(&GEN.GenCfgHw2.r32);
    GEN.GenCfgHw2.bits.UnknownSERDES1010_01.setBaseRegister(&GEN.GenCfgHw2.r32);
    GEN.GenCfgHw2.bits.UnknownSERDES1010_10.setBaseRegister(&GEN.GenCfgHw2.r32);

    /** @brief Bitmap for @ref GEN_t.GenCpmuStatus. */ 

    /** @brief Bitmap for @ref GEN_t.GenCfg5. */ 
    GEN.GenCfg5.bits.unknown_0_0.setBaseRegister(&GEN.GenCfg5.r32);
    GEN.GenCfg5.bits.Disable1GHalfAdv.setBaseRegister(&GEN.GenCfg5.r32);
    GEN.GenCfg5.bits.unknown_3_2.setBaseRegister(&GEN.GenCfg5.r32);


}
