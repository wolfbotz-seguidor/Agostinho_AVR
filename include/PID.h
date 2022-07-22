#ifndef PID_H
#define PID_H

#define FRONTAIS 0
#define ENCODERS 1
#include <stdint.h>

int16_t PID(int16_t error); /* Algoritmo de controle PID usando os sensores frontais */

#endif