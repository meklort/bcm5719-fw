#!/bin/bash

IPXACT=~/ipxact/build/ipxact
PROJECT=bcm5719

echo "Regenerating Bcm5719 header"

${IPXACT} -p ${PROJECT} bcm5719.xml bcm5719.h

mv bcm5719_NVM.h ../libs/NVRam/
mv bcm5719_MII.h ../libs/MII/include/
mv bcm5719_DEVICE.h ../include/
mv bcm5719_GEN.h ../include/
mv bcm5719_APE.h ../include/
mv bcm5719_RXMBUF.h ../include
mv bcm5719_SDBCACHE.h ../include
mv bcm5719_TXMBUF.h ../include
mv bcm5719_BOOTCODE.h ../include


${IPXACT} -p ${PROJECT} bcm5719.xml bcm5719.cpp
mv *.cpp ../simulator/

${IPXACT} -p ${PROJECT} bcm5719.xml bcm5719.s
${IPXACT} -p ${PROJECT} bcm5719.xml -t asym bcm5719_sym.s
mv *.s ../libs/bcm5719/
