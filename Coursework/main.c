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
	init_USART();
	init_blue_switch();
	init_DAC();
	init_all_LED();
	init_timer2();
	init_timer3();
	init_timer5_wave();
	init_interrupts();
	init_ADC();
//	init_LCD();
//	LCD_CLR();
//	LCD_setup(); 
//	cmd_LCD(LCD_LINE1);
//	decimal(1000);
//	cmd_LCD(LCD_LINE2);
//	decimal_to_hex(1000);
//	LCD_setup();
//	cmd_LCD(LCD_LINE1);
//	decimal(voltage_ADC());
//	put_LCD('.');
//	decimal(remainder_ADC());
	
 
	
	while (1)
	{
//	sine_wave();
//	DC_output();
//	triangle_wave();
	__WFI();
	}
}