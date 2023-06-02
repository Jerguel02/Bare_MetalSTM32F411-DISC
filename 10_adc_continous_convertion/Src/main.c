#include "adc.h"

uint32_t read_adc;
int main(void)
{
	pa1_adc_init();
	adc_start_convertion();

	while (1)
	{

		read_adc = adc_read();

	}
}
