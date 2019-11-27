#ifndef ADC_H
#define ADC_H

#include <stm32f4xx.h>

#define ADC_input_port	GPIOC
#define ADC_input_pin		0
#define ADC_channel			10

void init_ADC (void);
unsigned short read_ADC (void);

#endif