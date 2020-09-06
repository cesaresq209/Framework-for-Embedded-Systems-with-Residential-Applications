/**
 * @file uart.h
 * @author Cesar Rodriguez
 * @brief UART framework module header
 */

/************************
 * Guard                *
 ************************/
#ifndef _UART_H_
#define _UART_H_

/************************
 * Includes             *
 ************************/
#include "frameworkCommon.h"
#include "uart_cfg.h"
#include "uart_wrapper.h"

/************************
 * Public Types         *
 ************************/

/**
 * @brief UART configuration structure
 */
typedef struct
{
    Uart_uartId_t    ID;
    Uart_clock_t     Clock;
    Uart_prescaler_t Prescaler;
    Uart_baud_rate_t Baud_Rate;
    Uart_data_bits_t Data_Bits;
    Uart_stop_bits_t Stop_Bits;
    Uart_parity_t    Parity;
} Uart_cfg_t;

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
extern const Uart_cfg_t Uart_Cfg[UART_ELEMENTS_MAX];

/************************
 * Public Functions     *
 ************************/
void     Uart_InitDefaults(const Uart_cfg_t* cfgPtr);
void     Uart_SetClock(Uart_uartId_t id, Uart_clock_t clock);
void     Uart_SetPrescaler(Uart_uartId_t id, Uart_prescaler_t prescaler);
void     Uart_SetBaudRate(Uart_uartId_t id, Uart_baud_rate_t baud_rate);
void     Uart_SetDataBits(Uart_uartId_t id, Uart_data_bits_t data_bits);
void     Uart_SetStopBits(Uart_uartId_t id, Uart_stop_bits_t stop_bits);
void     Uart_SetParity(Uart_uartId_t id, Uart_parity_t parity);
void     Uart_EnableUartClock(Uart_uartId_t id, uint8_t isEnabled);
void     Uart_EnableUart(Uart_uartId_t id);
void     Uart_DisableUart(Uart_uartId_t id);
void     Uart_Send(Uart_uartId_t id, uint16_t data);
uint16_t Uart_Receive(Uart_uartId_t id);

#endif /* _UART_H_ */
