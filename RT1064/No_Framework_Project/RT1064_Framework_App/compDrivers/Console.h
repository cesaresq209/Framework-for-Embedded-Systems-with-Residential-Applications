/*
 * UART.h
 *
 * Created: 26/09/2020 12:36:27 p. m.
 *  Author: usuario
 */ 

#include "fsl_lpuart.h"
#include "fsl_gpio.h"
#include "board.h"
#include "fsl_iomuxc.h"

#ifndef UART_H_
#define UART_H_
#define CONSOLE_UART_BAUDRATE (115200U)
#define CONSOLE_UART          LPUART1
#define CONSOLE_UART_CLK_FREQ BOARD_DebugConsoleSrcFreq()

void consoleInit();

char consoleReadChar();
void consoleSendChar(char c);
void consoleSendString(char *str);



#endif /* UART_H_ */
