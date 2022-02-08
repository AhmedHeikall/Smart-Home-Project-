/*
 * I2C.h
 *
 * Created: 16/12/2021 07:59:56 م
 *  Author: ascom
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "STD_TYPES.h"
/*MAster Mode */
void M_I2cMasterInit(void);
void M_I2cInit(void);
void M_I2cStartCondition(void);
void M_I2cStopCondition(void);
void M_I2cSendSlaveAddress_Write(u8);
void M_I2cSendSlaveAddress_Read(u8);
void M_I2cMasterSend_Data(u8);
u8 M_I2cMasterReceive_Data(void);
void M_I2cRepeatedStCondition(void);

/*slave mode */
void M_I2cSlaveReceive_AddressWrite(void);
void M_I2cSlaveReceive_AddressRead(void);
void M_I2cSlaveSend_Data(u8 Slave_data);

#define MASTER_T	0 
#define MASTER_R	1
#define SLAVE_T		2
#define SLAVE_R		3


#endif /* I2C_H_ */