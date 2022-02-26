/*
 * motor_virtual.c
 *
 * Created: 20-12-2021 12:43:52 PM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void cmd(int a);
void data(char b);
void display(const char*p);
char rec();

int main(void)
{
	char a;
	
	DDRA=0xFF;
	DDRB=0xFF;
	DDRC=0xFF;
	DDRD=0xFE;
	
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0E);
	
	UCSRA=0X00;
	UCSRB=0x18;
	UCSRC=0x06;
	UBRRL=0x33;
	UBRRH=0x00;
	
    while(1)
    {
		a=rec();
		if(a=='6')
		{
			PORTC=0xEE;
			_delay_ms(500);
			display("reverse");
			cmd(0x01);
		}
		
		else if(a=='7')
		{
			PORTC=0xDD;
			_delay_ms(500);
			display("forward");
			cmd(0x01);
		}
		else if (a=='9')
		{
			PORTC=0x00;
			_delay_ms(500);
			display("stop");
			cmd(0x01);
		}									
        
    }
}
char rec()
{
	while((UCSRA&0X80)==0);
	_delay_ms(500);
	return(UDR);
}
void cmd(int a)
{
	PORTA=a;
	PORTB=0x02;
	_delay_ms(500);
	PORTB=0x00;
}	
void data( char b)
{
	PORTA=b;
	PORTB=0x03;
	_delay_ms(500);
	PORTB=0X01;
}
void display(const char *p)
{
	while( *p!='\0')
	{
		data(*p);
		p++;
	}
}				