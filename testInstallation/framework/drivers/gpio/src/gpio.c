/**
 * @file gpio.c
 * @author Miguel Diaz
 * @brief GPIO framework module
 */

/************************
 * Includes             *
 ************************/
#include "gpio.h"

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
 * @brief Initialize GPIO pin
 * @param cfgPtr pin configuration structure
 */
void Gpio_Init(const Gpio_cfg_t* cfgPtr)
{
    uint16_t gpioNum;

    if (NULL != cfgPtr)
    {
        for (gpioNum = 0; gpioNum < GPIO_ELEMENTS_MAX; gpioNum++)
        {
            GpioWrapper_setMode(cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].Mode);
            GpioWrapper_setPull(cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].Pull);
            GpioWrapper_setSpeed(cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].Speed);

            if (cfgPtr[gpioNum].Mode == MODE_OUTPUT)
            {
                Gpio_SetPin(cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].InitOutValue);
            }
        }
    }
}

/**
 * @brief Write value to port
 * @param port Port to be written
 * @param value Value to be written to port
 */
void Gpio_WritePort(Gpio_portId_t port, Gpio_data_t value)
{
    GpioWrapper_WritePort(port, value);
}

/**
 * @brief Write value to GPIO pin
 * @param port Pin's port
 * @param pin Pin to be written
 * @param state Value to be written to pin
 */
void Gpio_SetPin(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_pinState_t state)
{
    GpioWrapper_SetPin(port, pin, state);
}

/**
 * @brief Read port's value
 * @param port Pin's port
 * @return Port's value
 */
Gpio_data_t Gpio_ReadPort(Gpio_portId_t port)
{
    return GpioWrapper_ReadPort(port);
}

/**
 * @brief Read GPIO pin's value
 * @param port Pin's port
 * @param pin Pin to be read
 * @return Pin's value
 */
Gpio_pinState_t Gpio_GetPin(Gpio_portId_t port, Gpio_pinId_t pin)
{
    return GpioWrapper_GetPin(port, pin);
}
