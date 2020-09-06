/******************************************************************************
 *. Copyright 2020 C�sar Rodr�guez, All Rights Reserved
 *.=============================================================================
 *. Template C Source File
 *.=============================================================================
 *. FILE: main.c
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
 * @file gpio_wrapper.c
 * @author Cesar Rodriguez
 * @brief GPIO framework module wrapper source file
 */

/***********************
 * Includes             *
 ***********************/
#include "gpio_wrapper.h"

/***********************
 * Type Definitions     *
 ***********************/

/***********************
 * Macros               *
 ***********************/

/***********************
 * Defines              *
 ***********************/

/***********************
 * Constants            *
 ***********************/

/***********************
 * Calibrations         *
 ***********************/

/***********************
 * Global Variables     *
 ***********************/

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
 * @brief Check if GPIO is valid
 * @param port Pin's port
 * @param pin Pin
 * @return
 */
bool GpioWrapper_IsGPIOValid(Gpio_portId_t port, Gpio_pinId_t pin)
{
    if ((pin >= PIN_MAX) || (port >= PORT_MAX))
    {
        return false;
    }
    switch (port)
    {
        case PORT_A:
        case PORT_C:
        case PORT_D:
            // PORT A has 8 pins
            return true;
            break;
        case PORT_B:
            // PORT B has just pins 0-5
            if (pin > PIN_5)
            {
                return false;
            }
            else
            {
                return true;
            }
            break;
        case PORT_E:
            // PORT E has just pins 0-4
            if (pin > PIN_4)
            {
                return false;
            }
            else
            {
                return true;
            }
            break;
        case PORT_F:
            // PORT F has just pins 0-6
            if (pin > PIN_6)
            {
                return false;
            }
            else
            {
                return true;
            }
            break;
        default:
            // pin not found
            return false;
            break;
    }
}

/**
 * @brief Configure GPIO for ADC use
 * @param port Pin's port
 * @param pin Pin
 */
void ConfigureGpioAsAdc(Gpio_portId_t port, Gpio_pinId_t pin)
{
    // Set GPIO as Input
    GpioWrapper_setMode(port, pin, MODE_INPUT);
    // Remove Pull Up/Down Resistor
    GpioWrapper_setPull(port, pin, PULL_NOT_AVAILABLE);
}

/**
 * @brief Configure GPIO for UART use
 * @param port Pin's port
 * @param pin Pin
 */
void ConfigureGpioAsUart(Gpio_portId_t port, Gpio_pinId_t pin)
{
    /*
    Pins that can be used for UART are:
        -UART0:PA0(Tx), PA1(Rx), PA4(Tx), PA5(Rx)
        -UART1:PC0(Tx), PC1(Rx), PC4(Tx), PC5(Rx)
        -UART2:PF0(Tx), PF1(Rx), PF4(Tx), PF5(Rx)
        -UART3:PB0(Tx), PB1(Rx), PB4(Tx), PB5(Rx)
    */
    uint8_t uartMux = PORTMUX.USARTROUTEA;
    uint8_t shiftVal;
    bool    portValid = false;

    // Check if PORT is valid and get offset for Multiplexer
    switch (port)
    {
        case PORT_A:
            shiftVal  = 0;
            portValid = true;
            break;
        case PORT_B:
            shiftVal  = 6;
            portValid = true;
            break;
        case PORT_C:
            shiftVal  = 2;
            portValid = true;
            break;
        case PORT_F:
            shiftVal  = 4;
            portValid = true;
            break;
        default:
            break;
    }
    if (portValid)
    {
        // Check if Pin is valid, configure GPIO and set Multiplexer
        switch (pin)
        {
            case PIN_0:
                // Set GPIO as Input
                GpioWrapper_setMode(port, pin, MODE_OUTPUT);
                // Remove Pull Up/Down Resistor
                GpioWrapper_setPull(port, pin, PULL_NOT_AVAILABLE);
                uartMux &= ~((uint8_t)1 << shiftVal);
                PORTMUX.USARTROUTEA = uartMux;
                break;
            case PIN_1:
                // Set GPIO as Input
                GpioWrapper_setMode(port, pin, MODE_INPUT);
                // Remove Pull Up/Down Resistor
                GpioWrapper_setPull(port, pin, PULL_NOT_AVAILABLE);
                uartMux &= ~((uint8_t)1 << shiftVal);
                PORTMUX.USARTROUTEA = uartMux;
                break;
            case PIN_4:
                // Set GPIO as Input
                GpioWrapper_setMode(port, pin, MODE_OUTPUT);
                // Remove Pull Up/Down Resistor
                GpioWrapper_setPull(port, pin, PULL_NOT_AVAILABLE);
                uartMux |= ((uint8_t)1 << shiftVal);
                PORTMUX.USARTROUTEA = uartMux;
                break;
            case PIN_5:
                // Set GPIO as Input
                GpioWrapper_setMode(port, pin, MODE_INPUT);
                // Remove Pull Up/Down Resistor
                GpioWrapper_setPull(port, pin, PULL_NOT_AVAILABLE);
                uartMux |= ((uint8_t)1 << shiftVal);
                PORTMUX.USARTROUTEA = uartMux;
                break;
            default:
                break;
        }
    }
}

/**
 * @brief Set pin's mode
 * @param port Pin's port
 * @param pin Pin
 * @param mode Mode
 */
void GpioWrapper_setMode(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_mode_t mode)
{
    if (!GpioWrapper_IsGPIOValid(port, pin))
    {
        // Invalid Pin
        return;
    }
    switch (port)
    {
        case PORT_A:
            PORTA_set_pin_dir(pin, mode);
            break;
        case PORT_B:
            PORTB_set_pin_dir(pin, mode);
            break;
        case PORT_C:
            PORTC_set_pin_dir(pin, mode);
            break;
        case PORT_D:
            PORTD_set_pin_dir(pin, mode);
            break;
        case PORT_E:
            PORTE_set_pin_dir(pin, mode);
            break;
        case PORT_F:
            PORTF_set_pin_dir(pin, mode);
            break;
        default:
            break;
    }
}

/**
 * @brief Set pin's pull resistor
 * @param port Pin's port
 * @param pin Pin
 * @param pull Pull resistor
 */
void GpioWrapper_setPull(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_pull_t pull)
{
    if (!GpioWrapper_IsGPIOValid(port, pin))
    {
        // Invalid Pin
        return;
    }
    switch (port)
    {
        case PORT_A:
            PORTA_set_pin_pull_mode(pin, pull);
            break;
        case PORT_B:
            PORTB_set_pin_pull_mode(pin, pull);
            break;
        case PORT_C:
            PORTC_set_pin_pull_mode(pin, pull);
            break;
        case PORT_D:
            PORTD_set_pin_pull_mode(pin, pull);
            break;
        case PORT_E:
            PORTE_set_pin_pull_mode(pin, pull);
            break;
        case PORT_F:
            PORTF_set_pin_pull_mode(pin, pull);
            break;
        default:
            break;
    }
}

/**
 * @brief Set pin's speed
 * @param port Pin's port
 * @param pin Pin
 * @param speed Speed
 * @note Speed can´t be configured for this microcontroller
 */
void GpioWrapper_setSpeed(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_speed_t speed)
{
    // No Speed settings
}

/**
 * @brief Set pin's output type
 * @param port Pin's port
 * @param pin Pin
 * @param output_type pin´s output type
 * @note Output Type can´t be configured for this microcontroller
 */
void GpioWrapper_setOutputType(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_outputType_t output_type)
{
    // GPIOs of this microcontroller can´t switch between open drain and push-pull
}

/**
 * @brief Configure pin for alternate function
 * @param port Pin's port
 * @param pin Pin
 * @param Gpio_alternate_t pin´s alternate function
 */
void GpioWrapper_setAlternate(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_alternate_t alternate)
{
    if (GpioWrapper_IsGPIOValid(port, pin))
    {
        switch (alternate)
        {
            case ALT_MODE_ANALOG:
                // Port D, Port E and pins 2-6 o Port F can be used for ADC
                if ((port == PORT_D) || (port == PORT_E) ||
                    ((port == PORT_F) && (pin > PIN_1) && (pin < PIN_6)))
                {
                    ConfigureGpioAsAdc(port, pin);
                }
                break;
            case ALT_MODE_UART:
                /*
                Pins that can be used for UART are:
                  -UART0:PA0(Tx), PA1(Rx), PA4(Tx), PA5(Rx)
                  -UART1:PC0(Tx), PC1(Rx), PC4(Tx), PC5(Rx)
                  -UART2:PF0(Tx), PF1(Rx), PF4(Tx), PF5(Rx)
                  -UART3:PB0(Tx), PB1(Rx), PB4(Tx), PB5(Rx)
                */
                ConfigureGpioAsUart(port, pin);
                break;
            case ALT_MODE_I2C:
            case ALT_MODE_SPI:
            case ALT_MODE_NONE:
            default:
                break;
        }
    }
}

/**
 * @brief Write value to port
 * @param port Port to be written
 * @param value Value to be written to port
 */
void GpioWrapper_WritePort(Gpio_portId_t port, Gpio_data_t value)
{
    if (port > PORT_MAX)
    {
        // Invalid Port
        return;
    }
    switch (port)
    {
        case PORT_A:
            PORTA_write_port(value);
            break;
        case PORT_B:
            PORTB_write_port(value);
            break;
        case PORT_C:
            PORTC_write_port(value);
            break;
        case PORT_D:
            PORTD_write_port(value);
            break;
        case PORT_E:
            PORTE_write_port(value);
            break;
        case PORT_F:
            PORTF_write_port(value);
            break;
        default:
            break;
    }
}

/**
 * @brief Write value to GPIO pin
 * @param port Pin's port
 * @param pin Pin to be written
 * @param state Value to be written to pin
 */
void GpioWrapper_SetPin(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_pinState_t state)
{
    if (!GpioWrapper_IsGPIOValid(port, pin))
    {
        // Invalid Pin
        return;
    }
    switch (port)
    {
        case PORT_A:
            PORTA_set_pin_level(pin, state);
            break;
        case PORT_B:
            PORTB_set_pin_level(pin, state);
            break;
        case PORT_C:
            PORTC_set_pin_level(pin, state);
            break;
        case PORT_D:
            PORTD_set_pin_level(pin, state);
            break;
        case PORT_E:
            PORTE_set_pin_level(pin, state);
            break;
        case PORT_F:
            PORTF_set_pin_level(pin, state);
            break;
        default:
            break;
    }
}

/**
 * @brief Read port's value
 * @param port Pin's port
 * @return Port's value
 */
Gpio_data_t GpioWrapper_ReadPort(Gpio_portId_t port)
{
    Gpio_data_t portValue;
    if (port > PORT_MAX)
    {
        // Invalid Port
        return (Gpio_data_t)0x00;
    }
    switch (port)
    {
        case PORT_A:
            portValue = PORTA_get_port_level();
            break;
        case PORT_B:
            portValue = PORTB_get_port_level();
            break;
        case PORT_C:
            portValue = PORTC_get_port_level();
            break;
        case PORT_D:
            portValue = PORTD_get_port_level();
            break;
        case PORT_E:
            portValue = PORTE_get_port_level();
            break;
        case PORT_F:
            portValue = PORTF_get_port_level();
            break;
        default:
            portValue = LOW;
            break;
    }
    return portValue;
}

/**
 * @brief Read GPIO pin's value
 * @param port Pin's port
 * @param pin Pin to be read
 * @return Pin's value
 */
Gpio_pinState_t GpioWrapper_GetPin(Gpio_portId_t port, Gpio_pinId_t pin)
{
    volatile Gpio_pinState_t pinState;
    if (!GpioWrapper_IsGPIOValid(port, pin))
    {
        // Invalid Pin
        return (Gpio_pinState_t)0;
    }
    switch (port)
    {
        case PORT_A:
            pinState = PORTA_get_pin_level(pin);
            break;
        case PORT_B:
            pinState = PORTB_get_pin_level(pin);
            break;
        case PORT_C:
            pinState = PORTC_get_pin_level(pin);
            break;
        case PORT_D:
            pinState = PORTD_get_pin_level(pin);
            break;
        case PORT_E:
            pinState = PORTE_get_pin_level(pin);
            break;
        case PORT_F:
            pinState = PORTF_get_pin_level(pin);
            break;
        default:
            pinState = LOW;
            break;
    }
    return pinState;
}
