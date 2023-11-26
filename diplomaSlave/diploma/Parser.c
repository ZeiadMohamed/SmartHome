/*
 * Parser.c
 *
 * Created: 11/9/2023 5:26:30 PM
 *  Author: TECH VALLEY
 */ 
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "avr/boot.h"
#include "avr/eeprom.h"

extern void func(void);

//u16 Data[100] = {0};
u32 Address= 0x00000000;
u16 Data=0;
u8 AsciToHex(u8 Copy_u8Asci)
{
	u8 Result;
	if ( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		Result = Copy_u8Asci - 48;
	}

	else
	{
		Result = Copy_u8Asci - 55;
	}

	return Result;
}


void ParseData(u8* Copy_u8BufData)
{
	u8 DigitLow,DigitHigh,CC,i;
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	u8 sreg;
	sreg = SREG;
	//u8 DataCounter = 0;

	/* Get Character Count */
	DigitHigh = AsciToHex (Copy_u8BufData[1]);
	DigitLow  = AsciToHex (Copy_u8BufData[2]);
	CC        = (DigitHigh<<4) | DigitLow ;

	/* Get Address */
	/*DataDigit0 = AsciToHex (Copy_u8BufData[3]);
	DataDigit1 = AsciToHex (Copy_u8BufData[4]);
	DataDigit2 = AsciToHex (Copy_u8BufData[5]);
	DataDigit3 = AsciToHex (Copy_u8BufData[6]);*/

	/* Clear Low Part of Address */
	/*Address = Address & 0xFFFF0000;
	Address = Address | (DataDigit3) | (DataDigit2 << 4) | (DataDigit1 << 8) | (DataDigit0<<12);*/

static u8 c=0;
static u8 page=0;
static u8 j=0;
u32 address;
if(c==0)
{
	
	address= page*128;
	
}
	for (i=0;i<CC/2; i++)
	{
		DataDigit0 = AsciToHex (Copy_u8BufData[4*i+9 ]);
		DataDigit1 = AsciToHex (Copy_u8BufData[4*i+10]);
		DataDigit2 = AsciToHex (Copy_u8BufData[4*i+11]);
		DataDigit3 = AsciToHex (Copy_u8BufData[4*i+12]);

		Data = (DataDigit3 << 8) | (DataDigit2 << 12) | (DataDigit1) | (DataDigit0<<4);
		boot_page_fill_safe(address+j,Data);
		j=j+2;
		//DataCounter++;
	}
	
	
	//FPEC_voidFlashWrite(Address,Data,CC/2);
	c++;
	if(c==8)
	{
		boot_page_write_safe(address);
		
		c=0;
		page++;
		j=0;
	}
	boot_rww_enable_safe();	
	SREG=sreg;
}

void ParseUpperAddress(u8* Copy_u8BufData)
{
	//	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	//
	//	/* Get Address */
	//	DataDigit0 = AsciToHex (Copy_u8BufData[3]);
	//	DataDigit1 = AsciToHex (Copy_u8BufData[4]);
	//	DataDigit2 = AsciToHex (Copy_u8BufData[5]);
	//	DataDigit3 = AsciToHex (Copy_u8BufData[6]);
	//
	//	/* Clear Low Part of Address */
	//	Address = Address & (u32)0x0000FFFF;
	//	Address = Address | (u32)((u32)(DataDigit3 << 28) | (u32)(DataDigit2 << 24) | (u32)(DataDigit1 << 20) | (u32)(DataDigit0 << 16));
}

void Parser_voidParseRecord(u8* Copy_u8BufData)
{
	switch (Copy_u8BufData[8])
	{
		case '0': ParseData(Copy_u8BufData); break;
		case '4': ParseUpperAddress(Copy_u8BufData); break;
		case '1':	eeprom_update_byte(0x00,1);  func();						break;
	}
}
