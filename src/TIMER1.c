#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1.h"

void TIMER1_voidInitServo(void) {

	set_bit(TCCR1A, WGM11);
	clr_bit(TCCR1A, WGM10);
	set_bit(TCCR1B, WGM13);
	set_bit(TCCR1B, WGM12);


	set_bit(TCCR1A, COM1A1);
	clr_bit(TCCR1A, COM1A0);

	ICR1 = 4999;

	clr_bit(TCCR1B, CS12);
	set_bit(TCCR1B, CS11);
	set_bit(TCCR1B, CS10);
}

void TIMER1_voidSetAngle(u8 Copy_u8Angle) {
	if (Copy_u8Angle <= 180) {

		u16 Local_u16OcrValue = 250 + (((u32)Copy_u8Angle * 250) / 180);
		OCR1A = Local_u16OcrValue;
	}
}