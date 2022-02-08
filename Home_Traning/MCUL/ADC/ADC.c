/*
 * ADC.c
 *
 * Created: 19/11/2021 10:35:33 ص
 *  Author: ascom
 */
#include "ADC_CFG.h" 
#include "ADC.h"
#include "REG.h"

#include "BIT_MATH.h"
#include "REG.h"
#include "STD_TYPES.h"

void M_AdcInit(void){
	/*MAKE THE PIN IS INPUT*/
	//CLR_BIT(DDRA,PIN_ADC);
	//SET_BIT(SREG,7);
	//SET_BIT(ADCSRA,3);
	/*set the volage ref*/
	//#if VOLTAGE_REF_MODE==VoltageRefMode_1 
	//CLR_BIT(ADMUX,7);
	//CLR_BIT(ADMUX,6);
	//#elif VOLTAGE_REF_MODE==VoltageRefMode_2
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	//#elif VOLTAGE_REF_MODE==VoltageRefMode_3
	//SET_BIT(ADMUX,7);
	//CLR_BIT(ADMUX,6);
	//#elif VOLTAGE_REF_MODE==VoltageRefMode_4
	//SET_BIT(ADMUX,7);
	//SET_BIT(ADMUX,6);
	//#endif
	
	/*select the start */
	//#if LEFT_ADJUST_MODE==Left_Adjust_Enable
	//SET_BIT(ADMUX,5);
	//#elif LEFT_ADJUST_MODE== right_Adjust_Enable
	CLR_BIT(ADMUX,5);
	//#endif
	
		
	/*******ENABLE THE ADC *********/
	SET_BIT(ADCSRA,7);
	
	/********AUTO TRRIGER *********/
	SET_BIT(ADCSRA,5);
	/*******ADJUST THE PRESCALER /128*/
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
    
}
u16 M_AdcRead(void){
	/*******START CONVERSION*******/
	u16 value=0;
	/*select the pin to take the reading */
SET_BIT(ADMUX,0);
CLR_BIT(ADMUX,1);
CLR_BIT(ADMUX,2);
CLR_BIT(ADMUX,3);
CLR_BIT(ADMUX,4);
	SET_BIT(ADCSRA,6);
	/*u8 adcL=0;
	u8 adcH=0;*/
	
	while(GET_BIT(ADCSRA,4)==0){
		/*WAIT FOR CONVERSION*/
		//_delay_ms(50);
	}
/*	adcL=ADCL;
	adcH=ADCH;*/
	value=ADCLVALUE;
	
	return value ;
}