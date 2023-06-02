#include "adc.h"

uint32_t read_adc;
int main(void)
{
	pa1_adc_init();


	while (1)
	{
		adc_start_convertion();
		read_adc = adc_read();

	}
}
