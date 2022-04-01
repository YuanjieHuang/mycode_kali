#!/usr/bin/bash
install() {
	apt install nfs-kernel-server
}

config_nfs() {
echo "/mnt/sda1/NFS *(rw,async,no_subtree_check)">>/etc/exports
source /etc/exports
exportfs -r
systemctl restart nfs-kernel-server.service
}


test_nfs() {
	mount -t nfs 192.168.123.2:/mnt/sda1/NFS /media
	ls /media
}
test_nfs


