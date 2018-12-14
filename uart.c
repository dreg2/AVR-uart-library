#include <avr/io.h>
#include <stdio.h>

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
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); // 8-bit data
	UCSR0B = _BV(RXEN0)  | _BV(TXEN0);  // Enable RX and TX

	// setup stdio
	stdin  = &uart_input;
	stdout = &uart_output;
	stderr = &uart_output;
	}

//----------------------------------------------------------------------------------------------------
// init uart baud 1200
//----------------------------------------------------------------------------------------------------
void uart_init_1200(void)
	{
	#undef BAUD
	#define BAUD 1200
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
	UCSR0A |= _BV(U2X0);
	#else
	UCSR0A &= (uint8_t)~(_BV(U2X0));
	#endif

	uart_init();
	}

//----------------------------------------------------------------------------------------------------
// init uart baud 2400
//----------------------------------------------------------------------------------------------------
void uart_init_2400(void)
	{
	#undef BAUD
	#define BAUD 2400
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
	UCSR0A |= _BV(U2X0);
	#else
	UCSR0A &= (uint8_t)~(_BV(U2X0));
	#endif

	uart_init();
	}

//----------------------------------------------------------------------------------------------------
// init uart baud 9600
//----------------------------------------------------------------------------------------------------
void uart_init_9600(void)
	{
	#undef BAUD
	#define BAUD 9600
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
	UCSR0A |= _BV(U2X0);
	#else
	UCSR0A &= (uint8_t)~(_BV(U2X0));
	#endif

	uart_init();
	}

//----------------------------------------------------------------------------------------------------
// init uart baud 19200
//----------------------------------------------------------------------------------------------------
void uart_init_19200(void)
	{
	#undef BAUD
	#define BAUD 19200
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
	UCSR0A |= _BV(U2X0);
	#else
	UCSR0A &= (uint8_t)~(_BV(U2X0));
	#endif

	uart_init();
	}

//----------------------------------------------------------------------------------------------------
// init uart baud 38400
//----------------------------------------------------------------------------------------------------
void uart_init_38400(void)
	{
	#undef BAUD
	#define BAUD 38400
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
	UCSR0A |= _BV(U2X0);
	#else
	UCSR0A &= (uint8_t)~(_BV(U2X0));
	#endif

	uart_init();
	}

//----------------------------------------------------------------------------------------------------
// init uart baud 57600
//----------------------------------------------------------------------------------------------------
void uart_init_57600(void)
	{
	#undef BAUD
	#define BAUD 57600
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
	UCSR0A |= _BV(U2X0);
	#else
	UCSR0A &= (uint8_t)~(_BV(U2X0));
	#endif

	uart_init();
	}

//----------------------------------------------------------------------------------------------------
// init uart baud 115200
// NOTE: setbaud.h isssues a warning "Baud rate achieved is higher than allowed" but it works
//----------------------------------------------------------------------------------------------------
void uart_init_115200(void)
	{
	#undef BAUD
	#define BAUD 115200
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
	UCSR0A |= _BV(U2X0);
	#else
	UCSR0A &= (uint8_t)~(_BV(U2X0));
	#endif

	uart_init();
	}

