#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx.h"
void pa1_adc_init(void);
void adc_start_convertion(void);
uint32_t adc_read(void);

#endif /* ADC_H_ */
