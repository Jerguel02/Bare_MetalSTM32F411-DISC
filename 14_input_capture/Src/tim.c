#include "tim.h"
#define TIM4EN		(1U<<2)
#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<12) | (1U<<13))
#define CCER_CC4E	(1U<<12)

#define GPIODEN		(1U<<3)
#define GPIOAEN		(1U<<0)

#define AFR15_TIM	(1U<<29)
#define AFR6_TIM	(1U<<25)
#define TIM3EN		(1U<<1)

#define CCER_CC1S	(1U<<0)
#define CCER_CC1E	(1U<<0)


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
void tim3_pa6_input_capture(void)
{
	//TIM3_CH1: PA6
	//Set enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//Set PA6 mode to alternate fuction
	GPIOA->MODER &=~ (1U<<12);
	GPIOA->MODER |= (1U<<13);
	//Set PA6 alternate functtion type to TIM3_CH1 (AF02)
	GPIOA->AFR[0] = AFR6_TIM;
	//Enable clock access to tim3
	RCC->APB1ENR |= TIM3EN;
	//Set prescaler
	TIM3->PSC = 16000 - 1; //16000000/16000
	//Set CH1 to input capture
	TIM3->CCMR1 = CCER_CC1S;
	//Set CH1 to capture rising edge
	TIM3->CCER = CCER_CC1E;
	//Enable TIM3
	TIM3->CR1 = CR1_CEN;
}
