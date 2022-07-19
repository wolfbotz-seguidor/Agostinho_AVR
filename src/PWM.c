#include "PWM.h"

void PWM_init(void)
{
  TCCR1A = 0xA3; //Configura operacao em fast PWM, utilizando registradores OCR1x para comparacao

}

void setup_pwm_setFreq(char option) 
{
    /*
    TABLE:
  	//no fast Mode
        option  frequency (as frequências no timer 1 são menores do que as frequências nos timers 0 e 2)
        
          9      16    kHz
          10       2    kHz
          11     250     Hz
          12     62,5    Hz
          13     15,6    Hz 
     */
    TCCR1B = option;
	
    /*
    TABLE:
  	//no phase corret PWM Mode
        option  frequency (as frequências no timer 1 são menores do que as frequências nos timers 0 e 2)
        
          9       8     kHz
          10       1     kHz
          11     125      Hz
          12     31,25    Hz
          13     7,8      Hz
     */
}

void pwm_set_duty_service(unsigned int duty, unsigned char channel)
{   
  if (channel == 1)
  {
      OCR1A = duty; //valores de 0 - 1023
      return;
  }
  OCR1B = duty; //registrador de PWM do OC1B
}
