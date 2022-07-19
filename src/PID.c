#include "PID.h"

#define ANGULAR 0
#define LINEAR  1
#define NUMERO_DE_TRECHOS 1

void acoes_de_controle(uint8_t trecho, float *proporcional, float *integral, float *derivativo, int16_t error, int8_t dado);

float kp_ang[NUMERO_DE_TRECHOS] = {0.2580}, 
      ki_ang[NUMERO_DE_TRECHOS] = {0.000000},
      kd_ang[NUMERO_DE_TRECHOS] = {0.000820};

float kp_line[NUMERO_DE_TRECHOS], kd_line[NUMERO_DE_TRECHOS], ki_line[NUMERO_DE_TRECHOS];

int16_t PID(uint8_t trecho, int16_t error, int8_t dado) /* Algoritmo de controle PID usando os sensores frontais */
{   
    int16_t correcao = 0;

    static float  proporcional = 0;
    static float  integral     = 0;
    static float  derivativo   = 0;

    acoes_de_controle(trecho, &proporcional, &integral, &derivativo, error, dado);
    correcao = (proporcional + integral + derivativo);
    
    return correcao; 

} /* end PID */

void acoes_de_controle(uint8_t trecho, float *proporcional, float *integral, float *derivativo, int16_t error, int8_t dado)
{
    static int16_t erroAnterior     = 0;
    static int16_t acao_integrativa = 0;
    static int16_t acao_derivativa  = 0; 

    acao_integrativa += error;
    
    acao_derivativa = error - erroAnterior;
    erroAnterior    = error;  
    /*if(acao_integrativa >  500)   acao_integrativa =  500;
    else if(acao_integrativa < -500)   acao_integrativa = -500;*/
    
    if(dado == ANGULAR)
    {
        *proporcional = (kp_ang[trecho]*error);  
        *integral     = (ki_ang[trecho]*acao_integrativa);
        *derivativo   = (kd_ang[trecho]*acao_derivativa);
    }

    else if(dado == LINEAR)
    {
        *proporcional = (kp_line[trecho]*error);  
        *integral     = (ki_line[trecho]*acao_integrativa);
        *derivativo   = (kd_line[trecho]*acao_derivativa);
    }
    
}