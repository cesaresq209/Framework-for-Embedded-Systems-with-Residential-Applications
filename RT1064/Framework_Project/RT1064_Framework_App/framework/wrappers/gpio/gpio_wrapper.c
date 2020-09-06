/******************************************************************************
 *. Copyright 2020 Cesar Rodriguez, All Rights Reserved
 *.=============================================================================
 *. Template C Source File
 *.=============================================================================
 *. FILE: gpio_wrapper.c
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

#define DUMMY_MUX          (uint32_t)0x00
#define MUX_ADDRESS_OFFSET (uint32_t)0x04
#define DUMMY_PAD          (uint32_t)0x00
#define PAD_ADDRESS_OFFSET (uint32_t)0x04

// Speed Configuration
#define SPEED_OFFSET     (uint8_t)6
#define CLEAR_SPEED_MASK (uint32_t)0xFFFFFF3F
// Pull Configuration
#define PULL_OFFSET     (uint8_t)12
#define CLEAR_PULL_MASK (uint32_t)0xFFFF0FFF
// Output Type Configuration
#define OUTPUT_TYPE_OFFSET     (uint8_t)11
#define CLEAR_OUTPUT_TYPE_MASK (uint32_t)0xFFFFF7FF
// GPIO Mux Configuration
#define GPIO_OFFSET     (uint8_t)0
#define CLEAR_GPIO_MASK (uint32_t)0xFFFFFFE0
#define MUX_AS_GPIO     (uint8_t)5
// UART  Mux Configuration
#define UART_OFFSET     (uint8_t)0
#define CLEAR_UART_MASK (uint32_t)0xFFFFFFE0

// UART Pins Configuration
/*
   -Slew Rate Field: Slow Slew Rate
   -Drive Strength Field: R0/6
   -Speed Field: medium(100MHz)
   -Open Drain Enable Field: Open Drain Disabled
   -Pull / Keep Enable Field: Pull/Keeper Enabled
   -Pull / Keep Select Field: Keeper
   -Pull Up / Down Config. Field: 100K Ohm Pull Down
   -Hyst. Enable Field: Hysteresis Disabled
*/
#define UART_CONFIGURATION (uint32_t)0x10B0U

/***********************
 * Constants            *
 ***********************/

/***********************
 * Calibrations         *
 ***********************/

/***********************
 * Global Variables     *
 ***********************/

Gpio_port_t* GPIO_port[PORT_MAX] = {GPIO1, GPIO2, GPIO3, GPIO4, GPIO5};

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
    if ((port >= PORT_MAX) || (pin >= PIN_MAX))
    {
        return false;
    }
    switch (port)
    {
        case PORT_1:
        case PORT_2:
        case PORT_4:
            // PORT 1,2 and 4 have 32 GPIO Pins
            return true;
            break;
        case PORT_3:
            // PORT 3 has just pins 0-27
            if (pin > PIN_27)
            {
                return false;
            }
            else
            {
                return true;
            }
            break;
        case PORT_5:
            // PORT 5 has just pins 0-2
            if (pin > PIN_2)
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
 * @brief Get Pin PadRegister
 * @param port Pin's port
 * @param pin Pin to be read
 * @return Pin's Pad Register
 */
uint32_t GpioWrapper_GetPadAddress(Gpio_portId_t port, Gpio_pinId_t pin)
{
    uint32_t pad_Address;
    uint32_t base_Address;
    switch (port)
    {
        case PORT_1:
            /*
             * GPIO_AD_B0_00 ->GPIO_AD_B0_15: GPIO1 Pin 0 to GPIO1 Pin 15
             * GPIO_AD_B1_00 ->GPIO_AD_B1_15: GPIO1 Pin 16 to GPIO1 Pin 31
             */
            base_Address = (uint32_t)0x401F82ACU; // Assign address of GPIO_AD_B0_00
            break;
        case PORT_2:
            /*
             * GPIO_B0_00 -> GPIO_B0_15: GPIO2 Pin 0 to GPIO2 Pin 15
             * GPIO_B1_00 -> GPIO_B1_15: GPIO2 Pin 16 to GPIO2 Pin 31
             */
            base_Address = (uint32_t)0x401F832CU; // Assign address of GPIO_AD_B0_00
            break;
        case PORT_3:
            /*
             * GPIO_SD_B1_00 ->GPIO_SD_B1_11: GPIO3 Pin 0 to GPIO3 Pin 11
             * GPIO_SD_B0_00 ->GPIO_SD_B0_05: GPIO3 Pin 12 to GPIO3 Pin 17
             * GPIO_EMC_32 -> GPIO_EMC_41: GPIO3 Pin18 to GPIO3 Pin 27
             */
            if (pin <= PIN_11)
            {
                base_Address = (uint32_t)0x401F83C4U; // Assign address of GPIO_SD_B1_00
            }
            else if (pin > PIN_17)
            {
                base_Address = (uint32_t)0x401F8284U; // Assign address of GPIO_EMC_32
            }
            else
            {
                base_Address = (uint32_t)0x401F83ACU; // Assign address of GPIO_SD_B0_00
            }
            break;
        case PORT_4:
            /*
             * GPIO_EMC_00 -> GPIO_EMC_31: GPIO4 Pin0 to GPIO4 Pin 31
             */
            base_Address = (uint32_t)0x401F8204U; // Assign address of GPIO_EMC_00
            break;
        case PORT_5:
            /*
             * SNVS_WAKEUP -> GPIO5 Pin 0
             * SNVS_PMIC_ON_REQ-> GPIO5 Pin 1
             * SNVS_PMIC_STBY_REQ-> GPIO5 Pin 2
             */
            base_Address = (uint32_t)0x400A8018U; // Assign address of SNVS_WAKEUP
            break;
        default:
            pad_Address = DUMMY_PAD;
            return pad_Address;
            break;
    }
    pad_Address = base_Address + (pin * PAD_ADDRESS_OFFSET);
    return pad_Address;
}

/**
 * @brief Get Pin Mux Register
 * @param port Pin's port
 * @param pin Pin to be read
 * @return Pin's Mux Register
 */
uint32_t GpioWrapper_GetMuxAddress(Gpio_portId_t port, Gpio_pinId_t pin)
{
    uint32_t mux_Address;
    uint32_t base_Address;
    switch (port)
    {
        case PORT_1:
            /*
             * GPIO_AD_B0_00 ->GPIO_AD_B0_15: GPIO1 Pin 0 to GPIO1 Pin 15
             * GPIO_AD_B1_00 ->GPIO_AD_B1_15: GPIO1 Pin 16 to GPIO1 Pin 31
             */
            base_Address = (uint32_t)0x401F80BCU; // Assign address of GPIO_AD_B0_00
            break;
        case PORT_2:
            /*
             * GPIO_B0_00 -> GPIO_B0_15: GPIO2 Pin 0 to GPIO2 Pin 15
             * GPIO_B1_00 -> GPIO_B1_15: GPIO2 Pin 16 to GPIO2 Pin 31
             */
            base_Address = (uint32_t)0x401F813CU; // Assign address of GPIO_AD_B0_00
            break;
        case PORT_3:
            /*
             * GPIO_SD_B1_00 ->GPIO_SD_B1_11: GPIO3 Pin 0 to GPIO3 Pin 11
             * GPIO_SD_B0_00 ->GPIO_SD_B0_05: GPIO3 Pin 12 to GPIO3 Pin 17
             * GPIO_EMC_32 -> GPIO_EMC_41: GPIO3 Pin18 to GPIO3 Pin 27
             */
            if (pin <= PIN_11)
            {
                base_Address = (uint32_t)0x401F81D4U; // Assign address of GPIO_SD_B1_00
            }
            else if (pin > PIN_17)
            {
                base_Address = (uint32_t)0x401F8094U; // Assign address of GPIO_EMC_32
            }
            else
            {
                base_Address = (uint32_t)0x401F81BCU; // Assign address of GPIO_SD_B0_00
            }
            break;
        case PORT_4:
            /*
             * GPIO_EMC_00 -> GPIO_EMC_31: GPIO4 Pin0 to GPIO4 Pin 31
             */
            base_Address = (uint32_t)0x401F8014U; // Assign address of GPIO_EMC_00
            break;
        case PORT_5:
            /*
             * SNVS_WAKEUP -> GPIO5 Pin 0
             * SNVS_PMIC_ON_REQ-> GPIO5 Pin 1
             * SNVS_PMIC_STBY_REQ-> GPIO5 Pin 2
             */
            base_Address = (uint32_t)0x400A8000U; // Assign address of SNVS_WAKEUP
            break;
        default:
            mux_Address = DUMMY_MUX;
            return mux_Address;
            break;
    }
    mux_Address = base_Address + (pin * MUX_ADDRESS_OFFSET);
    return mux_Address;
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
    // Disable Keeper and Remove Pull Up/Down Resistor
    GpioWrapper_setPull(port, pin, PULL_NOT_AVAILABLE);
}

/**
 * @brief Configure GPIO for UART use
 * @param port Pin's port
 * @param pin Pin
 */
void ConfigureGpioAsUart(Gpio_portId_t port, Gpio_pinId_t pin)
{
    uint8_t  muxOffset   = 0;
    uint32_t value       = 0;
    uint32_t uartPinMask = 0x00000000;
    // Get address of mux register
    uint32_t mux_Address = GpioWrapper_GetMuxAddress(port, pin);
    if (mux_Address == DUMMY_MUX)
    {
        // Invalid  Pin
        return;
    }
    uint32_t pad_Address = GpioWrapper_GetPadAddress(port, pin);
    if (pad_Address == DUMMY_PAD)
    {
        // Invalid  Pin
        return;
    }
    switch (port)
    {
        case PORT_1:
            /*
            Create mask to check if pin is valid.
            Valid UART pins are:
            - UART1: PORT1 Pin 12(TX, ALT2), PORT1 Pin 13 (RX, ALT2)
            - UART2: PORT1 Pin 18(TX, ALT2), PORT1 Pin 19 (RX, ALT2)
            - UART3: PORT1 Pin 22(TX, ALT2), PORT1 Pin 23 (RX, ALT2)
            - UART6: PORT1 Pin 2 (TX, ALT2), PORT1 Pin 3  (RX, ALT2)
            - UART8: PORT1 Pin 26(TX, ALT2), PORT1 Pin 27 (RX, ALT2)
            */
            uartPinMask = 0x0CCC300C;
            // Check if the pin is valid for UART
            if ((1 << pin) & uartPinMask)
            {
                // Enable Mux Clock
                CLOCK_EnableClock(kCLOCK_Iomuxc);
                // Select GPIO Signal in Mux
                value = *((volatile uint32_t*)mux_Address);
                // Select UART Offset (All Pins of PORT1 Use Alternate Funcion 2)
                muxOffset = 0x12;
                value &= CLEAR_UART_MASK;
                value |= (muxOffset << UART_OFFSET);
                // Select UART Functionality in Mux
                *((volatile uint32_t*)mux_Address) = value;
                // Configure PAD
                *((volatile uint32_t*)pad_Address) = UART_CONFIGURATION;
            }
            break;
        case PORT_2:
            // UART3: PORT2 Pin 8 (TX, ALT3), PORT2 Pin 9 (RX, ALT3)
            // UART4: PORT2 Pin 16(TX, ALT2), PORT2 Pin 17(RX, ALT2)
            // UART5: PORT2 Pin 28(TX, ALT1), PORT2 Pin 29(RX, ALT1)
            uartPinMask = 0x30030300;
            // Check if the pin is valid for UART
            if ((1 << pin) & uartPinMask)
            {
                // Enable Mux Clock
                CLOCK_EnableClock(kCLOCK_Iomuxc);
                // Select GPIO Signal in Mux
                uint32_t value = *((volatile uint32_t*)mux_Address);
                // Select UART Offset
                if ((pin == 8) || (pin == 9))
                {
                    // UART3 Pins use Alternate Function 3
                    muxOffset = 0x13;
                }
                else if ((pin == 16) || (pin == 17))
                {
                    // UART4 Pins use Alternate Function 2
                    muxOffset = 0x12;
                }
                else
                {
                    // UART5 Pins use Alternate Function 1
                    muxOffset = 0x11;
                }
                value &= CLEAR_UART_MASK;
                // Select UART Functionality in Mux
                value |= (muxOffset << UART_OFFSET);
                *((volatile uint32_t*)mux_Address) = value;
                // Configure PAD
                *((volatile uint32_t*)pad_Address) = UART_CONFIGURATION;
            }
            break;
        case PORT_3:
            // UART2: PORT3 Pin 11 (TX, ALT2), PORT3 Pin 10 (RX,ALT2)
            // UART4: PORT3 Pin 0  (TX, ALT4), PORT3 Pin 1  (RX,ALT4)
            // UART7: PORT3 Pin 8  (TX, ALT2), PORT3 Pin 18 (RX,ALT2), PORT3 Pin 9 (RX, ALT2)
            // UART8: PORT3 Pin 24 (TX, ALT2), PORT3 Pin 16 (TX,ALT2)
            // UART8: PORT3 Pin 17 (RX, ALT2), PORT3 Pin 25 (RX,ALT2)
            uartPinMask = 0x03070F03;
            // Check if the pin is valid for UART
            if ((1 << pin) & uartPinMask)
            {
                // Enable Mux Clock
                CLOCK_EnableClock(kCLOCK_Iomuxc);
                // Select GPIO Signal in Mux
                uint32_t value = *((volatile uint32_t*)mux_Address);
                // Select UART Offset
                if ((pin == 0) || (pin == 1))
                {
                    // UART4 Pins use Alternate Function 4
                    muxOffset = 0x14;
                }
                else
                {
                    // Other pins use alternate function 2
                    muxOffset = 0x12;
                }
                value &= CLEAR_UART_MASK;
                value |= (muxOffset << UART_OFFSET);
                // Select UART Functionality in Mux
                *((volatile uint32_t*)mux_Address) = value;
                // Configure PAD
                *((volatile uint32_t*)pad_Address) = UART_CONFIGURATION;
            }
            break;
        case PORT_4:
            // UART3: PORT4 Pin 13 (TX, ALT2), PORT4 Pin 14 (RX,ALT2)
            // UART4: PORT4 Pin 19 (TX, ALT2), PORT4 Pin 20 (RX,ALT2)
            // UART5: PORT4 Pin 23 (TX, ALT2), PORT4 Pin 24 (RX,ALT2)
            // UART6: PORT4 Pin 25 (TX, ALT2), PORT4 Pin 26 (RX,ALT2)
            // UART7: PORT4 Pin 31 (TX, ALT2)
            uartPinMask = 0x87986000;
            // Check if the pin is valid for UART
            if ((1 << pin) & uartPinMask)
            {
                // Enable Mux Clock
                CLOCK_EnableClock(kCLOCK_Iomuxc);
                // Select GPIO Signal in Mux
                uint32_t value = *((volatile uint32_t*)mux_Address);
                // Select UART Offset (All Pins of PORT4 Use alternate funcion 2)
                muxOffset = 0x12;
                value &= CLEAR_UART_MASK;
                value |= (muxOffset << UART_OFFSET);
                // Select UART Functionality in Mux
                *((volatile uint32_t*)mux_Address) = value;
                // Configure PAD
                *((volatile uint32_t*)pad_Address) = UART_CONFIGURATION;
            }
            break;
        // PORT 5 does not contain GPIO Pins
        case PORT_5:
        default:
            break;
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
    uint32_t mux_Address = GpioWrapper_GetMuxAddress(port, pin);
    if ((mux_Address == DUMMY_MUX) || !GpioWrapper_IsGPIOValid(port, pin))
    {
        // Invalid  Pin
        return;
    }
    gpio_pin_config_t pin_Config = {mode, 0U, kGPIO_NoIntmode};
    // Enable Mux Clock
    CLOCK_EnableClock(kCLOCK_Iomuxc);
    // Init Pin as GPIO
    GPIO_PinInit(GPIO_port[port], pin, &pin_Config);

    // Select GPIO Signal in Mux
    uint32_t value = *((volatile uint32_t*)mux_Address);
    value &= CLEAR_GPIO_MASK;
    value |= (MUX_AS_GPIO << GPIO_OFFSET);
    *((volatile uint32_t*)mux_Address) = value;

    switch (port)
    {
        case PORT_1:
            // GPIO1 and GPIO6 share same IO MUX function, select GPIO1
            IOMUXC_GPR->GPR26 = IOMUXC_GPR->GPR26 & (~((uint32_t)1 << pin));
            break;
        case PORT_2:
            // GPIO2 and GPIO7 share same IO MUX function, select GPIO2
            IOMUXC_GPR->GPR27 = IOMUXC_GPR->GPR27 & (~((uint32_t)1 << pin));
            break;
        case PORT_3:
            // GPIO3 and GPIO8 share same IO MUX function, select GPIO3
            IOMUXC_GPR->GPR28 = IOMUXC_GPR->GPR28 & (~((uint32_t)1 << pin));
            break;
        case PORT_4:
            // GPIO4 and GPIO9 share same IO MUX function, select GPIO4
            IOMUXC_GPR->GPR29 = IOMUXC_GPR->GPR29 & (~((uint32_t)1 << pin));
            break;
        case PORT_5:
            // GPIO5 does not share IO Mux function
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
    uint32_t pad_Address = GpioWrapper_GetPadAddress(port, pin);
    if ((pad_Address == DUMMY_PAD) || (!GpioWrapper_IsGPIOValid(port, pin)))
    {
        // Invalid  Pin
        return;
    }
    uint32_t value = *((volatile uint32_t*)pad_Address);
    value &= CLEAR_PULL_MASK;
    value |= (pull << PULL_OFFSET);
    *((volatile uint32_t*)pad_Address) = value;
}

/**
 * @brief Set pin's speed
 * @param port Pin's port
 * @param pin Pin
 * @param speed Speed
 */
void GpioWrapper_setSpeed(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_speed_t speed)
{
    uint32_t pad_Address = GpioWrapper_GetPadAddress(port, pin);
    if ((pad_Address == DUMMY_PAD) || (speed == SPEED_NOT_AVAILABLE) ||
        (!GpioWrapper_IsGPIOValid(port, pin)))
    {
        // Invalid  Pin
        return;
    }
    uint32_t value = *((volatile uint32_t*)pad_Address);
    value &= CLEAR_SPEED_MASK;
    value |= (speed << SPEED_OFFSET);
    *((volatile uint32_t*)pad_Address) = value;
}

/**
 * @brief Set pin's output type
 * @param port Pin's port
 * @param pin Pin
 * @param output_type pin´s output type
 */
void GpioWrapper_setOutputType(Gpio_portId_t port, Gpio_pinId_t pin, Gpio_outputType_t output_type)
{
    uint32_t pad_Address = GpioWrapper_GetPadAddress(port, pin);
    if ((pad_Address == DUMMY_PAD) || (!GpioWrapper_IsGPIOValid(port, pin)))
    {
        // Invalid  Pin
        return;
    }
    uint32_t value = *((volatile uint32_t*)pad_Address);
    value &= CLEAR_OUTPUT_TYPE_MASK;
    value |= (output_type << OUTPUT_TYPE_OFFSET);
    *((volatile uint32_t*)pad_Address) = value;
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
                // Just pins from 12 to 31 of PORT 1 Support ADC
                if ((port == PORT_1) && (pin >= PIN_12))
                {
                    ConfigureGpioAsAdc(port, pin);
                }
                break;
            case ALT_MODE_UART:
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
    uint8_t output;
    if ((port >= PORT_MAX))
    {
        // Invalid Port
        return;
    }
    for (uint8_t i = 0; i < PIN_MAX; i++)
    {
        output = (uint8_t)((value & ((Gpio_data_t)1 << i)) >> i);
        GPIO_PinWrite(GPIO_port[port], (uint32_t)i, output);
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
        // Invalid pin
        return;
    }
    GPIO_PinWrite(GPIO_port[port], pin, (uint8_t)state);
}

/**
 * @brief Read port's value
 * @param port Pin's port
 * @return Port's value
 */
Gpio_data_t GpioWrapper_ReadPort(Gpio_portId_t port)
{
    if ((port >= PORT_MAX))
    {
        // Invalid Port
        return (Gpio_data_t)0x00000000;
    }
    Gpio_data_t portValue = 0x00000000;
    for (uint8_t i = 0; i < PIN_MAX; i++)
    {
        portValue |= (GPIO_PinRead(GPIO_port[port], i) << i);
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
    Gpio_pinState_t pinState;
    if ((port >= PORT_MAX))
    {
        // Invalid Port
        return (Gpio_pinState_t)0;
    }
    pinState = GPIO_PinRead(GPIO_port[port], pin);

    return pinState;
}
