#include "tim.h"
#define TIME2EN		(1U<<0)
#define CR1_CEN		(1U<<0)

void tim2_1hz_init(void)
{
	//Enable clock access to tim2
	RCC->AHB1ENR |= TIME2EN;

	//Set prescaler value (PRESCALER)
	TIM2->PSC = 1600 - 1;//16MHz/1600 = 10kHz

	//Set auto-reload value (AUTO RELOAD REG)
	TIM2->ARR = 10000 - 1;//10000/10000 = 1

	//CLear counter (COUNTER)
	TIM2->CNT = 0;
	//Enable timer (CONTROL REGISTER)
	TIM2->CR1 = CR1_CEN;
}
