# BCM5719 Firmware Reimplementation

## Introduction
This library contains a clean-room reimplementation of the BCM5719 firmware based on the [Ortega](https://github.com/hlandau/ortega/blob/master/rtg-spec.md) specification.

The firmware has been tested on the [Talos II](https://wiki.raptorcs.com/wiki/Talos_II) and [Blackbird](https://wiki.raptorcs.com/wiki/Blackbird) made by [Raptor Computer Systems](https://www.raptorcs.com/).

**Note: This firmware is currently in development. Flashing the firmware to a network card can result in a bricked device when either an external programmer is required, or the external flash must be temporarily disabled during boot-up.**

## Requirements
This repository depends on a number of external tools
- Customized LLVM/Clang compiler for MIPS firmware
- CMake 3.5.1+
- Linux (utilities)
- IPXact generator (optional)

### Required Compiler
Due to limitations in the MIPS CPU, this firmware requires a custom compiler to function properly.
The custom compiler can be built using the following steps:
```bash
git clone https://github.com/meklort/llvm-project.git -b meklort-10.0.0
cd llvm-project
mkdir build
cd build
cmake ../llvm -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/llvm-bcm5719 -DLLVM_ENABLE_PROJECTS="lld;clang"
ninja
ninja install
```

## Status
The current version of the code is functional and is able to handle network traffic over NC-SI
  - Libraries:
    - MII Library: Done
    - NVRAM Library: Done   
  - Stage1/Stage2
    - Implementation: Functional
    - Testing: Minimal, WIP
    - VPD: Started, not functional
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

## Compiling
To compile the firmware, the following command sequence can be used:
```bash
mkdir build
cd build
cmake .. -G Ninja
cmake --build .
```

## Usage
Before proceeding, the Linux driver must be unloaded. On the Talos II, this can be done as root with the following:
```bash
echo 0004:01:00.0 > /sys/bus/pci/devices/0004:01:00.0/driver/unbind
echo 0004:01:00.1 > /sys/bus/pci/devices/0004:01:00.1/driver/unbind
```

### Backup Firmware
Before proceeding, the original firmware should be backed up.
```bash
cd build
sudo ./utils/bcmflash/bcmflash -t hardware -b binary
```
This will result in a firmware image, firmware.fw, bing stored in the current directory.

### Stage 1 - MIPS Firmware
After compilation, the MIPS firmware is ready to be uploaded to the NIC.
```bash
cd build
sudo ./utils/bcmflash/bcmflash -t hardware -1 stage1/stage1.bin
```

### APE Firmware (BMC/NC-SI communication)
The APE firmware can be tested by loading it into ram using the following sequence (Note: this may fail unless if stage1 has been loaded):

#### Testing on the Talos II with port 0 for BMC traffic
<details>

```bash
cd build
sudo ./utils/bcmregtool/bcmregtool --apeboot=ape/ape-port0.bin
```

Once tested, the APE firmware can be loaded into the device using the following command:
```bash
cd build
sudo ./utils/bcmflash/bcmflash -t hardware -a ape/ape-port0.bin
```
</details>

#### Testing on the Blackbird with port 2 for BMC traffic
<details>

```bash
cd build
sudo ./utils/bcmregtool/bcmregtool --apeboot=ape/ape-port2.bin
```

Once tested, the APE firmware can be loaded into the device using the following command:
```bash
cd build
sudo ./utils/bcmflash/bcmflash -t hardware -a ape/ape-port2.bin
```
</details>

### Firmware Log
The APE and Stage1 firmware are able to print status messages to a log. This can be accessed in one of two ways:
 * The ./utils/apeconsole/apeconsole utility can be used if no driver is loaded by the host.
 * The EM100Pro console can be used if wired to the SPI bus on the BCM5719. This allows for printouts even when the host is off.
