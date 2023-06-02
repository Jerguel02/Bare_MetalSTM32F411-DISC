#include "stm32f4xx.h"


#define GPIODEN			(1U<<3)
#define PIN13_LED_ON	(1U<<13)
#define PIN13_LED_OFF 	(1U<<29)




int main(void)
{
	RCC->AHB1ENR |= GPIODEN;
	GPIOD->MODER |= (1U<<26);
	GPIOD->MODER &=~ (1U<<27);

	while (1)
	{
		GPIOD->BSRR = PIN13_LED_ON;
		for (int i=0; i<1000000; i++);
		GPIOD->BSRR = PIN13_LED_OFF;
		for (int i=0; i<1000000; i++);
	}
}

