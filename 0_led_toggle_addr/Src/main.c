//STM32F411E_DISC
//LED: PD13
//Code base on Reference Manual

#define PERIPH_BASE			(0x40000000UL)

#define AHB1PERIPH_OFFSET	(0x00020000UL)
#define AHB1PERIPH_BASE		(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOD_OFFSET		(0x0C00UL)
#define GPIOD_BASE			(AHB1PERIPH_BASE + GPIOD_OFFSET)

#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int*)(RCC_BASE + AHB1EN_R_OFFSET))

#define GPIODEN				(1U<<3)
#define MODE_R_OFFSET		(0x00UL)
#define GPIOD_MODE_R		(*(volatile unsigned int*)(GPIOD_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET			(0x14UL)
#define GPIOD_OD_R			(*(volatile unsigned int*)(GPIOD_BASE + OD_R_OFFSET))

#define PIN13_LED			(1U<<13)
//Set PA6 Output: MODER6[0:1] -> |= (1U<<12); &=~(1U<<13)

int main(void)
{
	RCC_AHB1EN_R |= GPIODEN;
	GPIOD_MODE_R |= (1U<<26);
	GPIOD_MODE_R &=~(1U<<27);
	while (1)
	{
		GPIOD_OD_R ^= PIN13_LED;
		for (int i = 0; i<1000000; i++);
	}

}
