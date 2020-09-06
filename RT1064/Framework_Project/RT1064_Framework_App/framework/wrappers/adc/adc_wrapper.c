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
#define ADC_SW_CHANNEL (uint8_t)0
#define INVALID_CLOCK  (uint8_t)0

// ADC Clocks
#define ADC1_CLOCK kCLOCK_Adc1
#define ADC2_CLOCK kCLOCK_Adc2

/***********************
 * Constants            *
 ***********************/

/***********************
 * Calibrations         *
 ***********************/

/***********************
 * Global Variables     *
 ***********************/
Adc_t*          Adc[ADC_MAX] = {ADC1, ADC2};
Adc_channelId_t Adc_Channel  = ADC_CHANNEL_0;

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
 */
void AdcWrapper_EnableAdcClock(Adc_adcId_t id, uint8_t isEnabled)
{
    uint32_t clock_id = 0;
    switch (id)
    {
        case ADC_1:
            clock_id = ADC1_CLOCK;
            break;
            break;
        case ADC_2:
            clock_id = ADC2_CLOCK;
            break;
        default:
            clock_id = INVALID_CLOCK;
            break;
    }

    if (clock_id != INVALID_CLOCK)
    {
        if (isEnabled == ENABLE_ADC_CLOCK)
        {
            CLOCK_EnableClock(clock_id);
        }
        else
        {
            CLOCK_DisableClock(clock_id);
        }
    }
}

/**
 * @brief Set ADC´s number of samples
 * @param id ADC ID
 * @param samples number of samples to take
 */
void AdcWrapper_SetSamples(Adc_adcId_t id, Adc_samples_t samples)
{
    if (samples != ADC_NOT_SUPPORTED)
    {
        ADC_SetHardwareAverageConfig(Adc[id], samples);
    }
}

/**
 * @brief Set ADC´s clock source
 * @param id ADC ID
 * @param clock_source clock source used by the ADC
 */
void AdcWrapper_SetClockSource(Adc_adcId_t id, Adc_clock_t clock_source)
{
    uint32_t value = 0;
    if (clock_source != ADC_NOT_SUPPORTED)
    {
        value = Adc[id]->CFG;
        value &= (uint32_t)(~ADC_CFG_ADICLK_MASK);
        value |= ADC_CFG_ADICLK(clock_source);
        Adc[id]->CFG = value;
    }
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
 * @note The conversion result of the ADC for this MCU is right justified and not adjustable.
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
    uint32_t value = 0;
    if (prescaler != ADC_NOT_SUPPORTED)
    {
        value = Adc[id]->CFG;
        value &= (uint32_t)(~ADC_CFG_ADIV_MASK);
        value |= ADC_CFG_ADIV(prescaler);
        Adc[id]->CFG = value;
    }
}

/**
 * @brief Set ADC´s resolution
 * @param id ADC ID
 * @param resolution resolution (in bits) the ADC will have
 */
void AdcWrapper_SetResolution(Adc_adcId_t id, Adc_resolution_t resolution)
{
    uint32_t value = 0;
    if (resolution != ADC_NOT_SUPPORTED)
    {
        value = Adc[id]->CFG;
        value &= (uint32_t)(~ADC_CFG_MODE_MASK);
        value |= ADC_CFG_MODE(resolution);
        Adc[id]->CFG = value;
    }
}

/**
 * @brief Set ADC´s voltage reference
 * @param id ADC ID
 * @param reference voltage reference used by the ADC
 */
void AdcWrapper_SetVoltageReference(Adc_adcId_t id, Adc_reference_t reference)
{
    // This MCU voltage reference is tied to VREFH and VREFL and is not adjustable
}

/**
 * @brief Performs ADC Calibration
 * @param id ADC ID
 */
void AdcWrapper_CalibrateAdc(Adc_adcId_t id)
{
    ADC_DoAutoCalibration(Adc[id]);
}

/**
 * @brief Enables ADC
 * @param id ADC ID
 * @note The ADC of this MCU does not support to be disabled/enabled
 */
void AdcWrapper_EnableAdc(Adc_adcId_t id)
{
    // The ADC of this MCU Does not need to be Enabled/Disabled
}

/**
 * @brief Disables ADC
 * @param id ADC ID
 * @note The ADC of this MCU does not support to be disabled/enabled
 */
void AdcWrapper_DisableAdc(Adc_adcId_t id)
{
    // The ADC of this MCU Does not need to be Enabled/Disabled
}

/**
 * @brief Gets the result of ADC Conversion
 * @param id ADC ID
 * @return Result of ADC´s conversion
 */
uint16_t AdcWrapper_GetResult(Adc_adcId_t id)
{
    return ADC_GetChannelConversionValue(Adc[id], ADC_SW_CHANNEL);
}

/**
 * @brief Gets the status of the current ADC Conversion
 * @param id ADC ID
 * @return Status of ADC´s conversion
 */
Adc_status_t AdcWrapper_GetConversionStatus(Adc_adcId_t id)
{
    return ADC_GetChannelStatusFlags(Adc[id], ADC_SW_CHANNEL);
}

/**
 * @brief Starts ADC conversion in the previously selected channel
 * @param id ADC ID
 */
void AdcWrapper_StartConversion(Adc_adcId_t id)
{
    uint32_t value;
    value                       = ADC_HC_ADCH(Adc_Channel);
    Adc[id]->HC[ADC_SW_CHANNEL] = value;
}
