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
	init_LCD();
	LCD_CLR();
	cmd_LCD(LCD_LINE1);
	LCD_string("Press blue");
	cmd_LCD(LCD_LINE2);
	LCD_string("button");
	init_USART();
	init_blue_switch();                                                                                                   
	init_DAC();
	init_onboard_LEDs();
	init_external_LEDs();
	init_timer2();
	init_interrupts();
	init_ADC();  
	init_timer5_wave();
	                     
}