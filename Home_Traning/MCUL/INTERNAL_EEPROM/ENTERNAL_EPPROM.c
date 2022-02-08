/*
 * ENTERNAL_EPPROM.c
 *
 * Created: 21/12/2021 09:50:42 م
 *  Author: ascom
 */ 

#include "ENTERNAL_EPPROM.h"
#include "DIO.h"
#include "REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
u8 M_IntEppromDataRead(u16 address){
	u8 Date=0 ;
	while(GET_BIT(EECR,1)!=0){
		
	}
		EEAR=0x5f;
		Date=EEDR;
		/*Enable the master write */
		SET_BIT(EECR,2);
		/*Enable the Read enable */
		SET_BIT(EECR,0);
		return Date;
}
void M_IntEppromDataWrit(u8 data,u16 address){
	/*wait for the ongoing process ended */
	while(GET_BIT(EECR,1)!=0){}
	EEAR=0x5f;
	EEDR=data;
	/*Enable the master write */
	SET_BIT(EECR,2);
	/*Enable the write enable */
	SET_BIT(EECR,1);
}