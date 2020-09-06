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
// ################## Kamino generator v1.1.0: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
{APP_UART_NAME,
APP_UART_CLOCK,
APP_UART_PRESCALER,
APP_UART_BAUD_RATE,
APP_UART_DATA_BITS,
APP_UART_STOP_BITS,
APP_UART_PARITY,
}
// ################## Kamino generator v1.1.0: Generated code! ################
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
