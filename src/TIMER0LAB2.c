#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "TIMER0LAB2.h"

void TIMER0_voidInitCTC(void) {

	set_bit(TCCR0, WGM01);
	clr_bit(TCCR0, WGM00);

	set_bit(TCCR0, CS02);
	clr_bit(TCCR0, CS01);
	set_bit(TCCR0, CS00);

	set_bit(TIMSK, OCIE0);


	sei();
}

void TIMER0_voidSetOCR0(u8 Copy_u8Value) {
	OCR0 = Copy_u8Value;
}


ISR(TIMER0_COMP_vect) {
	static u8 Local_u8State = LOW;
	Local_u8State = !Local_u8State;
	
	DIO_voidSetPinValue(DPORTC, PIN0, Local_u8State);
}
