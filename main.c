/*
 * main.c
 *
 * Version: 2017-11-07
 *  Author: Ricardo van der Vlag
 */

#include <avr/io.h>
#define F_CPU 16E6			// CPU frequency
#include <util/delay.h>

volatile status = "up";

int main(void)
{
	ser_init();
	_delay_ms(1000);
	
	setupLed(); // Setup for led config
	// Tunrs right led on based on status
	// Down is red and up is green
	if (status == "up")
	{greenLedOn();}
	
	if (status == "down")
	{redLedOn();}
	
	char buffer[200];
	while(1) {
		ser_readln(buffer, 200);
		uint8_t ok=0;
		
		
		
		if (ok==0)
		{ser_writeln("Unknown command!");}
			
		if (ok==1)
		{ser_writeln("OK");}
			
		else
		{ser_writeln("ERR");}
	}
}