#include "USART.h"
#include "string.h"

void init_USART (void)
{
	unsigned char i1, i2;
	
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;		//usart clock enable
	
	USART_PORT->MODER&=~( (3u<<(2*USART_TX_pin)) | (3u<<(2*USART_RX_pin)));		//clear port enable clock
	USART_PORT->MODER|= ( (2u<<(2*USART_TX_pin)) | (2u<<(2*USART_RX_pin)));		//reset pin functions
	
	i1=USART_TX_pin/8;																												//used to select the AFR[reg] for the TX pin
																																						//pins 0-7 are ARF[0], pins 8-15 are ARF[1]
	i2=USART_RX_pin>>3;																												//the RX_pin is the same as above for the TX_pin 
	
		//alternate functions for the select bits
	USART_PORT->AFR[i1]&=~(0x0f<<(4*(USART_TX_pin-(i1*8))));    							//clear pin functions
	USART_PORT->AFR[i1]|= (0x07<<(4*(USART_TX_pin-(i1*8))));									//set the TX_pin as alternate function for USART
	USART_PORT->AFR[i2]&=~(0x0f<<(4*(USART_RX_pin-(i2*8))));									//clear pin functions
	USART_PORT->AFR[i2]|= (0x07<<(4*(USART_RX_pin-(i2*8))));									//set the RX_pin as alternate function for USART
	
	RCC->APB1ENR|=RCC_APB1ENR_USART3EN;																				//USART1 clock enabled
	USART_MODULE->CR1|=( 																											//USART1 configuration
	USART_CR1_TE | 																														//transmit enabled
	USART_CR1_RE |																														//recieve enabled
	USART_CR1_UE | 																														//usart main enable bit
	USART_CR1_RXNEIE 																													//RXNE enable
	);
	
}