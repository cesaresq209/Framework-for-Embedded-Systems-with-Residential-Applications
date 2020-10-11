/*
 * ADC.h
 *
 * Created: 26/09/2020 12:35:25 p. m.
 *  Author: usuario
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "fsl_adc.h"

#define ADC_BASE          ADC1
#define ADC_POT_CHANNEL   15U
#define ADC_CHANNEL_GROUP 0U

void initPOT();
uint32_t getPotValue();




#endif /* ADC_H_ */
