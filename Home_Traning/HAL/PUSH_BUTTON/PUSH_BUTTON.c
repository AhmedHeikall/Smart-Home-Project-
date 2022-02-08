/*
 * PUSH_BUTTON.c
 *
 * Created: 17/11/2021 12:41:24 م
 *  Author: ascom
 */ 
#include "PUSH_BUTTON_CFG.h"

# define F_CPU 16000000UL
#include <util/delay.h>

void H_ButtonInit(u8 Button_Number){
	M_PinMode(Button_Number,INPUT);
	_delay_ms(110);
}

u8 H_ButtonRead(u8 Button_Number){
	u8 read =M_PinRead(Button_Number);
	return read ;
}