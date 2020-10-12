/*
 * ADC.c
 *
 * Created: 26/09/2020 12:34:02 p. m.
 *  Author: usuario
 */ 

#include "POT.h"

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

	/*Enabling ADC */
	Adc_EnableAdc(POT_FW_ADC_NAME);
}

uint16_t getPotValue()
{
	Adc_SetChannel(POT_FW_ADC_NAME,POT_ADC_CHANNEL);
	/* Start ADC conversion */
    Adc_StartConversion(POT_FW_ADC_NAME);

    /* Wait until ADC conversion done */
    while ( !Adc_GetConversionStatus(POT_FW_ADC_NAME) )
    {
        ;
    }

    return ( Adc_GetResult(POT_FW_ADC_NAME) & 0x3FF);
}
