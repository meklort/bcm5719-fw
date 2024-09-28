////////////////////////////////////////////////////////////////////////////////
///
/// @file       tests.cpp
///
/// @project
///
/// @brief      NVRam tests
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

#include "gtest/gtest.h"
#include "../bcm5719_NVM.h"

#include <bcm5719-endian.h>
#include <NVRam.h>
namespace
{

class NVRamTests : public testing::Test {
    void SetUp() override {
        NVM.SoftwareArbitration.r32.installWriteCallback(
            [](uint32_t val, uint32_t offset, void *args) -> uint32_t
            {
                return static_cast<NVRamTests *>(args)->WriteSoftwareArbitration(val, offset);
            }
            , this);
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
        // NVM.SoftwareArbitration.r32.
    }

    uint32_t WriteSoftwareArbitration(uint32_t val, uint32_t offset)
    {
        uint32_t newVal = NVM.SoftwareArbitration.r32.getValue();

        // Copy req set to Req bits.
        newVal |= (val & (NVM_SOFTWARE_ARBITRATION_REQ_SET0_MASK | NVM_SOFTWARE_ARBITRATION_REQ_SET1_MASK | NVM_SOFTWARE_ARBITRATION_REQ_SET2_MASK | NVM_SOFTWARE_ARBITRATION_REQ_SET3_MASK)) << (NVM_SOFTWARE_ARBITRATION_REQ0_SHIFT - NVM_SOFTWARE_ARBITRATION_REQ_SET0_SHIFT);
        // Clear any Clr bits.
        newVal &= ~(val & (NVM_SOFTWARE_ARBITRATION_REQ_CLR0_MASK | NVM_SOFTWARE_ARBITRATION_REQ_CLR1_MASK | NVM_SOFTWARE_ARBITRATION_REQ_CLR2_MASK | NVM_SOFTWARE_ARBITRATION_REQ_CLR3_MASK)) << (NVM_SOFTWARE_ARBITRATION_REQ0_SHIFT - NVM_SOFTWARE_ARBITRATION_REQ_CLR0_SHIFT);


        // Clear Won bit if Req bits not set.
        newVal &= ((newVal | ~(NVM_SOFTWARE_ARBITRATION_REQ0_MASK | NVM_SOFTWARE_ARBITRATION_REQ1_MASK | NVM_SOFTWARE_ARBITRATION_REQ2_MASK | NVM_SOFTWARE_ARBITRATION_REQ3_MASK))) >> (NVM_SOFTWARE_ARBITRATION_REQ0_SHIFT - NVM_SOFTWARE_ARBITRATION_ARB_WON0_SHIFT);

        // Set new Won bit.
        if (0 == (newVal & (NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK)))
        {
            // Set Won bit, priority encoded
            if (newVal & NVM_SOFTWARE_ARBITRATION_REQ0_MASK)
            {
                newVal |= NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK;
            }
            else if (newVal & NVM_SOFTWARE_ARBITRATION_REQ1_MASK)
            {
                newVal |= NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK;
            }
            else if (newVal & NVM_SOFTWARE_ARBITRATION_REQ2_MASK)
            {
                newVal |= NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK;
            }
            else if (newVal & NVM_SOFTWARE_ARBITRATION_REQ3_MASK)
            {
                newVal |= NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK;
            }
        }

        return newVal;
    }
};

TEST_F(NVRamTests, NVRam_acquireLock)
{
    NVRam_acquireLock();
    EXPECT_NE(NVM.SoftwareArbitration.r32 & (NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK), 0);
    NVRam_releaseLock();
    EXPECT_EQ(NVM.SoftwareArbitration.r32 & (NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK), 0);
}

TEST_F(NVRamTests, NVRam_releaseAllLocks)
{
    NVRam_acquireLock();
    EXPECT_NE(NVM.SoftwareArbitration.r32 & (NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK), 0);
    NVRam_releaseAllLocks();
    EXPECT_EQ(NVM.SoftwareArbitration.r32 & (NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK), 0);
}

TEST_F(NVRamTests, NVRam_releaseAllLocks_allReqs)
{
    RegNVMSoftwareArbitration_t req;
    req.r32 = 0;
    req.bits.ReqSet0 = 1;
    req.bits.ReqSet1 = 1;
    req.bits.ReqSet2 = 1;
    req.bits.ReqSet3 = 1;
    NVM.SoftwareArbitration = req;

    EXPECT_NE(NVM.SoftwareArbitration.r32 & (NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK), 0);

    // Release our lock only
    NVRam_releaseLock();
    EXPECT_NE(NVM.SoftwareArbitration.r32 & (NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK), 0);

    NVRam_releaseAllLocks();
    EXPECT_EQ(NVM.SoftwareArbitration.r32 & (NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK | NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK), 0);
}


} // namespace
