#include "LCD.h"

void lcd_delayus(unsigned int us)		//blocking delay for LCD, argument is approximate number of micro-seconds to delay
{
	unsigned char i;
	while(us--)
	{
		for(i=0; i<SystemCoreClock/4000000; i++)

		{
		__NOP();}
	}
}
void wait_LCD_busy(void)
{
	int port;														//setting variable port
	set_LCD_bus_input();								//Configure Data Bus Lines as Inputs 
	set_LCD_RW();												//Apply Read Command Instructions to LCD
	clr_LCD_RS();
	do {
		set_LCD_E();											//Set Enable bit
		port = LCD_PORT->IDR &= (1<<7);		//Read LCD Port
		clr_LCD_E();											//Reset Enable Bit
	}
	while (port == 0x80);	
	set_LCD_bus_output();								//Configure Data Bus Lines as Digital Output
}

void set_LCD_data(unsigned char d, int val)
{
	LCD_PORT->BSRR=(0xf0<<(LCD_D0_pin+16));	//clear data lines
	if(val == '1')
	{
	LCD_PORT->BSRR=((d << LCD_D0_pin) & 0xF0);					//put data on lines
	}
	if(val == '0')
	{
	LCD_PORT->BSRR=((d << (LCD_D0_pin + 4))& 0xF0);					//put data on lines
	}
}

void strobe_LCD(void)		//10us high pulse on LCD enable line
{
	lcd_delayus(10);
	set_LCD_E();
	lcd_delayus(10);
	clr_LCD_E();
}


void cmd_LCD(unsigned char cmd)		//sends a byte to the LCD control register
{
	wait_LCD_busy();									//wait for LCD to be not busy
	clr_LCD_RS();										//control command
	clr_LCD_RW();										//write command
	set_LCD_data(cmd,'1');					//set data on bus
	strobe_LCD();												//apply command
	
	wait_LCD_busy();											//wait for LCD to be not busy
	clr_LCD_RS();												//control command
	clr_LCD_RW();												//write command
	set_LCD_data(cmd,'0');		//set data on bus
	strobe_LCD();												//apply command
}

void put_LCD(unsigned char put)	//sends a char to the LCD display
{
	wait_LCD_busy();								//wait for LCD to be not busy
	set_LCD_RS();										//text command
	clr_LCD_RW();										//write command
	set_LCD_data(put,'1');					//set data on bus
	strobe_LCD();										//apply command
	
	wait_LCD_busy();								//wait for LCD to be not busy
	set_LCD_RS();										//text command
	clr_LCD_RW();										//write command
	set_LCD_data(put,'0');					//set data on bus
	strobe_LCD();										//apply command
}
void decimal(int decimal)
 {
	char dec[20];
	int array = 0;
	if(decimal == 0)
	{
		put_LCD('0');
	}
	while(decimal > 0)
	{
		dec[array] = (decimal % 10) + 0x30;
		decimal /= 10;
		array++;
	}
	for(int i = array-1; i >=0; i--)
	{
		unsigned char character = dec[i];
		put_LCD(character);
	}
	
}
void decimal_to_hex(int decimal)
{
	char hex[20];
	int array = 0;
	if(decimal == 0)
	{
		put_LCD('0');
	}
	while(decimal > 0)
	{
		switch(decimal % 16)
		{
			case 10:
				hex[array] = 'A'; break;
			case 11:
				hex[array] = 'B'; break;
			case 12:
				hex[array] = 'C'; break;
			case 13:
				hex[array] = 'D'; break;
			case 14:
				hex[array] = 'E'; break;
			case 15:
				hex[array] = 'F'; break;
			default:
				hex[array] = (decimal % 16) + 0x30;
		}
		decimal /= 16;
		array++;
	}
	for(int i = array-1; i >= 0; i--)
	{
		unsigned char character = hex[i];
		put_LCD(character);
	}
}
void init_LCD(void)
{
		SystemCoreClockUpdate();
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;	//enable LCD port clock
	
			//CONFIG LCD GPIO PINS
		LCD_PORT->MODER&=~(					//clear pin direction settings
			(3u<<(2*LCD_RS_pin))|
			(3u<<(2*LCD_RW_pin))|
			(3u<<(2*LCD_E_pin))	|
			(0xff00<<(2*LCD_D0_pin))
			);
	
	LCD_PORT->MODER|=(				//reset pin direction settings to digital outputs
			(1u<<(2*LCD_RS_pin))|
			(1u<<(2*LCD_RW_pin))|
			(1u<<(2*LCD_E_pin))	|
			(0x5500<<(2*LCD_D0_pin))
		);
	
			//LCD INIT COMMANDS
	clr_LCD_RS();					//all lines default low
	clr_LCD_RW();
	clr_LCD_E();
	
	lcd_delayus(5000);		//25ms startup delay
	cmd_LCD(0x28);				//Function set: 2 Line, 4-bit, 5x7 dots
	cmd_LCD(0x0F);				//Display on, Cursor blinking command
	cmd_LCD(0x01);				//Clears the LCD
	cmd_LCD(0x06);				//Entry mode, auto increment with no shift
}
void LCD_setup (void)
{
	cmd_LCD(LCD_LINE1);
	put_LCD('A');
	put_LCD('A');
	put_LCD('A');
	put_LCD('A');
}


