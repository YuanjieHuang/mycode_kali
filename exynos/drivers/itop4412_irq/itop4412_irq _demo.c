/*以后写驱动可以讲头文件一股脑的加载代码前面*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <mach/gpio.h>
#include <plat/gpio-cfg.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <mach/regs-gpio.h>
#include <asm/io.h>
#include <linux/regulator/consumer.h>
#include <linux/delay.h>

/*中断函数头文件*/
#include <linux/interrupt.h>
#include <linux/irq.h>

#define IRQ_DEBUG
#ifdef IRQ_DEBUG
#define DPRINTK(x...) printk("IRQ_CTL DEBUG:" x)
#else
#define DPRINTK(x...)
#endif

#define DRIVER_NAME "irq_test"

static int irq_probe(struct platform_device *pdev)
{
        int ret;
        char *banner = "irq_test Initialize\n";

        printk(banner);

        return 0;

exit:
        return ret;
}

static int irq_remove (struct platform_device *pdev)
{
	
		return 0;
}

static int irq_suspend (struct platform_device *pdev, pm_message_t state)
{
        DPRINTK("irq suspend:power off!\n");
        return 0;
}

static int irq_resume (struct platform_device *pdev)
{
        DPRINTK("irq resume:power on!\n");
        return 0;
}

static struct platform_driver irq_driver = {
        .probe = irq_probe,
        .remove = irq_remove,
        .suspend = irq_suspend,
        .resume = irq_resume,
        .driver = {
                .name = DRIVER_NAME,
                .owner = THIS_MODULE,
        },
};

static void __exit irq_test_exit(void)
{
		platform_driver_unregister(&irq_driver);
}

static int __init irq_test_init(void)
{
        return platform_driver_register(&irq_driver);
}

module_init(irq_test_init);
module_exit(irq_test_exit);

MODULE_LICENSE("Dual BSD/GPL");