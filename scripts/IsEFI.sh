#!/bin/bash
# YaLAI Installer: UEFI support checker script
# Copyright minigyima, 2020
if [[ -d "/sys/firmware/efi/" ]]; then
      SYSTEM="UEFI"
      else
      SYSTEM="BIOS"
fi
echo $SYSTEM > IsEFI.txt