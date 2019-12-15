#include "MORSE.h"
#include "delay.h"
#include "LED.h"
#include "ADC.h"

int w = 1;

void dot (void) // 
{
	variable_delay(w);
}

void dash (void)
{
	variable_delay(3*w);
}
void intra_char (void)
{
	variable_delay(w);
}
void inter_char (void)
{
	variable_delay(3*w);
}
void word_space (void)
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
void morse_voltage (void)
{
	unsigned int voltage_int;
	voltage_int = read_ADC();
	
	float voltage_float = ((voltage_int*3.3)/4095);
	
	char array [16];
	
}