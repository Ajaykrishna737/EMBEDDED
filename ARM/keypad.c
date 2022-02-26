#include<lpc21xx.h>
void delay();
void cmd( int a);
void data( char b);
char key();
void display(const char *p);
void main()
{
IO0DIR=0xFFFFFFFF;
IO1DIR=0xF0FFFFFF;

cmd(0x01);
cmd(0x38);
cmd(0x06);
cmd(0x0E);
cmd(0x80);

char a[4]="1234",b[4];
for (int i=0;i<4;i++)
{
b[i]=key();
data(b[i]);

}
 int c=0;
for(int i=0;i<4;i++)
{
if(a[i]==b[i])
{
c++;
}
}
if(c==4)
{
display("access granted");
cmd(0xc0);
cmd(0x01);
}
else
{
display("wrong");
cmd(0x01);
}
}


char key()
{
while(1)
{

IO1CLR=0xFFFFFFFF;
IO1SET=0X7F000000;
int e=IO1PIN&0X0F000000;
switch(e)
{
case 0x07000000:return('1');break;
case 0x0B000000:return('2');break;
case 0x0D000000:return('3');break;
case 0x0E000000:return('4');break;
}

IO1CLR=0xFFFFFFFF;
IO1SET=0xBF000000;

e=IO1PIN&0x0F000000;

switch(e)
{
case 0x07000000:return('5');break;
case 0x0B000000:return('6');break;
case 0x0D000000:return('7');break;
case 0x0E000000:return('8');break;
}

IO1CLR=0xFFFFFFFF;
IO1SET=0xDF000000;
 e=IO1PIN&0x0F000000;

switch(e)
{
case 0x07000000:return('9');break;
case 0x0B000000:return('a');break;
case 0x0D000000:return('b');break;
case 0x0E000000:return('c');break;
}

IO1CLR=0xFFFFFFFF;
IO1SET=0xEF000000;
 e=IO1PIN&0x0F000000;

switch(e)
{
case 0x07000000:return('D');break;
case 0x0B000000:return('E');break;
case 0x0D000000:return('F');break;
case 0x0E000000:return('G');break;
}
}
}
void cmd(int a)
{
IO0CLR=0xFFFFFFFF;
delay();
IO0SET=a<<7;
IO0SET=0X00000002;
delay();
IO0CLR=0x00000002;
delay();
}
void data( char b)
{
IO0CLR=0xFFFFFFFF;
delay();
IO0SET=b<<7;
IO0SET=0X00000003;
delay();
IO0CLR=0x00000002;
delay();
}
void display(const char *p)
{
while(*p!='0')
{
data(*p);
p++;
}
}
void delay()
{
for(int i=0;i<1000;i++)
for(int j=0;j<1000;j++);
}



