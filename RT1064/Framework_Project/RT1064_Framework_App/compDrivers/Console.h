/*
 * UART.h
 *
 * Created: 26/09/2020 12:36:27 p. m.
 *  Author: usuario
 */ 


#ifndef UART_H_
#define UART_H_

#include <stdio.h>
#include <string.h>
#include "uart.h"

/* Initialization function for console*/
void consoleInit();

/* Read a char from the serial port
* @return Read value
*/
char consoleReadChar();

/* send a char trough the serial port
* @param char to send
*/
void consoleSendChar(char c);

/* send a char trough the serial port
* @param string to send
*/
void consoleSendString(char *str);



#endif /* UART_H_ */
