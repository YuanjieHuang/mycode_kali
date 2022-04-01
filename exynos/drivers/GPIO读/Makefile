#!/bin/bash
obj-m += gpio_read.o 

KDIR := /home/yjie/exynos/android/iTop4412_Kernel_3.0

PWD ?= $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
		
clean:
	rm -rf .* *.ko *.o *.mod.c *.symvers *.order
