#include <lpc21xx.h>
void delay();
 void main()
{
IO0DIR=0xFFFFFFFF
IO1DIR=0xFFFFFFFF;
while(1)
{
IO0SET=0x0000000F;
delay();
IO0CLR=0xFFFFFFFF;
delay();
IO1SET=0x0000000F;
delay();
IO1CLR=0xFFFFFFFF;
delay();
for();
	
	for(int i=0;i<f;i++)
{
	IO0SET=IO1SET<<1;
}
}
}
void delay()
{
int i,j;
for(i=0;i<500;i++)
for(j=0;j<500;j++);
}