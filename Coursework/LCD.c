#include "LCD.h"
#include "string.h"
#include "ADC.h"

void LCD_delay_us(unsigned int us)						//blocking delay for LCD, argument is approximate number of micro-seconds to delay
{
	unsigned char i; 														//create unsigned char i
	while(us--) 																//while the value of us = us -1
	{
		for(i=0; i<SystemCoreClock/4000000; i++) 	//for the values of i between 0 and SystemCoreClock (180000000) over 4000000
		{
			__NOP();																//no operation while the above statment is true, creating a blocking delay
		}
	}
}
void wait_LCD_busy(void)                  		//wats for the LCD to be ready by checking the wait busy flag                                     
{                                        
	int i = 1;																	//create an int i = 1
	
	set_LCD_bus_input();												//sets the LCD bus input
	clr_LCD_RS();																//clears the control command 
	set_LCD_RW();																//sets the write command
	
	while(i)																		//while i
	{
		set_LCD_E();															//high on the LCD enable line
		LCD_delay_us(10);													//wait of 10us
		i = LCD_PORT->IDR;												//maps the LCD port pin equal i
		i &= (1u<<7);															//sets the LCD port pin 
		clr_LCD_E();															//set the LCD enable pin low 
		LCD_delay_us(10);													//wait of 10us
		strobe_LCD();															//strobe_LCD the LCD
	}
		set_LCD_bus_output();											//set the LCD bus back to output
		clr_LCD_RW();															//clears the write command 
}
void set_LCD_data(unsigned char d, int val)		//sets the data for the LCD
{
	LCD_PORT->BSRR=(0xf0<<(LCD_D0_pin+16));			//clear data lines
	if(val == '1')
	{
	LCD_PORT->BSRR=((d<<LCD_D0_pin)&0xF0);			//put data on lines
	}
	if(val == '0')
	{
	LCD_PORT->BSRR=((d<<(LCD_D0_pin+4))&0xF0);	//put data on lines
	}
}

void strobe_LCD(void)													//10us high pulse on LCD enable line
{
	LCD_delay_us(10);														//wait of 10us
	set_LCD_E(); 																//high on the LCD enable line
	LCD_delay_us(10); 													// wait of 10us
	clr_LCD_E(); 																//low on the LCD enable line
}
void cmd_LCD(unsigned char cmd)								//sends a byte to the LCD control register
{
	wait_LCD_busy();														//wait for LCD to be not busy
	clr_LCD_RS();																//control command
	clr_LCD_RW();																//write command
	set_LCD_data(cmd,'1');											//set data on bus
	strobe_LCD();																//apply command
	
	wait_LCD_busy();														//wait for LCD to be not busy
	clr_LCD_RS();																//control command
	clr_LCD_RW();																//write command
	set_LCD_data(cmd,'0');											//set data on bus
	strobe_LCD();																//apply command
}
void put_LCD(unsigned char put)								//sends a char to the LCD display
{
	wait_LCD_busy();														//wait for LCD to be not busy
	set_LCD_RS();																//text command
	clr_LCD_RW();																//write command
	set_LCD_data(put,'1');											//set data on bus
	strobe_LCD();																//apply command
	
	wait_LCD_busy();														//wait for LCD to be not busy
	set_LCD_RS();																//text command
	clr_LCD_RW();																//write command
	set_LCD_data(put,'0');											//set data on bus
	strobe_LCD();																//apply command
}
void decimal(int decimal)											//sends a decimal number to the LCD display from a decimal input
 {
	char dec[20];																//sets up array for the decimal input for the LCD 
	int array = 0; 															//sets the initial value of the array to 0
	if(decimal == 0) 														//if the value of decimal is 0
	{
		put_LCD('0'); 														//put out a 0 on the LCD
	}
	while(decimal > 0) 													//while the decimal value is greater than 0
	{
		dec[array] = (decimal % 10) + 0x30; 			//divide the decimal by 10 and put the remainder value into the array 
		decimal /= 10; 														//diveide the remainder by 10
		array++; 																	//add one extra byte to the array 
	}
	for(int i = array-1; i >=0; i--) 						//for all the values of the array 
	{
		unsigned char character = dec[i]; 				//call the value of byte 'i' in the array and convert it to a char  
		put_LCD(character); 											//write the char value to the LCD.
	}
	
}
void decimal_to_hex(int decimal)							//sends a hex number to the output of the LCD from a decimal input
{
	char hex[20]; 															//sets up an array for the decimal to hex input for the LCD
	int array = 0;															//set the initial value of the array to 0
	if(decimal == 0) 														//if the value of decimal is 0
	{
		put_LCD('0'); 														//put a 0 onto the LCD display
	}
	while(decimal > 0) 													//while the decimal value is greater than 0
	{
		switch(decimal % 16)											//divide the decimal number by 16
		{
			case 10:
				hex[array] = 'A'; break;							//if the number is 10, output an A into the array
			case 11:
				hex[array] = 'B'; break;							//if the number is 11, output a B into the array
			case 12:
				hex[array] = 'C'; break; 							//if the number is 12, output a C into the array
			case 13:
				hex[array] = 'D'; break; 							//if the number is 13, output a D into the array
			case 14:
				hex[array] = 'E'; break; 							//if the number is 14, output an E onto the array
			case 15: 
				hex[array] = 'F'; break; 							//if the number if 15, output an F onto the array 
			default:
				hex[array] = (decimal % 16) + 0x30; 	//if the number is less than 10, output the decimal value into the array 
		}
		decimal /= 16;														//divide the decimal number by 
		array++;																	//add one extra byte to the array
	}
	for(int i = array-1; i >= 0; i--) 					//for all the values of the array 
	{
		unsigned char character = hex[i]; 				//call the value of bit 'i' in the array and convert it to a char  
		put_LCD(character); 											//write the char value to the LCD.
	}
}
void init_LCD(void)														//intialises the LCD into 4 bit mode
{
		SystemCoreClockUpdate();
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;				//enable LCD port clock
	
			//CONFIG LCD GPIO PINS
		LCD_PORT->MODER&=~(												//clear pin direction settings
			(3u<<(2*LCD_RS_pin))|
			(3u<<(2*LCD_RW_pin))|
			(3u<<(2*LCD_E_pin))	|
			(0xff00<<(2*LCD_D0_pin))
			);
	
	LCD_PORT->MODER|=(													//reset pin direction settings to digital outputs
			(1u<<(2*LCD_RS_pin))|
			(1u<<(2*LCD_RW_pin))|
			(1u<<(2*LCD_E_pin))	|
			(0x5500<<(2*LCD_D0_pin))
		);
	
	//LCD INIT COMMANDS
	clr_LCD_RS();																//all lines default low
	clr_LCD_RW();
	clr_LCD_E();
	
	LCD_delay_us(25000);												//25ms startup delay
	cmd_LCD(0x28);															//Function set: 2 Line, 4-bit, 5x7 dots
	cmd_LCD(0x0F);															//Display on, Cursor blinking command
	cmd_LCD(0x01);															//Clears the LCD
	cmd_LCD(0x06);															//Entry mode, auto increment with no shift
}
void LCD_string (char *string)								//sends a string of data to the LCD display
{
	LCD_CLR();																	//clear the LCD display
	cmd_LCD(LCD_LINE1);													//sets the cursor to the start of Line 1 on the LCD display
	int string_length = strlen(string); 				//write the value of the length of the string to an int
	for( int i = 0; i<= string_length -1; i++)	//for valus of string length up to string length -1
	{
		char character = string[i]; 							//write the corresponding value of the array to char character 
		put_LCD(character);												//put_LCD the character out onto the LCD display
	}
}
void LCD_proportional_bar (void)							//send a bar proportional to the input voltae on the ADC
{
	unsigned int data_ADC; 											//create an unsigned int called data_ADC
	data_ADC = read_ADC; 												//map the value of read_ADC to data_ADC
	unsigned int bar_value_array[16] = 
		 {2, 		254, 	508,	762,
			1016,	1270,	1524,	1778,
			2032,	2286,	2540,	2794,
			3048,	3302,	3556,	3810}; 								// creates an array of 16 bytes with the values shown 
	cmd_LCD(LCD_LINE2);													//sets the cursor to the start of the second line on the LCD
	for(int  c=0; c<16; c++) 										//for all the values of c between 0 and 16
	{
		if(data_ADC > bar_value_array[c]) 				//check if the value of data_ADC is greater than bar_value_array[c]
		{
			LCD_CLR(); 															//clear the LCD display
			put_LCD('-'); 													//if the value is greater put a bar onto the LCD
		}
	}		
}