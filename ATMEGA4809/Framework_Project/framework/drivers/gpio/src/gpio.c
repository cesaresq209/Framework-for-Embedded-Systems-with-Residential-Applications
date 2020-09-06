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
void Gpio_InitDefaults(const Gpio_cfg_t* cfgPtr)
{
    if (NULL != cfgPtr)
    {
        for (uint8_t gpioNum = 0; gpioNum < GPIO_ELEMENTS_MAX; gpioNum++)
        {
            // Configure as GPIO
            if (cfgPtr[gpioNum].Mode != MODE_ALTERNATE_FUNCTION)
            {
                GpioWrapper_setMode(cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].Mode);
                GpioWrapper_setPull(cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].Pull);
                GpioWrapper_setSpeed(cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].Speed);
                if (cfgPtr[gpioNum].Mode == MODE_OUTPUT)
                {
                    GpioWrapper_setOutputType(
                        cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].Output_Type);
                    Gpio_SetPin(cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].InitOutValue);
                }
            }
            // Configure pin for alternate use
            else
            {
                GpioWrapper_setAlternate(
                    cfgPtr[gpioNum].Port, cfgPtr[gpioNum].Pin, cfgPtr[gpioNum].Alternate);
            }
        }
    }
}

/**
 * @brief Set pin's mode
 * @param port Pin's port
 * @param pin Pin
 * @param mode Mode
 */
void Gpio_setMode(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_mode_t mode)
{
    GpioWrapper_setMode(port, pin, mode);
}

/**
 * @brief Set pin's pull resistor
 * @param port Pin's port
 * @param pin Pin
 * @param pull Pull resistor
 */
void Gpio_setPull(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_pull_t pull)
{
    GpioWrapper_setPull(port, pin, pull);
}

/**
 * @brief Set pin's speed
 * @param port Pin's port
 * @param pin Pin
 * @param speed Speed
 */
void Gpio_setSpeed(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_speed_t speed)
{
    GpioWrapper_setSpeed(port, pin, speed);
}

/**
 * @brief Set pin's Output Type
 * @param port Pin's port
 * @param pin Pin
 * @param output_type Pin´s Output Type
 */
void Gpio_setOutputType(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_outputType_t output_type)
{
    GpioWrapper_setOutputType(port, pin, output_type);
}

/**
 * @brief Configure pin for alternate function
 * @param port Pin's port
 * @param pin Pin
 * @param Gpio_alternate_t pin´s alternate function
 */
void Gpio_setAlternate(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_alternate_t alternate)
{
    GpioWrapper_setAlternate(port, pin, alternate);
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
