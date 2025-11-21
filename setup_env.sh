#!/bin/bash
mkdir workspace
git submodule init
git submodule update --depth 1
cd edk2
git checkout edk2-stable202302 --force
git submodule init
git submodule update
cd ..
set -e
export PACKAGES_PATH=$PWD/edk2:$PWD/edk2-platforms:$PWD
export WORKSPACE=$PWD/workspace
cd $PWD/edk2
. edksetup.sh
make -C BaseTools
cd $PWD