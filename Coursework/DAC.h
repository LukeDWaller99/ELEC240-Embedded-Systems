#ifndef DAC_H
#define DAC_H

#include <stm32f4xx.h>

#define DAC_port 	GPIOA
#define DAC_pin		5
#define WAVEFORM_LENGTH 69 
#define PI 	3.1415926535897932384626433832

/*
Function: init_DAC
Returns: void - nothing
Arguments: void - nothing 

This function is used to setup and initialise the DAC
so that it operates correctly 
*/
void init_DAC 			(void);

/*
Function: output_DAC
Returns: void - nothing
Arguments: unsigned short d

This function is used to output the value of d onto
the DAC, this can be used to set DC voltage levels 
or even create various different waves
*/
void output_DAC			(unsigned short d);

/*
Function: DC_output
Returns: void - nothing
Arguments: void - nothing 

This function is used to output a DC level on the DAC
*/
void DC_output 			(void);

/*
Function: triangle_wave
Returns: void - nothing
Arguments: void - nothing 

This function is used to generate a triangle wave
on the output of the DAC
*/
void triangle_wave 	(void);

/*
Function: sine_wave
Returns: void - nothing
Arguments: void - nothing 

This function is used to generate a sine wave on
the output of the DAC
*/
void sine_wave 			(void);

/*
Function: square wave
Returns: void - nothing
Arguments: void - nothing 

This function is used to generate a square wave on
the output of the DAC
*/
void square_wave 		(void);

#endif