#!/bin/bash
# based on the instructions from edk2-platforms
rm -rf boot-enchilada.img
set -e
export PACKAGES_PATH=$PWD/edk2:$PWD/edk2-platforms:$PWD
export WORKSPACE=$PWD/workspace
. edk2/edksetup.sh

# build bootshim
./build_boot_shim.sh

# not actually GCC5; it's GCC7 on Ubuntu 18.04.
# anyways, start the build
GCC5_AARCH64_PREFIX=aarch64-linux-gnu- build -s -n 0 -a AARCH64 -t GCC5 -p Sdm845Pkg/Devices/enchilada.dsc

# post-build packing
cat ./BootShim/BootShim.bin "workspace/Build/Sdm845Pkg/DEBUG_GCC5/FV/SDM845PKG_UEFI.fd" > "workspace/Build/Sdm845Pkg/DEBUG_GCC5/FV/SDM845PKG_UEFI.fd-bootshim"||exit 1
gzip -c < "workspace/Build/Sdm845Pkg/DEBUG_GCC5/FV/SDM845PKG_UEFI.fd-bootshim" > "workspace/Build/Sdm845Pkg/DEBUG_GCC5/FV/SDM845PKG_UEFI.fd-bootshim.gz"||exit 1
cat "workspace/Build/Sdm845Pkg/DEBUG_GCC5/FV/SDM845PKG_UEFI.fd-bootshim.gz" ./ImageResources/enchilada.dtb > ./ImageResources/bootpayload.bin||exit 1

# create bootable android boot.img
python3 ./ImageResources/mkbootimg.py \
  --kernel ./ImageResources/bootpayload.bin \
  --ramdisk ./ImageResources/ramdisk \
  --kernel_offset 0x00000000 \
  --ramdisk_offset 0x00000000 \
  --tags_offset 0x00000000 \
  --os_version 13.0.0 \
  --os_patch_level "2025-05" \
  --header_version 1 \
  -o boot-enchilada.img \
  ||_error "\nFailed to create Android Boot Image!\n"