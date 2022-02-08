/*
 * TIMER.c
 *
 * Created: 20/11/2021 09:19:03 ص
 *  Author: ascom
 */ 
#include "TIMER_CFG.h"
#include "REG.h"
#include "DIO.h"
#include "BIT_MATH.h"
#include "TIMER.h"
#include "STD_TYPES.h"
u32 number_of_overflow;
u32 total_ticks;
u32 number_of_compare_match;
void M_Timer_0_Init(void){
	
	#if TIMER_0_MODE==Normal_mode // used the normal mode 
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	SET_BIT(TIMSK,0);
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,0);
	#elif TIMER_0_MODE==PWM_Phase_Correct_mode
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	#elif TIMER_0_MODE==CTC_mode
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
    SET_BIT(SREG,7);
    SET_BIT(TIMSK,0);
	
	#elif TIMER_0_MODE==Fast_PWM_mode
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	//SET_BIT(TCCR0,7);
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4); //choose non inverting mode 
	SET_BIT(DDRB,3);
	#endif
	
}
void M_Timer_2_Init(void){
	
	#if TIMER_2_MODE==Normal_mode_2 // used the normal mode
	CLR_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);
	SET_BIT(TIMSK,0);
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,0);
	#elif TIMER_2_MODE==PWM_Phase_Correct_mode_2
	CLR_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);
	#elif TIMER_2_MODE==CTC_mode_2
	SET_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,0);
	
	#elif TIMER_2_MODE==Fast_PWM_mode_2
	SET_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);
	//SET_BIT(TCcR0,7);
	SET_BIT(TCCR2,5);
	CLR_BIT(TCCR2,4); //choose non inverting mode
	SET_BIT(DDRD,7);//set OCR2 
	#endif
	
}


void M_PwmFast_1_Init(void){
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	//SET_BIT(TC0R0,7);
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4); //choose non inverting mode
	SET_BIT(DDRD,7);// from mcu
}

void M_PwmFast_2_Init(void){
	SET_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);
	//SET_BIT(TCcR0,7);
	SET_BIT(TCCR2,5);
	CLR_BIT(TCCR2,4); //choose non inverting mode
	//SET_BIT(DDRD,7);
	M_PinMode(PD7,OUTPUT);
}
void M_Timer_0_Set(u32 delay_time){
//	u32 Tick_time=1024/16 ;
	 total_ticks =(delay_time*1000)/64;
	   number_of_overflow=total_ticks/256;
	   TCNT0=0;
	if ((total_ticks%256)!=0)
	{
		TCNT0=255-(total_ticks%256);
		number_of_overflow=(total_ticks/256);
		number_of_overflow++;
	}
	
	
	
	
	
}
void M_Timer_0_Start(void){
	SET_BIT(TCCR0,2);//enable the clock pulses 
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
}
void M_Timer_0_Stop(void){
	CLR_BIT(TCCR0,2);//disable the clock pulses 
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
}
void M_Timer_0_Set_Ctc(u32 desired_time){
	u8 x=255;
	 total_ticks =(desired_time*1000)/64;

	 TCNT0=0;
	 while(((total_ticks%x)!=0)&&(x>0)){
		 --x; 
	 }
	 OCR0=x+1; //the value the count to reach it  
	 number_of_compare_match=total_ticks/x; 
}
void M_PwmFast_0_Set_Duty_cycle(u8 desired_duty){
	OCR0=((desired_duty*256)/100)-1 ;
}  
void M_PwmFast_0_Start(void){
	M_Timer_0_Start();
}
void M_PwmFast_0_Stop(void){
	M_Timer_0_Stop();
}

void M_Timer_2_Start(void){
	SET_BIT(TCCR2,2);//enable the clock pulses
	CLR_BIT(TCCR2,1);
	SET_BIT(TCCR2,0);
}
void M_Timer_2_Stop(void){
	CLR_BIT(TCCR2,2);//disable the clock pulses
	CLR_BIT(TCCR2,1);
	CLR_BIT(TCCR2,0);
}










void M_PwmFast_2_Set_Duty_cycle(u8 desired_duty){
	OCR2=((desired_duty*256)/100)-1 ;
}
void M_PwmFast_2_Start(void){
	M_Timer_2_Start();
}
void M_PwmFast_2_Stop(void){
	M_Timer_2_Stop();
}






void PWM_1_INIT(void)
{
	/*to select mode 14 -> fast pwm mode with icr in top in timer 1*/
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	
	/*to select non inverted mode*/
	SET_BIT(TCCR1A,7);
	ICR1 = 1250;
}
void PWM_1_SET_DUTY_CYCLE(u8 duty_cycle)
{
	OCR1A = (( duty_cycle * 1250 ) / 100 ) - 1;
}
void PWM_1_START(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
}