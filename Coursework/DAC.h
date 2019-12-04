#ifndef DAC_H
#define DAC_H

#include <stm32f4xx.h>

#define DAC_port 	GPIOA
#define DAC_pin		5

void init_DAC 			(void);
void output_DAC			(unsigned short d);
void DC_output 			(void);
void triangle_wave 	(void);
void sine_wave 			(void);

#endif