////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.cpp
///
/// @project
///
/// @brief      Main bcm regiuster tool for decoding BCM5179 registers.
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

#include "../NVRam/bcm5719_NVM.h"

#include <APE.h>
#include <APE_APE_PERI.h>
#include <APE_DEVICE.h>
#include <APE_NVIC.h>
#include <HAL.hpp>
#include <MII.h>
#include <NVRam.h>
#include <OptionParser.h>
#include <bcm5719-endian.h>
#include <bcm5719_APE.h>
#include <bcm5719_GEN.h>
#include <bcm5719_SHM.h>
#include <bcm5719_SHM_CHANNEL0.h>
#include <bcm5719_SHM_CHANNEL1.h>
#include <bcm5719_eeprom.h>
#include <elfio/elfio.hpp>
#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>

#define VERSION_STRING STRINGIFY(VERSION_MAJOR) "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH)

using namespace std;
using namespace ELFIO;
using optparse::OptionParser;

elfio gELFIOReader;

const char *regnames[32] = {
    "$zero",                                                  /* Zero register - always 0 */
    "$at",                                                    /* Assembler register */
    "$v0",   "$v1",                                           /* Results */
    "$a0",   "$a1", "$a2", "$a3",                             /* Aguments */
    "$t0",   "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", /* Temp, not saved */
    "$s0",   "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", /* Saved registers */
    "$t8",   "$t9",                                           /* Temp, not saved */
    "$k0",   "$k1",                                           /* Kernel / OS */
    "$gp",   "$sp", "$fp",                                    /* Pointers */
    "$ra",                                                    /* return address */
};

void boot_ape_loader()
{
    extern unsigned char apeloader_bin[];
    extern unsigned int apeloader_bin_len;

    int function = DEVICE.Status.bits.FunctionNumber;
    int numWords = apeloader_bin_len / 4;

    RegAPEMode_t mode;
    mode.r32 = 0;
    mode.bits.Halt = 1;
    mode.bits.FastBoot = 1;
    APE.Mode = mode;

    // We hijack the complete SHM here.

    // load file.
    for (int i = 0; i < numWords; i++)
    {
        SHM.write(0x0B00 + i * 4, htobe32(((uint32_t *)apeloader_bin)[i]));
    }

    // Mark fw as not read.
    SHM.FwStatus.bits.Ready = 0;
    // Start the file
    APE.GpioMessage.r32 = 0x60220B00 | 2 + (0x1000 * function);

    mode.bits.Halt = 0;
    mode.bits.FastBoot = 1;
    mode.bits.Reset = 1;
    APE.Mode = mode;

    // Wait for ready.
    while (0 == SHM.FwStatus.bits.Ready)
        ;
}

uint32_t loader_read_mem(uint32_t addr)
{
    SHM.LoaderArg0.r32 = addr;
    SHM.LoaderCommand.bits.Command = SHM_LOADER_COMMAND_COMMAND_READ_MEM;

    // Wait for command to be handled.
    while (0 != SHM.LoaderCommand.bits.Command)
        ;

    return (uint32_t)SHM.LoaderArg0.r32;
}

void loader_write_mem(uint32_t addr, uint32_t value)
{
    SHM.LoaderArg0.r32 = addr;
    SHM.LoaderArg1.r32 = value;
    SHM.LoaderCommand.bits.Command = SHM_LOADER_COMMAND_COMMAND_WRITE_MEM;

    // Wait for command to be handled.
    while (0 != SHM.LoaderCommand.bits.Command)
        ;
}

const string symbol_for_address(uint32_t address, uint32_t &offset)
{
    Elf_Half sec_num = gELFIOReader.sections.size();

    for (int i = 0; i < sec_num; ++i)
    {
        section *psec = gELFIOReader.sections[i];
        // Check section type
        if (psec->get_type() == SHT_SYMTAB)
        {
            const symbol_section_accessor symbols(gELFIOReader, psec);
            for (unsigned int j = 0; j < symbols.get_symbols_num(); ++j)
            {
                std::string name;
                Elf64_Addr value;
                Elf_Xword size;
                unsigned char bind;
                unsigned char type;
                Elf_Half section_index;
                unsigned char other;

                // Read symbol properties
                if (symbols.get_symbol(j, name, value, size, bind, type, section_index, other))
                {
                    if (value <= address && value + size > address)
                    {
                        offset = address - value;
                        return name;
                    }
                }
            }
        }
    }

    return string("unknown");
}

void print_context(void)
{
    uint32_t r[32];
    uint32_t pc;
    uint32_t opcode;

    // Read out the device context.
    pc = DEVICE.RxRiscProgramCounter.r32;
    opcode = DEVICE.RxRiscCurrentInstruction.r32;
    r[0] = DEVICE.RxRiscRegister0.r32;
    r[1] = DEVICE.RxRiscRegister1.r32;
    r[2] = DEVICE.RxRiscRegister2.r32;
    r[3] = DEVICE.RxRiscRegister3.r32;
    r[4] = DEVICE.RxRiscRegister4.r32;
    r[5] = DEVICE.RxRiscRegister5.r32;
    r[6] = DEVICE.RxRiscRegister6.r32;
    r[7] = DEVICE.RxRiscRegister7.r32;
    r[8] = DEVICE.RxRiscRegister8.r32;
    r[9] = DEVICE.RxRiscRegister9.r32;
    r[10] = DEVICE.RxRiscRegister10.r32;
    r[11] = DEVICE.RxRiscRegister11.r32;
    r[12] = DEVICE.RxRiscRegister12.r32;
    r[13] = DEVICE.RxRiscRegister13.r32;
    r[14] = DEVICE.RxRiscRegister14.r32;
    r[15] = DEVICE.RxRiscRegister15.r32;
    r[16] = DEVICE.RxRiscRegister16.r32;
    r[17] = DEVICE.RxRiscRegister17.r32;
    r[18] = DEVICE.RxRiscRegister18.r32;
    r[19] = DEVICE.RxRiscRegister19.r32;
    r[20] = DEVICE.RxRiscRegister20.r32;
    r[21] = DEVICE.RxRiscRegister21.r32;
    r[22] = DEVICE.RxRiscRegister22.r32;
    r[23] = DEVICE.RxRiscRegister23.r32;
    r[24] = DEVICE.RxRiscRegister24.r32;
    r[25] = DEVICE.RxRiscRegister25.r32;
    r[26] = DEVICE.RxRiscRegister26.r32;
    r[27] = DEVICE.RxRiscRegister27.r32;
    r[28] = DEVICE.RxRiscRegister28.r32;
    r[29] = DEVICE.RxRiscRegister29.r32;
    r[30] = DEVICE.RxRiscRegister30.r32;
    r[31] = DEVICE.RxRiscRegister31.r32;

    printf("==== Context ===\n");
    uint32_t sym_offset = 0;
    string symbol = symbol_for_address(pc, sym_offset);
    printf("   pc: 0x%08X (%s+%d)   opcode: 0x%08X \n", pc, symbol.c_str(), sym_offset, opcode);
    int numCols = 4;
    int offset = 32 / numCols;
    for (int i = 0; i < ARRAY_ELEMENTS(r) / 4; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            printf("$%d(%5s): 0x%08X    ", i + j * offset, regnames[i + j * offset], r[i + j * offset]);
        }
        printf("\n");
    }
}

void writeMemory(uint32_t rxAddr, uint32_t value)
{
    cout << "Updating " << std::hex << rxAddr << " to " << std::hex << value << endl;
    // Halt.
    RegDEVICERxRiscMode_t mode;
    mode.r32 = 0;
    mode.bits.Halt = 1;
    DEVICE.RxRiscMode = mode;

    DEVICE.RxRiscMode.print();

    // Save old state that we will clobber so we can restore it afterwards.
    uint32_t oldIP = DEVICE.RxRiscProgramCounter.r32;
    uint32_t oldT6 = DEVICE.RxRiscRegister14.r32;
    uint32_t oldT7 = DEVICE.RxRiscRegister15.r32;

    // Check that the instructions we are expecting to use are correct. This will
    // break if the ROM is different.
    DEVICE.RxRiscProgramCounter.r32 = 0x40000038;

    cout << "PC is now " << (uint32_t)DEVICE.RxRiscProgramCounter.r32 << endl;
    uint32_t iw = DEVICE.RxRiscCurrentInstruction.r32;
    if (iw != 0xADCF0000)
    { // sw $t7, 0($t6)
        fprintf(stderr, "cannot set RX word via forced store because the device has an unknown ROM (got 0x%08X)\n", iw);
        return;
    }

    DEVICE.RxRiscRegister14.r32 = rxAddr;
    DEVICE.RxRiscRegister15.r32 = value;

    mode.bits.SingleStep = 1;
    DEVICE.RxRiscMode = mode;

    // Don't remove this, it creates a small delay which seems to sometimes be
    // necessary.
    uint32_t pc = DEVICE.RxRiscProgramCounter.r32;
    if (pc != 0x4000003C)
    {
        fprintf(stderr, "  bad2 0x%08x\n", pc);
    }

    // Restore.
    DEVICE.RxRiscRegister15.r32 = oldT7;
    DEVICE.RxRiscRegister14.r32 = oldT6;
    DEVICE.RxRiscProgramCounter.r32 = oldIP;

    mode.bits.SingleStep = 0;
    DEVICE.RxRiscMode = mode;
}

void step(void)
{
    uint32_t oldPC = DEVICE.RxRiscProgramCounter.r32;

    RegDEVICERxRiscMode_t mode;
    mode.r32 = 0;
    mode.bits.SingleStep = 1;
    mode.bits.Halt = 1;
    DEVICE.RxRiscMode = mode;

    // Force a re-load of the next word.
    uint32_t newPC = DEVICE.RxRiscProgramCounter.r32;

    if (oldPC + 4 != newPC)
    {
        // branched. Re-read PC to re-read opcode
        DEVICE.RxRiscProgramCounter.r32 = DEVICE.RxRiscProgramCounter.r32;
    }
}

int main(int argc, char const *argv[])
{
    OptionParser parser = OptionParser().description("BCM Register Utility v" VERSION_STRING);

    parser.version(VERSION_STRING);

    parser.add_option("--elf").dest("debugfile").metavar("DEBUG_FILE").help("Elf file used for improved context decoding.");

    parser.add_option("-f", "--function")
        .dest("function")
        .type("int")
        .set_default("0")
        .metavar("FUNCTION")
        .help("Read registers from the specified pci function.");

    parser.add_option("-s", "--step").dest("step").set_default("0").action("store_true").help("Single step the CPU.");

    parser.add_option("-t", "--stepto").dest("stepto").metavar("ADDR").help("Single step the CPU.");

    parser.add_option("--halt").dest("halt").set_default("0").action("store_true").help("Halt the CPU.");

    parser.add_option("-pc", "--pc").dest("pc").help("Force the PC to the specified value.");

    parser.add_option("-c", "--context").dest("context").set_default("0").action("store_true").help("Print the current CPU context.");

    parser.add_option("-g", "--run").dest("run").set_default("0").action("store_true").help("Continue CPU execution.");

    parser.add_option("-i", "--info").dest("info").set_default("0").action("store_true").help("Print device information registers.");

    parser.add_option("-a", "--ape").dest("ape").set_default("0").action("store_true").help("Print ape information registers.");

    parser.add_option("-rx", "--rx").dest("rx").set_default("0").action("store_true").help("Print rx information registers.");

    parser.add_option("-tx", "--tx").dest("tx").set_default("0").action("store_true").help("Print tx information registers.");

    parser.add_option("-p", "--apeboot").dest("apeboot").metavar("APE_FILE").help("File to boot on the APE.");

    parser.add_option("--apehalt").dest("apehalt").set_default("0").action("store_true").help("Halt the APE.");

    parser.add_option("-n", "--network").dest("network").set_default("0").action("store_true").help("Print network information / status.");

    parser.add_option("--nvm").dest("nvm").set_default("0").action("store_true").help("Print NVM registers");

    parser.add_option("--nvic").dest("nvic").set_default("0").action("store_true").help("Print NVIC registers");

    parser.add_option("--unlock").dest("unlock").set_default("0").action("store_true").help("Unlock NVM and APE registers");

    parser.add_option("-apereset", "--apereset").dest("apereset").set_default("0").action("store_true").help("File to boot on the APE.");

    parser.add_option("-reset", "--reset").dest("reset").set_default("0").action("store_true").help("File to boot on the APE.");

    parser.add_option("-m", "--mii").dest("mii").set_default("0").action("store_true").help("Print MII information registers.");

    parser.add_option("-d", "--dumpregs").dest("dumpregs").set_default("0").action("store_true").help("Dump main device and APE registers.");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();

    if (!initHAL(NULL, options.get("function")))
    {
        cerr << "Unable to locate pci device with function " << (int)options.get("function") << endl;
        exit(-1);
    }

    if (options.is_set("debugfile"))
    {
        if (!gELFIOReader.load(options["debugfile"]))
        {
            cerr << "Unablt to read elf file " << options["debugfile"] << endl;
            exit(-1);
        }
    }

    if (options.get("step"))
    {
        do
        {
            cout << "Stepping...\n";
            step();
            print_context();

        } while (DEVICE.RxRiscProgramCounter.r32 > 0x40000000);
        exit(0);
    }

    if (options.is_set("stepto"))
    {
        uint32_t addr = stoi(options["stepto"], nullptr, 0);
        do
        {
            cout << "Stepping...\n";

            step();
            print_context();

        } while (DEVICE.RxRiscProgramCounter.r32 != addr);
        exit(0);
    }

    if (options.get("halt"))
    {
        cout << "Halting...\n";
        RegDEVICERxRiscMode_t mode;
        mode.r32 = 0;
        mode.bits.Halt = 1;
        DEVICE.RxRiscMode = mode;

        print_context();
        exit(0);
    }

    if (options.is_set("pc"))
    {
        uint32_t pc = stoi(options["pc"], nullptr, 0);

        std::ios::fmtflags fmt(std::cout.flags());
        cout << "Updating PC to 0x" << std::hex << pc << endl;
        std::cout.flags(fmt);

        RegDEVICERxRiscMode_t mode;
        mode.r32 = 0;
        mode.bits.Halt = 1;
        DEVICE.RxRiscMode = mode;

        DEVICE.RxRiscProgramCounter.r32 = pc;
        print_context();
        exit(0);
    }

    if (options.get("context"))
    {
        print_context();
        exit(0);
    }

    if (options.get("run"))
    {
        cout << "Running...\n";
        RegDEVICERxRiscMode_t mode;
        mode.r32 = 0; // Ensure single-step and halt are cleared
        DEVICE.RxRiscMode = mode;
        exit(0);
    }

    if (options.get("mii"))
    {
        uint8_t phy = MII_getPhy(&DEVICE);

        printf("MII Phy:          %d\n", phy);
        printf("MII PHY ID[high]: 0x%04X\n", MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_PHY_ID_HIGH));
        printf("MII PHY ID[low]:  0x%04X\n", MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_PHY_ID_LOW));

        RegMIIControl_t control;
        control.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_CONTROL);
        control.print();

        RegMIIStatus_t status;
        status.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_STATUS);
        status.print();

        RegMIIAutonegotiationAdvertisement_t auto_adv;
        auto_adv.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_AUTONEGOTIATION_ADVERTISEMENT);
        auto_adv.print();

        RegMIIAutonegotiationLinkPartnerAbilityBasePage_t auto_lpabp;
        auto_lpabp.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE);
        auto_lpabp.print();

        RegMIIAutonegotiationExpansion_t auto_exp;
        auto_exp.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_AUTONEGOTIATION_EXPANSION);
        auto_exp.print();

        RegMII1000baseTControl_t gig_baset;
        gig_baset.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_1000BASE_T_CONTROL);
        gig_baset.print();

        RegMII1000baseTStatus_t gig_baset_stat;
        gig_baset_stat.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_1000BASE_T_STATUS);
        gig_baset_stat.print();

        RegMIIIeeeExtendedStatus_t ieee_ext_status;
        ieee_ext_status.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_IEEE_EXTENDED_STATUS);
        ieee_ext_status.print();

        RegMIIPhyExtendedControl_t phy_ext_control;
        phy_ext_control.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_PHY_EXTENDED_CONTROL);
        phy_ext_control.print();

        RegMIIPhyExtendedStatus_t phy_ext_status;
        phy_ext_status.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_PHY_EXTENDED_STATUS);
        phy_ext_status.print();

        RegMIIReceiveErrorCounter_t rx_err;
        rx_err.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_RECEIVE_ERROR_COUNTER);
        rx_err.print();

        RegMIIFalseCarrierSenseCounter_t fcsc;
        fcsc.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_FALSE_CARRIER_SENSE_COUNTER);
        fcsc.print();

        RegMIILocalRemoteReceiverNotOkCounter_t rx_nok;
        rx_nok.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER);
        rx_nok.print();

        RegMIIAuxiliaryControl_t aux_control;
        aux_control.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_AUXILIARY_CONTROL);
        aux_control.print();

        RegMIIAuxiliaryStatusSummary_t aux_status;
        aux_status.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_AUXILIARY_STATUS_SUMMARY);
        aux_status.print();

        RegMIIInterruptStatus_t irq_status;
        irq_status.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_INTERRUPT_STATUS);
        irq_status.print();

        RegMIIInterruptMask_t irq_mask;
        irq_mask.r16 = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_INTERRUPT_MASK);
        irq_mask.print();

        exit(0);
    }

    if (options.is_set("apeboot"))
    {
        int fileLength = 0;
        int fileWords = 0;
#define NVRAM_SIZE (1024u * 256u) /* 256KB */

        union
        {
            uint8_t bytes[NVRAM_SIZE];
            uint32_t words[NVRAM_SIZE / 4];
        } ape;

        string &file = options["apeboot"];

        fstream infile;
        infile.open(file, fstream::in | fstream::binary);
        if (infile.is_open())
        {
            // get length of file:
            infile.seekg(0, infile.end);
            fileLength = infile.tellg();
            fileWords = fileLength / 4;
            infile.seekg(0, infile.beg);

            // Read in file
            infile.read((char *)ape.bytes, fileLength);

            infile.close();
        }
        else
        {
            cerr << " Unable to open file '" << file << "'" << endl;
            exit(-1);
        }

        boot_ape_loader();

        if (ape.words[0] == be32toh(APE_HEADER_MAGIC))
        {
            // The file is swapped... fix it.
            for (int i = 0; i < sizeof(ape) / sizeof(ape.words[0]); i++)
            {
                ape.words[i] = be32toh(ape.words[i]);
            }
        }

        // load file.
        for (int i = 0; i < fileWords; i++)
        {
            uint32_t addr = 0x10D800 + i * 4;
            loader_write_mem(addr, ape.words[i]);
        }

        RegAPEMode_t mode;
        mode.r32 = 0;
        mode.bits.Halt = 1;
        mode.bits.FastBoot = 1;
        APE.Mode = mode;

        // Set the payload address
        APE.GpioMessage.r32 = 0x10D800 | 2;

        // Clear the signature.
        SHM.SegSig.r32 = 0xBAD0C0DE;

        // Boot
        mode.bits.Halt = 0;
        mode.bits.FastBoot = 1;
        mode.bits.Reset = 1;
        APE.Mode = mode;

        exit(0);
    }

    if (options.get("apereset"))
    {

        // Halt
        RegAPEMode_t mode;
        mode.r32 = 0;
        mode.bits.Halt = 1;
        mode.bits.FastBoot = 0;
        APE.Mode = mode;

        // Boot
        mode.bits.Halt = 0;
        mode.bits.FastBoot = 0;
        mode.bits.Reset = 1;
        APE.Mode = mode;

        exit(0);
    }

    if (options.get("apehalt"))
    {
        // Halt
        RegAPEMode_t mode;
        mode.r32 = 0;
        mode.bits.Halt = 1;
        mode.bits.FastBoot = 0;
        APE.Mode = mode;

        exit(0);
    }
    if (options.get("reset"))
    {

        DEVICE.MiscellaneousConfig.bits.GRCReset = 1;
        exit(0);
    }

    if (options.get("rx"))
    {
        DEVICE.ReceiveMacMode.print();
        DEVICE.EmacMode.print();
        APE.RxbufoffsetFunc0.print();
        APE.RxPoolModeStatus0.print();

        exit(0);
    }

    if (options.get("tx"))
    {
        DEVICE.GrcModeControl.print();
        DEVICE.EmacMode.print();
        APE.Mode.print();
        APE.Status.print();
        APE.TxState0.print();
        APE.TxToNetPoolModeStatus0.print();
        APE.TxToNetBufferAllocator0.print();
        APE.TxToNetBufferRing0.print();
        APE.TxToNetBufferReturn0.print();
        APE.TxToNetDoorbellFunc0.print();
        if (APE.TxToNetDoorbellFunc0.bits.TXQueueFull)
        {
            fprintf(stderr, "TX Queue Full\n");
        }

        exit(0);
    }

    if (options.get("ape"))
    {
        APE.Mode.print();
        APE.Mode2.print();
        APE.Status.print();
        SHM.FwStatus.print();
        SHM.FwFeatures.print();
        SHM.FwVersion.print();

        printf("APE SegSig: 0x%08X\n", (uint32_t)SHM.SegSig.r32);
        printf("APE SegLen: 0x%08X\n", (uint32_t)SHM.ApeSegLength.r32);
        printf("APE RcpuApeResetCount: 0x%08X\n", (uint32_t)SHM.RcpuApeResetCount.r32);

        printf("APE RCPU SegSig: 0x%08X\n", (uint32_t)SHM.RcpuSegSig.r32);
        printf("APE RCPU SegLen: 0x%08X\n", (uint32_t)SHM.RcpuSegLength.r32);
        printf("APE RCPU Init Count: 0x%08X\n", (uint32_t)SHM.RcpuInitCount.r32);
        printf("APE RCPU FW Version: 0x%08X\n", (uint32_t)SHM.RcpuFwVersion.r32);

        printf("APE RCPU CfgFeature: 0x%08X\n", (uint32_t)SHM.RcpuCfgFeature.r32);
        printf("APE RCPU PCI Vendor/Device ID: 0x%08X\n", (uint32_t)SHM.RcpuPciVendorDeviceId.r32);
        printf("APE RCPU PCI Subsystem ID: 0x%08X\n", (uint32_t)SHM.RcpuPciSubsystemId.r32);

        DEVICE.PerfectMatch1High.print();
        DEVICE.PerfectMatch1Low.print();

        printf("\n======= NCSI =======\n");
        APE_PERI.RmuControl.print();
        APE_PERI.BmcToNcTxStatus.print();
        APE_PERI.BmcToNcTxControl.print();
        APE_PERI.BmcToNcRxStatus.print();
        APE_PERI.BmcToNcRxControl.print();
        SHM_CHANNEL0.NcsiChannelNcsiTx.print();
        SHM_CHANNEL0.NcsiChannelNcsiRx.print();

        printf("\n======= Port 0 =======\n");
        SHM_CHANNEL0.NcsiChannelNetworkTx.print();
        SHM_CHANNEL0.NcsiChannelNetworkRx.print();
        APE_PERI.BmcToNcSourceMacHigh.print();
        APE_PERI.BmcToNcSourceMacMatch0High.print();
        APE_PERI.BmcToNcSourceMacMatch0Low.print();
        APE_PERI.BmcToNcSourceMacMatch1High.print();
        APE_PERI.BmcToNcSourceMacMatch1Low.print();
        APE_PERI.BmcToNcSourceMacMatch2High.print();
        APE_PERI.BmcToNcSourceMacMatch2Low.print();
        APE_PERI.BmcToNcSourceMacMatch3High.print();
        APE_PERI.BmcToNcSourceMacMatch3Low.print();
        APE_PERI.ArbControl.print();

        printf("\n** TX ** \n");
        APE.TxToNetPoolModeStatus0.print();
        APE.TxToNetBufferAllocator0.print();
        APE.TxToNetBufferRing0.print();

        printf("\n** RX ** \n");
        APE.RxbufoffsetFunc0.print();
        APE.RxPoolRetire0.print();
        APE.RxPoolFreePointer0.print();
        APE.RxPoolModeStatus0.print();

        exit(0);
    }

    if (options.get("dumpregs"))
    {
        DEVICE.print();
        APE.print();
        APE_PERI.print();

        exit(0);
    }

    if (options.get("unlock"))
    {
        NVRam_releaseAllLocks();
        APE_releaseAllLocks();

        // Ensure we don't have bitbang mode enabled.
        NVRam_acquireLock();
        NVM.NvmCfg1.bits.BitbangMode = 0;
        NVRam_releaseLock();

        exit(0);
    }
    if (options.get("nvm"))
    {
        NVM.print();

        exit(0);
    }

    if (options.get("nvic"))
    {
        NVIC.print();

        exit(0);
    }

    if (options.get("network"))
    {
        RegMIIStatus_t stat;

        uint8_t phy = MII_getPhy(&DEVICE);
        APE_aquireLock();
        uint16_t status_value = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_STATUS);
        stat.r16 = status_value;
        stat.print();
        if (stat.bits.ExtendedStatusSupported)
        {
            RegMIIIeeeExtendedStatus_t ext_stat;
            uint16_t ext_status_value = MII_readRegister(&DEVICE, phy, (mii_reg_t)REG_MII_IEEE_EXTENDED_STATUS);
            ext_stat.r16 = ext_status_value;
            ext_stat.print();
        }

        APE_releaseLock();

        exit(0);
    }

    if (options.get("info"))
    {
        GEN.GenDataSig.print();
        GEN.GenFwMbox.print();
        GEN.GenAsfStatusMbox.print();
        GEN.GenFwVersion.print();
        DEVICE.ChipId.print();
        DEVICE.PciVendorDeviceId.print();
        DEVICE.PciSubsystemId.print();
        DEVICE.PciClassCodeRevision.print();
        DEVICE.Status.print();

        // GenCfgFeature
        // GenCfgHw
        // GenCfgShared
        // GenCfgHw2
        // GenCfg5

        printf("\n");

        uint64_t serial = (((uint64_t)(DEVICE.PciSerialNumberHigh.r32)) << 32) | DEVICE.PciSerialNumberLow.r32;
        printf("Serial Number:   0x%016lX\n", serial);

        uint64_t genmac = (((uint64_t)(GEN.GenMacAddrHighMbox.r32)) << 32) | GEN.GenMacAddrLowMbox.r32;
        printf("GEN Mac Addr:   0x%016lX\n", genmac);

        printf("\n");

        printf("Power Budget[0]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget0.r32);
        printf("Power Budget[1]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget1.r32);
        printf("Power Budget[2]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget2.r32);
        printf("Power Budget[3]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget3.r32);
        printf("Power Budget[4]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget4.r32);
        printf("Power Budget[5]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget5.r32);
        printf("Power Budget[6]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget6.r32);
        printf("Power Budget[7]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget7.r32);

        printf("\n");

        uint64_t mac0 = (((uint64_t)(DEVICE.EmacMacAddresses0High.r32)) << 32) | DEVICE.EmacMacAddresses0Low.r32;
        uint64_t mac1 = (((uint64_t)(DEVICE.EmacMacAddresses1High.r32)) << 32) | DEVICE.EmacMacAddresses1Low.r32;
        uint64_t mac2 = (((uint64_t)(DEVICE.EmacMacAddresses2High.r32)) << 32) | DEVICE.EmacMacAddresses2Low.r32;
        uint64_t mac3 = (((uint64_t)(DEVICE.EmacMacAddresses3High.r32)) << 32) | DEVICE.EmacMacAddresses3Low.r32;
        printf("MAC0: 0x%012lX\n", mac0);
        printf("MAC1: 0x%012lX\n", mac1);
        printf("MAC2: 0x%012lX\n", mac2);
        printf("MAC3: 0x%012lX\n", mac3);

        printf("\n");

        printf("Reg 6408: 0x%08X\n", (uint32_t)DEVICE._6408.r32);
        printf("Reg 64c0: 0x%08X\n", (uint32_t)DEVICE._64c0.r32);
        printf("Reg 64c8: 0x%08X\n", (uint32_t)DEVICE._64c8.r32);
        printf("Reg 64dc: 0x%08X\n", (uint32_t)DEVICE._64dc.r32);
        printf("Reg 6530: 0x%08X\n", (uint32_t)DEVICE._6530.r32);
        printf("Reg 6550: 0x%08X\n", (uint32_t)DEVICE._6550.r32);
        printf("Reg 65f4: 0x%08X\n", (uint32_t)DEVICE._65f4.r32);
        printf("Reg 7c04: 0x%08X\n", (uint32_t)DEVICE._7c04.r32);

        DEVICE.LedControl.print();
        printf("GrcModeControl:     0x%08X\n", (uint32_t)DEVICE.GrcModeControl.r32);
        // DEVICE.GrcModeControl.bits.NVRAMWriteEnable = 1;
        DEVICE.GrcModeControl.print();
        DEVICE.GphyControlStatus.print();
        DEVICE.TopLevelMiscellaneousControl1.print();
        DEVICE.MiscellaneousLocalControl.print();

        DEVICE.RxRiscMode.print();
        DEVICE.RxRiscStatus.print();

        DEVICE.RxCpuEventEnable.print();
        DEVICE.RxCpuEvent.print();
        exit(0);
    }

    printf("EmacMode.PortMode: %0x\n", (uint32_t)DEVICE.EmacMode.bits.PortMode);
    printf("RxRiscMode: %0x\n", (uint32_t)DEVICE.RxRiscMode.r32);

    // printf("HostDriverId: %0x\n", APE.HostDriverId.r32);
    // printf("RcpuPciSubsystemId: %0x\n", APE.RcpuPciSubsystemId.r32);

    print_context();

    return 0;
}
