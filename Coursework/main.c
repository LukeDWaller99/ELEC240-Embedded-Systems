#include <stm32f4xx.h>	//includes the header file for this MCU family
												//this file contains the definitions for the regiset adresses and values etc...
#include "init.h"

int main(void)
{
	
init_all_components();
                                                                                                                                                                                                                           
	while (1)
	{
		__WFI();
	}
}