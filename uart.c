#include <avr/io.h>
#include <stdio.h>

#ifndef BAUD
	#define BAUD 19200
#endif
#include <util/setbaud.h>

#include "uart.h"

FILE uart_input  = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);
FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);


//----------------------------------------------------------------------------------------------------
// receive char from uart
//----------------------------------------------------------------------------------------------------
uint8_t uart_getchar(__attribute__ ((unused))FILE *stream)
	{
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
	}

//----------------------------------------------------------------------------------------------------
// put character to uart
//----------------------------------------------------------------------------------------------------
void uart_putchar(uint8_t c, __attribute__ ((unused))FILE *stream)
	{
	if (c == '\n')
		uart_putchar('\r', stream);
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	}

//----------------------------------------------------------------------------------------------------
// initialize uart
//----------------------------------------------------------------------------------------------------
void uart_init(void)
	{
	UCSR0B = (1 << RXEN0)  | (1 << TXEN0);  // Enable RX and TX
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data

	// setup stdio
	stdin  = &uart_input;
	stdout = &uart_output;
	stderr = &uart_output;
	}

//----------------------------------------------------------------------------------------------------
// init uart baud to BAUD
//----------------------------------------------------------------------------------------------------
void uart_init_baud(void)
	{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
		UCSR0A |= (1 << U2X0);
	#else
		UCSR0A &= (uint8_t)~(1 << U2X0);
	#endif

	uart_init();
	}
