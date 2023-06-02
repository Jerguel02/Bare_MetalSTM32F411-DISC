
#ifndef UART_H_
#define UART_H_
#include "stm32f4xx.h"
#include "stdio.h"
#include "stdint.h"
#define GPIOAEN		(1U<<0)
#define UART1EN		(1U<<4)

#define CR1_TE		(1U<<3)
#define CR1_UE		(1U<<13)
#define CR1_RE		(1U<<2)
#define SR_TXE		(1U<<7)
#define SR_RNXE		(1U<<5)

#define SYS_FREQ	16000000
#define APB2_CLK		SYS_FREQ
void uart1_tx_rx_init(void);
char uart1_read(void);
int __io_putchar(int ch);


#endif /* UART_H_ */
