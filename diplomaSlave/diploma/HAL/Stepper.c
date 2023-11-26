/*
 * Stepper.c
 *
 * Created: 11/27/2022 11:52:33 AM
 *  Author: TECH VALLEY
 */ 
#include "Stepper.h"
void stepper_uni_ccw(void)
{
	
	
	
	DIO_write(coil1A,LOW);
	DIO_write(coil1B,HIGH);
	DIO_write(coil2A,LOW);
	DIO_write(coil2B,LOW);
	_delay_ms(DELAY);
	
	DIO_write(coil1A,HIGH);
	DIO_write(coil1B,LOW);
	DIO_write(coil2A,LOW);
	DIO_write(coil2B,LOW);
	_delay_ms(DELAY);
	
	
	DIO_write(coil1A,LOW);
	DIO_write(coil1B,LOW);
	DIO_write(coil2A,HIGH);
	DIO_write(coil2B,LOW);
	_delay_ms(DELAY);
	
	DIO_write(coil1A,LOW);
	DIO_write(coil1B,LOW);
	DIO_write(coil2A,LOW);
	DIO_write(coil2B,HIGH);
	_delay_ms(DELAY);
}
void stepper_uni_cw(void)
{
	DIO_write(coil1A,LOW);
	DIO_write(coil1B,LOW);
	DIO_write(coil2A,LOW);
	DIO_write(coil2B,HIGH);
	_delay_ms(DELAY);
	DIO_write(coil1A,LOW);
	DIO_write(coil1B,LOW);
	DIO_write(coil2A,HIGH);
	DIO_write(coil2B,LOW);
	_delay_ms(DELAY);
	DIO_write(coil1A,HIGH);
	DIO_write(coil1B,LOW);
	DIO_write(coil2A,LOW);
	DIO_write(coil2B,LOW);
	_delay_ms(DELAY);
	DIO_write(coil1A,LOW);
	DIO_write(coil1B,HIGH);
	DIO_write(coil2A,LOW);
	DIO_write(coil2B,LOW);
	_delay_ms(DELAY);
}

void stepper_by_rotate(u8 rotate)
{
	for(u16 i=0;i<rotate*500;i++)
	{
		stepper_uni_cw();
	}
}

void stepper_by_angle(u16 angle)
{
	u16 rotations=(angle*(u32)500)/360;
	for(u16 i=0;i<rotations;i++)
	{
		stepper_uni_cw();
	}
}