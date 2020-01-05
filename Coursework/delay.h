#ifndef DELAY_H
#define DELAY_H

#include <stm32f4xx.h>

/*
Function: init_timer(number)_(time) 
Returns: void - nothing 
Arguments: void - nothing

These funstions are used to set up all of the timers for the 
various functions on the nucelo board (use stated in .c file)
*/
void init_timer2 				(void);
void init_timer3_2s 		(void);
void init_timer3_1s 		(void);
void init_timer3_750ms 	(void);
void init_timer3_500ms 	(void);
void init_timer3_250ms 	(void);
void init_timer4 				(void);
void init_timer2 				(void);
void init_timer5_wave		(void);
void init_timer7				(void);

/*
Function: variable_delay_timer
Returns: void - nothing 
Arguments: uint32_t n

This function is used as a variable dealy function that you pass
your own time into dynamically in code
*/
void variable_delay_timer (uint32_t n); 

/*
Function: variable_delay
Returns: void - nothing
Arguments: int t

This function is a variable delay that operates in ms
the delay length can be altered by passing a different
variable into it
*/
void variable_delay 		(int t);

/*
Function: DC_mode
Returns: void - nothing 
Arguments: void nothing

This function is used to select DC operating mode 
and set all of the parameters for the DC mode
*/
void DC_mode 						(void);

/*
Function: sine_mode
Returns: void - nothing 
Arguments: void - nothing

This function is used to select the sine wave 
operating mode and set all of the parameters for
the sine wave mode
*/
void sine_mode 					(void);

/*
Function: traingle_mode
Returns: void - nothing
Arguments: void - nothing

This function is used to selec the triangle wave
operating mode and set all of the parameters for 
the triangle wave mode
*/
void triangle_mode 			(void);

/*
Function: square_mode
Returns: void - nothing
Arguments: void - nothing 

This function is used to select the square wave 
operating mode and set all of the parameters for
the sqaure wave mode
*/
void square_mode 				(void);

#endif