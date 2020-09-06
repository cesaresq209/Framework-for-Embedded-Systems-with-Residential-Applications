/**
 * @file gpio.h
 * @author Miguel Diaz
 * @brief GPIO framework module header
 */

/************************
 * Guard                *
 ************************/
#ifndef _GPIO_H_
#define _GPIO_H_

/************************
 * Includes             *
 ************************/
#include "frameworkCommon.h"
#include "gpio_cfg.h"
#include "gpio_wrapper.h"

/************************
 * Public Types         *
 ************************/

/**
 * @brief GPIO configuration structure
 */
typedef struct
{
    Gpio_portId_t     Port;
    Gpio_pin_t        Pin;
    Gpio_mode_t       Mode;
    Gpio_alternate_t  Alternate;
    Gpio_outputType_t Output_Type;
    Gpio_pull_t       Pull;
    Gpio_speed_t      Speed;
    Gpio_pinState_t   InitOutValue;
} Gpio_cfg_t;

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
extern const Gpio_cfg_t Gpio_Cfg[GPIO_ELEMENTS_MAX];

/************************
 * Public Functions     *
 ************************/
void        Gpio_InitDefaults(const Gpio_cfg_t* cfgPtr);
void        Gpio_setMode(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_mode_t mode);
void        Gpio_setPull(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_pull_t pull);
void        Gpio_setSpeed(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_speed_t speed);
void        Gpio_setOutputType(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_outputType_t output_type);
void        Gpio_setAlternate(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_alternate_t alternate);
void        Gpio_WritePort(Gpio_portId_t port, Gpio_data_t value);
void        Gpio_SetPin(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_pinState_t state);
Gpio_data_t Gpio_ReadPort(Gpio_portId_t port);
Gpio_pinState_t Gpio_GetPin(Gpio_portId_t port, Gpio_pinId_t pin);

#endif /* _GPIO_H_ */
