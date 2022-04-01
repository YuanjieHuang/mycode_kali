# src:https://github.com/fatedier/frp/releases
部署服务端
    然后进入frp软件目录，编辑frps.ini。一个简易有授权的配置为： 
[common]

bind_port = 你的端口号
token=认证密钥 
接下来启动frps服务：
nohup ./frps -c frps.ini >> frps.log 2>&1 &
如果开了防火墙，记得放行相应的端口。

树莓派上部署客户端
[common]
server_addr = 服务器ip
server_port = 服务器端口
token = 服务器密钥

[ssh]
type = tcp
local_ip = 127.0.0.1
local_port = 22
remote_port = 希望在服务器上监听的端口

配置好后启动frp客户端：
nohup ./frpc -c frpc.ini >> frpc.log 2>&1 &



对于接上显示器的树莓派，建议用vncserviced。
三种开启方法同ssh，命令行命令是：
sudo systemctl enable vncserver-x11-serviced && 
sudo systemctl start vncserver-x11-serviced。
树莓派用的realvnc服务端，需要下载realvnc客户端才能连接；