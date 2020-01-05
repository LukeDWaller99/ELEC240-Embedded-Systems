#include "init.h"
#include "delay.h"
#include "LCD.h"
#include "USART.h"
#include "LED.h"
#include "SWITCH.h"
#include "ADC.h"
#include "DAC.h"
#include "INTERRUPT.h"
#include "PLL_Config.c"

void init_all_components (void)	//this is to set up all of the components needed at once reducing the complixity of the main function in the main.c file
{
	PLL_Config(); 
	SystemCoreClockUpdate();
	init_LCD(); 
	LCD_CLR();
	cmd_LCD(LCD_LINE1);
	LCD_string("PUSH BUTTON TO");
	init_USART();
	send_USART('a');
	init_blue_switch();                                                                                                   
	init_DAC();
	init_onboard_LEDs();
	init_external_LEDs();
	init_timer2();
	init_interrupts();
	init_ADC();   
	init_timer5_wave();
	init_timer7();                 
}