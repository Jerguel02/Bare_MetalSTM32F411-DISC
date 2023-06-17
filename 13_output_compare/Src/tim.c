#include "tim.h"
#define TIM4EN		(1U<<2)
#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<12) | (1U<<13))
#define CCER_CC4E	(1U<<12)
#define GPIODEN		(1U<<3)
#define AFR15_TIM	(1U<<29)



void tim4_1hz_init(void)
{
	//Enable clock access to tim2
	RCC->APB1ENR |= TIM4EN;

	//Set prescalder value
	TIM4->PSC = 1600 - 1;//16MHz/1600 = 10kHz

	//Set auto-reload value
	TIM4->ARR = 10000 - 1;//10000/10000 = 1

	//CLear counter
	TIM4->CNT = 0;
	//Enable timer
	TIM4->CR1 = CR1_CEN;
}
void tim4_pd15_output_compare(void)
{
	//Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIODEN;

	//Set PD15 mode to alternate function
	GPIOD->MODER &= ~(1U<<30);
	GPIOD->MODER |= (1U<<31);
	//Set PD15 alternate function type to TIM2_CH1 (AF01)
	GPIOD->AFR[1] |= AFR15_TIM;

	//Enable clock access to tim4
	RCC->APB1ENR |= TIM4EN;

	//Set prescalder value
	TIM4->PSC = 1600 - 1;//16MHz/1600 = 10kHz

	//Set auto-reload value
	TIM4->ARR = 10000 - 1;//10000/10000 = 1
	//Set output compare toggle mode
	//CAPTURE COMPARE MODE REG
	TIM4->CCMR2 = OC_TOGGLE;
	//CAPTURE/COMPARE ENABLE REG
    //Enable tim4 ch4 in compare mode
	TIM4->CCER |= CCER_CC4E;
	//CLear counter
	TIM4->CNT = 0;
	//Enable timer
	TIM4->CR1 = CR1_CEN;
}
