# Git Server

## Setup Server

### login ssh

```sh
ssh -Y alarm@10.124.4.150
```

### apache server

```sh
sudo systemctl enable httpd.service
sudo systemctl start httpd
```

### git server

```sh
sudo mkdir -p /srv/git
sudo gpasswd -a alarm http
sudo chown -R http:http /srv/git/
```

### git apache config

```sh
echo 'LoadModule cgi_module modules/mod_cgi.so' | sudo tee -a /etc/httpd/conf/httpd.conf
#echo 'LoadModule env_module modules/mod_env.so' | sudo tee -a /etc/httpd/conf/httpd.conf
#echo 'LoadModule alias_module modules/mod_alias.so' | sudo tee -a /etc/httpd/conf/httpd.conf

echo '
<Directory "/usr/lib/git-core*">
   Options ExecCGI Indexes
   Order allow,deny
   Allow from all
   Require all granted
</Directory>

<LocationMatch "^/.*/git-receive-pack$">
    Options +ExecCGI
    Require all granted
</LocationMatch>

<LocationMatch "^/.*/git-upload-pack$">
    Options +ExecCGI
    Require all granted
</LocationMatch>

SetEnv GIT_PROJECT_ROOT /srv/git
SetEnv GIT_HTTP_EXPORT_ALL
ScriptAlias /git/ /usr/lib/git-core/git-http-backend/
' | sudo tee -a /etc/httpd/conf/httpd.conf
```

### gitweb interface

```sh
echo '
Alias /gitweb "/usr/share/gitweb"
<Directory "/usr/share/gitweb">
    DirectoryIndex gitweb.cgi
    Options ExecCGI
    Require all granted
    <Files gitweb.cgi>
        SetHandler cgi-script
    </Files>
    SetEnv  GITWEB_CONFIG  /etc/gitweb.conf
</Directory>' | sudo tee /etc/httpd/conf/extra/gitweb.conf

echo 'Include conf/extra/gitweb.conf' | sudo tee -a /etc/httpd/conf/httpd.conf
```

```sh
export IPNUMBER='10.124.5.150'

echo "our \$projectroot = \"/srv/git\";" | sudo tee /etc/gitweb.conf
echo "\$feature{'blame'}{'default'} = [1];" | sudo tee -a /etc/gitweb.conf
echo "\$feature{'highlight'}{'default'} = [1];" | sudo tee -a /etc/gitweb.conf
```

### git authentication (optional)

```sh
cd /srv/git
htpasswd -c htpasswd-git gitserv

echo '
<Location /git/>
        AuthName "Restricted Git"
        AuthType Basic
        AuthUserFile /srv/git/htpasswd-git
        <If "%{QUERY_STRING} =~ m#service=git-receive-pack# || %{REQUEST_URI} =~ m#/git-receive-pack$#">
                Require valid-user
        </If>
        Satisfy all
</Location>
' | sudo tee -a /etc/httpd/conf/httpd.conf
```

### Reboot

```sh
sudo reboot
```

## Test on Webrowser

```sh
firefox http://10.124.4.150/gitweb
```

## Create Repository

```sh
cd /srv/git
sudo -u http git --bare init projectTes.git/
sudo chown -R http:http /srv/git/projectTes.git/

cd projectTes.git/
echo "GitServer Test" | sudo -u http tee description
sudo -u http git config --file config http.receivepack true
```

## Git Client Workflow

### git clone-push

```sh
git clone http://10.124.4.150/git/projectTes.git
cd projectTes/

echo "test gitserver" > tes.txt
git add .
git commit -m "initial commit"
git push origin master
```

### git add remote

```sh
git remote add gitlocal http://10.124.4.150/git/projectTes.git
git remote -v

git branch
git push gitlocal master
```
