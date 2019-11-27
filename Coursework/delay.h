#ifndef DELAY_H
#define DELAY_H

#include "stm32f4xx.h"

void init_timer2 			(void);
void init_timer3 			(void);
void init_timer4 			(void);
void init_timer2_5Hz 	(void);
void init_timer5_10us	(void);

#endif