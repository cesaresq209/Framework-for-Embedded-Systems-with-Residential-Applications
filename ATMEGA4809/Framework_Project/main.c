/******************************************************************************
*. Copyright 2020 Cesar Rodriguez, All Rights Reserved
*.=============================================================================
*. Template C Source File
*.=============================================================================
*. FILE: main.c
*.
*. DESCRIPTION:
*. This file
*.
*. SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" FOR THE PURPOSES OF THE
*. PROVIDED TRAINING CLASS AND IT IS NOT INTENDED AS PRODUCTION CODE AND WITHOUT
*. WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION,
*. ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A
*. PARTICULAR PURPOSE. IN NO EVENT SHALL SALVADOR ALMANZA OR ITS LICENSORS BE LIABLE OR
*. OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH
*. OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES
*. OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT,
*. PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
*. PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD
*. PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR
*. COSTS.
*.
\*****************************************************************************/
/***********************
 * Includes             *
 ***********************/
#include "main.h"
#include "frameworkCommon.h"
#include "frameworkIncludes.h"
#include "ComponentDrivers/LED.h"
#include "ComponentDrivers/POT.h"
#include "ComponentDrivers/Console.h"

/***********************
 * Type Definitions     *
 ***********************/

/***********************
 * Macros               *
 ***********************/
#define UART_READ() consoleReadChar()
/***********************
 * Defines              *
 ***********************/

/***********************
 * Constants            *
 ***********************/

/***********************
 * Calibrations         *
 ***********************/

/***********************
 * Global Variables     *
 ***********************/

/***********************
 * File Scope Variables *
 ***********************/

/***********************
 * Function Prototypes  *
 ***********************/

/***********************
 * Function Definitions *
 ***********************/
void printVoltage(float voltage)
{
	char voltageString[50];
	sprintf(voltageString,"Measured Voltage: %.2f \n",voltage);
	consoleSendString(voltageString);
}
/*********************************************************************
*. Name: main
*.====================================================================
*. Description:
*. C entry point, executes the systems initialization and application
*.
\********************************************************************/
int main(void)
{
    States_t  current_State = HW_INIT;
    volatile uint16_t ADC_Value     = 0;
    volatile float    voltage       = 0;
    while (true)
    {
        switch (current_State)
        {
            case HW_INIT:
                /* 
				Initialize basic hardware functionality, GPIO, 
				UART and ADC
				*/
                HWInit();				
				Gpio_InitDefaults(Gpio_Cfg);
				initLED();
				initPOT();
				consoleInit();
                current_State = WAIT;
                break;
            case WAIT:
			    /*
				Perform UART Read, if read value is equal to 
				0 (48), change state to MEASURE_VOLTAGE
				*/
                if (UART_READ() == 48)
                {
                    current_State = MEASURE_VOLTAGE;
                }
                break;
            case MEASURE_VOLTAGE:
			    /*
				Measure voltage and print the result through UART
				*/				
				ADC_Value = getPotValue();
				voltage = (ADC_Value*3.3)/1024;
				printVoltage(voltage);
                current_State = UPDATE_LED;
                break;
            case UPDATE_LED:
			    /*
				Update LED Value:
				-ON if measured voltage <2.5 V
				-Off if measured voltage >=2.5V
				*/
				if(voltage > 2.5)
				{
					setLED(LED_ON);
				}
				else
				{
					setLED(LED_OFF);
				}
                current_State = WAIT;
                break;
            default:
                break;
        }
    }
}
