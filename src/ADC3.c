#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC3.h"

void ADC_voidInit(void) {
	set_bit(ADMUX, REFS0);
	clr_bit(ADMUX, REFS1);

	set_bit(ADCSRA, ADEN);

	set_bit(ADCSRA, ADPS2);
	set_bit(ADCSRA, ADPS1);
	set_bit(ADCSRA, ADPS0);
}

u16 ADC_u16ReadChannel(u8 Copy_u8Channel) {

	ADMUX = (ADMUX & 0xE0) | (Copy_u8Channel & 0x07);

	set_bit(ADCSRA, ADSC);

	while (get_bit(ADCSRA, ADSC) == 1);

	return ADC;
}