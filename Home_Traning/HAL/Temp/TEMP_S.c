/*
 * TEMP_S.c
 * Created: 17/09/2021 12:19:29 ص
 *  Author: MOHAMED_HELMY
 */ 

#include "ADC.h"
#include "TEMP_S_CFG.h"

void TEMP_S_INIT(void)
{
	M_AdcInit();
}
u16  TEMP_S_READ(void)
{
	u16 value;	
	value = M_AdcRead();
	u16 temp;
	temp = ((u32)value * 500 ) / 1023;
	return temp;
}