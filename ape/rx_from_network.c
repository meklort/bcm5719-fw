////////////////////////////////////////////////////////////////////////////////
///
/// @file       rx_from_network.c
///
/// @project
///
/// @brief      Initialization code for RX from network.
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

#include "ape.h"

#include <APE_FILTERS.h>

typedef struct {
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

void initRxFromNetwork(void)
{
    for(int i = 0; i < 32; i++)
    {
        FILTERS.ElementConfig[i] = gElementInit[i].cfg;
        FILTERS.ElementPattern[i] = gElementInit[i].pat;
    }

}
