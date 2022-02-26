#include<lpc21xx.h>
void delay();
void cmd(int a);
void data( char b);
void display( const char *p);
void main()
{
IO0DIR=0xFFFFFFFF;
IO1DIR=0xFFFFFFFF;

cmd(0x38);
cmd(0x01);
cmd(0x06);
cmd(0x0E);
cmd(0x80);


while(1)
{
if((IO0PIN&0x00001000)==0)
{
int a=0x00000001;
IO1SET=a;
delay();
IO1CLR=a;
delay();
for(int i=0;i<32;i++)
{
a=a<<1;
IO1SET=a;
delay();
IO1CLR=a;
delay();
display("one");
cmd(0x01);
}
}

if((IO0PIN&0x00008000)==0)
{
IO1SET=0xFFFFFFFF;
delay();
IO1CLR=0xFFFFFFFF;
delay();
IO1SET=0x00000000;
delay();
IO1CLR=0x00000000;
delay();
display("one");
cmd(0x01);
}
else if((IO0PIN&0x00004000)==0)
{
IO1SET=0X55555555;
delay();
IO1CLR=0xFFFFFFFF;
delay();
IO1SET=0xAAAAAAAA;
delay();
IO1CLR=0xFFFFFFFF;
delay();
}
else if((IO0PIN&0x00002000)==0)
{
IO1SET=0x00FF00FF;
delay();
IO1CLR=0xFFFFFFFF;
delay();
IO1SET=0xFF00FF00;
delay();
IO1CLR=0xFFFFFFFF;
delay();
}
}
}
void cmd( int a)

{
IO0CLR=0xFFFFFFFF;
delay();
IO0SET=a<<2;
IO0SET=0x00000002;
delay();
IO0CLR=0x00000002;
delay();
}

void data( char b)
{
IO0CLR=0XFFFFFFFF;
delay();
IO0SET=b<<2;
IO0SET=0x00000003;
delay();
IO0CLR=0x00000002;
delay();
}
void display( const char *p)
{

while(*p!='\0')
{
data(*p);
p++;
}
}

void delay()
{

for(int i=0;i<500;i++)
for(int j=0;j<500;j++);
}

