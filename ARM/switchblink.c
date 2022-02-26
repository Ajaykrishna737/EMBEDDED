 #include<lpc21xx.h>
 void delay();
 void main()
 {
 IO0DIR=0XFFFFFFFF;
 IO1DIR=0x00000000;
 while(1)
 {
 if((IO1PIN&0x80000000)==0)
 {
int  a=0x00000001;
 IO0SET=a;
 delay();
 IO0CLR=a;
 delay();
 for(int i=0;i<32;i++)
 {
 a=a<<1;
 
 IO0SET=a;
 delay();
 IO0CLR= a;
 delay();
 }
 }
 if((IO1PIN&0x20000000)==0)
 {
 IO0SET=0x00FF00FF;
 delay();
 IO0CLR=0xFFFFFFFF;
 delay();
 IO0SET=0xFF00FF00;
 delay();
 IO0CLR=0xFFFFFFFF;
 delay();
 }
 if((IO1PIN&0x40000000)==0)
 {
 IO0SET=0x55555555;
 delay();
 IO0CLR=0xFFFFFFFF;
 delay();
 IO0SET=0xaaaaaaaa;
 delay();
 IO0CLR=0xFFFFFFFF;
 delay();
 }
  
 
 }
 }
 void delay()
 
 {
 for(int i=0;i<500;i++)
 for(int j=0;j<500;j++);
 }
 