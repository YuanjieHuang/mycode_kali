src=$(wildcard *.c)
obj=$(patsubst %.c,%,$(src))
obj:=$(filter-out binaryTree, $(obj))
#VPATH = src


CC=gcc
CXX=g++
RM= rm -f
CFLAGS= -lm -w -I include

all:binaryTree.o $(obj) 
##将obj中所有无扩展名为的文件替换成扩展名为.c的文件
$(obj):%:%.c
	$(CC) binaryTree.o $^ -o $@ $(CFLAGS) 

.PHONY: all clean

binaryTree.o: 
	$(CXX) -c binaryTree.c

clean:
	$(RM) $(obj)
show:
	echo $(obj)