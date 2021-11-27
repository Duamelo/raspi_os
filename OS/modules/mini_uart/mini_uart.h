#ifndef	_MINI_UART_H
#define	_MINI_UART_H

#include "peripherals/mini_uart.h"
#include "../gpio/gpio.h"
#include "utils.h"


void uart_init ( void );
char uart_recv ( void );
void uart_send ( char c );
void putc ( void* p, char c );

#endif  /*_MINI_UART_H */
