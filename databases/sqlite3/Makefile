# 2、notdir:去掉目标的路径函数
# 经常可以看到这样用dir=$(notdir $(wildcard ./sub/*.c)),目的是去除掉./sub/ 路径
#$(<function> <arg1,...,argn>)\
$@指代当前目标\
$^ 指代所有前置条件，之间以空格分隔。\
$? 指代比目标更新的所有前置条件，之间以空格分隔。\
$< 指代第一个前置条件\
$(@D) 和 $(@F) 分别指向 $@ 的目录名和文件名。比如，$@是 src/input.c，那么$(@D) 的值为 src ，$(@F) 的值为 input.c。\
$(<D) 和 $(<F) 分别指向 $< 的目录名和文件名。 
src=$(wildcard *.c)
obj=$(patsubst %.c,%,$(src))

CC=gcc
RM= rm -f
CFLAGS= -lsqlite3

all:$(obj)
##将obj中所有无扩展名为的文件替换成扩展名为.c的文件
$(obj):%:%.c
	$(CC) $^ -o $@ $(CFLAGS) 

.PHONY: all clean

clean:
	$(RM) $(obj)