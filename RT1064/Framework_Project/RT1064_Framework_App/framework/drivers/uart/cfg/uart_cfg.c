/**
 * @file uart_cfg.c
 * @author Cesar Rodriguez
 * @brief UART Framework Configuration
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

/**
 * @brief GPIO initial configuration structures array
 */
const Uart_cfg_t Uart_Cfg[UART_ELEMENTS_MAX] = {
// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
{Console_NAME,
Console_CLOCK,
Console_PRESCALER,
Console_BAUD_RATE,
Console_DATA_BITS,
Console_STOP_BITS,
Console_PARITY,
}
// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######
};
/************************
 * File Scope Variables *
 ************************/

/************************
 * Function Prototypes  *
 ************************/

/************************
 * Function Definitions *
 ************************/
