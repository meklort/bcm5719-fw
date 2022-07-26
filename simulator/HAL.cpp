////////////////////////////////////////////////////////////////////////////////
///
/// @file       HAL.cpp
///
/// @project
///
/// @brief      C++ Register wrapper code
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
#include "../libs/NVRam/bcm5719_NVM.h"

#include <APE_NVIC.h>
#include <HAL.hpp>
#include <bcm5719_APE.h>
#include <bcm5719_APE_PERI.h>
#include <bcm5719_DEVICE.h>
#include <bcm5719_GEN.h>
#include <bcm5719_SHM.h>
#include <bcm5719_SHM_CHANNEL0.h>
#include <bcm5719_SHM_CHANNEL1.h>
#include <bcm5719_SHM_CHANNEL2.h>
#include <bcm5719_SHM_CHANNEL3.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

typedef struct
{
    uint16_t vendor_id;
    uint16_t device_id;
} devices_t;

static devices_t gSupportedDevices[] = {
    { .vendor_id = 0x14e4, .device_id = 0x1657 },
};

bool HAL_deviceIsSupported(uint16_t vendor_id, uint16_t device_id)
{
    for (size_t i = 0; i < ARRAY_ELEMENTS(gSupportedDevices); i++)
    {
        devices_t *pDevice = &gSupportedDevices[i];
        if (vendor_id == pDevice->vendor_id && device_id == pDevice->device_id)
        {
            return true;
        }
    }

    return false;
}

static uint32_t loader_read_mem(uint32_t val, uint32_t offset, void *args)
{
    uint32_t addr = (uint32_t)((uint64_t)args);
    addr += offset;

    SHM.LoaderArg0.r32 = addr;
    SHM.LoaderCommand.bits.Command = SHM_LOADER_COMMAND_COMMAND_READ_MEM;

    // Wait for command to be handled.
    while (0 != SHM.LoaderCommand.bits.Command)
        ;

    return (uint32_t)SHM.LoaderArg0.r32;
}

static uint32_t loader_write_mem(uint32_t val, uint32_t offset, void *args)
{
    uint32_t addr = (uint32_t)((uint64_t)args);
    addr += offset;

    SHM.LoaderArg0.r32 = addr;
    SHM.LoaderArg1.r32 = val;
    SHM.LoaderCommand.bits.Command = SHM_LOADER_COMMAND_COMMAND_WRITE_MEM;

    // Wait for command to be handled.
    while (0 != SHM.LoaderCommand.bits.Command)
        ;

    return val;
}

bool HAL_init(const char *path, int wanted_function)
{
    const hal_config_t *config = HAL_probePCI(path, wanted_function);

    if (!config)
    {
        // Unable to locate device.
        return false;
    }

    uint8_t *DEVICEBase = config->DEVICEBase;
    uint8_t *APEBase = config->APEBase;

    init_bcm5719_DEVICE();
    init_bcm5719_DEVICE_sim(DEVICEBase, config->read, config->write);

    init_bcm5719_GEN();
    init_bcm5719_GEN_sim(&DEVICEBase[0x8000 + 0xB50], config->read, config->write); // 0x8000 for windowed area

    init_bcm5719_NVM();
    init_bcm5719_NVM_sim(&DEVICEBase[0x7000], config->read, config->write);

    init_bcm5719_APE();
    init_bcm5719_APE_sim(APEBase, config->read, config->write);

    init_bcm5719_APE_PERI();
    init_bcm5719_APE_PERI_sim(&APEBase[0x8000], config->read, config->write);

    init_bcm5719_SHM();
    init_bcm5719_SHM_sim(&APEBase[0x4000], config->read, config->write);

    init_bcm5719_SHM_CHANNEL0();
    init_bcm5719_SHM_CHANNEL0_sim(&APEBase[0x4900], config->read, config->write);
    init_bcm5719_SHM_CHANNEL1();
    init_bcm5719_SHM_CHANNEL1_sim(&APEBase[0x4a00], config->read, config->write);
    init_bcm5719_SHM_CHANNEL2();
    init_bcm5719_SHM_CHANNEL2_sim(&APEBase[0x4b00], config->read, config->write);
    init_bcm5719_SHM_CHANNEL3();
    init_bcm5719_SHM_CHANNEL3_sim(&APEBase[0x4c00], config->read, config->write);

    init_APE_NVIC();
    init_APE_NVIC_sim(0, loader_read_mem, loader_write_mem);

    return true;
}
