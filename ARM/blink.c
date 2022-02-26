#include<lpc21xx.h>
void delay();
 void main()
{
IO0DIR=0xFFFFFFFF;
while(1)
{
IO0SET=0xFFFFFFFF;
delay();
IO0CLR=0xFFFFFFFF;
delay();
}
}
void delay()
{
int i,j;
for(i=0;i<500;i++)
for(j=0;j<500;j++);
}