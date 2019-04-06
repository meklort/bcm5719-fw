#!/bin/bash

IPXACT=~/ipxact/build/ipxact
PROJECT=bcm5719

echo "Regenerating Bcm5719 header"

${IPXACT} -p ${PROJECT} SHM.xml DEVICE.xml NVM.xml bcm5719.xml bcm5719_full.xml

${IPXACT} -p ${PROJECT} bcm5719_full.xml bcm5719.h

mv bcm5719_NVM.h ../libs/NVRam/
mv bcm5719_MII.h ../libs/MII/include/
mv bcm5719_DEVICE.h ../include/
mv bcm5719_GEN.h ../include/
mv bcm5719_APE.h ../include/
mv bcm5719_SHM.h ../include/
mv bcm5719_RXMBUF.h ../include
mv bcm5719_SDBCACHE.h ../include
mv bcm5719_TXMBUF.h ../include
mv bcm5719_BOOTCODE.h ../include


${IPXACT} -p ${PROJECT} bcm5719_full.xml bcm5719.cpp
mv *.cpp ../simulator/

# ${IPXACT} -p ${PROJECT} bcm5719_full.xml bcm5719.s
${IPXACT} -p ${PROJECT} bcm5719_full.xml -t asym bcm5719_sym.s
mv *.s ../libs/bcm5719/


PROJECT=ape

echo "Regenerating APE header"


${IPXACT} -p ${PROJECT} FILTERS.xml SHM.xml NVIC.xml DEVICE.xml NVM.xml APE.xml APE_full.xml

${IPXACT} -p ${PROJECT} APE_full.xml APE.h
mv APE_NVIC.h ../include/

# ${IPXACT} -p ${PROJECT} NVIC.xml APE_full.xml APE.s
${IPXACT} -p ${PROJECT} APE_full.xml -t asym APE_sym.s
mv *.s ../libs/bcm5719/
mv APE_SHM*.h ../include
mv APE_FILTERS*.h ../include

${IPXACT} -p ${PROJECT} APE_full.xml -t ape_cpp APE.cpp
mv *.cpp ../simulator/
