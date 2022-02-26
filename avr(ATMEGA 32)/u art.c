/*
 * u_art.c
 *
 * Created: 16-12-2021 12:16:14 PM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
	
		
	DDRD=0xFE;
	
	UCSRA=0X00;
	UCSRB=0X18;
	UCSRC=0X06;
	UBRRL=0X33;
	UBRRH=0X00;
	UDR='H';
    while((UCSRA&0X40)==0);
    _delay_ms(500);
         
}	  
