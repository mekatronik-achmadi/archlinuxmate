# RaspberryPi Basic Installation

## Disk Install

### prepare disk

```sh
sudo fdisk -l
export DEVDISK='/dev/sdb'

sudo parted ${DEVDISK} mklabel msdos
```

```sh
yes | sudo parted ${DEVDISK} mkpart primary 0% 200
yes | sudo parted ${DEVDISK} mkpart primary 200 100%

yes | sudo mkfs.vfat -F 32 ${DEVDISK}1
yes | sudo mkfs.ext4 ${DEVDISK}2

yes | sudo parted ${DEVDISK} set 1 boot on
yes | sudo parted ${DEVDISK} set 1 lba on
```

### download image

```sh
wget -c http://os.archlinuxarm.org/os/ArchLinuxARM-rpi-armv7-latest.tar.gz
```

### deploy image

```sh
sudo fdisk -l
export DEVDISK='/dev/sdb'

sudo mkdir -p /mnt/mmc/{boot,root}
sudo mount ${DEVDISK}1 /mnt/mmc/boot
sudo mount ${DEVDISK}2 /mnt/mmc/root

mkdir -p armv7h/
cd armv7h/

sudo bsdtar -xpf ../ArchLinuxARM-rpi-armv7-latest.tar.gz -C /mnt/mmc/root
sudo sync

sudo mv -vf /mnt/mmc/root/boot/* /mnt/mmc/boot/
sudo sync

sudo umount /mnt/mmc/root /mnt/mmc/boot
```

--------------------------------------------------------------------------------

## Qemu run

### mount disk (host-pc)

```sh
sudo fdisk -l
export DEVDISK='/dev/sdb'

sudo mount ${DEVDISK}2 /mnt/mmc/root
sudo mount ${DEVDISK}1 /mnt/mmc/root/boot
```

### copy qemu-arm-static (host-pc)

```sh
sudo cp -vf /usr/bin/qemu-arm-static /mnt/mmc/root/usr/bin/
```

### test chroot into mounted sdcard (host-pc)

```sh
sudo arch-chroot /mnt/mmc/root /bin/bash

echo "LANG=en_US.UTF-8" > /etc/locale.conf
echo "en_US ISO-8859-1" >> /etc/locale.gen
echo "en_US.UTF-8 UTF-8" >> /etc/locale.gen
locale-gen

pacman -V

exit
```

--------------------------------------------------------------------------------

## Install packages

### chroot into mounted sdcard (host-pc)

```sh
sudo arch-chroot /mnt/mmc/root /bin/bash
```

### initialize pacman keyring (qemu-chroot)

```sh
# need internet connection and proper time setting
pacman-key --init
#pacman-key --refresh-keys # if failed
pacman-key --populate archlinuxarm
```

### download database (host-pc)

```sh
mkdir -p databases/;cd databases/
echo "
http://mirror.archlinuxarm.org/armv7h/core/core.db
http://mirror.archlinuxarm.org/armv7h/extra/extra.db
http://mirror.archlinuxarm.org/armv7h/community/community.db
http://mirror.archlinuxarm.org/armv7h/alarm/alarm.db
http://mirror.archlinuxarm.org/armv7h/aur/aur.db
" > ../dbase.txt
wget -c -i ../dbase.txt
cd ../

sudo rsync -avh databases/ /mnt/mmc/root/var/lib/pacman/sync/
```

### generate upgrade packages urls (qemu-chroot)

```sh
pacman -Sup > /home/alarm/upgrade_pkgs.txt
```

### download upgrade packages (host-pc)

```sh
cp -vf /mnt/mmc/root/home/alarm/upgrade_pkgs.txt ./
mkdir -p packages/official/;cd packages/official/
wget -c -i ../../upgrade_pkgs.txt
cd ../../

sudo rsync -avh packages/official/ /mnt/mmc/root/var/cache/pacman/pkg/
```

### upgrade packages (qemu-chroot)

```sh
sed -i "s#= Required DatabaseOptional#= Never#g" /etc/pacman.conf
sed -i "s#= Optional TrustAll#= Never#g" /etc/pacman.conf
sed -i "s#= Optional#= Never#g" /etc/pacman.conf

pacman -Su --noconfirm
```

### copy install packages list (host-pc)

```sh
cp -vf ../archmate/pkg_basic.txt /mnt/mmc/root/home/alarm/basiclist.txt
cp -vf ../archmate/pkg_server.txt /mnt/mmc/root/home/alarm/serverlist.txt
cp -vf ../archmate/pkg_mate.txt /mnt/mmc/root/home/alarm/matelist.txt
```

### generate basic packages urls (qemu-chroot)

```sh
pacman -Sp $(cat /home/alarm/basiclist.txt) > /home/alarm/basic_pkgs.txt
```

### download basic packages (host-pc)

```sh
cp -vf /mnt/mmc/root/home/alarm/basic_pkgs.txt ./
mkdir -p packages/official/;cd packages/official/
wget -c -i ../../basic_pkgs.txt
cd ../../

sudo rsync -avh packages/official/ /mnt/mmc/root/var/cache/pacman/pkg/
```

### install basic packages (qemu-chroot)

```sh
sed -i "s#= Required DatabaseOptional#= Never#g" /etc/pacman.conf
sed -i "s#= Optional TrustAll#= Never#g" /etc/pacman.conf
sed -i "s#= Optional#= Never#g" /etc/pacman.conf

pacman -S --noconfirm $(cat /home/alarm/basiclist.txt)
```

### generate server/mate packages urls (qemu-chroot)

```sh
pacman -Sp $(cat /home/alarm/serverlist.txt) > /home/alarm/server_pkgs.txt
pacman -Sp $(cat /home/alarm/matelist.txt) > /home/alarm/mate_pkgs.txt
```

### download server/mate packages (host-pc)

```sh
cp -vf /mnt/mmc/root/home/alarm/server_pkgs.txt ./
cp -vf /mnt/mmc/root/home/alarm/mate_pkgs.txt ./
mkdir -p packages/official/;cd packages/official/
wget -c -i ../../server_pkgs.txt
wget -c -i ../../mate_pkgs.txt
cd ../../

sudo rsync -avh packages/official/ /mnt/mmc/root/var/cache/pacman/pkg/
```

### install server/mate packages (qemu-chroot)

```sh
sed -i "s#= Required DatabaseOptional#= Never#g" /etc/pacman.conf
sed -i "s#= Optional TrustAll#= Never#g" /etc/pacman.conf
sed -i "s#= Optional#= Never#g" /etc/pacman.conf

pacman -S --noconfirm $(cat /home/alarm/serverlist.txt) $(cat /home/alarm/matelist.txt)
```

### copy some mate desktop defaults (host-pc)

```sh
sudo cp -vf ../archmate/archmate-rpi.gschema.override /mnt/mmc/root/usr/share/glib-2.0/schemas/
sudo cp -vf ../archmate/archlinux.layout /mnt/mmc/root/usr/share/mate-panel/layouts/fedora.layout
```

--------------------------------------------------------------------------------

## Global Configuration

### basic config.txt (qemu-chroot)

```sh
echo "gpu_mem=128
dtparam=audio=on
camera_auto_detect=1
display_auto_detect=1

dtoverlay=vc4-kms-v3d
max_framebuffers=2
disable_overscan=1

[cm4]
otg_mode=1

[pi4]
arm_boost=1

[all]

" > /boot/config.txt
```

### set hostname (qemu-chroot)

```sh
echo "alarmrpi" > /etc/hostname
```

### silent cli (qemu-chroot)

```sh
echo '
boot_delay=0
disable_splash=1' >> /boot/config.txt

sed -i '$s/$/ audit=0 quiet loglevel=0/' /boot/cmdline.txt
echo 'kernel.printk = 3 3 3 3' > /etc/sysctl.d/20-quiet-printk.conf

# if not using bluetooth
echo 'dtoverlay=disable-bt' >> /boot/config.txt
```

### generate locale (qemu-chroot)

```sh
echo "LANG=en_US.UTF-8" > /etc/locale.conf
echo "en_US ISO-8859-1" >> /etc/locale.gen
echo "en_US.UTF-8 UTF-8" >> /etc/locale.gen
locale-gen
```

### sudoers no password (qemu-chroot)

```sh
echo "%wheel ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
```

### disable passwords (qemu-chroot)

```sh
passwd -d root
passwd -d alarm
```

### console font (qemu-chroot)

```sh
echo "FONT=ter-112n
FONT_MAP=8859-2
" > /etc/vconsole.conf
```

### enable timesync (qemu-chroot)

```sh
systemctl enable systemd-timesyncd
```

### enable network manager (qemu-chroot)

```sh
systemctl disable dhcpd4
systemctl disable wpa_supplicant
systemctl disable systemd-networkd
systemctl disable systemd-resolved

ln -svf /run/NetworkManager/resolv.conf /etc/resolv.conf
systemctl enable NetworkManager
```

### enable fake hwclock (qemu-chroot)

```sh
systemctl enable fake-hwclock fake-hwclock-save.timer
```

### enable ssh server (qemu-chroot)

```sh
mkdir -p /etc/ssh
echo "
PermitRootLogin yes
AuthorizedKeysFile .ssh/authorized_keys
PermitEmptyPasswords yes
ChallengeResponseAuthentication no
UsePAM yes
PrintMotd no
Subsystem sftp /usr/lib/ssh/sftp-server
X11Forwarding yes
X11UseLocalhost yes
X11DisplayOffset 10
AllowTcpForwarding yes
" > /etc/ssh/sshd_config

systemctl enable sshd.service
```

### nano settings (qemu-chroot)

```sh
echo '
set autoindent
set nowrap
set linenumbers
set mouse
set noconvert
set smooth
set constantshow
unset backup

include "/usr/share/nano/*.nanorc"
include "/usr/share/nano-syntax-highlighting/*.nanorc"
' > /etc/nanorc
```

### shell autologin (qemu-chroot)

```sh
mkdir -p /etc/systemd/system/getty@tty1.service.d/

echo "[Service]
ExecStart=
ExecStart=-/sbin/agetty --autologin alarm --noissue --noclear %I 38400 linux
" > /etc/systemd/system/getty@tty1.service.d/autologin.conf

echo "[Service]
TTYVTDisallocate=no
" > /etc/systemd/system/getty@tty1.service.d/noclear.conf
```

## Xorg Configuration

### fbdev config file (qemu-chroot)

```sh
echo 'Section "Device"
    Identifier    "FBDEV"
    Driver        "fbdev"
    Option        "fbdev" "/dev/fb0"
    Option        "SwapbufferWait" "true"
EndSection' > /etc/X11/xorg.conf.d/99-fbdev.conf
```

### xorg no blank (qemu-chroot)

```sh
echo 'Section "ServerFlags"
    Option "StandbyTime" "0"
    Option "SuspendTime" "0"
    Option "OffTime" "0"
    Option "BlankTime" "0"
EndSection' >  /etc/X11/xorg.conf.d/noblank.conf
```

### configure gitk (qemu-chroot)

```
mkdir -p /home/alarm/.config/git/
echo 'set mainfont {{Liberation Sans} 8}
set textfont {{LiterationMono Nerd Font} 8}
set uifont {{Liberation Sans} 8 bold}' > /home/alarm/.config/git/gitk
chown -Rvf alarm:alarm /home/alarm/.config/
```

### configure xterm (qemu-chroot)

```sh
echo "XTerm*faceName: LiterationMono Nerd Font Mono
XTerm*faceSize: 8
XTerm*background: white
XTerm*foreground: black
XTerm*selectToClipboard: true
XTerm*eightBitInput: false
XTerm*eightBitOutput: true
XClock.Clock.face: Liberation Sans:size=9
Xft.autohint: 0
Xft.antialias: 1
Xft.hinting: true
Xft.hintstyle: hintslight
Xft.dpi: 96
Xft.rgba: rgb
Xft.lcdfilter: lcddefault" | tee /home/alarm/.Xdefaults
chown -vf alarm:alarm /home/alarm/.Xdefaults
```

### configure gtk theme (qemu-chroot)

```sh
mkdir -p /etc/gtk-2.0/
echo '
gtk-icon-theme-name = "menta"
gtk-theme-name = "Menta"
gtk-font-name = "Liberation Sans 8"
' | tee /etc/gtk-2.0/gtkrc

mkdir -p /etc/gtk-3.0/
echo '
[Settings]
gtk-icon-theme-name = menta
gtk-theme-name = Menta
gtk-font-name = Liberation Sans 8
gtk-application-prefer-dark-theme = false
' | tee /etc/gtk-3.0/settings.ini
```

### some profiles (qemu-chroot)

```sh
mkdir -p /etc/profile.d/
echo '
export PATH=$PATH:~/.local/bin
export BROWSER=w3m
export QT_QPA_PLATFORMTHEME=qt5ct
export VISUAL=vim
export EDITOR=vim
export PAGER=most
export VIEWER=most
export FREETYPE_PROPERTIES="truetype:interpreter-version=40"
export FT2_SUBPIXEL_HINTING=2
' | tee /etc/profile.d/archmate-profile.sh
```

### vim modify (qemu-chroot)

```sh
mkdir -p /etc/
echo '" /usr/share/vim/vimfiles/archlinux.vim' > /etc/vimrc
echo 'runtime! archlinux.vim
autocmd BufWritePre * %s/\s\+$//e
filetype plugin on
filetype indent on
filetype plugin indent on
set expandtab ts=4 sw=4 ai
set conceallevel=0
set encoding=utf-8
set termguicolors
set ic is hls
set number
set wrap!
set mouse=a
let g:tagbar_width=30
let g:NERDTreeWinSize=30
syntax on' >> /etc/vimrc
```

### user group access (qemu-chroot)

```sh
groupadd -fr video
groupadd -fr lock
groupadd -fr uucp
groupadd -fr tty

gpasswd -a alarm video
gpasswd -a alarm lock
gpasswd -a alarm uucp
gpasswd -a alarm tty
```

### configure bash (qemu-chroot)

```sh
echo "
alias sudo='sudo -E'

alias bat='bat --theme=GitHub'
PS1='\[\033[01m\][\u@\h \W]\$ \[\033[00m\]'
" | tee -a /home/alarm/.bashrc
chown -vf alarm:alarm /home/alarm/.bashrc

echo '
[[ -f ~/.bashrc ]] && . ~/.bashrc
source ~/.bashrc

if [ -n "$SSH_CLIENT" ] || [ -n "$SSH_TTY" ]; then
    echo "SSH Login Success"
else
    if [ -z "${DISPLAY}" ] && [ "${XDG_VTNR}" -eq 1 ]; then
        # for cli or tigervnc
        true

        # for actual display
        #exec startx
    fi
fi' | tee /home/alarm/.bash_profile
chown -vf alarm:alarm /home/alarm/.bash_profile
```

### configure startx (qemu-chroot)

```sh
echo "exec mate-session" | tee /home/alarm/.xinitrc
chown -vf alarm:alarm /home/alarm/.xinitrc
```

### rebuild gschema (qemu-chroot)

```sh
glib-compile-schemas /usr/share/glib-2.0/schemas/
```

### clean unused themes

```sh
rm -rf /usr/share/themes/Clearlooks
rm -rf /usr/share/themes/Crux
rm -rf /usr/share/themes/Industrial
rm -rf /usr/share/themes/Mist
rm -rf /usr/share/themes/Raleigh
rm -rf /usr/share/themes/Redmond
rm -rf /usr/share/themes/ThinIce

rm -rf /usr/share/themes/Blue-Submarine
rm -rf /usr/share/themes/Green-Submarine
rm -rf /usr/share/themes/BlueLaguna
rm -rf /usr/share/themes/GreenLaguna
rm -rf /usr/share/themes/TraditionalOkTest

rm -rf /usr/share/themes/HighContrast
rm -rf /usr/share/themes/HighContrastInverse
rm -rf /usr/share/themes/ContrastHigh
rm -rf /usr/share/themes/ContrastHighInverse

rm -rf /usr/share/themes/Spidey*
rm -rf /usr/share/themes/Splint*
rm -rf /usr/share/themes/Dopple*
rm -rf /usr/share/themes/ClearlooksRe
rm -rf /usr/share/themes/DustBlue
rm -rf /usr/share/themes/Shiny
rm -rf /usr/share/themes/WinMe
rm -rf /usr/share/themes/eOS
rm -rf /usr/share/themes/Atlanta
rm -rf /usr/share/themes/Gorilla
rm -rf /usr/share/themes/Motif
rm -rf /usr/share/themes/Esco

rm -rf /usr/share/themes/TraditionalGreen
rm -rf /usr/share/themes/TraditionalOk
rm -rf /usr/share/themes/YaruGreen
rm -rf /usr/share/themes/YaruOk

rm -rf /usr/share/themes/*-border
```

--------------------------------------------------------------------------------

## Finish

### clean-up package cache (qemu-chroot)

```sh
rm -vf /home/alarm/{upgrade_pkgs.txt}
rm -vf /home/alarm/{basic_pkgs.txt,basiclist.txt}
rm -vf /home/alarm/{server_pkgs.txt,serverlist.txt}
rm -vf /home/alarm/{mate_pkgs.txt,matelist.txt}
rm -vf /var/cache/pacman/pkg/*
```

### exit from mounted sdcard chroot (qemu-chroot)

```sh
exit
```

### umount disk (host-pc)

```sh
sudo umount /mnt/mmc/root/boot/
sudo umount /mnt/mmc/root/
```

### clear url list files (host-pc)

```sh
 rm -vf dbase.txt upgrade_pkgs.txt basic_pkgs.txt server_pkgs.txt mate_pkgs.txt
```