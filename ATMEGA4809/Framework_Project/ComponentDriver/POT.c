/*
 * ADC.c
 *
 * Created: 26/09/2020 12:34:02 p. m.
 *  Author: usuario
 */ 

#include "POT.h"

void initPOT()
{
	Adc_InitDefaults(Adc_Cfg);
	
	/* VREF Internal Reference Config */
	/* Seems like the framework does not configure this reference
		if not doing this the ADC value will w=always return 1023
		when more than 0.55V detected*/
	VREF.CTRLA = VREF_ADC0REFSEL_4V34_gc;
	
	/*Enabling ADC */
	Adc_EnableAdc(ADC0_NAME);
}

uint16_t getPotValue()
{	
	/* Start ADC conversion */
    Adc_StartConversion(ADC0_NAME);
    
    /* Wait until ADC conversion done */
    while ( !Adc_GetConversionStatus(ADC0_NAME) )
    {
        ;
    }
    
    return Adc_GetResult(ADC0_NAME);
}