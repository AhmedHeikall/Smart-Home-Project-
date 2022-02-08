/*
 * CFile1.c
 *
 * Created: 08/02/2022 11:39:27 م
 *  Author: kcs
 */ 
#include "REG.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "STD_TYPES.h"
void DC_INIT(void)
{
	M_PinMode(PD7,OUTPUT);
}
void DC_ON(void)
{
	M_PinWrite(PD7,HIGH);
}
void DC_OFF(void)
{
	M_PinWrite(PD7,LOW);
}