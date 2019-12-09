#include "ADC.h"
#include "LED.h"
#include "USART.h"
#include "LCD.h"

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
void voltage_display (void)
{
	unsigned int voltage_int;
	voltage_int = read_ADC();
	
	float voltage_float = ((voltage_int*3.3)/4095);
	
	char array [16];
	sprintf(array, "%.3f V", voltage_float);
	
	LCD_CLR();
	cmd_LCD(LCD_LINE1);
	LCD_string(array);
	USART_string(array);
	LCD_proportional_bar();
}
//void external_LED_ADC (void)
//{
//	float voltage = read_ADC();
//	
//	voltage = (voltage) / 1241;
//	
//	if(voltage < 2)
//	{
//		external_LED1_on();
//		external_LED2_off();
//		external_LED3_off();
//		external_LED4_off();
//	}
//	else if (voltage < 2)
//	{
//		external_LED1_on();
//		external_LED2_on();
//		external_LED3_off();
//		external_LED4_off();
//	}
//	else if (voltage < 3)
//	{
//		external_LED1_on();
//		external_LED2_on();
//		external_LED3_on();
//		external_LED4_off();
//	}
//	else
//	{
//		external_LED1_on();
//		external_LED2_on();
//		external_LED3_on();
//		external_LED4_on();
//	}
//}