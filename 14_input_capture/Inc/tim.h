#ifndef TIM_H_
#define TIM_H_

#include "stm32f4xx.h"
void tim4_1hz_init(void);
void tim4_pd15_output_compare(void);
void tim3_pa6_input_capture(void);
#define SR_UIF		(1U<<0)
//CAPTURE/COMPARE 1 INTERRUPT FLAG
#define SR_CC1IF	(1U<<1)
#endif /* TIM_H_ */
