/*
 * Sensors.h
 *
 * Created: 11/21/2022 5:30:05 PM
 *  Author: TECH VALLEY
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_
#include "StdTypes.h"
#include "ADC.h"
#include "Timer.h"
#include "Exi.h"
#include "DIO_Interface.h"
#include   "LCD.h"
#define  F_CPU 8000000
#include <util\delay.h>
#define LM35_CH CH_7
#define MPX_CH CH_2
u16 temp_read(void);
void C_queue(u16 temp);
void C_dequeue(void);
void tempf_init(void);
void tempf_runnable(void);
u16 tempf_getRead(void);
u16 pressure_read(void);
typedef enum
{
	US1=pinb0,
	US2=pinb1,
	US3=pinb4,
	US4=pinb3
	
	}Ultrasonic_type;
void Ultrasonics_init(void);
u16 Ultrasonics_start(void);
void Ultrasonics_check(void);
u16  Ultrasonics_get(Ultrasonic_type no);
#endif /* SENSORS_H_ */