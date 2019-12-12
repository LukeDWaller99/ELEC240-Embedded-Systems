#ifndef USART_H
#define USART_H

#include <stm32f4xx.h>
#include "stdio.h"

#define USART_MODULE 		USART3
#define USART_PORT 			GPIOD
#define USART_TX_pin		8
#define	USART_RX_pin		9

void init_USART 				(void);
char USART_read 				(void);
void send_USART 				(unsigned char d);
void USART_string 			(char *string);
void myPrintf 					(const char* format,...);

#endif