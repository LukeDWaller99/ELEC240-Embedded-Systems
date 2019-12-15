#ifndef FPGA_H
#define FPGA_H

#include <stm32f4xx.h>

void init_FPGA (void);
void packet_designator_0 (void);
void packet_designator_1 (void);
void flash_pin_on (void);
void flash_pin_off (void);
void strobe_FPGA (void);
short data_mask (unsigned short ADC_input);
short send_lsb (unsigned short ADC_b_bit);
short send_msb (unsigned short ADC_8_bit);
void send_FPGA_data (unsigned short ADC_lsb, unsigned short ADC_msb);

#endif 