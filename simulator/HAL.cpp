#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <sys/types.h>
#include <dirent.h>
#include <sys/mman.h>

#include <endian.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "pci_config.h"

#include <bcm5719_DEVICE.h>

#define DEVICE_CONFIG "config"
#define BAR_STR         "resource%d"

#define ARRAY_ELEMENTS(__x__)       (sizeof(__x__)/sizeof(__x__[0]))

typedef struct {
    uint16_t    vendor_id;
    uint16_t    device_id;
} devices_t;

devices_t gSupportedDevices[] = {
    {.vendor_id = 0x14e4, .device_id = 0x1657},
};


bool is_supported(uint16_t vendor_id, uint16_t device_id)
{
    for(unsigned int i = 0; i < ARRAY_ELEMENTS(gSupportedDevices); i++)
    {
        devices_t *pDevice = &gSupportedDevices[i];
        if( vendor_id == pDevice->vendor_id &&
            device_id == pDevice->device_id)
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

#define MAX_NUM_BARS    8
uint8_t* bar[MAX_NUM_BARS] = {0};


uint32_t read_device_chipid(uint32_t)
{
    printf("DEIVCE CHIP ID\n");
    return 1123;
}

void initHAL(const char* pci_path)
{
    char* pConfigPath =  (char*)malloc(strlen("%s/" DEVICE_CONFIG) + strlen(pci_path) + 1);
    sprintf(pConfigPath, "%s/" DEVICE_CONFIG, pci_path);

    FILE* pConfigFile = fopen(pConfigPath, "rb");
    int memfd;

    pci_config_t config;

    if(fread(&config, sizeof(config), 1, pConfigFile))
    {
        if(is_supported(config.vendor_id, config.device_id))
        {
            printf("Found supported device %x:%x at %s\n", config.vendor_id, config.device_id, pConfigPath);
            for(unsigned int i = 0; i < ARRAY_ELEMENTS(config.BAR); i++)
            {
                char* pBARPath =  (char*)malloc(strlen("%s/" BAR_STR) + strlen(pci_path) + 1);
                sprintf(pBARPath, "%s/" BAR_STR, pci_path, i);

                uint64_t addr;
                if(is_bar_64bit(config.BAR[i]))
                {
                    addr = get_bar_addr(config.BAR[i]);
                    addr |= ((uint64_t)config.BAR[i+1]) << 32u;
                }
                else
                {
                    addr = config.BAR[i];
                }

                printf("BAR[%d]: %016lx\n", i, addr);


                if ((memfd = open(pBARPath, O_RDWR|O_SYNC)) < 0 )
                {
                    printf("Error opening %s file. \n", pBARPath);
                    close(memfd);
                    break;
                }
                else
                {
                    printf("mmaping %s\n", pBARPath);
                }



                bar[i] = (uint8_t*)mmap(0, 64*1024, PROT_READ | PROT_WRITE, MAP_SHARED, memfd, 0); // PROT_WRITE
                if(bar[i] == MAP_FAILED)
                {
                    printf("Oh dear, something went wrong with mmap(0, %d, 0x%lX)! %s\n", getpagesize(), addr, strerror(errno));
                    exit(-1);
                }

                if(is_bar_64bit(config.BAR[i])) 
                {
                    i++;
                }

                free(pBARPath);
            }

            free(pConfigPath);
        }
    }

    uint8_t* DEVICEBase = (uint8_t*)bar[0];
    // void* APEBase = bar[2];
    // printf("[0] = 0x%0X\n", *((uint32_t*)bar[0]));
    // printf("[2] = 0x%0X\n", *((uint32_t*)bar[2]));
    // printf("[b50] = %x\n", ((uint32_t*)(bar[0]))[0xb50/4]);

    // // DEVICE.ChipId.r32.installReadCallback(&read_device_chipid);
    // // DEVICE.ChipId.r32.installWriteCallback(&read_device_chipid);
    // uint32_t testmp = DEVICE.ChipId.r32;
    // printf("ChipId: %x\n", testmp);
    // printf("ChipId: %x\n", (unsigned int)DEVICE.ChipId.r32);

    printf("-------\n");

    extern void init_bcm5719_DEVICE(void);
    extern void init_bcm5719_DEVICE_mmap(void*);
    extern void init_bcm5719_APE(void);
    extern void init_bcm5719_NVM(void);
    extern void init_bcm5719_NVM_mmap(void*);
    init_bcm5719_DEVICE();
    init_bcm5719_DEVICE_mmap(DEVICEBase);
    init_bcm5719_APE();
    // init_bcm5719_APE_mmap();
    init_bcm5719_NVM();
    init_bcm5719_NVM_mmap(DEVICEBase + 0x7000);
}

