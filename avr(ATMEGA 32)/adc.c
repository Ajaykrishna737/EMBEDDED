hg/*
 * adc.c
 *
 * Created: 21-12-2021 12:37:07 PM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>

void cmd(int a);
void data(char b);
int main(void)

{
int a;
DDRC=0XFF;
DDRD=0XFF;
DDRA=0X00;
cmd(0X38);
cmd(0x01);
cmd(0X80);
cmd(0X06);
cmd(0x0E);

ADMUX=0X60;
while(1)
{

ADCSRA=0XC0;
while((ADCSRA&0X40)==1);
a=ADCH;
int b,c,d;
b=(a/100)+48;
data(b);
c=((a%100)/10)+48;
data(c);
d=(a%10)+48;
data(d);
cmd(0X01);

}
}

void cmd(int a)
{
PORTD=a;
PORTC=0X02;
_delay_ms(500);
PORTC=0X00;
}
void data(char b)
{
PORTD=b;
PORTC=0X03;
_delay_ms(500);
PORTC=0X01;
}