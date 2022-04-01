#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>

#define DEVICE_NAME "hello_ctl123"
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("TOPEET");

static long hello_ioctl( struct file *files, unsigned int cmd, unsigned long arg)
{
	printk("cmd is %d,arg is %d\n",cmd,arg);
	return 0;
}

static int hello_release(struct inode *inode, struct file *file)
{
	printk(KERN_EMERG "hello release\n");
	return 0;
}

static int hello_open(struct inode *inode, struct file *file)
{
	printk(KERN_EMERG "hello open\n");
	return 0;
}

static struct file_operations hello_ops = {
	.owner = THIS_MODULE,
	.open = hello_open,
	.release = hello_release,
	.unlocked_ioctl = hello_ioctl,
};

static  struct miscdevice hello_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &hello_ops,
};

static int hello_init(void)
{
	printk(KERN_EMERG "HELLO WORLD enter!\n");
	misc_register(&hello_dev);
	
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_EMERG "HELLO WORLD exit!\n");
	misc_deregister(&hello_dev);	
}

module_init(hello_init);
module_exit(hello_exit);
