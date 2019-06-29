////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_HAL.cpp
///
/// @project
///
/// @brief      C++ Register wrapper code for the APE
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

#include <HAL.hpp>
#include <APE_NVIC.h>
#include <APE_FILTERS0.h>
#include <APE_FILTERS1.h>
#include <APE_FILTERS2.h>
#include <APE_FILTERS3.h>
#include <APE_TX_PORT0.h>
#include <APE_RX_PORT0.h>
#include <APE_TX_PORT1.h>
#include <APE_RX_PORT1.h>
#include <APE_TX_PORT2.h>
#include <APE_RX_PORT2.h>
#include <APE_TX_PORT3.h>
#include <APE_RX_PORT3.h>
#include <APE_DEVICE.h>
#include <APE_DEVICE1.h>
#include <APE_DEVICE2.h>
#include <APE_DEVICE3.h>

void initAPEHAL(void)
{
    // init_APE_DEVICE0();
    // init_APE_DEVICE0_sim(NULL);
    init_APE_DEVICE1();
    init_APE_DEVICE1_sim(NULL);
    init_APE_DEVICE2();
    init_APE_DEVICE2_sim(NULL);
    init_APE_DEVICE3();
    init_APE_DEVICE3_sim(NULL);

    init_APE_FILTERS0();
    init_APE_FILTERS0_sim(NULL);

    init_APE_FILTERS1();
    init_APE_FILTERS1_sim(NULL);

    init_APE_FILTERS2();
    init_APE_FILTERS2_sim(NULL);

    init_APE_FILTERS3();
    init_APE_FILTERS3_sim(NULL);

    init_APE_NVIC();
    init_APE_NVIC_sim(NULL);

    init_APE_TX_PORT0();
    init_APE_TX_PORT0_sim(NULL);

    init_APE_RX_PORT0();
    init_APE_RX_PORT0_sim(NULL);

    init_APE_TX_PORT1();
    init_APE_TX_PORT1_sim(NULL);

    init_APE_RX_PORT1();
    init_APE_RX_PORT1_sim(NULL);

    init_APE_TX_PORT2();
    init_APE_TX_PORT2_sim(NULL);

    init_APE_RX_PORT2();
    init_APE_RX_PORT2_sim(NULL);

    init_APE_TX_PORT3();
    init_APE_TX_PORT3_sim(NULL);

    init_APE_RX_PORT3();
    init_APE_RX_PORT3_sim(NULL);
}