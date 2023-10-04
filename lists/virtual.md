# Virtual Packages

## Official

### install virtualization tools
virtualbox vde2 virtualbox-host-dkms virtualbox-guest-iso
qemu-desktop qemu-guest-agent qemu-emulators-full
qemu-user-static qemu-user-static-binfmt

### install docker
docker docker-compose

--------------------------------------------------------------------------------

## AUR

### install iso2usb writer
- https://aur.archlinux.org/packages/ventoy-bin/

### install virtualbox extension pack
- https://aur.archlinux.org/packages/virtualbox-ext-oracle/

--------------------------------------------------------------------------------

## Configurations

### configure virtualbox host

```sh
echo 'vboxdrv
vboxnetadp
vboxnetflt
vboxpci' | sudo tee /etc/modules-load.d/virtualbox.conf

sudo groupadd vboxusers
sudo gpasswd -a $USER vboxusers
```

```sh
echo 'mount shared folder on guest'
sudo mount -t vboxsf -o rw,uid=$USER folder_name /mnt
```

### configure qemu additional driver

```sh
wget https://www.spice-space.org/download/binaries/spice-guest-tools/spice-guest-tools-latest.exe
```

