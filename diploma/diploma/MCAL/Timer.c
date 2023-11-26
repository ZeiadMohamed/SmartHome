/*
 * Timer.c
 *
 * Created: 12/9/2022 9:05:35 AM
 *  Author: TECH VALLEY
 */ 
#include "Timer.h"
void Timer0_init(Timer_mode mode,Prescaler_mode prescaler)
{
	switch(mode)
	{
		case NORMAL:
			CLEAR_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
		break;
		case CTC:
			CLEAR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
		break;
		case Fast_PWM:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case Phase_correct:
			CLEAR_BIT(TCCR0,WGM01);
			SET_BIT(TCCR0,WGM00);
		break;
			
	}
	TCCR0=TCCR0&0xF8;
	TCCR0=TCCR0|prescaler;
}
void OC0_init(OC_mode mode)
{
	switch(mode)
	{
		case Disconnected:
			CLEAR_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
		break;
		case Toggle:
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case Non_inverting:
		SET_BIT(TCCR0,COM01);
		CLEAR_BIT(TCCR0,COM00);
		break;
		case Inverting:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
}
void Timer0_Interrupt_enable(void)
{
	SET_BIT(TIMSK,0);
}
void Timer0_Interrupt_disable(void)
{
	CLEAR_BIT(TIMSK,0);
}
static void (* Timer0_FPTR)(void)=NULLPTR;
static void (* OC0_FPTR)(void)=NULLPTR;
static void (* ICU_FPTR)(void)=NULLPTR;
void Timer0_Interrupt_set_call_back(void(*pf)(void))
{
	Timer0_FPTR=pf;
}
ISR(Timer0_vect)
{
	if(Timer0_FPTR!=NULLPTR)
		Timer0_FPTR();
}
void OC0_Interrupt_enable(void)
{
	SET_BIT(TIMSK,1);
}
void OC0_Interrupt_disable(void)
{
	CLEAR_BIT(TIMSK,1);
}
void OC0_Interrupt_set_call_back(void(*pf)(void))
{
	OC0_FPTR=pf;
}
ISR(OC0_vect)
{
	if(OC0_FPTR!=NULLPTR)
	OC0_FPTR();
}
u8 get_timer0(void)
{
	return TCNT0;
}
void set_timer(u8 time)
{
	TCNT0=time;
}
//void set_interrupt_time(u8 time);
u8 get_OC0(void)
{
	return OCR0;
}
void set_OC0(u8 time)
{
	OCR0=time;
}






void Timer1_init(Timer1_mode mode,Prescaler_mode prescaler)
{
	switch(mode)
	{
		case NORMAL1:
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		break;
		case Phase_correct_8_bit:
		SET_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		break;
		case CTC1:
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		break;
		case Fast_PWM_8_bit:
		SET_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		break;
		case Phase_correct_Top_ICR1:
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		case Phase_correct_Top_OCR1A:
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		case CTC_Top_ICR1:
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		case Fast_PWM_Top_ICR1:
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		case Fast_PWM_Top_OCR1A:
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		
	}
	TCCR1B=TCCR1B&0xF8;
	TCCR1B=TCCR1B|prescaler;
}
void OC1A_init(OC_mode mode)
{
	switch(mode)
	{
		case Disconnected:
		CLEAR_BIT(TCCR1A,6);
		CLEAR_BIT(TCCR1A,7);
		break;
		case Toggle:
		SET_BIT(TCCR1A,6);
		CLEAR_BIT(TCCR1A,7);
		break;
		case Non_inverting:
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
		break;
		case Inverting:
		SET_BIT(TCCR1A,6);
		SET_BIT(TCCR1A,7);
		break;
	}
}
void OC1B_init(OC_mode mode)
{
	switch(mode)
	{
		case Disconnected:
		CLEAR_BIT(TCCR1A,4);
		CLEAR_BIT(TCCR1A,5);
		break;
		case Toggle:
		SET_BIT(TCCR1A,4);
		CLEAR_BIT(TCCR1A,5);
		break;
		case Non_inverting:
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
		break;
		case Inverting:
		SET_BIT(TCCR1A,4);
		SET_BIT(TCCR1A,5);
		break;
	}
}
void Timer1_Interrupt_enable(void)
{
	SET_BIT(TIMSK,2);
}
void Timer1_Interrupt_disable(void)
{
	CLEAR_BIT(TIMSK,2);
}
static void (* Timer1_FPTR)(void)=NULLPTR;
static void (* OC1A_FPTR)(void)=NULLPTR;
static void (* oc1a_FPTR)(void)=NULLPTR;
static void (* OC1B_FPTR)(void)=NULLPTR;
void Timer1_Interrupt_set_call_back(void(*pf)(void))
{
	Timer1_FPTR=pf;
}
ISR(Timer1_vect)
{
	if(Timer1_FPTR!=NULLPTR)
	Timer1_FPTR();
}
void OC1A_Interrupt_enable(void)
{
	SET_BIT(TIMSK,4);
}
void OC1A_Interrupt_disable(void)
{
	CLEAR_BIT(TIMSK,4);
}
void OC1A_Interrupt_set_call_back(void(*pf)(void))
{
	OC1A_FPTR=pf;
}
ISR(OC1A_vect)
{
	if(OC1A_FPTR!=NULLPTR)
	OC1A_FPTR();
}
void OC1B_Interrupt_enable(void)
{
	SET_BIT(TIMSK,3);
}
void OC1B_Interrupt_disable(void)
{
	CLEAR_BIT(TIMSK,3);
}
void OC1B_Interrupt_set_call_back(void(*pf)(void))
{
	OC1B_FPTR=pf;
}
ISR(OC1B_vect)
{
	if(OC1B_FPTR!=NULLPTR)
	OC1B_FPTR();
}
u16 get_timer1(void)
{
	return TCNT1;
}
void set_timer1(u16 time)
{
	TCNT1=time;
}
//void set_interrupt_time(u8 time);
u16 get_OC1A(void)
{
	return OCR1A;
}
void set_OC1A(u16 time)
{
	OCR1A=time;
}
u16 get_OC1B(void)
{
	return OCR1B;
}
void set_OC1B(u16 time)
{
	OCR1B=time;
}
void ICU_Interrupt_enable(void)
{
	SET_BIT(TIMSK,5);
}
void ICU_mode (ICU_mode_t mode)
{
	if(mode==Falling)
	{
		CLEAR_BIT(TCCR1B,6);
	}
	else if(mode == Rising)
	{
		SET_BIT(TCCR1B,6);
	}
}
void ICU_Interrupt_set_call_back(void(*pf)(void))
{
	ICU_FPTR=pf;
}
ISR(ICU_vect)
{
	if(ICU_FPTR!=NULLPTR)
	ICU_FPTR();
}

void Timer1_SetInterruptus(u16 time, void(*localfptr)(void))
{
	Timer1_init(CTC1,Prescaler_8);
	OCR1A=time-1;
	OC1A_Interrupt_set_call_back(localfptr);
	OC1A_Interrupt_enable();
}
u16 timeg;
u16 millis=0,secs=0;
void oc1f(void)
{
	
	millis++;
	if(millis==1000)
	{
		millis=0;
		secs++;
	}
		if(secs==timeg)
		{
			oc1a_FPTR();
			millis=0;
			secs=0;
			Timer1_Stop();
			//cli();
			OC1A_Interrupt_disable();
		}
}
void Timer1_SetInterruptsecSingle(u16 time, void(*localfptr)(void))
{
	millis=0;
	secs=0;
	timeg=time;
	set_timer1(0);
	Timer1_init(CTC1,Prescaler_8);
	OCR1A=999;
	oc1a_FPTR=localfptr;
	OC1A_Interrupt_set_call_back(oc1f);
	OC1A_Interrupt_enable();
}

void Timer1_initWithoutStart(Timer1_mode mode)
{
	switch(mode)
	{
		case NORMAL1:
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		break;
		case Phase_correct_8_bit:
		SET_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		break;
		case CTC1:
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		break;
		case Fast_PWM_8_bit:
		SET_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		break;
		case Phase_correct_Top_ICR1:
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		case Phase_correct_Top_OCR1A:
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		case CTC_Top_ICR1:
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		case Fast_PWM_Top_ICR1:
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		case Fast_PWM_Top_OCR1A:
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		break;
		
	}
	//TCCR1B=TCCR1B&0xF8;
	//TCCR1B=TCCR1B|prescaler;
}
void Timer1_ChoosePre(Prescaler_mode prescaler)
{
	TCCR1B=TCCR1B&0xF8;
	TCCR1B=TCCR1B|prescaler;
}

void Timer1_StartWithPre8(void)
{
	
	Timer1_ChoosePre(Prescaler_8);
}
void Timer1_Stop(void)
{
	
	Timer1_ChoosePre(Stop);
}