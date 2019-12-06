#include "FPGA.h"

void init_FPGA (void)
{
	//enable ports 
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOEEN;		//GPIO E clock enabled
	
	//configure port pin functions for data line PE_15
	GPIOE->MODER&=~(3u<<(2*15));					//clear pin function on GPIOE 	- data line PE_15
	GPIOE->MODER|=(1u<<(2*15));						//set new pin function on GPIOE - data line PE_15
	
	//configure port pin functions for data line PE_12
	GPIOE->MODER&=~(3u<<(2*12));					//clear pin function on GPIOE	- data line PE_12
	GPIOE->MODER|=(1u<<(2*12));						//set new pin function on GPIOE - data line PE_12
	
	//configure port pin functions for data line PE_10
	GPIOE->MODER&=~(3u<<(2*10));				//clear pin function on GPIOE - data line PE_10
	GPIOE->MODER|=(1u<<(2*10));					//set new pin function on GPIOE - data line PE_10
	
	//configure port pin functions for data line PE_2
	GPIOE->MODER&=~(3u<<(2*2));					//clear pin function on GPIOE - data line PE_2
	GPIOE->MODER|=(1u<<(2*2));					//set new pin function on GPIOE - data line PE_2
	
	//configure port pin functions for control line PB_11
	GPIOB->MODER&=~(3u<<(2*11));					//clear pin function on GPIOB - control line PB_11
	GPIOB->MODER|=(1u<<(2*11));					//set new pin function on GPIOB - control line PB_1
	
	//configure port pin functions for control line PB_10
	GPIOB->MODER&=~(3u<<(2*10));				//clear pin function on GPIOB - control line PB_10
	GPIOB->MODER|=(1u<<(2*10));					//set new pin function on GPIOB - control line PB_10
}
void send_FPGA (void)
{
	
}