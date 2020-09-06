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
// ################## Kamino generator v1.0.3: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
#include "port.h"
// ################## Kamino generator v1.0.3: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######

/************************
 * Public Types         *
 ************************/
/**
 * @brief GPIO elements
 */
typedef enum
{
    // ################## Kamino generator v1.0.3: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
USER_BUTTON,
USER_LED,
POT,
RX,
TX,
// ################## Kamino generator v1.0.3: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######
    GPIO_ELEMENTS_MAX
} Gpio_elementsType;

/************************
 * Public Macros        *
 ************************/

/************************
 * Public Defines       *
 ************************/
// ################## Kamino generator v1.0.3: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######

// ################## Kamino generator v1.0.3: Generated code! ################
// ######## Do NOT modify code between this footer and the header above #######

// ################## Kamino generator v1.0.3: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
// USER_BUTTON
#define USER_BUTTON_PORT PORT_B
#define USER_BUTTON_PIN PIN_2
#define USER_BUTTON_MODE MODE_INPUT
#define USER_BUTTON_ALT_MODE ALT_MODE_NONE
#define USER_BUTTON_OUT_TYPE OTYPE_PUSH_PULL
#define USER_BUTTON_PULL PULL_UP
#define USER_BUTTON_SPEED SPEED_FAST
#define USER_BUTTON_INIT_OUT LOW

// USER_LED
#define USER_LED_PORT PORT_B
#define USER_LED_PIN PIN_5
#define USER_LED_MODE MODE_OUTPUT
#define USER_LED_ALT_MODE ALT_MODE_NONE
#define USER_LED_OUT_TYPE OTYPE_PUSH_PULL
#define USER_LED_PULL PULL_NOT_AVAILABLE
#define USER_LED_SPEED SPEED_FAST
#define USER_LED_INIT_OUT LOW

// POT
#define POT_PORT PORT_D
#define POT_PIN PIN_0
#define POT_MODE MODE_ALTERNATE_FUNCTION
#define POT_ALT_MODE ALT_MODE_ANALOG
#define POT_OUT_TYPE OTYPE_PUSH_PULL
#define POT_PULL PULL_NOT_AVAILABLE
#define POT_SPEED SPEED_FAST
#define POT_INIT_OUT LOW

// UART RX
#define RX_PORT PORT_C
#define RX_PIN PIN_1
#define RX_MODE MODE_ALTERNATE_FUNCTION
#define RX_ALT_MODE ALT_MODE_UART
#define RX_OUT_TYPE OTYPE_PUSH_PULL
#define RX_PULL PULL_NOT_AVAILABLE
#define RX_SPEED SPEED_FAST
#define RX_INIT_OUT LOW

// UART TX
#define TX_PORT PORT_C
#define TX_PIN PIN_0
#define TX_MODE MODE_ALTERNATE_FUNCTION
#define TX_ALT_MODE ALT_MODE_UART
#define TX_OUT_TYPE OTYPE_PUSH_PULL
#define TX_PULL PULL_NOT_AVAILABLE
#define TX_SPEED SPEED_FAST
#define TX_INIT_OUT LOW

// ################## Kamino generator v1.0.3: Generated code! ################
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
