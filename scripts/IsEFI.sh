#!/bin/bash
if [[ -d "/sys/firmware/efi/" ]]; then
      SYSTEM="UEFI"
      else
      SYSTEM="BIOS"
fi
echo $SYSTEM > IsEFI.txt