#!/bin/bash
ssr_server_install(){
    echo "Install ssr..."
    wget -N --no-check-certificate https://raw.githubusercontent.com/ToyoDAdoubi/doubi/master/ssr.sh && chmod +x ssr.sh && bash ssr.sh
    # wget -N --no-check-certificate https://raw.githubusercontent.com/ToyoDAdoubiBackup/doubi/master/ss-go.sh && chmod +x ss-go.sh && bash ss-go.sh
    # wget -N --no-check-certificate https://raw.githubusercontent.com/ToyoDAdoubiBackup/doubi/master/ssrmu.sh && chmod +x ssrmu.sh && bash ssrmu.sh#multi users
    echo "Install improve speed tools..."
    wget -N --no-check-certificate "https://raw.githubusercontent.com/chiakge/Linux-NetSpeed/master/tcp.sh" && chmod +x tcp.sh
}

# Python : https://github.com/shadowsocks/shadowsocks/tree/master#install
# Shadowsocks-libev: https://github.com/shadowsocks/shadowsocks-libev#installation
install_ss(){
    apt-get install python-pip;
    pip install git+https://github.com/shadowsocks/shadowsocks.git@master
}


# 创建一个 /etc/shadowsocks.json 文件，格式如下
generate_cfg_file(){
    cat >/etc/shadowsocks.json<<EOF
    {
        "server":"服务器 IP 或是域名",
        "server_port":端口号,
        "local_address": "127.0.0.1",
        "local_port":1080,
        "password":"密码",
        "timeout":300,
        "method":"加密方式 (chacha20-ietf-poly1305 / aes-256-cfb)",
        "fast_open": false
    }
EOF
}

# Python 版客户端命令是 sslocal ， Shadowsocks-libev 客户端命令为 ss-local
start_ss(){
    /usr/local/bin/sslocal -c /etc/shadowsocks.json -d start
}

client_ssr_cfg(){
echo
}
ssr_server_install;
