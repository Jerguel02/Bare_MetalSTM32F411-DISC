#ifndef TIM_H_
#define TIM_H_

#include "stm32f4xx.h"
void tim4_1hz_init(void);
void tim4_pd15_output_compare(void);
#define SR_UIF		(1U<<0)
#endif /* TIM_H_ */
