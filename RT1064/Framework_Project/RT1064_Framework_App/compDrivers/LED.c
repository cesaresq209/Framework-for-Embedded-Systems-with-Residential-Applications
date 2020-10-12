/*
 * LED.c
 *
 * Created: 26/09/2020 12:33:48 p. m.
 *  Author: brios
 */ 
#include "LED.h"
void initLED()
{
	Gpio_SetPin(LED_Port_PORT, LED_Port_PIN, LED_OFF);
}

void setLED(Gpio_pinState_t newState)
{
	Gpio_SetPin(LED_Port_PORT, LED_Port_PIN, newState);
}
