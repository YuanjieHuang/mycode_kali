sudo apt-get install dnsmasq
sudo vim /etc/dnsmasq.conf
去掉strict-order前面的#号
listen-address=127.0.0.1,192.168.1.103
修改resolv.conf文件，添加以下几行
nameserver 127.0.0.1
nameserver 223.5.5.5
nameserver 114.114.114.114


curl -sSL https://install.pi-hole.net | bash