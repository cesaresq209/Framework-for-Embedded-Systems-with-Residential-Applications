/**
 * @file MCU_Helper.h
 * @author Cesar Rodriguez
 * @brief Helper file for MCU Elements not currently supported in the framework
 */

/************************
 * Guard                *
 ************************/
#ifndef _MCU_HELPER_H_
#define _MCU_HELPER_H_

/************************
 * Includes             *
 ************************/

/************************
 * Public Types         *
 ************************/

/************************
 * Public Macros        *
 ************************/
#define GetMainClockFrequency() MAIN_CLOCK_FREQUENCY
#define GetAdcClockFrequency()  ADC_CLOCK_FREQUENCY
#define GetUartClockFrequency() UART_CLOCK_FREQUENCY

/************************
 * Public Defines       *
 ************************/
#define MAIN_CLOCK_FREQUENCY (uint32_t) 24000000
#define ADC_CLOCK_FREQUENCY  (uint32_t) 75000000
#define UART_CLOCK_FREQUENCY (uint32_t) 80000000
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

#endif /* _MCU_HELPER_H_ */
