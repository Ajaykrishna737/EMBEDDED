/*
 * keypad_with__dc_motor.c
 *
 * Created: 16-12-2021 11:52:15 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void cmd(int a);
void data( char b);
void display(const char *p);
char key();

void main()

{
	int a,i;
	DDRD=0xF0;
	DDRC=0xFF;
	DDRA=0xFF;
	DDRB=0xFF;
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0E);
	
	while(1)
	{
		a=key();
		data(a);
		if(a=='6')
		{
			PORTB=0xDD;
			_delay_ms(500);
			display("reverse");
			cmd(0x01);
		}
		else if (a=='7')
		{
			PORTB=0xEE;
			_delay_ms(500);
			display("forward");
			cmd(0x01);
		}
		else if (a=='8')
		{
			
			PORTB=0x00;
			_delay_ms(500);
			display("stop");
			cmd(0x01);
		}			
		}			
		}
		
	
	
				
   

char key()
{
	int e;
	while(1)
	{			
		PORTD=0x7F;
		e=PIND&0x0F;
		switch(e)
		{
			case 0x07:return('1');break;
			case 0x0B:return('2');break;
			case 0x0D:return('3');break;
			case 0x0E:return('4');break;
		}
		PORTD=0xBF;
		e=PIND&0x0F;
		switch(e)
		{			
			case 0x07:return('5');break;
			case 0x0B:return('6');break;
			case 0x0D:return('7');break;
			case 0x0E:return('8');break;			
        
    }
	PORTD=0xDF;
		e=PIND&0x0F;
		switch(e)
		{			
			case 0x07:return('9');break;
			case 0x0B:return('A');break;
			case 0x0D:return('B');break;
			case 0x0E:return('C');break;			
        
    }
	PORTD=0xEF;
		e=PIND&0x0F;
		switch(e)
		{			
			case 0x07:return('D');break;
			case 0x0B:return('E');break;
			case 0x0D:return('F');break;
			case 0x0E:return('G');break;			
        
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