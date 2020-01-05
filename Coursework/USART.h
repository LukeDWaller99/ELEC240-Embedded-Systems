#ifndef USART_H
#define USART_H

#include <stm32f4xx.h>
#include "stdio.h"

#define USART_MODULE 		USART3
#define USART_PORT 			GPIOD
#define USART_TX_pin		8
#define	USART_RX_pin		9

/*
Function: init_USART
Returns: void - nothing 
Arguments: void - nothing

This function is used to initalise the USART module
*/
void init_USART 				(void);

/*
Function: USART_read
Returns: char
Arguments: void - nothing 

This function is used to scan the input to the USART
module and echo back what is been inputed as a character
that is usable by other functions
*/
char USART_read 				(void);

/*
Function: send_USART
Returns: void - nothing
Arguments: unsigned char d

This function is used to send a user defined character 
over the USART module 
*/
void send_USART 				(unsigned char d);

/*
Function: USART_string
Returns: void - nothing
Arguments: char *string

This function is used to sned a user defined string of 
characters over the USART module 
*/
void USART_string 			(char *string);

/*
Function: mode_selector
Returns: void - nothing 
Arguments: char *string

This function is used to select the mode of the Nucelo
board between, DC mode, Sine mode , Triangle mode, 
and Sqaure mode
*/
void mode_selector			(char *string);

/*
Function: myPrintf
Returns: void - nothing 
Arguments: const char *format, ... (this means an unspecified
number of variables can be used)

This function is used as a printf functions that allows 
the user to print out values onto the USART module
*/
void myPrintf 					(const char* format,...);

#endif