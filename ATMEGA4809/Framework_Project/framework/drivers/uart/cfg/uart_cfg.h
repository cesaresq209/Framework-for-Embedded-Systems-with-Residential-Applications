/**
 * @file uart_cfg.h
 * @author Cesar Rodriguez
 * @brief UART framework configuration header
 */

/************************
 * Guard                *
 ************************/
#ifndef _UART_CFG_H_
#define _UART_CFG_H_

/************************
 * Includes             *
 ************************/
// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
#include "usart_basic.h"
// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######

/************************
 * Public Types         *
 ************************/
/**
 * @brief GPIO elements
 */
typedef enum
{
    // ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
Console_UART,
// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######
    UART_ELEMENTS_MAX
} Uart_elementsType;

/************************
 * Public Macros        *
 ************************/

/************************
 * Public Defines       *
 ************************/
// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######

// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######

// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
// Console_UART
#define Console_UART_NAME UART1
#define Console_UART_CLOCK UART_NOT_SUPPORTED
#define Console_UART_PRESCALER UART_NOT_SUPPORTED
#define Console_UART_BAUD_RATE 9600
#define Console_UART_DATA_BITS UART_8_DATA_BITS
#define Console_UART_STOP_BITS UART_1_STOP_BIT
#define Console_UART_PARITY UART_NO_PARITY

// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######

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

#endif /* _UART_CFG_H_ */
