#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ITeodora");
MODULE_DESCRIPTION("Proba");
MODULE_VERSION("0.1");

static int __init atlas_adc_init(void) {
    printk(KERN_INFO "Pokrece se init...\n");
    return 0; // 0 znači da je modul uspešno učitan
}

static void __exit atlas_adc_exit(void) {
    printk(KERN_INFO "Gasi se...\n");
}

module_init(atlas_adc_init);
module_exit(atlas_adc_exit);