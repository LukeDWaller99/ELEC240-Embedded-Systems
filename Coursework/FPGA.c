#include "FPGA.h"
#include "delay.h"
#include "LCD.h"
#include "ADC.h"

void init_FPGA (void)
{
	//enable ports 
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOEEN;		//GPIO E clock enabled
	
	//configure port pin functions for data line PE_15 (bit 0 )
	GPIOE->MODER&=~(3u<<(2*15));					//clear pin function on GPIOE 	- data line PE_15
	GPIOE->MODER|=(1u<<(2*15));						//set new pin function on GPIOE - data line PE_15
	
	//configure port pin functions for data line PE_12 (bit 1)
	GPIOE->MODER&=~(3u<<(2*12));					//clear pin function on GPIOE	- data line PE_12
	GPIOE->MODER|=(1u<<(2*12));						//set new pin function on GPIOE - data line PE_12
	
	//configure port pin functions for data line PE_10 (bit 2)
	GPIOE->MODER&=~(3u<<(2*10));				//clear pin function on GPIOE - data line PE_10
	GPIOE->MODER|=(1u<<(2*10));					//set new pin function on GPIOE - data line PE_10
	
	//configure port pin functions for data line PE_2 (bit 3)
	GPIOE->MODER&=~(3u<<(2*2));					//clear pin function on GPIOE - data line PE_2
	GPIOE->MODER|=(1u<<(2*2));					//set new pin function on GPIOE - data line PE_2
	
	//configure port pin functions for the packet designator PB_11
	GPIOB->MODER&=~(3u<<(2*11));					//clear pin function on GPIOB - control line PB_11
	GPIOB->MODER|=(1u<<(2*11));					//set new pin function on GPIOB - control line PB_1
	
	//configure port pin functions for LED state flash PB_10
	GPIOB->MODER&=~(3u<<(2*10));				//clear pin function on GPIOB - control line PB_10
	GPIOB->MODER|=(1u<<(2*10));					//set new pin function on GPIOB - control line PB_10
}
void packet_designator_0 (void) //set the packet designator to 0
{
	GPIOB->BSRR |= 27;
}
void packet_designator_1 (void) //set the packet designator to 1
{
	GPIOB->BSRR |= 11;
}
void flash_pin_on (void) //sets the flash pin to 1
{
	GPIOB->BSRR |= 26; 
}
void flash_pin_off (void) //sets the flash pin to 0
{
	GPIOB->BSRR |= 10;
}
void strobe_FPGA (void)
{
	flash_pin_on();
	LCD_delay_us(1);
	flash_pin_off();
}

void input_ADC (void) //masks and shifts the data from the ADC
{
	unsigned short ADC_input; //create an unsigned short for ADC input
	ADC_input = read_ADC(); //puts the values of the ADC in to the ADC_input
	
	ADC_input = data_mask(ADC_input); 
}
short data_mask (unsigned short ADC_input)
{
	short ADC_8_bit; //creates a short called ADC_8_bit
	ADC_input &= 0xFF0; //maks the 4 least significant bits of the 12 bit value
	ADC_input = ADC_8_bit >> 4; //shift left by 4 bits to make it an 8 bit value 
	return ADC_8_bit; //returns the 8 bit value
}
short send_lsb (unsigned short ADC_8_bit) //send the least significant bits
{
	short ADC_lsb; //create a short called ADC_lsb
	ADC_8_bit &= 0x0F; //masks the 4 most significant bits
	return ADC_lsb;
}
short send_msb (unsigned short ADC_8_bit) //send the most significant bits 
{
	short ADC_msb; //create a short called ADC_msb
	ADC_8_bit &= 0xF0; //masks the 4 least significant bits
	ADC_msb = ADC_8_bit >> 4; //shifts left by 4 bits to make it a 4 bit value
	return ADC_msb;
}
void send_FPGA_data (unsigned short ADC_lsb, unsigned short ADC_msb)
{ 
	int bit_value;
	int control =0;  //create a varibale called control 
	if ( control ==0) //if control = o
	{
		packet_designator_0(); //set the packet designator to 0
		for (int bit_num = 0; bit_num		< 4; bit_num ++)
		{
			bit_value = ADC_lsb &= 0x01; //mask the value of ADC_lsb 
			
			if (bit_num == 0)
			{
				if (bit_value == 1)
				{
					GPIOB -> BSRR |= (1u<<15);
				}
				else if (bit_value == 0)
				{
					GPIOB -> BSRR |= (1u<<(15 + 16));
				}
			}
			else if (bit_num == 1)
			{
				if (bit_value == 1)
				{
					GPIOB -> BSRR |= (1u<<12);
				}
				else if (bit_value == 0)
				{
					GPIOB -> BSRR |= (1u<<(12+16));
				}
			}
			else if (bit_num == 2)
			{
				if (bit_value == 1)
				{
					GPIOB -> BSRR |= (1u<<10);
				}
				else if (bit_value == 0)
				{
					GPIOB -> BSRR |= (1u<<(10+16));
				}
			}
			else if (bit_num == 3)
			{
				if (bit_value ==1)
				{
					GPIOB -> BSRR |= (1u<<2);
				}
				else if (bit_value == 0)
				{
					GPIOB -> BSRR |= (1u<<(2+16));
				}
			}
			ADC_lsb &= 0xE; //mask the least significant bit
			ADC_lsb = ADC_lsb >> 1; //shift the value right by 1 
		}
		strobe_FPGA(); //strobe to the FPGA board 
		control = 1; //set control to 1
	}
	else if ( control == 1) //if control = 1
	{
		packet_designator_1(); //set the packet designator to 1
		for (int bit_num; bit_num		< 4; bit_num ++)
		{
			bit_value = ADC_msb &= 0x01; //mask the value of the lsb of ADC_msb
			
			if (bit_num == 0)
			{
				if (bit_value == 1)
				{
					GPIOB -> BSRR |= (1u<<15);
				}
				else if (bit_value == 0)
				{
					GPIOB -> BSRR |= (1u<<(15+16));
				}
			}
			else if (bit_num == 1)
			{
				if (bit_value == 1)
				{
					GPIOB -> BSRR |= (1u<<12);
				}
				else if (bit_value == 0)
				{
					GPIOB -> BSRR |= (1u<<(12+16)); 
				}
			}
			else if (bit_num == 2)
			{
				if (bit_value == 1)
				{
					GPIOB -> BSRR |= (1u<<10);
				}
				else if (bit_value == 0)
				{
					GPIOB -> BSRR |= (1u<<(10+16));
				}
			}
			else if (bit_num == 3)
			{
				if (bit_value == 1)
				{
					GPIOB -> BSRR |= (1u<<2);
				}
				else if (bit_value == 0)
				{
					GPIOB -> BSRR |= (1u<<(2+16));
				}
			}
			ADC_msb &= 0xE; //mask the least significant bit 
			ADC_msb = ADC_msb >> 1; //shift the value right by 1 
		}
		strobe_FPGA(); //strobe to the FGPA Board 
		 control = 0; //set control to 0
	}
}