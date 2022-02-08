/*
 * I2C.c
 *
 * Created: 16/12/2021 07:59:37 م
 *  Author: ascom
 */ 
# define F_CPU 16000000UL
#include <util/delay.h>
#include "I2C_CFG.h"
#include "DIO.h"
#include "REG.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "BUZZER.h"
void M_I2cMasterInit(void){
		/*set clock frequency */
		CLR_BIT(TWSR,0);
		CLR_BIT(TWSR,1);
		//TWBR=0x07;
		TWBR = 0x48;
		/*Enable the i2c */
		SET_BIT(TWCR,2);
		//kk
		_delay_ms(100);
}
void M_I2cInit(void){
   #if I2C_MODE==MASTER_T
	/*set clock frequency */
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	 TWBR=0x0C;
	/*Enable the i2c */
	SET_BIT(TWCR,2);
	#elif I2C_MODE==MASTER_R
	/*set clock frequency */
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	 TWBR=2040;
	
	/*Enable the i2c */
	SET_BIT(TWCR,2);
	
	#elif I2C_MODE==SLAVE_R
	/*Set the bit of Stop and start condition*/
	
	CLR_BIT(TWCR,4);
	CLR_BIT(TWCR,5);
	/*Put the address of the slave here and the slave will compare it */
	TWAR=Slave_Address ;
	/*Active The ACK */
	SET_BIT(TWCR,6);
	/*Enable the i2c */
	SET_BIT(TWCR,2);
	#elif I2C_MODE==SLAVE_T
	/*Set the bit of Stop and start condition*/
	
	CLR_BIT(TWCR,4);
	CLR_BIT(TWCR,5);
	
	/*Put the address of the slave here and the slave will compare it */
	TWAR=(Slave_Address<<1)|(1) ;//select the general call
	/*Active The ACK */
	SET_BIT(TWCR,6);
	/*Enable the i2c */
	SET_BIT(TWCR,2);
	#endif 
}
void M_I2cStartCondition(void){

	/*clear the interrupt flag */
	SET_BIT(TWCR,7);
	/*Set the bit of start condition*/
	SET_BIT(TWCR,5);
	/*clear the bit of Stop condition*/
	CLR_BIT(TWCR,4);
	
	
	/*Wait To Done...Wait for the interrupt flag */
	while((GET_BIT(TWCR,7))!=1){
		
		
	}
	
	/*check for the status register TWSR*/
	while((TWSR&0xF8)!=(0x08)){
		 
	}
	

	/*Clear the bit of start condition*/
	//CLR_BIT(TWCR,5);//المشكله كانت هناااااااااااااااااااااااا
	_delay_ms(100);
	
}
void M_I2cStopCondition(void){
	/*clear the interrupt flag */
	SET_BIT(TWCR,7);
	/*Clear the bit of start condition*/
	CLR_BIT(TWCR,5);
	/*Set the bit of Stop condition*/
	SET_BIT(TWCR,4);

	//_delay_ms(100);
	
}
void M_I2cSendSlaveAddress_Write(u8 Address){
	TWDR=Address<<1;//لحد دلوقتي مهم تكون الاول 
	/*clear the bit of Stop condition*/
	CLR_BIT(TWCR,4);
	/*Clear the bit of start condition*/
	CLR_BIT(TWCR,5);
	/*clear the interrupt flag */
	SET_BIT(TWCR,7);
	
	/*Copy the address in the Data register to pass it */
	/*shift this because i send 7_Bit And need  the operation */
	
	
	/*Wait To Done...Wait for the interrupt flag */
	while((GET_BIT(TWCR,7))!=1){
		
	}
	
	/*SLA+W has been transmitted ACK has been received*/
	while((TWSR&0xF8)!=(0x18)){
		
	}
 
   _delay_ms(100);
	
	
}
void M_I2cSendSlaveAddress_Read(u8 Address){
	   /*shift this because i send 7_Bit And need  the operation */
	   TWDR=(Address<<1)|(1) ; // هنا لازم تكون دي ف الاول الترتيب مهم جداااااا
	   
	   
	/*clear the bit of Stop condition*/
	CLR_BIT(TWCR,4);
   /*clear the interrupt flag */
   SET_BIT(TWCR,7);
   /*Clear the bit of start condition*/
   CLR_BIT(TWCR,5);
   /*Copy the address in the Data register to pass it */

  
   /*Wait To Done...Wait for the interrupt flag */
   while((GET_BIT(TWCR,7))!=1){
   }
	
	/*SLA+R has been transmitted;ACK has been received*/
	while((TWSR&0xF8)!=(0x40)){
	}
	
	_delay_ms(100);
}
void M_I2cMasterSend_Data(u8 Data){
	/*Pass the Data to TWDR*/
	TWDR=Data;
	/*clear the bit of Stop condition*/
	CLR_BIT(TWCR,4);
	   /*Clear the bit of start condition*/
	   CLR_BIT(TWCR,5);
   /*clear the interrupt flag */
   SET_BIT(TWCR,7);

   
	
	/*Wait To Done...Wait for the interrupt flag */
	while((GET_BIT(TWCR,7))!=1){
	}
	
	/*Data has been transmitted ACK has been received*/
	while((TWSR&0xF8)!=(0x28)){
		
	}
	
	//_delay_ms(100);
}
u8 M_I2cMasterReceive_Data(void){
	
	
	/*Clear the bit of start condition*/
	CLR_BIT(TWCR,5);
	/*clear the bit of Stop condition*/
	CLR_BIT(TWCR,4);
	   
	/*clear the interrupt flag */
	SET_BIT(TWCR,7);
	
	
	/*Clear the bit of start condition*/
	//Data_received=TWDR;
	while((GET_BIT(TWCR,7))!=1){
		
	}
	
	/* Data byte has been received ACK has been returned*/
	while((TWSR&0xF8)!=(0x58)){// this is very important to use NACK here 
		
	}
	
/*while(1){
	H_BuzzerTwis();
	_delay_ms(500);
	H_BuzzerOff();
}*/
    u8 x =TWDR;
	return x;
	_delay_ms(100);
}

void M_I2cSlaveReceive_AddressWrite(void){
	/*clear the interrupt flag */
	SET_BIT(TWCR,7);
	
	
	while((GET_BIT(TWCR,7))!=1){
		
	}
	
	/*Address has been received ACK has been returned*/
	while((TWSR&0xF8)!=(0x60)){
	}
	
	/*Clear the bit of start condition*/
	//Data_received=TWDR;

}
void M_I2cSlaveReceive_AddressRead(void){
		/*clear the interrupt flag */
		SET_BIT(TWCR,7);
		
		while((GET_BIT(TWCR,7))!=1){
			
		}
		
		/*Address has been received ACK has been returned*/
		while((TWSR&0xF8)!=(0xA8)){
		}
		/*Clear the bit of start condition*/
		//Data_received=TWDR;
		
		//SET_BIT(TWCR,5);
}
void M_I2cSlaveSend_Data(u8 Slave_data){
		/*clear the interrupt flag */
		SET_BIT(TWCR,7);
		
		TWDR=Slave_data;
		
		
		while((GET_BIT(TWCR,7))!=1){
			
		}
		
		/*Address has been received ACK has been returned*/
		while((TWSR&0xF8)!=(0xB8)){
		}
		/*Clear the bit of start condition*/
		//Data_received=TWDR;
		
		//SET_BIT(TWCR,5);
}
void M_I2cRepeatedStCondition(void){
	
	SET_BIT(TWCR,5);//مهم جدا تكون الاول 
		/*clear the bit of Stop condition*/
	CLR_BIT(TWCR,4);
	/*clear the interrupt flag */
	SET_BIT(TWCR,7);
	

    while((GET_BIT(TWCR,7))!=1){
    }
 
	/*Address has been received ACK has been returned*/
	while((TWSR&0xF8)!=(0x10)){
		
	}
	
	
	/*Clear the bit of start condition*/
	//Data_received=TWDR;
	_delay_ms(100);
	
}