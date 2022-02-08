/*
 * LCD.c
 *
 * Created: 18/11/2021 07:41:56 م
 *  Author: ascom
 */ 
#include "LCD_CFG.h"
#include "DIO.h"
# define F_CPU 16000000UL
#include <util/delay.h>
void H_Lcd_Write_Cmd(u8 CMD){
	LCD_PORT=(LCD_PORT&0X0F)|(CMD&0XF0);
	M_PinWrite(LCD_RS,LOW);
	M_PinWrite(LCD_RW,LOW);
	M_PinWrite(LCD_EN,HIGH);
	_delay_ms(5);
	M_PinWrite(LCD_EN,LOW);
	_delay_ms(5);
	LCD_PORT=(LCD_PORT&0X0F)|(CMD<<4);
	M_PinWrite(LCD_RS,LOW);
	M_PinWrite(LCD_RW,LOW);
	M_PinWrite(LCD_EN,HIGH);
	_delay_ms(5);
	M_PinWrite(LCD_EN,LOW);
	_delay_ms(5);
}
void H_LcdInit(void){
	LCD_Direction=0XFF;
	M_PinMode(LCD_RS,OUTPUT);//لازم التاخير !!!!!
	_delay_ms(1000);
	M_PinMode(LCD_RW,OUTPUT);
	_delay_ms(100);
	M_PinMode(LCD_EN,OUTPUT);
	_delay_ms(100);
	H_Lcd_Write_Cmd(_4_BIT_MODE);
	_delay_ms(100);
	H_Lcd_Write_Cmd(0x32);//??????
	_delay_ms(100);
	
	H_Lcd_Write_Cmd(0x28);//??????
	_delay_ms(100);
	H_Lcd_Write_Cmd(DISPLAY_ON);
	_delay_ms(100);
	H_Lcd_Write_Cmd(CLEAR_SCREEN);
	_delay_ms(100);
	H_Lcd_Write_Cmd(SHIFT_CURSOR_r);
	_delay_ms(100);
}

void H_Lcd_Write_Data(u8 DATA){
	LCD_PORT=(LCD_PORT&0X0F)|(DATA&0XF0);
	M_PinWrite(LCD_RS,HIGH);
	M_PinWrite(LCD_RW,LOW);
	M_PinWrite(LCD_EN,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN,LOW);

	LCD_PORT=(LCD_PORT&0X0F)|(DATA<<4);
	M_PinWrite(LCD_RS,HIGH);
	M_PinWrite(LCD_RW,LOW);
	M_PinWrite(LCD_EN,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN,LOW);
	
}

void H_Lcd_Clear(void){
	H_Lcd_Write_Cmd(CLEAR_SCREEN);
	
}
void H_Lcd_Write_String(u8*ptr){
	u8 i=0;
	for (i=0;*(ptr+i)!='\0';i++)
	{
		H_Lcd_Write_Data(*(ptr+i));
	}
	
}
void H_Lcd_shift_data(){
H_Lcd_Write_Cmd(Shift_data_to_right_side);
H_Lcd_Write_Cmd(go_to_first_line_position_0);
//H_Lcd_Write_Cmd(0x18);
//	Shift complete data to left side

}
void H_LcdInteger(u32 Number_Int){
	/*u32 rem=0;
	while(Number_Int!=0){
		rem=rem*10+Number_Int%10;
		Number_Int=Number_Int/10; 
		
	}
	Number_Int=rem;
	rem=0;
	while(Number_Int!=0){
		rem=48+Number_Int%10; // convert the number into ascii 
		// ده عشان ال سي دي مش بتاخد مني غير الاسكي ف هحول الرقم وبعدين هي هتاخده تحوله لاسكي تاتني
		H_Lcd_Write_Data(rem);
		Number_Int=Number_Int/10;
		
	}*/
	u8 i =0 ;
	u8 arr[16];
	u8 rem =0 ;
	u8 j=0 ;
	u8 temp=0 ;
	while(Number_Int!=0){
		rem=Number_Int%10+48 ;
		arr[i]=rem ;
		Number_Int=Number_Int/10 ;
		++i ;
	}
	temp=i ;
	for (j=0 ;j<i;++j)
	{
		H_Lcd_Write_Data(arr[temp-1]);
		--temp;
	}
	i=0 ;
}

void H_Lcd_Write_Char(u8 chara){
	H_Lcd_Write_Data(chara);
}
void H_LcdFirstLine(void){
		H_Lcd_Write_Cmd(0x80);
		
		
}
void H_LcdSecondLine(void){
	H_Lcd_Write_Cmd(0xC0 );
}
void H_CoursorIncrement(void){
	H_Lcd_Write_Cmd(0x06 );
} 