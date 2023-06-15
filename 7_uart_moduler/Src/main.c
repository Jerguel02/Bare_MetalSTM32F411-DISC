#include "uart.h"



int main(void)
{

	uart1_tx_init();
	while (1)
	{

		printf("Hello!...\r\n");
		for (int i=0; i<100000; i++);

	}
}
