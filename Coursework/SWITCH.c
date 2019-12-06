#include "SWITCH.h"
#include "LED.h"
#include "USART.h"

void init_blue_switch(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;						//enable GPIOC clock
	RCC->APB2ENR |= 0x4000;													//enable SYSCFG clock
	
	GPIOC->MODER &= ~0x0c000000;										//clear pin mode for switch
	
	SYSCFG->EXTICR[3] &= ~0x00f0;										//clear the port selection for EXTI13
	SYSCFG->EXTICR[3] |=  0x0020;										//select the port C for EXTI13
	
	EXTI->IMR 	|= 0x2000;													//unmasks EXTI13
	EXTI->FTSR 	|= 0x2000;													//selects falling edge trigger for button
}

void EXTI15_10_IRQHandler (void) 
{
	EXTI->PR |= 0x2000;															//clear interrupt pending flag
	send_USART('a');																//sends 'a' via usart to the terminal
	toggle_green_LED();															//toggles the green LED 
}
