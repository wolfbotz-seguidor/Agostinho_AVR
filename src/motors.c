// motor direito AIN1 e AIN2  | motor esquerdo BIN1 e BIN2
//AIN1 5 - PD5
//AIN2 6 - PD6
//BIN1 4 - PD4 
//BIN2 3 - PD3

#include "motors.h"
#include "macros.h"

#define AIN1    PD5
#define AIN2    PD6
#define BIN1    PD4
#define BIN2    PD3

void frente()
{    
    set_bit(PORTD, AIN1);
    clear_bit(PORTD, AIN2);
    set_bit(PORTD, BIN1);
    clear_bit(PORTD, BIN2);
}
void tras()
{
    clear_bit(PORTD, AIN1);
    set_bit(PORTD, AIN2);
    clear_bit(PORTD, BIN1);
    set_bit(PORTD, BIN2);    
}
void freio()
{
    clear_bit(PORTD, AIN1);
    clear_bit(PORTD, AIN2);
    clear_bit(PORTD, BIN1);
    clear_bit(PORTD, BIN2);   
}

void girodireita(){  

    clear_bit(PORTD, AIN1);
    clear_bit(PORTD, AIN2);
    set_bit(PORTD, BIN1);
    clear_bit(PORTD, BIN2);
}

void giroesquerda(){
    
    set_bit(PORTD, AIN1);
    clear_bit(PORTD, AIN2);
    clear_bit(PORTD, BIN1);
    clear_bit(PORTD, BIN2);
}
