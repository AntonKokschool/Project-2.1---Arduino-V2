/*
 * rollFunctions.c
 *
 * Created: 10-11-2017 12:55:05
 *  Author: Ricardo
 */ 
#define F_CPU 16E6			// CPU frequency
#include <util/delay.h>

char controlRol()
{
	char buffer[200];
	char status = "up";
	uint8_t ok=0;

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

	if (!strcmp(buffer, "Are you Arduino?"))
	{ser_writeln("I am Arduino!"); ok=1;}

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
}

void rolDown()
{
	greenLedOff();
	redLedOn();
	yellowLedOn();
	_delay_ms(5000);
	yellowLedOff();
}

void rolUp()
{
	redLedOff();
	greenLedOn();
	yellowLedOn();
	_delay_ms(5000);
	yellowLedOff();
}