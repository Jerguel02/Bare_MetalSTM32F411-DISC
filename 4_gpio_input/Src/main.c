#include "stm32f4xx.h"


#define GPIODEN			(1U<<3)
#define GPIOAEN			(1U<<0)
#define PIN13_LED_ON	(1U<<13)
#define PIN13_LED_OFF 	(1U<<29)
#define PIN0_INPUT		(1U<<0)



int main(void)
{
	RCC->AHB1ENR |= GPIODEN;
	RCC->AHB1ENR |= GPIOAEN;
	GPIOD->MODER |= (1U<<26);
	GPIOD->MODER &=~ (1U<<27);
	GPIOA->MODER &=~ (1U<<0);
	GPIOA->MODER &=~ (1U<<1);
	while (1)
	{
		if (GPIOA->IDR & PIN0_INPUT)
			GPIOD->BSRR = PIN13_LED_ON;
//		for (int i=0; i<1000000; i++);
		else
			GPIOD->BSRR = PIN13_LED_OFF;
//		for (int i=0; i<1000000; i++);
	}
}

