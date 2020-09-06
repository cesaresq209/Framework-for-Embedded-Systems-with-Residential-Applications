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
// ################## Kamino generator v1.1.0: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
#include "fsl_lpuart.h"
// ################## Kamino generator v1.1.0: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######

/************************
 * Public Types         *
 ************************/
/**
 * @brief GPIO elements
 */
typedef enum
{
    // ################## Kamino generator v1.1.0: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
APP_UART,
// ################## Kamino generator v1.1.0: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######
    UART_ELEMENTS_MAX
} Uart_elementsType;

/************************
 * Public Macros        *
 ************************/

/************************
 * Public Defines       *
 ************************/
// ################## Kamino generator v1.1.0: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######

// ################## Kamino generator v1.1.0: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######

// ################## Kamino generator v1.1.0: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
// APP_UART
#define APP_UART_NAME UART1
#define APP_UART_CLOCK INTERNAL_CLOCK_FOR_UART
#define APP_UART_PRESCALER DO_NOT_DIVIDE_UART_CLOCK
#define APP_UART_BAUD_RATE 9600
#define APP_UART_DATA_BITS UART_8_DATA_BITS
#define APP_UART_STOP_BITS UART_1_STOP_BIT
#define APP_UART_PARITY UART_NO_PARITY

// ################## Kamino generator v1.1.0: Generated code! ################
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
