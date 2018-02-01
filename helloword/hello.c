#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

int hello_init(void)
{
	printk(KERN_EMERG"Hello world!\n");
	return 0;

}

void hello_exit(void)
{
	printk(KERN_EMERG "GOODBY ,cruel world\n");
}


module_init(hello_init);
module_exit(hello_exit);


