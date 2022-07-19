// motor direito AIN1 e AIN2  | motor esquerdo BIN1 e BIN2
//AIN1 5 - PD5
//AIN2 6 - PD6
//BIN1 4 - PD4 
//BIN2 3 - PD3

#include "motors.h"

void frente(){
    
    set_outputs_service(AIN1);
    clear_outputs_service(AIN2);
    set_outputs_service(BIN1);
    clear_outputs_service(BIN2);

}
void tras(){
    
    clear_outputs_service(AIN1);
    set_outputs_service(AIN2);
    clear_outputs_service(BIN1);
    set_outputs_service(BIN2);

}
void freio(){
    
    clear_outputs_service(AIN1);
    clear_outputs_service(AIN2);
    clear_outputs_service(BIN1);
    clear_outputs_service(BIN2);
}

void girodireita(){  
    
    clear_outputs_service(AIN1);
    clear_outputs_service(AIN2);
    set_outputs_service(BIN1);
    clear_outputs_service(BIN2);

}

void giroesquerda(){
    
    set_outputs_service(AIN1);
    clear_outputs_service(AIN2);
    clear_outputs_service(BIN1);
    clear_outputs_service(BIN2);

}
