/*
 * LED.c
 *
 * Created: 26/09/2020 12:33:48 p. m.
 *  Author: brios
 */ 
#include "LED.h"

void initLED()
{
	CLOCK_EnableClock(kCLOCK_Iomuxc);           /* iomuxc clock (iomuxc_clk_enable): 0x03U */

	  /* GPIO configuration of USER_LED on GPIO_AD_B0_09 (pin F14) */
	  gpio_pin_config_t USER_LED_config = {
	      .direction = kGPIO_DigitalOutput,
	      .outputLogic = 0U,
	      .interruptMode = kGPIO_NoIntmode
	  };
	  /* Initializing GPIO functionality on GPIO1 Pin 9 */
	  GPIO_PinInit(LED_PIN_GPIO, 9U, &USER_LED_config);

	  IOMUXC_SetPinMux(
	        IOMUXC_GPIO_AD_B0_09_GPIO1_IO09,        /* GPIO_AD_B0_09 is configured as GPIO1_IO09 */
	        0U);

	  IOMUXC_SetPinConfig(
	        IOMUXC_GPIO_AD_B0_09_GPIO1_IO09,        /* GPIO_AD_B0_09 PAD functional properties : */
	        0x10B0U);                               /* Slew Rate Field: Slow Slew Rate
	                                                   Drive Strength Field: R0/6
	                                                   Speed Field: medium(100MHz)
	                                                   Open Drain Enable Field: Open Drain Disabled
	                                                   Pull / Keep Enable Field: Pull/Keeper Enabled
	                                                   Pull / Keep Select Field: Keeper
	                                                   Pull Up / Down Config. Field: 100K Ohm Pull Down
	                                                   Hyst. Enable Field: Hysteresis Disabled */

}

void setLED(int newState)
{
	if (newState)
	{
		GPIO_PinWrite(LED_PIN_GPIO, LED_PIN_PIN, 0U);
	}
	else
	{
		GPIO_PinWrite(LED_PIN_GPIO, LED_PIN_PIN, 1U);
	}

}
