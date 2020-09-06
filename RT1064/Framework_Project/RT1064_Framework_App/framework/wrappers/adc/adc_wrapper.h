/**
 * @file adc_wrapper.h
 * @author Cesar Rodriguez
 * @brief ADC framework module wrapper header
 */

/************************
 * Guard                *
 ************************/
#ifndef _ADC_WRAPPER_H_
#define _ADC_WRAPPER_H_

/************************
 * Includes             *
 ************************/
#include "MIMXRT1064.h"
#include "fsl_adc.h"

/************************
 * Public Types         *
 ************************/

/**
 * @brief ADC IDs for RT1064
 */
typedef enum
{
    ADC_1,
    ADC_2,
    ADC_MAX
} Adc_adcId_t;

/**
 * @brief ADC Channel IDs for RT1064
 */
typedef enum
{
    ADC_CHANNEL_0 = 0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7,
    ADC_CHANNEL_8,
    ADC_CHANNEL_9,
    ADC_CHANNEL_10,
    ADC_CHANNEL_11,
    ADC_CHANNEL_12,
    ADC_CHANNEL_13,
    ADC_CHANNEL_14,
    ADC_CHANNEL_15,
    ADC_MAX_CHANNEL
} Adc_channelId_t;

/**
 * @brief ADC data type
 */
typedef ADC_Type Adc_t;

/**
 * @brief ADC samples data type
 */
typedef adc_hardware_average_mode_t Adc_samples_t;

/**
 * @brief ADC clock source data type
 */
typedef adc_clock_source_t Adc_clock_t;

/**
 * @brief ADC justification type
 */
typedef uint8_t Adc_justification_t;

/**
 * @brief ADC prescaler type
 */
typedef adc_clock_driver_t Adc_prescaler_t;

/**
 * @brief ADC resolution type
 */
typedef adc_resolution_t Adc_resolution_t;

/**
 * @brief ADC voltage reference type
 */
typedef uint8_t Adc_reference_t;

/**
 * @brief ADC status type
 */
typedef uint8_t Adc_status_t;
/************************
 * Public Macros        *
 ************************/

/************************
 * Public Defines       *
 ************************/
// Dummy value used for unsuported definitions
#define ADC_NOT_SUPPORTED 0x55

#define ENABLE_ADC_CLOCK  (uint8_t)1
#define DISABLE_ADC_CLOCK (uint8_t)0

// Measurement Samples
#define ADC_DISABLE_SAMPLE         kADC_HardwareAverageDiasable
#define ADC_TAKE_2_SAMPLES         ADC_NOT_SUPPORTED
#define ADC_TAKE_4_SAMPLES         kADC_HardwareAverageCount4
#define ADC_TAKE_8_SAMPLES         kADC_HardwareAverageCount8
#define ADC_TAKE_16_SAMPLES        kADC_HardwareAverageCount16
#define ADC_TAKE_32_SAMPLES        kADC_HardwareAverageCount32
#define ADC_TAKE_64_SAMPLES        ADC_NOT_SUPPORTED
#define ADC_TAKE_ALTERNATE_SAMPLES ADC_NOT_SUPPORTED

// Clock Source
#define INTERNAL_CLOCK_FOR_ADC   ADC_NOT_SUPPORTED
#define PERIPHERAL_CLOCK_FOR_ADC kADC_ClockSourceIPG
#define ADC_CLOCK_FOR_ADC        kADC_ClockSourceAD
#define OTHER_CLOCK_FOR_ADC      kADC_ClockSourceIPGDiv2

// Justification
#define ADC_RIGHT_JUSTIFIED ADC_NOT_SUPPORTED
#define ADC_LEFT_JUSTIFIED  ADC_NOT_SUPPORTED

// Clock Prescaler
#define DO_NOT_DIVIDE_ADC_CLOCK   kADC_ClockDriver1
#define DIVIDE_ADC_CLOCK_BY_2     kADC_ClockDriver2
#define DIVIDE_ADC_CLOCK_BY_4     kADC_ClockDriver4
#define DIVIDE_ADC_CLOCK_BY_8     kADC_ClockDriver8
#define DIVIDE_ADC_CLOCK_BY_16    ADC_NOT_SUPPORTED
#define DIVIDE_ADC_CLOCK_BY_32    ADC_NOT_SUPPORTED
#define DIVIDE_ADC_CLOCK_BY_64    ADC_NOT_SUPPORTED
#define DIVIDE_ADC_CLOCK_BY_128   ADC_NOT_SUPPORTED
#define DIVIDE_ADC_CLOCK_BY_256   ADC_NOT_SUPPORTED
#define DIVIDE_ADC_CLOCK_BY_512   ADC_NOT_SUPPORTED
#define DIVIDE_ADC_CLOCK_BY_OTHER ADC_NOT_SUPPORTED

// ADC Resolution
#define ADC_8_BIT_RESOLUTION  kADC_Resolution8Bit
#define ADC_10_BIT_RESOLUTION kADC_Resolution10Bit
#define ADC_12_BIT_RESOLUTION kADC_Resolution12Bit
#define ADC_16_BIT_RESOLUTION ADC_NOT_SUPPORTED
#define ADC_OTHER_RESOLUTION  ADC_NOT_SUPPORTED

// ADC Voltage Reference
#define ADC_USE_INTERNAL_VOLTAGE_REFERENCE  ADC_NOT_SUPPORTED
#define ADC_USE_EXTERNAL_VOLTAGE_REFERENCE  ADC_NOT_SUPPORTED
#define ADC_USE_SUPPLY_VOLTAGE_AS_REFERENCE ADC_NOT_SUPPORTED
#define ADC_USE_OTHER_VOLTAGE_REFERENCE     ADC_NOT_SUPPORTED

// ADC Conversion Status
#define CONVERSION_IN_PROGRESS (uint8_t)0
#define CONVERSION_READY       (uint8_t)1

/************************
 * Public Constants     *
 ************************/

/************************
 * Public Calibrations  *
 ************************/

/************************
 * Public Variables     *
 ************************/

/************************
 * Public Functions     *
 ************************/
void         AdcWrapper_EnableAdcClock(Adc_adcId_t id, uint8_t isEnabled);
void         AdcWrapper_SetSamples(Adc_adcId_t id, Adc_samples_t samples);
void         AdcWrapper_SetClockSource(Adc_adcId_t id, Adc_clock_t clock_source);
void         AdcWrapper_SetChannel(Adc_adcId_t id, Adc_channelId_t channel);
void         AdcWrapper_SetJustification(Adc_adcId_t id, Adc_justification_t justification);
void         AdcWrapper_SetPrescaler(Adc_adcId_t id, Adc_prescaler_t prescaler);
void         AdcWrapper_SetResolution(Adc_adcId_t id, Adc_resolution_t resolution);
void         AdcWrapper_SetVoltageReference(Adc_adcId_t id, Adc_reference_t reference);
void         AdcWrapper_CalibrateAdc(Adc_adcId_t id);
void         AdcWrapper_EnableAdc(Adc_adcId_t id);
void         AdcWrapper_DisableAdc(Adc_adcId_t id);
uint16_t     AdcWrapper_GetResult(Adc_adcId_t id);
Adc_status_t AdcWrapper_GetConversionStatus(Adc_adcId_t id);
void         AdcWrapper_StartConversion(Adc_adcId_t id);
#endif /* _ADC_WRAPPER_H_ */
