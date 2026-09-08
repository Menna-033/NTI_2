#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ADC2.h"

int main(void) {
	LCD_voidInit();
	ADC_voidInit();

	u16 Local_u16AdcValue = 0;
	u32 Local_u32VoltageMV = 0;

	while (1) {
		/* ????? ??? ???????? ???????? ?? PA0 */
		Local_u16AdcValue = ADC_u16ReadChannel(0);

		/* ???? ????? ???????? ???? */
		Local_u32VoltageMV = ((u32)Local_u16AdcValue * 5000UL) / 1024;

		/* ????? ??? ?????? */
		LCD_voidClear();
		LCD_voidSendString((const u8*)"Voltage:");
		LCD_voidSendNumber(Local_u32VoltageMV);
		LCD_voidSendString((const u8*)" mV");

		_delay_ms(1000);
	}

	return 0;
}