////////////////////////////////////////////////////////////////////////////////
///
/// @file       vpd.c
///
/// @project    
///
/// @brief      VPD Support Routines
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

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define VPD_DATA_TYPE_SMALL (0x00)
#define VPD_DATA_TYPE_LARGE (0x01)
#define VPD_TAG_IDENTIFIER  (0x02)
#define VPD_TAG_END         (0x0F)
#define VPD_TAG_VPD_R       (0x10)
#define VPD_TAG_VPD_W       (0x11)
typedef union {
    struct {
        uint8_t bytes:3;
        uint8_t tag:4;
        uint8_t type:1;
    } small;
    struct {
        uint8_t tag:7;
        uint8_t type:1;
    } large;
    uint8_t data;
} vpd_resource_typet_t;

typedef struct {
    uint16_t    name;
    uint8_t     length;
    uint8_t     data;
} __attribute__((packed)) vpd_field_t;

typedef union {
    uint8_t bytes[0x100];
} vpd_t;


#define VPD_PRODUCT_NAME        "PN"
#define VPD_ENGINEERING_CHANGE  "EC"
#define VPD_SERIAL_NUMBER       "SN"
#define VPD_MANUFACTURING_ID    "MN"
#define VPD_VENDOR_SPECIFIC_0   "V0"
#define VPD_CHECKSUM            "RV"

const char* vpd_get_field_name(uint16_t field);


uint8_t* vpd_get_identifier(uint8_t *buffer, size_t *len);
uint8_t* vpd_get_resource_by_name(uint8_t* buffer, size_t* len, uint16_t name);
uint8_t* vpd_get_resource_by_index(uint8_t* buffer, size_t* len, uint16_t* name, size_t index);
bool vpd_set_resource(uint8_t* buffer, size_t len, uint16_t resource, uint8_t* add_data, size_t add_len);
bool vpd_is_valid(uint8_t* buffer, size_t len);

