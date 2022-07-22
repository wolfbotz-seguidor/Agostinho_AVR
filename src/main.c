//#define FCPU  16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "macros.h"

void setup_timer0_interrupt(void)
{ 
  TCNT0  = 6;    //125us

  /*tempo =65536 * Prescaler/Fosc = 65536 * 1024/16000000 = 4, 19s
    tempo = X_bit_timer * Prescaler/Fosc
    Valor inicial de contagem = 256 - tempo_desejado*Fosc/Prescaler = 256 - 0,001*16000000/1024 = 255
    Valor inicial de contagem = X_bit_timer - tempo_desejado*Fosc/Prescaler */
}

void setup(void);
void loop(void);

int main()
{
  setup();
  while(1) loop();
  return 0;
}


void setup(void)
{
/* ======DEFINIÇÕES=====
entradas: A0, A1, A2, A3 PORTC || A6, A7 (sensores frontais) 
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
  DDRB  = 0b00000110;
  DDRC  = 0b00000000;
  PORTD = 0b10000111; //entrada pull-up, saída 1 on-off 
  PORTB = 0b11111001;
  PORTC = 0b11111111;
  
  TCCR0B = 0x02; // TC0 com prescaler de 8
  TCNT0  = 6;    // 125us
  TIMSK0 = 0x01; // habilita a interrupcao do TC0
  
  /*tempo =65536 * Prescaler/Fosc = 65536 * 1024/16000000 = 4, 19s
    tempo = X_bit_timer * Prescaler/Fosc
    Valor inicial de contagem = 256 - tempo_desejado*Fosc/Prescaler = 256 - 0,001*16000000/1024 = 255
    Valor inicial de contagem = X_bit_timer - tempo_desejado*Fosc/Prescaler */

  PWM_init();
  setup_pwm_setFreq(12);
  pwm_set_duty_service(15, 0);
}

void loop(void)
{
  /*
  
  mapeamento de pista
  leitura de sensores 

  */
}