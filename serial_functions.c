/*
 * serial_functions.c
 *
 * Created: 8-11-2017 11:43:30
 *  Author: Ricardo
 */ 

#include <avr/io.h>

// Output on USB = PD1 = bread pin 1
// F_OSC = 16 MHz & baud rate = 19.200
#define UBBRVAL 51

// Serial init function, enables data-transport in both directions
void ser_init() {
	// Set baud rate
	UBRR0H = 0;
	UBRR0L = UBBRVAL;
	// disable U2X mode
	UCSR0A = 0;
	// enable TX and RX
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);
	// set frame format: asynchronous, 8 data bits, 1 stop bit, no parity
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
}

void ser_write(uint8_t data)
{
	// Wait for an empty transmit buffer
	// UDRE is set when the transmit buffer is empty
	loop_until_bit_is_set(UCSR0A, UDRE0);
	// Send data
	UDR0 = data;
}

void ser_writeln(char *line)
{
	uint8_t lenght = strlen(line);
	for (uint8_t p=0; p < lenght ; p++)
	{
		char c = line[p];
		ser_write(c);
	}
	ser_write(0x0A);
}

// Serial read function in C

char ser_read() {
	loop_until_bit_is_set(UCSR0A, RXC0); /* Wait until data exists. */
	return UDR0;
}

// Serial read line function in C (from computer to Arduino)

void ser_readln(char *line, uint8_t bufsize) {
	uint8_t p=0;
	char c;
	do {
		c=ser_read();
		if (c!='\n') {
			line[p++]=c;
		}
		line[p]='\0';
	} while ((c!='\n') && (p<bufsize-1));
}