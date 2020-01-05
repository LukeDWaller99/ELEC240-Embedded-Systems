#ifndef FPGA_H
#define FPGA_H

#include <stm32f4xx.h>

/*
Function: init_FPGA
Returns: void - nothing
Arguments: void - nothing 

This function is used to setup all the pins on the Nucleo
board for the correct communications the FPGA board. It sets up
the data lines, the enable line, and the packet selector
line
*/
void init_FPGA 						(void);

/*
Function: packet_designator_0
Returns: void - nothing
Arguments: void - nothing 

This function is used to set the packet designator pin
low 
*/
void packet_designator_0 	(void);

/*
Function: packet_designator_1
Returns: void - nothing
Arguments: void - nothing 

This function is used to set the packet designator pin
high
*/
void packet_designator_1 	(void);

/*
Function: flash_pin_on
Returns: void - nothing
Arguments: void - nothing 

This function is used to set the FPGA flash pin high
*/
void flash_pin_on 				(void);

/*
Function: flash_pin_off
Returns: void - nothing
Arguments: void - nothing 

This function is used to set the FPGA flash pin low
*/
void flash_pin_off 				(void);

/*
Function: strobe_FPGA
Returns: void - nothing
Arguments: void - nothing 

This function is used to send the required information to
the FPGA board
*/
void strobe_FPGA 					(void);

/*
Function: data_mask
Returns: short
Arguments: unsigned short ADC_input

This function is used to mask and bit shift the 12 bit
input from the ADC to the required 8 bit input that is 
required for the input of the FPGA board (2 4 bit strobes)

*/
short data_mask 					(unsigned short ADC_input);

/*
Function: send_lsb
Returns: short
Arguments: unsigned short ADC_8_bit

This function is used to send the 4 lsbs to the FPGA
board. It masks the 4 most significant bits so it is 
make into a 4 bit value
*/
short send_lsb 						(unsigned short ADC_8_bit);

/*
Function: send_msb
Returns: short
Arguments: void - nothing 

This function is used to send the 4 msbs to the FPGA 
board. It masks the 4 least significant bits and then 
shifts it 4 bits to the right to make it into a 4 bit 
value
*/
short send_msb 						(unsigned short ADC_8_bit);

/*
Function: send_FPGA_data
Returns: void - nothing
Arguments: unsigned short ADC_lsb, unsigned short ADC_msb 

This function is used to send the data to the FPGA board.
It checks the package designator before strobing the appropriate
data to the FPGA board. This allows 8 bit communication 
using 4 data lines, simiklar to the 4 bit LCD communication.
*/
void send_FPGA_data 			(unsigned short ADC_lsb, unsigned short ADC_msb);

#endif 