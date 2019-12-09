#include "SWITCH.h"
#include "LED.h"
#include "USART.h"
#include "LCD.h"
#include "delay.h"

int mode = 0;

void init_blue_switch(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;						//enable GPIOC clock
	RCC->APB2ENR |= 0x4000;													//enable SYSCFG clock
	
	GPIOC->MODER &= ~0x0c000000;										//clear pin mode for switch
	
	SYSCFG->EXTICR[3] &= ~0x00f0;										//clear the port selection for EXTI13
	SYSCFG->EXTICR[3] |=  0x0020;										//select the port C for EXTI13
	
	EXTI->IMR 	|= 0x2000;													//unmasks EXTI13
	EXTI->RTSR 	|= 0x2000;													//selects rising edge trigger for button
}
void EXTI15_10_IRQHandler (void) 
{
	EXTI->PR |= 0x2000;
	LCD_CLR();
	blue_LED_off();
	green_LED_off();
	red_LED_off();
	variable_delay(1);
	if(GPIOC-> IDR & 0x2000)
	{
		variable_delay(2000);
		if(GPIOC->IDR & 0x2000)
		{
			while(GPIOC->IDR & 0x2000)
			{
				cmd_LCD(LCD_LINE1);
				LCD_string("HOLD :");
				red_LED_off();
				variable_delay(1000);
			}
			LCD_CLR();                                                                                                                                                                                                                      
		}
		else 
		{
			if(mode ==0)
			{
				DC_mode();
				mode = 1;
			}
			else if(mode == 1)
			{
				AC_mode();
				mode = 2;
			}
			else if(mode == 2)
			{
				square_mode();
				mode = 3;
			}
			else if(mode == 3)
			{
				triangle_mode();
				mode = 4;
			}
			else if(mode ==4)
			{
				sine_mode();
				mode =0;
			}
		}
	}
	
}
