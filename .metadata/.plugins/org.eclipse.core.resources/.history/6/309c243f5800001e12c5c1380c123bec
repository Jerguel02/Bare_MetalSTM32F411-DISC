#include "adc.h"


#define GPIOAEN		(1U<<0)
#define ADC1EN 		(1U<<8)
#define ADC_CH1		(1U<<0)
#define ADC_SEQ_LEN_1  0x00
#define CR2_ADON		(1U<<0)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)
//3 channel adc config with 3 channel
//ch2 ch3 ch5
//1st =ch5
//2nd = ch2
//3th = ch3
void pa1_adc_init(void)
{
	//enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//set the mode of PA1 to analog
	GPIOA->MODER |=(1U<<2);
	GPIOA->MODER |=(1U<<3);

	//enable clock access to adc
	RCC->APB2ENR |= ADC1EN;
	//Convertion sequence start
	ADC1->SQR3 =ADC_CH1;
	//Convertion sequence length
	ADC1->SQR1 = ADC_SEQ_LEN_1;
	//Enable ADC module
	ADC1->CR2 = CR2_ADON;
}

void adc_start_convertion(void)
{
	//Start convertion
	ADC1->CR2 |= CR2_SWSTART;
}

uint32_t adc_read(void)
{
	//wait for convertion to be complete
	if (!(ADC1->SR & SR_EOC));
	//Read convert result
	return (ADC1 -> DR);
}
