#include "adc.h"
#include "systick.h"
#include "tim.h"
#define GPIODEN		(1U<<3)
#define PIN13_LED	(1U<<13)

int timestamp = 0;
//connect a bus wire from PD15 to PA6
int main(void)
{
	tim4_pd15_output_compare();
	tim3_pa6_input_capture();
	while (1)
	{
		//Wait until edge is capture
		while (!(TIM3->SR & SR_CC1IF))
		{

		}
		//Read Value
		timestamp = TIM3->CCR1;

	}
}
