////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.c
///
/// @project
///
/// @brief      Main stage1 code
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

#include "ape.h"

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
#include <Network.h>
#include <types.h>

#ifndef CXX_SIMULATOR
#include <printf.h>
#endif

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

void wait_for_rx(volatile DEVICE_t *device, volatile SHM_t *shm)
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
    uint32_t buffer[1024];

    RegAPE_PERIBmcToNcRxStatus_t stat;
    stat.r32 = APE_PERI.BmcToNcRxStatus.r32;

    if (stat.bits.New)
    {
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
            int32_t bytes = stat.bits.PacketLength;
            if (!stat.bits.Passthru)
            {
                int32_t words = DIVIDE_RND_UP(bytes, sizeof(uint32_t));
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
                NetworkPort_t *port = &gPort0;
                if (port->shm_channel->NcsiChannelInfo.bits.Enabled)
                {
                    if (!Network_TX_transmitPassthroughPacket(bytes, port))
                    {
                        printf("Resetting TX...\n");
                        // Reset TX, as it's likely locked up now.
                        // Network_resetTX(port);
                        Network_InitPort(port);
                    }
                }
                else
                {
                    printf("Dropping PT\n");
                    int32_t words = DIVIDE_RND_UP(bytes, sizeof(uint32_t));
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
}

void checkSupply(bool alwaysReport)
{
    static int gVMainOn;
    if (alwaysReport || (gVMainOn != DEVICE.Status.bits.VMAINPowerStatus))
    {
        gVMainOn = DEVICE.Status.bits.VMAINPowerStatus;
        printf("VMAINPowerStatus: %d\n", gVMainOn);
    }
}

void __attribute__((noreturn)) loaderLoop(void)
{
    uint32_t host_state = SHM.HostDriverState.bits.State;
    // Update SHM.Sig to signal ready.
    SHM.SegSig.bits.Sig = SHM_SEG_SIG_SIG_LOADER;
    SHM.FwStatus.bits.Ready = 1;

    printf("APE Ready\n");
    for (;;)
    {
        handleBMCPacket();
        NCSI_handlePassthrough();
        handleCommand();
        checkSupply(false);

        // Make sure we haven't locked up the RMU state machine.
        if (APE_PERI.BmcToNcRxStatus.bits.InProgress)
        {
            printf("BMC in prog, initRMU\n");
            initRMU();
            APE_PERI.BmcToNcRxControl.bits.ResetBad = 1;
            while (APE_PERI.BmcToNcRxControl.bits.ResetBad)
            {
                // Wait
            }
        }

        if (host_state != SHM.HostDriverState.bits.State)
        {
            host_state = SHM.HostDriverState.bits.State;
            if (SHM_HOST_DRIVER_STATE_STATE_UNLOAD == host_state)
            {
                printf("host unloaded.\n");
                wait_for_all_rx();
                NCSI_reload(ALWAYS_RESET);
            }
            else if (SHM_HOST_DRIVER_STATE_STATE_START == host_state)
            {
                printf("host started\n");
                initRMU();
            }
            else
            {
                printf("wol?\n");
            }
        }
        else if (0 == APE.Mode.bits.Channel0Enable)
        {
            // This will trigger any time the host is unloaded.
            printf("Channel0Enable == 0. Reset TX/RX\n");
            wait_for_all_rx();
            // Channel enable was cleared.
            NCSI_reload(SHM_HOST_DRIVER_STATE_STATE_START != SHM.HostDriverState.bits.State ? ALWAYS_RESET : NEVER_RESET);
            initRMU();
        }
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

void __attribute__((noreturn)) __start()
{
    if (handle_reset() || SHM.RcpuWritePointer.r32 > sizeof(SHM.RcpuPrintfBuffer) || SHM.RcpuReadPointer.r32 > sizeof(SHM.RcpuPrintfBuffer) ||
        SHM.RcpuHostReadPointer.r32 > sizeof(SHM.RcpuPrintfBuffer))
    {
        SHM.RcpuWritePointer.r32 = 0;
        SHM.RcpuReadPointer.r32 = 0;
        SHM.RcpuHostReadPointer.r32 = 0;
        printf("Chip Reset.\n");
        initRMU();

        NCSI_init();
    }
    else
    {
        printf("APE Reload.\n");
        initRMU();
        NCSI_reload(SHM_HOST_DRIVER_STATE_STATE_START != SHM.HostDriverState.bits.State ? AS_NEEDED : NEVER_RESET);
    }

    checkSupply(true);

    printf("Begin APE.\n");

    loaderLoop();
}
