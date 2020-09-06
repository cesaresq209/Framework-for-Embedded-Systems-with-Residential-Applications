/**
 * @file framework_helper.h
 * @author Cesar Rodriguez
 * @brief Framework helper file for requirede definitions still not
 * handled in the framework
 */

/************************
 * Guard                *
 ************************/
#ifndef _FRAMEWORK_HELPER_H_
#define _FRAMEWORK_HELPER_H_

/************************
 * Includes             *
 ************************/

/************************
 * Public Types         *
 ************************/

/************************
 * Public Macros        *
 ************************/
#define GetClockFrequency()   MAIN_CLOCK_FREQUENCY
#define GetAdcClockFrequency() ADC_CLOCK_FREQUENCY
/************************
 * Public Defines       *
 ************************/
#define MAIN_CLOCK_FREQUENCY (uint32_t) 3330000
#define ADC_CLOCK_FREQUENCY  (uint32_t) 3330000
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

#endif /* _FRAMEWORK_HELPER_H_ */