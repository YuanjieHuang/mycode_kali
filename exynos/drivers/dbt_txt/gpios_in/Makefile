#!/bin/bash
export ARCH=arm
obj-m += itop4412_of_gpio_in.o 

KDIR := /home/tree-4412/itop4412_kernel_4_14_2_bsp/linux-4.14.2_iTop-4412_scp

PWD ?= $(shell pwd)
all:
	make -C $(KDIR) M=$(PWD) modules
		
clean:
	rm -rf .* *.ko *.o *.mod.c *.symvers *.order
