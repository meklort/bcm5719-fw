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
#include <NCSI.h>
#include <NVRam.h>
#include <Timer.h>
#include <ape_main.h>

// RTOS
#include <FreeRTOS.h>
#include <task.h>

#ifndef CXX_SIMULATOR
#include <ape_console.h>
#include <printf.h>
#endif

#define RMU_WATCHDOG_TIMEOUT_MS (10)
#define RX_CPU_RESET_TIMEOUT_MS (1000) /* Wait up to 1 second for each RX CPU to start */

static NetworkPort_t *gPort;

uint32_t SystemCoreClock = 50 * 1000 * 1000; /* 50MHz */

/* Dimensions the buffer that the task being created will use as its stack.
NOTE:  This is the number of words the stack will hold, not the number of
bytes.  For example, if each stack item is 32-bits, and this is set to 100,
then 400 bytes (100 * 32-bits) will be allocated. */
#define STACK_SIZE 2048

/* Structure that will hold the TCB of the task being created. */
StaticTask_t xTaskBuffer;

/* Buffer that the task being created will use as its stack.  Note this is
an array of StackType_t variables.  The size of StackType_t is dependent on
the RTOS port. */
StackType_t xStack[STACK_SIZE];

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
        case SHM_LOADER_COMMAND_COMMAND_CALL:
        {
            // call address specified in arg0.
            void (*function)(uint32_t) = ((void *)arg0);
            function(arg1);
            break;
        }
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
            printf("RX CPU reset timeout.\n");
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

void handleBMCPacket(void)
{
    static bool packetInProgress = false;
    static uint32_t inProgressStartTime = 0;
    uint32_t buffer[1024];

    RegAPE_PERIBmcToNcRxStatus_t stat;
    stat.r32 = APE_PERI.BmcToNcRxStatus.r32;

    if (stat.bits.New)
    {
        packetInProgress = false;
        if (stat.bits.Bad)
        {
            // ACK bad packet.
            RMU_resetBadPacket();
        }
        else
        {
            uint32_t bytes = stat.bits.PacketLength;
            if (!stat.bits.Passthru)
            {
                uint32_t words = DIVIDE_RND_UP(bytes, sizeof(uint32_t));
                if (words > ARRAY_ELEMENTS(buffer))
                {
                    // This should never happen...
                    printf("Dropping NCSI packet\n");
                    while (words--)
                    {
                        // Read out the packet, but drop it.
                        uint32_t word = APE_PERI.BmcToNcReadBuffer.r32;
                        (void)word;
                    }
                }
                else
                {
                    int i = 0;
                    while (words--)
                    {
                        uint32_t word = (APE_PERI.BmcToNcReadBuffer.r32);
                        buffer[i] = word;
                        i++;
                    }

                    NetworkFrame_t *frame = ((NetworkFrame_t *)buffer);

                    handleNCSIFrame(frame);
                }
            }
            else
            {
                // Pass through to network
                NetworkPort_t *port = gPort;
                ++port->shm_channel->NcsiChannelNcsiRx.r32;
                if (port->shm_channel->NcsiChannelInfo.bits.Enabled)
                {
                    if (!Network_TX_transmitPassthroughPacket(bytes, port))
                    {
                        printf("Resetting TX...\n");
                        // Reset, as it's likely locked up now.
                        wait_for_all_rx();
                        RMU_init();
                        NCSI_reload(AS_NEEDED);
                    }
                }
                else
                {
                    printf("Dropping PT\n");
                    uint32_t words = DIVIDE_RND_UP(bytes, sizeof(uint32_t));
                    while (words--)
                    {
                        // Read out the packet, but drop it.
                        uint32_t word = APE_PERI.BmcToNcReadBuffer.r32;
                        (void)word;
                    }
                }
            }
        }
    }
    else if (stat.bits.InProgress)
    {
        if (packetInProgress)
        {
            // In some cases (RMU reset during startup w/ active communication)
            // the RMU state machine can enter a stuck state.
            // This can be seen as an InProgress for an unreasonable amount of time.
            // In such a case, reset the RMU to recover.
            if (Timer_didTimeElapsed1KHz(inProgressStartTime, RMU_WATCHDOG_TIMEOUT_MS))
            {
                printf("RMU Hang detected, resetting.\n");
                RMU_init();
                packetInProgress = false;
            }
        }
        else
        {
            packetInProgress = true;
            inProgressStartTime = Timer_getCurrentTime1KHz();
        }
    }
}

void checkSupply(void)
{
    if (NVIC.InterruptClearPending.r32 & NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_VMAIN)
    {
        NVIC.InterruptClearPending.r32 = NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_VMAIN;

        printf("Power State Changed.\n");

        wait_for_all_rx();
        RMU_init();
        NCSI_reload(AS_NEEDED);
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

    shm->FwVersion.r32 = (VERSION_MAJOR << 24) | (VERSION_MINOR << 16) | VERSION_PATCH; //lint !e835
    shm->FwFeatures.r32 = features.r32;
    shm->FwStatus.r32 = status.r32;

    shm->SegSig.r32 = 'APE!'; //lint !e742
}

void __attribute__((noreturn)) loaderLoop(void)
{
    uint32_t host_state = SHM.HostDriverState.bits.State;
    bool reset_allowed = host_state == SHM_HOST_DRIVER_STATE_STATE_START;

    // Update SHM.Sig to signal ready.
    SHM.SegSig.bits.Sig = SHM_SEG_SIG_SIG_LOADER;
    initSHM(&SHM);
    initSHM(&SHM1);
    initSHM(&SHM2);
    initSHM(&SHM3);

    for (;;)
    {
        handleBMCPacket();
        NCSI_handlePassthrough();
        handleCommand(&SHM);
        handleCommand(&SHM1);
        handleCommand(&SHM2);
        handleCommand(&SHM3);
        checkSupply();

        if (host_state != SHM.HostDriverState.bits.State)
        {
            reload_type_t type;
            host_state = SHM.HostDriverState.bits.State;

            if (SHM_HOST_DRIVER_STATE_STATE_START == host_state)
            {
                type = NEVER_RESET;
                printf("host started\n");

                reset_allowed = true;
            }
            else
            {
                if (SHM_HOST_DRIVER_STATE_STATE_UNLOAD == host_state)
                {
                    printf("host unloaded.\n");
                    type = AS_NEEDED;
                }
                else
                {
                    printf("wol?\n");
                    type = AS_NEEDED;
                }

                reset_allowed = false;
            }

            wait_for_all_rx();
            RMU_init();
            NCSI_reload(type);
        }
        else if (reset_allowed && !Network_checkEnableState(gPort))
        {
            printf("APE mode change, resetting.\n");
            wait_for_all_rx();
            RMU_init();
            NCSI_reload(AS_NEEDED);

            // Update host state to make sure we don't reset twice if it's changed.
            host_state = SHM.HostDriverState.bits.State;

            reset_allowed = false;
        }

        Network_checkPortState(gPort);
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

//lint -esym(714, __start) // Referenced by build tools.
void __attribute__((noreturn)) __start()
{
    SHM.SegSig.r32 = 1;

    // Ensure all pending interrupts are cleared.
    NVIC.InterruptClearPending.r32 = 0xFFFFFFFF;

    // Switch to APE interrupt handlers
    union
    {
        uint32_t u32;
        vector_table_t *vectors;
    } caster;
    caster.vectors = &gVectors;
    NVIC.VectorTableOffset.r32 = caster.u32;

    // Handle Initialization
    bool full_init = handle_reset();
    if (reset_ape_console())
    {
        full_init = true;
    }

    printf("APE v" STRINGIFY(VERSION_MAJOR) "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH) " NCSI Port " STRINGIFY(NETWORK_PORT) "\n");
    gPort = Network_getPort(NETWORK_PORT);

    NCSI_usePort(gPort);

    checkSupply();

    RMU_init();

    ncsi_print_enabled = true;

    if (full_init)
    {
        printf("Chip Reset.\n");
        NCSI_init();
    }
    else
    {
        printf("APE Reload.\n");
        NCSI_reload(SHM_HOST_DRIVER_STATE_STATE_START != SHM.HostDriverState.bits.State ? AS_NEEDED : NEVER_RESET);
    }

    TaskHandle_t xHandle;

    /* Create the task without using any dynamic memory allocation. */
    xHandle = xTaskCreateStatic(vTaskCode,        /* Function that implements the task. */
                                "Main",           /* Text name for the task. */
                                STACK_SIZE,       /* Number of indexes in the xStack array. */
                                (void *)1,        /* Parameter passed into the task. */
                                tskIDLE_PRIORITY, /* Priority at which the task is created. */
                                xStack,           /* Array to use as the task's stack. */
                                &xTaskBuffer);    /* Variable to hold the task's data structure. */

    (void)xHandle;
    /* Start the tasks and timer running. */
    vTaskStartScheduler();

    loaderLoop();
}

void vApplicationIdleHook(void)
{
    /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
    to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
    task.  It is essential that code added to this hook function never attempts
    to block in any way (for example, call xQueueReceive() with a block time
    specified, or call vTaskDelay()).  If the application makes use of the
    vTaskDelete() API function (as this demo application does) then it is also
    important that vApplicationIdleHook() is permitted to return to its calling
    function, because it is the responsibility of the idle task to clean up
    memory allocated by the kernel to any task that has since been deleted. */

    SHM.FwVersion.r32++;

} //lint !e741

/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */
    taskDISABLE_INTERRUPTS();
    for (;;)
        ; //lint !e722
}

void vApplicationTickHook(void)
{
#if 0
#if mainCHECK_INTERRUPT_STACK == 1
extern unsigned long _pvHeapStart[];

	/* This function will be called by each tick interrupt if
	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
	added here, but the tick hook is called from an interrupt context, so
	code must not attempt to block, and only the interrupt safe FreeRTOS API
	functions can be used (those that end in FromISR()). */

	/* Manually check the last few bytes of the interrupt stack to check they
	have not been overwritten.  Note - the task stacks are automatically
	checked for overflow if configCHECK_FOR_STACK_OVERFLOW is set to 1 or 2
	in FreeRTOSConifg.h, but the interrupt stack is not. */
	configASSERT( memcmp( ( void * ) _pvHeapStart, ucExpectedInterruptStackValues, sizeof( ucExpectedInterruptStackValues ) ) == 0U );
#endif /* mainCHECK_INTERRUPT_STACK */
#endif

    // uTickInterruptCounter++;
    SHM.FwFeatures.r32++;
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
