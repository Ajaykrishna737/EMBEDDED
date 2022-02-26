/*
 * timer.c
 *
 * Created: 04-01-2022 10:25:11 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include<util/delay.h>
void timer();

int main(void)
{
  DDRC=0xFF;
  DDRD=0xFF;
  
  TCCR2=0x07;
  TCNT2=0xFF;
 
  while(1)
  {
	  PORTD=0xFF;
	  timer();
	  PORTD=0x00;
	  timer();
  }
}
void timer()
{
	while((TIFR&0x40)==0);
}