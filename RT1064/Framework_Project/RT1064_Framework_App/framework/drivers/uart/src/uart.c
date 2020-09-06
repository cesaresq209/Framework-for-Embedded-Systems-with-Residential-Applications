/**
 * @file uart.c
 * @author Cesar Rodriguez
 * @brief UART framework module
 */

/************************
 * Includes             *
 ************************/
#include "uart.h"

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
 * @brief Initialize UART from the dynamic element (uart_cfg)
 * @param cfgPtr UART Configuration Structure
 */
void Uart_InitDefaults(const Uart_cfg_t* cfgPtr)
{
    uint8_t uartNum;

    if (NULL != cfgPtr)
    {
        for (uartNum = 0; uartNum < UART_ELEMENTS_MAX; uartNum++)
        {
            UartWrapper_SetClock(cfgPtr[uartNum].ID, cfgPtr[uartNum].Clock);
            UartWrapper_SetPrescaler(cfgPtr[uartNum].ID, cfgPtr[uartNum].Prescaler);
            UartWrapper_EnableUartClock(cfgPtr[uartNum].ID, ENABLE_UART_CLOCK);
            UartWrapper_SetBaudRate(cfgPtr[uartNum].ID, cfgPtr[uartNum].Baud_Rate);
            UartWrapper_SetDataBits(cfgPtr[uartNum].ID, cfgPtr[uartNum].Data_Bits);
            UartWrapper_SetStopBits(cfgPtr[uartNum].ID, cfgPtr[uartNum].Stop_Bits);
            UartWrapper_SetParity(cfgPtr[uartNum].ID, cfgPtr[uartNum].Parity);
        }
    }
}

/**
 * @brief Sets UART Clock
 * @param id UART ID
 * @param clock UART Clock Source
 */
void Uart_SetClock(Uart_uartId_t id, Uart_clock_t clock)
{
    UartWrapper_SetClock(id, clock);
}

/**
 * @brief Sets Prescaler for UART Clock
 * @param id UART ID
 * @param prescaler Prescaler for UART Clock
 */
void Uart_SetPrescaler(Uart_uartId_t id, Uart_prescaler_t prescaler)
{
    UartWrapper_SetPrescaler(id, prescaler);
}

/**
 * @brief Sets UART Baud Rate
 * @param id UART ID
 * @param baud_rate UART´s Baud Rate
 */
void Uart_SetBaudRate(Uart_uartId_t id, Uart_baud_rate_t baud_rate)
{
    Uart_SetBaudRate(id, baud_rate);
}

/**
 * @brief Sets number of data bits for UART
 * @param id UART ID
 * @param data_bits Data Bits for UART
 */
void Uart_SetDataBits(Uart_uartId_t id, Uart_data_bits_t data_bits)
{
    UartWrapper_SetDataBits(id, data_bits);
}

/**
 * @brief Sets number of stop bits for UART
 * @param id UART ID
 * @param stop_bits Stop Bits for UART
 */
void Uart_SetStopBits(Uart_uartId_t id, Uart_stop_bits_t stop_bits)
{
    UartWrapper_SetStopBits(id, stop_bits);
}

/**
 * @brief Set UART´s Parity
 * @param id UART ID
 * @param parity UART´s parity
 */
void Uart_SetParity(Uart_uartId_t id, Uart_parity_t parity)
{
    UartWrapper_SetParity(id, parity);
}

/**
 * @brief Enables/Disables UART Clock
 * @param id UART ID
 * @param isEnabled Enable/Disable Clock
 */
void Uart_EnableUartClock(Uart_uartId_t id, uint8_t isEnabled)
{
    UartWrapper_EnableUartClock(id, isEnabled);
}

/**
 * @brief Enables UART
 * @param id UART ID
 */
void Uart_EnableUart(Uart_uartId_t id)
{
    UartWrapper_EnableUart(id);
}

/**
 * @brief Disables UART
 * @param id UART ID
 */
void Uart_DisableUart(Uart_uartId_t id)
{
    UartWrapper_DisableUart(id);
}

/**
 * @brief Sends Data through UART
 * @param id UART ID
 * @param data Data to send
 */
void Uart_Send(Uart_uartId_t id, uint16_t data)
{
    UartWrapper_Send(id, data);
}

/**
 * @brief Receives Data through UART
 * @param id UART ID
 * @return Data read through UART
 */
uint16_t Uart_Receive(Uart_uartId_t id)
{
    return UartWrapper_Receive(id);
}
