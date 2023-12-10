arch=arm
autoload=no
baudrate=115200
board=evb_rk3568
board_name=evb_rk3568
boot_a_script=load ${devtype} ${devnum}:${distro_bootpart} ${scriptaddr} ${prefix}${script}; source ${scriptaddr}
boot_extlinux=sysboot ${devtype} ${devnum}:${distro_bootpart} any ${scriptaddr} ${prefix}extlinux/extlinux.conf
boot_net_usb_start=usb start
boot_prefixes=/ /boot/
boot_script_dhcp=boot.scr.uimg
boot_scripts=boot.scr.uimg boot.scr
boot_targets=mmc1 mmc0 mtd2 mtd1 mtd0 usb0 pxe dhcp
bootargs=root=/dev/nfs nfsroot=192.168.123.104:/export/rootfs nolock,proto=tcp,nfsvers=3 ip=192.168.123.91:192.168.123.104:192.168.123.1:255.255.255.0::eth0:off rootwait rw initl
bootargs_nfs=setenv bootargs root=/dev/nfs nfsroot=${serverip}:${rootpath} nolock,proto=tcp,nfsvers=3 ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}::eth0:off  rootwait rw ini}
bootcmd=boot_android ${devtype} ${devnum};boot_fit;bootrkp;run distro_bootcmd;
bootcmd_dhcp=run boot_net_usb_start; if dhcp ${scriptaddr} ${boot_script_dhcp}; then source ${scriptaddr}; fi;
bootcmd_mmc0=setenv devnum 0; run mmc_boot
bootcmd_mmc1=setenv devnum 1; run mmc_boot
bootcmd_mtd0=setenv devnum 0; run mtd_boot
bootcmd_mtd1=setenv devnum 1; run mtd_boot
bootcmd_mtd2=setenv devnum 2; run mtd_boot
bootcmd_nfs=run bootargs_nfs; nfs ${kernel_addr} ${serverip}:${rootpath}/boot/Image;nfs ${fdt_addr} ${serverip}:${rootpath}/boot/armada-3720-catdrive.dtb;booti $kernel_addr - $f;
bootcmd_pxe=run boot_net_usb_start; dhcp; if pxe get; then pxe boot; fi
bootcmd_usb0=setenv devnum 0; run usb_boot
bootdelay=0
bootm_low=0x9400000
bootm_mapsize=0x76c00000
console=ttySAC0
cpu=armv8
devnum=0
devplist=1
devtype=mmc
distro_bootcmd=for target in ${boot_targets}; do run bootcmd_${target}; done
eth1addr=c6:25:3b:84:bb:34
ethact=ethernet@fe010000
ethaddr=c2:25:3b:84:bb:34
fdt_addr_r=0x0a100000
fdt_high=0xffffffffffffffff
fdtcontroladdr=0xa100000
fileaddr=0xc00800
filesize=0x2634cb0
gatewayip=192.168.123.1
init=/init
initrd_high=0xffffffffffffffff
ipaddr=192.168.123.91
kernel_addr_c=0x04080000
kernel_addr_no_low_bl32_r=0x00280000
kernel_addr_r=0x00280000
mmc_boot=if mmc dev ${devnum}; then setenv devtype mmc; run scan_dev_for_boot_part; fi
netmask=255.255.255.0
partitions=uuid_disk=${uuid_gpt_disk};name=uboot,start=8MB,size=4MB,uuid=${uuid_gpt_loader2};name=trust,size=4M,uuid=${uuid_gpt_atf};name=misc,size=4MB,uuid=${uuid_gpt_misc};nam;
pxefile_addr_r=0x00e00000
ramdisk_addr_r=0x0a200000
rkimg_bootdev=if mmc dev 1 && rkimgtest mmc 1; then setenv devtype mmc; setenv devnum 1; echo Boot from SDcard;elif mmc dev 0; then setenv devtype mmc; setenv devnum 0;elif mtd_
rootpath=/export/rootfs
scan_dev_for_boot=echo Scanning ${devtype} ${devnum}:${distro_bootpart}...; for prefix in ${boot_prefixes}; do run scan_dev_for_extlinux; run scan_dev_for_scripts; done;
scan_dev_for_boot_part=part list ${devtype} ${devnum} -bootable devplist; env exists devplist || setenv devplist 1; for distro_bootpart in ${devplist}; do if fstype ${devtype} $e
scan_dev_for_extlinux=if test -e ${devtype} ${devnum}:${distro_bootpart} ${prefix}extlinux/extlinux.conf; then echo Found ${prefix}extlinux/extlinux.conf; run boot_extlinux; echi
scan_dev_for_scripts=for script in ${boot_scripts}; do if test -e ${devtype} ${devnum}:${distro_bootpart} ${prefix}${script}; then echo Found U-Boot script ${prefix}${script}; re
scriptaddr=0x00c00000
serial#=68b639b85b2b1018
serverip=192.168.123.104
soc=rockchip
stderr=serial,vidconsole
stdin=serial,usbkbd
stdout=serial,vidconsole
usb_boot=usb start; if usb dev ${devnum}; then setenv devtype usb; run scan_dev_for_boot_part; fi
vendor=rockchip

Environment size: 5043/32764 bytes



#!/bin/bash









































arch=arm
args=console=ttyMV0,115200 root=/dev/sda1 rootwait rw init=/sbin/init
baudrate=115200
board=mvebu_armada-37xx
board_name=mvebu_armada-37xx
boot_args_nfs=root=/dev/nfs nfsroot=192.168.123.2:/root/nfs ip=192.168.123.222:192.168.123.2:192.168.123.1:255.255.255.0::eth0:off init=/sbin/init console=ttyMV0
boot_mmc0p1= setenv bootdev mmc 0:1; ext4load ${bootdev} ${scriptaddr} /boot/boot.scr && source ${scriptaddr};
boot_mmc0p2= setenv bootdev mmc 0:2; ext4load ${bootdev} ${scriptaddr} /boot/boot.scr && source ${scriptaddr};
boot_sata=scsi scan; setenv bootdev scsi 0:1; ext4load ${bootdev} ${scriptaddr} /boot/boot.scr && source ${scriptaddr};
boot_targets=usb mmc0p1 mmc0p2 sata
boot_usb=usb start; setenv bootdev usb 0:1; ext4load ${bootdev} ${scriptaddr} /boot/boot.scr && source ${scriptaddr};
bootargs=root=/dev/nfs nfsroot=192.168.123.2:/root/nfs ip=192.168.123.222:192.168.123.2:192.168.123.1:255.255.255.0::eth0:off init=/sbin/init console=ttyMV0;
bootargs_bak=root=/dev/nfs nfsroot=192.168.123.104:/export/rootfs ip=192.168.123.222:192.168.123.104:192.168.123.1:255.255.255.0::eth0:off init=/sbin/init console=ttyMV0
bootcmd=gpio input GPIO23; if test $? = 0 ;then echo "Enter button mode";run bootcmd_button;else echo "Enter nomal Mode";run bootcmd_normal;fi
bootcmd_bak=gpio input GPIO23; if test $? = 0 ;then echo "Enter button mode";run bootcmd_button;else echo "Enter nomal Mode";run bootcmd_normal;fi
bootcmd_button=for target in ${boot_targets};do run boot_${target}; done;
bootcmd_my=ext4load mmc 0:1 0x1000000 boot/armada-3720-catdrive.dtb;ext4load mmc 0:1 0x2000000 boot/Image;booti 0x2000000 - 0x1000000;
bootcmd_normal=run bootcmd_syno;
bootcmd_syno=run syno_bootargs;sf probe;sf read $loadaddr 0x0D5000 0x306000;echo "syno: start decompressing kernel... ";lzmadec $loadaddr $kernel_addr;sf read $initrd_addr 0x3DB;
bootdelay=1
console=console=ttyMV0,115200 earlycon=ar3700_uart,0xd0012000
cpu=armv8
ethact=neta@30000
ethaddr=00:11:32:11:22:00
ethprime=eth0
fdt_addr=0x6000000
fdt_high=0xffffffffffffffff
fdtcontroladdr=1f6437d0
gateway=192.168.123.1
gatewayip=192.168.123.1
hostname=catdrive
image_name=/vmlinuz
initrd_addr=0x1100000
initrd_size=0x2000000
ipaddr=192.168.123.222
kernel_addr=0x7000000
loadaddr=0x8000000
netdev=eth0
netmask=255.255.255.0
rootpath=/srv/nfs/
scriptaddr=0x6d00000
serverip=192.168.123.2
soc=mvebu
stderr=serial@12000
stdin=serial@12000
stdout=serial@12000
syno_bootargs=setenv bootargs console=ttyS0,115200 ip=off root=/dev/sda1 rw swiotlb=2048 syno_hw_version=DS119j syno_fw_version=M.246 syno_hdd_powerup_seq=1 ihd_num=1 netif_num=
vendor=Marvell
watchdog=no

Environment size: 2876/8188 bytes

setenv serverip 192.168.123.104
setenv rootpath /export/rootfs
setenv ipaddr 192.168.123.91
setenv gatewayip 192.168.123.1
setenv netmask 255.255.255.0
setenv console ttySAC0
setenv init /init
setenv  bootargs_nfs 'setenv bootargs root=/dev/nfs nfsroot=${serverip}:${rootpath} nolock,proto=tcp,nfsvers=3 ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}::eth0:off  rootwait rw init=${init} console=${console}'
setenv bootcmd_nfs 'run bootargs_nfs; nfs ${kernel_addr} ${serverip}:${rootpath}/boot/Image;nfs ${fdt_addr} ${serverip}:${rootpath}/boot/armada-3720-catdrive.dtb;booti $kernel_addr - $fdt_addr;'
bootm ${fdt_addr} - ${kernel_addr}



arch=arm
autoload=no
baudrate=115200
board=evb_rk3568
board_name=evb_rk3568
boot_a_script=load ${devtype} ${devnum}:${distro_bootpart} ${scriptaddr} ${prefix}${script}; source ${scriptaddr}
boot_extlinux=sysboot ${devtype} ${devnum}:${distro_bootpart} any ${scriptaddr} ${prefix}extlinux/extlinux.conf
boot_net_usb_start=usb start
boot_prefixes=/ /boot/
boot_script_dhcp=boot.scr.uimg
boot_scripts=boot.scr.uimg boot.scr
boot_targets=mmc1 mmc0 mtd2 mtd1 mtd0 usb0 pxe dhcp
bootargs=console=ttySAC0 init=/linuxrc root=nfs nfsroot=${serverip}:${rootpath},nolock,proto=tcp,nfsvers=3 ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}::eth0:off storagemedil
bootargs_nfs=setenv bootargs root=/dev/nfs nfsroot=${serverip}:${rootpath} nolock,proto=tcp,nfsvers=3 ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}::eth0:off  rootwait rw ini}
bootcmd=boot_android ${devtype} ${devnum};boot_fit;bootrkp;run distro_bootcmd;
bootcmd_dhcp=run boot_net_usb_start; if dhcp ${scriptaddr} ${boot_script_dhcp}; then source ${scriptaddr}; fi;
bootcmd_mmc0=setenv devnum 0; run mmc_boot
bootcmd_mmc1=setenv devnum 1; run mmc_boot
bootcmd_mtd0=setenv devnum 0; run mtd_boot
bootcmd_mtd1=setenv devnum 1; run mtd_boot
bootcmd_mtd2=setenv devnum 2; run mtd_boot
bootcmd_nfs=run bootargs_nfs; nfs ${kernel_addr} ${serverip}:${rootpath}/boot/Image;nfs ${fdt_addr} ${serverip}:${rootpath}/boot/armada-3720-catdrive.dtb;booti $kernel_addr - $f;
bootcmd_pxe=run boot_net_usb_start; dhcp; if pxe get; then pxe boot; fi
bootcmd_usb0=setenv devnum 0; run usb_boot
bootdelay=0
console=ttySAC0
cpu=armv8
devnum=0
devplist=1
devtype=mmc
distro_bootcmd=for target in ${boot_targets}; do run bootcmd_${target}; done
eth1addr=c6:25:3b:84:bb:34
ethaddr=c2:25:3b:84:bb:34
fdt_addr_r=0x0a100000
fdtcontroladdr=0xa100000
gatewayip=192.168.123.1
init=/init
ipaddr=192.168.123.91
kernel_addr_c=0x04080000
kernel_addr_no_low_bl32_r=0x00280000
kernel_addr_r=0x00280000
mmc_boot=if mmc dev ${devnum}; then setenv devtype mmc; run scan_dev_for_boot_part; fi
netmask=255.255.255.0
partitions=uuid_disk=${uuid_gpt_disk};name=uboot,start=8MB,size=4MB,uuid=${uuid_gpt_loader2};name=trust,size=4M,uuid=${uuid_gpt_atf};name=misc,size=4MB,uuid=${uuid_gpt_misc};nam;
pxefile_addr_r=0x00e00000
ramdisk_addr_r=0x0a200000
rkimg_bootdev=if mmc dev 1 && rkimgtest mmc 1; then setenv devtype mmc; setenv devnum 1; echo Boot from SDcard;elif mmc dev 0; then setenv devtype mmc; setenv devnum 0;elif mtd_
rootpath=/export/rootfs
scan_dev_for_boot=echo Scanning ${devtype} ${devnum}:${distro_bootpart}...; for prefix in ${boot_prefixes}; do run scan_dev_for_extlinux; run scan_dev_for_scripts; done;
scan_dev_for_boot_part=part list ${devtype} ${devnum} -bootable devplist; env exists devplist || setenv devplist 1; for distro_bootpart in ${devplist}; do if fstype ${devtype} $e
scan_dev_for_extlinux=if test -e ${devtype} ${devnum}:${distro_bootpart} ${prefix}extlinux/extlinux.conf; then echo Found ${prefix}extlinux/extlinux.conf; run boot_extlinux; echi
scan_dev_for_scripts=for script in ${boot_scripts}; do if test -e ${devtype} ${devnum}:${distro_bootpart} ${prefix}${script}; then echo Found U-Boot script ${prefix}${script}; re
scriptaddr=0x00c00000
serial#=68b639b85b2b1018
serverip=192.168.123.104
soc=rockchip
stderr=serial,vidconsole
stdin=serial,usbkbd
stdout=serial,vidconsole
usb_boot=usb start; if usb dev ${devnum}; then setenv devtype usb; run scan_dev_for_boot_part; fi
vendor=rockchip