//#define FCPU  16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "macros.h"
#include "PWM.h"

// atmega328p
/*tempo =65536 * Prescaler/Fosc = 65536 * 1024/16000000 = 4, 19s
    tempo = X_bit_timer * Prescaler/Fosc
    Valor inicial de contagem = 256 - tempo_desejado*Fosc/Prescaler = 256 - 0,001*16000000/1024 = 255
    Valor inicial de contagem = X_bit_timer - tempo_desejado*Fosc/Prescaler */

uint16_t PWMGeral;
uint8_t tempo_max1, tempo_max2;

// PROTÓTIPOS DAS FUNÇÕES
void setup(void);
void loop(void);
void contadores(void); 
void contador1(void);
void contador2(void);

ISR(PCINT1_vect){

}

ISR(TIMER0_OVF_vect) // rotina de interrupção
{ 
  TCNT0  = 6;    //125us
  contadores();
  //funcao contador
    /*
  
  mapeamento de pista
  leitura de sensores 

  */
}

int main()
{
  setup();
  while(1) loop();
  return 0;
}


void setup(void)
{
/* ======DEFINIÇÕES=====
entradas: A0, A1, A2, A3,  PORTC || A6, A7 (sensores frontais) 
          A4 (sensor de curva)
          A5 (sensor lateral de parada)
saídas: =PonteH=
        AIN1 5 - PD5
        AIN2 6 - PD6
        BIN1 4 - PD4
        BIN2 3 - PD3
        ==PWM==
        A 9   - PB1
        B 10  - PB2
*/
  DDRD  = 0b01111000;
  DDRB  = 0b00000110; // o pino que vai ser de PWM será de saída 
  DDRC  = 0b00000000; // tudo é entrada pq é sensor
  PORTD = 0b00000000; // 
  PORTB = 0b00000000; 
  PORTC = 0b00110000; // Pull up nos pinos PC4 e PC5 estão ativados
  
  TCCR0B = 0x02; // TC0 com prescaler de 8
  TCNT0  = 6;    // 125us 
  TIMSK0 = 0x01; // habilita a interrupcao do TC0
  PCICR =  0b00000010; // habita o PCINT1
  PCMSK1 = 0b00110000; // habilita o PCINT13 e PCINT12 

  PWM_init(); // define as portas 9 e 10 como PWM rápido de 10 bits
  setup_pwm_setFreq(12); // 62,5 Hz
  
  tempo_max1 = 2; // base de 125us (250us);
  tempo_max2 = 4; // base de 125us (500us);

  sei(); // habilita todas as interrupções previamente configuradas
}

void loop(void)
{
  //vazio
  //utilizar somente para funcoes de baixa prioridade!!!!!!!
}
void contadores(void){

  static uint8_t qnt_tempo1 = 1, qnt_tempo2 = 1;
    
    if(qnt_tempo1 < tempo_max1) qnt_tempo1++;

    else
    {
        contador1();
        qnt_tempo1 = 1;

    }

    if(qnt_tempo2 < tempo_max2) qnt_tempo2++;

    else
    {
        contador2();
        qnt_tempo2 = 1;    

    }
   
}
 void contador1(){

 }
 void contador2(){


 }