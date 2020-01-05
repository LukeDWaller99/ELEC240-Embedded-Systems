#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stm32f4xx.h>

/*
Function: init_interrupts
Returns: void - nothing
Arguments: void - nothing 

This function is used to inialise the interrupts for
the onboard blue switch and the USART3
*/
void init_interrupts (void);

#endif