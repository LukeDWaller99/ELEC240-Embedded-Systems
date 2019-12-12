#ifndef SWITCH_H
#define SWITCH_H
#include <stm32f4xx.h>

void init_blue_switch (void);
void EXTI15_10_IRQHandler (void);
void unlock_animation (void);

#endif