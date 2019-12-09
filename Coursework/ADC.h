#ifndef ADC_H
#define ADC_H

#include <stm32f4xx.h>

#define ADC_input_port	GPIOC
#define ADC_input_pin		0
#define ADC_channel			10
#define ADC_value 

void init_ADC (void);
unsigned short read_ADC (void);
float voltage_ADC (void);
float remainder_ADC (void);
void external_LED_ADC (void);

#endif