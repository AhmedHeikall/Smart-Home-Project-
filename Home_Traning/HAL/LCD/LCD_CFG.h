/*
 * LCD_CFG.h
 *
 * Created: 18/11/2021 07:41:40 م
 *  Author: ascom
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "DIO.h"
#include "REG.h"
#define LCD_Direction   DDRA 
#define LCD_PORT	    PORTA
#define LCD_D0	        PA0
#define LCD_D1	        PA1
#define LCD_D2	        PA2
#define LCD_D3	        PA3
#define LCD_D4	        PA4 
#define LCD_D5	        PA5
#define LCD_D6	        PA6
#define LCD_D7	        PA7
#define LCD_RS			PB1
#define LCD_RW			PB2
#define LCD_EN			PB0
	
#define _8_BIT_MODE		0x38
#define _4_BIT_MODE		0x33
#define DISPLAY_ON		0X0C
#define CLEAR_SCREEN	0x01
#define SHIFT_CURSOR_r	0X06
#define Shift_data_to_right_side	0x1C
 
#define  go_to_first_line_position_0  0x80 








#endif /* LCD_CFG_H_ */