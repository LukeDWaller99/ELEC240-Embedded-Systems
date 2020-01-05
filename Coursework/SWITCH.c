 #include "SWITCH.h"
#include "LED.h"
#include "USART.h"
#include "LCD.h"
#include "delay.h"
#include "ADC.h"

int mode = 0;

void init_blue_switch(void)												//initialise the blue button
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;						//enable GPIOC clock
	RCC->APB2ENR |= 0x4000;													//enable SYSCFG clock
	
	GPIOC->MODER &= ~0x0c000000;										//clear pin mode for switch
	
	SYSCFG->EXTICR[3] &= ~0x00f0;										//clear the port selection for EXTI13
	SYSCFG->EXTICR[3] |=  0x0020;										//select the port C for EXTI13
	
	EXTI->IMR 	|= 0x2000;													//unmasks EXTI13
	EXTI->RTSR 	|= 0x2000;													//selects rising edge trigger for button
}

/*
handler for the interrupt of the blue button
it handles what happens when the button is pressed
ie. swapping between the different modes and 
 
*/
void EXTI15_10_IRQHandler (void) 									
{
	EXTI->PR |= 0x2000;															//clear the interrupt flag
//animation = 0;
	blue_LED_off();																	//turns off the blue LED 
	green_LED_off();																//turn off the green LED
	red_LED_off(); 																	//turn off the red LED
	variable_delay(1);															//variable delay of 1us
	if(GPIOC-> IDR & 0x2000) 												//if button is pressed 
	{
		variable_delay(2000); 												//wait 2s 
		if(GPIOC->IDR & 0x2000) 											//if button is still pressed 
		{
			LCD_CLR();																	//clears the LCD
			while(GPIOC->IDR & 0x2000) 									//while button is pressed
			{
				cursor_set(1,1);													//set the cursor to column 1, row 1
				LCD_string("HOLD :"); 										//write HOLD: to the LCD
				red_LED_off(); 														//turn off the red LED 
				voltage_display();												//display the voltage of the ADC
				variable_delay(10000); 										//variable delay of 10s
			}
			LCD_CLR(); 																	//clear the LCD                                                                                                                                                                                                                    
		}
		else 
		{
			if(mode ==0)	
			{
				DC_mode();																//run DC mode
				mode = 1;																	//set the mode to 1
			}
			else if(mode == 1)
			{
				square_mode(); 														//run the square wave mode
				mode = 2; 																//set the mode to 2 
			}
			else if(mode == 2)
			{
				triangle_mode(); 													//run the triangle wave mode 
				mode = 3; 																//set the mode to 3
			}
			else if(mode ==3)
			{
				sine_mode(); 															//run the sine wave mode
				mode =0; 																	//set the mode to 4 
			}
		}
	}
	
}

