/*
 * SPI.h
 *
 * Created: 10/15/2023 3:15:17 AM
 *  Author: TECH VALLEY
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#define MASTER	0
#define SLAVE	1
#define SPI_MODE MASTER
void SPI_Init(void);
u8 SPI_SendReceive(u8 data);
u8 SPI_ReceiveNoBlock(void);
void SPI_SendNoBlock(u8 data);
u8 SPI_ReceivePeriodic(u8 *pdata);
void SPI_InterruptEnable(void);
void SPI_SetCallBack(void(*pf)(void));




#endif /* SPI_H_ */