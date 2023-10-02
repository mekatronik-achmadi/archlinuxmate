# ArchISO Packages

## Official

### install basic system
linux base base-devel
linux-headers linux-firmware
multilib-devel terminus-font

### install basic tools
bash-completion mkinitcpio
squashfs-tools rsync zsync
dkms arch-install-scripts
neofetch lsb-release dtc
nano dialog bc tmux tree
nano-syntax-highlighting
curl wget openssh sshfs
pacman-contrib mlocate
virtualbox-guest-utils
intel-ucode amd-ucode
mkinitcpio-archiso
cdrtools syslinux
libxcrypt-compat
pv archinstall

### install posix meta
posix posix-software-development
posix-xsi posix-c-development

### install cli tools
mc highlight
python lua perl
hexedit most bat
moc fdupes w3m lynx

### install vim editor
vim vim-nerdtree vim-surround
vim-nerdcommenter vim-gitgutter
vim-airline vim-tagbar vim-tabular

### install xorg server
xorg xorg-apps xorg-drivers
xorg-xinit xorg-fonts
xsel xclip xterm
xorg-fonts-misc

### install login manager
lightdm lightdm-gtk-greeter
lightdm-gtk-greeter-settings

### install mate desktop
mate-common gnome-common
libappindicator-gtk3
mate mate-extra

### install themes and icons
gnome-icon-theme-extras gnome-themes-extra
gtk-update-icon-cache icon-naming-utils
arc-solid-gtk-theme papirus-icon-theme
libcanberra sound-theme-freedesktop
gtk-engines gtk-engine-murrine

### install gtk 2/3 libraries
gtk3 wxgtk3 glade
gtk2 gtkmm gtkmm3
python-wxpython
python-gobject

### install desktop basic
ttf-liberation-mono-nerd
ttf-liberation onboard
dconf-editor trash-cli
xdg-desktop-portal-gtk
redshift python-xdg
archlinux-wallpaper
xdg-desktop-portal
xdg-user-dirs-gtk
tk ttf-dejavu
gnome-keyring

### install desktop tools
geany geany-plugins
qt5-base qt6-base
qt5ct qt6ct scrot
parcellite meld
zenity xdotool
shotwell xchm

### install networking system
networkmanager nm-connection-editor
network-manager-applet modemmanager
mobile-broadband-provider-info iftop
bind-tools netctl ppp wpa_supplicant
net-tools wavemon bmon nethogs gping
crda iw iwd wireless_tools tigervnc
bridge-utils ethtool usb_modeswitch
nmap openresolv dhclient dhcpcd mtr
tcpdump fping gnu-netcat inetutils
traceroute dhcp dnsmasq nss-mdns

### install android driver
android-file-transfer scrcpy
android-udev python-pyudev

### install audio system
pulseaudio portaudio
jack2 pulseaudio-jack
alsa-utils alsa-firmware
alsa-ucm-conf sof-firmware
alsa-oss alsa-lib alsa-plugins
pulseaudio-equalizer pavucontrol
pulseaudio-alsa pulseaudio-bluetooth

### install gio filesystem
gvfs gvfs-mtp gvfs-google
gvfs-gphoto2 gvfs-afc
gvfs-smb gvfs-nfs

### install compression tools
xz bzip2 gzip lz4 p7zip arj atool
lrzip lzip lzop zip unzip zstd cpio
tar libarchive unrar lhasa rpmextract

### install build tools
git tig github-cli
bear hub subversion
autoconf meson ninja
vala autogen automake
cblas openblas lapack
pkgconf gendesk help2man
mercurial breezy cvs cloc
cmake extra-cmake-modules
dos2unix doxygen graphviz
jre8-openjdk jdk8-openjdk
tcsh gobject-introspection

### install python installer
python-pkgconfig python-wheel
python-build python-installer
python-pipenv python-virtualenv
python-pip python-distutils-extra
cython pybind11 python-setuptools

### install internet tools
firefox filezilla uget aria2
qbittorrent-nox qbittorrent

### install bluetooth support
blueman bluez
bluez-utils

### install multimedia
gstreamer gst-libav
vlc rhythmbox mpv
ffmpegthumbnailer
gst-plugins-base
gst-plugins-good
gst-plugins-ugly
gst-plugins-bad
gstreamer-vaapi
guvcview ffmpeg

### install libva driver
intel-media-driver
libva-intel-driver
libva-vdpau-driver
libva-mesa-driver
libva libva-utils
libvdpau-va-gl
vdpauinfo

### install cd-dvd tools
gnome-multi-writer
fuseiso mdf2iso
brasero bchunk
squashfuse
dvdauthor
vcdimager

### install printing support
cups cups-pdf
ghostscript gsfonts
system-config-printer
gutenprint foomatic-db-engine
foomatic-db foomatic-db-nonfree

### install image scanner
sane sane-airscan xsane
ipp-usb simple-scan

### install system information
lm_sensors xsensors hddtemp
lsof nmon sysstat procps-ng
usbutils dmidecode hwdetect
hdparm sdparm smartmontools
linux-tools arandr read-edid
hwloc hwinfo lshw mesa-utils
dstat ltrace strace mesa-demos
ccze htop inxi atop libstatgrab

### install disk tools
ntfs-3g exfat-utils
gparted dosfstools
gpart e2fsprogs
gptfdisk mtools
fuse2 fuse3

### install boot system
grub os-prober
efibootmgr
edk2-shell
edk2-ovmf

--------------------------------------------------------------------------------

## Non-Official

### install additional base
- qt5gtk2: https://aur.archlinux.org/packages/qt5gtk2/
- qt6gtk2: https://aur.archlinux.org/packages/qt6gtk2/
- brisk-menu: https://aur.archlinux.org/packages/brisk-menu/
- gtk3-nocsd-git: https://aur.archlinux.org/packages/gtk3-nocsd-git/
- humanity-icon-theme: https://aur.archlinux.org/packages/humanity-icon-theme/
- mate-tweak: https://github.com/mekatronik-achmadi/archmate/tree/master/pkgbuilds/custom/mate-tweak/
- bluementa-icon-theme: https://github.com/mekatronik-achmadi/archmate/tree/master/pkgbuilds/custom/bluementa-icon/

### install additional tools
- downgrade: https://aur.archlinux.org/packages/downgrade/
- git-cola: https://github.com/mekatronik-achmadi/archmate/tree/master/pkgbuilds/custom/git-cola/
- hardinfo-git: https://github.com/mekatronik-achmadi/archmate/tree/master/pkgbuilds/custom/hardinfo-git/

### install vim additionals
- vim-plug-git: https://aur.archlinux.org/packages/vim-plug-git/
- vi-vim-symlink: https://aur.archlinux.org/packages/vi-vim-symlink/
- vim-devicons-git: https://aur.archlinux.org/packages/vim-devicons-git/

### install archmate
- archmate-font: https://github.com/mekatronik-achmadi/archmate/tree/master/pkgbuilds/custom/archmate-font/
- archmate-theme: https://github.com/mekatronik-achmadi/archmate/tree/master/pkgbuilds/custom/archmate-theme/
- archmate-default: https://github.com/mekatronik-achmadi/archmate/tree/master/pkgbuilds/custom/archmate-default/
- archmate-archiso: https://github.com/mekatronik-achmadi/archmate/tree/master/pkgbuilds/custom/archmate-archiso/
- archmate-install: https://github.com/mekatronik-achmadi/archmate/tree/master/pkgbuilds/custom/archmate-install/

--------------------------------------------------------------------------------

## Configurations

### after installation

```sh
rsync -a /etc/skel/ $HOME/

sudo systemctl enable systemd-timesyncd
sudo systemctl start systemd-timesyncd
sudo ln -svf /usr/share/zoneinfo/Asia/Jakarta /etc/localtime
sudo date -s "28 MAR 2023 20:46:00"

sudo mkdir -vp /var/lib/pacman/sync/
sudo mkdir -vp /var/cache/pacman/pkg/

export ISOVER='mate_102023'
export DIRPATH="/home/developments/Packages/ArchMate-x86_64/$ISOVER"
sudo rsync -avh $DIRPATH/databases/ /var/lib/pacman/sync/
sudo rsync -avh $DIRPATH/packages/official/ /var/cache/pacman/pkg/

echo "install driver packages"
most lists/driver.md
```

### pacman-key problem

```sh
# optionally only if had problems
# need internet connection and proper time setting

sudo pacman-key --init
sudo pacman-key --populate archlinux

# if initialitation keep failed
#sudo pacman-key --refresh-keys
```

### configure booting

#### GRUB-BIOS from Live ISO

```sh
sudo mount /dev/sda1 /mnt/
sudo arch-chroot /mnt/

grub-install --recheck --target=i386-pc /dev/sda
grub-mkconfig -o /boot/grub/grub.cfg

exit
sudo umount /mnt/
```

#### GRUB-UEFI from Live ISO

```sh
sudo mount /dev/sda2 /mnt/
sudo mount /dev/sda1 /mnt/boot/EFI
sudo arch-chroot /mnt/

# reinstall grub for default uefi
grub-install --recheck --target=x86_64-efi --efi-directory=/boot/EFI/ --bootloader-id=grub_uefi

# reinstall grub for removable uefi
grub-install --recheck --removable --target=x86_64-efi --efi-directory=/boot/EFI/ --bootloader-id=grub_uefi

grub-mkconfig -o /boot/grub/grub.cfg

exit
sudo umount /mnt/boot/EFI
sudo umount /mnt/
```

#### GRUB include Windows

```sh
echo 'Reconfig GRUB to include Windows'
sudo sed -i 's|#GRUB_DISABLE_OS_PROBER=false|GRUB_DISABLE_OS_PROBER=false|g' /etc/default/grub
sudo grub-mkconfig -o /boot/grub/grub.cfg
```

#### GRUB SWAP partition

```sh
sudo mkswap /dev/sdxy
sudo swapon /dev/sdxy

SWAPUUID=$(sudo blkid -s UUID -o value /dev/sdxy)
echo "UUID=$SWAPUUID none swap defaults 0 0" | sudo tee -a /etc/fstab
```

#### Bash AutoLogin

```sh
sudo systemctl disable lightdm

sudo mkdir -p /etc/systemd/system/getty@tty1.service.d/
echo -e "[Service]
ExecStart=
ExecStart=-/sbin/agetty --autologin $USER --noissue --noclear %I 38400 linux
" | sudo tee /etc/systemd/system/getty@tty1.service.d/autologin.conf
```

### generic configurations

#### configure git user

```sh
git config --global init.defaultBranch main
git config --global user.name "mekatronik-achmadi"
git config --global user.email "mekatronik.achmadi@gmail.com"
```

#### create new user with/without password

```sh
sudo useradd -m -g users -G wheel,storage,power -s /bin/bash -c username username

# change password
sudo passwd username

# remove password password
sudo passwd -d username
```

#### configure networkmanager

```sh
sudo systemctl disable systemd-networkd
sudo systemctl disable systemd-resolved
sudo systemctl stop systemd-networkd
sudo systemctl stop systemd-resolved

sudo ln -svf /run/NetworkManager/resolv.conf /etc/resolv.conf
sudo systemctl enable NetworkManager
sudo systemctl start NetworkManager
```

#### configure bluetooth

```sh
sudo systemctl enable bluetooth
sudo systemctl start bluetooth
sudo bluetoothctl
```

#### configure vim

```sh
sudo mkdir -p /etc
echo '" /usr/share/vim/vimfiles/archlinux.vim' | sudo tee /etc/vimrc
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
syntax on' | sudo tee -a /etc/vimrc
```

#### configure vnc server

```sh
vncpasswd

x0vncserver -rfbauth ~/.vnc/passwd
#x0vncserver -geometry 1280x1024+0+0 -rfbauth ~/.vnc/passwd
```

#### configure vnc viewer

```sh
# Menu/Fullscreen -> F8

vncviewer <ip_number>:0
```

#### configure firefox
- https://addons.mozilla.org/en-US/firefox/addon/ublock-origin/
- https://addons.mozilla.org/en-US/firefox/addon/adblock-for-firefox/

#### configure google drive
- https://workspace.google.com/marketplace/app/file_checksum/982370769845

--------------------------------------------------------------------------------

## Notes

### updated list
- [ ] archiso.md

