rm -rf testpack
rm -f testpack.tar
mkdir -p testpack/nart
mkdir -p testpack/tcmd
mkdir -p testpack/scripts
cp -rf $WORKAREA/tools/systemtools/testcmd_tlv/Linux/athtestcmd testpack/tcmd/
cp -rf $WORKAREA/tools/systemtools/art2_peregrine/src/art2/.output/* testpack/nart/
cp -f $WORKAREA/support/loadAR9888UTF.sh testpack/scripts/
cp -f $WORKAREA/tools/.bashrc_tools testpack/
cp /usr/local/lib/*.ko testpack
cp $WORKAREA/target/.output/AR9888/hw.$TARGET_VER/bin/utf.bin testpack/utf.bin
cp $WORKAREA/target/.output/AR9888/hw.$TARGET_VER/bin/athwlan.bin testpack/athwlan.bin
cp $WORKAREA/target/.output/AR9888/hw.$TARGET_VER/bin/otp.bin testpack/otp.bin
cp $WORKAREA/../../scripts/fakeBoardData_AR6004_AP.bin testpack/fakeBoardData_AR6004.bin
cp -f $WORKAREA/os/linux/tools/bmiloader/bmiloader testpack/bmiloader
cp $WORKAREA/../../scripts/rc.tools testpack/scripts/rc.tools
cp $WORKAREA/../../scripts/rc.wlan testpack/scripts/rc.wlan
tar -cf testpack.tar testpack
rm -rf testpack
