#include "../libs/NVRam/bcm5719_NVM.h"
#include "pci_config.h"

#include <bcm5719_DEVICE.h>
#include <bcm5719_APE.h>
#include <dirent.h>
#include <endian.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <string>

using namespace std;

#define DEVICE_CONFIG   "config"
#define BAR_STR         "resource"

#define ARRAY_ELEMENTS(__x__) (sizeof(__x__) / sizeof(__x__[0]))

typedef struct
{
    uint16_t vendor_id;
    uint16_t device_id;
} devices_t;

devices_t gSupportedDevices[] = {
    {.vendor_id = 0x14e4, .device_id = 0x1657},
};

bool is_supported(uint16_t vendor_id, uint16_t device_id)
{
    for (unsigned int i = 0; i < ARRAY_ELEMENTS(gSupportedDevices); i++)
    {
        devices_t *pDevice = &gSupportedDevices[i];
        if (vendor_id == pDevice->vendor_id && device_id == pDevice->device_id)
        {
            return true;
        }
    }

    return false;
}

#define BAR_REGION_MASK (0x1)
#define BAR_TYPE_MASK   (0x6)
#define BAR_TYPE_16BIT  (1u << 1)
#define BAR_TYPE_32BIT  (0u << 1)
#define BAR_TYPE_64BIT  (2u << 1)
#define BAR_ADDR_MASK   (0xFFFFFF0)
bool is_bar_64bit(uint32_t bar)
{
    return (BAR_TYPE_64BIT == (bar & BAR_TYPE_MASK));
}

uint32_t get_bar_addr(uint32_t bar)
{
    return (bar & BAR_ADDR_MASK);
}

#define MAX_NUM_BARS 8
uint8_t *bar[MAX_NUM_BARS] = {0};

uint32_t read_device_chipid(uint32_t)
{
    printf("DEIVCE CHIP ID\n");
    return 1123;
}

void initHAL(const char *pci_path)
{
    struct stat st;
    int memfd;

    string configPath = string(pci_path) + string("/") + string(DEVICE_CONFIG);
    const char* pConfigPath = configPath.c_str();

    FILE *pConfigFile = fopen(pConfigPath, "rb");

    if(!pConfigFile)
    {
        fprintf(stderr, "Unable to open PCI configuration %p\n", pConfigPath);
        exit(-1);
    }

    pci_config_t config;

    if (fread(&config, sizeof(config), 1, pConfigFile))
    {
        if (is_supported(config.vendor_id, config.device_id))
        {
            printf("Found supported device %x:%x at %s\n", config.vendor_id,
                   config.device_id, configPath.c_str());
            for (unsigned int i = 0; i < ARRAY_ELEMENTS(config.BAR); i++)
            {
                string BARPath = string(pci_path) + "/" BAR_STR + to_string(i);
                const char* pBARPath = BARPath.c_str();

                if ((memfd = open(pBARPath, O_RDWR | O_SYNC)) < 0)
                {
                    printf("Error opening %s file. \n", pBARPath);
                    close(memfd);
                    exit(-1);
                }
                else
                {
                    printf("mmaping BAR[%d]: %s\n", i, pBARPath);
                }

                if (fstat(memfd, &st) < 0)
                {
                    fprintf(stderr, "error: couldn't stat file\n");
                    exit(-1);
                }

                bar[i] = (uint8_t *)mmap(0, st.st_size, PROT_READ | PROT_WRITE,
                                         MAP_SHARED, memfd, 0); // PROT_WRITE
                if (bar[i] == MAP_FAILED)
                {
                    printf("Unable to mmap %s: %s\n", pBARPath,
                           strerror(errno));
                    exit(-1);
                }

                if (is_bar_64bit(config.BAR[i]))
                {
                    i++;
                }
            }
        }
    }

    uint8_t *DEVICEBase = (uint8_t *)bar[0];

    init_bcm5719_DEVICE();
    init_bcm5719_DEVICE_mmap(DEVICEBase);
    init_bcm5719_APE();
    // init_bcm5719_APE_mmap();
    init_bcm5719_NVM();
    init_bcm5719_NVM_mmap(DEVICEBase + 0x7000);
}
