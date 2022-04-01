#include <linux/init.h>
/*包含初始化宏定义的头文件,代码中的module_init和module_exit在此文件中*/
#include <linux/module.h>
/*包含初始化加载模块的头文件,代码中的MODULE_LICENSE在此头文件中*/

/*定义module_param module_param_array的头文件*/
#include <linux/moduleparam.h>
/*定义module_param module_param_array中perm的头文件*/
#include <linux/stat.h>

/*三个字符设备函数*/
#include <linux/fs.h>
/*MKDEV转换设备号数据类型的宏定义*/
#include <linux/kdev_t.h>
/*定义字符设备的结构体*/
#include <linux/cdev.h>

#define DEVICE_NAME "ascdev"
#define DEVICE_MINOR_NUM 2
#define DEV_MAJOR 0
#define DEV_MINOR 0

MODULE_LICENSE("Dual BSD/GPL");
/*声明是开源的，没有内核版本限制*/
MODULE_AUTHOR("iTOPEET_dz");
/*声明作者*/

int numdev_major = DEV_MAJOR;
int numdev_minor = DEV_MINOR;

/*输入主设备号*/
module_param(numdev_major,int,S_IRUSR);
/*输入次设备号*/
module_param(numdev_minor,int,S_IRUSR);


static int scdev_init(void)
{
	int ret = 0;
	dev_t num_dev;
	
	
	printk(KERN_EMERG "numdev_major is %d!\n",numdev_major);
	printk(KERN_EMERG "numdev_minor is %d!\n",numdev_minor);
	
	if(numdev_major){
		num_dev = MKDEV(numdev_major,numdev_minor);
		ret = register_chrdev_region(num_dev,DEVICE_MINOR_NUM,DEVICE_NAME);
	}
	else{
		/*动态注册设备号*/
		ret = alloc_chrdev_region(&num_dev,numdev_minor,DEVICE_MINOR_NUM,DEVICE_NAME);
		/*获得主设备号*/
		numdev_major = MAJOR(num_dev);
		printk(KERN_EMERG "adev_region req %d !\n",numdev_major);
	}
		
	if(ret<0){
		printk(KERN_EMERG "register_chrdev_region req %d is failed!\n",numdev_major);		
	}
		
	printk(KERN_EMERG "scdev_init!\n");
	/*打印信息，KERN_EMERG表示紧急信息*/
	return 0;
}

static void scdev_exit(void)
{
	printk(KERN_EMERG "scdev_exit!\n");
	unregister_chrdev_region(MKDEV(numdev_major,numdev_minor),DEVICE_MINOR_NUM);
}


module_init(scdev_init);
/*初始化函数*/
module_exit(scdev_exit);
/*卸载函数*/