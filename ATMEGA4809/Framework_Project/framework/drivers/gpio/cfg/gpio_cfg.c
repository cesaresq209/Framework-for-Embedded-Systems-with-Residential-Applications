/**
 * @file gpio_cfg.c
 * @author Miguel Diaz
 * @brief GPIO gramework configuration
 */

/************************
 * Includes             *
 ************************/
#include "gpio.h"

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
const Gpio_cfg_t Gpio_Cfg[GPIO_ELEMENTS_MAX] = {
// ################## Kamino generator v1.2.5: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
{LED_Port_PORT,
LED_Port_PIN,
LED_Port_MODE,
LED_Port_ALT_MODE,
LED_Port_OUT_TYPE,
LED_Port_PULL,
LED_Port_SPEED,
LED_Port_INIT_OUT
},
{UART_TX_Port_PORT,
UART_TX_Port_PIN,
UART_TX_Port_MODE,
UART_TX_Port_ALT_MODE,
UART_TX_Port_OUT_TYPE,
UART_TX_Port_PULL,
UART_TX_Port_SPEED,
UART_TX_Port_INIT_OUT
},
{UART_RX_Port_PORT,
UART_RX_Port_PIN,
UART_RX_Port_MODE,
UART_RX_Port_ALT_MODE,
UART_RX_Port_OUT_TYPE,
UART_RX_Port_PULL,
UART_RX_Port_SPEED,
UART_RX_Port_INIT_OUT
},
{POT_Port_PORT,
POT_Port_PIN,
POT_Port_MODE,
POT_Port_ALT_MODE,
POT_Port_OUT_TYPE,
POT_Port_PULL,
POT_Port_SPEED,
POT_Port_INIT_OUT
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
