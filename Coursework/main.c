#include <stm32f4xx.h>	//includes the header file for this MCU family
												//this file contains the definitions for the regiset adresses and values etc...
#include "PLL_Config.c"
#include "delay.h"
#include "LED.h"
#include "LCD.h"
#include "USART.h"
#include "SWITCH.h"
#include "init.h"
#include "DAC.h"
#include "INTERRUPT.h"
#include "ADC.h"



int main(void)
{
	PLL_Config(); 
	SystemCoreClockUpdate();
	init_LCD(); 
	LCD_CLR();
	cmd_LCD(LCD_LINE1);
	LCD_string("PUSH BUTTON");
	init_USART();
	init_blue_switch();                                                                                                   
	init_DAC();
	init_onboard_LEDs();
	init_external_LEDs();
	init_timer2();
	init_interrupts();
	init_ADC();  
	init_timer5_wave();

	                                                                                                                                                                                                                                        
	while (1)
	{
		unlock_animation();
//		__WFI();
	}
}