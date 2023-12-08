# Chip Support

## Alternative Repositories

**Arch Linux ARM dropping armv6 support as Februari 2022**

Affected platforms

- Raspberry Pi B
- Raspberry Pi Zero and Zero W

Option available:

- Migrate back to Raspbian (Recommended)
- Use archives in:
  - OS:
    - https://alaa.ad24.cz/repos/2022/02/06/os/rpi/
    - http://tardis.tiny-vps.com/aarm/repos/2022/01/08/os/rpi/
  - Packages:
    - https://alaa.ad24.cz/repos/2022/02/06/armv6h/
    - http://tardis.tiny-vps.com/aarm/repos/2022/01/08/armv6h/

## Transmission Daemon

### basic settings

```sh
sudo gpasswd -a alarm transmission

sudo mkdir -p /etc/systemd/system/transmission.service.d/
echo '[Service]
User=alarm' | sudo tee /etc/systemd/system/transmission.service.d/username.conf
sudo systemctl daemon-reload

sudo systemctl enabled transmission
sudo systemctl start transmission

# run once to generate settings
w3m http://localhost:9091

# reboot to for user relogin
reboot
```

### daemon access and target directory

```sh
sudo systemctl stop transmission
```

```sh
sed -i 's#"rpc-whitelist-enabled": true#"rpc-whitelist-enabled": false#g' \
/home/alarm/.config/transmission-daemon/settings.json
```

```sh
mkdir -p /home/alarm/Downloads/Torrents/
chmod -Rvf 775 /home/alarm/Downloads/Torrents/
chgrp -Rvf transmission /home/alarm/Downloads/Torrents/

sed -i 's#/home/alarm/Downloads#/home/alarm/Downloads/Torrents#g' \
/home/alarm/.config/transmission-daemon/settings.json
```

```sh
sudo systemctl start transmission
```
