/*
 * LCD.h
 *
 * Created: 18/11/2021 07:41:20 م
 *  Author: ascom
 */ 


#ifndef LCD_H_
#define LCD_H_

void H_LcdInit(void);
void H_Lcd_Write_Cmd(u8);
void H_Lcd_Write_Char(u8);
void H_Lcd_Write_Data(u8);
void H_Lcd_Clear(void);
void H_Lcd_Write_String(u8*ptr);
void H_Lcd_shift_data();
void H_LcdInteger(u32);
void H_LcdFirstLine(void);
void H_LcdSecondLine(void);
void H_CoursorIncrement(void);
#endif /* LCD_H_ */