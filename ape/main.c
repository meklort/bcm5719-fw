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
#include <APE_SHM.h>
#include <APE_SHM1.h>
#include <APE_SHM2.h>
#include <APE_SHM3.h>
#include <Ethernet.h>
#include <NCSI.h>
#include <NVRam.h>
#include <ape_main.h>

#ifndef CXX_SIMULATOR
#include <ape_console.h>
#include <printf.h>
#endif

#define RMU_WATCHDOG_TIMEOUT_MS (10)

static NetworkPort_t *gPort;

void handleCommand(void)
{
    uint32_t command = SHM.LoaderCommand.bits.Command;
    if (!command)
    {
        return;
    }

    uint32_t arg0 = SHM.LoaderArg0.r32;
    uint32_t arg1 = SHM.LoaderArg1.r32;

    switch (command)
    {
        default:
            break;

        case SHM_LOADER_COMMAND_COMMAND_READ_MEM:
        {
            // Read word address specified in arg0
            uint32_t *addr = ((void *)arg0);
            SHM.LoaderArg0.r32 = *addr;
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
    SHM.LoaderCommand.bits.Command = 0;
}

void wait_for_rx(const volatile DEVICE_t *device, const volatile SHM_t *shm)
{
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
            APE_PERI.BmcToNcRxControl.bits.ResetBad = 1;
            while (APE_PERI.BmcToNcRxControl.bits.ResetBad)
            {
                // Wait
            }
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
                        initRMU();
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
            if (APE.Tick1khz.r32 - inProgressStartTime > RMU_WATCHDOG_TIMEOUT_MS)
            {
                printf("RMU Hang detected, resetting.\n");
                initRMU();
                packetInProgress = false;
            }
        }
        else
        {
            packetInProgress = true;
            inProgressStartTime = APE.Tick1khz.r32;
        }
    }
}

void checkSupply(bool alwaysReport)
{
    static int gVMainOn = false;
    int status = DEVICE.Status.bits.VMAINPowerStatus;
    if (alwaysReport || gVMainOn != status)
    {
        printf("VMAINPowerStatus: %d\n", status);
        if (0 == status && !alwaysReport)
        {
            printf("Powered off, resetting\n");
            wait_for_all_rx();
            initRMU();
            NCSI_reload(ALWAYS_RESET);
        }

        gVMainOn = status;
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
        handleCommand();
        checkSupply(false);

        if (host_state != SHM.HostDriverState.bits.State)
        {
            host_state = SHM.HostDriverState.bits.State;
            if (SHM_HOST_DRIVER_STATE_STATE_START == host_state)
            {
                printf("host started\n");
                wait_for_all_rx();
                initRMU();
                NCSI_reload(NEVER_RESET);
            }
            else
            {
                wait_for_all_rx();
                initRMU();
                if (SHM_HOST_DRIVER_STATE_STATE_UNLOAD == host_state)
                {
                    printf("host unloaded.\n");
                    NCSI_reload(ALWAYS_RESET);
                }
                else
                {
                    printf("wol?\n");
                    NCSI_reload(AS_NEEDED);
                }
            }
        }

        Network_checkPortState(gPort);
    }
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
    bool full_init = handle_reset();
    if (reset_ape_console())
    {
        full_init = true;
    }

    printf("APE v" STRINGIFY(VERSION_MAJOR) "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH) " NCSI Port " STRINGIFY(NETWORK_PORT) "\n");
    gPort = Network_getPort(NETWORK_PORT);

    NCSI_usePort(gPort);

    checkSupply(true);

    initRMU();

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

    loaderLoop();
}
