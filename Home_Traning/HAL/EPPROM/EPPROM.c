/*
 * EPPROM.c
 *
 * Created: 20/12/2021 05:55:55 م
 *  Author: ascom
 */ 
#include "EPPROM.h"
#include "I2C.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "BUZZER.h"
# define F_CPU 16000000UL
#include <util/delay.h>
void H_EppromInit(void){
	M_I2cMasterInit();
}
void H_EppromWrite(u8 data,u8 address){
	// u8 x=address>>1 ;
	
	M_I2cStartCondition();

	M_I2cSendSlaveAddress_Write(0x50);
	
    M_I2cMasterSend_Data(address);
		
	
	M_I2cMasterSend_Data(0x50);
	
	M_I2cStopCondition();
	_delay_ms(50);
	//معظم المشاكل هنا ف جزء الديلاي  
	//لازم هنا يكون في delay
		
}

u8 H_EppromRead(u8 address){
	
		M_I2cStartCondition();
	
		
		M_I2cSendSlaveAddress_Write(0x50);//مهم جدا الترتيب لازم الاول تكون دي ف الفانكشن بتاعهتا 
		
		M_I2cMasterSend_Data(address);
		
		M_I2cRepeatedStCondition();//مهم جدا هنا لازم اعمل ستارت الاول ..اول حاجه خالص 
	
		M_I2cSendSlaveAddress_Read(0x50);
		
		 /*	while(1){
			 	H_BuzzerTwis();
			 	_delay_ms(500);
			 	H_BuzzerOff();
		 	}*/
		//M_I2cMasterSend_Data(1);
		
		u8 x=M_I2cMasterReceive_Data();//هنا هترق معايا لو كنت عايز استلم بايت واحد ولا لا هتفرق ف الرقم ال هتاكد منه الاكنلوج
		M_I2cStopCondition();
		return  x ;
}
