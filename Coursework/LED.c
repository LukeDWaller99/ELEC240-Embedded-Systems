#include "LED.h"

void init_all_LED (void)									//this void is used to setup all of the LED pins instead of using seperate voids for each LED
																					//because there are so many LEDs to set up this saves on space when initialising in the main
{
		//enable port s
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOBEN;			//GPIO B clock enabled
	
	//configure port pin functions for the onboard green LED
	GPIOB->MODER&=~(3u<<(2*0));							//clear pin functions on GPIOB - green LED
	GPIOB->MODER|=(1u<<(2*0));							//set new pin fuctions on GPIOB - green LED
	
		//configure port pin functions for the onboard red LED
	GPIOB->MODER&=~(3u<<(2*14));						//clear pin functions on GPIOB - red LED
	GPIOB->MODER|= (1U<<(2*14));						//set new pin functions on GPIOB - red LED
	
		//configure port pin functions for the onboard blue LED
	GPIOB->MODER&=~(3u<<(2*7));						//clear pin functions on GPIOB - blue LED
	GPIOB->MODER|= (1U<<(2*7));						//set new pin functions on GPIOB - blue LED
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