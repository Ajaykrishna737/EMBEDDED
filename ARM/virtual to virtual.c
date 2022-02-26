#include<lpc21xx.h>
void delay();
void data( char b);
char rec();
void main()
{

char a[10];
int i;
IO0DIR=0x00000001;
PINSEL0=0x00000005;




U0LCR=0X83;
U0DLL=0X63;
U0DLM=0X00;
U0LCR=0X03;



while(rec()!='*');
	for(i=0;a[i-1]!='#';i++)
	{
		a[i]=rec();
	}
	a[i-1]='\0';
	for(i=0;a[i]!='\0';i++)
	{
		data(a[i]);
	}
}

char rec()
{
while((U0LSR&0x01)==0);
return(U0RBR);
delay();

}
void data(char b)

{
U0THR=b;
while((U0LSR&0x20)==0);
delay();
}



void delay()
{
for(int i=0;i<500;i++)
for(int j=0;j<500;j++);
}
