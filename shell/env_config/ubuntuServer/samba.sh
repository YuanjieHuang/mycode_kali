#!/bin/bash

brook(){
  curl -L https://github.com/txthinking/brook/releases/download/v20230401/brook_linux_amd64 -o /usr/bin/brook
  chmod +x /usr/bin/brook
  setsid brook server --listen :9999 --password hello
}
hysteria(){
  bash <(curl -fsSL https://git.io/hysteria.sh)

}
ssr(){
  wget -N --no-check-certificate https://raw.githubusercontent.com/ToyoDAdoubi/doubi/master/ssr.sh && chmod +x ssr.sh && bash ssr.sh
  # wget -N --no-check-certificate https://raw.githubusercontent.com/ToyoDAdoubiBackup/doubi/master/ss-go.sh && chmod +x ss-go.sh && bash ss-go.sh
}
v2ray()
{
  source <(curl -sL https://multi.netlify.app/v2ray.sh) --zh
}
trojan(){
  bash -c "$(curl -fsSL https://raw.githubusercontent.com/atrandys/trojan/master/trojan_mult.sh)"
}

tcp(){
  wget -N --no-check-certificate "https://raw.githubusercontent.com/chiakge/Linux-NetSpeed/master/tcp.sh"
  chmod +x tcp.sh
  ./tcp.sh
}

blue(){
    echo -e "\033[34m\033[01m$1\033[0m"
}
green(){
    echo -e "\033[32m\033[01m$1\033[0m"
}
red(){
    echo -e "\033[31m\033[01m$1\033[0m"
}

rand(){
    min=$1
    max=$(($2-$min+1))
    num=$(cat /dev/urandom | head -n 10 | cksum | awk -F ' ' '{print $1}')
    echo $(($num%$max+$min))  
}

version_lt(){
    test "$(echo "$@" | tr " " "\n" | sort -rV | head -n 1)" != "$1"; 
}


check_release(){

    source /etc/os-release
    RELEASE=$ID
    VERSION=$VERSION_ID

}
docker_pha() {
  docker run -p 3306:3306 --name mysql_docker -v /home/yjie/conf:/etc/mysql/conf.d -v /home/yjie/logs:/logs -v /home/yjie/data:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=123456 -d mysql:5.7
ocker run --name phabricator -p 443:443 -p 332:22 -p 8891:80 -v /root/phabricator/backup:/repos -e PHABRICATOR_HOST=192.168.123.100:8891 -e MYSQL_HOST=172.17.0.2 -e MYSQL_USER=root -e MYSQL_PASS=123456 -e PHABRICATOR_REPOSITORY_PATH=/repos -e PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin -it redpointgames/phabricator /bin/bash /app/init.sh

}
git_cfg() {
  cat >>~/.gitconfig <<EOF
[core]
        editor = vim
[alias]
        co = checkout
        ci = commit
        st = status
        br = branch
        hist = log --pretty=format:\"%h %ad | %s%d [%an] \"  --graph --date=short
        type = cat-file -t
        dump = cat-file -p
	lg = log --topo-order --all --graph --date=local --pretty=format:'%C(green)%h%C(reset) %><(55,trunc)%s%C(red)%d%C(reset) %C(blue)[%an]%C(reset) %C(yellow)%ad%C(reset)%n'
EOF
}

ubuntu2204_static_ipv4_cfg() {
  $ cat >>/etc/netplan/00-installer-config.yaml<< EOF
network:
  ethernets:
    ens18:
      dhcp4: no
      addresses: [192.168.123.200/24]
      routes:
        - to: default
          via: 192.168.123.1
            #      gateway4: 192.168.123.1
      nameservers:
        addresses: [8.8.8.8,114.114.114.114]
  version: 2
EOF
}

sftp_install() {
  mkdir -pv /mnt/sda1/sftp/public
  groupadd sftp
  useradd -g sftp -d /mnt/sda1/sftp -p sftp -s /bin/false sftp
  echo "set sftp user password!"
  passwd sftp
  chmod 777 /mnt/sda1/sftp/public
  chown -R sftp:sftp /mnt/sda1/sftp/public
  chmod 755 /mnt/sda1/sftp
  chown root:root /mnt/sda1/sftp

}

tftp_cfg() {
  apt-get update
  apt-get upgrade
  sudo apt-get install tftp-hpa tftpd-hpa 
  mkdir -p /home/samba/tftp
sudo cat>>/etc/default/tftpd-hpa<<eof
TFTP_USERNAME="tftp"
TFTP_DIRECTORY="/home/samba/tftp" # 这是tftpd-hpa的服务目录 要和上面建立的服务器目录一样
TFTP_ADDRESS="0.0.0.0:69"
TFTP_OPTIONS="-l -c -s"    # -c是可以上传文件
eof
  sudo service tftpd-hpa restart

}

ntp_cfg() {
  timedatectl
  sudo timedatectl set-timezone your_time_zone
  timesyncd
}

gitlab_cfg() {
  sudo apt-get install curl openssh-server ca-certificates apt-transport-https
  curl https://packages.gitlab.com/gpg.key | sudo apt-key add -
  sudo curl -sS https://packages.gitlab.com/install/repositories/gitlab/raspberry-pi2/script.deb.sh | sudo bash
  sudo EXTERNAL_URL="192.168.123.162" apt-get install gitlab-ce
}

smb_cfg() {
  sudo apt install samba samba-common
  # 新建目录，用于共享
  sudo mkdir /home/samba
  # 更改权限信息
  sudo chown nobody:nogroup /home/samba
  # 给所有用户添加读写权限
  sudo chmod 777 /home/samba
  sudo smbpasswd -a ubuntu

  cat >> /etc/samba/smb.conf <<EOF
[Volumes]
  comment = ubuntu samba server
  path = /srv/samba
  browseable = yes
  writable = yes
  available = yes
  valid users = ubuntu

[public]
  comment = public folder
  path = /home/samba
  read only = no
  browseable = yes
  public = yes
  writable = yes
EOF
sudo systemctl restart smbd
# man 5 smb.conf
}

nfs_server_cfg() {
    #config server
    sudo apt install nfs-kernel-server
    sudo mkdir /home/samba -p
    sudo chown nobody:nogroup /home/samba
    sudo cat >> /etc/exports <<EOF
    /home/samba 192.168.123.0/24(rw,sync,no_subtree_check)
    /home 192.168.123.0/24(rw,sync,no_root_squash,no_subtree_check)
EOF
    sudo systemctl restart nfs-kernel-server
    sudo ufw allow from 192.168.123.0/24 to any port nfs
    sudo ufw enable
    sudo ufw status

}

nfs_client_cfg() {
    #config client
    sudo apt install nfs-common
    sudo mkdir -p /mnt/nfs
    sudo mkdir -p /nfs/home
    sudo mount 192.168.123.138:/mnt/nfs /mnt/nfs
    # sudo cat >> /etc/fstab <<EOF
    # 192.168.77.10:/home/samba /home/samba  nfs defaults,timeo=900,retrans=5,_netdev 0 0
    # 192.168.77.10:/home /nfs/home                nfs defaults,timeo=900,retrans=5,_netdev 0 0
    # EOF
}


ftp_cfg() {
# https://www.myfreax.com/how-to-setup-ftp-server-with-vsftpd-on-ubuntu-18-04/
    sudo apt-get install vsftpd
    sudo systemctl status vsftpd
    
    cat >> /etc/vsftpd.conf <<EOF
    anonymous_enable=NO
    local_enable=YES
    write_enable=YES
    chroot_local_user=YES
    allow_writeable_chroot=YES
EOF
    sudo /etc/init.d/vsftpd restart
}

man_page() {
sudo apt-get install manpages manpages-dev manpages-de  manpages-de-dev
sudo apt-get install manpages-posix manpages-posix-dev
sudo apt-get install linux-doc libcorelinux-dev
#或者直接下载 C++ 帮助文档，然后把文件拷贝到 /usr/share/man/man3 # man std::vector
sudo apt-get install libc-dev glibc-doc libstdc++-10-dev libstdc++-10-doc
cat >> ~/.bashrc <<EOF
#/*manpages颜色  .bashrc*/
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_mb=$'\E[01;32m'
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_md=$'\E[01;36m'   # man description
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_me=$'\E[0m'
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_so=$'\E[01;32m'
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_se=$'\E[0m' 
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_us=$'\E[01;32m'  # underly select  
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_ue=$'\E[0m' 
EOF

}


start_menu(){
    clear
    green "==============================================="
    green " 介绍: 一键安装wireguard, 增加wireguard多用户"
    green " 系统: Centos7+/Ubuntu18.04+/Debian9+"
    green " 作者: atrandys www.atrandys.com"
    green " 提示: 脚本安装过程中会升级内核，请勿生产环境使用"
    green "==============================================="
    green "1. 安装wireguard"
    red "2. 删除wireguard"
    green "3. 显示默认用户二维码"
    green "4. 增加用户"
    red "0. 退出"
    echo
    read -p "请选择:" num
    case "$num" in
        1)
        check_selinux
        ;;
        2)
        remove_wg
        ;;
        3)
        content=$(cat /etc/wireguard/client.conf)
        echo "${content}" | qrencode -o - -t UTF8
        ;;
        4)
        add_user
        ;;
        0)
        exit 1
        ;;
        *)
        clear
        red "Please enter the correct number!"
        sleep 1s
        start_menu
        ;;
        esac
}

start_menu

# setenv bootargs root=/dev/nfs nfsroot=${serverip}:${rootpath} nolock,proto=tcp,nfsvers=4 ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}::eth0:off  rootwait rw init=/bin/sh console=ttyMV0,115200
# bootcmd=for target in ${boot_targets}; do run bootcmd_${target}; done