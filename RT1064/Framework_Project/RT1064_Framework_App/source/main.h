/******************************************************************************
 *. Copyright 2020 Cesar Rodriguez, All Rights Reserved
 *.=============================================================================
 *. Main application header
 *.=============================================================================
 *. FILE: main.h
 *.
 *. DESCRIPTION:
 *. This file
 *.
 *. SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" FOR THE PURPOSES OF THE
 *. PROVIDED TRAINING CLASS AND IT IS NOT INTENDED AS PRODUCTION CODE AND WITHOUT
 *. WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION,
 *. ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A
 *. PARTICULAR PURPOSE. IN NO EVENT SHALL SALVADOR ALMANZA OR ITS LICENSORS BE LIABLE OR
 *. OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH
 *. OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES
 *. OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT,
 *. PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 *. PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD
 *. PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR
 *. COSTS.
 *.
 \*****************************************************************************/

/*-------------------- Guard to prevent recursive inclusion -----------------*/
#ifndef _MAIN_H_
#define _MAIN_H_

/***********************
 * Includes             *
 ***********************/
#include "board.h"
#include "peripherals.h"

/***********************
 * Public Types        *
 ***********************/
typedef enum
{
    HW_INIT,
    WAIT,
    MEASURE_VOLTAGE,
    UPDATE_LED,
    STATES_NUMBER
} States_t;

/***********************
 * Public Macros        *
 ***********************/
// Initialize clocks and HAL
#define HWInit()          \
    BOARD_BootClockRUN(); \
    SystemCoreClockUpdate();

#define BUTTON_PRESSED     LOW
#define BUTTON_NOT_PRESSED HIGH

#define LED_ON    LOW
#define LED_OFF   HIGH
#define ADC_STEPS 4095
/***********************
 * Public Defines       *
 ***********************/

/***********************
 * Public Constants     *
 ***********************/

/***********************
 * Public Calibrations  *
 ***********************/

/***********************
 * Public Variables     *
 ***********************/

/***********************
 * Public Functions     *
 ***********************/

#endif /* _MAIN_H_ */

/******************************************************************************
 * Revision Log:
 *.=============================================================================
 * Created By:   Revision  Date:       Description:
 *.-----------------------------------------------------------------------------
 * Cesar Rodriguez   1.0       2020-03-29 Initial Revision.
 \*****************************************************************************/

/******************************* END OF FILE *********************************/
