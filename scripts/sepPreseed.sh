#!/bin/bash
preseed() {
    # Block device, aka Disk
    disk=$(cat preseed.conf | grep disk | sed -E 's/^disk=//')
    # Root partition
    root_part=$(cat preseed.conf | grep root_partition | sed -E 's/^root_partition=//')
    # Swap partition
    swap_part=$(cat preseed.conf | grep swap_partition | sed -E 's/^swap_partition=//')
    # EFI partition
    efi_part=$(cat preseed.conf | grep efi_partition | sed -E 's/^efi_partition=//')
    # Locale
    locale=$(cat preseed.conf | grep locale | sed -E 's/^locale=//')
    # Keyboard layout
    layout=$(cat preseed.conf | grep keylayout | sed -E 's/^keylayout=//')
    # Timezone
    zone=$(cat preseed.conf | grep tzone | sed -E 's/^tzone=//')
    # Subzone
    subzone=$(cat preseed.conf | grep subzone | sed -E 's/^subzone=//')
    # Hostname
    hostname=$(cat preseed.conf | grep hostname | sed -E 's/^hostname=//')
    # Username    
    username=$(cat preseed.conf | grep username | sed -E 's/^username=//')
    # Shell    
    shell=$(cat preseed.conf | grep shell | sed -E 's/^shell=//')
    # Desktop environment
    desktop=$(cat preseed.conf | grep desktop | sed -E 's/^desktop=//')
    # Display manager    
    dm=$(cat preseed.conf | grep display_manager | sed -E 's/^display_manager=//')
    # AUR support
    aur_support=$(cat preseed.conf | grep aur_support | sed -E 's/^aur_support=//')
    # Echo start
    echo "$disk" > preseed_values/disk.txt
    echo "$root_part" > preseed_values/root.txt
    echo "$swap_part" > preseed_values/swap.txt
    echo "$efi_part" > preseed_values/efi.txt
    echo "$locale" > preseed_values/locale.txt
    echo "$layout" > preseed_values/keylayout.txt
    echo "$zone" > preseed_values/timezone.txt
    echo "$subzone" > preseed_values/subzone.txt
    echo "$username" > preseed_values/username.txt
    echo "$hostname" > preseed_values/hostname.txt
    echo "$shell" > preseed_values/shell.txt
    echo "$desktop" > preseed_values/desktop.txt
    echo "$dm" > preseed_values/dm.txt
    echo "$aur_support" > preseed_values/aur_support.txt
}
if [ ! -d "./preseed_values" ] 
then
    mkdir preseed_values
fi
preseed