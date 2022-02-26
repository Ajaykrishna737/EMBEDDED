#include<lpc21xx.h>
void delay();
void delay1();
void cmd( int a);
void data( char b);
char key();
char rec();
void display(const char *p);
void main()
	
{  
PINSEL0=0x00000005;
IO0DIR=0xFFFFF001;
IO1DIR=0xF0FFFFFF;

  cmd(0x38);
  cmd(0x01);
  cmd(0x80);
  cmd(0x06);
  cmd(0x0E);
	
 char x[3]="123";
char y[3]="456";
char z[3]="789";
char q[3];
    while(1)
{
if((IO0PIN&0x00000100)==0)
{
IO1SET=0x00DD0000;
delay1();
IO1CLR=0x00FF0000;
delay1();
display("GATE1 OPEN");
cmd(0X01);
display("MOVE TO TOLL");
cmd(0X01);
IO1SET=0x00000000;
delay1();
IO1CLR=0x00FF0000;
delay1();
int i,j;int c=0;
 for(i=0;i<3;i++)
 {
  q[i]=key();
  data(q[i]);
 }
 cmd(0XC0);
 for(j=0;j<3;j++)
 {
 if(x[j]==q[j])
 {
 c++;
 }
 }
 if(c==3)
 {
display("two Wheel");
 cmd(0X01);
 display("Amount 50");
 cmd(0X01);
 
U0LCR=0X83;
U0DLL=0X63;
U0DLM=0X00;
U0LCR=0X03;
 char t;char v;char u;
 t=rec();
 data(t);
 v=rec();
 data(v);
 u=rec();
 data(u);
 cmd(0X01);
 t=t-48;
 v=v-48;
 u=u-48;
 int rs=t*100+v*10+u;
 if(rs>50)
 {
 int bln=rs-50;
 display("balance");
 cmd(0XC0);
 int m,n,o;
 m=(bln/100)+48;
 data(m);
 n=((bln%100)/10)+48;
 data(n);
 o=(bln%10)+48;
 data(o);
 cmd(0X01);
 char tt;char vv;char uu;
 tt=rec();
 data(tt);
 vv=rec();
 data(vv);
 uu=rec();
 data(uu);
 cmd(0X01);
 tt=tt-48;
 vv=vv-48;
 uu=uu-48;
 int rss=tt*100+vv*10+uu;
 if (rss==bln)
 {
	 cmd(0X01);
IO1SET=0x00EE0000;
delay1();
IO1CLR=0x00FF0000;
delay1();
 display("Move to Gate2");
 cmd(0x01);
 
 } 
 else
 {
 display("pay balance");
 
 cmd(0X01);
IO1SET=0x00DD0000;
delay1();
IO1CLR=0x00FF0000;
delay1();
 display("GATE2 OPEN");
 cmd(0X01);
 }
}
 else if(rs=50)
 {
 display("no balance");
 cmd(0x01);
 }
 }
 else 
 {
 display("Wrong Password");
 cmd(0X01);
 }
}
else if((IO0PIN&0x00000200)==0)
{
IO1SET=0x00DD0000;
delay1();
IO1CLR=0x00FF0000;
delay1();
display("GATE2 OPEN");
cmd(0X01);
display("MOVE TO TOLL");
cmd(0X01);
IO1SET=0x00000000;
delay1();
IO1CLR=0xFFFFFFFF;
delay();
int i,j;int c=0;
 for(i=0;i<3;i++)
 {

  q[i]=key();
  data(q[i]);
 }
 cmd(0XC0);
 for(j=0;j<3;j++)
 {
 if(y[j]==q[j])
 {
 c++;
 }
 }
 if(c==3)
 {
 display("Four Wheel");
 cmd(0X01);
 display("Amount 100");
 cmd(0X01);
U0LCR=0X83;
U0DLL=0X63;
U0DLM=0X00;
U0LCR=0X03;
 char t;char v;char u;
 t=rec();
 data(t);
 v=rec();
 data(v);
 u=rec();
 data(u);
 cmd(0X01);
 t=t-48;
 v=v-48;
 u=u-48;
 int rs=t*100+v*10+u;
 if(rs>100)
 {
 int bln=rs-100;
 display("balance");
 cmd(0XC0);
 int m,n,o;
 m=(bln/100)+48;
 data(m);
 n=((bln%100)/10)+48;
 data(n);
 o=(bln%10)+48;
 data(o);
 cmd(0X01);
 char tt;char vv;char uu;
 tt=rec();
 data(tt);
 vv=rec();
 data(vv);
 uu=rec();
 data(uu);
 cmd(0X01);
 tt=tt-48;
 vv=vv-48;
 uu=uu-48;
 int rss=tt*100+vv*10+uu;
 if (rss==bln)
 {
 display("Move to Gate2");
	 cmd(0x01);
 } 
 else
 {
 display("pay balance");
 
 cmd(0X01);
 IO1SET=0x00EE0000;
delay1();
IO1CLR=0x00FFFF00;
delay1();
 display("GATE2 OPEN");
	 cmd(0xc0);
 cmd(0X01);
 }
}
 else if(rs=100)
 {
 display("no balance");
 }
 }
 else 
 {
 display("Wrong Password");
 cmd(0X01);
 }
}
if((IO0PIN&0x00000400)==0)
{
IO1SET=0x00DD0000;
delay1();
IO1CLR=0x00FF0000;
delay1();
display("GATE3 OPEN");
cmd(0X01);
display("MOVE TO TOLL");
cmd(0X01);
IO1SET=0x00000000;
delay1();
IO1CLR=0xFFFFFFFFF;
delay();

int i,j;int c=0;
 for(i=0;i<3;i++)
 {
  q[i]=key();
  data(q[i]);
 }
 cmd(0XC0);
 for(j=0;j<3;j++)
 {
 if(z[j]==q[j])
 {
 c++;
 }
 }
 if(c==3)
 {
 display("six Wheel");
 cmd(0X01);
 display("Amount 200");
 cmd(0X01);
U0LCR=0X83;
U0DLL=0X63;
U0DLM=0X00;
U0LCR=0X03;
 char t;char v;char u;
 t=rec();
 data(t);
 v=rec();
 data(v);
 u=rec();
 data(u);
 cmd(0X01);
 t=t-48;
 v=v-48;
 u=u-48;
 int rs=t*100+v*10+u;
 if(rs>100)
 {
 int bln=rs-200;
 display("balance");
 cmd(0XC0);
 int m,n,o;
 m=(bln/100)+48;
 data(m);
 n=((bln%100)/10)+48;
 data(n);
 o=(bln%10)+48;
 data(o);
 cmd(0X01);
 char tt;char vv;char uu;
 tt=rec();
 data(tt);
 vv=rec();
 data(vv);
 uu=rec();
 data(uu);
 cmd(0X01);
 tt=tt-48;
 vv=vv-48;
 uu=uu-48;
 int rss=tt*100+vv*10+uu;
 if (rss==bln)
 {
 display("Move to Gate2");
	 cmd(0x01);
 } 
 else
 {
 display("pay balance");
 
 cmd(0X01);
 IO1SET=0x00EE0000;
delay1();
  IO1CLR=0x00FFFF00;
delay1();
 display("GATE2 OPEN");
 cmd(0X01);
 }
}
 else if(rs=200)
 {
 display("no balance");
 }
 }
 else 
 {
 display("Wrong Password");
 cmd(0X01);
 }
}

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

char rec()
{
while((U0LSR&0X01)==0);
delay();
return(U0RBR);
}
void cmd(int a)
{
IO0CLR=0xFFFFFFFF;
delay();
IO0SET=a<<16;
IO0SET=0X00002000;
delay();
IO0CLR=0x00002000;
delay();
}
void data( char b)
{
IO0CLR=0xFFFFFFFF;
delay();
IO0SET=b<<16;
IO0SET=0X00003000;
delay();
IO0CLR=0x00002000;
delay();
}
void display(const char *p)
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
for(int j=0;j<2000;j++);
}

void delay1()

{
for(int i=0;i<500;i++)
for(int j=0;j<6000;j++);
}


