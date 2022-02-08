/*
 * keypad.c
 *
 * Created: 25/11/2021 01:43:21 ص
 *  Author: ascom
 */

# define F_CPU 16000000UL
#include <util/delay.h> 
#include "KEYPAD_CFG.h"
#include "keypad.h"
extern u8 Number_Of_PS ;
  u8 Kaypad_symbols[4][4]={{'7','8','9','/'},
                           {'4','5','6','*'},
                           {'1','2','3','-'},
                           {'C','0','=','+'}};
	  
void KeypadInit(void){
	/*make the first 4 pins output */
	M_PinMode(KAY_PAD_ROW_PIN_1,OUTPUT);
	M_PinMode(KAY_PAD_ROW_PIN_2,OUTPUT);
	M_PinMode(KAY_PAD_ROW_PIN_3,OUTPUT);
	M_PinMode(KAY_PAD_ROW_PIN_4,OUTPUT);
	/*make it by default high */
	M_PinWrite(KAY_PAD_ROW_PIN_1,HIGH);
	M_PinWrite(KAY_PAD_ROW_PIN_2,HIGH);
	M_PinWrite(KAY_PAD_ROW_PIN_3,HIGH);
	M_PinWrite(KAY_PAD_ROW_PIN_4,HIGH);
	/*make the second is inputs to read from them*/
	M_PinMode(KAY_PAD_COL_PIN_1,INPUT);
	M_PinMode(KAY_PAD_COL_PIN_2,INPUT);
	M_PinMode(KAY_PAD_COL_PIN_3,INPUT);
	M_PinMode(KAY_PAD_COL_PIN_4,INPUT);
	/*active the internal pull up resistor by put 1 in port register
	to make the buttons see 1 in the normal mode */ 
	M_PinWrite(KAY_PAD_COL_PIN_1,HIGH);
	M_PinWrite(KAY_PAD_COL_PIN_2,HIGH);
	M_PinWrite(KAY_PAD_COL_PIN_3,HIGH);
	M_PinWrite(KAY_PAD_COL_PIN_4,HIGH);
}

u8 KeypadRead(void){
	
	u8 row=0;
	u8 col=0;
	u8 flag=0;
	u8 symbol_returned='a';
	u8 temp =0 ;
	
	for ( row =0 ;row<4;row++)
	{
		M_PinWrite((row+KAY_PAD_ROW_PIN_1),LOW);
		for (col=0;col<4;col++)
		{
			temp=M_PinRead(KAY_PAD_COL_PIN_1+col);
			if (temp==pressed)
			{
					symbol_returned=Kaypad_symbols[row][col];
			flag=1;
				while(temp==pressed){
					temp=M_PinRead(KAY_PAD_COL_PIN_1+col);	//kan fi 3'alta hina da kda 7L mo4kilt el bouncing 
					
				}
				if (flag==1)
				{
					break;
				}
			}  
			
		}
		M_PinWrite((row+KAY_PAD_ROW_PIN_1),HIGH);
		if (flag==1)
		{
			flag=0 ;
			break;
		}
	}
	
	
	return symbol_returned ;
}

u8 Password (u8 *PS){
		u8 returned_value =1 ;
		/*user passwords */
		u8 User_One_Ps[3]="123";
		u8 User_2_Ps[3]="456";
		u8 User_3_Ps[3]="789";
		for(u8 i =0 ;i<3;++i){
			if(Number_Of_PS !=3){
				returned_value =0 ;
				break;
			}
			  if (User_One_Ps[i]!=PS[i]) { //i have  problem here that not valid to use && (Number_Of_PS !=3)
				returned_value =0 ;
				break;
			}
		}

			if (returned_value ==0 )
			{
			for(u8 i =0 ;i<3;++i){
					     
	        if(User_2_Ps[i]!=PS[i]){
			 returned_value =2;
			 break;
				        }				   
	               }
				}	
			if (returned_value ==2)
				{
				for(u8 i =0 ;i<3;++i){
				 if(User_3_Ps[i]!=PS[i]){
				 returned_value=3;
				 break;
								  }
							    }		
		}
		return returned_value;
	}
