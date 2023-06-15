#include "adc.h"
#include "systick.h"
#include "tim.h"
#define GPIODEN		(1U<<3)
#define PIN13_LED	(1U<<13)

int main(void)
{
	RCC->AHB1ENR |= GPIODEN;
	GPIOD->MODER |= (1U<<26);
	GPIOD->MODER &=~ (1U<<27);
	tim2_1hz_init();
	while (1)
	{
		//wait for UIF
		while (TIM2->SR & SR_UIF);
		//Clear UIF
		TIM2->SR &=~ SR_UIF;
		GPIOD->ODR ^= PIN13_LED;
		systickDelayms(1000);

	}
}
