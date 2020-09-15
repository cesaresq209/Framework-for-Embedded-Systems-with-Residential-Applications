/**
 * @file adc_cfg.h
 * @author Cesar Rodriguez
 * @brief ADC framework configuration header
 */

/************************
 * Guard                *
 ************************/
#ifndef _ADC_CFG_H_
#define _ADC_CFG_H_

/************************
 * Includes             *
 ************************/
FWK_ADC_INCLUDES

/************************
 * Public Types         *
 ************************/
/**
 * @brief GPIO elements
 */
typedef enum
{
    FWK_ADC_ELEMENTS
    ADC_ELEMENTS_MAX
} Adc_elementsType;

/************************
 * Public Macros        *
 ************************/

/************************
 * Public Defines       *
 ************************/
FWK_ADC_CFG_DEFINITIONS

FWK_ADC_ELEMENTS_DEFINITIONS

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

#endif /* _ADC_CFG_H_ */
