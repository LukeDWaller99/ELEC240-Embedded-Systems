#include "DAC.h"

void init_DAC (void)
{
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;			//enable the DAC port clock
	DAC_port->MODER|=(3u<<(2*DAC_pin));			//set the DAC output pin as anaglogue
	
	RCC->APB1ENR|=RCC_APB1ENR_DACEN;				//enable the DAC clock
	DAC->CR|=DAC_CR_EN2;										//enable DAC 2 
}
void output_DAC (unsigned short d)
{
	DAC->DHR12R2=d;													//wite the data byte to the DAC 2 output register
}

void DC_output (void)
{
	output_DAC(0xFFFF);											//outputs a DC value to the DAC
}
void triangle_wave (void)											//Generates a sawtooth wave 
{
	int i;
	for (i=0; i<0xFFF; i++)								//sawtooth starts at 0, goes to 0xFFFF, incrementing the count by 1 each time
	{
		output_DAC(i);												//outputs the value of i to the DAC
	}
	for (i=0xFFF; i>1; i--)
	{
		output_DAC(i);
	}
}
void sine_wave (void)
{
	
}