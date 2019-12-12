#include "delay.h"
#include "LED.h"
#include "ADC.h"
#include "DAC.h"
#include "stdint.h"
#include "LCD.h"
#include "string.h"
#include "USART.h"

void init_timer2 (void) 													//timer set for the red LED interrupt at 4.7Hz
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;								//clock for timer 2 enabled
	TIM2->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM2->PSC=30000-1;																//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM2->ARR=313;																	//counter reload value, this sets the period of the timer to 208ms when F_APB =90MHz and PSC = 256
	TIM2->CNT=0;																		//zero timer counter 
  NVIC->ISER[0]|=(1u<<28);												//timer 2 interrupt enabled
	TIM2->CR1|=TIM_CR1_CEN;													//timer counter start
}
void init_timer3_2s (void)												//timer set for the green LED interrupt at0.5Hz
                                                                                                                                                                                                                                                              {
	RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;								//clock for timer 3 enabled
	TIM3->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM3->PSC=30000-1;															//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM3->ARR=6000;																	//counter reload value, this sets the period of the timer to 100ms when F_APB =90MHz and PSC = 256
	TIM3->CNT=0;																		//zero timer counter 
	NVIC->ISER[0]|=(1u<<29);												//timer 3 interrupt enabled
	TIM3->CR1|=TIM_CR1_CEN;													//timer counter start
}
void init_timer3_1s (void)												//timer set for the green LED interrupt at 1Hz
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;								//clock for timer 3 enabled
	TIM3->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM3->PSC=30000-1;															//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM3->ARR=3000;																	//counter reload value, this sets the period of the timer to 100ms when F_APB =90MHz and PSC = 256
	TIM3->CNT=0;																		//zero timer counter 
	NVIC->ISER[0]|=(1u<<29);												//timer 3 interrupt enabled
	TIM3->CR1|=TIM_CR1_CEN;													//timer counter start
}
void init_timer3_500ms (void)											//timer set for the green LED interrupt at 2Hz
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;								//clock for timer 3 enabled
	TIM3->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM3->PSC=3000-1;																//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM3->ARR=2000;																	//counter reload value, this sets the period of the timer to 100ms when F_APB =90MHz and PSC = 256
	TIM3->CNT=0;																		//zero timer counter 
	NVIC->ISER[0]|=(1u<<29);												//timer 3 interrupt enabled
	TIM3->CR1|=TIM_CR1_CEN;													//timer counter start	
}
void init_timer3_250ms (void)											//timers set for the green LED interrupt at 4Hz
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;								//clock for timer 3 enabled
	TIM3->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM3->PSC=3000-1;																//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM3->ARR=1000;																	//counter reload value, this sets the period of the timer to 100ms when F_APB =90MHz and PSC = 256
	TIM3->CNT=0;																		//zero timer counter 
	NVIC->ISER[0]|=(1u<<29);												//timer 3 interrupt enabled
	TIM3->CR1|=TIM_CR1_CEN;													//timer counter start	
}
void init_timer4 (void)														//timer for the propertional LED bar running at 0.5Hz
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM4EN;								//clock for timer 4 enabled
	TIM4->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM4->PSC=30000-1;															//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM4->ARR=2000;																	//counter reload value, this sets the period of the timer to 100ms when F_APB =90MHz and PSC = 256
	TIM4->CNT=0;																		//zero timer counter 
	NVIC->ISER[0]|=(1u<<30);												//timer 4 interrupt enabled
	TIM4->CR1|=TIM_CR1_CEN;													//timer counter start
}
void init_timer5_wave (void)											//timer set to 48KHz used for the waves
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM5EN;								//clock for timer 5 enabled
	TIM5->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM5->PSC=11-1;																	//APB clock is divided by 2 = 90MHz/2 = 45MHz
	TIM5->ARR=187;																	//counter reload value, this sets the period of the timer to 10us when F_APB = 90MHz and the PSC = 256
	TIM5->CNT=0;																		//zero timer counter
	NVIC->ISER[1]|=(1u<<18);												//timer 5 interrupt enabled
	TIM5->CR1|=TIM_CR1_CEN;													//timer 5 counter start
}
void init_timer7 (void)														//timer set to XXXX for the Morse code
{
	RCC->AHB1ENR|=RCC_APB1ENR_TIM7EN;								//clock for timer 7 enabled 
	TIM7->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 108MHz/2 = 90MHz
	TIM7->PSC=30000-1;	
	TIM7->ARR=6000;
	TIM7->CNT=0;
	NVIC->ISER[1]|=(1u<<23);
	TIM5->CR1|=TIM_CR1_CEN;
}
void variable_delay_timer (uint32_t n)
{
	CoreDebug->DEMCR|=CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CYCCNT=0;
	DWT->CTRL|=DWT_CTRL_CPIEVTENA_Msk;
	uint32_t start, cnt;
	start = DWT->CYCCNT;
	cnt = n*(SystemCoreClock/1000000);
	while(((DWT->CYCCNT - start))<cnt);
}
void variable_delay (int delay)										//variable timer set in ms
{
	int t = 0;																			//
	while(t<(SystemCoreClock/(18000/delay)))
	{
		__NOP();
		t++;
	}
}
int red_LED= 1;
int blue_LED = 1;
int green_LED = 1;
int wave_selector =0;
void TIM2_IRQHandler (void) 	
{
	TIM2->SR&=~TIM_SR_UIF;							//interrupt flag cleared in status register
	if(red_LED == 1)
		{
		red_LED_off();
		red_LED = 0;
		}
	else if(red_LED == 0)
		{
		red_LED_on();
		red_LED = 1;
		}
}	
void TIM3_IRQHandler (void)						
{
	TIM3->SR&=~TIM_SR_UIF;							//interrupt flag cleared in status register
	if(green_LED == 1)
	{
		green_LED_off();
		green_LED = 0;
	}
	else if(green_LED ==0)
	{
		green_LED_on();
		green_LED = 1;
	}
}
void TIM4_IRQHandler (void)				
{
	TIM4->SR&=~TIM_SR_UIF;							//interrupt flag cleared in status register 
	voltage_display();
}
void TIM5_IRQHandler (void)
{
	TIM5->SR&=~TIM_SR_UIF;							//interrupt flag cleared in status register
	if(wave_selector == 1)
	{
		DC_output();
	}
	else if(wave_selector == 2)
	{
		triangle_wave();										//runs the code the triangle wave
	}
	else if(wave_selector == 3)
	{
		sine_wave();	
	}
	else if(wave_selector == 4)
	{
		square_wave(); 
	}
}
void TIM7_IRQHandler (void)
{
	TIM7->SR&=~TIM_SR_UIF;	//interrupt flag cleared in status register 
	
}
void DC_mode (void)
{
	myPrintf("DC:\n\r");
	LCD_CLR();
	init_timer3_2s();
	cursor_set(1,1);
	LCD_string("DC");
	wave_selector = 1;
	init_timer4();                     
}

void square_mode (void)
{
	LCD_CLR();
	init_timer3_1s();
	cursor_set(1,1);
	LCD_string("Square");
	wave_selector = 4;
	init_timer4();   
}
void sine_mode (void)
{
	LCD_CLR();
	init_timer3_500ms();
	cursor_set(1,1);
	LCD_string("Sine");
	wave_selector = 3;
	init_timer4();   
}
void triangle_mode (void)
{
	LCD_CLR();
	init_timer3_250ms();
	cursor_set(1,1);
	LCD_string("Triangle");
	wave_selector = 2;
	init_timer4();   
}