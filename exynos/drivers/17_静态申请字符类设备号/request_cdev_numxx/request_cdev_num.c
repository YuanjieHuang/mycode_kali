#include <linux/init.h>
/*包含初始化宏定义的头文件,代码中的module_init和module_exit在此文件中*/
#include <linux/module.h>
/*包含初始化加载模块的头文件,代码中的MODULE_LICENSE在此头文件中*/

/*定义module_param module_param_array的头文件*/
#include <linux/moduleparam.h>
/*定义module_param module_param_array中perm的头文件*/
#include <linux/stat.h>

/*定义字符设备的结构体，注册设备号的函数*/
#include <linux/cdev.h>
/*MKDEV转换设备号数据类型的宏定义*/
#include <linux/kdev_t.h>
/*字符设备注册函数*/
#include <linux/fs.h>

MODULE_LICENSE("Dual BSD/GPL");
/*声明是开源的，没有内核版本限制*/
MODULE_AUTHOR("iTOPEET_dz");
/*声明作者*/


#define DEVICE_NAME "scdev"
#define DEVICE_MINOR_NUM 2
#define DEV_MAJOR 0
#define DEV_MINOR 2


int numdev_major,numdev_minor;


int numdev_major = DEV_MAJOR;	/* 定义主设备号 */
int numdev_minor = DEV_MINOR;	/* 定义次设备号 */


/* 主设备号设置为模块参数 */
module_param(numdev_major,int,S_IRUSR);
/* 次设备号设置为模块参数 */
module_param(numdev_minor,int,S_IRUSR);

static int hello_init(void)
{
	int ret= 0;
	/*声明设备号*/
	dev_t num_dev;
	
	printk(KERN_EMERG "numdev_major is %d!\n",numdev_major);
	printk(KERN_EMERG "numdev_minor is %d!\n",numdev_minor);
	
	if(numdev_major){
		/*获得设备号*/
		num_dev = MKDEV(numdev_major,numdev_minor);
		/*静态注册设备号*/
		ret = register_chrdev_region(num_dev, DEVICE_MINOR_NUM, DEVICE_NAME);
	}
	else{
		printk(KERN_EMERG "numdev_major %d is failed!\n",numdev_major);
	}
	
	if(ret<0){
		printk(KERN_EMERG "req numdev_major %d is failed!\n",numdev_major);	
		return 0;		
	}
	
	printk(KERN_EMERG "Hello World enter!\n");
	/*打印信息，KERN_EMERG表示紧急信息*/
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_EMERG "Hello world exit!\n");
	unregister_chrdev_region(MKDEV(numdev_major,numdev_minor), DEVICE_MINOR_NUM);
}


module_init(hello_init);
/*初始化函数*/
module_exit(hello_exit);
/*卸载函数*/