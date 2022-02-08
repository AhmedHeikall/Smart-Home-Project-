/*
 * REG.h
 *
 * Created: 8/29/2021 12:50:48 PM
 *  Author: dell
 */ 


#ifndef REG_H_
#define REG_H_

#include "STD_TYPES.h"

/*************** DIO_REGISTERS *************/

#define PORTA      (*((volatile u8*)0x3B))
#define DDRA       (*((volatile u8*)0x3A))
#define PINA       (*((volatile u8*)0x39))

#define PORTB      (*((volatile u8*)0x38))
#define DDRB       (*((volatile u8*)0x37))
#define PINB       (*((volatile u8*)0x36))

#define PORTC      (*((volatile u8*)0x35))
#define DDRC       (*((volatile u8*)0x34))
#define PINC       (*((volatile u8*)0x33))

#define PORTD      (*((volatile u8*)0x32))
#define DDRD       (*((volatile u8*)0x31))
#define PIND       (*((volatile u8*)0x30))
/************INTERRUPT REGISTERS***********/
#define SREG      (*((volatile u8*)0x5F))
#define GICR      (*((volatile u8*)0x5B))
#define GIFR      (*((volatile u8*)0x5A))
#define MCUCR     (*((volatile u8*)0x55))
#define MCUCSR    (*((volatile u8*)0x54))
/************ADC REGISTERS*****************/
#define ADMUX		(*((volatile u8*)0x27))
#define ADCSRA		(*((volatile u8*)0x26))
#define ADCL		(*((volatile u8*)0x24))
#define ADCH		(*((volatile u8*)0x25))
#define ADCLVALUE	(*((volatile u16*)0x24))
/***********TIMER REGISTER******************/
#define TCCR0		(*((volatile u8*)0x53))
#define TCNT0		(*((volatile u8*)0x52))
#define TIFR		(*((volatile u8*)0x58))
#define TIMSK		(*((volatile u8*)0x59)) 
#define OCR0		(*((volatile u8*)0x5C)) 

#define TCCR2		(*((volatile u8*)0x45))
#define TCNT2		(*((volatile u8*)0x44))
#define OCR2		(*((volatile u8*)0x43)) 


/**************_TIMER_1_REGISTERS_************/

#define TCCR1A      (*((volatile u8*)0x4F))
#define TCCR1B      (*((volatile u8*)0x4E))
#define OCR1A       (*((volatile u16*)0x4A))
#define ICR1        (*((volatile u16*)0x46))
/*************USART REGESTER****************/
#define UDR  		(*((volatile u8*)0x2C))
#define UCSRA		(*((volatile u8*)0x2B))
#define UCSRB		(*((volatile u8*)0x2A))
#define UCSRC		(*((volatile u8*)0x40))
#define UBRRH		(*((volatile u8*)0x40))
#define UBRRL  		(*((volatile u8*)0x29))
/*************I2C REGESTER****************/
#define TWCR  		(*((volatile u8*)0x56))
#define TWDR  		(*((volatile u8*)0x23))
#define TWBR  		(*((volatile u8*)0x20))
#define TWAR  		(*((volatile u8*)0x22))
#define TWSR  		(*((volatile u8*)0x21))
/************INTRNAl EEPROM****************/
#define EEAR  		(*((volatile u16*)0x3E))
#define EEDR  		(*((volatile u8*)0x3D))
#define EECR  		(*((volatile u8*)0x3C))

#endif /* REG_H_ */