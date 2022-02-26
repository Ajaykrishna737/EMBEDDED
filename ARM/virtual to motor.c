#include<lpc21xx.h>
void delay();
void delay1();
void cmd(int a);
void data(char b);
char rec();
void main()
{
char a;
IO0DIR=0xFFFFFFFF;
IO1DIR=0xFFFFFFFF;
PINSEL0=0x00000005;


cmd(0x01);
cmd(0x38);
cmd(0x0E);
cmd(0x06);
cmd(0x80);


U0LCR=0X83;
U0DLL=0X63;
U0DLM=0X00;
U0LCR=0X03;

while(1)
{
a=rec();
if (a=='8')
{
IO1SET=0x000DD000;
delay1();
IO1CLR=0x000FF000;
delay1();
cmd(0x01);
}

else if(a==7)
{
IO1SET=0x000EE000;
delay1();
IO1CLR=0x000FF000;
delay1();

cmd(0x01);
}
else if(a==7)
{
IO1SET=0x00000000;
delay1();
IO1CLR=0x000FF000;
delay1();

cmd(0x01);
}
}
}

char rec()
{
while((U0LSR&0X01)==0);
delay();
return(U0RBR);
}
void cmd(int a)
{
IO0CLR=0XFFFFFFFF;
delay();
IO0SET=a<<16;
IO0SET=0X00002000;
delay();
IO0CLR=0X00002000;
delay();
}
void data( char b)
{
IO0CLR=0XFFFFFFF;
delay();
IO0SET=b<<16;
IO0SET=0x00003000;
delay();
IO0CLR=0x00002000;
delay();
}

void delay()
{
for(int i=0;i<500;i++)
for(int j=0;j<500;j++);
}

void delay1()
{
for(int i=0;i<50000;i++)
for(int j=0;j<50000;j++);
}