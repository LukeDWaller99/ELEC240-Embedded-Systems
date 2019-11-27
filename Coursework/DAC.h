#include <stm32f4xx.h>

#define DAC_port 	GPIOA
#define DAC_pin		5

void init_DAC (void);
void output_DAC	(unsigned short d);