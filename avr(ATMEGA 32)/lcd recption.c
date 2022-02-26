/*
 * lcd_recption.c
 *
 * Created: 18-12-2021 12:16:39 PM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void cmd(int a);
void data(char b);
void display (const char *p);
char rec();


int main(void)
{
   char a;
  
   DDRC=0xFF;
   DDRA=0xFF;
   cmd(0x38);
   cmd(0x01);
   cmd(0x80);
   cmd(0x06);
   cmd(0x0E);
   
   DDRD=0xFE;
   UCSRA=0x00;
   UCSRB=0x18;
   UCSRC=0x06;
   UBRRL=0x33;
   UBRRH=0x00;
   while(1)
   {
	   
	   a=rec();
	   data(a);
   }
   
}
char rec()
{
	while((UCSRA&0x80)==0);
	return(UDR);
_delay_ms(500);	
}   
void cmd(int a)
{
	PORTC=a;
	PORTA=0x02;
	_delay_ms(500);
	PORTA=0X00;
	
}
void data(char b)
{
	PORTC=b;
	PORTA=0x03;
	_delay_ms(500);
	PORTA=0x01;
}	
void display (const char *p)
{
	while(*p!='\0')
	{
		data(*p);
		p++;
	}
}


