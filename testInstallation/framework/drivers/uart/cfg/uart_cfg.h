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
FWK_UART_INCLUDES

/************************
 * Public Types         *
 ************************/
/**
 * @brief GPIO elements
 */
typedef enum
{
    FWK_UART_ELEMENTS
    UART_ELEMENTS_MAX
} Uart_elementsType;

/************************
 * Public Macros        *
 ************************/

/************************
 * Public Defines       *
 ************************/
FWK_UART_CFG_DEFINITIONS

FWK_UART_ELEMENTS_DEFINITIONS

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
