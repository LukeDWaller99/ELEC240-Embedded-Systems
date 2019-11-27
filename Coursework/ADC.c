#include "ADC.h"

void init_ADC (void)
{
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOCEN;								//GPIOC clock update
	ADC_input_port->MODER|=(3u<<(2*ADC_input_pin));		//ADC input pin in analogue mode
	
	RCC->APB2ENR|=RCC_APB2ENR_ADC1EN;									//ADC clock enabled 
	ADC1->SQR1&=~ADC_SQR1_L;													//sets the number of conversions per sequence to 1
	ADC1->SQR3&=~ADC_SQR3_SQ1; 												//clears the channel select bits 
	ADC1->SQR3|=ADC_channel;													//set the channel for the ADC
	ADC1->CR2|=ADC_CR2_ADON;													//enable the ADC
}

unsigned short read_ADC (void)
{
	ADC1->CR2|=ADC_CR2_SWSTART;												//stat the ADC conversion 
	while((ADC1->SR & ADC_SR_EOC) == 0)								//wait for the ADC conversion to be complete
	{
		__NOP();
	}
	return ADC1->DR;																	//return the converted value
}