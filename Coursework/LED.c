#include "LED.h"

void init_green_LED (void)
{
	//enable port s
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOBEN;			//GPIO B clock enabled
	
	//configure port pin functions
	GPIOB->MODER&=~(3u<<(2*0));							//clear pin functions on GPIOB
	GPIOB->MODER|=(1u<<(2*0));							//set new pin fuctions on GPIOB
}
void init_red_LED (void)
{
	//enable port s
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOBEN;			//GPIO B clock enabled
	
	//configure port pin functions
	GPIOB->MODER&=~(3u<<(2*14));						//clear pin functions on GPIOB
	GPIOB->MODER|= (1U<<(2*14));						//set new pin functions on GPIOB
}
