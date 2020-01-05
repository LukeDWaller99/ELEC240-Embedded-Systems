#include "INTERRUPT.h"

void init_interrupts (void)					//initialise all of the interrupts for the code 
{
	NVIC->ISER[1] |= (1u << 8);				//interrupt for blue switch
	NVIC->ISER[1] |= (1u << 7);				//interupt for USART3
}
