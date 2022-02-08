/*
 * ADC.h
 *
 * Created: 19/11/2021 10:35:46 ص
 *  Author: ascom
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "STD_TYPES.h"
/*AREF, Internal Vref turned off*/
#define VoltageRefMode_1	1
/*AVCC with external capacitor at AREF pin*/
#define VoltageRefMode_2	2
/* Reserved*/
#define VoltageRefMode_3	3
/*Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
#define VoltageRefMode_4	4

/*******the left adjust ***************/
#define  right_Adjust_Enable		0

#define  Left_Adjust_Disable	1

void M_AdcInit(void);
u16 M_AdcRead(void);




#endif /* ADC_H_ */