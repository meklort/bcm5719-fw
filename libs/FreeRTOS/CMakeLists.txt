################################################################################
###
### @file       libs/Network/CMakeLists.txt
###
### @project
###
### @brief      Network CMake file
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2019, Evan Lojewski
### @cond
###
### All rights reserved.
###
### Redistribution and use in source and binary forms, with or without
### modification, are permitted provided that the following conditions are met:
### 1. Redistributions of source code must retain the above copyright notice,
### this list of conditions and the following disclaimer.
### 2. Redistributions in binary form must reproduce the above copyright notice,
### this list of conditions and the following disclaimer in the documentation
### and/or other materials provided with the distribution.
### 3. Neither the name of the copyright holder nor the
### names of its contributors may be used to endorse or promote products
### derived from this software without specific prior written permission.
###
################################################################################
###
### THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
### AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
### IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
### ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
### LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
### CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
### SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
### INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
### CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
### ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
### POSSIBILITY OF SUCH DAMAGE.
### @endcond
################################################################################

project(FreeRTOS)

# .\app\main_full.c
# .\app\main_blinky.c
# .\app\main.c
# .\app\IntQueueTimer.h
# .\app\IntQueueTimer.c
# .\app\FreeRTOSConfig.h
# .\Keil_specific\RegTest_Keil.s
# .\Keil_specific\compiler_attributes.h
# .\board\boards\board.c
# .\board\boards\board.h
# .\board\boards\clock_config.c
# .\board\boards\clock_config.h
# .\board\boards\peripherals.c
# .\board\boards\peripherals.h
# .\board\boards\pin_mux.c
# .\board\boards\pin_mux.h
# .\component\lists\generic_list.h
# .\component\lists\generic_list.c
# .\component\serial_manager\serial_manager.c
# .\component\serial_manager\serial_manager.h
# .\component\serial_manager\serial_port_internal.h
# .\component\serial_manager\serial_port_uart.c
# .\component\serial_manager\serial_port_uart.h
# .\component\uart\uart.h
# .\component\uart\usart_adapter.c
# .\device\fsl_device_registers.h
# .\device\LPC51U68.h
# .\device\LPC51U68_features.h
# .\device\system_LPC51U68.c
# .\device\system_LPC51U68.h
# .\drivers\fsl_clock.c
# .\drivers\fsl_clock.h
# .\drivers\fsl_common.c
# .\drivers\fsl_common.h
# .\drivers\fsl_ctimer.c
# .\drivers\fsl_ctimer.h
# .\drivers\fsl_flexcomm.c
# .\drivers\fsl_flexcomm.h
# .\drivers\fsl_gpio.c
# .\drivers\fsl_gpio.h
# .\drivers\fsl_iocon.h
# .\drivers\fsl_pint.c
# .\drivers\fsl_pint.h
# .\drivers\fsl_power.c
# .\drivers\fsl_power.h
# .\drivers\fsl_reset.c
# .\drivers\fsl_reset.h
# .\drivers\fsl_usart.c
# .\drivers\fsl_usart.h
# .\Keil_specific\startup_LPC51U68.s
# .\utilities\fsl_assert.c
# .\utilities\fsl_debug_console.c
# .\utilities\fsl_debug_console.h
# .\utilities\fsl_debug_console_conf.h
# .\utilities\fsl_str.c
# .\utilities\fsl_str.h
# .\CMSIS\arm_common_tables.h
# .\CMSIS\arm_const_structs.h
# .\CMSIS\cmsis_armcc.h
# .\CMSIS\cmsis_armclang.h
# .\CMSIS\cmsis_compiler.h
# .\CMSIS\cmsis_gcc.h
# .\CMSIS\cmsis_iccarm.h
# .\CMSIS\cmsis_version.h
# .\CMSIS\core_cm0plus.h


SET(SOURCES
    # FreeRTOS-Kernel/croutine.c
    FreeRTOS-Kernel/event_groups.c
    FreeRTOS-Kernel/list.c
    FreeRTOS-Kernel/queue.c
    # FreeRTOS-Kernel/stream_buffer.c
    FreeRTOS-Kernel/tasks.c
    FreeRTOS-Kernel/timers.c
    FreeRTOS-Kernel/include/atomic.h
    FreeRTOS-Kernel/include/croutine.h
    FreeRTOS-Kernel/include/deprecated_definitions.h
    FreeRTOS-Kernel/include/event_groups.h
    FreeRTOS-Kernel/include/FreeRTOS.h
    FreeRTOS-Kernel/include/list.h
    FreeRTOS-Kernel/include/message_buffer.h
    FreeRTOS-Kernel/include/mpu_prototypes.h
    FreeRTOS-Kernel/include/mpu_wrappers.h
    FreeRTOS-Kernel/include/portable.h
    FreeRTOS-Kernel/include/projdefs.h
    FreeRTOS-Kernel/include/queue.h
    FreeRTOS-Kernel/include/semphr.h
    FreeRTOS-Kernel/include/stack_macros.h
    FreeRTOS-Kernel/include/StackMacros.h
    FreeRTOS-Kernel/include/stream_buffer.h
    FreeRTOS-Kernel/include/task.h
    FreeRTOS-Kernel/include/timers.h
    FreeRTOS-Kernel/portable/GCC/ARM_CM0/port.c
    FreeRTOS-Kernel/portable/GCC/ARM_CM0/portmacro.h
    string.c
    FreeRTOS-Kernel/portable/MemMang/heap_5.c
# ..\Common\include/blocktim.h
# ..\Common\include/countsem.h
# ..\Common\include/IntQueue.h
# ..\Common\include/recmutex.h
# ..\Common\Minimal\blocktim.c
# ..\Common\Minimal\IntQueue.c
# ..\Common\Minimal\recmutex.c
# ..\Common\Minimal\countsem.c
# .\Keil_specific\keil_lib_power.lib
)

# ARM Library
arm_add_library(${PROJECT_NAME}-arm STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME}-arm PRIVATE )
target_include_directories(${PROJECT_NAME}-arm PUBLIC ../../include)
target_include_directories(${PROJECT_NAME}-arm PUBLIC include)
target_include_directories(${PROJECT_NAME}-arm PUBLIC FreeRTOS-Kernel/include)
target_include_directories(${PROJECT_NAME}-arm PUBLIC FreeRTOS-Kernel/portable/GCC/ARM_CM0)

target_include_directories(${PROJECT_NAME}-arm PRIVATE port)


# Disable errors due to linting until all issues are fixed.
target_compile_definitions(${PROJECT_NAME}-arm PRIVATE "-DNO_FLINT_ERRORS")
