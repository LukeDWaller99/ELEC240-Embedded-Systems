#ifndef MORSE_H
#define MORSE_H

#include <stm32f4xx.h>

/*
Functions: dot, dash, and various spaces
Returns: void - nothing
Arguments: void - nothing 

These functions are the basic functions that set up the
delay times for the morse code to work correctly. These 
are called during the other functions
*/
void dot 						(void);
void dash 					(void);
void intra_char 		(void);
void inter_char 		(void);
void word_space 		(void);

/*
Functions: zero up to nine
Returns: void - nothing
Arguments: void - nothing 

These are the functions that output the numbers using the
blue onboard LED. They use the funtons above the create
the appropritate timings
*/
void zero 					(void);
void one 						(void);
void two 						(void);
void three 					(void);
void four 					(void);
void five 					(void);
void six 						(void);
void seven 					(void);
void eight 					(void);
void nine 					(void);

/*
Function: decimal_point
Returns: void - nothing
Arguments: void - nothing 

This function is used to create a decimal point in morse
code to seperate the numbers correctly 
*/
void decimal_point 	(void);

/*
Function: morse_voltage
Returns: void - nothing
Arguments: void - nothing 

This function is used to output the input voltage as morse
code using the blue LED. it takes the input from the ADC
and outputs it as morse code. 
*/
void morse_voltage 	(void);

#endif