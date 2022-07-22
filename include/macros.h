#include <avr/io.h>

#define set_bit(reg, bit)       (reg |=  (1<<bit))
#define clear_bit(reg, bit)     (reg &= ~(1<<bit))
#define toggle_bit(reg, bit)    (reg ^=  (1<<bit))
#define test_bit(reg, bit)      (reg &   (1<<bit))