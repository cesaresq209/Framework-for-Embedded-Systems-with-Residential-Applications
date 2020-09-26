/*
 * LED.h
 *
 * Created: 26/09/2020 12:35:48 p. m.
 *  Author: brios
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "avr/io.h"

/* LED Pin */
#define LED_PIN PIN5_bm

/* Led State */
#define LED_ON	0
#define LED_OFF	1

void initLED();
void setLED(int newState);






#endif /* GPIO_H_ */