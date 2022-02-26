/*
 * pwm.c
 *
 * Created: 05-01-2022 10:28:34 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int i;
DDRB=0xFF;
TCCR0=0x69;
TCNT0=0xFF;
while(1)
{
	
	for(i=0;i<256;i++)
	{
		OCR0=i;
		_delay_ms(500);
	}
}   
}