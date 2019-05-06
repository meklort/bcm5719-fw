# BCM5719 Firmware Reimplementation

## Introduction
This library contains a clean-room reimplementation of the BCM5719 firmware based on the [Ortega](https://github.com/hlandau/ortega/blob/master/rtg-spec.md) specification.

The firmware has been tested on the [Talos II](https://wiki.raptorcs.com/wiki/Talos_II) by [Raptor Computer Systems](https://www.raptorcs.com/).

**Note: This firmware is currently in development. Flashing the firmware to a network card can result in a bricked device when either an external programmer is required, or the external flash must be temporarily disabled during boot-up.**

## Requirements
This repository depends on a number of external tools
- Customized LLVM/Clang compiler for MIPS firmware
- CMake 3.5.1+
- Linux (utilities)
- Clang Format (optional)
- Flexelint/PCLint+ (optional)
- IPXact generator (optional)

### Required Compiler
Due to limitations in the MIPS CPU, this firmware requires a custom compiler to function properly.
The custom compuler can be built using the following steps:
```bash
git clone https://github.com/meklort/llvm-project.git -b meklort-7.0.1
cd llvm-project
mkdir build
cd build
cmake ../llvm -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/llvm-bcm5719
ninja
ninja install
```

## Status
  - Libraries:
    - MII Library: Done
    - NVRAM Library: Done   
  - Stage1
    - Implementation: Functional
    - Testing: Minimal, WIP
  - Stage2
    - Implementation: Merged with Stage1, functional
    - VPD: Not started
    - WOL: Not started
  - APE
    - Implementation in progress
  - Utilities
    - Firmware tool: Functional
    - Register tool: Functional
    - APE Tool: In progress

## Compiling
To compile the firmware, the following command sequence can be used:
```bash
mkdir build
cd build
cmake .. -G Ninja
cmake --build .
```

