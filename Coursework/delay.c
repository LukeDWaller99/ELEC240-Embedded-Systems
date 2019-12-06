#include "delay.h"
#include "LED.h"
#include "ADC.h"
#include "DAC.h"

void init_timer2 (void) 
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;		//clock for timer 2 enabled
	TIM2->DIER|=TIM_DIER_UIE;						//enabled timer update interrupt
																			//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM2->PSC=256-1;										//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM2->ARR=73230;										//counter reload value, this sets the period of the timer to 208ms when F_APB =90MHz and PSC = 256
	TIM2->CNT=0;												//zero timer counter 
  NVIC->ISER[0]|=(1u<<28);						//timer 2 interrupt enabled
	TIM2->CR1|=TIM_CR1_CEN;							//timer counter start
}

void init_timer3 (void)
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;		//clock for timer 3 enabled
	TIM3->DIER|=TIM_DIER_UIE;						//enabled timer update interrupt
																			//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM3->PSC=256-1;										//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM3->ARR=35156;										//counter reload value, this sets the period of the timer to 100ms when F_APB =90MHz and PSC = 256
	TIM3->CNT=0;												//zero timer counter 
	NVIC->ISER[0]|=(1u<<29);						//timer 3 interrupt enabled
	TIM3->CR1|=TIM_CR1_CEN;							//timer counter start
}

void init_timer4 (void)
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM4EN;		//clock for timer 4 enabled
	TIM4->DIER|=TIM_DIER_UIE;						//enabled timer update interrupt
																			//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM4->PSC=256-1;										//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM4->ARR=35156;										//counter reload value, this sets the period of the timer to 100ms when F_APB =90MHz and PSC = 256
	TIM4->CNT=0;												//zero timer counter 
	NVIC->ISER[0]|=(1u<<30);						//timer 4 interrupt enabled
	TIM4->CR1|=TIM_CR1_CEN;							//timer counter start
}
void init_timer5_wave (void) 				//timer set at 48KHz
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM5EN;		//clock for timer 5 enabled
	TIM5->DIER|=TIM_DIER_UIE;						//enabled timer update interrupt
																			//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM5->PSC=11-1;											//APB clock is divided by 2 = 90MHz/2 = 45MHz
	TIM5->ARR=187;											//counter reload value, this sets the period of the timer to 10us when F_APB = 90MHz and the PSC = 256
	TIM5->CNT=0;												//zero timer counter
	NVIC->ISER[1]|=(1u<<18) ;						//timer 5 interrupt enabled
	TIM5->CR1|=TIM_CR1_CEN;							//timer 5 counter start
}
void TIM2_IRQHandler (void) 					//timer 2 interrupt routine
{
	TIM2->SR&=~TIM_SR_UIF;							//interrupt flag cleared in status register
	toggle_red_LED();										//toggles the red LED
}	
void TIM3_IRQHandler (void)						//timer 3 interrupt routine
{
	TIM3->SR&=~TIM_SR_UIF;							//interrupt flag cleared in status register
	toggle_blue_LED();									//toggles the blue LED
}
void TIM4_IRQHandler (void)						//timer 4 interrupt routine
{
	TIM4->SR&=~TIM_SR_UIF;							//interrupt flag cleared in status register 
}
void TIM5_IRQHandler (void)
{
	TIM5->SR&=~TIM_SR_UIF;							//interrupt flag cleared in status register
	triangle_wave();										//runs the code the triangle wave
}