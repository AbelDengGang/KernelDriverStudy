#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>


MODULE_AUTHOR("Alessandro Rubini, Jonathan Corbet");
MODULE_LICENSE("Dual BSD/GPL");

static int hello_major;
static int hello_minor = 3;
static int hello_devs = 4;

int __init hello_init(void)
{
    int result;
    dev_t dev= 0;
    
    printk(KERN_NOTICE "hello_init\n");
    result = alloc_chrdev_region(&dev, hello_minor, hello_devs,
            "hello");
    hello_major = MAJOR(dev);
    printk(KERN_EMERG "hello_major = %d\n",hello_major);

	return 0;

}

void hello_exit(void)
{
    printk(KERN_NOTICE "hello_exit\n");
    dev_t dev=0;
    dev=MKDEV(hello_major,hello_minor);
    unregister_chrdev_region(dev,hello_devs);
}


module_init(hello_init);
module_exit(hello_exit);



