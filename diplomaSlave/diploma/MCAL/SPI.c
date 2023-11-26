/*
 * SPI.c
 *
 * Created: 10/15/2023 3:15:02 AM
 *  Author: TECH VALLEY
 */ 
#include "SPI.h"
static void (* SPI_FPTR)(void)=NULLPTR;
void SPI_Init(void)
{
	if(SPI_MODE==MASTER)
		SET_BIT(SPCR,4);
	else
		CLEAR_BIT(SPCR,4);
	SET_BIT(SPCR,6);
}
u8 SPI_SendReceive(u8 data)
{
	SPDR=data;
	while(!READ_BIT(SPSR,7));
	return SPDR;
}
u8 SPI_ReceiveNoBlock(void)
{
	return SPDR;
}
void SPI_SendNoBlock(u8 data)
{
	SPDR=data;
}
u8 SPI_ReceivePeriodic(u8 *pdata)
{
	if(READ_BIT(SPSR,7))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}
void SPI_InterruptEnable(void)
{
	SET_BIT(SPCR,7);
}
void SPI_SetCallBack(void(*pf)(void))
{
	SPI_FPTR=pf;
}
ISR(SPI_vect)
{
	SPI_FPTR();
}

u8 SPI_ReceiveBusyWait(void)
{
		while(!READ_BIT(SPSR,7));
		return SPDR;
}
