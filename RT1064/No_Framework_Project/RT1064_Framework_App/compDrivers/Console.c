/*
 * UART.c
 *
 * Created: 26/09/2020 12:34:19 p. m.
 *  Author: usuario
 */ 
#include "Console.h"


void consoleInit(void)
{
	lpuart_config_t config;

	  IOMUXC_SetPinMux(
	      IOMUXC_GPIO_AD_B0_12_LPUART1_TX,        /* GPIO_AD_B0_12 is configured as LPUART1_TX */
	      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
	  IOMUXC_SetPinMux(
	      IOMUXC_GPIO_AD_B0_13_LPUART1_RX,        /* GPIO_AD_B0_13 is configured as LPUART1_RX */
	      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
	  IOMUXC_SetPinConfig(
	      IOMUXC_GPIO_AD_B0_12_LPUART1_TX,        /* GPIO_AD_B0_12 PAD functional properties : */
	      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
	                                                 Drive Strength Field: R0/6
	                                                 Speed Field: medium(100MHz)
	                                                 Open Drain Enable Field: Open Drain Disabled
	                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
	                                                 Pull / Keep Select Field: Keeper
	                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
	                                                 Hyst. Enable Field: Hysteresis Disabled */
	  IOMUXC_SetPinConfig(
	      IOMUXC_GPIO_AD_B0_13_LPUART1_RX,        /* GPIO_AD_B0_13 PAD functional properties : */
	      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
	                                                 Drive Strength Field: R0/6
	                                                 Speed Field: medium(100MHz)
	                                                 Open Drain Enable Field: Open Drain Disabled
	                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
	                                                 Pull / Keep Select Field: Keeper
	                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
	                                                 Hyst. Enable Field: Hysteresis Disabled */

  LPUART_GetDefaultConfig(&config);
  config.enableTx     = true;
  config.enableRx     = true;
  LPUART_Init(CONSOLE_UART, &config, CONSOLE_UART_CLK_FREQ);
}

char consoleReadChar(void)
{
	uint8_t ch;
	LPUART_ReadBlocking(CONSOLE_UART, &ch, 1);
	return (char)ch;
}


void consoleSendChar(char c)
{
	uint8_t ch = (uint8_t)c;
	LPUART_WriteBlocking(CONSOLE_UART, &ch, 1);
}

void consoleSendString(char *str)
{
	for(size_t i = 0; i < strlen(str); i++)
	{
		uint8_t ch = (uint8_t)str[i];
		LPUART_WriteBlocking(CONSOLE_UART, &ch, 1);
	}
}

