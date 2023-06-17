#include "adc.h"
#include "systick.h"
#include "tim.h"
#define GPIODEN		(1U<<3)
#define PIN13_LED	(1U<<13)

int main(void)
{
	tim4_pd15_output_compare();
	while (1)
	{

	}
}
