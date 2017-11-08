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

	while(1) {
		
		ser_writeln("Arduino\n");
		_delay_ms(1000);
		
	}
}