#include "DIO.h"

int main(void) {
	
	DIO_voidSetPortDirection(DIO_PORTA, 0x00);
	DIO_voidSetPortValue(DIO_PORTA, 0xFF); 

	
	DIO_voidSetPinDirection(DIO_PORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN1, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN2, OUTPUT);

	while (1) {
	
		if (DIO_u8GetPinValue(DIO_PORTA, PIN7) == LOW) {
			DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
			DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
			DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH);
		}
		else {
			
			if (DIO_u8GetPinValue(DIO_PORTA, PIN0) == LOW) DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
			else DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);

			
			if (DIO_u8GetPinValue(DIO_PORTA, PIN1) == LOW) DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
			else DIO_voidSetPinValue(DIO_PORTC, PIN1, LOW);

			
			if (DIO_u8GetPinValue(DIO_PORTA, PIN2) == LOW) DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH);
			else DIO_voidSetPinValue(DIO_PORTC, PIN2, LOW);
		}
	}
	return 0;
}
