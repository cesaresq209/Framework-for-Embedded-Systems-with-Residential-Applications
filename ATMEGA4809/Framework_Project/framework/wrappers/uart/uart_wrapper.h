/**
 * @file uart_wrapper.h
 * @author Cesar Rodriguez
 * @brief UART framework module wrapper header
 */

/************************
 * Guard                *
 ************************/
#ifndef _UART_WRAPPER_H_
#define _UART_WRAPPER_H_

/************************
 * Includes             *
 ************************/
#include "usart_basic.h"
#include "MCU_Helper.h"
/************************
 * Public Types         *
 ************************/
/**
 * @brief UART IDs
 */
typedef enum
{
    UART0,
    UART1,
    UART2,
    UART3,
    UART_MAX
} Uart_uartId_t;

/**
 * @brief UART data type
 */
typedef uint8_t Uart_t;

/**
 * @brief UART clock source data type
 */
typedef uint8_t Uart_clock_t;

/**
 * @brief UART prescaler data type
 */
typedef uint8_t Uart_prescaler_t;

/**
 * @brief UART baud rate data type
 */
typedef uint32_t Uart_baud_rate_t;

/**
 * @brief UART data bits data type
 */
typedef USART_CHSIZE_t Uart_data_bits_t;

/**
 * @brief UART stop bits data type
 */
typedef USART_SBMODE_t Uart_stop_bits_t;

/**
 * @brief UART parity data type
 */
typedef USART_PMODE_t Uart_parity_t;

/************************
 * Public Macros        *
 ************************/

/************************
 * Public Defines       *
 ************************/
// Dummy value used for unsuported definitions
#define UART_NOT_SUPPORTED (uint8_t)0x55

// Enable/Disable Clock
#define ENABLE_UART_CLOCK  (uint8_t)1
#define DISABLE_UART_CLOCK (uint8_t)0

// Clock Source
#define INTERNAL_CLOCK_FOR_UART   UART_NOT_SUPPORTED
#define PERIPHERAL_CLOCK_FOR_UART UART_NOT_SUPPORTED
#define UART_CLOCK_FOR_UART       UART_NOT_SUPPORTED
#define OTHER_CLOCK_FOR_UART      UART_NOT_SUPPORTED

// Clock Prescaler
#define DO_NOT_DIVIDE_UART_CLOCK   UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_2     UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_4     UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_8     UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_16    UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_32    UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_64    UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_128   UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_256   UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_512   UART_NOT_SUPPORTED
#define DIVIDE_UART_CLOCK_BY_OTHER UART_NOT_SUPPORTED

// Data Bits
#define UART_5_DATA_BITS  USART_CHSIZE_5BIT_gc
#define UART_6_DATA_BITS  USART_CHSIZE_6BIT_gc
#define UART_7_DATA_BITS  USART_CHSIZE_7BIT_gc
#define UART_8_DATA_BITS  USART_CHSIZE_8BIT_gc
#define UART_9_DATA_BITS  USART_CHSIZE_9BITL_gc
#define UART_10_DATA_BITS UART_NOT_SUPPORTED

// Stop Bits
#define UART_1_STOP_BIT  USART_SBMODE_1BIT_gc
#define UART_2_STOP_BITS USART_SBMODE_2BIT_gc

// Parity
#define UART_EVEN_PARITY USART_PMODE_EVEN_gc
#define UART_ODD_PARITY  USART_PMODE_ODD_gc
#define UART_NO_PARITY   USART_PMODE_DISABLED_gc

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
void     UartWrapper_SetClock(Uart_uartId_t id, Uart_clock_t clock);
void     UartWrapper_SetPrescaler(Uart_uartId_t id, Uart_prescaler_t prescaler);
void     UartWrapper_SetBaudRate(Uart_uartId_t id, Uart_baud_rate_t baud_rate);
void     UartWrapper_SetDataBits(Uart_uartId_t id, Uart_data_bits_t data_bits);
void     UartWrapper_SetStopBits(Uart_uartId_t id, Uart_stop_bits_t stop_bits);
void     UartWrapper_SetParity(Uart_uartId_t id, Uart_parity_t parity);
void     UartWrapper_EnableUartClock(Uart_uartId_t id, uint8_t isEnabled);
void     UartWrapper_EnableUart(Uart_uartId_t id);
void     UartWrapper_DisableUart(Uart_uartId_t id);
void     UartWrapper_Send(Uart_uartId_t id, uint16_t data);
uint16_t UartWrapper_Receive(Uart_uartId_t id);

#endif /* _UART_WRAPPER_H_ */