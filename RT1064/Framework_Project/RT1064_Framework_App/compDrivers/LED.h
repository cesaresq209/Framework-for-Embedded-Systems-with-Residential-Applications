/*
 * LED.h
 *
 * Created: 26/09/2020 12:35:48 p. m.
 *  Author: brios
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "gpio.h"

/* Led State */
#define LED_ON	LOW
#define LED_OFF	HIGH

/* Initialization function for LED*/
void initLED();

/* Sets the state of the led
* @params newState
*/
void setLED(Gpio_pinState_t newState);



#endif /* GPIO_H_ */
