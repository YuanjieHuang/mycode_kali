###### shell脚本的调试方法

```shell
-n 用于检测脚本语法错误，但不执行脚本；如：/bin/sh -n *.sh

-v 一边执行脚本，一边将执行的脚本命令打印到标准错误输出

-x 提供跟踪执行信息，将执行的每一条命令和结果依次打印出来

xargs - build and execute command lines form standard input
find . -type f -print | xargs file
find . -name *.py xargs vim 


sed:Stream Editor
sed option 'script' file1 file2 ...
sed option -f scriptfile file1 file2 ...

/pattern/action		如：/pattern/p /pattern/d a,append;i,insert;d,delete;s,substitution

awk:
awk option 'script' file1 file2 ...
awk option -f scriptfile file1 file2 ...

/pattern/ {action}
condition {action}
与sed类似，pattern是正则表达式，actions是一系列操作。awk程序是一行一行独处待处理文件，如果某一行与pattern匹配或满足condition条件，则执行相应的actions，如果awk命令只有actions部分，则actions作用于待处理文件的每一行。

命令的condition部分可以是两个特殊的condition--BEGIN和END，对于每个待处理文件，BEGIN后面的actions在处理整个文件之前执行一次，END后面的actions在整个文件处理完之后执行一次。
如，awk '/^ *$/ {x=x+1} END {print x}' ps.txt 
awk常用的内建变量：FIELNAME NR NF OFS FS ORS RS
打印系统用户账户列表：
awk 'BEGIN {FS=":"} {print $1}' /etc/passwd
```

###### 开机自启动脚本

先将脚本复制或软链接到/etc/init.d/目录下，然后用：

update-rc xxx defaults NN命令（xxx为脚本名，NN为启动顺序）

shell习题：

1.计算1-100的和：

```shell
#!/bin/bash
SUM=0
I=0
while [$I -le 100]; do
	SUM=$((SUM+I))
	I=$(($I+1))
done
```

2.将一个目录下所有的文件的扩展名改为bak

```shell
for i in *.*; do
	mv $i ${i%%.*}.bak 
done 
```



```
根据端口列进程
netstat -ntlp | grep 80 awk '{print $7}' | cut -d/ -fl
获得访问前10位的ip地址：
cat access.log|awk'{print $1}'|sort|uniq c|sort -nr|head -10
```



```shell
echo "root's bins: ${find ./ -type f |xargs ls -l |sed '/-..x/p' | wc -l}"
netstat -apn | grep sshd | sed -n 's/. *:::\([0-9]*\)\/sshd/\1 \2/p'
free  -m | sed -n '/Swap/p' | awk '{print $2}'
cat /etc/passwd | awk -F: '{if ($7!="") printf $7}' | sort |uniq -c
time (
for i in {1..2000}; do
	mkdir /tmp/nnn$i
done
)

for FileName in `ls -l | awk '$5>10240 {print $9}'`; do
	mv $FileName /tmp
done
```

```shell
#!/bin/bash
user=`whoami`
case $user in
	root)
		echo "hello root";;
	*)
		echo "hello $user ,welcome"
esac

echo "date:`date`"
echo "calculator:`cal`"
echo "The machine's name:`uname -s;uname -r`"
echo "root's running progress:`ps -u root`"

seq 1 100 产生1～100的数组
```

###### 自动化部署

pexpect

fabric

