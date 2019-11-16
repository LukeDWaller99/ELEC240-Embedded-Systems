#include <stm32f4xx.h>	//includes the header file for this MCU family
												//this file contains the definitions for the regiset adresses and values etc...
												
#include "PLL_Config.c"
#include "delay.h"
#include "LED.h"

int main(void)
{
	PLL_Config();
	SystemCoreClockUpdate();
	
	init_timer2();
	init_all_LED();
	
	while (1)
	{
		__WFI();
	}
}
