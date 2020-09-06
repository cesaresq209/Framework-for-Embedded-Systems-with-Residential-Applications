/**
 * @file gpio_wrapper.h
 * @author Cesar Rodriguez
 * @brief GPIO framework module wrapper header
 */

/************************
 * Guard                *
 ************************/
#ifndef _GPIO_WRAPPER_H_
#define _GPIO_WRAPPER_H_

/************************
 * Includes             *
 ************************/
#include "MIMXRT1064.h"
#include "fsl_gpio.h"

/************************
 * Public Types         *
 ************************/

/**
 * @brief GPIO port IDs for RT1064
 */
typedef enum
{
    PORT_1,
    PORT_2,
    PORT_3,
    PORT_4,
    PORT_5,
    PORT_MAX
} Gpio_portId_t;

/**
 * @brief GPIO pin IDs for RT1064
 */
typedef enum
{
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15,
    PIN_16,
    PIN_17,
    PIN_18,
    PIN_19,
    PIN_20,
    PIN_21,
    PIN_22,
    PIN_23,
    PIN_24,
    PIN_25,
    PIN_26,
    PIN_27,
    PIN_28,
    PIN_29,
    PIN_30,
    PIN_31,
    PIN_MAX
} Gpio_pinId_t;

/**
 * @brief GPIO Alternate Modes
 */
typedef enum
{
    ALT_MODE_ANALOG,
    ALT_MODE_UART,
    ALT_MODE_I2C,
    ALT_MODE_SPI,
    ALT_MODE_NONE,
    ALT_MODE_MAX_VALUE
} Gpio_alternate_t;

/**
 * @brief GPIO port data type
 */
typedef GPIO_Type Gpio_port_t;

/**
 * @brief GPIO pin data type
 */
typedef uint32_t Gpio_pin_t;

/**
 * @brief GPIO data type
 */
typedef uint32_t Gpio_data_t;

/**
 * @brief GPIO mode type
 */
typedef gpio_pin_direction_t Gpio_mode_t;

/**
 * @brief GPIO pull resistor type
 */
typedef uint8_t Gpio_pull_t;

/**
 * @brief GPIO pin speed type
 */
typedef uint8_t Gpio_speed_t;

/**
 * @brief GPIO pin output type
 */
typedef uint8_t Gpio_outputType_t;

/**
 * @brief GPIO pinstate
 */
typedef uint8_t Gpio_pinState_t;

/************************
 * Public Macros        *
 ************************/

/************************
 * Public Defines       *
 ************************/
// Dummy value used for unsuported definitions
#define GPIO_NOT_SUPPORTED 0x55

// Pin state
#define HIGH (uint8_t)0x01
#define LOW  (uint8_t)0x00

// MODE
#define MODE_INPUT              kGPIO_DigitalInput
#define MODE_OUTPUT             kGPIO_DigitalOutput
#define MODE_ALTERNATE_FUNCTION ((uint32_t)0x02)

// PULL
#define PULL_UP            ((uint8_t)0xB)
#define PULL_DOWN          ((uint8_t)0x03)
#define PULL_NOT_AVAILABLE ((uint8_t)0x0)

// SPEED
#define SPEED_FAST          ((uint8_t)0x0)
#define SPEED_MEDIUM        ((uint8_t)0x1)
#define SPEED_HIGH          ((uint8_t)0x3)
#define SPEED_NOT_AVAILABLE (uint8_t) GPIO_NOT_SUPPORTED

// Output Type
#define OTYPE_PUSH_PULL  ((uint8_t)0x0)
#define OTYPE_OPEN_DRAIN ((uint8_t)0x1)

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

void GpioWrapper_setMode(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_mode_t mode);
void GpioWrapper_setPull(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_pull_t pull);
void GpioWrapper_setSpeed(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_speed_t speed);
void GpioWrapper_setOutputType(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_outputType_t output_type);
void GpioWrapper_setAlternate(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_alternate_t alternate);
void GpioWrapper_WritePort(Gpio_portId_t port, Gpio_data_t value);
void GpioWrapper_SetPin(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_pinState_t state);
Gpio_data_t     GpioWrapper_ReadPort(Gpio_portId_t port);
Gpio_pinState_t GpioWrapper_GetPin(Gpio_portId_t port, Gpio_pinId_t pin);

#endif /* _GPIO_WRAPPER_H_ */
