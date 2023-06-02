#include "stdint.h"
#include "stm32f4xx.h"

#define GPIOAEN		(1U<<0)
#define UART1EN		(1U<<4)

#define CR1_TE		(1U<<3)
#define CR1_UE		(1U<<13)
#define SR_TXE		(1U<<7)

#define SYS_FREQ	16000000
#define APB2_CLK		SYS_FREQ

#define UART_BAUDRATE 9600
void uart1_tx_init(void);
void uart1_write(int ch);
static void uart_set_baundrate(USART_TypeDef *UARTx, uint32_t PeriphClk, uint32_t Baudrate);
static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t Baudrate);

int main(void)
{

	uart1_tx_init();
	while (1)
	{

		uart1_write('I');
		for (int i=0; i<100000; i++);

	}
}

void uart1_tx_init(void)
{
	/******************Config uart gpio pin**************
	*Enable clock access to gpioa
	*Set PA9 mode to AF mode
	*Set PA9 AF type to UART_TX (AF07)*/

	RCC->AHB1ENR |= GPIOAEN;

	GPIOA ->MODER &=~ (1U<<18);
	GPIOA ->MODER |= (1U<<19);
	//MODER9->10
	GPIOA ->AFR[1] |= (1U<<4);
	GPIOA ->AFR[1] |= (1U<<5);
	GPIOA ->AFR[1] |= (1U<<6);
	GPIOA ->AFR[1] &=~ (1U<<7);
	//AF7
	RCC->APB2ENR |= UART1EN; //enable uart1
	uart_set_baundrate(USART1, APB2_CLK, UART_BAUDRATE); //config baudrate
	USART1->CR1 = CR1_TE; //config transfer direction
	USART1->CR1 |= CR1_UE;//Enable USART


}
void uart1_write(int ch)
{
	while (!(USART1->SR & SR_TXE));
	USART1 -> DR = (ch & 0xFF);  //DR: Data Register, write to transmit data reg

}
static void uart_set_baundrate(USART_TypeDef *UARTx, uint32_t PeriphClk, uint32_t Baudrate)
{
	UARTx->BRR = compute_uart_div(PeriphClk, Baudrate);
}
static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t Baudrate)
{
	return ((PeriphClk +(Baudrate/2U))/Baudrate);
}
