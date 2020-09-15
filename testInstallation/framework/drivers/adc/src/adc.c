/**
 * @file adc.c
 * @author Cesar Rodriguez
 * @brief ADC framework module
 */

/************************
 * Includes             *
 ************************/
#include "adc.h"

/************************
 * Type Definitions     *
 ************************/

/************************
 * Macros               *
 ************************/

/************************
 * Defines              *
 ************************/

/************************
 * Constants            *
 ************************/

/************************
 * Calibrations         *
 ************************/

/************************
 * Global Variables     *
 ************************/

/************************
 * File Scope Variables *
 ************************/

/************************
 * Function Prototypes  *
 ************************/

/************************
 * Function Definitions *
 ************************/
/**
 * @brief Initialize ADC
 * @param cfgPtr ADC Configuration Structure
 */
void Adc_Init(const Adc_cfg_t* cfgPtr)
{
    uint8_t adcNum;

    if (NULL != cfgPtr)
    {
        for (adcNum = 0; adcNum < ADC_ELEMENTS_MAX; adcNum++)
        {
            AdcWrapper_EnableAdcClock(cfgPtr[adcNum].ID,ENABLE_ADC_CLOCK);
            AdcWrapper_SetSamples(cfgPtr[adcNum].ID,cfgPtr[adcNum].Samples);
            AdcWrapper_SetClockSource(cfgPtr[adcNum].ID,cfgPtr[adcNum].Clock);
            AdcWrapper_SetJustification(cfgPtr[adcNum].ID, cfgPtr[adcNum].Justification);
            AdcWrapper_SetPrescaler(cfgPtr[adcNum].ID,cfgPtr[adcNum].Prescaler);
            AdcWrapper_SetResolution(cfgPtr[adcNum].ID,cfgPtr[adcNum].Prescaler);
            AdcWrapper_SetVoltageReference(cfgPtr[adcNum].ID, cfgPtr[adcNum].Reference);
        }
    }
}

/**
 * @brief Enable/Disables ADC Clock
 * @param id ADC ID
 * @param isEnabled Enable/Disable clock
 */
void Adc_EnableClock(Adc_adcId_t id, uint8_t isEnabled)
{
    AdcWrapper_EnableAdcClock(id,isEnabled);
}

/**
 * @brief Set ADC´s number of samples
 * @param id ADC ID
 * @param samples number of samples to take
 */
void Adc_SetSamples(Adc_adcId_t id,Adc_samples_t samples)
{
    AdcWrapper_SetSamples(id,samples);
}

/**
 * @brief Set ADC´s clock source
 * @param id ADC ID
 * @param clock_source clock source used by the ADC
 */
void Adc_SetClockSource(Adc_adcId_t id, Adc_clock_t clock_source)
{
    AdcWrapper_SetClockSource(id, clock_source);
}

/**
 * @brief Set the Channel to be used by the ADC
 * @param id ADC ID
 * @param channel Channel to be used in the ADC Conversion
 */
void Adc_SetChannel(Adc_adcId_t id,Adc_channelId_t channel)
{
    AdcWrapper_SetChannel(id,channel);
}

/**
 * @brief Set ADC´s result justification
 * @param id ADC ID
 * @param justification justification the ADC result will have
 */
void Adc_SetJustification(Adc_adcId_t id, Adc_justification_t justification)
{
    AdcWrapper_SetJustification(id,justification);
}

/**
 * @brief Set ADC´s clock prescaler
 * @param id ADC ID
 * @param prescaler prescaler to be applied to the ADC Clock
 */
void Adc_SetPrescaler(Adc_adcId_t id,Adc_prescaler_t prescaler)
{
    AdcWrapper_SetPrescaler(id,prescaler);
}

/**
 * @brief Set ADC´s resolution
 * @param id ADC ID
 * @param resolution resolution (in bits) the ADC will have
 */
void Adc_SetResolution(Adc_adcId_t id,Adc_resolution_t resolution)
{
    AdcWrapper_SetResolution(id,resolution);
}

/**
 * @brief Set ADC´s voltage reference
 * @param id ADC ID
 * @param reference voltage reference used by the ADC
 */
void Adc_SetVoltageReference(Adc_adcId_t id, Adc_reference_t reference)
{
    AdcWrapper_SetVoltageReference(id,reference);
}

/**
 * @brief Performs ADC Calibration
 * @param id ADC ID
 */
void Adc_CalibrateAdc(Adc_adcId_t id)
{
    AdcWrapper_CalibrateAdc(id);
}

/**
 * @brief Enables ADC
 * @param id ADC ID
 */
void Adc_EnableAdc(Adc_adcId_t id)
{
    AdcWrapper_EnableAdc(id);
}

/**
 * @brief Disables ADC
 * @param id ADC ID
 */
void Adc_DisableAdc(Adc_adcId_t id)
{
    AdcWrapper_DisableAdc(id);
}

/**
 * @brief Gets the result of ADC Conversion
 * @param id ADC ID
 * @return Result of ADC´s conversion
 */
uint16_t Adc_GetResult(Adc_adcId_t id)
{
    return AdcWrapper_GetResult(id);
}

/**
 * @brief Gets the status of the current ADC Conversion
 * @param id ADC ID
 * @return Status of ADC´s conversion
 */
Adc_status_t Adc_GetConversionStatus(Adc_adcId_t id)
{
    return AdcWrapper_GetConversionStatus(id);
}

/**
 * @brief Starts ADC conversion in the previously selected channel
 * @param id ADC ID
 */
void Adc_StartConversion(Adc_adcId_t id)
{
    AdcWrapper_StartConversion(id);
}
