#include "LED.h"

void init_all_LED (void)									
{
																					//this void is used to setup all of the LED pins instead of using seperate voids for each LED
																					//because there are so many LEDs to set up this saves on space when initialising in the main
		//enable ports
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOBEN;			//GPIO B clock enabled
	
	//configure port pin functions for the onboard green LED
	GPIOB->MODER&=~	(3u<<(2*0));							//clear pin functions on GPIOB - green LED
	GPIOB->MODER|=	(1u<<(2*0));							//set new pin fuctions on GPIOB - green LED
	
		//configure port pin functions for the onboard red LED
	GPIOB->MODER&=~	(3u<<(2*14));						//clear pin functions on GPIOB - red LED
	GPIOB->MODER|= 	(1u<<(2*14));						//set new pin functions on GPIOB - red LED
	
		//configure port pin functions for the onboard blue LED
	GPIOB->MODER&=~	(3u<<(2*7));						//clear pin functions on GPIOB - blue LED
	GPIOB->MODER|= 	(1u<<(2*7));						//set new pin functions on GPIOB - blue LED
	
		//configure port pin functions for external LED1
	GPIOB->MODER&=~	(3u<<(2*8));						//clear pin functions on GPIOB - external LED1
	GPIOB->MODER|=	(1u<<(2*8));						//set new pin functions on GPIOB - external LED1
	
		//configure port pin functions for external LED2
	GPIOB->MODER&=~(3u<<(2*10));					//clear pin functions on GPIOB - external LED2
	GPIOB->MODER|=(1u<<(2*10));						//set new pin functions on GPIOB - external LED2

		//configure port pin functions for external LED3
	GPIOB->MODER&=~(3u<<(2*11));					//clear pin functions on GPIOB - external LED3
	GPIOB->MODER|=(1u<<(2*11));						//set new pin functions on GPIOB - external LED3
	
		//configure port pin functions for external LED4
	GPIOB->MODER&=~(3u<<(2*12));					//clear pin functions on GPIOB - external LED4
	GPIOB->MODER|=(1u<<(2*12));						//set new pin functions on GPIOB - external LED4
}
void toggle_green_LED (void)
{
	GPIOB->ODR^=(1u<<0);									//XOR the GPIOB data register to invert the pin
}
void toggle_red_LED (void)
{
	GPIOB->ODR^=(1u<<14);									//XOR the GPIOb data register to invert the pin
}
void toggle_blue_LED (void)
{
	GPIOB->ODR^=(1u<<7);									//XOR the GPIOB data register to invert the pin
}
void toggle_external_LED1 (void)
{
	GPIOB->ODR^=(1u<<8);									//XOR the GPIOB data register to invert the pin 
}
void toggle_external_LED2 (void)
{
	GPIOB->ODR^=(1u<<10);									//XOR the GPIOB data register to invert the pin
}
void toggle_external_LED3 (void)
{
	GPIOB->ODR^=(1u<<11);									//XOR the GPIOB data register to invert the pin
}
void toggle_external_LED4 (void)
{
	GPIOB->ODR^=(1u<<12);									//XOR the GPIOB data register to invert the pin
}