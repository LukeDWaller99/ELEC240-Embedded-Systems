#include "ADC.h"
#include "LED.h"
#include "USART.h"
#include "LCD.h"
#include <stdio.h>

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

unsigned short read_ADC (void)											//read the value of the ADC
{
	ADC1->CR2|=ADC_CR2_SWSTART;												//stat the ADC conversion 
	while((ADC1->SR & ADC_SR_EOC) == 0)								//wait for the ADC conversion to be complete
	{
		__NOP();																				//set to no operation while above statement is true
	}
	return ADC1->DR;																	//return the converted value
}
void voltage_display (void)													//display the voltage of the ADC in several formats 
{
	unsigned int voltage_int;													//create an int voltage_int;
	voltage_int = read_ADC();													//setbuf the value of voltae_int to the ADC value
	
	float voltage_float = ((voltage_int*3.3)/4095);		//create a float voltage_float and scale it to between 0 - 3.3V 
	
	char array [16];																	//create an 16 byte array 
	sprintf(array, "%.3fV", voltage_float);						//create a string in the array using the value of voltage_float
	
	cursor_set(10, 1);																//set the cursor to column 10, row 1 
	LCD_string(array);																//put out the value of the array to the LCD
	myPrintf(
	"\x1b[0J\x1b[u\x1b[32;1mVoltage : %.3fV\n\r"
	, voltage_float); 																//put the vlaue of voltage_float out onto the USART using ansi escape code to clear the terminal and change the colour of the text                                                                                                                                                                                                                                                                                                                                                                                            
	LCD_proportional_bar();    												//output the LCD proportional bar                                                                                                  
	if(voltage_float == 0)														//if the value is  = 0, turn off all the LEDs 							
	{
		external_LED1_off();														
		external_LED2_off();														 
		external_LED3_off();														 
		external_LED4_off();														
	}
	else if(voltage_float < 0.825)										//if the value is 3.3V/4 = 0.825V, turn on LED 1
	{
		external_LED1_on();															
		external_LED2_off();														
		external_LED3_off();														
		external_LED4_off();														
	}
	else if (voltage_float < 1.65)										//if value is 3.3V/4 * 2 < 1.65V, turn on LEDs 1, and 2
	{
		external_LED1_on();															
		external_LED2_on();															
		external_LED3_off();
		external_LED4_off();
	}
	else if (voltage_float < 2.475)										//if value is 3.3V/4 * 3 < 2.475, turn on LEDs 1, 2, and 3 
	{
		external_LED1_on();
		external_LED2_on();
		external_LED3_on();
		external_LED4_off();
	}
	else																							//else turn on all the LEDs
	{
		external_LED1_on();
		external_LED2_on();
		external_LED3_on();
		external_LED4_on();
	}
}