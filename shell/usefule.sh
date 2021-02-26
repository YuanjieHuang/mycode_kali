#!/bin/bash
# find .. -name "*.out" |xargs -i rm {} 
find .. -iname '*.o' |xargs -i cp {} .
# mkdir ./bak && find . -name "*.c" |xargs -i cp {} ./bak
find .. |egrep '\.o$' |wc

git status | grep deleted | awk '{print $2}'
git rm `git status | grep deleted | awk '{print $2}'`
git add -u
