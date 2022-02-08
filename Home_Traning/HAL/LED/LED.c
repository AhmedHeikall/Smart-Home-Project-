/*
 * LED.c
 *
 * Created: 17/11/2021 10:34:58 ص
 *  Author: ascom
 */ 
#include "DIO.h"
#include "STD_TYPES.h"
void H_LedInit(u8 LED_NUMBER){
	M_PinMode(LED_NUMBER,OUTPUT);
}

void H_LedOn(u8 LED_NUMBER){
	M_PinWrite(LED_NUMBER,HIGH);
}
void H_LedOff(u8 LED_NUMBER){
	M_PinWrite(LED_NUMBER,LOW);
}

void H_LedToggel(u8 LED_NUMBER){
	M_PinTog(LED_NUMBER);
}