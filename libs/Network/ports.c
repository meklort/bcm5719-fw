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

#include <APE_DEVICE1.h>
#include <APE_DEVICE2.h>
#include <APE_DEVICE3.h>
#include <APE_FILTERS1.h>
#include <APE_FILTERS2.h>
#include <APE_FILTERS3.h>
#include <APE_RX_PORT1.h>
#include <APE_RX_PORT2.h>
#include <APE_RX_PORT3.h>
#include <APE_SHM_CHANNEL0.h>
#include <APE_SHM_CHANNEL1.h>
#include <APE_SHM_CHANNEL2.h>
#include <APE_SHM_CHANNEL3.h>
#include <APE_TX_PORT1.h>
#include <APE_TX_PORT2.h>
#include <APE_TX_PORT3.h>
#include <Network.h>

NetworkPort_t gPort0 = {
    .device = &DEVICE,
    .filters = &FILTERS0,
    .shm_channel = &SHM_CHANNEL0,

    .tx_port = &TX_PORT0,
    .tx_allocator = &APE.TxToNetBufferAllocator0,
    .tx_doorbell = &APE.TxToNetDoorbellFunc0,
    .tx_mode = &APE.TxToNetPoolModeStatus0,

    .rx_port = &RX_PORT0,
    .rx_offset = &APE.RxbufoffsetFunc0,
    .rx_retire = &APE.RxPoolRetire0,
    .rx_mode = &APE.RxPoolModeStatus0,
};

NetworkPort_t gPort1 = {
    .device = &DEVICE1,
    .filters = &FILTERS1,
    .shm_channel = &SHM_CHANNEL1,

    .tx_port = &TX_PORT1,
    .tx_allocator = &APE.TxToNetBufferAllocator1,
    .tx_doorbell = &APE.TxToNetDoorbellFunc1,
    .tx_mode = &APE.TxToNetPoolModeStatus1,

    .rx_port = &RX_PORT1,
    .rx_offset = &APE.RxbufoffsetFunc1,
    .rx_retire = &APE.RxPoolRetire1,
    .rx_mode = &APE.RxPoolModeStatus1,
};

NetworkPort_t gPort2 = {
    .device = &DEVICE2,
    .filters = &FILTERS2,
    .shm_channel = &SHM_CHANNEL2,

    .tx_port = &TX_PORT2,
    .tx_allocator = &APE.TxToNetBufferAllocator2,
    .tx_doorbell = &APE.TxToNetDoorbellFunc2,
    .tx_mode = &APE.TxToNetPoolModeStatus2,

    .rx_port = &RX_PORT2,
    .rx_offset = &APE.RxbufoffsetFunc2,
    .rx_retire = &APE.RxPoolRetire2,
    .rx_mode = &APE.RxPoolModeStatus2,
};

NetworkPort_t gPort3 = {
    .device = &DEVICE3,
    .filters = &FILTERS3,
    .shm_channel = &SHM_CHANNEL3,

    .tx_port = &TX_PORT3,
    .tx_allocator = &APE.TxToNetBufferAllocator3,
    .tx_doorbell = &APE.TxToNetDoorbellFunc3,
    .tx_mode = &APE.TxToNetPoolModeStatus3,

    .rx_port = &RX_PORT3,
    .rx_offset = &APE.RxbufoffsetFunc3,
    .rx_retire = &APE.RxPoolRetire3,
    .rx_mode = &APE.RxPoolModeStatus3,
};

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

void Network_resetTX(NetworkPort_t *port)
{
    // Enable TX
    RegAPETxToNetPoolModeStatus_t txMode;
    txMode.r32 = 0;
    txMode.bits.Reset = 1;
    *(port->tx_mode) = txMode;

    txMode.bits.Reset = 0;
    txMode.bits.Enable = 1;
    *(port->tx_mode) = txMode;
}

void Network_resetRX(NetworkPort_t *port)
{
    // Enable RX
    RegAPERxPoolModeStatus_t rxMode;
    rxMode.r32 = 0;
    rxMode.bits.Reset = 1;
    *(port->rx_mode) = rxMode;

    rxMode.bits.Reset = 0;
    rxMode.bits.Enable = 1;
    *(port->rx_mode) = rxMode;
}

void Network_InitPort(NetworkPort_t *port)
{
    Network_InitFilters(port);

    Network_resetTX(port);
    Network_resetRX(port);

    // Ensure REG_RECEIVE_MAC_MODE has ENABLE set.
    // I recommend also setting APE_PROMISCUOUS_MODE and PROMISCUOUS_MODE,
    // as these will cause you less headaches during development.
    RegDEVICEReceiveMacMode_t macMode;
    macMode = port->device->ReceiveMacMode;
    macMode.bits.Enable = 1;
    macMode.bits.APEPromiscuousMode = 0;
    port->device->ReceiveMacMode = macMode;

    Network_SetMACAddr(port, 0, 0, 1, true);
}
