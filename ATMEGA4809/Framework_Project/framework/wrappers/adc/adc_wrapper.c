/******************************************************************************
 *. Copyright 2020 Cesar Rodriguez, All Rights Reserved
 *.=============================================================================
 *. Template C Source File
 *.=============================================================================
 *. FILE: adc_wrapper.c
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

/**
 * @file adc_wrapper.c
 * @author Cesar Rodriguez
 * @brief ADC framework module wrapper source file
 */

/***********************
 * Includes             *
 ***********************/
#include "adc_wrapper.h"

/***********************
 * Type Definitions     *
 ***********************/

/***********************
 * Macros               *
 ***********************/

/***********************
 * Defines              *
 ***********************/
#define PERCENT_FREQUENCY_50 (uint32_t)1500000

#define ADC_RESOLUTION_MASK        (uint8_t)0x04
#define ADC_SAMPLES_MASK           (uint8_t)0x07
#define ADC_VOLTAGE_REFERENCE_MASK (uint8_t)0x30
#define ADC_PRESCALER_MASK         (uint8_t)0x07

/***********************
 * Constants            *
 ***********************/

/***********************
 * Calibrations         *
 ***********************/

/***********************
 * Global Variables     *
 ***********************/
Adc_channelId_t Adc_Channel = ADC_CHANNEL_0;

/***********************
 * File Scope Variables *
 ***********************/

/***********************
 * Function Prototypes  *
 ***********************/

/***********************
 * Function Definitions *
 ***********************/

/**
 * @brief Enable/Disables ADC Clock
 * @param id ADC ID
 * @param isEnabled Enable/Disable clock
 * @note This MCU can´t enable/disable ADC Clock
 */
void AdcWrapper_EnableAdcClock(Adc_adcId_t id, uint8_t isEnabled)
{
    // This MCU can´t enable/disable ADC Clock
}

/**
 * @brief Set ADC´s number of samples
 * @param id ADC ID
 * @param samples number of samples to take
 */
void AdcWrapper_SetSamples(Adc_adcId_t id, Adc_samples_t samples)
{
    uint8_t value = 0;

    if ((samples != ADC_NOT_SUPPORTED) && (id == ADC1))
    {
        value = ADC0.CTRLB;
        value &= (uint8_t)(~ADC_SAMPLES_MASK);
        value |= (samples & ADC_RESOLUTION_MASK);
        ADC0.CTRLB = value;
    }
}

/**
 * @brief Set ADC´s clock source
 * @param id ADC ID
 * @param clock_source clock source used by the ADC
 * @note The ADC of this MCU can only be driven by the main clock
 */
void AdcWrapper_SetClockSource(Adc_adcId_t id, Adc_clock_t clock_source)
{
    // The ADC of this MCU can only be driven by the main clock
}

/**
 * @brief Set the Channel to be used by the ADC
 * @param id ADC ID
 * @param channel Channel to be used in the ADC Conversion
 */
void AdcWrapper_SetChannel(Adc_adcId_t id, Adc_channelId_t channel)
{
    Adc_Channel = channel;
}

/**
 * @brief Set ADC´s result justification
 * @param id ADC ID
 * @param justification justification the ADC result will have
 * @note The conversion result of the ADC for this MCU is right justified and not adjustable
 */
void AdcWrapper_SetJustification(Adc_adcId_t id, Adc_justification_t justification)
{
    // The conversion result of the ADC for this MCU is right justified and not adjustable.
}

/**
 * @brief Set ADC´s clock prescaler
 * @param id ADC ID
 * @param prescaler prescaler to be applied to the ADC Clock
 */
void AdcWrapper_SetPrescaler(Adc_adcId_t id, Adc_prescaler_t prescaler)
{
    uint8_t value = 0;

    if ((prescaler != ADC_NOT_SUPPORTED) && (id == ADC1))
    {
        value = ADC0.CTRLC;
        value &= (uint8_t)(~ADC_PRESCALER_MASK);
        value |= (prescaler & ADC_PRESCALER_MASK);
        ADC0.CTRLC = value;
    }
}

/**
 * @brief Set ADC´s resolution
 * @param id ADC ID
 * @param resolution resolution (in bits) the ADC will have
 */
void AdcWrapper_SetResolution(Adc_adcId_t id, Adc_resolution_t resolution)
{
    uint8_t value = 0;

    if ((resolution != ADC_NOT_SUPPORTED) && (id == ADC1))
    {
        value = ADC0.CTRLA;
        value &= (uint8_t)(~ADC_RESOLUTION_MASK);
        value |= (resolution & ADC_RESOLUTION_MASK);
        ADC0.CTRLA = value;
    }
}

/**
 * @brief Set ADC´s voltage reference
 * @param id ADC ID
 * @param reference voltage reference used by the ADC
 */
void AdcWrapper_SetVoltageReference(Adc_adcId_t id, Adc_reference_t reference)
{
    uint8_t value = 0;

    if ((reference != ADC_NOT_SUPPORTED) && (id == ADC1))
    {
        value = ADC0.CTRLC;
        value &= (uint8_t)(~ADC_VOLTAGE_REFERENCE_MASK);
        value |= (reference & ADC_VOLTAGE_REFERENCE_MASK);
        ADC0.CTRLC = value;
    }
}

/**
 * @brief Performs ADC Calibration
 * @param id ADC ID
 */
void AdcWrapper_CalibrateAdc(Adc_adcId_t id)
{
    if (id == ADC1)
    {
        if (GetAdcClockFrequency() > PERCENT_FREQUENCY_50)
        {
            ADC0.CALIB = ADC_DUTYCYC_DUTY50_gc; /* 50% Duty cycle */
        }
        else
        {
            ADC0.CALIB = ADC_DUTYCYC_DUTY25_gc; /* 50% Duty cycle */
        }
    }
}

/**
 * @brief Enables ADC
 * @param id ADC ID
 */
void AdcWrapper_EnableAdc(Adc_adcId_t id)
{
    if (id == ADC1)
    {
        ADC_0_enable();
    }
}

/**
 * @brief Disables ADC
 * @param id ADC ID
 */
void AdcWrapper_DisableAdc(Adc_adcId_t id)
{
    if (id == ADC1)
    {
        ADC_0_disable();
    }
}

/**
 * @brief Gets the result of ADC Conversion
 * @param id ADC ID
 * @return Result of ADC´s conversion
 */
uint16_t AdcWrapper_GetResult(Adc_adcId_t id)
{
    if (id == ADC1)
    {
        return ADC_0_get_conversion_result();
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Gets the status of the current ADC Conversion
 * @param id ADC ID
 * @return Status of ADC´s conversion
 */
Adc_status_t AdcWrapper_GetConversionStatus(Adc_adcId_t id)
{
    if (id == ADC1)
    {
        return ADC_0_is_conversion_done();
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Starts ADC conversion in the previously selected channel
 * @param id ADC ID
 */
void AdcWrapper_StartConversion(Adc_adcId_t id)
{
    if (id == ADC1)
    {
        ADC_0_start_conversion((adc_0_channel_t)Adc_Channel);
    }
}
