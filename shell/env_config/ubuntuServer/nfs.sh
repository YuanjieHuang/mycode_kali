#!/bin/bash

#config server
sudo apt install nfs-kernel-server
sudo mkdir /mnt/nfs -p
sudo chown nobody:nogroup /mnt/nfs
sudo cat >> /etc/exports <<EOF
/mnt/nfs client_ip(rw,sync,no_subtree_check)
/home client_ip(rw,sync,no_root_squash,no_subtree_check)
EOF
sudo systemctl restart nfs-kernel-server
sudo ufw allow from 192.168.123.0/24 to any port nfs
sudo ufw enable
sudo ufw status

#config client
sudo apt install nfs-common
sudo mkdir -p /mnt/nfs
sudo mkdir -p /nfs/home
sudo mount 192.168.123.138:/mnt/nfs /mnt/nfs
sudo mount host_ip:/home /nfs/home

sudo cat >> /etc/fstab <<EOF
192.168.77.10:/mnt/nfs /mnt/nfs  nfs defaults,timeo=900,retrans=5,_netdev 0 0
192.168.77.10:/home /nfs/home                nfs defaults,timeo=900,retrans=5,_netdev 0 0
EOF

