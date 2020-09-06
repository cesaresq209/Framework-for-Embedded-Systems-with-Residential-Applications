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
// ################## Kamino generator v1.0.3: Generated code! ################
// ######## Do NOT modify code between this header and the footer below #######
{USER_BUTTON_PORT,
USER_BUTTON_PIN,
USER_BUTTON_MODE,
USER_BUTTON_ALT_MODE,
USER_BUTTON_OUT_TYPE,
USER_BUTTON_PULL,
USER_BUTTON_SPEED,
USER_BUTTON_INIT_OUT
},
{POT_PORT,
POT_PIN,
POT_MODE,
POT_ALT_MODE,
POT_OUT_TYPE,
POT_PULL,
POT_SPEED,
POT_INIT_OUT
},
{USER_LED_PORT,
USER_LED_PIN,
USER_LED_MODE,
USER_LED_ALT_MODE,
USER_LED_OUT_TYPE,
USER_LED_PULL,
USER_LED_SPEED,
USER_LED_INIT_OUT
},
{RX_PORT,
RX_PIN,
RX_MODE,
RX_ALT_MODE,
RX_OUT_TYPE,
RX_PULL,
RX_SPEED,
RX_INIT_OUT
},
{TX_PORT,
TX_PIN,
TX_MODE,
TX_ALT_MODE,
TX_OUT_TYPE,
TX_PULL,
TX_SPEED,
TX_INIT_OUT
},
// ################## Kamino generator v1.0.3: Generated code! ################
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
