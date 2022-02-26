/*
 * avr_lcd.c
 *
 * Created: 14-12-2021 10:28:12 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void cmd (int a);
void display(const char *p);

int main(void)
{
	int i;
	char a[]="Hello";
	DDRD=0xFF;
	DDRC=0XFF;
	cmd(0x01);
	cmd(0x80);
	cmd(0x0E);
	cmd(0x38);
	cmd(0x06);
       
	   for(i=0;a[i]!='\0';i++) 
	   {
		   data(a[i]);
	   }
}	
	void cmd(int a)
	{
		PORTD=a;
		PORTC=0x02;
		_delay_ms(500);
		PORTC=0x00;
	}
	void data (char b)
	{	
	PORTD= b;
	PORTC=0x03;
	_delay_ms(500);	
	PORTC=0x01;
	}		
	  void display(const char *p) 
	  {
		  while (*p!='\0')
		  {
			  data(*p);
			  p++;
		  }			  		   
		  }    
