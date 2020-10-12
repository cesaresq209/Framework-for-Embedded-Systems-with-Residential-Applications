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
#include "fsl_lpuart.h"
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
Console,
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
// Console
#define Console_NAME UART1
#define Console_CLOCK UART_NOT_SUPPORTED
#define Console_PRESCALER UART_NOT_SUPPORTED
#define Console_BAUD_RATE 115200
#define Console_DATA_BITS UART_8_DATA_BITS
#define Console_STOP_BITS UART_1_STOP_BIT
#define Console_PARITY UART_NO_PARITY

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
