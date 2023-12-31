# RaspberryPi Basic Configurations

## Bugfixes

### dkms build arch directory

```sh
cd /usr/lib/modules/$(uname -r)/build/arch/
sudo ln -svf arm armv7l
cd -
```

### libblas armv7 (optional)

```sh
sudo ln -svf libopenblas_armv7p-r0.3.19.so /usr/lib/libblas.so.3
```

### redirect libEGL (experimental)

```sh
# using default
ls /usr/lib/libEGL.so.1*
ls /usr/lib/libGLESv2.so.2*
sudo ln -svf /usr/lib/libEGL.so.1.1.0 /usr/lib/libEGL.so
sudo ln -svf /usr/lib/libEGL.so.1.1.0 /usr/lib/libEGL.so.1
sudo ln -svf /usr/lib/libGLESv2.so.2.1.0 /usr/lib/libGLESv2.so
sudo ln -svf /usr/lib/libGLESv2.so.2.1.0 /usr/lib/libGLESv2.so.2

# using video-core (Pi4 Only)
ls /opt/vc/lib/libEGL.so*
ls /opt/vc/lib/libGLESv2.so*
sudo ln -svf /opt/vc/lib/libEGL.so /usr/lib/libEGL.so
sudo ln -svf /opt/vc/lib/libEGL.so /usr/lib/libEGL.so.1
sudo ln -svf /opt/vc/lib/libGLESv2.so /usr/lib/libGLESv2.so
sudo ln -svf /opt/vc/lib/libGLESv2.so /usr/lib/libGLESv2.so.2
```

--------------------------------------------------------------------------------

## Additional Drivers

### USB-WiFi TL-WN823N (RTL8192EU)

- https://aur.archlinux.org/packages/8192eu-dkms-git/

```sh
#sudo dkms install --no-depmod 8192eu/r257.744bbe5 -k $(uname -r)
#sudo depmod -a
#sudo modprobe 8192eu

echo "blacklist rtl8xxxu" | sudo tee /etc/modprobe.d/rtl8xxxu.conf
```

--------------------------------------------------------------------------------

## Additional Configuration

### login ssh

```sh
rm -r ~/.ssh/

# ssh with X11 forwarding
#ssh -Y alarm@10.124.4.150
ssh -X alarm@10.124.4.150

hwclock --show --verbose;date
sudo date -s "9 JUL 2021 07:00:00"

python /home/alarm/tkfree.py

exit
```

### WiFi Connection

```sh
sudo nmcli radio wifi on

sudo nmcli dev wifi
sudo iwlist wlan0 scan | grep SSID

sudo nmcli --ask dev wifi connect CobaMQTT
sudo nmcli dev wifi connect CobaMQTT password "cobamqtt"

sudo nmcli con
sudo nmcli con show CobaMQTT
sudo nmcli con delete CobaMQTT
```

```sh
# alternative front-end
sudo nmtui
```

### Run GUI Program without Desktop Environment (qemu-chroot)

```sh
echo "startx /usr/bin/python /home/alarm/tkfree.py" >> ~/.bashrc
```

```sh
echo '
if [ -n "$SSH_CLIENT" ] || [ -n "$SSH_TTY" ]; then
    echo "SSH Login Success"
else
    startx /usr/bin/python /home/alarm/tkfree.py &> /dev/null
    #startx /usr/bin/python /home/alarm/tkfree.py -- -logverbose 6 &> ~/xorg.log
fi
' >> /home/alarm/.bashrc
```

### FTP server

```sh
echo 'vsftpd: ALL
vsftpd: 10.0.0.0/255.255.255.0
' | sudo tee /etc/hosts.allow

echo '
listen=YES
local_enable=YES
write_enable=NO
local_root=/home/alarm/Downloads/
anonymous_enable=YES
no_anon_password=YES
anon_upload_enable=NO
anon_mkdir_write_enable=NO
anon_other_write_enable=NO
anon_world_readable_only=YES
anon_root=/home/alarm/Downloads/
ftpd_banner=Welcome on Achmadi Movie Torrent
' | sudo tee /etc/vsftpd.conf

sudo systemctl enable vsftpd
sudo systemctl start vsftpd

# test on local
ftp localhost
```

### VNC server

#### remote virtual monitor without physical display

```sh
vncpasswd

mkdir -p ~/.vnc/
echo 'session=openbox
geometry=1024x768
alwaysshared
' | tee ~/.vnc/config
echo ':1=alarm' | sudo tee /etc/tigervnc/vncserver.users

sudo systemctl enable vncserver@:1
sudo systemctl start vncserver@:1
```

#### remote virtual monitor on direct display (user)

```sh
vncpasswd

x0vncserver -rfbauth ~/.vnc/passwd
#x0vncserver -geometry 1280x1024+0+0 -rfbauth ~/.vnc/passwd
```

#### remote virtual monitor on direct display (root)

```sh
vncpasswd

echo "[Unit]
Description=Remote desktop service (VNC) for :0 display
Requires=display-manager.service
After=network-online.target
After=display-manager.service

[Service]
Type=simple
Environment=HOME=/root
Environment=XAUTHORITY=/var/run/lightdm/root/:0
ExecStart=x0vncserver -display :0 -rfbauth /home/alarm/.vnc/passwd
Restart=on-failure
RestartSec=500ms

[Install]
WantedBy=multi-user.target
" | sudo tee /etc/systemd/system/x0vncserver.service

sudo systemctl enable x0vncserver
sudo systemctl start x0vncserver
```

#### access vnc client example

```sh
# Port 5900 -> :0
# Port 5901 -> :1
# Menu/Fullscreen -> F8

vncviewer <ip_number>:<display_number>

vncviewer 10.124.2.141:0
vncviewer 10.124.2.141:1
```
