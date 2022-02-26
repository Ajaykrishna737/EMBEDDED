#include<lpc21xx.h>
void delay();
void cmd(int x);
void data( char y);
void main()
{
	IO1DIR=0xFFFF0000;
IO0DIR=0xF0FFFFFF;

PINSEL1=0x15400000;
cmd(0x01);
cmd(0x38);
cmd(0x06);
cmd(0x80);
cmd(0x0E);
int a, b,e, c,d;
while(1)
{
ADCR=0x01200001;
while((ADDR&0x80000000)==0);
a=ADDR>>6;
b=a/1000+48;
data(b);
c=(a%1000)/100+48;
data(c);
d=(a%100)/10+48;
data(d);
e=(a%10)+48;
data(e);
	cmd(0x01);
}

}


void cmd(int x)
{
IO1CLR=0xFFFFFFFF;
delay();
IO1SET=x<<20;
IO1SET=0x20000000;
delay();
IO1CLR=0x20000000;
delay();

}

void data(char y)
{
IO1CLR=0xFFFFFFFF;
delay();
IO1SET=y<<20;
IO1SET=0x30000000;
delay();
IO1CLR=0x20000000;
delay();

}
void delay()
{
for(int i=0;i<500;i++)
for(int j=0;j<500;j++);
}