#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdio.h>

extern FILE uart_output;
extern FILE uart_input;

void    uart_putchar(uint8_t c, FILE *stream);
uint8_t uart_getchar(FILE *stream);

void    uart_init(void);
void    uart_init_1200(void);
void    uart_init_2400(void);
void    uart_init_4800(void);
void    uart_init_9600(void);
void    uart_init_19200(void);
void    uart_init_28400(void);
void    uart_init_57600(void);
void    uart_init_115200(void);

void    uart_set_baud(uint32_t);

#endif // UART_H_
