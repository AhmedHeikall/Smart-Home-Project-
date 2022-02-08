/*
 * EPPROM.h
 *
 * Created: 20/12/2021 05:56:12 م
 *  Author: ascom
 */ 


#ifndef EPPROM_H_
#define EPPROM_H_
#include "STD_TYPES.h"
void H_EppromInit(void);
void H_EppromWrite(u8,u8);
u8 H_EppromRead(u8);




#endif /* EPPROM_H_ */