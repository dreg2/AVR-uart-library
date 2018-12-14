#include <avr/io.h>
#include <stdio.h>

#include "uart.h"

int main(void)
	{
        uart_init_115200(); // initialize uart
	printf("uart initialized 0x%02hx 0x%02hx 0x%02hx\n", UBRR0H, UBRR0L, (UCSR0A & (1<<U2X0)));
        uart_set_baud(115200UL); // initialize uart

        while(1)
                {
                puts("Hello world!");
                uint8_t input = (uint8_t)getchar();
                printf("You wrote %c\n", input);
                }

	return 0;
	}

