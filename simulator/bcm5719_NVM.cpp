////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_NVM.cpp
///
/// @project    <PROJECT>
///
/// @brief      bcm5719_NVM simulation support
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

#include <bcm5719_NVM.h>

NVM_t NVM;

void init_bcm5719_NVM(void)
{
    /** @brief Component Registers for @ref NVM. */ 
    /** @brief Bitmap for @ref NVM_t.Command. */ 
    NVM.Command.bits.Done.setBaseRegister(&NVM.Command.r32);
    NVM.Command.bits.Doit.setBaseRegister(&NVM.Command.r32);
    NVM.Command.bits.Wr.setBaseRegister(&NVM.Command.r32);
    NVM.Command.bits.Erase.setBaseRegister(&NVM.Command.r32);
    NVM.Command.bits.First.setBaseRegister(&NVM.Command.r32);
    NVM.Command.bits.Last.setBaseRegister(&NVM.Command.r32);
    NVM.Command.bits.WriteEnableCommand.setBaseRegister(&NVM.Command.r32);
    NVM.Command.bits.WriteDisableCommand.setBaseRegister(&NVM.Command.r32);

    /** @brief Bitmap for @ref NVM_t.Write. */ 

    /** @brief Bitmap for @ref NVM_t.Addr. */ 

    /** @brief Bitmap for @ref NVM_t.Read. */ 

    /** @brief Bitmap for @ref NVM_t.NvmCfg1. */ 
    NVM.NvmCfg1.bits.FlashMode.setBaseRegister(&NVM.NvmCfg1.r32);
    NVM.NvmCfg1.bits.BufferMode.setBaseRegister(&NVM.NvmCfg1.r32);
    NVM.NvmCfg1.bits.SPICLKDIV.setBaseRegister(&NVM.NvmCfg1.r32);
    NVM.NvmCfg1.bits.ProtectMode.setBaseRegister(&NVM.NvmCfg1.r32);
    NVM.NvmCfg1.bits.FlashSize.setBaseRegister(&NVM.NvmCfg1.r32);
    NVM.NvmCfg1.bits.PageSize.setBaseRegister(&NVM.NvmCfg1.r32);

    /** @brief Bitmap for @ref NVM_t.SoftwareArbitration. */ 
    NVM.SoftwareArbitration.bits.ReqSet0.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ReqSet1.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ReqSet2.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ReqSet3.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ReqClr0.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ReqClr1.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ReqClr2.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ReqClr3.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ArbWon0.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ArbWon1.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ArbWon2.setBaseRegister(&NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.ArbWon3.setBaseRegister(&NVM.SoftwareArbitration.r32);

    /** @brief Bitmap for @ref NVM_t.Access. */ 
    NVM.Access.bits.Enable.setBaseRegister(&NVM.Access.r32);
    NVM.Access.bits.WriteEnable.setBaseRegister(&NVM.Access.r32);


}
