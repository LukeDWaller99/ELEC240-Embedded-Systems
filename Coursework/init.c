#include "init.h"
#include "delay.h"
#include "LCD.h"
#include "USART.h"
#include "LED.h"
#include "SWITCH.h"
#include "ADC.h"

void init_all_components (void)	//this is to set up all of the components needed at once reducing the complixity of the main function in the main.c file
{
	init_all_LED();
	init_LCD();
	init_USART();
	init_blue_switch();
	init_timer2();
	init_timer3();
	init_timer4();
	init_timer5_10us();
	init_ADC();
}