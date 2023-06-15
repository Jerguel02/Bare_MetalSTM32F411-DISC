#include "uart.h"

#define GPIODEN			(1U<<3)
#define GPIOAEN			(1U<<0)
#define PIN13_LED_ON	(1U<<13)
#define PIN13_LED_OFF 	(1U<<29)
#define PIN0_INPUT		(1U<<0)


int main(void)
{
	char key;
	RCC->AHB1ENR |= GPIODEN;
	RCC->AHB1ENR |= GPIOAEN;
	GPIOD->MODER |= (1U<<26);
	GPIOD->MODER &=~ (1U<<27);
	GPIOA->MODER &=~ (1U<<0);
	GPIOA->MODER &=~ (1U<<1);
	uart1_tx_rx_init();
	while (1)
	{
		key = uart1_read();
		if (key == '1')
		{

			GPIOD->BSRR = PIN13_LED_ON;


		}
		else
		{

			GPIOD->BSRR = PIN13_LED_OFF;

		}


	}
}
