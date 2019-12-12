#include "USART.h"
#include "string.h"
#include "stdio.h"
#include "stdarg.h"

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
	
	CLEAR_BIT(USART_MODULE->CR2,(1<<12|1<<13));																//clear stop bits = 1 stop bit
	CLEAR_BIT(USART_MODULE->CR1, 1<<15);																				//16 bit oversmapling on the USART
	CLEAR_BIT(USART_MODULE->CR1, 1<<12);																			//1 start bit 8 data bits 
	CLEAR_BIT(USART_MODULE->CR1, 1<<10);																			//Disable the parity bit
	CLEAR_BIT(USART_MODULE->CR1, 1<<9);																				//SET even parity
	USART_MODULE->BRR= 0x187;																									//set the baud rate due to the calculations 

}
char USART_read (void)
{
	while (!(USART_MODULE->SR	&	0x00020)){}																		//read chararters written into the USART in the data register
	return USART_MODULE->DR;
}
void send_USART (unsigned char d)
{
	while (!(USART_MODULE->SR	&	USART_SR_TC));																//write byte to the USART data register
	USART_MODULE->DR=d;
}
void USART3_IRQHandler (void)
{
	char c = USART_read();
	send_USART(c);
	USART3->SR = 0x2000; 
}
int fgetc(FILE *f)
{
	int x;
	
	x = USART_read();	//read the character from the console
	
	if(x == '\r')
	{
		send_USART(x); //IF '\r' after it is echoed, a '\n' is needed afterwards
		x = '\n';
	}
	send_USART(x);
	return x;
}
int fputc(int x, FILE *f)
{
	send_USART(x); //write the character out to the console
	return x;  
}
void USART_string (char *string)
{
	int string_length = strlen(string);																				//writes the length of the string to an integer
	for( int i = 0; i<= string_length; i++)
	{
		char character = string[i];																							//writes the position of i in the string to the char character
		send_USART(character);																									//sends the character to the send usart function that writes the character out in usart 
	}
}
#define BUFFER_SIZE 255
char transmit_buffer[BUFFER_SIZE];
void myPrintf (const char* format,...) //the elipses define dynamic linking or binding - this means there are variable numbers of argumetents
{
	va_list arguments;
	va_start(arguments,format);
	vsprintf(transmit_buffer ,format,arguments);
	va_end(arguments);
	
	for(unsigned int i =0; i < BUFFER_SIZE; i++)
	{
		send_USART(transmit_buffer[i]);
	}
}