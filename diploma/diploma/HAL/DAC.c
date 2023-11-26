/*
 * DAC.c
 *
 * Created: 10/27/2023 4:03:31 PM
 *  Author: TECH VALLEY
 */ 
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "DAC.h"
u8 arrsin[21]={128,168,203,232,250,255,250,232,203,168,128,88,52,24,6,0,6,24,52,88,128};
void setDAC (void)
{
	static u8 i=0;
	DIO_write_port(PD,arrsin[i]);
	i++;
	if(i==21)
	i=0;
}