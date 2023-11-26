/*
 * Servo.c
 *
 * Created: 12/11/2022 9:18:52 AM
 *  Author: TECH VALLEY
 */ 
#include "Servo.h"
u16 OCR1B_value;
void fzy(void)
{
	static u8 flag=1;
	if(flag)
	{
		DIO_write(pind7,HIGH);
		TCNT1= 65535 - OCR1B_value-5; 
	}
	else
	{
		DIO_write(pind7,LOW);
		TCNT1= 65535 + OCR1B_value - 20000-5;
	}
	flag = flag ^ 1;
}
void servo_init(void)
{
	Timer1_init(Fast_PWM_Top_OCR1A,Prescaler_8);
	OC1B_init(Non_inverting);
	set_OC1A(20000);
}
void ser(u8 angle)
{
	u16 value=999+(angle*(u32)1000)/180;
	set_OC1B(value);
}
void servo_initNormal(void)
{
	Timer1_init(NORMAL1,Prescaler_8);
}
void servo_toNormal(u8 angle)
{
	Timer1_Interrupt_set_call_back(fzy);
	Timer1_Interrupt_enable();
	OCR1B_value = 999 + (angle*(u32)1000)/180;
}