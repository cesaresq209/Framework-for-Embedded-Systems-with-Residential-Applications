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
#define GET_BAUD_RATE       ((float)(3333333.33333 * 64 / (16 * (float)BAUD_RATE)) + 0.5)
#define UART_DATA_BITS_MASK (uint8_t)0x03
#define UART_STOP_BITS_MASK (uint8_t)0x08
#define UART_PARITY_MASK    (uint8_t)0x30
#define UART_9_BIT_MASK     (uint8_t)0x01
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
 * @brief Sets UART Clock
 * @param id UART ID
 * @param clock UART Clock Source
 * @note The UART of this MCU can only be driven by the main clock
 */
void UartWrapper_SetClock(Uart_uartId_t id, Uart_clock_t clock)
{
    // The UART of this MCU can only be driven by the main clock
}

/**
 * @brief Sets Prescaler for UART Clock
 * @param id UART ID
 * @param prescaler Prescaler for UART Clock
 * @note This MCU can´t apply a prescaler to the UART Clock source
 */
void UartWrapper_SetPrescaler(Uart_uartId_t id, Uart_prescaler_t prescaler)
{
    // This MCU can´t apply a prescaler to the UART Clock source
}

/**
 * @brief Sets UART Baud Rate
 * @param id UART ID
 * @param baud_rate UART´s Baud Rate
 */
void UartWrapper_SetBaudRate(Uart_uartId_t id, Uart_baud_rate_t baud_rate)
{
    /*
    UART0 base address is 0x0800
    UART1 base address is 0x0820
    UART2 base address is 0x0840
    UART3 base address is 0x0860
    */
    if (id < UART_MAX)
    {
        USART_t* uartAddress;
        uint16_t value;
        if (id < UART_MAX)
        {
            // Calculate correct UART Address
            uartAddress = (USART_t*)(0x0800 + (id * 0x20));
            value = (uint16_t)((float)(GetMainClockFrequency() * 64 / (16 * (float)baud_rate)) + 0.5);
            uartAddress->BAUD = value;
        }
    }
}

/**
 * @brief Sets number of data bits for UART
 * @param id UART ID
 * @param data_bits Data Bits for UART
 */
void UartWrapper_SetDataBits(Uart_uartId_t id, Uart_data_bits_t data_bits)
{
    /*
    UART0 base address is 0x0800
    UART1 base address is 0x0820
    UART2 base address is 0x0840
    UART3 base address is 0x0860
    */
    if ((id < UART_MAX) && (data_bits != UART_NOT_SUPPORTED))
    {
        USART_t* uartAddress;
        uint8_t  value;
        // Calculate correct UART Address
        uartAddress = (USART_t*)(0x0800 + (id * 0x20));
        value       = uartAddress->CTRLC;
        value &= ~(UART_DATA_BITS_MASK);
        value |= (data_bits & UART_DATA_BITS_MASK);
        uartAddress->CTRLC = value;
        // Update Data Bits array for other functions
        Uart_Data_Bits[id] = data_bits;
    }
}

/**
 * @brief Sets number of stop bits for UART
 * @param id UART ID
 * @param stop_bits Stop Bits for UART
 */
void UartWrapper_SetStopBits(Uart_uartId_t id, Uart_stop_bits_t stop_bits)
{
    /*
    UART0 base address is 0x0800
    UART1 base address is 0x0820
    UART2 base address is 0x0840
    UART3 base address is 0x0860
    */
    if ((id < UART_MAX) && (stop_bits != UART_NOT_SUPPORTED))
    {
        USART_t* uartAddress;
        uint8_t  value;
        if ((id < UART_MAX) && (stop_bits != UART_NOT_SUPPORTED))
        {
            // Calculate correct UART Address
            uartAddress = (USART_t*)(0x0800 + (id * 0x20));
            value       = uartAddress->CTRLC;
            value &= ~(UART_STOP_BITS_MASK);
            value |= (stop_bits & UART_STOP_BITS_MASK);
            uartAddress->CTRLC = value;
        }
    }
}

/**
 * @brief Set UART´s Parity
 * @param id UART ID
 * @param parity UART´s parity
 */
void UartWrapper_SetParity(Uart_uartId_t id, Uart_parity_t parity)
{
    /*
    UART0 base address is 0x0800
    UART1 base address is 0x0820
    UART2 base address is 0x0840
    UART3 base address is 0x0860
    */
    if ((id < UART_MAX) && (parity != UART_NOT_SUPPORTED))
    {
        USART_t* uartAddress;
        uint8_t  value;
        if ((id < UART_MAX) && (parity != UART_NOT_SUPPORTED))
        {
            // Calculate correct UART Address
            uartAddress = (USART_t*)(0x0800 + (id * 0x20));
            value       = uartAddress->CTRLC;
            value &= ~(UART_PARITY_MASK);
            value |= (parity & UART_PARITY_MASK);
            uartAddress->CTRLC = value;
        }
    }
}

/**
 * @brief Enables/Disables UART Clock
 * @param id UART ID
 * @param isEnabled Enable/Disable Clock
 * @note UART Clock can´t be disabled, UART Module is disabled by disabling TX and RX
 */
void UartWrapper_EnableUartClock(Uart_uartId_t id, uint8_t isEnabled)
{
    // UART Clock can´t be disabled, UART Module is disabled by disabling TX and RX
}

/**
 * @brief Enables UART
 * @param id UART ID
 */
void UartWrapper_EnableUart(Uart_uartId_t id)
{
    /*
    UART0 base address is 0x0800
    UART1 base address is 0x0820
    UART2 base address is 0x0840
    UART3 base address is 0x0860
    */
    if ((id < UART_MAX))
    {
        USART_t* uartAddress;
        if (id < UART_MAX)
        {
            // Calculate correct UART Address
            uartAddress = (USART_t*)(0x0800 + (id * 0x20));
            // Enable Transmitter and Receiver
            uartAddress->CTRLB |= USART_RXEN_bm | USART_TXEN_bm;
        }
    }
}

/**
 * @brief Disables UART
 * @param id UART ID
 */
void UartWrapper_DisableUart(Uart_uartId_t id)
{
    /*
    UART0 base address is 0x0800
    UART1 base address is 0x0820
    UART2 base address is 0x0840
    UART3 base address is 0x0860
    */
    if ((id < UART_MAX))
    {
        USART_t* uartAddress;
        if (id < UART_MAX)
        {
            // Calculate correct UART Address
            uartAddress = (USART_t*)(0x0800 + (id * 0x20));
            // Enable Transmitter and Receiver
            uartAddress->CTRLB &= ~(USART_RXEN_bm | USART_TXEN_bm);
        }
    }
}

/**
 * @brief Sends Data through UART
 * @param id UART ID
 * @param data Data to send
 */
void UartWrapper_Send(Uart_uartId_t id, uint16_t data)
{
    /*
    UART0 base address is 0x0800
    UART1 base address is 0x0820
    UART2 base address is 0x0840
    UART3 base address is 0x0860
    */
    if ((id < UART_MAX))
    {
        USART_t* uartAddress;
        if (id < UART_MAX)
        {
            // Calculate correct UART Address
            uartAddress = (USART_t*)(0x0800 + (id * 0x20));
            // Check if there is unread data
            while (!(uartAddress->STATUS & USART_DREIF_bm))
                ;
            uartAddress->TXDATAL = (data & 0xFF);
            // If we are using 9 bits, attach extra bit
            if (Uart_Data_Bits[id] == UART_9_DATA_BITS)
            {
                uartAddress->TXDATAH = ((data >> 7) & UART_9_BIT_MASK);
            }
        }
    }
}

/**
 * @brief Receives Data through UART
 * @param id UART ID
 * @return Data read through UART
 */
uint16_t UartWrapper_Receive(Uart_uartId_t id)
{
    /*
    UART0 base address is 0x0800
    UART1 base address is 0x0820
    UART2 base address is 0x0840
    UART3 base address is 0x0860
    */
    if ((id < UART_MAX))
    {
        USART_t* uartAddress;
        uint16_t value = 0x00;
        if (id < UART_MAX)
        {
            // Calculate correct UART Address
            uartAddress = (USART_t*)(0x0800 + (id * 0x20));
            // Check if there is unread data
            while (!(uartAddress->STATUS & USART_RXCIF_bm))
                ;
            value = uartAddress->RXDATAL;
            // If we are using 9 bits, attach extra bit to value
            if (Uart_Data_Bits[id] == UART_9_DATA_BITS)
            {
                value |= (uartAddress->RXDATAH & UART_9_BIT_MASK);
            }
        }
        return value;
    }
    else
    {
        return 0;
    }
}