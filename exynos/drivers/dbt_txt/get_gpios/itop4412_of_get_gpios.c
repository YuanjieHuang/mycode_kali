#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_gpio.h>

#include <linux/miscdevice.h>
#include <linux/fs.h>

#define DRIVER_NAME "leds_test"

int gpio_pin[2] = {-1};

static int leds_probe(struct platform_device * pdev)
{
	struct device_node *node = pdev->dev.of_node;
	int ret;
	
	printk("led init\n");
	
	gpio_pin[0] = of_get_named_gpio(node, "gpios1", 0);
	gpio_pin[1] = of_get_named_gpio(node, "gpios2", 0);
	
	ret = gpio_request(gpio_pin[0], "led1");
	if(ret!=0){
		printk("gpio_pin[0] request %d failed.", gpio_pin[0]);
		return ret;
	}
	if (gpio_pin[1] < 0)
        printk("gpio_pin[1] is not available \n");
	ret = gpio_request(gpio_pin[1], "led2");
	if(ret!=0){
		printk("gpio_pin[1] request %d failed.", gpio_pin[1]);
		return ret;
	}
	printk("gpio_pin[0] is %d\n",gpio_pin[0]);
	printk("gpio_pin[1] is %d\n",gpio_pin[1]);
	
	
	gpio_free(gpio_pin[0]);
	gpio_free(gpio_pin[1]);
	
	gpio_direction_output(gpio_pin[0],0);
	gpio_set_value(gpio_pin[0], 1);
	
	gpio_direction_output(gpio_pin[1],0);
	gpio_set_value(gpio_pin[1], 1);
	
	 
	return 0;
}

static int leds_remove(struct platform_device * pdev)
{
	printk(KERN_ALERT "Goodbye, curel world, this is remove\n");
	return 0;
}

static const struct of_device_id of_leds_dt_match[] = {
	{.compatible = DRIVER_NAME},
	{},
};

MODULE_DEVICE_TABLE(of,of_leds_dt_match);

static struct platform_driver leds_driver = {
	.probe 	= leds_probe,
	.remove = leds_remove,
	.driver = {
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
		.of_match_table = of_leds_dt_match,
		},
};

static int leds_init(void)
{
	printk(KERN_ALERT "Hello, world\n");
	return platform_driver_register(&leds_driver);
	return 0;
}

static void leds_exit(void)
{
	printk(KERN_ALERT "Goodbye, curel world\n");
	platform_driver_unregister(&leds_driver);
}

module_init(leds_init);
module_exit(leds_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("rty");
MODULE_DESCRIPTION("topeet4412_regiter_dev_drv");
