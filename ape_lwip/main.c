////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.c
///
/// @project
///
/// @brief      Main APE code
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

// #define EN_HTTPD
// #define EN_IPERF
#define EN_SNTP

#include <time.h>

#include <APE.h>
#include <APE_APE.h>
#include <APE_APE_PERI.h>
#include <APE_DEVICE1.h>
#include <APE_DEVICE2.h>
#include <APE_DEVICE3.h>
#include <APE_NVIC.h>
#include <APE_SHM.h>
#include <APE_SHM1.h>
#include <APE_SHM2.h>
#include <APE_SHM3.h>
#include <Ethernet.h>
#include <Network.h>
#include <NVRam.h>
#include <Timer.h>
#include <ape_main.h>

// RTOS
#include <FreeRTOS.h>
#include <task.h>

// Lwip
#include <lwip/tcpip.h>
#include <lwip/dhcp.h>
#include <lwip/netifapi.h>
#include <lwip/snmp.h>
#include <lwip/apps/sntp.h>
#ifdef EN_HTTPD
#include <lwip/apps/httpd.h>
#endif
#ifdef EN_IPERF
#include <lwip/apps/lwiperf.h>
#endif

#ifndef CXX_SIMULATOR
#include <ape_console.h>
// #include <printf.h>
#endif

#define RX_CPU_RESET_TIMEOUT_MS (1000) /* Wait up to 1 second for each RX CPU to start */
// #define GRC_RESET_TIMEOUT_MS (250)     /* Wait 250ms for the GRC reset to settle */

static NetworkPort_t *gPort;
// static uint32_t gResetTime;
// static uint32_t gResetDelay;
// static bool gPortReset;

static struct netif my_netif;
static struct netif *pNetif = &my_netif;

#if 0
void triggerPendingReset(uint32_t delay)
{
    gPortReset = true;
    gResetDelay = delay;

    gResetTime = Timer_getCurrentTime1KHz();
}
#endif
uint32_t SystemCoreClock = 125 * 1000 * 1000; /* 50MHz */

/* Dimensions the buffer that the task being created will use as its stack.
NOTE:  This is the number of words the stack will hold, not the number of
bytes.  For example, if each stack item is 32-bits, and this is set to 100,
then 400 bytes (100 * 32-bits) will be allocated. */
#define STACK_SIZE 512

/* Structure that will hold the TCB of the task being created. */
StaticTask_t xTaskBuffer;
StaticTask_t xTaskRxPacketBuffer;

/* Buffer that the task being created will use as its stack.  Note this is
an array of StackType_t variables.  The size of StackType_t is dependent on
the RTOS port. */
StackType_t xStack[STACK_SIZE];
StackType_t xStackRxPacket[STACK_SIZE];
TaskHandle_t xHandleRxPacket;

void handleCommand(volatile SHM_t *shm)
{
    uint32_t command = shm->LoaderCommand.bits.Command;
    if (!command)
    {
        return;
    }

    uint32_t arg0 = shm->LoaderArg0.r32;
    uint32_t arg1 = shm->LoaderArg1.r32;

    switch (command)
    {
        default:
            break;

        case SHM_LOADER_COMMAND_COMMAND_READ_MEM:
        {
            // Read word address specified in arg0
            uint32_t *addr = ((void *)arg0);
            shm->LoaderArg0.r32 = *addr;
            break;
        }
        case SHM_LOADER_COMMAND_COMMAND_WRITE_MEM:
        {
            // Write word address specified in arg0 with arg1
            uint32_t *addr = ((void *)arg0);
            *addr = arg1;
            break;
        }
        // case SHM_LOADER_COMMAND_COMMAND_CALL:
        // {
        //     // call address specified in arg0.
        //     void (*function)(uint32_t) = ((void *)arg0);
        //     function(arg1);
        //     break;
        // }
    }

    // Mark command as handled.
    shm->LoaderCommand.bits.Command = 0;
}

void wait_for_rx(const volatile DEVICE_t *device, const volatile SHM_t *shm)
{
    uint32_t startTime = Timer_getCurrentTime1KHz();

    bool waiting = true;
    do
    {
        if (device->RxRiscStatus.bits.Halted)
        {
            // If the RX CPU has halted, exit out.
            waiting = false;
        }

        if (SHM_RCPU_SEG_SIG_SIG_RCPU_MAGIC == shm->RcpuSegSig.bits.Sig)
        {
            // Firmware has finished initialization.
            waiting = false;
        }

        if (Timer_didTimeElapsed1KHz(startTime, RX_CPU_RESET_TIMEOUT_MS))
        {
            // printf("RX CPU reset timeout.\n");
            waiting = false;
        }
    } while (waiting);
}

void wait_for_all_rx()
{
    wait_for_rx(&DEVICE, &SHM);
    wait_for_rx(&DEVICE1, &SHM1);
    wait_for_rx(&DEVICE2, &SHM2);
    wait_for_rx(&DEVICE3, &SHM3);
}

void __attribute__((interrupt)) IRQ_VoltageSource()
{
    NVIC.InterruptClearPending.r32 = NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_VMAIN;

    NetworkPort_t *port = gPort;

    if (port->device->Status.bits.VMAINPowerStatus)
    {
        // printf("Vsrc: Main\n");
    }
    else
    {
        // printf("Vsrc: Aux\n");
    }

    // Ensure we reinitialize hardware as needed.
    // triggerPendingReset(0);
}

bool portResetInProgress(RegAPEStatus_t status, RegAPEStatus2_t status2, const NetworkPort_t *port)
{
    if ((status.r32 & port->APEStatus.r32) || (status2.r32 & port->APEStatus2.r32))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool resetInProgress(RegAPEStatus_t status, RegAPEStatus2_t status2)
{
    if (status.bits.Port0GRCReset || status.bits.Port1GRCReset || status2.bits.Port2GRCReset || status2.bits.Port3GRCReset)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void __attribute__((interrupt)) IRQ_PowerStatusChanged(void)
{
    RegAPEStatus_t status = APE.Status;
    RegAPEStatus2_t status2 = APE.Status2;

    // Clear Interrupts
    APE.Status.r32 = status.r32;
    APE.Status2.r32 = status2.r32;

    NVIC.InterruptClearPending.r32 = NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_GENERAL_RESET;

    // printf("PowerStateChanged.\n");

    if (resetInProgress(status, status2))
    {
        if (portResetInProgress(status, status2, gPort))
        {
            // printf("GRC Reset.\n");
            // triggerPendingReset(GRC_RESET_TIMEOUT_MS);
        }

        // Disable the interrupt so that we can exit the interrupt handler
        NVIC.InterruptClearEnable.r32 = NVIC_INTERRUPT_SET_ENABLE_SETENA_GENERAL_RESET;
    }
}

void initSHM(volatile SHM_t *shm)
{
    RegSHMFwStatus_t status;
    status.r32 = 0;
    status.bits.Ready = 1;

    RegSHMFwFeatures_t features;
    features.r32 = 0;
    features.bits.NCSI = 1;

    shm->SegMessageBufferOffset.r32 = ((unsigned)REG_SHM_DRIVER_BUFFER - (unsigned)REG_SHM_BASE); // Scratchpad buffer start.
    shm->SegMessageBufferLength.r32 =
        ARRAY_ELEMENTS(shm->DriverBuffer) * sizeof(uint32_t); // Scratchpad buffer available length - 8 bytes before loader handler.

    shm->FwVersion.r32 = (VERSION_MAJOR << 24) | (VERSION_MINOR << 16) | VERSION_PATCH; //lint !e835
    shm->FwFeatures.r32 = features.r32;
    shm->FwStatus.r32 = status.r32;

    // Host segment follows ape / shm segment.
    shm->ApeSegLength.r32 = ((unsigned)REG_SHM_HOST_SEG_SIG - (unsigned)REG_SHM_SEG_SIG);
    shm->SegSig.r32 = 'APE!'; //lint !e742
}

/*-----------------------------------------------------------------------------------*/
/*
 * low_level_output():
 *
 * Should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf
 * might be chained.
 *
 */
/*-----------------------------------------------------------------------------------*/

// char buf[1518]; /* max packet size including VLAN excluding CRC */
static err_t
low_level_output(struct netif *netif, struct pbuf *p)
{
    NetworkPort_t *port = netif->state;
    (void)netif;
    (void)p;

    // printf("OUT: \n");
    // for(int i = 0; i < 16; i++)
    // {
    //     printf("0x%02x ", ((char *)p->payload)[i]);
    // }
    // printf("\n");
    unsigned int len = p->tot_len;
    // printf("tx %d, %p\n", len, p->next);
    if (Network_TX_transmitBePacket(p->payload, len, port))
    // if (Network_TX_transmitBePacket(p->payload, p->tot_len - 4, port))
    {
        // printf("txd\n");
        return (err_t)ERR_OK;
    }
    else
    {
        printf("tx err\n");
        return (err_t)ERR_BUF;
    }

}

signed char
net_init(struct netif *netif)
{
    NetworkPort_t *port = netif->state;

    // printf("NET INIT\n");
    MIB2_INIT_NETIF(netif, snmp_ifType_other, 100000000);

    netif->name[0] = 'a';
    netif->name[1] = 'p';

#if LWIP_NETIF_HOSTNAME
    netif->hostname = "lwip";
#endif

#if LWIP_IPV4
    netif->output = etharp_output;
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
    netif->output_ip6 = ethip6_output;
#endif /* LWIP_IPV6 */
    netif->linkoutput = low_level_output;
    netif->mtu = 0xffff;

    /* (We just fake an address...) */
    // 00-60-A7-5C-CA-2B
    netif->hwaddr[0] = 0x00;
    netif->hwaddr[1] = 0x60;
    netif->hwaddr[2] = 0xA7;
    netif->hwaddr[3] = 0x5C;
    netif->hwaddr[4] = 0xCA;
    netif->hwaddr[5] = 0x2B;
    netif->hwaddr_len = 6;

    uint32_t low = (uint32_t)netif->hwaddr[5] | ((uint32_t)netif->hwaddr[4] << 8) | ((uint32_t)netif->hwaddr[3] << 16) | ((uint32_t)netif->hwaddr[2] << 24);
    uint16_t high = (uint32_t)netif->hwaddr[1] | ((uint32_t)netif->hwaddr[0] << 8);

    // printf("port init\n");
    Network_InitPort(port, AS_NEEDED);
    Timer_delayMs(1000);
    Network_SetMACAddr(port, high, low, 0, (bool)true);
    Timer_delayMs(1000);
    // printf("check state\n");

    Network_checkPortState(port);


    /* device capabilities */
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_IGMP;

    netif_set_link_up(netif);

// #if !NO_SYS
//   sys_thread_new("tapif_thread", tapif_thread, netif, DEFAULT_THREAD_STACKSIZE, DEFAULT_THREAD_PRIO);
// #endif /* !NO_SYS */
  return 0;
}
void vTaskRxPacket(void *pvParameters);

void sntp_set_system_time_us(uint32_t seconds, uint32_t us)
{
    time_t t = seconds;
    struct tm now;
    (void)localtime(&t, &now);

    printf("Time: %u:%u\n", now.tm_year, us);
}

void __attribute__((noreturn)) loaderLoop(void)
{
    DEVICE.ApeClkPolicy.bits.APEClockSwitch = DEVICE_APE_CLK_POLICY_APE_CLOCK_SWITCH_125_MHZ;
    DEVICE.ApeClkPolicy.bits.ClockOverrideAPEClockSwitch = DEVICE_APE_CLK_POLICY_CLOCK_OVERRIDE_APE_CLOCK_SWITCH_125_MHZ;
    DEVICE.ApeClkPolicy.bits.LAPMAPEClockSwitch = DEVICE_APE_CLK_POLICY_LAPM_APE_CLOCK_SWITCH_25_MHZ;
    DEVICE.ApeClkPolicy.bits.APEClockSpeedOverrideEnable = 1;

    int loop = 0;
    // Update SHM.Sig to signal ready.
    initSHM(&SHM);
    initSHM(&SHM1);
    // initSHM(&SHM2);
    // initSHM(&SHM3);

    // Enable GRC Reset / Power Status Changed and Vsrc interrupts
    // Enable Packet interrupts
    NVIC.InterruptSetEnable.r32 =
        NVIC_INTERRUPT_SET_ENABLE_SETENA_VMAIN | NVIC_INTERRUPT_SET_ENABLE_SETENA_GENERAL_RESET |
        NVIC_INTERRUPT_SET_ENABLE_SETENA_RX_PACKET_EVEN | NVIC_INTERRUPT_SET_ENABLE_SETENA_RX_PACKET_ODD;


    ip4_addr_t my_ip = {0};
    ip4_addr_t my_gw = {0};
    ip4_addr_t my_netmask = {0};

    LOCK_TCPIP_CORE();
    // printf("netif_add\n");
    netif_set_default(NULL);
    pNetif = netif_add(pNetif, &my_ip, &my_netmask, &my_gw, Network_getPort(NETWORK_PORT), net_init, netif_input);
    // pNetif = netif_add(pNetif, &my_ip, &my_netmask, &my_gw, Network_getPort(NETWORK_PORT), net_init, NULL); //netif_input);
    netif_set_up(pNetif);
    netif_set_default(pNetif);

#ifdef EN_SNTP
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    // sntp_setservername(0, "pool.ntp.org");
    sntp_servermode_dhcp(true);
    sntp_init();
#endif

    (void)dhcp_start(pNetif);

#ifdef EN_HTTPD
    httpd_init();
    // struct altcp_tls_config *conf = NULL;
    // httpd_inits(conf);
#endif

#ifdef EN_IPERF
    ip4_addr_t server_ip;
    IP_ADDR4 (& server_ip, 192, 168, 32, 44); // IP 407 own static IP


    (void)lwiperf_start_tcp_server(&server_ip, 2233, NULL, NULL);
#endif
    UNLOCK_TCPIP_CORE();


    for (;;)
    {
#if 0
        if (NVIC_INTERRUPT_SET_ENABLE_SETENA_GENERAL_RESET != (NVIC.InterruptSetEnable.r32 & NVIC_INTERRUPT_SET_ENABLE_SETENA_GENERAL_RESET))
        {
            // A Global Reset occured, wait for it to settle.
            RegAPEStatus_t status = APE.Status;
            RegAPEStatus2_t status2 = APE.Status2;

            // Wait for reset to complete.
            if (resetInProgress(status, status2))
            {
                // We are waiting for the reset signals to clear before continuing.
                APE.Status.r32 = status.r32;
                APE.Status2.r32 = status2.r32;

                // Initialize timer for reset.
                if (portResetInProgress(status, status2, gPort))
                {
                    if (!gPortReset)
                    {
                        printf("GRC Reset.\n");
                    }

                    triggerPendingReset(GRC_RESET_TIMEOUT_MS);
                }
            }
            else
            {
                // We may still have an interrupt pending since we disabled the interrupt. Clear it so we don't get an extra trigger.
                NVIC.InterruptClearPending.r32 = NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_GENERAL_RESET;

                // Reset complete, re-enable interrupt handler.
                NVIC.InterruptSetEnable.r32 = NVIC_INTERRUPT_SET_ENABLE_SETENA_GENERAL_RESET;

                if (!Network_checkEnableState(gPort))
                {
                    // If an unrelated port is unloaded, the APE mode may be cleared. Set it again.
                    wait_for_all_rx();
                    Network_setEnableState(gPort);
                }
            }
        }

        if (gPortReset && Timer_didTimeElapsed1KHz(gResetTime, gResetDelay))
        {
            gPortReset = false;

            printf("Handling reset...\n");

            // Perform TX reinit as the PHY / MII was also probably reset.
            wait_for_all_rx();
            Network_InitPort(gPort, AS_NEEDED);
        }

        if (!gPortReset)
        {
            Network_checkPortState(gPort);
        }

        // handleCommand(&SHM);
        handleCommand(&SHM1);
#endif
        printf("main%d %x %x\n", ++loop, NVIC.InterruptSetEnable.r32, NVIC.InterruptSetPending.r32);
        // NVIC.InterruptSetEnable.r32 = NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_RX_PACKET_ODD | NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_RX_PACKET_EVEN;
        // taskENABLE_INTERRUPTS();

        vTaskDelay(1000);

        // taskYIELD();
    }
}

/* Function that implements the task being created. */
void vTaskCode(void *pvParameters)
{
    (void)pvParameters;
    /* The parameter value is expected to be 1 as 1 is passed in the
    pvParameters value in the call to xTaskCreateStatic(). */
    // configASSERT( ( uint32_t ) pvParameters == 1UL );

    loaderLoop();

}

bool handle_reset(void)
{
    uint32_t chip_id = DEVICE.ChipId.r32;
    if (!chip_id)
    {
        printf("Resetting...\n");
        RegAPEGpio_t apegpio;
        apegpio.r32 = APE.Gpio.r32;

        // Release all locks to ensure that the RX CPU will be able to boot up
        NVRam_releaseAllLocks();
        APE_releaseAllLocks();

        // Reset needed.
        // Configure the clock mux to be driving by the APE.
        apegpio.bits.PIN0ModeOutput = 1;
        apegpio.bits.PIN1ModeOutput = 1;
        apegpio.bits.PIN2ModeOutput = 1;
        apegpio.bits.PIN0UnknownOut = 1; // Clock_P
        apegpio.bits.PIN1UnknownOut = 0; // Clock_N
        apegpio.bits.PIN2UnknownOut = 1; // CLock Mux = APE GPIO
        APE.Gpio.r32 = apegpio.r32;

        for (int i = 0; i < 38; i++)
        {
            // Clock it...
            apegpio.bits.PIN0UnknownOut = ~apegpio.bits.PIN0UnknownOut; // Clock_P
            apegpio.bits.PIN1UnknownOut = ~apegpio.bits.PIN1UnknownOut; // Clock_N
            APE.Gpio.r32 = apegpio.r32;
        }

        do
        {
            // Wait for the ChipID register to be readable
            chip_id = DEVICE.ChipId.r32;
        } while (!chip_id);

        // Restore the mux settings.
        apegpio.bits.PIN2UnknownOut = 0; // CLock Mux = PCIe clock
        APE.Gpio.r32 = apegpio.r32;

        // Wait for the RX CPU to finish executing before continuing.
        wait_for_all_rx();

        return true;
    }
    else
    {
        // No reset
        return false;
    }
}

void *memset(void *s, int c, size_t n);
//lint -e 527
//lint -esym(714, __start) // Referenced by build tools.
int gInitData = 0;
void __attribute__((noreturn)) __start()
{
    // Zero out bss
    extern char _ebss[];
    extern char _fbss[];
    memset(_fbss, 0, (size_t)(_ebss - _fbss));
    printf("zero = %p to %p (%d)\n", _fbss, _ebss, (_ebss - _fbss));
    // for (;;) {}
    printf("gInitData = %d\n", gInitData);
    SHM.SegSig.r32 = 1;

    // Ensure all pending interrupts are cleared.
    NVIC.InterruptClearPending.r32 = 0xFFFFFFFF;
    // gPortReset = false;

    // Switch to APE interrupt handlers
    union
    {
        uint32_t u32;
        vector_table_t *vectors;
    } caster;
    caster.vectors = &gVectors;
    NVIC.VectorTableOffset.r32 = caster.u32;

    // Handle Initialization
    // bool full_init = handle_reset();
    if (reset_ape_console())
    {
        // full_init = true;
    }

    printf("\nAPE v" STRINGIFY(VERSION_MAJOR) "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH) " NCSI Port " STRINGIFY(NETWORK_PORT) "\n");

    gPort = Network_getPort(NETWORK_PORT);

    RMU_init();

    // extern char _ebss[];
    extern char _fstack[];
    // printf("Heap: %p (%u bytes)\n", _ebss, (unsigned int)(_fstack - _ebss) );
    /* Allocate two blocks of RAM for use by the heap.  The first is a block of
    0x10000 bytes starting from address 0x80000000, and the second a block of
    0xa0000 bytes starting from address 0x90000000.  The block starting at
    0x80000000 has the lower start address so appears in the array fist. */
    // extern char _ebss[];
    const HeapRegion_t xHeapRegions[] =
    {
        { ( uint8_t * ) _ebss, (unsigned int)(_fstack - _ebss) },
        // { ( uint8_t * ) 0x90000000UL, 0xa0000 },
        { NULL, 0 } /* Terminates the array. */
    };
    printf("Heap: %x - %x\n", xHeapRegions[0].pucStartAddress, xHeapRegions[0].pucStartAddress + xHeapRegions[0].xSizeInBytes);
    /* Pass the array into vPortDefineHeapRegions(). */
    vPortDefineHeapRegions( xHeapRegions );

    TaskHandle_t xHandle;

    /* Create the task without using any dynamic memory allocation. */
    (void)xTaskCreate(vTaskCode,        /* Function that implements the task. */
                                "Main",           /* Text name for the task. */
                                STACK_SIZE,       /* Number of indexes in the xStack array. */
                                (void *)1,        /* Parameter passed into the task. */
                                (unsigned long)1u, /* Priority at which the task is created. */
                                &xHandle);    /* Variable to hold the task's data structure. */

    (void)xHandle;

    /* Create the task without using any dynamic memory allocation. */
    (void)xTaskCreate(vTaskRxPacket,        /* Function that implements the task. */
                                "RX",           /* Text name for the task. */
                                STACK_SIZE,       /* Number of indexes in the xStack array. */
                                (void *)1,        /* Parameter passed into the task. */
                                (unsigned long)3u, /* Priority at which the task is created. */
                                &xHandleRxPacket);    /* Variable to hold the task's data structure. */

    /* Start the tasks and timer running. */
    // printf("Starting RTOS\n");

    // APE SHM 0x60222000 - 0x60224000 (port 2, 3) could be used (8K),
#if 0
    // uint32_t *addr = (void*)0x7e007000;
    // 0x70000000, 0x80000000, 0x90000000
    uint32_t base = 0x60300000;
    printf("Scanning base: 0x%08x\n", base);
    for (unsigned int i = 0; i < 0x4000000; i += 0x100)
    {
        uint32_t *addr = (void*)(base + i * 4);
        printf("%p = %x\n", addr, *addr);
        __asm__("dsb");
        __asm__("isb");
        *addr = 0xFFFFFFFF;
        __asm__("dsb");
        __asm__("isb");
        printf("%p = %x\n", addr, *addr);
        if (*addr == 0xFFFFFFFF)
        {
            printf("match (%x)\n", *addr);
            for (;;)
            {

            }
        }
    }
#endif
    tcpip_init(NULL, NULL);

    // httpd_init();

    vTaskStartScheduler();

    // loaderLoop();
    for (;;) {}
}

#if 1
/**
 * Should allocate a pbuf and transfer the bytes of the incoming
 * packet from the interface into the pbuf.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return a pbuf filled with the received packet (including MAC header)
 *         NULL on memory error
 */
static struct pbuf *
low_level_input(const struct netif *netif)
{
    NetworkPort_t *port = netif->state;
    struct pbuf *p;
    u16_t len;
    // printf("rx\n");
    /* Obtain the size of the packet and put it into the "len"
        variable. */
    len = (uint16_t)Network_RxPatcketLen(port);
    // printf("packet with %d bytes.\n", (int32_t)len);

#if ETH_PAD_SIZE
    len += ETH_PAD_SIZE; /* allow room for Ethernet padding */
#endif

    /* We allocate a pbuf chain of pbufs from the pool. */
    p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);

    if (p != NULL) {

#if ETH_PAD_SIZE
        (void)pbuf_remove_header(p, ETH_PAD_SIZE); /* drop the padding word */
#endif

        /* We iterate over the pbuf chain until we have read the entire
        * packet into the pbuf. */
        // struct pbuf *q;
        // int i = 0;
        for (q = p; q != NULL; q = q->next) {
            printf("%d: %d %d\n", i, len, q->len);
        //     i++;
        // //   /* Read enough bytes to fill this pbuf in the chain. The
        // //    * available data in the pbuf is given by the q->len
        // //    * variable.
        // //    * This does not necessarily have to be a memcpy, you can also preallocate
        // //    * pbufs for a DMA-enabled MAC and after receiving truncate it to the
        // //    * actually received size. In this case, ensure the tot_len member of the
        // //    * pbuf is the sum of the chained pbuf len members.
        // //    */
        // // //   read data into(q->payload, q->len);
        // }
        // acknowledge that packet has been read();
        uint32_t rx_bytes;
        (void)Network_RxBePatcket(p->payload, &rx_bytes, port);
        // printf("in: ");
        // for(int i = 0; i < 16; i++)
        // {
        //     printf("0x%02x ", ((char *)p->payload)[i]);
        // }
        // printf("\n");

        MIB2_STATS_NETIF_ADD(netif, ifinoctets, p->tot_len);
        if (((u8_t *)p->payload)[0] & 1) {
            /* broadcast or multicast packet*/
            MIB2_STATS_NETIF_INC(netif, ifinnucastpkts);
        } else {
            /* unicast packet*/
            MIB2_STATS_NETIF_INC(netif, ifinucastpkts);
        }

#if ETH_PAD_SIZE
        (void)pbuf_add_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif

        LINK_STATS_INC(link.recv);
    } else {
        printf("drop rx %d\n", len);
        (void)Network_DropRxPatcket(port);
        LINK_STATS_INC(link.memerr);
        LINK_STATS_INC(link.drop);
        MIB2_STATS_NETIF_INC(netif, ifindiscards);
    }

    return p;
}

static void
ethernetif_input(struct netif *netif)
{
    struct pbuf *p;

    /* move received packet into a new pbuf */
    p = low_level_input(netif);

    /* if no packet could be read, silently ignore this */
    if (p != NULL) {
        LOCK_TCPIP_CORE();
        /* pass all packets to ethernet_input, which decides what packets it supports */
        if (netif->input(p, netif) != (err_t)ERR_OK) {
            LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_input: IP input error\n"));
            (void)pbuf_free(p);
        }
        UNLOCK_TCPIP_CORE();
    }
}
#endif

void __attribute__((interrupt)) IRQ_RxPacketEven(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // NVIC.InterruptClearPending.r32 = NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_RX_PACKET_EVEN;
    NVIC.InterruptClearEnable.r32 = NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_RX_PACKET_EVEN;

    // printf("even\n");
    (void)xTaskNotifyFromISR(xHandleRxPacket, NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_RX_PACKET_EVEN, eSetBits, &xHigherPriorityTaskWoken); //lint !e747
    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}

void __attribute__((interrupt)) IRQ_RxPacketOdd(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // NVIC.InterruptClearPending.r32 = NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_RX_PACKET_ODD;
    NVIC.InterruptClearEnable.r32 = NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_RX_PACKET_ODD;

    // printf("odd\n");
    (void)xTaskNotifyFromISR(xHandleRxPacket, NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_RX_PACKET_ODD, eSetBits, &xHigherPriorityTaskWoken); //lint !e747
    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}

/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */
    // taskDISABLE_INTERRUPTS();
    printf("Stack overflow on '%s' (%p vs %p)\n", pcTaskName);
    for (;;)
        ; //lint !e722
}

void vApplicationMallocFailedHook(void)
{
    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */
    // taskDISABLE_INTERRUPTS();
    printf("Malloc failed\n");
    for (;;)
    {
    }
}

/* configSUPPORT_STATIC_ALLOCATION is set to 1, so the application must provide an
implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
used by the Idle task. */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task’s
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task’s stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = ARRAY_ELEMENTS(uxIdleTaskStack);
}

/* configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
//lint -e714
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer,
                                    uint32_t *pulTimerTaskStackSize) //lint !e714
{
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

    /* Pass out a pointer to the StaticTask_t structure in which the Timer
    task’s state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task’s stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configTIMER_TASK_STACK_DEPTH is specified in words, not bytes. */
    *pulTimerTaskStackSize = ARRAY_ELEMENTS(uxTimerTaskStack);
}

void vTaskRxPacket(void *pvParameters)
{
    printf("rx task\n");
    (void)pvParameters;
    for (;;)
    {
        uint32_t value = 0;
        if (xTaskNotifyWait(0, 0, &value, portMAX_DELAY)) //lint !e747
        {
            // printf("rx packet\n");

            // TODO: call for both appropriate ports.
            // vPortEnterCritical();
            ethernetif_input(pNetif);
            // printf("rx donedone %x\n", value);
            // vPortExitCritical();

            // Re-enable interrupts.

            NVIC.InterruptClearPending.r32 = value;
            NVIC.InterruptSetEnable.r32 = value;
            /*  */// printf("%x -> %x\n", value, NVIC.InterruptSetEnable.r32);
        }
    }
}
