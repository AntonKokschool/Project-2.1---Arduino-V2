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
	init_eeprom();
	_delay_ms(1000);
	
	setupLed(); // Setup for led config
	// Tunrs right led on based on status
	// Down is red and up is green
	if (status == "up")
	{greenLedOn();}
	
	if (status == "down")
	{redLedOn();}
	
	char buffer[200];
	while(1)
	{
		ser_readln(buffer, 200);
		uint8_t ok=0;
		
		if (!strcmp(buffer, "Are you Arduino?"))
		{ser_writeln("I am Arduino!"); ok=1;}
		
		if (!strcmp(buffer, "Set name"))
		{
			ser_writeln("What is my new name?"); ok=1;
			ser_readln(buffer, 200);
			updatename(buffer);
			ser_writeln("My name is");
			ser_writeln(buffer);
		}

		if (!strcmp(buffer, "Rol up"))
		{
			if (status == "up")
			{ser_writeln("Already up"); ok=1;}
			else
			{
				ser_writeln("Rolling up");
				ser_writeln("OK");
				rolUp();
				ser_writeln("Rolled up"); ok=1;
				status = "up";
			}
		}
		
		if (!strcmp(buffer, "Status"))
		{
			if (status == "down")
			{
				ser_writeln("Rolled down"); ok=1;
			}
			else
			{
				ser_writeln("Rolled up"); ok=1;
			}
		}

		if (!strcmp(buffer, "Rol down"))
		{
			if (status == "down")
			{ser_writeln("Already down"); ok=1;}
			else
			{
				ser_writeln("Rolling down");
				ser_writeln("OK");
				rolDown();
				ser_writeln("Rolled down"); ok=1;
				status = "down";
			}
		}
		
		if (ok==0)
		{ser_writeln("Unknown command!");}
			
		if (ok==1)
		{ser_writeln("OK");}
			
		else
		{ser_writeln("ERR");}
	}
}