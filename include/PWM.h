#include <avr/io.h>
#define PWM_CHANNEL_1 1
#define PWM_CHANNEL_2 2

void setup_pwm_setFreq(char option);
void pwm_set_duty_service(unsigned int duty, unsigned char channel);
void PWM_init(void);