#include "LED.h"

	void init_onboard_LEDs (void)																						
{
																				//this void is used to setup all of the LED pins instead of using seperate voids for each LED
																				//because there are so many LEDs to set up this saves on space when initialising in the main
		//enable ports
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOBEN;		//GPIO B clock enabled
	
	//configure port pin functions for the onboard green LED
	GPIOB->MODER&=~	(3u<<(2*0));					//clear pin functions on GPIOB - green LED
	GPIOB->MODER|=	(1u<<(2*0));					//set new pin fuctions on GPIOB - green LED
	
		//configure port pin functions for the onboard red LED
	GPIOB->MODER&=~	(3u<<(2*14));					//clear pin functions on GPIOB - red LED
	GPIOB->MODER|= 	(1u<<(2*14));					//set new pin functions on GPIOB - red LED
	
		//configure port pin functions for the onboard blue LED
	GPIOB->MODER&=~	(3u<<(2*7));					//clear pin functions on GPIOB - blue LED
	GPIOB->MODER|= 	(1u<<(2*7));					//set new pin functions on GPIOB - blue LED
}
void init_external_LEDs (void)
{
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOEEN;
		//configure port pin functions for external LED1
	GPIOE->MODER	&=~	(3u<<(2*2));					//clear pin functions on GPIOB - external LED1
	GPIOE->MODER	|=	(1u<<(2*2));					//set new pin functions on GPIOB - external LED1
	GPIOE->OTYPER	|= 	(1u<< 2);									//putting the external LED in OPEN DRAIN
	
		//configure port pin functions for external LED2
	GPIOE->MODER&=~(3u<<(2*4));					//clear pin functions on GPIOB - external LED2
	GPIOE->MODER|=(1u<<(2*4));						//set new pin functions on GPIOB - external LED2
	GPIOE->OTYPER|= (1u << 4);									//putting the external LED in OPEN DRAIN

		//configure port pin functions for external LED3
	GPIOE->MODER&=~(3u<<(2*5));					//clear pin functions on GPIOB - external LED3
	GPIOE->MODER|=(1u<<(2*5));						//set new pin functions on GPIOB - external LED3
	GPIOE->OTYPER|= (1u << 5);									//putting the external LED in OPEN DRAIN

		//configure port pin functions for external LED4
	GPIOE->MODER&=~(3u<<(2*6));					//clear pin functions on GPIOB - external LED4
	GPIOE->MODER|=(1u<<(2*6));						//set new pin functions on GPIOB - external LED4
	GPIOE->OTYPER|= (1u << 6);									//putting the external LED in OPEN DRAIN
}
void green_LED_on (void)						
{
	GPIOB->BSRR = 1;									
}
void green_LED_off (void)
{
	GPIOB->BSRR = 1<<16; 
}
void red_LED_on (void)
 {
	GPIOB->BSRR = 1 << 14;									
}
void red_LED_off (void)
{
	GPIOB->BSRR = 1 << 30;
}
void blue_LED_on (void)
{
	GPIOB->BSRR =  1 << 7;									
}
void blue_LED_off (void)
{
	GPIOB->BSRR = 1 << 23;
}
void external_LED1_on (void)
{
	GPIOE->BSRR = 1u << (2+16);								 
}
void external_LED1_off (void)
{
	GPIOE->BSRR = 1u << 2;
}
void external_LED2_on (void)
{
	GPIOE->BSRR = 1u << (16+4);							
}
void external_LED2_off (void)
{
	GPIOE->BSRR = 1u << 4;
}
void external_LED3_on (void)
{
	GPIOE->BSRR = 1u << (16+5); 								
}
void external_LED3_off (void)
{
	GPIOE->BSRR = 1u << 5;
}
void external_LED4_on (void)
{
	GPIOE->BSRR = 1u << (16+6);							
}
void external_LED4_off (void)
{
	GPIOE->BSRR = 1u << 6;
}
