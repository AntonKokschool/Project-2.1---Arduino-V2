/*
 * Project-2.1---Arduino.c
 *
 * Created: 16-10-2017 15:52:44
 * Author : Ricardo
 */ 

#include <avr/io.h>


int main(void)
{
    volatile count = 0;
	
    while (1) 
    {
		if (count < 32767)
		{count++;}
		else
		{count = 0;}
    }
}

