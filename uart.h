#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdio.h>

extern FILE uart_output;
extern FILE uart_input;

// functions

// uart.c
void    uart_putchar(uint8_t c, FILE *stream);
uint8_t uart_getchar(FILE *stream);
void    uart_init(void);
void    uart_init_baud(void);

// uart_baud.c
void    uart_set_baud(uint32_t);

#endif // UART_H_
