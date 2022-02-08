/*
 * SSD.c
 *
 * Created: 17/11/2021 02:06:33 م
 *  Author: ascom
 */ 
#include "DIO.h"
#include "SSD_CFG.h"
void H_SsdInit(void){
	M_PinMode(SSD_ENABLE_1,OUTPUT);
	M_PinMode(SSD_ENABLE_2,OUTPUT);
	M_PinMode(DECODER_PIN_A,OUTPUT);
	M_PinMode(DECODER_PIN_B,OUTPUT);
	M_PinMode(DECODER_PIN_C,OUTPUT);
	M_PinMode(DECODER_PIN_D,OUTPUT);
}
void H_Ssd_1_Display(u8 FIRST_NUMBER_DISPLAY){
	M_PinWrite(SSD_ENABLE_2,HIGH);
	switch(FIRST_NUMBER_DISPLAY){
		case 0 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 1 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 2 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,HIGH);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 3 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,HIGH);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 4 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,HIGH);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 5 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,HIGH);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 6 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,HIGH);
		M_PinWrite(DECODER_PIN_C,HIGH);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 7 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,HIGH);
		M_PinWrite(DECODER_PIN_C,HIGH);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 8 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,HIGH);
		break;
		case 9 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,HIGH);
		break;
		
	   default: break;
	}
}
void H_Ssd_2_Display(u8 SECOND_NUMBER_DISPLAY){
	M_PinWrite(SSD_ENABLE_1,HIGH);
	switch(SECOND_NUMBER_DISPLAY){
		case 0 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 1 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 2 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,HIGH);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 3 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,HIGH);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 4 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,HIGH);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 5 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,HIGH);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 6 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,HIGH);
		M_PinWrite(DECODER_PIN_C,HIGH);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 7 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,HIGH);
		M_PinWrite(DECODER_PIN_C,HIGH);
		M_PinWrite(DECODER_PIN_D,LOW);
		break;
		case 8 :
		M_PinWrite(DECODER_PIN_A,LOW);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,HIGH);
		break;
		case 9 :
		M_PinWrite(DECODER_PIN_A,HIGH);
		M_PinWrite(DECODER_PIN_B,LOW);
		M_PinWrite(DECODER_PIN_C,LOW);
		M_PinWrite(DECODER_PIN_D,HIGH);
		break;
		
		default: break;
	}
}
void H_Ssd_1_Disable(){
	M_PinWrite(SSD_ENABLE_2,LOW);
}
void H_Ssd_2_Disable(){
	M_PinWrite(SSD_ENABLE_1,LOW);
}