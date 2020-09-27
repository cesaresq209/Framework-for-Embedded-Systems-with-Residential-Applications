/**
 * @file gpio_cfg.h
 * @author Miguel Diaz
 * @brief GPIO framework configuration header
 */

/************************
 * Guard                *
 ************************/
#ifndef _GPIO_CFG_H_
#define _GPIO_CFG_H_

/************************
 * Includes             *
 ************************/
// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
#include "port.h"
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
LED_Port,
UART_TX_Port,
UART_RX_Port,
POT_Port,
// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######
    GPIO_ELEMENTS_MAX
} Gpio_elementsType;

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
// LED_Port
#define LED_Port_PORT PORT_B
#define LED_Port_PIN PIN_5
#define LED_Port_MODE MODE_OUTPUT
#define LED_Port_ALT_MODE ALT_MODE_UART
#define LED_Port_OUT_TYPE OTYPE_PUSH_PULL
#define LED_Port_PULL PULL_NOT_AVAILABLE
#define LED_Port_SPEED SPEED_FAST
#define LED_Port_INIT_OUT LOW

// UART_TX_Port
#define UART_TX_Port_PORT PORT_C
#define UART_TX_Port_PIN PIN_0
#define UART_TX_Port_MODE MODE_ALTERNATE_FUNCTION
#define UART_TX_Port_ALT_MODE ALT_MODE_UART
#define UART_TX_Port_OUT_TYPE OTYPE_PUSH_PULL
#define UART_TX_Port_PULL PULL_NOT_AVAILABLE
#define UART_TX_Port_SPEED SPEED_FAST
#define UART_TX_Port_INIT_OUT LOW

// UART_RX_Port
#define UART_RX_Port_PORT PORT_C
#define UART_RX_Port_PIN PIN_1
#define UART_RX_Port_MODE MODE_ALTERNATE_FUNCTION
#define UART_RX_Port_ALT_MODE ALT_MODE_UART
#define UART_RX_Port_OUT_TYPE OTYPE_PUSH_PULL
#define UART_RX_Port_PULL PULL_NOT_AVAILABLE
#define UART_RX_Port_SPEED SPEED_FAST
#define UART_RX_Port_INIT_OUT LOW

// POT_Port
#define POT_Port_PORT PORT_D
#define POT_Port_PIN PIN_0
#define POT_Port_MODE MODE_ALTERNATE_FUNCTION
#define POT_Port_ALT_MODE ALT_MODE_ANALOG
#define POT_Port_OUT_TYPE OTYPE_PUSH_PULL
#define POT_Port_PULL PULL_NOT_AVAILABLE
#define POT_Port_SPEED SPEED_FAST
#define POT_Port_INIT_OUT LOW

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

#endif /* _GPIO_CFG_H_ */
