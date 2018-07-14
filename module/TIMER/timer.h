#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"



#define TIMER  (timer*0.01+TIM2->CNT/100000.)


void TIM3_Int_Init(u16 arr,u16 psc);
void TIM2_Int_Init(u16 arr,u16 psc);
 
#endif
