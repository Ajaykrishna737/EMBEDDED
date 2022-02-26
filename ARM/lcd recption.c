#include<lpc21xx.h>
void delay();
void data( char b);
void cmd(int a);
void display(const char *p);
char rec();
void main()
{
char a;
PINSEL0=0x00000005;
IO0DIR=0xFFFFFFF3;
IO1DIR=0xFFFFFFFF;

cmd(0x38);
cmd(0x01);
cmd(0x06);
cmd(0x0E);
cmd(0x80);


U0LCR=0X83;
U0DLL=0X63;
U0DLM=0X00;
U0LCR=0X03;

while(1)
{
a= rec();
data(a);
}
}
char rec()
{
while((U0LSR&0x01)==0);
return(U0RBR);
delay();
}

void cmd(int a)
{
IO0CLR=0xFFFFFFFF;
delay();
IO0SET=a<<16;
IO0SET=0x00002000;
delay();
IO0CLR=0x00002000;
delay();
}

void data( char b)
{
IO0CLR=0xFFFFFFFF;
delay();
IO0SET=b<<16;
IO0SET=0x00003000;
delay();
IO0CLR=0x00002000;
delay();
}

void display( const char *p)
{
while (*p!='\0')
{
data (*p);
p++;
}
}


void delay()
{
for(int i=0;i<500;i++)
for(int j=0;j<500;j++);
}



