#include <linux/init.h>
#include <linux/module.h>


MODULE_AUTHOR("Alessandro Rubini, Jonathan Corbet");
MODULE_LICENSE("Dual BSD/GPL");


int hello_init(void)
{
    printk(KERN_NOTICE "hello_init\n");
	return 0;

}

void hello_exit(void)
{
    printk(KERN_NOTICE "hello_exit\n");
}


module_init(hello_init);
module_exit(hello_exit);



