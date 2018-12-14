#include <avr/io.h>
#include <stdio.h>

#include "uart.h"

//----------------------------------------------------------------------------------------------------
// init uart baud 
//----------------------------------------------------------------------------------------------------
void uart_set_baud(uint32_t baud)
	{
	uint16_t ubrr_value;       

	ubrr_value = (uint16_t)(((F_CPU + (8UL * baud)) / (16UL * baud)) - 1UL);

	if (((100 * F_CPU) > ((16 * (ubrr_value + 1)) * ((100 * baud) + (baud * 2)))) ||
			((100 * F_CPU) < ((16 * (ubrr_value + 1)) * ((100 * baud) - (baud * 2)))))
		{
		// use 2x speed
		ubrr_value = (uint16_t)(((F_CPU + (4UL * baud)) / (8UL * baud)) - 1UL);
		UCSR0A |= _BV(U2X0);
		}
	else
		{
		// use normal speed
		UCSR0A &= (uint8_t)~(_BV(U2X0));
		}
		
	UBRR0L = (uint8_t)ubrr_value;
	UBRR0H = (uint8_t)(ubrr_value >> 8);

	uart_init();
	}
