#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Michael Stefanioros");
MODULE_DESCRIPTION("A simple kernel module that allocates and frees memory");

static char *memory;

static int my_init(void){
    // Dynamic memory allocation using kmalloc
    memory = kmalloc(4096, GFP_KERNEL);
    if (!memory) {
        return -ENOMEM;
    }

    printk(KERN_INFO "Allocated memory: %p\n", memory);
    printk(KERN_INFO "Memory contents: %s\n", memory);

    return 0;
}

static void my_exit(void){
    // Free the allocated memory
    kfree(memory);
    printk(KERN_INFO "Freed memory\n");
}

module_init(my_init);
module_exit(my_exit);