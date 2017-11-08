/*
 * main.c
 *
 * Version: 2017-11-07
 *  Author: Ricardo van der Vlag
 */

#include <avr/io.h>
#define F_CPU 16E6			// CPU frequency
#include <util/delay.h>

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