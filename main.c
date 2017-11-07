/*
 * main.c
 *
 * Version: 2017-11-07
 *  Author: Ricardo van der Vlag
 */

#include <avr/io.h>
#include <stdlib.h>
#include <avr/sfr_defs.h>
#define F_CPU 16E6			// CPU frequency
#include <util/delay.h>


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
}

// Serial read function in C

char ser_read() {
	loop_until_bit_is_set(UCSR0A, RXC0); /* Wait until data exists. */
	return UDR0;
}

// Serial read line function in C (from computer to Arduino)

char ser_readln()
{
	uint8_t p=0;
	char word;
	char part;
	
	while (part!='\n')
	{
		part=ser_read();
		word += part;
	}
}

int main(void)
{
	ser_init();
	_delay_ms(1000);
	
	DDRB=0; // read (pin 0+1)
	DDRD=4+8; // write (pin 2+3)
	PORTD|=4; // LED 1 is on by default
	
//	char word = ser_readln();
	while(1) {
		
		ser_writeln("Arduino\n");
		_delay_ms(1000);
		
	}
}