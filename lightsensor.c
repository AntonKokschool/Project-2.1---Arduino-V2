/*
 * lightsensor.c
 *
 * Created: 09-Nov-17 1:16:14 PM
 *  Author: Thijs
 */ 

#include <avr/io.h>
#include <stdint.h>       // needed for uint8_t
#define F_CPU 16E6			// CPU frequency
#include <util/delay.h>


int ADCsingleREAD(uint8_t adctouse)
{
	int ADCval;

	ADMUX = adctouse;        // use #1 ADC
	ADMUX |= (1 << REFS0);   // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);  // clear for 10 bit resolution

	// 128 prescaler
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	ADCSRA |= (1 << ADEN);    // Enable the ADC
	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	while(ADCSRA & (1 << ADSC)); // waits for the ADC to finish

	ADCval = ADCL;
	ADCval = (ADCH << 8) + ADCval; // ADCH is read so ADC can be updated again

	return ADCval;
}


int lightsensor(void)
{
	ser_init();
	int ADCvalue;
	DDRB = 1;
	while (1)
	{		
		ADCvalue = ADCsingleREAD(1);
		// ADCvalue now contains an 10bit ADC read
		if (ADCvalue < 100) {
			ser_writeln("Dark");
		} else {
			if (ADCvalue < 400) {
				ser_writeln("Dim");
			} else {
				if (ADCvalue < 420) {
					ser_writeln("Light");
				} else {
					if (ADCvalue < 430) {
						ser_writeln("Bright");
						PORTB = 1;
					} else {
						if (ADCvalue >= 440) {
							ser_writeln("Too Bright");
							PORTB = 1;
						}
					}
				}
			}
		}
	/*if (ADCvalue != 0) {
		PORTB = 1;
	} else {
		PORTB = 0;
		} */
		//ser_writeln(ADCvalue);
		_delay_ms(1000);
		PORTB = 0;
	}
}