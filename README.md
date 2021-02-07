# BCM5719 Firmware Reimplementation
This project contains a clean-room reimplementation of the BCM5719 firmware based on the [Ortega](https://github.com/hlandau/ortega/blob/master/rtg-spec.md) specification.

The firmware has been tested on the [Talos II](https://wiki.raptorcs.com/wiki/Talos_II) and [Blackbird](https://wiki.raptorcs.com/wiki/Blackbird) made by [Raptor Computer Systems](https://www.raptorcs.com/).

**Note: This firmware is currently in development. Flashing the firmware to a network card can result in a bricked device when either an external programmer is required, or the external flash must be temporarily disabled during boot-up.**

# Status
The current version of the code is functional and is able to handle network traffic over NC-SI.
  - Libraries:
    - MII Library: Done
    - NVRAM Library: Done
  - Stage1/Stage2
    - Implementation: Functional
    - Testing: Minimal, WIP
    - VPD: Functional
    - WOL: Not started
  - APE
    - NC-SI Handler: Functional
      - Get Version ID: Not Implemented
      - OEM Command: Not Implemented
    - BMC <-> Network Communication: Working
  - Utilities
    - Firmware tool: Functional
    - Register tool: Functional
  - Tests: To be written

# Usage
Blackbird and Talos II users may install this firmware using [fwupd](https://fwupd.org/), either via the Linux Vendor Firmware Service, or manually using `fwupdtool` and a [release archive](https://github.com/meklort/bcm5719-fw/releases). Other BCM5719 devices may not be thoroughly tested, or tested at all; should you wish to proceed, it is encouraged to download or [build](#building) the firmware and refer to instructions in [Development](#development), especially the section on [testing APE firmware](#testing-ape-firmware).

## Installing using LVFS
This project provides firmware releases on LVFS that can be installed using fwupd 1.5.2 or later.
The firmware can be selected for install by following the prompts using the `switch-branch` command in `fwupdmgr`:
```bash
sudo fwupdmgr switch-branch
```

This will flash the latest firmware from LVFS onto the network card and will save a backup of the previous firmware in `/var/lib/fwupd/backup/`.

Once switched, future releases will be installed using the standard update mechanism in fwupd.

## Installing using fwupdtool
Alternatively to using LVFS, the fwupd cab files in the release package can be manually flashed with `fwupdtool` 1.5.2 or later.

For **Talos II**:
```bash
sudo fwupdtool install ./fwupd/talos2-bcm5719-<version>.cab --allow-branch-switch
```
For **Blackbird**:
```bash
sudo fwupdtool install ./fwupd/blackbird-bcm5719-<version>.cab --allow-branch-switch
```

## Restoring From Backup
Past firmware images can be restored from backup using the bcmflash tool.
* If fwupd was used to flash firmware, past backups can be located at `/var/lib/fwupd/backup/`.
* If `bcmflash` was used to [create a backup](#backup-firmware) the previously saved `firmware.fw` should be used.

To restore a backup, the following command can be run:
```bash
sudo ./bin/bcmflash -t eth -i enP4p1s0f0 -r firmware.fw
```

# Building

### Requirements
This repository depends on a number of external tools
- Customized LLVM/Clang compiler for MIPS firmware
- CMake 3.5.1+
- Linux (utilities)
- IPXact generator (optional)

### Required Compiler
Due to limitations in the MIPS CPU, this firmware requires a custom compiler to function properly.
The custom compiler can be built using the following steps:
```bash
git clone https://github.com/meklort/llvm-project.git -b meklort-10.0.1
cd llvm-project
mkdir build
cd build
cmake ../llvm -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/llvm-bcm5719 -DLLVM_ENABLE_PROJECTS="lld;clang"
ninja
ninja install
```

### Compiling
To compile the firmware, the following command sequence can be used:
```bash
git submodule init
git submodule update
mkdir build
cd build
cmake .. -G Ninja
cmake --build .
```

## Development
To access the APE console, test APE firmware in RAM, etc., the Linux `tg3` driver must be unbound from at least one PCIe function of the NIC. Each function corresponds to a single Ethernet port; for instance, the Talos II has `0004:01:00.0` and `0004:01:00.1`, while the Blackbird additionally has `0004:01:00.2`. Unbinding will disable the corresponding `enP4p1s0f#` network adapter.

A function can be unbound via sysfs as follows:
```bash
echo 0004:01:00.0 > /sys/bus/pci/drivers/tg3/unbind
```

Rebinding is similar, except that the address is written to `bind` instead of `unbind`.

Unbinding a function allows `bcmflash` to access the device via `-t raw`, which is used with the `-i` option to select the function number to use.

Binding a function allows `bcmflash` to access the device via `-t eth`, with is used with the `-i` option to select the ethernet interface to use.

### Testing APE firmware

After unbinding the driver per the above, the APE firmware can be tested by loading it into RAM using the following sequence (note that this may fail if stage1 has not been loaded):

#### Talos II (BMC traffic on port 0)
```bash
cd build
sudo ./utils/bcmregtool/bcmregtool --apeboot=ape/ape-port0.bin
```

#### Blackbird (BMC traffic on port 2)
```bash
cd build
sudo ./utils/bcmregtool/bcmregtool --apeboot=ape/ape-port2.bin
```

### Firmware Log
The APE and Stage1 firmware are able to print status messages to a log. This can be accessed in one of two ways:
 * The ./utils/apeconsole/apeconsole utility can be used if no driver is loaded by the host.
 * The EM100Pro console can be used if wired to the SPI bus on the BCM5719. This allows for printouts even when the host is off.

## Backup Firmware
Before altering the BCM5719 flash, the original firmware should be backed up using `bcmflash` and the appropriate `-t` and `-i` options as described in [Development](#Development)

```bash
cd build
sudo ./bin/bcmflash -t eth -i enP4p1s0f0 -b binary
```
This will result in a firmware image, `firmware.fw`, being stored in the current directory.

## Flashing Firmware with bcmflash
The flash can be updated with development firmware using `bcmflash` and the appropriate `-t` and `-i` options as described in [Development](#Development)

### Updating the MIPS Firmware
```bash
cd build
sudo ./bin/bcmflash -t eth -i enP4p1s0f0 -1 stage1/stage1-port0.bin
```

### Updating the APE Firmware
```bash
cd build
sudo ./bin/bcmflash -t eth -i enP4p1s0f0 -a ape/ape-port0.bin
```
