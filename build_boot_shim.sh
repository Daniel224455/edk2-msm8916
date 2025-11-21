#!/bin/bash
cd BootShim
rm -f BootShim.elf BootShim.bin
make UEFI_BASE=0x9FC00000 UEFI_SIZE=0x00300000
cd ..
