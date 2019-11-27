#include "DAC.h"

void init_DAC (void)
{
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;		//enable the DAC port clock
	DAC_port->MODER|=(3u<<(2*DAC_pin));			//set the DAC output pin as anaglogue
	
	RCC->APB1ENR|=RCC_APB1ENR_DACEN;				//enable the DAC clock
	DAC->CR|=DAC_CR_EN2;										//enable DAC 2 
}
void output_DAC (unsigned short d)
{
	DAC->DHR12R2=d;													//wite the data byte to the DAC 2 output register
}