#!/bin/bash
# based on the instructions from edk2-platforms
rm -rf boot-enchilada.img
set -e
export PACKAGES_PATH=$PWD/edk2:$PWD/edk2-platforms:$PWD
export WORKSPACE=$PWD/workspace
. edk2/edksetup.sh

# not actually GCC5; it's GCC7 on Ubuntu 18.04.
# anyways, start the build
GCC5_AARCH64_PREFIX=aarch64-linux-gnu- build -s -n 0 -a AARCH64 -t GCC5 -b RELEASE -p Msm8916Pkg/Devices/j5nlte.dsc

# post-build packing
gzip -c < "workspace/Build/Msm8916Pkg/RELEASE_GCC5/FV/MSM8916PKG_UEFI.fd" > "boot-j5nlte.img"||exit 1
cat ImageResources/j5nlte.dtb >>boot-j5nlte.img||exit 1