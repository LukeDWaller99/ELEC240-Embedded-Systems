#ifndef LED_H 											//LED.h sets up all of the functions for the LED.c
#define LED_H

#include <stm32f4xx.h>

void init_onboard_LEDs		(void);
void init_external_LEDs		(void);
void green_LED_on					(void);
void green_LED_off				(void);
void red_LED_on						(void);
void red_LED_off 					(void);
void blue_LED_on 					(void);
void blue_LED_off					(void);
void external_LED1_on			(void);
void external_LED1_off		(void);
void external_LED2_on 		(void);
void external_LED2_off		(void);
void external_LED3_on 		(void);
void external_LED3_off		(void);
void external_LED4_on 		(void);
void external_LED4_off		(void);
void toggle_red_LED				(void);

#endif