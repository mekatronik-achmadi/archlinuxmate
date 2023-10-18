## Android-x86 in Qemu

### install qemu android-x86

- https://aur.archlinux.org/packages/qemu-android-x86/

### configure qemu android-x86

```sh
wget https://raw.githubusercontent.com/m9rco/Genymotion_ARM_Translation/master/package/Genymotion-ARM-Translation_for_8.0.zip

unsquashfs -q -f -d $HOME/.config/android-x86/ /usr/share/android-x86/system.sfs
sudo mount $HOME/.config/android-x86/system.img /mnt/

unzip Genymotion-ARM-Translation_for_8.0.zip
sudo cp -rf system/* /mnt/;rm -r ./system/

sudo sed -i '/^ro.product.cpu.abilist=x86_64,x86/ s/$/,armeabi-v7a,armeabi/' /mnt/build.prop
sudo sed -i '/^ro.product.cpu.abilist32=x86/ s/$/,armeabi-v7a,armeabi/' /mnt/build.prop

echo 'persist.sys.nativebridge=1' | sudo tee -a /mnt/build.prop
sudo sed -i 's/ro.dalvik.vm.native.bridge=0/ro.dalvik.vm.native.bridge=libhoudini.so/' /mnt/build.prop

sudo umount /mnt

sudo sed -i "s#\$NET_QEMULINE \$DATA_QEMULINE#-net nic -net user,hostfwd=tcp::4444-:5555 \$DATA_QEMULINE#g" /usr/bin/qemu-android
sudo sed -i "s#file=\$SYSTEMIMG#file=$HOME/.config/android-x86/system.img#g" /usr/bin/qemu-android

sudo rm -f /usr/share/applications/qemu-android.desktop
mkdir -p $HOME/.config/android-x86/
cp -f /usr/share/android-x86/config $HOME/.config/android-x86/
```

```sh
qemu-android
echo '
FULL = CTRL+ALT+F
HOME = WINDOWS
BACK = CTRL+ALT+BKSPACE'
```

```sh
echo 'Settings -> Network & internet -> Wi-Fi -> VirtWifi'
adb disconnect
adb connect localhost:4444

adb push file.mp3 /storage/self/primary/Download/
adb shell
exit

adb install file.apk
adb install --abi armeabi-v7a file.apk
```

```sh
echo 'reset device'
rm -f ~/.config/android-x86/data.img
qemu-android
```
