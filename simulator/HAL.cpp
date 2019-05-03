#include "../libs/NVRam/bcm5719_NVM.h"
#include "pci_config.h"

#include <bcm5719_DEVICE.h>
#include <bcm5719_APE.h>
#include <bcm5719_APE_PERI.h>
#include <bcm5719_SHM.h>
#include <bcm5719_SHM_CHANNEL0.h>
#include <bcm5719_SHM_CHANNEL1.h>
#include <bcm5719_SHM_CHANNEL2.h>
#include <bcm5719_SHM_CHANNEL3.h>
#include <bcm5719_GEN.h>
#include <APE_NVIC.h>
#include <APE_FILTERS.h>
#include <APE_TX_PORT.h>

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
#include <iostream>

#if __has_include("valgrind/valgrind.h")
#include <valgrind/valgrind.h>
#else
#define RUNNING_ON_VALGRIND 0
#endif

using namespace std;

#define DEVICE_ROOT     "/sys/bus/pci/devices/"
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

bool is_pci_function(const char *pci_path, int wanted_function)
{
    // Path: 0001:01:00.0
    int sys = 0;
    int bus = 0;
    int slot = 0;
    int function = 0;
    if (4 == sscanf(pci_path, "%d:%d:%d.%d\n", &sys, &bus, &slot, &function))
    {
        if (wanted_function == function)
        {
            return true;
        }
    }

    return false;
}

static char* locate_pci_path(int wanted_function)
{
    char* pci_path = NULL;
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(DEVICE_ROOT);
    if (pDir == NULL)
    {
        printf("Cannot open directory '%s'\n", DEVICE_ROOT);
        return NULL;
    }

    while ((pDirent = readdir(pDir)) != NULL && NULL == pci_path)
    {
        const char *pPCIPath = pDirent->d_name;
        if (is_pci_function(pDirent->d_name, wanted_function))
        {
            string configPath;
            configPath = string(DEVICE_ROOT) + pPCIPath + "/" + DEVICE_CONFIG;
            const char* pConfigPath = configPath.c_str();
            // This is the primary function of a device.
            // Read the configuration and see if it matches a supported
            // vendor/device.

            FILE *pConfigFile = fopen(pConfigPath, "rb");

            if (pConfigFile)
            {
                pci_config_t config;

                if (fread(&config, sizeof(config), 1, pConfigFile))
                {
                    if (is_supported(config.vendor_id, config.device_id))
                    {
                        pci_path = (char *)malloc(
                            strlen(DEVICE_ROOT "%s/") + strlen(pPCIPath) + 1);
                        sprintf(pci_path, DEVICE_ROOT "%s/", pPCIPath);
                    }
                }
                fclose(pConfigFile);
            }

        }
    }
    closedir(pDir);

    return pci_path;
}


bool initHAL(const char *pci_path, int wanted_function)
{
    char* located_pci_path = NULL;
    struct stat st;
    int memfd;

    if(RUNNING_ON_VALGRIND)
    {
        cerr << "Running on valgrind is not supported when mmaping device registers." << endl;
        return false;;
    }

    if(!pci_path)
    {
        // Let's 
        located_pci_path = locate_pci_path(wanted_function);
        pci_path = located_pci_path;
        if(!located_pci_path)
        {
            return false;
        }
    }

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
                    return false;
                }
                else
                {
                    printf("mmaping BAR[%d]: %s\n", i, pBARPath);
                }

                if (fstat(memfd, &st) < 0)
                {
                    fprintf(stderr, "error: couldn't stat file\n");
                    return false;
                }

                bar[i] = (uint8_t *)mmap(0, st.st_size, PROT_READ | PROT_WRITE,
                                         MAP_SHARED, memfd, 0); // PROT_WRITE
                if (bar[i] == MAP_FAILED)
                {
                    printf("Unable to mmap %s: %s\n", pBARPath,
                           strerror(errno));
                    return false;
                }

                if (is_bar_64bit(config.BAR[i]))
                {
                    i++;
                }
            }
        }
    }

    if(located_pci_path)
    {
        free(located_pci_path);
    }

    uint8_t *DEVICEBase = (uint8_t *)bar[0];
    uint8_t *APEBase = (uint8_t *)bar[2];

    init_bcm5719_DEVICE();
    init_bcm5719_DEVICE_sim(DEVICEBase);

    init_bcm5719_GEN();
    init_bcm5719_GEN_sim(&DEVICEBase[0x8000 + 0xB50]); // 0x8000 for windowed area

    init_bcm5719_NVM();
    init_bcm5719_NVM_sim(&DEVICEBase[0x7000]);

    init_bcm5719_APE();
    init_bcm5719_APE_sim(APEBase);

    init_bcm5719_APE_PERI();
    init_bcm5719_APE_PERI_sim(&APEBase[0x8000]);

    init_bcm5719_SHM();
    init_bcm5719_SHM_sim(&APEBase[0x4000]);

    init_bcm5719_SHM_CHANNEL0();
    init_bcm5719_SHM_CHANNEL0_sim(&APEBase[0x4900]);
    init_bcm5719_SHM_CHANNEL1();
    init_bcm5719_SHM_CHANNEL1_sim(&APEBase[0x4a00]);
    init_bcm5719_SHM_CHANNEL2();
    init_bcm5719_SHM_CHANNEL2_sim(&APEBase[0x4b00]);
    init_bcm5719_SHM_CHANNEL3();
    init_bcm5719_SHM_CHANNEL3_sim(&APEBase[0x4c00]);

    init_APE_FILTERS();
    init_APE_FILTERS_sim(NULL);

    init_APE_NVIC();
    init_APE_NVIC_sim(NULL);

    init_APE_TX_PORT();
    init_APE_TX_PORT_sim(NULL);

    return true;
}
