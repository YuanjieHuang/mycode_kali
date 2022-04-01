#!/bin/bash
obj-m += ch34x.o 
KDIR := /home/topeet/android4.0/iTop4412_Kernel_3.0
PWD ?= $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
		
clean:
	rm -rf *.mod.c *.o *.order *.ko *.mod.o *.symvers
