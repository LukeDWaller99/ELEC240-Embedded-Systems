#include "init.h"
#include "delay.h"
#include "LCD.h"
#include "USART.h"
#include "LED.h"
#include "SWITCH.h"
#include "ADC.h"
#include "DAC.h"
#include "INTERRUPT.h"

void init_all_components (void)	//this is to set up all of the components needed at once reducing the complixity of the main function in the main.c file
{
	init_onboard_LEDs();								//initialise the LEDS
	init_LCD();										//initialise the LCD
	init_USART();									//initialise the USART
	init_blue_switch();						//initialise the blue switch
	init_timer2();								//initialise timer 2
	init_timer4();								//initialise timer 4
	init_timer5_wave();						//initialise timer 5
	init_ADC();										//initialise the ADC
	init_DAC();										//initialise the DAC
	init_interrupts();						//initialise the interrupts
}