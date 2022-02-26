/*
 * adc_to_motor.c
 *
 * Created: 03-01-2022 10:46:40 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void cmd(int a);
void data (char b);

int main(void)
{
	int a,b, c,d;
	DDRC=0xFF;
	DDRB=0xFF;
	DDRD=0XFF;
	DDRA=0X00;
	
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0E);
	
	ADMUX=0x60;
    while(1)
    {
        ADCSRA=0XC0;
		while((ADCSRA&0X40)==1);
		a=ADCH;
		b=(a/100)+48;
		data(b);
		c=((a%100)/10)+48;
		data(c);
		d=(a%10)+48;
		data(d);
		cmd(0x01);
		if(a>=17)
		PORTB=0xe;
}
		
    }
void cmd(int a)
{
	

PORTD=a;
PORTC=0x02;
_delay_ms(500);
PORTC=0x00;
}
void data(char b)
{
	
	PORTD=b;
	PORTC=0x03;
	_delay_ms(500);
	PORTC=0x01;
	
}