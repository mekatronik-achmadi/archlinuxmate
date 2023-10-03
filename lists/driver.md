# Driver Packages

## Official

### install vulkan mesa driver
vulkan-radeon lib32-vulkan-radeon
vulkan-icd-loader lib32-vulkan-icd-loader
lib32-vulkan-intel lib32-vulkan-mesa-layers
vulkan-tools vulkan-intel vulkan-mesa-layers

### install acpi tools
acpi acpid acpi_call-dkms

### install intel-nvidia driver

```
echo "Install NVIDIA drivers first"
```
bumblebee primus lib32-primus
nvidia-prime bbswitch-dkms
primus_vk lib32-primus_vk
virtualgl lib32-virtualgl

--------------------------------------------------------------------------------

## AUR

### install hwclock
- https://aur.archlinux.org/packages/fake-hwclock/

### install gpu driver

#### nvidia-390 (utils,dkms,opencl)
- https://aur.archlinux.org/packages/nvidia-390xx-utils/
- https://aur.archlinux.org/packages/lib32-nvidia-390xx-utils/

--------------------------------------------------------------------------------

## Configurations

### configure fake-hwclock

```sh
sudo systemctl enable fake-hwclock fake-hwclock-save.timer
sudo systemctl start fake-hwclock
```

### configure nvidia

#### prevent nouveau and ibt

```sh
sudo sed -i 's@loglevel=3 quiet@loglevel=3 ibt=off quiet@g' /etc/default/grub
sudo grub-mkconfig -o /boot/grub/grub.cfg

sudo sed -i 's@kms @@g' /etc/mkinitcpio.conf
sudo mkinitcpio -p archmate
```

#### bumblebee setup

```sh
ls /usr/lib/modprobe.d/bumblebee.conf

sudo gpasswd -a $USER video
sudo gpasswd -a $USER bumblebee
sudo sed -i '0,/Driver=/s//Driver=nvidia/' /etc/bumblebee/bumblebee.conf
sudo sed -i 's@#   BusID "PCI:01:00:0"@   BusID "PCI:01:00:0"@g' /etc/bumblebee/xorg.conf.nvidia
sudo systemctl enable bumblebeed

sudo reboot
```

#### bumblebee usage

```sh
glxgears
optirun glxgears
optirun glxspheres64
#optirun glxspheres32
```

```sh
optirun wine program.exe
optirun -b primus wine program.exe

# if exit kill all wineserver
killall wineserver
```

#### optirun exit

```sh
optirun --status
lsmod | grep nvidia
sudo rmmod nvidia_drm nvidia_modeset nvidia
echo 'OFF' | sudo tee /proc/acpi/bbswitch
```

