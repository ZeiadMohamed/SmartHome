/*
 * sevenSeg.c
 *
 * Created: 11/16/2022 6:57:58 PM
 *  Author: TECH VALLEY
 */ 
#include "sevenSeg_cfg.h"
#include "MemMap.h"
#include "Utils.h"
#define  F_CPU 8000000
#include <util\delay.h>
#if _7_seg_model==with_decoder
void segment_dis(char n)
{
	Seg_Port_1=n%10;
	char msb=(n/10)<<4;
	Seg_Port_1= Seg_Port_1 | msb;
	_delay_ms(200);
}
#elif _7_seg_model==without_decoder
void segment_dis(char n)
{
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	Seg_Port_2=arr[n/10];
	Seg_Port_1=arr[n%10];
	_delay_ms(200);
}
#elif _7_seg_model==multiplixed
void segment_dis(char n)
{
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	set_bit(&PORTA,3);
	//CLEAR_BIT(PORTA,4);
	Seg_Port_1=arr[n%10];
	//set_bit(&PORTA,3);
	CLEAR_BIT(PORTA,4);
	_delay_ms(1);
	set_bit(&PORTA,4);
	//CLEAR_BIT(PORTA,3);
	Seg_Port_2=arr[n/10];
	//set_bit(&PORTA,4);
	CLEAR_BIT(PORTA,3);
	_delay_ms(1);
}
#endif