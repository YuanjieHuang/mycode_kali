touch etc/inittab 
#this is run first except when booting in single-user mode.
::sysinit:/etc/init.d/rcS
# /bin/sh invocations on selected ttys
::respawn:-/bin/sh
# Start an "askfirst" shell on the console (whatever that may be)
::askfirst:-/bin/sh
# Stuff to do when restarting the init process
::restart:/sbin/init
# Stuff to do before rebooting
::ctrlaltdel:/sbin/reboot
::shutdown:/sbin/swapoff -a

gedit etc/init.d/rcS
#!/bin/sh
#This is the first script called by init process
/bin/mount -a
echo /sbin/mdev>/proc/sys/kernel/hotplug
mdev -s

gedit etc/fstab 
#device     mount-point     type         options       dump     fsck order
proc        /proc           proc         defaults        0        0
tmpfs       /tmp            tmpfs    　　 defaults        0        0
sysfs       /sys            sysfs        defaults        0        0
tmpfs       /dev            tmpfs        defaults        0        0

gedit etc/profile
#!/bin/sh
export HOSTNAME=farsight
export USER=root
export HOME=root
export PS1="[$USER@$HOSTNAME \W]\# "
#export PS1="[\[\033[01;32m\]$USER@\[\033[00m\]\[\033[01;34m\]$HOSTNAME\[\033[00m\ \W]\$ "
PATH=/bin:/sbin:/usr/bin:/usr/sbin
LD_LIBRARY_PATH=/lib:/usr/lib:$LD_LIBRARY_PATH
export PATH LD_LIBRARY_PATH

