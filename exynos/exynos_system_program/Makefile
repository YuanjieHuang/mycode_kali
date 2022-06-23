src=$(wildcard *.c)
obj=$(patsubst %.c,%,$(src))

# PRE=arm-none-linux-gnueabi-
CC=$(PRE)gcc
RM= rm -f
CFLAGS= -lm -w -lpthread

all:$(obj)
##将obj中所有无扩展名为的文件替换成扩展名为.c的文件
$(obj):%:%.c
	$(CC) $^ -o $@ $(CFLAGS) 

.PHONY: all clean

clean:
	$(RM) $(obj)