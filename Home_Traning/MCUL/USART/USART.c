/*
 * USART.c
 *
 * Created: 15/12/2021 09:38:04 م
 *  Author: ascom
 */ 
#include "USART_CGF.h"
#include "USART.h"
#include "REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO.h"

void M_UsarIntInit(void){
	  M_PinMode(TX,OUTPUT);
	  M_PinMode(RX,INPUT);
	    UCSRC = 0b10000110;   // to select 8 bits for data bits
	    CLR_BIT(UCSRB,2);     // to select 8 bits for data bits
	    UBRRL=103;
		  /*Enable the re sever  */
		  SET_BIT(UCSRB,4);
		  /*Enable the Transmitter*/
		  SET_BIT(UCSRB,3);
		  /*Enable Interrupts */
		  /*RXCIE: RX Complete Interrupt Enable*/
		  SET_BIT(UCSRB,7);
		 /* Bit 6 – TXCIE: TX Complete Interrupt Enable*/
		  SET_BIT(UCSRB,6);
		/*  global*/ 
		  SET_BIT(SREG,7);
}
void M_UsartInit(void){
	/*this stable in send and reseve */
  M_PinMode(TX,OUTPUT);
  M_PinMode(RX,INPUT);
  /*This bit selects the UCSRC */
  UCSRC = 0b10000110;   // to select 8 bits for data bits
  CLR_BIT(UCSRB,2);     // to select 8 bits for data bits
  UBRRL=103;
  /*Enable the re sever  */
  SET_BIT(UCSRB,4);
  /*Enable the Transmitter*/
  SET_BIT(UCSRB,3);
}
void M_UsartTransmit(u8 Data_Transmit){
	/*wait*/
	while(GET_BIT(UCSRA,5)==0){ // كان في غلطه هنا 
		
	}
	UDR=Data_Transmit;
}
u8 M_UsartReceiver(void){
	u8 Data_Received=0 ;
	/*check if the data received*/
	while(GET_BIT(UCSRA,7)==0){
		
	}
	Data_Received=UDR; 
	return Data_Received ;
}
void M_UsartSendString(u8*String){
	u8 i=0 ;
	while(String[i]!='\0'){
		M_UsartTransmit(String[i]);
		i++ ;
	}
	
}