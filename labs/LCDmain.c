
#include <avr/io.h>
#include "LCD.h"
#include "util/delay.h"
#define  F_CPU 8000000UL
int main(void)
{
    LCD_init();
	LCD_SendCommand(0x80+2);
	LCD_SendString((u8*)" MENNA YASSER");
    while (1) 
    {
    }
}
