#include "adc.h"
#include "systick.h"
#define GPIODEN		(1U<<3)
#define PIN13_LED	(1U<<13)

int main(void)
{
	RCC->AHB1ENR |= GPIODEN;
	GPIOD->MODER |= (1U<<26);
	GPIOD->MODER &=~ (1U<<27);

	while (1)
	{

		GPIOD->ODR ^= PIN13_LED;
		systickDelayms(1000);

	}
}
