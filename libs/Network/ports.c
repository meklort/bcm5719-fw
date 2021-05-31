////////////////////////////////////////////////////////////////////////////////
///
/// @file       ports.c
///
/// @project
///
/// @brief      Port specific initialization and data structures.
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018-2021 Evan Lojewski
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

#include <APE.h>
#include <APE_DEVICE1.h>
#include <APE_DEVICE2.h>
#include <APE_DEVICE3.h>
#include <APE_FILTERS1.h>
#include <APE_FILTERS2.h>
#include <APE_FILTERS3.h>
#include <APE_RX_PORT1.h>
#include <APE_RX_PORT2.h>
#include <APE_RX_PORT3.h>
#include <APE_SHM.h>
#include <APE_SHM1.h>
#include <APE_SHM2.h>
#include <APE_SHM3.h>
#include <APE_SHM_CHANNEL0.h>
#include <APE_SHM_CHANNEL1.h>
#include <APE_SHM_CHANNEL2.h>
#include <APE_SHM_CHANNEL3.h>
#include <APE_TX_PORT1.h>
#include <APE_TX_PORT2.h>
#include <APE_TX_PORT3.h>
#include <MII.h>
#include <Network.h>

#ifdef CXX_SIMULATOR
#include <stdio.h>
#else
#include <printf.h>
#endif

NetworkPort_t gPort0 = {
    .device = &DEVICE,
    .filters = &FILTERS0,
    .shm_channel = &SHM_CHANNEL0,
    .shm = &SHM,

    .tx_port = &TX_PORT0,
    .tx_allocator = &APE.TxToNetBufferAllocator0,
    .tx_doorbell = &APE.TxToNetDoorbellFunc0,
    .tx_ring = &APE.TxToNetBufferRing0,
    .tx_mode = &APE.TxToNetPoolModeStatus0,

    .rx_port = &RX_PORT0,
    .rx_offset = &APE.RxbufoffsetFunc0,
    .rx_retire = &APE.RxPoolRetire0,
    .rx_ring = &APE.RxPoolFreePointer0,
    .rx_mode = &APE.RxPoolModeStatus0,

#ifndef CXX_SIMULATOR
    .APEModeEnable = {
        .r32 = APE_MODE_CHANNEL_0_ENABLE_MASK | APE_MODE_CHANNEL_2_ENABLE_MASK,
    },
    .APEMode2Enable = {
        .r32 = 0,
    },
    .APEStatus = {
        .r32 = APE_STATUS_PORT_0_GRC_RESET_MASK,
    },
    .APEStatus2 = {
        .r32 = 0,
    },
#endif
};

NetworkPort_t gPort1 = {
    .device = &DEVICE1,
    .filters = &FILTERS1,
    .shm_channel = &SHM_CHANNEL1,
#ifndef CXX_SIMULATOR
    .shm = &SHM1,
#else
    .shm = &SHM,
#endif

    .tx_port = &TX_PORT1,
    .tx_allocator = &APE.TxToNetBufferAllocator1,
    .tx_doorbell = &APE.TxToNetDoorbellFunc1,
    .tx_ring = &APE.TxToNetBufferRing1,
    .tx_mode = &APE.TxToNetPoolModeStatus1,

    .rx_port = &RX_PORT1,
    .rx_offset = &APE.RxbufoffsetFunc1,
    .rx_retire = &APE.RxPoolRetire1,
    .rx_ring = &APE.RxPoolFreePointer1,
    .rx_mode = &APE.RxPoolModeStatus1,

#ifndef CXX_SIMULATOR
    .APEModeEnable = {
        .r32 = APE_MODE_CHANNEL_1_ENABLE_MASK | APE_MODE_CHANNEL_3_ENABLE_MASK,
    },
    .APEMode2Enable = {
        .r32 = 0,
    },
    .APEStatus = {
        .r32 = APE_STATUS_PORT_1_GRC_RESET_MASK,
    },
    .APEStatus2 = {
        .r32 = 0,
    },
#endif
};

NetworkPort_t gPort2 = {
    .device = &DEVICE2,
    .filters = &FILTERS2,
    .shm_channel = &SHM_CHANNEL2,
#ifndef CXX_SIMULATOR
    .shm = &SHM2,
#else
    .shm = &SHM,
#endif

    .tx_port = &TX_PORT2,
    .tx_allocator = &APE.TxToNetBufferAllocator2,
    .tx_doorbell = &APE.TxToNetDoorbellFunc2,
    .tx_ring = &APE.TxToNetBufferRing2,
    .tx_mode = &APE.TxToNetPoolModeStatus2,

    .rx_port = &RX_PORT2,
    .rx_offset = &APE.RxbufoffsetFunc2,
    .rx_retire = &APE.RxPoolRetire2,
    .rx_ring = &APE.RxPoolFreePointer2,
    .rx_mode = &APE.RxPoolModeStatus2,

#ifndef CXX_SIMULATOR
    .APEModeEnable = {
        .r32 = APE_MODE_CHANNEL_0_ENABLE_MASK | APE_MODE_CHANNEL_2_ENABLE_MASK,
    },
    .APEMode2Enable = {
        .r32 = APE_MODE_2_CHANNEL_0_ENABLE_MASK | APE_MODE_2_CHANNEL_2_ENABLE_MASK,
    },
    .APEStatus = {
        .r32 = 0,
    },
    .APEStatus2 = {
        .r32 = APE_STATUS_2_PORT_2_GRC_RESET_MASK,
    },
#endif
};

NetworkPort_t gPort3 = {
    .device = &DEVICE3,
    .filters = &FILTERS3,
    .shm_channel = &SHM_CHANNEL3,
#ifndef CXX_SIMULATOR
    .shm = &SHM3,
#else
    .shm = &SHM,
#endif

    .tx_port = &TX_PORT3,
    .tx_allocator = &APE.TxToNetBufferAllocator3,
    .tx_doorbell = &APE.TxToNetDoorbellFunc3,
    .tx_ring = &APE.TxToNetBufferRing3,
    .tx_mode = &APE.TxToNetPoolModeStatus3,

    .rx_port = &RX_PORT3,
    .rx_offset = &APE.RxbufoffsetFunc3,
    .rx_retire = &APE.RxPoolRetire3,
    .rx_ring = &APE.RxPoolFreePointer3,
    .rx_mode = &APE.RxPoolModeStatus3,

#ifndef CXX_SIMULATOR
    .APEModeEnable = {
        .r32 = APE_MODE_CHANNEL_1_ENABLE_MASK | APE_MODE_CHANNEL_3_ENABLE_MASK,
    },
    .APEMode2Enable = {
        .r32 = APE_MODE_2_CHANNEL_1_ENABLE_MASK | APE_MODE_2_CHANNEL_3_ENABLE_MASK,
    },
    .APEStatus = {
        .r32 = 0,
    },
    .APEStatus2 = {
        .r32 = APE_STATUS_2_PORT_3_GRC_RESET_MASK,
    },
#endif
};

NetworkPort_t *Network_getPort(int i)
{
    switch (i)
    {
        default:
            return &gPort0;
        case 0:
            return &gPort0;
        case 1:
            return &gPort1;
        case 2:
            return &gPort2;
        case 3:
            return &gPort3;
    }
}
#ifndef CXX_SIMULATOR
typedef struct
{
    RegFILTERSElementConfig_t cfg;
    RegFILTERSElementPattern_t pat;
} FilterElementInit_t;

static const FilterElementInit_t gElementInit[32] = {
    [0] = {{0}},
    [1] = {{0}},
    [2] = {{0}},
    [3] = {{0}},
    [4] = {{0}},
    [5] = {{0}},
    [6] = {{0}},
    [7] = {{0}},
    [8] = {{0}},
    [9] = {{0}},
    [10] = {{0}},
    [11] = {{0}},
    [12] = {{0}},
    [13] = {{0}},
    [14] = {{0}},
    [15] = {{0}},

    // 16: Check MAC address multicast bit not set.
    [16] = {
        .cfg = { .bits = {
            .RuleOffset = 0,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_SOF,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_NE,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0x01000100},
    },

    [17] = {{0}},
    [18] = {{0}},

    // 19: Special VLAN match.
    [19] = {
        .cfg = { .bits = {
            .RuleOffset = 0,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_VLAN,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0},
    },

    // 20: IPv6 Neighbor Advertisement.
    [20] = {
        .cfg = { .bits = {
            .RuleOffset = 0,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_ICMPV6,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 0, // Disabled
        }},
        .pat = {.r32 = 0x8800FF00},
    },

    // 21: IPv6 Router Advertisement.
    [21] = {
        .cfg = { .bits = {
            .RuleOffset = 0,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_ICMPV6,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 0, // Disabled
        }},
        .pat = {.r32 = 0x8600FF00},
    },

    // 22: DHCPv6 Server.
    [22] = {
        .cfg = { .bits = {
            .RuleOffset = 2,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_UDP,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 0, // Disabled
        }},
        .pat = {.r32 = 0x0223FFFF},
    },

    [23] = {{0}},

    // 24: ARP match.
    [24] = {
        .cfg = { .bits = {
            .RuleOffset = 12,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_SOF,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0x0806FFFF},
    },

    // 25: DHCPv4.
    [25] = {
        .cfg = { .bits = {
            .RuleOffset = 2,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_UDP,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0x0044FFFF},
    },

    // 26: DHCPv4.
    [26] = {
        .cfg = { .bits = {
            .RuleOffset = 2,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_UDP,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0x0043FFFF},
    },

    // 27: NetBIOS
    [27] = {
        .cfg = { .bits = {
            .RuleOffset = 2,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_UDP,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0x0088FFFC},
    },

    // 28: Broadcast address match.
    [28] = {
        .cfg = { .bits = {
            .RuleOffset = 0,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_SOF,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 0,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0xFFFFFFFF},
    },

    // 29: Broadcast address match.
    [29] = {
        .cfg = { .bits = {
            .RuleOffset = 4,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_SOF,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0xFFFFFFFF},
    },

    // 30: IPv6 multicast.
    [30] = {
        .cfg = { .bits = {
            .RuleOffset = 0,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_SOF,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0x3333FFFF},
    },
    // 31: Check MAC address multicast bit is set.
    [31] = {
        .cfg = { .bits = {
            .RuleOffset = 0,
            .RuleClass = 0,
            .RuleHeader = FILTERS_ELEMENT_CONFIG_RULE_HEADER_SOF,
            .RuleOp = FILTERS_ELEMENT_CONFIG_RULE_OP_EQ,
            .reserved_23_18 = 0,
            .RuleMap = 0,
            .RuleDiscard = 0,
            .RuleMask = 1,
            .RuleP3 = 0,
            .RuleP2 = 0,
            .RuleP1 = 0,
            .RuleAnd = 0,
            .RuleEnable = 1,
        }},
        .pat = {.r32 = 0x01000100},
    },

};

typedef struct
{
    RegFILTERSRuleSet_t set;
    RegFILTERSRuleMask_t mask;
} FilterRuleInit_t;
static const FilterRuleInit_t gRuleInit[32] = {
    // S-0. Unused.
    [0] = {{0}},

    // S-1. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=1, MASK=0x0003_0000.
    [1] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x00030000},
    },

    // S-2. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=1, MASK=0x0005_0000.
    [2] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x00050000},
    },

    // S-3. ACTION=TO_APE_AND_HOST, COUNT=2, ENABLE=recommend 1, MASK=0x0009_0000
    [3] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 2,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x00090000},
    },

    // S-4. ACTION=T0_APE_AND_HOST, COUNT=0, ENABLE=1, MASK=0x0001_0000.
    [4] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x00010000},
    },

    // S-5. Not used, initialize to zero.
    [5] = {{0}},
    // S-6. Not used, initialize to zero.
    [6] = {{0}},
    // S-7. Not used, initialize to zero.
    [7] = {{0}},
    // S-8. Not used, initialize to zero.
    [8] = {{0}},

    // S-9. ACTION=TO_APE_AND_HOST, COUNT=2, ENABLE=recommend 1, MASK=0x3008_0000.
    [9] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 2,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x30080000},
    },

    // S-10. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=1 (essential for RX), MASK=0x3100_0000.
    [10] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x31000000},
    },

    // S-11. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=1 (essential for RX), MASK=0x3200_0000.
    [11] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x32000000},
    },

    // S-12. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=1 (essential for RX), MASK=0x3400_0000.
    [12] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x34000000},
    },

    // S-13. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=1 (essential for RX), MASK=0x3800_0000.
    [13] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x38000000},
    },

    // S-14. ACTION=TO_APE_AND_HOST, COUNT=2, ENABLE=1 (essential for RX), MASK=0x3000_0000.
    [14] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 2,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x30000000},
    },

    // S-15. Not used, initialize to zero.
    [15] = {{0}},
    // S-16. Not used, initialize to zero.
    [16] = {{0}},
    // S-17. Not used, initialize to zero.
    [17] = {{0}},

    // S-18. ACTION=TO_APE_AND_HOST, COUNT=2, ENABLE=recommend 1, MASK=0x8008_0000.
    [18] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 2,
            .reserved_30_19 = 0,
            .Enable = 1,
        }},
        .mask = {.r32 = 0x80080000},
    },

    // S-19. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=(0b11)<<(2*0).
    [19] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = (0x3)<<(2*0)},
    },

    // S-20. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=(0b11)<<(2*1).
    [20] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = (0x3)<<(2*1)},
    },

    // S-21. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=(0b11)<<(2*2).
    [21] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = (0x3)<<(2*2)},
    },

    // S-22. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=(0b11)<<(2*3).
    [22] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = (0x3)<<(2*3)},
    },

    // S-23. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=(0b11)<<(2*4).
    [23] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = (0x3)<<(2*4)},
    },

    // S-24. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=(0b11)<<(2*5).
    [24] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = (0x3)<<(2*5)},
    },

    // S-25. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=(0b11)<<(2*6).
    [25] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = (0x3)<<(2*6)},
    },

    // S-26. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=(0b11)<<(2*7).
    [26] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = (0x3)<<(2*7)},
    },

    // S-27. Not used, initialize to zero.
    [27] = {{0}},

    // S-28. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=0x4010_0000.
    [28] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = 0x40100000},
    },

    // S-29. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=0x4020_0000.
    [29] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = 0x40200000},
    },

    // S-30. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=0x4020_0000.
    [30] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = 0x40200000},
    },

    // S-31. ACTION=TO_APE_AND_HOST, COUNT=0, ENABLE=0, MASK=0x8000_0000.
    [31] = {
        .set = {.bits = {
            .Action = FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST,
            .reserved_2_2 = 0,
            .Count = 0,
            .reserved_30_19 = 0,
            .Enable = 0,
        }},
        .mask = {.r32 = 0x80000000},
    },
};
#endif

void Network_InitFilters(NetworkPort_t *port)
{
#ifdef CXX_SIMULATOR
    (void)port;
#else
    for (int i = 0; i < 32; i++)
    {
        port->filters->ElementConfig[i] = gElementInit[i].cfg;
        port->filters->ElementPattern[i] = gElementInit[i].pat;
    }

    for (int i = 1; i < 32; i++)
    {
        port->filters->RuleSet[i - 1] = gRuleInit[i].set;
        port->filters->RuleMask[i - 1] = gRuleInit[i].mask;
    }

    port->filters->RuleConfiguration.r32 = 0;
#endif
}

void Network_resetTX(NetworkPort_t *port, reload_type_t reset_phy)
{
    // Enable TX
    RegAPETxToNetPoolModeStatus_t txMode = *port->tx_mode;
    if ((ALWAYS_RESET == reset_phy) || txMode.bits.Error)
    {
        txMode.bits.Reset = 1;
        *(port->tx_mode) = txMode;
    }

    if (!txMode.bits.Enable)
    {
        txMode.bits.Reset = 0;
        txMode.bits.Enable = 1;
        *(port->tx_mode) = txMode;
    }
}

void Network_resetRX(NetworkPort_t *port, reload_type_t reset_phy)
{
    RegAPERxPoolModeStatus_t rxMode = *port->rx_mode;
    if ((ALWAYS_RESET == reset_phy) || rxMode.bits.Error)
    {
        // Enable RX
        rxMode.bits.Reset = 1;
        *(port->rx_mode) = rxMode;
    }

    if (!rxMode.bits.Enable)
    {
        rxMode.bits.Reset = 0;
        rxMode.bits.Enable = 1;
        *(port->rx_mode) = rxMode;
    }
}

bool Network_checkEnableState(NetworkPort_t *port)
{
    // Ensure APE mode is set properly
    if ((APE.Mode.r32 & port->APEModeEnable.r32) != port->APEModeEnable.r32)
    {
        return false;
    }

    // Ensure APE mode2 is set properly
    if ((APE.Mode2.r32 & port->APEMode2Enable.r32) != port->APEMode2Enable.r32)
    {
        return false;
    }

    return true;
}

void Network_InitPort(NetworkPort_t *port, reload_type_t reset_phy)
{
    RegMIIStatus_t stat;
    RegMIIIeeeExtendedStatus_t ext_stat;
    RegSHM_CHANNELNcsiChannelStatus_t linkStatus;
    uint8_t phy = MII_getPhy(port->device);

    if ((ALWAYS_RESET == reset_phy) || (AS_NEEDED == reset_phy && !Network_isLinkUp(port)))
    {
        APE_aquireLock();
        MII_reset(port->device, phy);
        APE_releaseLock();
    }
    else
    {
        bool updated;

        // Ensure the PHY is advertising all capabilities and updating if needed.
        APE_aquireLock();
        updated = MII_UpdateAdvertisement(port->device, phy);
        APE_releaseLock();

        if (updated)
        {
            printf("Advert updated\n");
        }
    }

    // 1000Mb/s mode only works if D0u is 0 when the host is off.
    // Note: Per ortega, this should possibly tansition between 0 and  6.25MHz depending on the power / clock states for power consumption reasons.
    port->device->D0uClockPolicy.r32 = 0;

    Network_InitFilters(port);

    Network_resetTX(port, reset_phy);
    Network_resetRX(port, reset_phy);

    APE.Mode.r32 |= port->APEModeEnable.r32;
    APE.Mode2.r32 |= port->APEMode2Enable.r32;

    // Ensure REG_RECEIVE_MAC_MODE has ENABLE set.
    // I recommend also setting APE_PROMISCUOUS_MODE and PROMISCUOUS_MODE,
    // as these will cause you less headaches during development.
    RegDEVICEReceiveMacMode_t macMode;
    macMode = port->device->ReceiveMacMode;
    macMode.bits.Enable = 1;
    // When set, allows APE to RX without having to reset the network configuration after a power off
    // When set, can cause the network to APE hardware blocks to lock up when the host is activly using the interface, so set to 0.
    macMode.bits.APEPromiscuousMode = 0;
    if (port->device->ReceiveMacMode.r32 != macMode.r32)
    {
        port->device->ReceiveMacMode = macMode;
    }

    // Enable RX/TX
    RegDEVICETransmitMacMode_t txMacMode;
    txMacMode = port->device->TransmitMacMode;
    txMacMode.bits.EnableTDE = 1;
    // txMacMode.bits.EnableFlowControl = 1;
    if (port->device->TransmitMacMode.r32 != txMacMode.r32)
    {
        port->device->TransmitMacMode = txMacMode;
    }

    RegDEVICEEeeMode_t eeeMode;
    eeeMode = port->device->EeeMode;
    eeeMode.bits.APETXDetectionEnable = 1;
    eeeMode.bits.EEELinkIdleDetectionEnable = 1;
    eeeMode.bits.SendIndexDetectionEnable = 1;
    eeeMode.bits.TXLPIEnable = 1;
    eeeMode.bits.RXLPIEnable = 1;
    if (port->device->EeeMode.r32 != eeeMode.r32)
    {
        port->device->EeeMode = eeeMode;
    }

    RegDEVICEBufferManagerMode_t bmm;
    bmm.r32 = 0;
    bmm.bits.Enable = 1;
    bmm.bits.AttentionEnable = 1;
    bmm.bits.ResetRXMBUFPointer = 1;
    if (port->device->BufferManagerMode.r32 != bmm.r32)
    {
        port->device->BufferManagerMode = bmm;
    }

    RegDEVICEEmacMode_t emacMode;
    emacMode = port->device->EmacMode;
    emacMode.bits.EnableAPERXPath = 1;
    emacMode.bits.EnableAPETXPath = 1;

    emacMode.bits.EnableFHDE = 1;
    emacMode.bits.EnableTCE = 1; // Transmit DMA needed for APE to work properly
    emacMode.bits.EnableRDE = 1;

    emacMode.bits.KeepFrameInWOL = 1;
    emacMode.bits.MACLoopbackModeControl = 0;
    if (port->device->EmacMode.r32 != emacMode.r32)
    {
        port->device->EmacMode = emacMode;
    }

    RegDEVICETransmitMacLengths_t txMacLengths;
    txMacLengths = port->device->TransmitMacLengths;
    txMacLengths.bits.SlotTimeLength = 0x20;
    txMacLengths.bits.IPGLength = 0x6;
    txMacLengths.bits.IPGCRSLength = 0x2;
    port->device->TransmitMacLengths = txMacLengths;

    port->device->MiscellaneousConfig.bits.DisableGRCReset = 1;
    port->device->LinkAwarePowerModeClockPolicy.bits.MACClockSwitch = DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_6_25MHZ;
    port->device->ClockSpeedOverridePolicy.r32 = 0;

    RegDEVICECpmuControl_t cmm;
    cmm = port->device->CpmuControl;
    cmm.bits.LinkIdlePowerModeEnable = 1;
    cmm.bits.LinkAwarePowerModeEnable = 1;
    cmm.bits.LinkSpeedPowerModeEnable = 1;
    if (port->device->CpmuControl.r32 != cmm.r32)
    {
        port->device->CpmuControl = cmm;
    }

    if (port->device->EmacMode.bits.EnableFHDE || port->device->EmacMode.bits.EnableRDE)
    {
        port->device->ReceiveListPlacementMode.bits.Enable = 1;
    }

    port->device->GrcModeControl.bits.HostStackUp = 1; // Enable packet RX

    APE_aquireLock();

    Network_updatePortState(port);

    uint16_t status_value = MII_readRegister(port->device, phy, (mii_reg_t)REG_MII_STATUS);
    stat.r16 = status_value;
    if (stat.bits.ExtendedStatusSupported)
    {
        uint16_t ext_status_value = MII_readRegister(port->device, phy, (mii_reg_t)REG_MII_IEEE_EXTENDED_STATUS);
        ext_stat.r16 = ext_status_value;
    }

    APE_releaseLock();

    // Set link status capabilities.
    linkStatus.r32 = 0;

    linkStatus.bits.LinkSpeed1000MFullDuplexCapable = ext_stat.bits._1000BASE_TFullDuplexCapable;
    linkStatus.bits.LinkSpeed1000MHalfDuplexCapable = ext_stat.bits._1000BASE_THalfDuplexCapable;

    linkStatus.bits.LinkSpeed100M_TXFullDuplexCapable = stat.bits._100BASE_XFullDuplexCapable;
    linkStatus.bits.LinkSpeed100M_TXHalfDuplexCapable = stat.bits._100BASE_XHalfDuplexCapable;

    linkStatus.bits.LinkSpeed10M_TFullDuplexCapable = stat.bits._10BASE_TFullDuplexCapable;
    linkStatus.bits.LinkSpeed10M_THalfDuplexCapable = stat.bits._10BASE_THalfDuplexCapable;

    port->shm_channel->NcsiChannelStatus = linkStatus;
}

void Network_checkPortState(NetworkPort_t *port)
{
    if (port->device->EmacStatus.bits.LinkStateChanged)
    {
        if (!port->link_state_printed)
        {
            printf("Link Status Changed\n");
            port->link_state_printed = true;
        }

        // Update state to match latest.
        if (Network_updatePortState(port))
        {
            RegDEVICEEmacStatus_t clearState;
            clearState.r32 = 0;
            clearState.bits.LinkStateChanged = 1;
            clearState.bits.ConfigurationChanged = 1;
            clearState.bits.SyncChanged = 1;
            clearState.bits.MICompletion = 1;
            port->device->EmacStatus.r32 = clearState.r32;

            printf("Link Status Updated\n");
            port->link_state_printed = false;
        }
    }
}

bool Network_updatePortState(NetworkPort_t *port)
{
    uint8_t phy = MII_getPhy(port->device);
    RegMIIAuxiliaryStatusSummary_t status;
    RegMIIControl_t control;
    bool updated = false;

    control.r16 = MII_readRegister(port->device, phy, (mii_reg_t)REG_MII_CONTROL);
    if (control.bits.RestartAutonegotiation)
    {
        // Link down, negotiation restarting, don't update mac mode.
    }
    else
    {
        status.r16 = MII_readRegister(port->device, phy, (mii_reg_t)REG_MII_AUXILIARY_STATUS_SUMMARY);
        if (control.bits.AutoNegotiationEnable && !status.bits.AutoNegotiationComplete)
        {
            // Link down, attempting to negotiate, don't update mac mode.
        }
        else
        {
            // Auto negotiation complete or mode forced.
            RegDEVICEEmacMode_t emacMode, emacModeOrig;
            emacModeOrig = emacMode = port->device->EmacMode;

            // Select full/half duplex mode.
            switch ((uint8_t)status.bits.AutoNegotiationHCD)
            {
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_NO_HCD:
                    // Error
                    break;

                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_10BASE_T_HALF_DUPLEX:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_100BASE_TX_HALF_DUPLEX:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_1000BASE_T_HALF_DUPLEX:
                    emacMode.bits.HalfDuplex = 1;
                    break;

                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_100BASE_T4:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_10BASE_T_FULL_DUPLEX:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_100BASE_TX_FULL_DUPLEX:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_1000BASE_T_FULL_DUPLEX:
                    emacMode.bits.HalfDuplex = 0;
                    break;
            }

            // Select Speed
            switch ((uint8_t)status.bits.AutoNegotiationHCD)
            {
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_NO_HCD:
                    // Error
                    break;

                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_10BASE_T_HALF_DUPLEX:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_10BASE_T_FULL_DUPLEX:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_100BASE_T4:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_100BASE_TX_HALF_DUPLEX:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_100BASE_TX_FULL_DUPLEX:
                    emacMode.bits.PortMode = DEVICE_EMAC_MODE_PORT_MODE_10_DIV_100;
                    break;

                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_1000BASE_T_HALF_DUPLEX:
                case MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_1000BASE_T_FULL_DUPLEX:
                    emacMode.bits.PortMode = DEVICE_EMAC_MODE_PORT_MODE_1000;
                    break;
            }

            if (emacMode.r32 != emacModeOrig.r32)
            {
                // Update emac mode to match current state.
                port->device->EmacMode = emacMode;

                RegDEVICETransmitMacLengths_t txMacLengths;
                txMacLengths = port->device->TransmitMacLengths;

                // Per the tg3.c driver, update slot time length when in half duplex 1G mode.
                if (emacMode.bits.PortMode == DEVICE_EMAC_MODE_PORT_MODE_1000 && emacMode.bits.HalfDuplex)
                {
                    txMacLengths.bits.SlotTimeLength = 0xFF;
                    txMacLengths.bits.IPGLength = 0x6;
                    txMacLengths.bits.IPGCRSLength = 0x2;
                }
                else
                {
                    txMacLengths.bits.SlotTimeLength = 0x20;
                    txMacLengths.bits.IPGLength = 0x6;
                    txMacLengths.bits.IPGCRSLength = 0x2;
                }
                port->device->TransmitMacLengths = txMacLengths;

                // Update EEE Control
                RegDEVICEEeeControl_t eeectrl;
                eeectrl.r32 = 0;
                if (emacMode.bits.PortMode == DEVICE_EMAC_MODE_PORT_MODE_1000)
                {
                    eeectrl.bits.ExitTime = DEVICE_EEE_CONTROL_EXIT_TIME_16_5_US;
                }
                else
                {
                    eeectrl.bits.ExitTime = DEVICE_EEE_CONTROL_EXIT_TIME_36_US;
                }
                port->device->EeeControl.r32 = eeectrl.r32;
            }

            updated = true;
        }
    }

    return updated;
}

void Network_resetLink(NetworkPort_t *port)
{
    uint8_t phy = MII_getPhy(port->device);
    APE_aquireLock();
    MII_reset(port->device, phy);
    APE_releaseLock();
}

bool Network_isLinkUp(NetworkPort_t *port)
{
    uint8_t phy = MII_getPhy(port->device);
    RegMIIAuxiliaryStatusSummary_t status;
    RegMIIControl_t control;
    bool linkup;

    control.r16 = MII_readRegister(port->device, phy, (mii_reg_t)REG_MII_CONTROL);
    if (control.bits.RestartAutonegotiation)
    {
        // Renegotiating, link not yet up, but in progress
        linkup = true;
    }
    else
    {
        status.r16 = MII_readRegister(port->device, phy, (mii_reg_t)REG_MII_AUXILIARY_STATUS_SUMMARY);
        if (control.bits.AutoNegotiationEnable && !status.bits.AutoNegotiationComplete)
        {
            // Renegotiating, link not yet up, but in progress
            linkup = true;
        }
        else
        {
            if (MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_NO_HCD == status.bits.AutoNegotiationHCD)
            {
                // Autoneg failed, link not up.
                linkup = false;
            }
            else
            {
                // Autoneg passed.
                linkup = true;
            }
        }
    }

    return linkup;
}
