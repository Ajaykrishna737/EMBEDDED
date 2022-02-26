#include<lpc21xx.h>
void delay();
void cmd( int a);
void data( char b);
void display(const *p);
void main()
{
int i;
char a[]="HELLO";
IO0DIR=0xFFFFFFFF;
IO1DIR=0xFFFF0000;


cmd(0x38);
cmd(0x01);
cmd(0x06);
cmd(0x0E);
cmd(0x80);
while(1)
{

for(i=0;a[i]!='\0';i++)
{
data(a[i]);

}
while(1);
}
}
void cmd( int a)
{

IO1CLR=0xFFFF0000;
delay();
IO1SET=a<<16;
IO0SET=0x00000002;
delay();
IO0CLR=0X00000002;
delay();
  
}


void data (char b)
{
IO1CLR=0xFFFF0000;
delay();
IO1SET=b<<16;
IO0SET=0x00000003;
delay();
IO0CLR=0X00000002;
  delay();
  
}
void display(const *p)
{
while(*p!='\0')
{
data(*p);
p++;
}
}


void delay()
{
int i,j;

for(i=0;i<500;i++)
for(j=0;j<500;j++);
}