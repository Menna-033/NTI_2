
#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0b00000001;
	PORTA =  0b00000010;
	
	
    while (1) 
    {
		
		if ((PINA & 0b00000010) == 0)
		{
			PORTA =  0b00000011 ;
		}else {
			PORTA =  0b00000010 ;
		}
    }
}

