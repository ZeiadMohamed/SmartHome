/*
 * Servo.h
 *
 * Created: 12/11/2022 9:18:39 AM
 *  Author: TECH VALLEY
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "Timer.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
void servo_init(void);
void ser(u8 angle);
void servo_initNormal(void);
void servo_toNormal(u8 angle);



#endif /* SERVO_H_ */