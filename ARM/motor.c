#include<lpc21xx.h>
void delay();
void delay1();
void cmd(int a);
void data(char b);
void display(const char *p);
void main()

{
IO0DIR=0xFFFFFFFF;
IO1DIR=0xFFFFFFFF;

cmd(0x38);
cmd(0x01);
cmd(0x80);
cmd(0x0E);
cmd(0x06);
cmd(0x01);

while(1)
{
if((IO1PIN&0x00000008)==0)
{
IO0SET=0x000000DD;
delay1();
IO0CLR=0x000000DD;
delay1();
display('forward');
cmd(0x01);
}
if((IO1PIN&0x40000000)==0)
{
IO0SET=0x00000022;
delay1();
IO0CLR=0x00000022;
delay1();
display("two");
cmd(0x01);
}

}
}
void cmd(int a)
{
IO1CLR=0xFFFFFFFF;
delay();
IO1SET=a<<16;
IO0SET=0x00002000;
delay();
IO0CLR=0x00002000;
delay();
}
void data( char b)
{
IO1CLR=0xFFFFFFFF;
delay();
IO1SET=b<<16;
IO0SET=0x00003000;
delay();
IO0CLR=0x00002000;
delay();
}

void display( const char *p)
{
while(*p!='0')
{
data(*p);
p++;
}
}

void delay ()

{
for(int i=0;i<500;i++)
for(int j=0;j<500;j++);
}

void delay1()
{
for(int i=0;i<10000;i++)
for(int j=0;j<10000;j++);
}