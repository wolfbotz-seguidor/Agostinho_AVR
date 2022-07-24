#include <avr/io.h>

#define set_bit(reg, bit)       (reg |=  (1<<bit)) //OR
#define clear_bit(reg, bit)     (reg &= ~(1<<bit)) //AND
#define toggle_bit(reg, bit)    (reg ^=  (1<<bit)) // XOR
#define test_bit(reg, bit)      (reg &   (1<<bit)) // AND para fazer a leitura do pino que queremos