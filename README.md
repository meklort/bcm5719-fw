# BCM5719 Firmware Reimplementation

## Introduction
This library contains a clean-room reimplementation of the BCM5719 firmware based on the [Ortega](https://github.com/hlandau/ortega/blob/master/rtg-spec.md) specification.

The firmware has been tested on on the [Talos II](https://wiki.raptorcs.com/wiki/Talos_II) by [Raptor Computer Systems](https://www.raptorcs.com/)

**Note: This firmware is currently in development. Flashing the firmware to a network card can result in a bricked device when either an external programmer is required, or the external flash must be temporarily disabled during boot-up.**

## Requirements
This repository depends on a number of external tools
- Customized LLVM/Clang compiler for MIPS firmware
- CMake 3.5.1+
- Linux (utilities)
- Clang Format (optional)
- Flexelint/PCLint+ (optional)
- IPXact generator (optional)

## Status
  - Libraries:
    - MII Library: Done
    - NVRAM Library: Done   
  - Stage1
    - Implementation: Functional
    - Testing: Minimal, WIP
  - Stage2
    - Implimentation: Merged with Stage1, functional
    - VPD: Not started
    - WOL: Not started
  - APE
    - Implementation in progress
  - Utilities
    - Firmware tool: Functional
    - Register tool: Functional
    - APE Tool: In progress