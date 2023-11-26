/*
 * Exi.c
 *
 * Created: 11/22/2022 7:47:46 PM
 *  Author: TECH VALLEY
 */ 
#include "Exi.h"
void GI_init(void)
{
	sei();
}
void EXI_trigger_edge(Exi_no no,Exi_type type)
{
	switch(no)
	{
		case INT0:
			MCUCR=MCUCR&0xFC;  //11111100
			MCUCR |= type;
		break;
		case INT1:
			MCUCR=MCUCR&0xF3;  //11110011
			type=type<<2;
			MCUCR |= type;
		break;
		case INT2:
			if(type==falling)
				CLEAR_BIT(MCUCSR,6);
			else if(type==rising)
				SET_BIT(MCUCSR,6);
		break;
	}
}

void EXI_enable(Exi_no no)
{
	switch(no)
	{
		case INT0:
		SET_BIT(GICR,6);
		break;
		case INT1:
		SET_BIT(GICR,7);
		break;
		case INT2:
		SET_BIT(GICR,5);
		break;
	}
}
void EXI_disable(Exi_no no)
{
		switch(no)
		{
			case INT0:
			CLEAR_BIT(GICR,6);
			break;
			case INT1:
			CLEAR_BIT(GICR,7);
			break;
			case INT2:
			CLEAR_BIT(GICR,5);
			break;
		}
}
void EXI_init(void)
{
	EXI_trigger_edge(INT0,falling);
	EXI_trigger_edge(INT1,falling);
	EXI_trigger_edge(INT2,falling);
}
static void (* INT0_FPTR)(void)=NULLPTR;
static void (* INT1_FPTR)(void)=NULLPTR;
static void (* INT2_FPTR)(void)=NULLPTR;
void EXI_set_call_back(Exi_no no,void(*localptr)(void))
{
	switch(no)
	{
		case INT0:
		INT0_FPTR=localptr;
		break;
		case INT1:
		INT1_FPTR=localptr;
		break;
		case INT2:
		INT2_FPTR=localptr;
		break;
	}
}
ISR(INT0_vect)
{
	if(INT0_FPTR!=NULLPTR)
		INT0_FPTR();
	
}

ISR(INT1_vect)
{
	if(INT1_FPTR!=NULLPTR)
	INT1_FPTR();
	
}

ISR(INT2_vect)
{
	if(INT2_FPTR!=NULLPTR)
	INT2_FPTR();
	
}