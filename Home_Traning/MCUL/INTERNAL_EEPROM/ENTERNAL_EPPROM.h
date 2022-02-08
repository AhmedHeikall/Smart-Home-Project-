/*
 * ENTERNAL_EPPROM.h
 *
 * Created: 21/12/2021 09:51:03 م
 *  Author: ascom
 */ 


#ifndef ENTERNAL_EPPROM_H_
#define ENTERNAL_EPPROM_H_
#include "STD_TYPES.h"

/*void M_IntEppromAddressRead(u16 address);
void M_IntEppromAddressWrite(u16 address);*/
u8 M_IntEppromDataRead(u16 address);
void M_IntEppromDataWrit(u8 data,u16 address);



#endif /* ENTERNAL_EPPROM_H_ */