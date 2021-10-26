ldd /bin/ls
        linux-vdso.so.1 (0x00007ffd05f48000)

cat /proc/self/maps
dd if=/proc/self/mem of=linux_vdso bs=4096 skip=34359682551 count=2