
project(simulator)

simulator_add_library(${PROJECT_NAME} STATIC
            HAL.cpp
            bcm5719_DEVICE_mmap.cpp
            bcm5719_DEVICE.cpp
            bcm5719_GEN_mmap.cpp
            bcm5719_GEN.cpp
            bcm5719_NVM_mmap.cpp
            bcm5719_NVM.cpp
            # APE Speciifc registers
            bcm5719_APE.cpp
            bcm5719_APE_mmap.cpp
            bcm5719_SHM.cpp
            bcm5719_SHM_mmap.cpp
            )

include_directories(../libs/NVRam)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC ../include)
