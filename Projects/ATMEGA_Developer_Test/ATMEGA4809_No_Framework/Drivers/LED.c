/*
 * LED.c
 *
 * Created: 26/09/2020 12:33:48 p. m.
 *  Author: brios
 */ 
#include "LED.h"

void initLED()
{
	/* Configure PB5 as output */
	PORTB.DIRSET = LED_PIN;
}

void setLED(int newState)
{
	if(newState)
	{
		PORTB.OUTSET = LED_PIN;
	}
	else
	{
		PORTB.OUTCLR = LED_PIN;
	}	
}
