#!/bin/bash

IPXACT=~/ipxact/build/ipxact

echo "Regenerating Bcm5719 header"

${IPXACT} bcm5719.xml bcm5719.h

mv bcm5719_NVM.h ../libs/NVRam/
mv bcm5719_MII.h ../libs/MII/include/
mv bcm5719_DEVICE.h ../include/
mv bcm5719_GEN.h ../include/
mv bcm5719_APE.h ../include/

${IPXACT} bcm5719.xml bcm5719.cpp
mv *.cpp ../simulator/
