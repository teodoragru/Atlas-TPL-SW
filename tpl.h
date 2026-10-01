// tpl.h
struct tpl_dac_info {
    int channel;
    int addr;
    int led_addr;
    int vref;
    int init_val;
};

struct tplcfg {
    struct tpl_dac_info dac_info;
    // Sutra ovde dodaješ info za LVDT, IEPE itd.
};