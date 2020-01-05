#ifndef LCD_H
#define LCD_H

#include <stm32f4xx.h>
#include "delay.h"

#define LCD_PORT		GPIOD
#define LCD_RS_pin	2			//set up to avoid using the pins that are covered by the FPGA board
#define LCD_RW_pin	0
#define LCD_E_pin		1
#define LCD_D0_pin	0
#define LCD_LINE1		0x80
#define LCD_LINE2		0xc0

#define set_LCD_RS()					LCD_PORT->BSRR=(1u<<LCD_RS_pin)
#define clr_LCD_RS()					LCD_PORT->BSRR=(1u<<(LCD_RS_pin+16))
#define set_LCD_RW()					LCD_PORT->BSRR=(1u<<LCD_RW_pin)
#define clr_LCD_RW()					LCD_PORT->BSRR=(1u<<(LCD_RW_pin+16))
#define set_LCD_E()						LCD_PORT->BSRR=(1u<<LCD_E_pin)
#define clr_LCD_E()						LCD_PORT->BSRR=(1u<<(LCD_E_pin+16))
#define LCD_CLR()							cmd_LCD(0x01)
#define set_LCD_bus_input()		LCD_PORT->MODER&=~(0xff00<<(2*LCD_D0_pin))
#define set_LCD_bus_output()	LCD_PORT->MODER|=(0x5500<<(2*LCD_D0_pin))

/*
Function: LCD_delay_us
Returns: void - nothing
Arguments: unsigned int us

This function is a variable delay timer used in the
setup of the LCD display, set in us
*/
void LCD_delay_us					(unsigned int us);

/*
Function: wait_LCD_busy
Returns: void - nothing 
Arguments: void - nothing

This function is used to check the wait busy flag
for the LCD display to make sure it is avaliable
when data is being transfered to the LCD display
*/
void wait_LCD_busy				(void);

/*
Function: set_LCD_data
Returns: void - nothing
Arguments: unsigned char d, int val

This function is used to put the data onto the 
LCD display data lines 
*/
void set_LCD_data					(unsigned char d, int val);

/*
Function: strobe_LCD
Returns: void - nothing
Arguments: void - nothing

This function is used to send the data to the
LCD, it sets the enable line high for 10us then
sets it low for 10us. This allows the LCD display 
to recieve data
*/
void strobe_LCD						(void);

/*
Function: cmd_LCD
Returns: void - nothing
Arguments: unsigned char cmd

This function is used to send data to the LCD 
control register to do various functions such as
cursor flash, cursor location, and setting the mode
(8bit of 4 bit mode)
*/
void cmd_LCD							(unsigned char cmd);

/*
Function: put_LCD
Returns: void - nothing 
Arguments: unsigned char put

This function is used to send single characters to
the LCD display
*/
void put_LCD							(unsigned char put);

/*
Function: init_LCD
Returns: void - nothing
Arguments: void - nothing

This function is used to set up the LCD so that it 
operaters correctly and puts the LCD display into 
4 bit operation mode
*/
void init_LCD							(void);

/*
Function: decimal
Returns: void - nothing
Arguments: int decimal

This function is used to print a decimal value 
to the LCD display in decimal
*/
void decimal							(int decimal);

/*
Function: decimal_to_hex
Returns: void - nothing 
Arguments: int decimal

This function is used to a convert a decimal
value into hex and output it onto the LCD 
display
*/
void decimal_to_hex				(int decimal);

/*
Function: LCD_string
Returns: void - nothing
Arguments: char *string

This function is used to sned an inputted string
onto the LCD display
*/
void LCD_string 					(char *string);

/*
Function: LDC_proportional_bar 
Returns: void - nothing
Arguments: void - nothing 

This function is used to send a bar proportional in 
length to the input voltage of the ADC to the LCD 
display along the bottom line
*/
void LCD_proportional_bar (void);

/*
Function: cursor_set
Returns: void - nothing
Arguments: int column, int row

This function is used to set the cursor postion on the
LCD display. This allows dictation of where on the LCD
display certain features are printed instead of just 
at a predefined, default position
*/
void cursor_set 					(int column, int row);

/*
Function: custom_char_locked
Returns: void - nothing
Arguments: void - nothing 

This function is used to generate the custom locked 
charecter and output it on the top line of the LCD 
display
*/
void custom_char_locked 	(void);

/*
Function: custom_char_unlocked 
Returns: void - nothing
Arguments: void - nothing

This function is used to generate the custom unlocked
character and output it on the top line of the LCD 
display
*/
void custom_char_unlocked (void);           

#endif					 