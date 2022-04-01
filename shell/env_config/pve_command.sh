/var/lib/vz/template/iso/
qm importovf 999  WindowsServer2012.ovf  local-lvm
pvesh get /nodes/pve/qemu/105/status/current
pvesh get /cluster/resources
pvesh create /nodes/pve/qemu/201/status/start
cat /etc/iscsi/initiatorname.iscsi
