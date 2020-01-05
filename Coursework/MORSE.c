#include "MORSE.h"
#include "delay.h"
#include "LED.h"
#include "ADC.h"

/*
For morse code, everything is run using ratios that all stem from the length of a dot
	A dot is one unit long
	A dash is equivalent to three dots 
	An intra character space is equal to one dot
	An inter character space is equal to three dots
	A word space is equal to 7 dots
*/
int w = 1; 																												//													

void dot (void) //. 
{
	variable_delay(w);
}

void dash (void) //-
{
	variable_delay(3*w);
}
void intra_char (void) //.
{
	variable_delay(w);
}
void inter_char (void) //-
{
	variable_delay(3*w);
}
void word_space (void) //--.
{
	variable_delay(7*w);
}
void zero (void) //-----
{
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	inter_char();
}
void one (void) //.----
{
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	inter_char();
}
void two (void) //..---
{
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	inter_char();
}
void three (void) //...--
{
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	inter_char();
}
void four (void) //....-
{
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	inter_char();	
}
void five (void) //......
{
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	inter_char();	
}
void six (void) //-.....
{
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	inter_char();
}
void seven (void) //--...
{
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	inter_char();
}
void eight (void) //---..
{
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	inter_char();
}
void nine (void) //----.
{
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dot();
	blue_LED_off();
	inter_char();
}
void decimal_point (void) // .-.-.-
{
	blue_LED_on();
	dot();
	blue_LED_off();
	intra_char();
	blue_LED_on();
	dash();
	blue_LED_off();
	intra_char();
}
void morse_voltage (void)
{
	unsigned int voltage_int; 											//create a variable voltage_int
	voltage_int = read_ADC();												//read_ADC the value from the ADC
	
	float voltage_float = ((voltage_int*3.3)/4095);	//convert the value from the ADC to a voltage 
		
	if(voltage_float == 0)
	{
		zero();
		word_space();
	}
	else if(voltage_float < 0.5)
	{
		zero();
		decimal_point();
		five();
		word_space();
	}
	else if(voltage_float < 1)
	{
		one();
		decimal_point();
		zero();
		word_space();
	}
	else if(voltage_float < 1.5)
	{
		one();
		decimal_point();
		five();
		word_space();
	}
	else if(voltage_float < 2)
	{
		two();
		decimal_point();
		zero();
		word_space();
	}
	else if(voltage_float < 2.5)
	{
		two();
		decimal_point();
		five();
		word_space();
	}
	else if(voltage_float < 3)
	{
		three();
		decimal_point();
		zero();
		word_space();
	}
	else
	{
		three();
		decimal_point();
		three();
		word_space();
	}
}