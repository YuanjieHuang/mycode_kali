#!/bin/bash
# find .. -name "*.out" |xargs -i rm {} 
find .. -iname '*.o' |xargs -i cp {} .
# mkdir ./bak && find . -name "*.c" |xargs -i cp {} ./bak
find .. |egrep '\.o$' |wc
find /usr/include/ -iname '*.h' | xargs grep 'ORIG_EAX' -sl



git status | grep deleted | awk '{print $2}'
git rm `git status | grep deleted | awk '{print $2}'`
git add -u
git commit --amend
git commit -am "message"
git checkout -b <branch name>
git fetch / git merge
git cherry-pick <commit ID>
git pull --rebase / git rebase --continue
git rebase -i master / git rebase --continue 

git rebase -i master这条命令就是我们最好的工具。它不仅可以让我们当前的分支从master同步最新的代码，而且还可以将我们分支上的多个commit合并成为一个，可以让branch更简洁，毕竟branch上的代码都是为了实现一个功能。

delete first line
1.采用awk
awk '{$1="";print $0}'  file
2.采用sed
sed -e 's/[^ ]* //'  file

########################################################################
find ~/github/mycode_kali -name "*.txt" |xargs -0  echo 
xargs -a /etc/os-release echo
xargs -a /etc/hostname 
ls *.txt |grep xargs -I {} cp {} /tmp/
ls *.txt |grep xargs -I [] cp [] /tmp/
ls *.txt |grep xargs -I %  cp %  /tmp/
seq 5|xargs
seq 5|xargs -n 3 #-n 3 一次调用3个参数
echo "helloatheaworld"|xargs -da #specify 'a' as a seprate charactor

#shell解释器属性
set -o
braceexpand [+-]B
noclobber [+-]C
hashall    [+-]h
shopt
shopt -s extglob
ls !(a.txt|b.txt)

emulate -lLR zsh
setopt
#进程替换
wc -l <(who)
ls | tee >(grep sh$ >sh.log) >(grep txt$ >txt.log)

player="DUNCAN"
mvp=player
echo ${mvp}
echo ${!mvp}
${val:-keywords}
${val:=keywords}
echo ${color:=blue}
${val:?keywords}
echo ${input:?'你没有输入变量的值'}
${val:+keywords}

#####变量内容统计与替换#######
${!U*}
${!U@}

${!arry_name[*]}
${!arry_name[@]}

declare -A str
str[a]=aaa
str[b]=bbb
str[word]="key value"
echo ${!str[*]}
echo ${!str[@]}
${#val} #统计变量val长度
${变量/旧字符串/新字符串}
${变量//旧字符串/新字符串}
${变量^匹配字符} #小写转大写
${变量^^匹配字符}
lowers="hello the world"
echo ${lowers^} #首字母
echo ${lowers^^} #所有字母
echo ${lowers^h} 
echo ${lowers^^h}
echo ${lowers^^[heo]}
${变量,匹配字符}
${变量,,匹配字符}

IFS分隔符，默认为空格、Tab、换行
IFS=$',' read -p "Input 3 charactor" x y z

ls -l /proc/$$/fd #查看当前shell的文件描述符
touch test.txt
exec 11>test.txt #创建可输出文件描述符
echo hello >&11
cat test.txt
exec 11<&-  #关闭文件描述符

exec 14<>test.txt ##创建可读可写文件描述符
cat <&14  #读取文件内容

mkfifo pipe_file
echo "hello world">pipe_file
cat pipe_file

printf "%s" "$IFS" |od -b

[ $USER == root ] && echo Y || echo N
[ $USER != root]  && echo Y || echo N
#[[ ]]  ==为模式匹配，允许通配符，如*、？、[...]  =~才是正则匹配
[[ a == [a-z] ]] && echo Y || echo N
[[ a == [0-9] ]] && echo Y || echo N

name="welcome to Shenzhen"
[[ $name =~ w ]] && echo Y || echo N
[[ $name =~ [0-9] ]] && echo Y || echo N
#支持()
[[ a == a && (b == b || c == d) ]] && echo Y || echo N
#提示：if语句后面的条件测试语句不一定非要是test或[]测试语句，任何有返回值的命令都可以写在if语句后面，命令的返回值为0则为真，返回非0则为假
grep root /etc/passwd
grep ":..0:" /etc/passwd
grep "sbin/[^n]" /etc/passwd
grep "0\{1,2\}" /etc/passwd
grep "\(root\).*\1" /etc/passwd
grep "^$" /etc/passwd
grep -v "^$" /etc/passwd