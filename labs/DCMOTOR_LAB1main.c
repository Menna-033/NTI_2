
#include <avr/io.h>
#include "DIO.h"
#include <util/delay.h>
#define F_CPU 1000000UL

int main(void)
{
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
    while (1) 
    {
		DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
		_delay_ms(5000);
		DIO_voidSetPinValue(DPORTC,PIN0,LOW);
		_delay_ms(5000);
    }
}
