#include <linux/kernel.h>
#include <linux/module.h>

MODULE_DESCRIPTION("My kernel module: Version 2");
MODULE_AUTHOR("Michael Stefanioros");
MODULE_LICENSE("GPL");

static int my_init(void){
        printk("Module started\n");
        return 0;
}

static void my_exit(void){
        printk("Module ended\n");
}

module_init(my_init);
module_exit(my_exit);
