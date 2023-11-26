/*
 * Timer.h
 *
 * Created: 12/9/2022 8:50:17 AM
 *  Author: TECH VALLEY
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
typedef enum
{
	NORMAL,
	CTC,
	Fast_PWM,
	Phase_correct
	}Timer_mode;

typedef enum
{
	Stop,
	NO_Prescaler,
	Prescaler_8,
	Prescaler_64,
	Prescaler_256,
	Prescaler_1024,
	External_falling,
	External_rising
}Prescaler_mode;

typedef enum
{
	Disconnected,
	Toggle,
	Inverting,
	Non_inverting
}OC_mode;

typedef enum
{
	Falling,
	Rising
}ICU_mode_t;

void Timer0_init(Timer_mode mode,Prescaler_mode prescaler);
void OC0_init(OC_mode mode);
void Timer0_Interrupt_enable(void);
void Timer0_Interrupt_disable(void);
void Timer0_Interrupt_set_call_back(void(*pf)(void));
void OC0_Interrupt_enable(void);
void OC0_Interrupt_disable(void);
void OC0_Interrupt_set_call_back(void(*pf)(void));
u8 get_timer0(void);
void set_timer(u8 time);
void set_interrupt_time(u8 time);
u8 get_OC0(void);
void set_OC0(u8 time);

typedef enum
{
	NORMAL1,
	Phase_correct_8_bit,
	CTC1,
	Fast_PWM_8_bit,
	Phase_correct_Top_ICR1,
	Phase_correct_Top_OCR1A,
	CTC_Top_ICR1,
	Fast_PWM_Top_ICR1,
	Fast_PWM_Top_OCR1A
	
	
}Timer1_mode;

void Timer1_init(Timer1_mode mode,Prescaler_mode prescaler);
void OC1A_init(OC_mode mode);
void OC1B_init(OC_mode mode);
void Timer1_Interrupt_enable(void);
void Timer1_Interrupt_disable(void);
void Timer1_Interrupt_set_call_back(void(*pf)(void));
void OC1A_Interrupt_enable(void);
void OC1A_Interrupt_disable(void);
void OC1A_Interrupt_set_call_back(void(*pf)(void));
void OC1B_Interrupt_enable(void);
void OC1B_Interrupt_disable(void);
void OC1B_Interrupt_set_call_back(void(*pf)(void));
u16 get_timer1(void);
void set_timer1(u16 time);
void set_interrupt_time1(u8 time);
u16 get_OC1A(void);
void set_OC1A(u16 time);
u16 get_OC1B(void);
void set_OC1B(u16 time);
void ICU_Interrupt_enable(void);
void ICU_mode(ICU_mode_t mode);
void ICU_Interrupt_set_call_back(void(*pf)(void));

void Timer1_SetInterruptus(u16 time, void(*localfptr)(void));

void oc1f(void);
void Timer1_SetInterruptsecSingle(u16 time, void(*localfptr)(void));
void Timer1_initWithoutStart(Timer1_mode mode);
void Timer1_ChoosePre(Prescaler_mode prescaler);
void Timer1_StartWithPre8(void);
void Timer1_Stop(void);

#endif /* TIMER_H_ */