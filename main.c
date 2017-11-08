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
char buffer[200];
	while(1)
	{
		
		ser_readln(buffer, 200);
		if (!strcmp(buffer, "Arduino"))
			{
				ser_writeln("Handshake")
			}
		if (strcmp(buffer, 200))
			{
				ser_writeln("ERROR")
			}
		
	}
}