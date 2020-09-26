/*
 * ATMEGA4809_No_Framework.c
 *
 * Created: 26/09/2020 12:28:32 p. m.
 * Author : usuario
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "Drivers/LED.h"
#include "Drivers/POT.h"
#include "Drivers/Console.h"

#define INIT 0
#define WAIT 1
#define GET_MEASURE 2
#define UPDT_LED 3

#define ADCCONVERSION(value) (value*4.34)/1024


int main(void)
{	
	int currentState = INIT;
	float voltage = 0;
	char command = 'c';
	char voltageString[50];

	while (1)
	{
		switch(currentState)
		{
			case INIT:
				/* Init LED */
				initLED();
				/* Init Pot */
				initPOT();
				/* Init Console */
				consoleInit();
				setLED(LED_OFF);
				currentState = WAIT;
				consoleSendString("Transition to WAIT\n");
				break;
			case WAIT:
				consoleSendString("Enter Command: \n");
				command = consoleReadChar();
				if(command == '0')
				{
					currentState = GET_MEASURE;
					consoleSendString("Transition to GET_MEASURE\n");
				}
				break;
			case GET_MEASURE:
				voltage = ADCCONVERSION(getPotValue());
				sprintf(voltageString,"Measured Voltage: %.2f \n",voltage);
				consoleSendString(voltageString);
				currentState = UPDT_LED;
				consoleSendString("Transition to UPDT_LED\n");
				break;
			case UPDT_LED:
				if(voltage <= 2.5)
				{
					setLED(LED_OFF);
				}
				else
				{
					setLED(LED_ON);
				}
				currentState = WAIT;
				consoleSendString("Transition to WAIT\n");
				break;
		}
	}
}

