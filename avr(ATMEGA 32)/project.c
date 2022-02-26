/*
 * project.c
 *
 * Created: 06-01-2022 11:18:57 AM
 *  Author: USER
 */ 


#include <avr/io.h>
#include <util/delay.h>
void cmd(int a);
void data( char b);
void display(const char *p);
char key();
char rec();

int main(void)

{
  
  DDRC=0xF0;
  DDRD=0x0C;
  DDRB=0xFF;
  DDRA=0xFF;
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
   if((PIND&0x80)==0)
{
PORTB=0XDF;
_delay_ms(500);
display("GATE1 OPEN");
cmd(0X01);
display("MOVE TO TOLL");
cmd(0X01);
PORTB=0X00;
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
 
 UCSRA=0X00;
UCSRB=0X18;
UCSRC=0X06;
UBRRL=0X33;
UBRRH=0X00;
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
 PORTB=0X0E;
  _delay_ms(500);
 display("Move to Gate2");
 cmd(0x01);
 
 } 
 else
 {
 display("pay balance");
 
 cmd(0X01);
 PORTB=0X0E;
  _delay_ms(500);
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
else if((PIND&0x40)==0)
{
PORTB=0X05;
_delay_ms(500);
display("GATE2 OPEN");
cmd(0X01);
display("MOVE TO TOLL");
cmd(0X01);
PORTB=0X00;
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
UCSRA=0x00;
UCSRB=0x18;
UCSRC=0X06;
UBRRL=0X33;
UBRRH=0X00;
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
 } 
 else
 {
 display("pay balance");
 
 cmd(0X01);
 PORTB=0XE0;
  _delay_ms(500);
 display("GATE2 OPEN");
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
else if((PIND&0x20)==0)
{
PORTB=0X05;
_delay_ms(500);
display("GATE3 OPEN");
cmd(0X01);
display("MOVE TO TOLL");
cmd(0X01);
PORTB=0X00;
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
UCSRA=0x00;
UCSRB=0x18;
UCSRC=0X06;
UBRRL=0X33;
UBRRH=0X00;
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
 } 
 else
 {
 display("pay balance");
 
 cmd(0X01);
 PORTB=0XE0;
  _delay_ms(500);
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

char key()
{
	int e;
	while(1)
	{			
		PORTC=0x7F;
		e=PINC&0x0F;
		switch(e)
		{
			case 0x07:return('1');break;
			case 0x0B:return('2');break;
			case 0x0D:return('3');break;
			case 0x0E:return('4');break;
		}
		PORTC=0xBF;
		e=PINC&0x0F;
		switch(e)
		{			
			case 0x07:return('5');break;
			case 0x0B:return('6');break;
			case 0x0D:return('7');break;
			case 0x0E:return('8');break;			
        
    }
	PORTC=0xDF;
		e=PINC&0x0F;
		switch(e)
		{			
			case 0x07:return('9');break;
			case 0x0B:return('A');break;
			case 0x0D:return('B');break;
			case 0x0E:return('C');break;			
        
    }
	PORTC=0xEF;
		e=PINC&0x0F;
		switch(e)
		{			
			case 0x07:return('D');break;
			case 0x0B:return('E');break;
			case 0x0D:return('F');break;
			case 0x0E:return('G');break;			
        
    }
}
}
char rec()
{
while((UCSRA&0x80)==0);
return(UDR);
_delay_ms(500);
}
void cmd (int a)
  {

    PORTA=a;
  PORTD=0x08;
  _delay_ms(5000);
  PORTD=0x00;
  }
  void data( char b)
  {
    PORTA=b;
    PORTD=0x0C;
    _delay_ms(5000);
    PORTD=0x04;
  }  
void display(const char *p)
{
while(*p!='\0')
{
data(*p);
p++;
}
}
