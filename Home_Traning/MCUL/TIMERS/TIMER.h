/*
 * TIMER.h
 *
 * Created: 20/11/2021 09:19:19 ص
 *  Author: ascom
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "STD_TYPES.h"
void M_Timer_0_Init(void);
void M_Timer_0_Set(u32);
void M_Timer_0_Start(void);
void M_Timer_0_Stop(void);
void M_Timer_0_Set_Ctc(u32);

void M_PwmFast_0_Init(void);
void M_PwmFast_0_Set_Duty_cycle(u8);
void M_PwmFast_0_Start(void);
void M_PwmFast_0_Stop(void);

void PWM_1_INIT(void);
void PWM_1_SET_DUTY_CYCLE(u8 duty_cycle);
void PWM_1_START(void);

#define  Normal_mode		    0
#define  PWM_Phase_Correct_mode	1
#define  CTC_mode	            2
#define  Fast_PWM_mode         	3
/********Timer2 **********************/

void M_Timer_2_Init(void);
void M_Timer_2_Start(void);
void M_Timer_2_Stop(void);
void M_PwmFast_2_Init(void);
void M_PwmFast_2_Set_Duty_cycle(u8);
void M_PwmFast_2_Start(void);
void M_PwmFast_2_Stop(void);
			   
#define  Normal_mode_2		        0
#define  PWM_Phase_Correct_mode_2	1
#define  CTC_mode_2	                2
#define  Fast_PWM_mode_2         	3


#endif /* TIMER_H_ */