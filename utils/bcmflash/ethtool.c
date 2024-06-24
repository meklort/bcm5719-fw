////////////////////////////////////////////////////////////////////////////////
///
/// @file       iface.c
///
/// @project
///
/// @brief      Ethtool-based network interface APIs.
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018-2020, Evan Lojewski
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

#include <errno.h>
#include <linux/ethtool.h>
#include <linux/sockios.h>
#include <malloc.h>
#include <net/if.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <types.h>

#define BCM_NVRAM_MAGIC (0x669955AAu)

/* Context for sub-commands */
struct cmd_context
{
    int fd;           /* socket for ethtool ioctl */
    struct ifreq ifr; /* ifreq for ethtool ioctl */
};

static int do_ioctl(struct cmd_context *ctx, void *cmd)
{
    ctx->ifr.ifr_data = (char *)cmd;
    return ioctl(ctx->fd, SIOCETHTOOL, &ctx->ifr);
}

bool bcmflash_ethtool_init(const char *name)
{
    struct cmd_context ctx = { 0 };

    strcpy(ctx.ifr.ifr_name, name);

    ctx.fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct ethtool_drvinfo drvinfo;

    drvinfo.cmd = ETHTOOL_GDRVINFO;
    if (do_ioctl(&ctx, &drvinfo) < 0)
    {
        return false;
    }

    return true;
}

size_t bcmflash_ethtool_size(const char *name)
{
    struct cmd_context ctx = { 0 };

    strcpy(ctx.ifr.ifr_name, name);

    ctx.fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct ethtool_drvinfo drvinfo;

    drvinfo.cmd = ETHTOOL_GDRVINFO;
    if (do_ioctl(&ctx, &drvinfo) < 0)
    {
        const char *errstr = strerror(errno);
        printf("Cannot get driver information, %d: %s\n", errno, errstr);
        return 0;
    }

    return drvinfo.eedump_len;
}

bool bcmflash_ethtool_read(const char *name, void *buffer, size_t len)
{
    uint32_t address = 0;
    uint32_t bytes = len;

    uint32_t eeprom_size = bcmflash_ethtool_size(name);

    struct cmd_context ctx = { 0 };

    strcpy(ctx.ifr.ifr_name, name);

    ctx.fd = socket(AF_INET, SOCK_DGRAM, 0);

    // Limit reads to valid ranges. the ioctl will fail if we try to read past the end.
    uint32_t end_address = address + bytes;

    end_address = MIN(end_address, eeprom_size);
    bytes = end_address - address;

    struct ethtool_eeprom *eeprom;
    eeprom = (struct ethtool_eeprom *)calloc(1, sizeof(struct ethtool_eeprom) + eeprom_size);
    eeprom->cmd = ETHTOOL_GEEPROM;
    eeprom->len = bytes;
    eeprom->offset = address;

    if (do_ioctl(&ctx, eeprom) < 0)
    {
        const char *errstr = strerror(errno);
        printf("Cannot read eeprom, %d: %s\n", errno, errstr);
        free(eeprom);
        return false;
    }

    memcpy(buffer, &eeprom->data[0], bytes);

    free(eeprom);

    return true;
}

bool bcmflash_ethtool_write(const char *name, void *buffer, size_t len)
{
    uint32_t address = 0;
    uint32_t bytes = len;

    uint32_t eeprom_size = bcmflash_ethtool_size(name);

    struct cmd_context ctx = { 0 };

    strcpy(ctx.ifr.ifr_name, name);

    ctx.fd = socket(AF_INET, SOCK_DGRAM, 0);

    uint32_t end_address = address + bytes;
    bytes = end_address - address;

    if (end_address > eeprom_size)
    {
        printf("Cannot write past the end of eeprom.\n");
        return false;
    }

    struct ethtool_eeprom *eeprom;
    eeprom = (struct ethtool_eeprom *)calloc(1, sizeof(struct ethtool_eeprom) + eeprom_size);
    eeprom->cmd = ETHTOOL_SEEPROM;
    eeprom->magic = BCM_NVRAM_MAGIC;
    eeprom->len = bytes;
    eeprom->offset = address;

    memcpy(&eeprom->data[0], buffer, bytes);

    if (do_ioctl(&ctx, eeprom) < 0)
    {
        printf("Cannot write eeprom");
        free(eeprom);
        return false;
    }

    free(eeprom);

    return true;
}
