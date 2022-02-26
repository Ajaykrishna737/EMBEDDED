#include<lpc21xx.h>
void delay();
void main()
{
PINSEL0=0x00000001;
IO0DIR=0x000000001;
U0LCR=0X83;
U0DLL=0X63;
U0DLM=0X00;
U0LCR=0X03;
U0THR='H';
while((U0LSR&0x20)==0);
delay();

}
void delay()
{
for(int i=0;i<500;i++)
for(int j=0;j<500;j++);
}