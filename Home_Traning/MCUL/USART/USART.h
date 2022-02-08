/*
 * USART.h
 *
 * Created: 15/12/2021 09:38:21 م
 *  Author: ascom
 */ 


#ifndef USART_H_
#define USART_H_
#include "STD_TYPES.h"
void M_M_UsarIntInit(void);
void M_UsartInit(void);
void M_UsartTransmit(u8);
u8 M_UsartReceiver(void);
void M_UsartSendString(u8*String);
#define Register_Select		7		//The URSEL must be one when writing the UCSRC.
#define USART_Mode_Select	0	   // Asynchronous Operation


#endif /* USART_H_ */