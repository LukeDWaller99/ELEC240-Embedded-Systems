#ifndef ADC_H
#define ADC_H

#include <stm32f4xx.h>

#define ADC_input_port	GPIOC
#define ADC_input_pin		0
#define ADC_channel			10
#define ADC_value 

/*
Function: init_ADC
Returns: void - nothing
Arguments: void - nothing 

This function is used to initalise and setup 
the ADC so that it operates correctly
*/
void init_ADC (void);

/*
Function: read_ADC
Returns: unsigned short
Arguments: void - nothing 

This function is used to collect the data and read
the voltage level on the ADC and returns it as an
unsigned short so that i can be used by other 
functions
*/
unsigned short read_ADC (void);

/*
Function: voltage_display
Returns: void - nothing
Arguments: void - nothing 

This function is used to display the voltage into 
the ADC in various forms such as USART, the LCD
proportional bar, and the four external LEDs
*/
void voltage_display (void);

#endif