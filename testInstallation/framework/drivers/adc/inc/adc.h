/**
 * @file adc.h
 * @author Cesar Rodriguez
 * @brief ADC framework module header
 */

/************************
 * Guard                *
 ************************/
#ifndef _ADC_H_
#define _ADC_H_

/************************
 * Includes             *
 ************************/
#include "frameworkCommon.h"
#include "adc_cfg.h"
#include "adc_wrapper.h"

/************************
 * Public Types         *
 ************************/

/**
 * @brief ADC configuration structure
 */
typedef struct
{
    Adc_adcId_t         ID;
    Adc_samples_t       Samples;
    Adc_clock_t         Clock;
    Adc_justification_t Justification;
    Adc_prescaler_t     Prescaler;
    Adc_resolution_t    Resolution;
    Adc_reference_t     Reference;
} Adc_cfg_t;

/************************
 * Public Macros        *
 ************************/

/************************
 * Public Defines       *
 ************************/

/************************
 * Public Constants     *
 ************************/

/************************
 * Public Calibrations  *
 ************************/

/************************
 * Public Variables     *
 ************************/
extern const Adc_cfg_t Adc_Cfg[ADC_ELEMENTS_MAX];

/************************
 * Public Functions     *
 ************************/
void Adc_Init(const Adc_cfg_t* cfgPtr);
void Adc_EnableClock(Adc_adcId_t id, uint8_t isEnabled);
void Adc_SetSamples(Adc_adcId_t id,Adc_samples_t samples);
void Adc_SetClockSource(Adc_adcId_t id, Adc_clock_t clock_source);
void Adc_SetChannel(Adc_adcId_t id,Adc_channelId_t channel);
void Adc_SetJustification(Adc_adcId_t id, Adc_justification_t justification);
void Adc_SetPrescaler(Adc_adcId_t id,Adc_prescaler_t prescaler);
void Adc_SetResolution(Adc_adcId_t id,Adc_resolution_t resolutionn);
void Adc_SetVoltageReference(Adc_adcId_t id, Adc_reference_t reference);
void Adc_CalibrateAdc(Adc_adcId_t id);
void Adc_EnableAdc(Adc_adcId_t id);
void Adc_DisableAdc(Adc_adcId_t id);
uint16_t Adc_GetResult(Adc_adcId_t id);
Adc_status_t Adc_GetConversionStatus(Adc_adcId_t id);
void Adc_StartConversion(Adc_adcId_t id);

#endif /* _ADC_H_ */
