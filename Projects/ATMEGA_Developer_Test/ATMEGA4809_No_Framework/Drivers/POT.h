/*
 * ADC.h
 *
 * Created: 26/09/2020 12:35:25 p. m.
 *  Author: usuario
 */ 


#ifndef ADC_H_
#define ADC_H_

/* RTC Period */
#define RTC_PERIOD            (511)

#include "avr/io.h"
#include <avr/interrupt.h>

void initPOT();
uint16_t getPotValue();




#endif /* ADC_H_ */