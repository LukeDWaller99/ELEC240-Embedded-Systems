#include <stm32f4xx.h>	//includes the header file for this MCU family
												//this file contains the definitions for the regiset adresses and values etc...
#include "PLL_Config.c"
#include "delay.h"
#include "LED.h"
#include "LCD.h"
#include "USART.h"
#include "SWITCH.h"
#include "init.h"

int main(void)
{
	PLL_Config();
	SystemCoreClockUpdate();

//	init_USART();
//	init_blue_switch();
	init_LCD();
	LCD_CLR();
	LCD_setup();
	cmd_LCD(LCD_LINE1);
	decimal(1000);
	cmd_LCD(LCD_LINE2);
	decimal_to_hex(1000);
	
	
//	NVIC->ISER[1] |= (1u << 8);				//interrupt for blue switch
//	NVIC->ISER[1] |= (1u << 7);				//interupt for USART3 
	
	while (1)
	{
	__WFI();
	}
}
