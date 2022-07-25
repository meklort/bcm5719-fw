////////////////////////////////////////////////////////////////////////////////
///
/// @file       usb3380.cpp
///
/// @project
///
/// @brief      C++ Register wrapper code
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2022, Evan Lojewski
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
#include "pci_config.h"

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
#include <libusb3380.h>
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

libusb3380_context_t *gCtx;

using namespace std;

static hal_config_t gConfig = { 0 };

#define BAR_REGION_MASK (0x1)
#define BAR_TYPE_MASK (0x6)
#define BAR_TYPE_16BIT (1u << 1)
#define BAR_TYPE_32BIT (0u << 1)
#define BAR_TYPE_64BIT (2u << 1)
#define BAR_ADDR_MASK (0xFFFFFF0)
static bool is_bar_64bit(uint32_t bar)
{
    return (BAR_TYPE_64BIT == (bar & BAR_TYPE_MASK));
}

#define MAX_NUM_BARS 8
static uint32_t barusb[MAX_NUM_BARS] = { 0 };
static size_t barlen[MAX_NUM_BARS];

static uint32_t read_from_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    union
    {
        uint8_t *ptr;
        uint32_t val;
    } caster;
    caster.ptr = base;
    usb3380_pci_dev_mem_read32(gCtx, caster.val, &val);
    return val;
}

static uint32_t write_to_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    union
    {
        uint8_t *ptr;
        uint32_t val;
    } caster;
    caster.ptr = base;
    usb3380_pci_dev_mem_write32(gCtx, caster.val, val);
    return val;
}

static libusb_device *find_usb_match(libusb_device **usbdev, size_t devices, int usb_bus, int usb_port, int usb_addr, unsigned *devid, char *devid_s,
                                     size_t devid_s_sz)
{
    struct libusb_device_descriptor desc;
    int res;
    for (unsigned i = 0; i < devices; i++)
    {
        res = libusb_get_device_descriptor(usbdev[i], &desc);
        if (res)
            continue;

        if (desc.idProduct != LIBUSB3380_PID || desc.idVendor != LIBUSB3380_VID)
        {
            printf("Skipping %X:%X\n", desc.idProduct, desc.idVendor);
            continue;
        }
            // continue;

        uint8_t bus = libusb_get_bus_number(usbdev[i]);
        uint8_t port = libusb_get_port_number(usbdev[i]);
        uint8_t addr = libusb_get_device_address(usbdev[i]);

        *devid = (unsigned)bus * 1000000 + (unsigned)port * 1000 + addr;
        snprintf(devid_s, devid_s_sz, "%d/%d/%d", bus, port, addr);

        printf("usb3380: comparing devices %d/%d/%d <> %d/%d/%d\n", usb_bus, usb_port, usb_addr, bus, port, addr);

        if ((usb_addr == -1 && usb_bus == -1 && usb_port == -1) || (usb_addr == -1 && usb_bus == -1 && usb_port == port) ||
            (usb_addr == -1 && usb_bus == bus && usb_port == port) || (usb_bus == bus && usb_port == port && usb_addr == addr))
        {
            return usbdev[i];
        }
    }
    return NULL;
}

const hal_config_t *HAL_probeUSB(const char *path, int wanted_function)
{
    if (!path)
    {
        // Path is not for a usb device.
        return NULL;
    }

    if (0 != strncmp("usb:", path, sizeof("usb:") - 1))
    {
        // path does not start with usb prefix.
        return NULL;
    }

    libusb3380_pcidev_t *pcidev;
    int res;
    unsigned devid;
    char devid_s[16];

    int usb_bus = -1;
    int usb_port = -1;
    int usb_addr = -1;
    int usb_speed = 0;

    libusb_context *uctx;
    if (libusb_init(&uctx))
    {
        return NULL;
    }

    libusb_device **usbdev;
    ssize_t devices = libusb_get_device_list(uctx, &usbdev);
    if (devices < 0)
    {
        libusb_exit(uctx);
        return NULL;
    }
    libusb_device *match = find_usb_match(usbdev, devices, usb_bus, usb_port, usb_addr, &devid, devid_s, sizeof(devid_s));

    if (match == NULL)
    {
        printf("No USB device was found to match %d/%d/%d\n", usb_bus, usb_port, usb_addr);
        libusb_exit(uctx);
        return NULL;
    }

    switch (libusb_get_device_speed(match))
    {
        case LIBUSB_SPEED_LOW:
            usb_speed = 1;
            break;
        case LIBUSB_SPEED_FULL:
            usb_speed = 12;
            break;
        case LIBUSB_SPEED_HIGH:
            usb_speed = 480;
            break;
        case LIBUSB_SPEED_SUPER:
            usb_speed = 5000;
            break;
    }

    bool int_polling = (usb_speed < 5000);

    res = usb3380_context_init_ex(&gCtx, match, uctx);
    libusb_free_device_list(usbdev, 1);
    if (res)
    {
        printf("Unable to allocate USB3380 context: error: %d\n", res);
        libusb_exit(uctx);
        return NULL;
    }

    libusb3380_pcie_rc_cfg_t cfg;

    usb3380_init_rc_def(&cfg);
    res = usb3380_init_root_complex(gCtx, &cfg);
    if (res)
    {
        if (res == -EAGAIN && int_polling)
        {
            // Hack
            libusb_reset_device(*(libusb_device_handle **)gCtx);

            usb3380_context_free(gCtx);

            // Reinitialization takes time, wait 0.5sec
            usleep(500000);

            // Repeat reinitialization with the same usb_bus and usb_port,
            // addr will differ after usb reset
            if (libusb_init(&uctx))
            {
                return NULL;
            }
            devices = libusb_get_device_list(uctx, &usbdev);
            if (devices < 0)
            {
                libusb_exit(uctx);
                return NULL;
            }
            match = find_usb_match(usbdev, devices, usb_bus, usb_port, -1, &devid, devid_s, sizeof(devid_s));
            if (match == NULL)
            {
                libusb_exit(uctx);
                return NULL;
            }

            res = usb3380_context_init_ex(&gCtx, match, uctx);
            libusb_free_device_list(usbdev, 1);
            if (res)
            {
                printf("Unable to reinitialize context: error: %d\n", res);
                return NULL;
            }

            res = usb3380_init_root_complex(gCtx, &cfg);
            if (res)
            {
                printf("Unable to initialize USB3380 Root Complex mode: error: %d\n", res);
                goto usbinit_fail;
            }
        }
    }

    res = usb3380_init_first_dev(gCtx, 0, &pcidev);
    if (res)
    {
        printf("No devices were found: error: %d\n", res);
        goto usbinit_fail;
    }

    pci_config_t config;
    for (int i = 0; i < sizeof(config) / 4; i++)
    {
        uint32_t data;
        usb3380_pci_cfg_read(gCtx, MAKE_CFG_0(0, 0, 0, (i * 4)), &data);
        ((uint32_t *)&config)[i] = data;
    }

    for (size_t i = 0; i < ARRAY_ELEMENTS(config.BAR); i++)
    {
        barusb[i] = usb3380_pci_dev_bar_addr(pcidev, i);
        barlen[i] = usb3380_pci_dev_bar_length(pcidev, i);

        if (is_bar_64bit(config.BAR[i]))
        {
            i++;
        }
    }

    if (!HAL_deviceIsSupported(usb3380_pci_dev_vid(pcidev), usb3380_pci_dev_did(pcidev)))
    {
        printf("Enumerated device isn't supported [%04x:%04x]\n", usb3380_pci_dev_vid(pcidev), usb3380_pci_dev_did(pcidev));
        goto usbinit_fail;
    }

    union
    {
        uint32_t val;
        uint8_t *ptr;
    } caster;

    caster.val = barusb[0];
    gConfig.DEVICEBase = caster.ptr;
    caster.val = barusb[2];
    gConfig.APEBase = caster.ptr;

    gConfig.read = read_from_ram;
    gConfig.write = write_to_ram;

    return &gConfig;

usbinit_fail:
    usb3380_context_free(gCtx);
    return NULL;
}
