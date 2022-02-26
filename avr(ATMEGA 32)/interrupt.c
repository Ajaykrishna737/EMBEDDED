/*
 * interrupt.c
 *
 * Created: 06-01-2022 10:38:15 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

int main(void)
{
	DDRD=0xFF;
	DDRC=0xFF;
   MCUCR=0x02;
   GICR=0x40;
   while(1)
   {
	   PORTD=0xFF;
	   _delay_ms(500);
	   PORTD=0x00;
	   _delay_ms(500);
	   sei();
   }
}   
   ISR(INT0_vect)
   {
	   cli();
	   PORTC=0x55;
	   _delay_ms(500);
	   PORTC=0xAA;
	   _delay_ms(500);
	   sei();
   }
