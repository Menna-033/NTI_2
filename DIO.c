#include <avr/io.h>
#include "DIO.h"

void DIO_voidSetPinDirection(u8 PortId, u8 PinId, u8 Direction) {
	if (Direction == OUTPUT) {
		switch(PortId) {
			case DIO_PORTA: SET_BIT(DDRA, PinId); break;
			case DIO_PORTB: SET_BIT(DDRB, PinId); break;
			case DIO_PORTC: SET_BIT(DDRC, PinId); break;
			case DIO_PORTD: SET_BIT(DDRD, PinId); break;
		}
		} else {
		switch(PortId) {
			case DIO_PORTA: CLR_BIT(DDRA, PinId); break;
			case DIO_PORTB: CLR_BIT(DDRB, PinId); break;
			case DIO_PORTC: CLR_BIT(DDRC, PinId); break;
			case DIO_PORTD: CLR_BIT(DDRD, PinId); break;
		}
	}
}

void DIO_voidSetPinValue(u8 PortId, u8 PinId, u8 Value) {
	if (Value == HIGH) {
		switch(PortId) {
			case DIO_PORTA: SET_BIT(PORTA, PinId); break;
			case DIO_PORTB: SET_BIT(PORTB, PinId); break;
			case DIO_PORTC: SET_BIT(PORTC, PinId); break;
			case DIO_PORTD: SET_BIT(PORTD, PinId); break;
		}
		} else {
		switch(PortId) {
			case DIO_PORTA: CLR_BIT(PORTA, PinId); break;
			case DIO_PORTB: CLR_BIT(PORTB, PinId); break;
			case DIO_PORTC: CLR_BIT(PORTC, PinId); break;
			case DIO_PORTD: CLR_BIT(PORTD, PinId); break;
		}
	}
}

u8 DIO_u8GetPinValue(u8 PortId, u8 PinId) {
	u8 Result = LOW;
	switch(PortId) {
		case DIO_PORTA: Result = GET_BIT(PINA, PinId); break;
		case DIO_PORTB: Result = GET_BIT(PINB, PinId); break;
		case DIO_PORTC: Result = GET_BIT(PINC, PinId); break;
		case DIO_PORTD: Result = GET_BIT(PIND, PinId); break;
	}
	return Result;
}

void DIO_voidSetPortDirection(u8 PortId, u8 Direction) {
	switch(PortId) {
		case DIO_PORTA: DDRA = Direction; break;
		case DIO_PORTB: DDRB = Direction; break;
		case DIO_PORTC: DDRC = Direction; break;
		case DIO_PORTD: DDRD = Direction; break;
	}
}

void DIO_voidSetPortValue(u8 PortId, u8 Value) {
	switch(PortId) {
		case DIO_PORTA: PORTA = Value; break;
		case DIO_PORTB: PORTB = Value; break;
		case DIO_PORTC: PORTC = Value; break;
		case DIO_PORTD: PORTD = Value; break;
	}
}
