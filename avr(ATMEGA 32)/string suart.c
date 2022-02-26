/*
 * string_suart.c
 *
 * Created: 17-12-2021 12:32:09 PM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void display (char b);

int main(void)
{
	int i;
	char a[10]="hello";
	UCSRA=0X00;
	UCSRB=0X18;
	UCSRC=0X06;
	UBRRL=0X33;
	UBRRH=0X00;
	for(i=0;a[i]!='\0';i++)
	{
		display(a[i]);
	}		
		while(1); 
    
	}   
	   
    void display (char b)
	{
	UDR=b;
	while((UCSRA&0x40)==0);
	_delay_ms(500);
	}	
