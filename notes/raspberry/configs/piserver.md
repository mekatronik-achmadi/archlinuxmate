# Pi Server

## Basic Configuration

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
sudo nmtui
```

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

## Hello Word JS

Save as **app.js**:

```js
const http = require('http');

//const hostname = '127.0.0.1';
const  hostname = '10.124.4.252';
const port = 3000;

const server = http.createServer((req,res) => {
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/plain');
    res.end('Hello World');
    console.log(req.headers['user-agent']);
});

server.listen(port, hostname, () => {
    console.log(`Server Running at http://${hostname}:${port}/`);
});
```

running on Node.JS

```sh
node app.js

#NODE_DEBUG=cluster,net,http,fs,tls,module,timers node app.js
```

test on local webrowser:

```sh
w3m http://localhost:3000
w3m http://10.124.4.252:3000
```

## Hello Word PHP

```sh
sudo sed -i "s@#LoadModule unique_id_module@LoadModule unique_id_module@g" /etc/httpd/conf/httpd.conf
sudo sed -i "s@LoadModule mpm_event_module modules/mod_mpm_event.so@#LoadModule mpm_event_module modules/mod_mpm_event.so@g" /etc/httpd/conf/httpd.conf
sudo sed -i "s@#LoadModule mpm_prefork_module modules/mod_mpm_prefork.so@LoadModule mpm_prefork_module modules/mod_mpm_prefork.so@g" /etc/httpd/conf/httpd.conf

sudo vim /etc/httpd/conf/httpd.conf
```

Place this at the end of the **LoadModule** list:

```text
LoadModule php_module modules/libphp.so
AddHandler php-script .php
```

Place this at the end of the **Include** list:

```text
Include conf/extra/php_module.conf
```

PhpInfo example:

```sh
echo "<?php phpinfo(); ?>"  | sudo tee /srv/http/phpinfo.php
```

Run http server:

```sh
sudo systemctl start httpd
sudo systemctl enable httpd

#sudo systemctl restart httpd
```

test on local webrowser:

```sh
w3m http://localhost/phpinfo.php
w3m http://10.124.4.252/phpinfo.php
```
