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
	TIM2->PSC=30000-1;															//APB clock divided by 256 = 90MHz/256 = 351KHz
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
	TIM3->ARR=6000;																	//counter reload value, this sets the period of the timer to 2s when F_APB =90MHz and PSC = 30000
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
	TIM3->ARR=3000;																	//counter reload value, this sets the period of the timer to 1s when F_APB =90MHz and PSC = 30000
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
	TIM3->ARR=2000;																	//counter reload value, this sets the period of the timer to 500ms when F_APB =90MHz and PSC = 3000
	TIM3->CNT=0;																		//zero timer counter 
	NVIC->ISER[0]|=(1u<<29);												//timer 3 interrupt enabled
	TIM3->CR1|=TIM_CR1_CEN;													//timer counter start	
}
void init_timer3_250ms (void)											//timer set for the green LED interrupt at 4Hz
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;								//clock for timer 3 enabled
	TIM3->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 180MHz/2 = 90MHz
	TIM3->PSC=3000-1;																//APB clock divided by 256 = 90MHz/256 = 351KHz
	TIM3->ARR=1000;																	//counter reload value, this sets the period of the timer to 250ms when F_APB =90MHz and PSC = 3000
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
void init_timer7 (void)														//timer set to 1s for the cumstom char
{
	RCC->AHB1ENR|=RCC_APB1ENR_TIM7EN;								//clock for timer 7 enabled 
	TIM7->DIER|=TIM_DIER_UIE;												//enabled timer update interrupt
																									//the APB clock is FCY/2 = 108MHz/2 = 90MHz
	TIM7->PSC=30000-1;															//APB clock is divided by 2 = 90MHz/2 = 45MHz
	TIM7->ARR=3000;																	//counter reload value, this sets the period of the timer to 1s when F_APB = 90MHz and the PSC = 30000
	TIM7->CNT=0;																		//zero timer counter
	NVIC->ISER[1]|=(1u<<23);												//timer 7 interrupt enabled
	TIM7->CR1|=TIM_CR1_CEN;													//timer 7 count start 
}
void variable_delay_timer (uint32_t n)						//variable timer set in us
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
	int t = 0;																			//create variable t and set it to 0
	while(t<(SystemCoreClock/(18000/delay)))				//while t < value of delay
	{
		__NOP();																			//no operation (block the processor from operating)
		t++;																					//increment t
	}
}

int red_LED= 1;																		//create variable red_LED and set to 1
int blue_LED = 1;																	//create variable blue_LED and set to 1 
int green_LED = 1;																//create variable green_LED and set to 1
int wave_selector =0;															//create variable wave_selector and set to 0

void TIM2_IRQHandler (void) 											//handler for timer 2 interrupt to toggle the red LED
{
	TIM2->SR&=~TIM_SR_UIF;													//interrupt flag cleared in status register
	if(red_LED == 1)																//if red_LED = 1						
		{										
		red_LED_off();																//turn the red LED off 
		red_LED = 0;																	//set red_LED to 0
		}
	else if(red_LED == 0)														//if red_LED =0
		{
		red_LED_on();																	//turn the red LED on
		red_LED = 1;																	//set red_LED to 1
		}
}	
void TIM3_IRQHandler (void)												//handler for timer 3 interrupt to toggle the green LED
{
	TIM3->SR&=~TIM_SR_UIF;													//interrupt flag cleared in status register
	if(green_LED == 1)															//if green_LED = 1
	{
		green_LED_off();															//turn the green LED off 
		green_LED = 0;																//set green_LED to 0
	}
	else if(green_LED ==0)													//if green LED = 0
	{
		green_LED_on();																//turn the green LED on
		green_LED = 1;																//set green_LED to 1
	}
}
void TIM4_IRQHandler (void)												//handler for timer 4 interrupt to update the voltage display
{
	TIM4->SR&=~TIM_SR_UIF;													//interrupt flag cleared in status register 
	voltage_display();															//call voltage_display 
}
void TIM5_IRQHandler (void)												//handler for timer 5 interrupt to select wave output type on the DAC
{
	TIM7->SR&=~TIM_SR_UIF;													//interrupt flag cleared in status register
	if(wave_selector == 1)													//if wave_selector = 1
	{
		DC_output();																	//set to DC output mode
	}
	else if(wave_selector == 2)											//if wave_selector = 2
	{
		triangle_wave();															//set to traingle wave output mode 
	}
	else if(wave_selector == 3)											//if wave_selector = 3
	{
		sine_wave();																	//set to sine wave output mode
	}
	else if(wave_selector == 4)											//if wave_selector = 4
	{
		square_wave(); 																//setbuf to square wave output mode
	}
}
void TIM7_IRQHandler (void)												//handler for timer 7 interrupt to animate the custom char
{
	TIM7->SR&=~TIM_SR_UIF;													//interrupt flag cleared in status register 
	custom_char_locked();														//use custom char locked 
	variable_delay(1000);														//variable_delay delay set to 1s
	custom_char_unlocked();													//use custom char unlocked 
}
void DC_mode (void)																//DC mode
   {

	LCD_CLR();																			//clear the LCD 
	init_timer3_2s();																//initialise timer 3 at 0.5Hz
	cursor_set(1,1);																//set the cursor to the 1st column and row
	LCD_string("DC");																//put "DC" onto the LCD 
	wave_selector = 1;															//set the wave_selecotr to 1
	init_timer4();                    							//initlise timer 4
}
void square_mode (void)														//square mode 
{
	LCD_CLR();																			//clear the LCD
	init_timer3_1s();																//initialise timer 3 at 1Hz 
	cursor_set(1,1);																//set the cursor to the 1st column and row 
	LCD_string("Square");														//put "Square" onto the LCD
	wave_selector = 4;															//set the wave_selector to 4
	init_timer4();  																//initilise timer 4
}
void sine_mode (void)															//sine mode 
{
	LCD_CLR();																			//clear the LCD
	init_timer3_500ms();														//intialise timer 3 at 2Hz
	cursor_set(1,1);																//set the cursor to the 1st column and row
	LCD_string("Sine");															//put "Sine" onto the LCD
	wave_selector = 3;															//set the wave_selector to 3
	init_timer4(); 																	//initialise timer 4
}
void triangle_mode (void)													//tirangle mode
{
	LCD_CLR();																			//clear the LCD 
	init_timer3_250ms();														//initialise timer 3 at 4Hz
	cursor_set(1,1);																//set the cursor to the 1st column and row 
	LCD_string("Triangle");													//put "Triangle" onto the LCD
	wave_selector = 2;															//set the wave selector to 2
	init_timer4();  																//initialise timer 4
}