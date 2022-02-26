/*
 * motor.c
 *
 * Created: 15-12-2021 10:33:06 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void cmd(int a);
void data(char b);
void display(const char *p);

int main(void)
{
	DDRD=0xFF;
	DDRB=0x00;
	DDRC=0xFF;
	DDRA=0xFF;
	cmd(0x01);
	cmd(0x80);
	cmd(0x0E);
	cmd(0x38);
	cmd(0x06);
    while(1)
     
    {
		if((PINB&0x01)==0)
		{
			PORTD=0xDD;
			_delay_ms(500);
			display("one");
			cmd(0x01);
		
    }
	else if((PINB&0x02)==0)
		{
			PORTD=0xEE;
			_delay_ms(500);
			display("second");
			cmd(0x01);
		}
		else if((PINB&0x04)==0)
		{
			PORTD=0x00;
			_delay_ms(500);
			display("third");
			cmd(0x01);
		}				
}
	}
void cmd(int a)
{
PORTC=a;
PORTA=0x02;
_delay_ms(500);
PORTA=0x00;
	}
	void data (char b)
	{
		PORTC=b;
		PORTA=0x03;
		_delay_ms(500);
		PORTA=0x01;
	}
	void display(const char *p)
	{
		while(*p!='\0')
		{
			data(*p);
			p++;
		}
	}