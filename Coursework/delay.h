#ifndef DELAY_H
#define DELAY_H

#include <stm32f4xx.h>

void init_timer2 			(void);
void init_timer3_2s 			(void);
void init_timer3_1s (void);
void init_timer3_750ms (void);
void init_timer3_500ms (void);
void init_timer3_250ms (void);
void init_timer4 			(void);
void init_timer2 			(void);
void init_timer5_wave	(void);
void variable_delay 	(int t);
void DC_mode (void);
void AC_mode (void);
void sine_mode (void);
void triangle_mode (void);
void square_mode (void);

#endif