/*
 * recaption_data.c
 *
 * Created: 18-12-2021 10:35:12 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void data (char b);
char rec();

int main(void)
{
	DDRD=0xFE;
    char a;
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0X06;
	UBRRL=0X33;
	UBRRH=0X00;
	while(1)
	{
		a=rec();
		data(a);
	}
			
	}
	char rec()
	{
		
		while((UCSRA&0X80)==0);
		return(UDR);
		_delay_ms(500);
	}
	void data (char b)
	{
	UDR=b;
	while((UCSRA&0X40)==0);
	_delay_ms(500);
	
}