#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ADC3.h"

#define GREEN_LED_PIN   PIN0
#define YELLOW_LED_PIN  PIN1
#define RED_LED_PIN     PIN2
#define BUZZER_PIN      PIN3

int main(void) {
	ADC_voidInit();

	DIO_voidSetPinDirection(DPORTC, GREEN_LED_PIN, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, YELLOW_LED_PIN, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, RED_LED_PIN, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, BUZZER_PIN, OUTPUT);

	u16 Local_u16AdcValue = 0;
	u16 Local_u16Temp = 0;

	while (1) {
		Local_u16AdcValue = ADC_u16ReadChannel(0);

		
		Local_u16Temp = (u16)(((u32)Local_u16AdcValue * 500UL) / 1024);

		/* ?????? ??????: ???? ??????? ??? ?? 20 °C */
		if (Local_u16Temp < 20) {
			DIO_voidSetPinValue(DPORTC, GREEN_LED_PIN, HIGH);
			DIO_voidSetPinValue(DPORTC, YELLOW_LED_PIN, LOW);
			DIO_voidSetPinValue(DPORTC, RED_LED_PIN, LOW);
			DIO_voidSetPinValue(DPORTC, BUZZER_PIN, LOW);
		}
		/* ?????? ???????: ???? ??????? ??? 20 °C ? 40 °C */
		else if (Local_u16Temp >= 20 && Local_u16Temp <= 40) {
			DIO_voidSetPinValue(DPORTC, GREEN_LED_PIN, LOW);
			DIO_voidSetPinValue(DPORTC, YELLOW_LED_PIN, HIGH);
			DIO_voidSetPinValue(DPORTC, RED_LED_PIN, LOW);
			DIO_voidSetPinValue(DPORTC, BUZZER_PIN, LOW);
		}
		/* ?????? ???????: ???? ??????? ???? ?? 40 °C (???) */
		else {
			DIO_voidSetPinValue(DPORTC, GREEN_LED_PIN, LOW);
			DIO_voidSetPinValue(DPORTC, YELLOW_LED_PIN, LOW);
			DIO_voidSetPinValue(DPORTC, RED_LED_PIN, HIGH);
			DIO_voidSetPinValue(DPORTC, BUZZER_PIN, HIGH);
		}

		_delay_ms(200);
	}

	return 0;
}