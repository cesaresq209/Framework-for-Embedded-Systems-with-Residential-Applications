/*
 * ADC.c
 *
 * Created: 26/09/2020 12:34:02 p. m.
 *  Author: usuario
 */ 

#include "POT.h"

void initPOT()
{
	/* Disable digital inputs */
    PORTD.PIN0CTRL &= ~PORT_ISC_gm;
    PORTD.PIN0CTRL |= PORT_ISC_INPUT_DISABLE_gc;
    
    /* Disable pull-up resistor */
    PORTD.PIN0CTRL &= ~PORT_PULLUPEN_bm;

    ADC0.CTRLC = ADC_PRESC_DIV4_gc      /* CLK_PER divided by 4 */
               | ADC_REFSEL_INTREF_gc;  /* Internal reference */
    
    ADC0.CTRLA = ADC_ENABLE_bm          /* Enabling ADC*/
               | ADC_RESSEL_10BIT_gc;   /* 10-bit mode */
    
    /* Select ADC channel */
    ADC0.MUXPOS  = ADC_MUXPOS_AIN0_gc;
	
	/* VREF Internal Reference Config */
	VREF.CTRLA = VREF_ADC0REFSEL_4V34_gc;
}

uint16_t getPotValue()
{	
	/* Start ADC conversion */
    ADC0.COMMAND = ADC_STCONV_bm;
    
    /* Wait until ADC conversion done */
    while ( !(ADC0.INTFLAGS & ADC_RESRDY_bm) )
    {
        ;
    }
    
    /* Clear the interrupt flag */
    ADC0.INTFLAGS = ADC_RESRDY_bm;
    
    return ADC0.RES;
}