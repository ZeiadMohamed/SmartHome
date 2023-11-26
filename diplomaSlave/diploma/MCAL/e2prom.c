/*
 * e2prom.c
 *
 * Created: 11/21/2023 10:54:06 AM
 *  Author: TECH VALLEY
 */ 
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "e2prom.h"
void e2prom_write(u16 add,u8 data)
{
	while (READ_BIT(EECR,1));
	EEAR = add;
	EEDR = data;
	SET_BIT(EECR,2);
	SET_BIT(EECR,1);
}
u8 e2prom_read(u16 add)
{
	while (READ_BIT(EECR,1));
	EEAR = add;
	SET_BIT(EECR,0);
	return EEDR;
}