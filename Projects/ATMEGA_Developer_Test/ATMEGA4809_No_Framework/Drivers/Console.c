/*
 * UART.c
 *
 * Created: 26/09/2020 12:34:19 p. m.
 *  Author: usuario
 */ 
#include "Console.h"


void consoleInit(void)
{
    PORTC.DIR &= ~PIN1_bm;
    PORTC.DIR |= PIN0_bm;
    
    USART1.BAUD = (uint16_t)UART1_BAUD_RATE(9600);

    USART1.CTRLB |= USART_RXEN_bm | USART_TXEN_bm;
}

char consoleReadChar(void)
{
    while (!(USART1.STATUS & USART_RXCIF_bm))
    {
        ;
    }
    return USART1.RXDATAL;
}


void consoleSendChar(char c)
{
    while (!(USART1.STATUS & USART_DREIF_bm))
    {
        ;    
    }
    USART1.TXDATAL = c;
}

void consoleSendString(char *str)
{
    for(size_t i = 0; i < strlen(str); i++)
    {
        consoleSendChar(str[i]);
    }
}

