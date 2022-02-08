/*
 * BUZZER.c
 *
 * Created: 17/11/2021 11:08:48 ص
 *  Author: ascom
 */ 
#include "BUZZER_CFG.h"
//#include "DIO.h"

#include <util/delay.h>
# define F_CPU 16000000UL
void H_BuzzerInit(void){
	M_PinMode(BUZZER_PIN,OUTPUT);
}
void H_BuzzerOn(void){
	M_PinWrite(BUZZER_PIN,HIGH);
}
void H_BuzzerOff(void){
	M_PinWrite(BUZZER_PIN,LOW);
}
void H_BuzzerTwis(void){
	M_PinWrite(BUZZER_PIN,HIGH);
	_delay_ms(110);
	M_PinWrite(BUZZER_PIN,LOW);
	_delay_ms(110);
	M_PinWrite(BUZZER_PIN,HIGH);
	_delay_ms(110);
	M_PinWrite(BUZZER_PIN,LOW);
	_delay_ms(110);
}