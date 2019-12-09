#ifndef LCD_H
#define LCD_H

#include <stm32f4xx.h>
#include "delay.h"
#define LCD_PORT	GPIOD
#define LCD_RS_pin	2		//set up to avoid using the pins that are covered by the FPGA board
#define LCD_RW_pin	0
#define LCD_E_pin		1

#define LCD_D0_pin	0

#define LCD_LINE1		0x80
#define LCD_LINE2		0xc0

#define set_LCD_RS()	LCD_PORT->BSRR=(1u<<LCD_RS_pin)
#define clr_LCD_RS()	LCD_PORT->BSRR=(1u<<(LCD_RS_pin+16))
#define set_LCD_RW()	LCD_PORT->BSRR=(1u<<LCD_RW_pin)
#define clr_LCD_RW()	LCD_PORT->BSRR=(1u<<(LCD_RW_pin+16))
#define set_LCD_E()		LCD_PORT->BSRR=(1u<<LCD_E_pin)
#define clr_LCD_E()		LCD_PORT->BSRR=(1u<<(LCD_E_pin+16))

#define LCD_CLR()		cmd_LCD(0x01)

#define set_LCD_bus_input()		LCD_PORT->MODER&=~(0xff00<<(2*LCD_D0_pin))
#define set_LCD_bus_output()	LCD_PORT->MODER|=(0x5500<<(2*LCD_D0_pin))

void LCD_delay_us(unsigned int us);
void wait_LCD_busy(void);
void set_LCD_data(unsigned char d, int pdt);
void strobe_LCD(void);
void cmd_LCD(unsigned char cmd);
void put_LCD(unsigned char put);
void init_LCD(void);
void decimal(int decimal);
void decimal_to_hex(int decimal);
void LCD_setup (void);  
void LCD_string (char *string);
           
#endif					 