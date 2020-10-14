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

#ifdef CXX_SIMULATOR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vpd.h>

typedef struct
{
    const char *name;
    const char *string;
} vpd_name_entry_t;

vpd_name_entry_t mNames[] = {
    {.name = VPD_PRODUCT_NAME,          .string = "Product Name"},
    {.name = VPD_ENGINEERING_CHANGE,    .string = "Engineering Change"},
    {.name = VPD_SERIAL_NUMBER,         .string = "Serial Number"},
    {.name = VPD_MANUFACTURING_ID,      .string = "Manufacturer ID"},
    {.name = VPD_CHECKSUM,              .string = "Checksum"},
};

bool vpd_is_checksum(uint16_t field)
{
    if (0 == strncmp(VPD_CHECKSUM, (const char *)&field, 2))
    {
        return true;
    }
    return false;
}
const char *vpd_get_field_name(uint16_t field)
{
    for (int i = 0; i < sizeof(mNames) / sizeof(mNames[0]); i++)
    {
        if (0 == strncmp(mNames[i].name, (const char *)&field, 2))
        {
            return mNames[i].string;
        }
    }

#ifdef CXX_SIMULATOR
    printf("Unknown %c%c\n", field, field >> 8);
#endif
    return NULL;
}

static uint8_t *get_next_tag(uint8_t *buffer, uint32_t *len)
{
    if (!len)
    {
        return NULL;
    }

    uint16_t tag_len = 0;
    vpd_resource_typet_t b0 = {.data = buffer[0]};
    if (VPD_DATA_TYPE_LARGE == b0.large.type)
    {

        tag_len = 3;
        tag_len += buffer[1] | buffer[2] << 8;
    }
    else
    {
        tag_len = 1;
        tag_len += b0.small.bytes;
    }

    *len -= tag_len;
    return &buffer[tag_len];
}

static uint8_t *get_tag_data(uint8_t *buffer, uint32_t *len)
{
    if (!len)
    {
        return NULL;
    }

    vpd_resource_typet_t b0 = {.data = buffer[0]};
    if (VPD_DATA_TYPE_LARGE == b0.large.type)
    {
        *len = buffer[1] | buffer[2] << 8;
        return &buffer[3];
    }
    else
    {
        *len = b0.small.bytes;
        return &buffer[1];
    }
}

uint8_t *vpd_get_resource_by_name(uint8_t *buffer, uint32_t *len, uint16_t type)
{
    return NULL;
}

uint8_t *vpd_get_resource_by_index(uint8_t *buffer, uint32_t *len, uint16_t *name,
                                   uint32_t index)
{
    index++;
    uint32_t new_len = *len;
    uint8_t *new_buf = get_next_tag(buffer, &new_len);
    new_buf = get_tag_data(new_buf, &new_len);

    vpd_field_t *field;
    do
    {
        field = (vpd_field_t *)new_buf;

        new_buf += field->length;
        new_buf += 3;

        index--;
        if (index && vpd_is_checksum(field->name))
        {
            // last entry found, but we requested more.
            return NULL;
        }
    } while (index);

    *name = field->name;
    *len = field->length;
    return &field->data;
}
bool vpd_set_resource(uint8_t *buffer, uint32_t len, uint16_t resource,
                      uint8_t *add_data, uint32_t add_len)
{
    return false;
}
bool vpd_is_valid(uint8_t *buffer, uint32_t len)
{
    if (!len)
    {
        return false;
    }

    if (!vpd_get_identifier(buffer, &len))
    {
        return false;
    }

    // TODO: check checksum.
    return len != 0;
}

uint8_t *vpd_get_identifier(uint8_t *buffer, uint32_t *len)
{
    if (!len)
        return NULL;

    return get_tag_data(buffer, len);
}

#endif /* CXX_SIMULATOR */
