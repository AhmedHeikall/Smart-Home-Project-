/*
 * keypad.h
 *
 * Created: 25/11/2021 01:43:40 ص
 *  Author: ascom
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STD_TYPES.h"
void KeypadInit(void);
u8 KeypadRead(void);
u8 Password (u8 *PS);

#define pressed  0 
/*		     H_Lcd_Clear();
H_Lcd_Write_String("Continue ?");
u8 Replay=KeypadRead();
if (flag==1 || Replay==1)

{
H_Lcd_Clear();
H_Lcd_Write_String("Welcome ");
H_LcdSecondLine();

_delay_ms(1500);
H_Lcd_Clear();
H_Lcd_Write_String("air open ");
H_LcdSecondLine();
H_Lcd_Write_String("Enter + ");
_delay_ms(1500);
H_Lcd_Clear();
H_Lcd_Write_String("air Close ");
H_LcdSecondLine();
H_Lcd_Write_String("Enter - ");
_delay_ms(1500);
H_Lcd_Clear();
H_Lcd_Write_String("led0 on ");
H_LcdSecondLine();
H_Lcd_Write_String("Enter 0 ");
_delay_ms(1500);
H_Lcd_Clear();
H_Lcd_Write_String("led 1 run ");
H_LcdSecondLine();
H_Lcd_Write_String("Enter 1 ");
_delay_ms(1500);
H_Lcd_Clear();
H_Lcd_Write_String("led 2 run ");
H_LcdSecondLine();
H_Lcd_Write_String("Enter 2 ");
_delay_ms(1500);
H_Lcd_Clear();
H_Lcd_Write_String("led 3 run ");
H_LcdSecondLine();
H_Lcd_Write_String("Enter 3 ");
_delay_ms(1500);
H_Lcd_Clear();
H_Lcd_Write_String("led 4 run ");
H_LcdSecondLine();
H_Lcd_Write_String("Enter 4 ");
_delay_ms(1500);
H_Lcd_Clear();
H_Lcd_Write_String("led 5 run ");
H_LcdSecondLine();
H_Lcd_Write_String("Enter 5 ");
}
									 /*
									  switch(User_Selection)
									  {
										  case '+':
										  //door Code
										  M_UsartSendString("\r\nAdmin !!\r\n  The air conditioning has been turned on\r\n");
										  break;

										  case '-':
										  M_UsartSendString("\r\nAdmin !!\r\n  The air conditioning has been turned OFF\r\n");
										  //close the door
										  break;

										  case '0':
										  M_UsartSendString("\r\nAdmin !!\r\n  The Led0  has been turned on\r\n");
										
										  break;

										  case '1':
										   M_UsartSendString("\r\nAdmin !!\r\n  The Led1  has been turned on\r\n");
										  break;
										  
										  
										  case '2':
										   M_UsartSendString("\r\nAdmin !!\r\n  The Led2  has been turned on\r\n");
										  break;
										  
										  
										  case '3':
										   M_UsartSendString("\r\nAdmin !!\r\n  The Led3  has been turned on\r\n");
										  break;
										  case '4':
										   M_UsartSendString("\r\nAdmin !!\r\n  The Led4  has been turned on\r\n");
										   break;
										   case '5':
										   M_UsartSendString("\r\nAdmin !!\r\n  The Led5  has been turned on\r\n");
										    break;
										  
										  
										  
									  }
*/


#endif /* KEYPAD_H_ */