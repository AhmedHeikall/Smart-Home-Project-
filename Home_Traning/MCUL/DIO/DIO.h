/*
 * DIO.h
 *
 * Created: 17/11/2021 08:25:26 ص
 *  Author: ascom
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "STD_TYPES.h"
/*************PORT A ***************/

#define PA0		40
#define PA1		41
#define PA2		42
#define PA3		43
#define PA4		44
#define PA5		45
#define PA6		46
#define PA7		47

/*************PORT B ***************/

#define PB0		30
#define PB1		31
#define PB2		32
#define PB3		33
#define PB4		34
#define PB5		35
#define PB6		36
#define PB7		37

/*************PORT C ***************/

#define PC0		20
#define PC1		21
#define PC2		22
#define PC3		23
#define PC4		24
#define PC5		25
#define PC6		26
#define PC7		27

/*************PORT D ***************/

#define PD0		10
#define PD1		11
#define PD2		12
#define PD3		13
#define PD4		14
#define PD5		15
#define PD6		16
#define PD7		17

/***********PORT MODES **********/
#define  OUTPUT		1
#define  INPUT		0
/*******PORT STATUS ***********/
#define HIGH	1
#define LOW		0

 
/*function to control in the direction of the pin M this is in the MCUL */
/*take the pin and the statue needed */
void M_PinMode(u8,u8); 
/*FUNCTION TO WRITE ON THE PORT TO GIVE VOLTIGE OR NOT */
/*take the pin and the statue needed */
void M_PinWrite(u8,u8);
/*function to read the port */
u8 M_PinRead(u8);
void M_PinTog(u8);
/*void M_PortMode(u8);
void M_PortWrite(u8);*/

#endif /* DIO_H_ */