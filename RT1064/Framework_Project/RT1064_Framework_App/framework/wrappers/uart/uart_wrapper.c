/******************************************************************************
 *. Copyright 2020 Cesar Rodriguez, All Rights Reserved
 *.=============================================================================
 *. Template C Source File
 *.=============================================================================
 *. FILE: uart_wrapper.c
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
 * @file uart_wrapper.c
 * @author Cesar Rodriguez
 * @brief UART framework module wrapper source file
 */

/***********************
 * Includes             *
 ***********************/
#include "uart_wrapper.h"

/***********************
 * Type Definitions     *
 ***********************/

/***********************
 * Macros               *
 ***********************/

/***********************
 * Defines              *
 ***********************/
#define UART_DATA_MASK  (uint32_t)0x000003FF
#define ENABLE_UART     true
#define DISABLE_UART    false
#define SEVEN_DATA_BITS (uint8_t)7
#define EIGHT_DATA_BITS (uint8_t)8
#define NINE_DATA_BITS  (uint8_t)9

// CTL Register Masks
#define CTL_CLEAR_DATA_BITS_MASK   (uint32_t)0x00000810
#define CTL_CLEAR_PARITY_BITS_MASK (uint32_t)0x00000011

// BAUD Register Masks
#define BAUD_CLEAR_DATA_BITS_MASK (uint32_t)0x20000000
#define BAUD_CLEAR_STOP_BITS_MASK (uint32_t)0x00002000

/***********************
 * Constants            *
 ***********************/

/***********************
 * Calibrations         *
 ***********************/

/***********************
 * Global Variables     *
 ***********************/
Uart_data_bits_t Uart_Data_Bits[UART_MAX];

Uart_parity_t Uart_Parity[UART_MAX];

Uart_t* Uart[UART_MAX] = {LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8};

clock_ip_name_t UartClocks[UART_MAX] = {kCLOCK_Lpuart1,
                                        kCLOCK_Lpuart2,
                                        kCLOCK_Lpuart3,
                                        kCLOCK_Lpuart4,
                                        kCLOCK_Lpuart5,
                                        kCLOCK_Lpuart6,
                                        kCLOCK_Lpuart7,
                                        kCLOCK_Lpuart8};
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
 * @brief Adjust data bits of UART based on desired data bits and parity
 * @param id UART ID
 * @note All Uarts of this MCU share the same clock. It needs to be configured through the clocks
 * module.
 */
void UartWrapper_AdjustDataBits(Uart_uartId_t id)
{
    uint32_t value           = 0x00000000;
    uint8_t  desiredDataBits = Uart_Data_Bits[id];
    if (Uart_Parity[id] != UART_NO_PARITY)
    {
        // If parity is enabled, add one data bit
        desiredDataBits++;
    }
    /*
    CTL Register M7 (Bit 11): 1->9 Data Bits, 0->8 Data Bits
    CTL Register M (Bit 4):1->7 Data Bits, 0->8 to 10 Data Bits
    BAUD Register M10 (Bit 29):1->10 Data Bits, 0->7 to 9 Data Bits
     */
    switch (desiredDataBits)
    {
        case SEVEN_DATA_BITS:
            // Get value of CTRL Register
            value = Uart[id]->CTRL;
            // Clear M and M4 Bits
            value &= ~(CTL_CLEAR_DATA_BITS_MASK);
            // Configure for 7 Bits
            value |= LPUART_CTRL_M7_MASK;
            Uart[id]->CTRL = value;
            break;
        case EIGHT_DATA_BITS:
            // Get value of CTRL Register
            value = Uart[id]->CTRL;
            // Clear M and M4 Bits (Configuratio for 8 Data Bits)
            value &= ~(CTL_CLEAR_DATA_BITS_MASK);
            Uart[id]->CTRL = value;
            break;
        case NINE_DATA_BITS:
            // Get value of CTRL Register
            value = Uart[id]->CTRL;
            // Clear M and M4 Bits
            value &= ~(CTL_CLEAR_DATA_BITS_MASK);
            // Configure for 9 Bits
            value |= LPUART_CTRL_M_MASK;
            Uart[id]->CTRL = value;
            break;
        default:
            break;
    }
}

/**
 * @brief Sets UART Clock
 * @param id UART ID
 * @param clock UART Clock Source
 * @note All Uarts of this MCU share the same clock. It needs to be configured through the clocks
 * module.
 */
void UartWrapper_SetClock(Uart_uartId_t id, Uart_clock_t clock)
{
    /*
    All Uarts of this MCU share the same clock. It needs to be
    configured through the clocks module.
    */
}

/**
 * @brief Sets Prescaler for UART Clock
 * @param id UART ID
 * @param prescaler Prescaler for UART Clock
 * @note This MCU does not support individual prescalers for the uart clock
 */
void UartWrapper_SetPrescaler(Uart_uartId_t id, Uart_prescaler_t prescaler)
{
    // This MCU does not support individual prescalers for the uart clock
}

/**
 * @brief Sets UART Baud Rate
 * @param id UART ID
 * @param baud_rate UART´s Baud Rate
 */
void UartWrapper_SetBaudRate(Uart_uartId_t id, Uart_baud_rate_t baud_rate)
{
    if (id < UART_MAX)
    {
        LPUART_SetBaudRate(Uart[id], baud_rate, GetUartClockFrequency());
    }
}

/**
 * @brief Sets number of data bits for UART
 * @param id UART ID
 * @param data_bits Data Bits for UART
 */
void UartWrapper_SetDataBits(Uart_uartId_t id, Uart_data_bits_t data_bits)
{
    if ((id < UART_MAX) && (data_bits != UART_NOT_SUPPORTED))
    {
        Uart_Data_Bits[id] = data_bits;
        UartWrapper_AdjustDataBits(id);
    }
}

/**
 * @brief Sets number of stop bits for UART
 * @param id UART ID
 * @param stop_bits Stop Bits for UART
 */
void UartWrapper_SetStopBits(Uart_uartId_t id, Uart_stop_bits_t stop_bits)
{
    if ((id < UART_MAX) && (stop_bits != UART_NOT_SUPPORTED))
    {
        uint32_t value = 0x00000000;
        value          = Uart[id]->BAUD;
        value &= ~(BAUD_CLEAR_STOP_BITS_MASK);
        value |= (stop_bits << 13);
        Uart[id]->BAUD = value;
    }
}

/**
 * @brief Set UART´s Parity
 * @param id UART ID
 * @param parity UART´s parity
 */
void UartWrapper_SetParity(Uart_uartId_t id, Uart_parity_t parity)
{
    if ((id < UART_MAX) && (parity != UART_NOT_SUPPORTED))
    {
        uint32_t value = 0x00000000;
        value          = Uart[id]->CTRL;
        value &= (~CTL_CLEAR_PARITY_BITS_MASK);
        value |= parity;
        Uart[id]->CTRL = value;
        // Adjust data bits to consider parity bit
        Uart_Parity[id] = parity;
        UartWrapper_AdjustDataBits(id);
    }
}

/**
 * @brief Enables/Disables UART Clock
 * @param id UART ID
 * @param isEnabled Enable/Disable Clock
 */
void UartWrapper_EnableUartClock(Uart_uartId_t id, uint8_t isEnabled)
{
    if (id < UART_MAX)
    {
        if (isEnabled == ENABLE_UART_CLOCK)
        {
            CLOCK_EnableClock(UartClocks[id]);
        }
        else
        {
            CLOCK_DisableClock(UartClocks[id]);
        }
    }
}

/**
 * @brief Enables UART
 * @param id UART ID
 */
void UartWrapper_EnableUart(Uart_uartId_t id)
{
    if (id < UART_MAX)
    {
        // Enable RX and TX
        LPUART_EnableRx(Uart[id], ENABLE_UART);
        LPUART_EnableTx(Uart[id], ENABLE_UART);
    }
}

/**
 * @brief Disables UART
 * @param id UART ID
 */
void UartWrapper_DisableUart(Uart_uartId_t id)
{
    if (id < UART_MAX)
    {
        // Disable RX and TX
        LPUART_EnableRx(Uart[id], DISABLE_UART);
        LPUART_EnableTx(Uart[id], DISABLE_UART);
    }
}

/**
 * @brief Sends Data through UART
 * @param id UART ID
 * @param data Data to send
 */
void UartWrapper_Send(Uart_uartId_t id, uint8_t data)
{
    if (id < UART_MAX)
    {
        uint8_t value = 0x00;
        // Read the value of Data Register
        value = Uart[id]->DATA;
        // Get new value, clearing data positions and making sure no more than 8 bits
        // are used as data.
        value = ((value & ~UART_DATA_MASK) | (data & UART_DATA_MASK));
        /* This API can only ensure that the data is written into the data buffer but can't
        ensure all data in the data buffer are sent into the transmit shift buffer. */
        while (!(Uart[id]->STAT & LPUART_STAT_TDRE_MASK))
        {
        }
        Uart[id]->DATA = value;
    }
}

/**
 * @brief Receives Data through UART
 * @param id UART ID
 * @return Data read through UART
 */
uint8_t UartWrapper_Receive(Uart_uartId_t id)
{
    if (id < UART_MAX)
    {
        uint16_t value = 0x00;
        // Get just data bits
        value = (Uart[id]->DATA & UART_DATA_MASK);
        return value;
    }
    else
    {
        return 0;
    }
}
