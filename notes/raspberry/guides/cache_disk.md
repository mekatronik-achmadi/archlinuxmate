# Cache Disk

## Prepare VDisk

```sh
qemu-img create armv7h.img 4G
dd status=progress if=/dev/zero of=armv7h.img bs=1G count=4

```sh

```sh
sudo parted armv7h.img mklabel msdos

yes | sudo parted armv7h.img mkpart primary 0% 100%
sudo losetup --partscan --find --show armv7h.img
sudo mkfs.ext4 /dev/loop0

sudo losetup -d /dev/loop0
```

## Cache Backup

```sh
sudo mkdir -p /mnt/pkgs/
sudo losetup --partscan --find --show armv7h.img
sudo mount /dev/loop0 /mnt/pkgs/
```

```sh
sudo mkdir -p /mnt/pkgs/databases/
sudo mkdir -p /mnt/pkgs/packages/official/

sudo rsync -avh armv7h/databases/ /mnt/pkgs/databases/
sudo rsync -avh armv7h/packages/official/ /mnt/pkgs/packages/official/
```

```sh
sudo umount /mnt/pkgs/
sudo losetup -d /dev/loop0
```

## Cache Mount

```sh
sudo losetup --partscan --find --show armv7h.img

sudo mkdir -p /mnt/mmc/root/mnt/pkgs/
sudo mount /dev/loop0 /mnt/mmc/root/mnt/pkgs/
```

## File check

```sh
sudo arch-chroot /mnt/mmc/root/
```

```sh
ls -1 /mnt/pkgs/databases/
ls -1 /mnt/pkgs/packages/official/

export CACHEDIR=/mnt/pkgs/packages/official/
pacman -Su --noconfirm
pacman -S --noconfirm --cachedir $CACHEDIR package_names
```

```sh
exit
```

## Cache unmount

```sh
sudo umount /mnt/mmc/root/mnt/pkgs/
sudo losetup -d /dev/loop0
```
