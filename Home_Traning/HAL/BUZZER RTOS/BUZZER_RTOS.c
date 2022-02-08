/*
 * BUZZER_RTOS.c
 *
 * Created: 29/12/2021 09:10:41 ص
 *  Author: ascom
 */ 
#include "FreeRTOS.h"
#include "task.h"
#include "BUZZER.h"
# define F_CPU 16000000UL
#include <util/delay.h>
void H_BuzzerTwiceRtos(void*ptr){
	H_BuzzerInit();
	while(1){
		H_BuzzerTwis();
		vTaskDelay(1000/portTICK_PERIOD_MS);
	}
}
void H_BuzzerFourtheRtos(void*ptr){
	H_BuzzerInit();
	while(1){
		H_BuzzerTwis();
		_delay_ms(110);
		H_BuzzerTwis();
		vTaskDelay(200/portTICK_PERIOD_MS);
	}
	
}