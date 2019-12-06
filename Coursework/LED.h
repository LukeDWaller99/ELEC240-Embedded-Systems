#ifndef LED_H 											//LED.h sets up all of the functions for the LED.c
#define LED_H

#include <stm32f4xx.h>

void init_all_LED					(void);
void toggle_green_LED 		(void);
void toggle_red_LED 			(void);
void toggle_blue_LED 			(void);
void toggle_external_LED1	(void);
void toggle_external_LED2	(void);
void toggle_external_LED3	(void);
void toggle_external_LED4	(void);

#endif