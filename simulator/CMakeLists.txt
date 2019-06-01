
project(simulator)

simulator_add_library(${PROJECT_NAME} STATIC
            HAL.cpp
            bcm5719_DEVICE_sim.cpp
            bcm5719_DEVICE.cpp
            bcm5719_GEN_sim.cpp
            bcm5719_GEN.cpp
            bcm5719_NVM_sim.cpp
            bcm5719_NVM.cpp

            # APE Speciifc registers
            bcm5719_APE.cpp
            bcm5719_APE_sim.cpp
            bcm5719_APE_PERI.cpp
            bcm5719_APE_PERI_sim.cpp
            bcm5719_SHM.cpp
            bcm5719_SHM_sim.cpp
            bcm5719_SHM_CHANNEL0.cpp
            bcm5719_SHM_CHANNEL0_sim.cpp
            bcm5719_SHM_CHANNEL1.cpp
            bcm5719_SHM_CHANNEL1_sim.cpp
            bcm5719_SHM_CHANNEL2.cpp
            bcm5719_SHM_CHANNEL2_sim.cpp
            bcm5719_SHM_CHANNEL3.cpp
            bcm5719_SHM_CHANNEL3_sim.cpp

            # APE indirect registers
            APE_FILTERS.cpp
            APE_FILTERS_sim.cpp
            APE_NVIC.cpp
            APE_NVIC_sim.cpp

            APE_TX_PORT0.cpp
            APE_TX_PORT0_sim.cpp
            APE_TX_PORT1.cpp
            APE_TX_PORT1_sim.cpp
            APE_TX_PORT2.cpp
            APE_TX_PORT2_sim.cpp
            APE_TX_PORT3.cpp
            APE_TX_PORT3_sim.cpp

            APE_RX_PORT0.cpp
            APE_RX_PORT0_sim.cpp
            APE_RX_PORT1.cpp
            APE_RX_PORT1_sim.cpp
            APE_RX_PORT2.cpp
            APE_RX_PORT2_sim.cpp
            APE_RX_PORT3.cpp
            APE_RX_PORT3_sim.cpp

            APE_DEVICE1.cpp
            APE_DEVICE1_sim.cpp
            APE_DEVICE2.cpp
            APE_DEVICE2_sim.cpp
            APE_DEVICE3.cpp
            APE_DEVICE3_sim.cpp

            APE_FILTERS1.cpp
            APE_FILTERS1_sim.cpp
            APE_FILTERS2.cpp
            APE_FILTERS2_sim.cpp
            APE_FILTERS3.cpp
            APE_FILTERS3_sim.cpp
            )

include_directories(../libs/NVRam)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC ../include)
