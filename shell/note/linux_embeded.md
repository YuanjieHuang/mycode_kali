gcc -g
gcc -ggdb 加入更多调试信息
CFLAGS = -Wall-pg 
LDFLAGS = -pg
gprof
CFLAGS = -ftest-coverage
gcov
设置网络服务
    DHCP
    udhcp
    http://udhcp.busybox.net
    Super-server
        inetd xinetd
        echo ::respawn:/usr/sbin/snmpd -f >>/etc/inittab
    http web
        Boa GPL许可，需C链接库，如glibc/Clibc
        http://www.boa.org  
        thttpd
        echo ::respawn:/usr/sbin/thttpd -C /etc/thttpd.conf >>/etc/inittab

    SSH
        dropbear

调试
gdb gdb-server .gdbinit文件

strace单进程追踪
Linux Trace Toolkit next generation(LTTng)

存储器调试
Electric Fence 
DUMA:http://duma.sourceforge.com

内核统计
readprofile