/*
 * star_and_ash_virtual.c
 *
 * Created: 20-12-2021 10:54:41 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
void data ( char b);
char rec();


int main(void)
{
    
  char a[10];
  int i;
  DDRD=0xFE;
  UCSRA=0x00;
  UCSRB=0x18;
  UCSRC=0x06;
  UBRRL=0x33;
  UBRRH=0x00;
  while(1)
  {
	  
  while( rec()!='*');
  
  for (i=0;a[i-1]!='#';i++)
  {
	  a[i]=rec();
  }
  a[i-1]='\0';
  for(i=0;a[i]!='\0';i++)
  {
	  data (a[i]);
	  
  }
}  
  }
void data( char b)
{
	

UDR=b;
while((UCSRA&0x40)==0);
_delay_ms(500);
}

char rec()
{
	while ((UCSRA&0x80)==0);
	return(UDR);
	
	_delay_ms(500);
}