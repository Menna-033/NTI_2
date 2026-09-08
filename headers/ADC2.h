#ifndef ADC2_H
#define ADC2_H

#include "STD_TYPES.h"

void LCD_voidInit(void);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendString(const u8* Copy_pu8String);
void LCD_voidSendNumber(u32 Copy_u32Number);
void LCD_voidClear(void);

#endif