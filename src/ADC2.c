#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ADC2.h"

/* ????? ????? ??????? ????? ??? LCD */
#define LCD_DATA_PORT    DPORTB
#define LCD_CTRL_PORT    DPORTC
#define LCD_RS_PIN       PIN0
#define LCD_RW_PIN       PIN1
#define LCD_EN_PIN       PIN2

void LCD_voidSendCommand(u8 Copy_u8Command) {
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Command);
	
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

void LCD_voidSendData(u8 Copy_u8Data) {
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Data);
	
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

void LCD_voidInit(void) {
	DIO_voidSetPortDirection(LCD_DATA_PORT, 0xFF); // OUTPUT
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT);

	_delay_ms(40);
	LCD_voidSendCommand(0x38); // 8-bit mode, 2 lines, 5x7 font
	LCD_voidSendCommand(0x0C); // Display ON, Cursor OFF
	LCD_voidSendCommand(0x01); // Clear Display
	_delay_ms(2);
}

void LCD_voidSendString(const u8* Copy_pu8String) {
	u8 i = 0;
	while (Copy_pu8String[i] != '\0') {
		LCD_voidSendData(Copy_pu8String[i]);
		i++;
	}
}

void LCD_voidSendNumber(u32 Copy_u32Number) {
	u8 arr[10];
	s8 i = 0;
	if (Copy_u32Number == 0) {
		LCD_voidSendData('0');
		return;
	}
	while (Copy_u32Number > 0) {
		arr[i] = (Copy_u32Number % 10) + '0';
		Copy_u32Number /= 10;
		i++;
	}
	for (i = i - 1; i >= 0; i--) {
		LCD_voidSendData(arr[i]);
	}
}

void LCD_voidClear(void) {
	LCD_voidSendCommand(0x01);
	_delay_ms(2);
}