/*
 * UARTstackApp.c
 *
 * Created: 8/29/2023 11:37:42 PM
 *  Author: TECH VALLEY
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "UART.h"
u8 stack[5];
u8 sp=0;
u8 stack_push(u8 data)
{
	if(sp==5)
		return Stack_full;
	else
	{
		stack[sp]=data;
		sp++;	
		return Stack_done;
	}
	
}
u8 stack_pop(u8 *data)
{
	if(sp==0)
	return Stack_empty;
	else
	{
		sp--;
		*data=stack[sp];
		return Stack_done;
	}
	
}