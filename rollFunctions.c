/*
 * rollFunctions.c
 *
 * Created: 10-11-2017 12:55:05
 *  Author: Ricardo
 */ 
#define F_CPU 16E6			// CPU frequency
#include <util/delay.h>

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