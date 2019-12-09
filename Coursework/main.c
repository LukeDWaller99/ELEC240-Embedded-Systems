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
	LCD_string("fuck off");
	init_USART();
	init_blue_switch();                                                                                                   
	init_DAC();
	init_onboard_LEDs();
	init_external_LEDs();
	init_timer2();
	init_interrupts();
	init_ADC();  
	init_timer4();
	init_timer5_wave();
	green_LED_on();
	blue_LED_on();
	red_LED_on();
//	external_LED1_on();
//	external_LED2_on();		
//	external_LED3_on();
//	external_LED4_on();
	                                                                                                                                                                                                                                        
	while (1)
	{
//	sine_wave();
//	DC_output();
//	triangle_wave();
//	external_LED_ADC();
	}
}