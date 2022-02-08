/*
 * SERVO.c
 *
 * Created: 23/12/2021 05:16:34 م
 *  Author: ascom
 */ 
#include "DIO.h"
#include "TIMER.h"
#include "STD_TYPES.h"

void SERVO_INIT(void)
{
	M_PinMode(PD5,OUTPUT);
	PWM_1_INIT();
	PWM_1_START();
}
void SERVO_MOVE(u8 duty_cycle)
{
	PWM_1_SET_DUTY_CYCLE(duty_cycle);
}