#!/bin/bash
# YaLAI Installer: Phase 10 - installer script
# Copyright minigyima, 2020
arch_chroot() {
    arch-chroot /mnt /bin/bash -c "${1}"
}
# Varriables from frontend
varSetup() {
    # Block device, aka Disk
    disk="/dev/$(cat .installVars.conf | grep disk | sed -E 's/^disk=//')"
    # Root partition
    root_part="/dev/$(cat .installVars.conf | grep root | sed -E 's/^root=//')"
    # Swap partition
    swap_part="/dev/$(cat .installVars.conf | grep swap | sed -E 's/^swap=//')"
    # EFI partition
    efi_boot="/dev/$(cat .installVars.conf | grep efi | sed -E 's/^efi=//')"
    # Locale
    locale=$(cat .installVars.conf | grep lang | sed -E 's/^lang=//')
    # Keyboard layout
    keylayout=$(cat .installVars.conf | grep key | sed -E 's/^key=//')
    # Timezone
    zone=$(cat .installVars.conf | grep tzone | sed -E 's/^tzone=//')
    # Subzone
    subzone=$(cat .installVars.conf | grep szone | sed -E 's/^szone=//')
    # Hostname
    hostname=$(cat .installVars.conf | grep hname | sed -E 's/^hname=//')
    # Username
    username=$(cat .installVars.conf | grep uname | sed -E 's/^uname=//')
    # Password
    passwd1=$(cat .installVars.conf | grep passwd1 | sed -E 's/^passwd1=//')
    passwd2=$(cat .installVars.conf | grep passwd2 | sed -E 's/^passwd2=//')
    # Root password
    root_password1=$(cat .installVars.conf | grep rtpass1 | sed -E 's/^rtpass1=//')
    root_password2=$(cat .installVars.conf | grep rtpass2 | sed -E 's/^rtpass2=//')
    # Shell
    shell=$(cat .installVars.conf | grep shell | sed -E 's/^shell=//' | awk '{print tolower($0)}')
    # Desktop environment
    desktop=$(cat .installVars.conf | grep de | sed -E 's/^de=//' | awk '{print tolower($0)}')
    # Display manager
    dm=$(cat .installVars.conf | grep dm | sed -E 's/^dm=//' | awk '{print tolower($0)}')
    # Aur support
    aur_support=$(cat .installVars.conf | grep asup | sed -E 's/^asup=//' | awk '{print tolower($0)}')
    # System type (UEFI, BIOS)
    SYSTEM=$(cat IsEFI.txt)
    # Deleting temporary varriable file...
    rm .installVars.conf
}
drivemount() {
    case $SYSTEM in
            'UEFI')
                # Mounting volumes (UEFI)
                echo "# Mounting partitions..." > progress.txt
                mount $root_part /mnt
                mkswap $swap_part
                swapon $swap_part
                mkdir /mnt/boot
                mkdir /mnt/boot/efi
                mount $efi_boot /mnt/boot/efi
                ;;
            
            'BIOS')
                # Mounting volumes (BIOS)
                echo "# Mounting partitions..." > progress.txt
                mount $root_part /mnt
                mkswap $swap_part
                swapon $swap_part
                ;;
                esac
}
baseInstall() {
    # Applying mirrorlist
    cp mirrorlist /etc/pacman.d/mirrorlist
    # Updating mirrors
    pacman -Syy
    pacman -S archlinux-keyring
    # Base, base-devel
    echo "# Installing base system via pacstrap..." > progress.txt
    pacstrap -i /mnt base base-devel bash --noconfirm
    # Old base dependencies
    echo "# Installing kernel and other utils..." > progress.txt
    arch_chroot "pacman -S --noconfirm --asdeps archlinux-keyring"
    arch_chroot "pacman-key --populate archlinux"
    arch_chroot "pacman -S --asdeps --noconfirm bash bzip2 coreutils cryptsetup device-mapper dhcpcd diffutils e2fsprogs file filesystem findutils gawk gcc-libs gettext glibc grep gzip inetutils iproute2 iputils jfsutils less licenses linux linux-firmware logrotate lvm2 man-db man-pages mdadm nano netctl pacman pciutils perl procps-ng psmisc reiserfsprogs s-nail sed shadow sysfsutils systemd-sysvcompat tar texinfo usbutils util-linux vi vim which xfsprogs"
}
sysConf() {
    # Genfstab
    echo "# Generating fstab via genfstab..." > progress.txt
    genfstab -U /mnt >> /mnt/etc/fstab
    # /etc/hosts
    echo "# Configuring hosts file..." > progress.txt
    arch_chroot "echo "$hostname" >> /etc/hostname"
    arch_chroot "echo "127.0.0.1		localhost" >> /etc/hosts"
    arch_chroot "echo "::1			localhost" >> /etc/hosts"
    # mkinitcpio
    echo "# Preparing kernel..." > progress.txt
    arch_chroot "mkinitcpio -p linux"
}
user() {
    echo "# Making new user..." > progress.txt
    arch_chroot "useradd -m -g users -G adm,lp,wheel,power,audio,video,uucp,lock -s /bin/bash $username"
    touch .passwd
    echo -e "$passwd1\n$passwd2" > .passwd
    arch_chroot "passwd $username" < .passwd >/dev/null
    rm .passwd
}
root_password() {
    echo "# Setting root password..." > progress.txt
    touch .passwd
    echo -e "$root_password1\n$root_password2" > .passwd
    arch_chroot "passwd root" < .passwd >/dev/null
    rm .passwd
}
localization() {
    # Locale
    echo "# Setting locale..."
    echo "LANG=\"${locale}\"" > /mnt/etc/locale.conf
    echo "${locale} UTF-8" > /mnt/etc/locale.gen
    echo "# Generating Locale..." > progress.txt
    arch_chroot "locale-gen"
    export LANG=${locale}
    # Keyboard layout
    echo "# Setting keyboard layout for console..." > progress.txt
    echo KEYMAP=$layout >> /mnt/etc/vconsole.conf
    # Timezone
    echo "# Setting timezone..." > progress.txt
    arch_chroot "rm /etc/localtime"
    arch_chroot "ln -s /usr/share/zoneinfo/${zone}/${subzone} /etc/localtime"
    # Hardware clock
    echo "# Setting up hardware clock..." > progress.txt
    arch_chroot "hwclock --systohc"
}
shell() {
    case $shell in
        'zsh')
           echo "# Setting up Zsh..." > progress.txt
		   sleep 1
		   arch_chroot "pacman -S --noconfirm zsh zsh-syntax-highlighting zsh-completions grml-zsh-config;chsh -s /usr/bin/zsh $username"
		   ;;
			

        'bash') 
			echo "# Setting up Bash..." > progress.txt
			sleep 1
			arch_chroot "pacman -S --noconfirm bash;chsh -s /bin/bash $username"
            ;;
		
		
		'fish') 
			echo "# Setting up Fish..." > progress.txt
			sleep 1
			arch_chroot "pacman -S --noconfirm fish;chsh -s /usr/bin/fish $username"
            ;;
			esac
}
xorg_pulse() {
    echo "# Installing Xorg and Pulseaudio..." > progress.txt
    pacstrap /mnt xorg xorg-xinit xorg-drivers pulseaudio pulseaudio-alsa pulseaudio-bluetooth
}
display_manager() {
    case $dm in
        'lightdm')
           echo "# Setting up LightDM..." > progress.txt
		   sleep 1
		   arch_chroot "pacman -S lightdm lightdm-gtk-greeter lightdm-gtk-greeter-settings --noconfirm"
		   arch_chroot "systemctl enable lightdm"
			;;
			

        'sddm') 
			echo "# Setting up SDDM..." > progress.txt
			sleep 1
			arch_chroot "pacman -S sddm sddm-kcm --noconfirm"
			arch_chroot "systemctl enable sddm"
            ;;
			
		'gdm') 
			echo "# Setting up GDM..." > progress.txt
			sleep 1
			arch_chroot "pacman -S gdm --noconfirm"
			arch_chroot "systemctl enable gdm"
            ;;
        
        'lxdm') 
			echo "# Setting up lxdm..." > progress.txt
			sleep 1
			arch_chroot "pacman -S lxdm --noconfirm"
			arch_chroot "systemctl enable lxdm"
            ;;
			esac
}
desktop() {
    case $desktop in
        'mate')
           echo "# Installing Mate..." > progress.txt
		   sleep 1
		   arch_chroot "pacman -S mate mate-extra mate-media --noconfirm"
		   ;;
			

        'kde_plasma') 
			echo "# Installing KDE Plasma..." > progress.txt
			sleep 1
			arch_chroot "pacman -S plasma dolphin konsole ark --noconfirm"
            ;;
		
		
		'gnome') 
			echo "# Installing Gnome..." > progress.txt
			sleep 1
			arch_chroot "pacman -S gnome --noconfirm"
            ;;

        'cinnamon') 
			echo "# Installing Cinnamon..." > progress.txt
			sleep 1
			arch_chroot "pacman -S cinnamon xed --noconfirm"
            ;;
        
        'budgie') 
			echo "# Installing Budgie..." > progress.txt
			sleep 1
			arch_chroot "pacman -S budgie-desktop nautilus budgie-extras --noconfirm"
            ;;

        'xfce') 
			echo "# Installing Xfce..." > progress.txt
			sleep 1
			arch_chroot "pacman -S xfce4 xfce4-goodies --noconfirm"
            ;;

        'lxde') 
			echo "# Installing Lxde..." > progress.txt
			sleep 1
			arch_chroot "pacman -S lxde --noconfirm"
            ;;
			esac
}
apps() {
    # Misc. configuration
    echo "# Configuring Sudo for automation..." > progress.txt
    arch_chroot "sed -i 's/^%wheel ALL=(ALL) ALL/# %wheel ALL=(ALL) ALL/' /etc/sudoers"
    arch_chroot "sed -i 's/^# %wheel ALL=(ALL) NOPASSWD: ALL/%wheel ALL=(ALL) NOPASSWD: ALL/' /etc/sudoers"
    echo "# Installing applications..." > progress.txt
    # Base programs
    arch_chroot "pacman -S --asdeps $(cat appreseed.conf | grep base | sed -E 's/^base=//') --noconfirm"
    # Apps from appreseed.conf
    arch_chroot "pacman -S $(cat appreseed.conf | grep pkgs | sed -E 's/^pkgs=//') --noconfirm"
    # Post-install (Postinst in appreseed.conf)
    arch_chroot "$(cat appreseed.conf | grep postinst | sed -E 's/^postinst=//')"
}
aurInstall() {
    if [ $aur_support == "true" ]
    then
        # AUR stuff (aka the Yay installer)
        echo "# Installing yay for AUR support..." > progress.txt
        arch_chroot "pacman -S git --noconfirm"
        arch_chroot "mkdir /yalai"
        arch_chroot "chmod 777 /yalai"
        arch_chroot "su -c 'cd /yalai && git clone https://aur.archlinux.org/yay.git' $username"
        arch_chroot "su -c 'cd /yalai/yay && makepkg -si --noconfirm' $username"
        # AUR package installer
        echo "# Installing AUR packages from AppPreseed..." > progress.txt
        arch_chroot "su -c 'yay -S --noconfirm $(cat appreseed.conf | grep aur | sed -E 's/^aur=//')' $username"
    else
        echo "# Skipping AUR installation..." > progress.txt
    fi
}
bootloader() {
     # GRUB 2 installer
    case $SYSTEM in
        'UEFI')
            # Installing packages           
			echo "# Installing GRUB for UEFI..." > progress.txt
            arch_chroot "pacman -S grub efibootmgr --noconfirm"
            # Mounting boot partition (if UEFI)
            arch_chroot "mkdir /boot/efi"
            arch_chroot "mount $efi_boot /boot/efi"
            # Installing grub
			arch_chroot "grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=GRUB"
			arch_chroot "grub-mkconfig -o /boot/grub/grub.cfg"
			;;
			

        'BIOS') 
			echo "# Installing GRUB for BIOS..." > progress.txt
            arch_chroot "pacman -S grub --noconfirm"
			arch_chroot "grub-install --target=i386-pc $disk"
			arch_chroot "grub-mkconfig -o /boot/grub/grub.cfg"
            ;;
			esac
}
cleanup() {
    # Normal sudo config
    echo "Configuring sudo for everyday use..." > progress.txt
    arch_chroot "sed -i 's/^%wheel ALL=(ALL) NOPASSWD: ALL/# %wheel ALL=(ALL) NOPASSWD: ALL/' /etc/sudoers"
    arch_chroot "sed -i 's/^# %wheel ALL=(ALL) ALL/%wheel ALL=(ALL) ALL/' /etc/sudoers"
    # Delete /mnt/yalai (yay build files)
    echo "# Deleting temporary files..." > progress.txt
    rm -rf /mnt/yalai
}
# Execution begins...
varSetup
drivemount
baseInstall
sysConf
user
root_password
localization
shell
xorg_pulse
display_manager
desktop
apps
aurInstall
bootloader
cleanup
echo "# Install finished! " > progress.txt
