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
