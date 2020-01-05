#ifndef SWITCH_H
#define SWITCH_H
#include <stm32f4xx.h>

/*
Function: init_blue_switch
Returns: void - nothing
Arguments: void - nothing

This function is used to initialise the onboard 
blue button for changing between different modes
on the nucelo board
*/
void init_blue_switch (void);
void EXTI15_10_IRQHandler (void);

#endif