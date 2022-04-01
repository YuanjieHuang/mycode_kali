apt install default-jdk
apt install mariadb-server
apt install git 
wget https://gerrit-releases.storage.googleapis.com/gerrit-3.3.1.war
java -jar gerrit* init -d localhost
apt install nginx
 sudo useradd gerrit -m -s /bin/bash
 sudo passwd gerrit
 su gerrit
 apt isntall php
 mkdir ~/Phabricator && cd ~/Phabricator

git clone https://github.com/phacility/libphutil.git
git clone https://github.com/phacility/arcanist.git
git clone https://github.com/phacility/phabricator.git

touch /etc/nginx/site-enabled/phabricator
cat /etc/nginx/site-enabled/phabricator<<eof
# Phabricattor
server {
    listen 80;
    root /var/www/phabricator;
    index index.html index.htm index.php;
    server_name phb.chenjiehua.me;

    location / {
        index index.php;
        rewrite ^/(.*)$ /index.php?__path__=/$1 last;
    }

    location = /favicon.ico {
        try_files $uri =204;
    }

    location /index.php {
        fastcgi_pass unix://var/run/php5-fpm.sock;
        fastcgi_index index.php;
        include fastcgi_params;
    }
}
eof
apt install php-mysql php-gd php-dev php-curl  php-cli php-json php-apcu php-apcu-bc
