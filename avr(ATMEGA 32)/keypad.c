/*
 * keypad.c
 *
 * Created: 15-12-2021 12:32:30 PM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void cmd(int a);
void data( char b);
void display(const char *p);

int main(void)

{
	int e;
	DDRD=0xF0;
	DDRC=0xFF;
	DDRA=0xFF;
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0E);
    while(1)
	
    {
		PORTD=0x7F;
		e=PIND&0x0F;
		switch(e)
		{
			case 0x07:data('1');break;
			case 0x0B:data('2');break;
			case 0x0D:data('3');break;
			case 0x0E:data('4');break;
		}
		PORTD=0xBF;
		e=PIND&0x0F;
		switch(e)
		{			
			case 0x07:data('5');break;
			case 0x0B:data('6');break;
			case 0x0D:data('7');break;
			case 0x0E:data('8');break;			
        
    }
	PORTD=0xDF;
		e=PIND&0x0F;
		switch(e)
		{			
			case 0x07:data('9');break;
			case 0x0B:data('A');break;
			case 0x0D:data('B');break;
			case 0x0E:data('C');break;			
        
    }
	PORTD=0xEF;
		e=PIND&0x0F;
		switch(e)
		{			
			case 0x07:data('D');break;
			case 0x0B:data('E');break;
			case 0x0D:data('F');break;
			case 0x0E:data('G');break;			
        
    }
	}
}		
		
	void cmd (int a)
	{

    PORTC=a;
	PORTA=0x02;
	_delay_ms(500);
	PORTA=0x00;
	}
	void data( char b)
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
	