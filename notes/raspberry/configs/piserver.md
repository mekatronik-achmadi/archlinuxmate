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
