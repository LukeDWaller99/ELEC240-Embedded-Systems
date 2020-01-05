#ifndef LED_H 											//LED.h sets up all of the functions for the LED.c
#define LED_H

#include <stm32f4xx.h>

/*
Function: init_(location)_LEDs
Returns: void - nothing
Arguments: void - nothing

These functions are used to initialise both the
onboard and external LEDs for the Nucleo board
The onboard LEDs are set up in a push pull 
configuration and the external LEDs are set to 
open drain mode
*/
void init_onboard_LEDs		(void);
void init_external_LEDs		(void);

/*
Function: (colour)_LED_on
Returns: void - nothing 
Arguments: void - nothing 

These functions are used to turn the onboard 
LEDs on
*/
void green_LED_on					(void);
void blue_LED_on 					(void);
void red_LED_on						(void);

/*
Function: (colour)_LED_off
Returns: void - nothing
Arguments: void - nothing

These functions are used to turn the onboard
LEDs off
*/
void green_LED_off				(void);
void blue_LED_off					(void);
void red_LED_off 					(void);

/*
Function: external_LED(number)_on
Returns: void - nothing 
Arguments: void - nothing 

These functions are used to turn the external
LEDs on
*/
void external_LED1_on			(void);
void external_LED2_on 		(void);
void external_LED3_on 		(void);

/*
Function: external_LED(number)_on
Returns: void - nothing 
Arguments: void - nothing 

These functions are used to turn the external
LEDs off
*/
void external_LED1_off		(void);
void external_LED2_off		(void);
void external_LED3_off		(void);
void external_LED4_off		(void);

#endif
