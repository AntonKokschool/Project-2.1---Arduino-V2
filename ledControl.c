#include <avr/interrupt.h>
/* Arduino 101: timer and interrupts
 1: Timer1 compare match interrupt example 
 more infos: http://www.letmakerobots.com/node/28278
 created by RobotFreak 
 */
void greenLedOn(){
	PORTD |= 0x20;				// Turns on green led
}
void greenLedOff(){
	PORTD &= ~0x20;				// Turns off green led
}
void yellowLedOn(){
	TIMSK1 |= (1 << OCIE1A);	// enable timer compare interrupt used for yellow led
}
void yellowLedOff(){
	TIMSK1 &= (1 << ~OCIE1A);	// disable timer compare interrupt used for yellow led
}
void redLedOn(){
	PORTD |= 0x80;				// Turns on red led
}
void redLedOff(){
	PORTD &= ~0x80;				// Turns off red led
}
void setupLed()
{
	DDRD = 0x20 | 0x40 | 0x80;
	// initialize timer1 
	cli();						// disable all interrupts
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;
	
	OCR1A = 31250;				// compare match register 16MHz/256/2Hz=
	TCCR1B |= (1 << WGM12);		// CTC mode
	TCCR1B |= (1 << CS12);		// 256 prescaler
	yellowLedOff();				
	sei();           // enable all interrupts
}


ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
	PORTD ^= 0x40;				// invert yellow led to on/off state
}