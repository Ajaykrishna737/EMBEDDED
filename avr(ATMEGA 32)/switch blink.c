/*
 * switch_blink.c
 *
 * Created: 10-12-2021 10:38:32 AM
 *  Author: USER
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0xFF;
	DDRC=0x00;
    while(1)
    {
		
              if ((PINC&0x01)==0)
				  
		{
			
		PORTD=0xFF;
		_delay_ms(500);
		PORTD=0x00;
		_delay_ms(500);
		}
		
		 if ((PINC&0x02)==0)
		 {
			
		PORTD=0x55;
		_delay_ms(500);
		PORTD=0xAA;
		_delay_ms(500);
		}
		 if ((PINC&0x04)==0)
				  
		{
			
		PORTD=0x0F;
		_delay_ms(500);
		PORTD=0xF0;
		_delay_ms(500);
		}	
		 
		if ((PINC&0x08)==0)				
		 
		 {
			 PORTD=0x01;
		_delay_ms(500);
		for (int i=0;i<8;i++)
		{
			PORTD=PORTD<<1;
			_delay_ms(500);
		}
		}
		if ((PINC&0x10)==0)				
		 
		 {
			 PORTD=0x80;
		_delay_ms(500);
		for (int i=0;i<8;i++)
		{
			PORTD=PORTD>>1;
			_delay_ms(500);
		}
		}	
			      
    }
}