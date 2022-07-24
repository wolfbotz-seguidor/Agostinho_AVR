#include "PID.h"

void acoes_de_controle(float *proporcional, float *integral, float *derivativo, int16_t error);

float kp_ang = {0.2580}, 
      ki_ang = {0.000000},
      kd_ang = {0.000820};

int16_t PID(int16_t error) /* Algoritmo de controle PID usando os sensores frontais */
{   
    int16_t correcao = 0;

    static float  proporcional = 0;
    static float  integral     = 0;
    static float  derivativo   = 0;

    acoes_de_controle(&proporcional, &integral, &derivativo, error);
    correcao = (proporcional + integral + derivativo);
    
    return correcao; 

} /* end PID */

void acoes_de_controle(float *proporcional, float *integral, float *derivativo, int16_t error)
{
    static int16_t erroAnterior     = 0;
    static int16_t acao_integrativa = 0;
    static int16_t acao_derivativa  = 0; 

    acao_integrativa += error;
    
    acao_derivativa = error - erroAnterior;
    erroAnterior    = error;
    

    *proporcional = (kp_ang*error);  
    *integral     = (ki_ang*acao_integrativa);
    *derivativo   = (kd_ang*acao_derivativa);
}