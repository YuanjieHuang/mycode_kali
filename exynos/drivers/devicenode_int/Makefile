#!/bin/bash
obj-m += devicenode_int.o 

KDIR := /home/topeet/android4.0/iTop4412_Kernel_3.0

PWD ?= $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
		
#make clean执行的操作是删除后缀为o的文件
clean:
	rm -rf .* *.ko *.o *.mod.c *.symvers *.order
