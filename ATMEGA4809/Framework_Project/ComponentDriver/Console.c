/*
 * Console.c
 *
 * Created: 26/09/2020 12:34:19 p. m.
 *  Author: Brios
 */ 
#include "Console.h"


void consoleInit(void)
{
	Uart_InitDefaults(Uart_Cfg);
	/*Enabling UART1*/
	Uart_EnableUart(Console_UART_NAME);
}

char consoleReadChar(void)
{
    return (char) Uart_Receive(Console_UART_NAME);
}


void consoleSendChar(char c)
{
    Uart_Send(Console_UART_NAME, (uint16_t) c);
}

void consoleSendString(char *str)
{
    for(size_t i = 0; i < strlen(str); i++)
    {
        consoleSendChar(str[i]);
    }
}

