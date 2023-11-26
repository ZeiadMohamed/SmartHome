/*
 * Stepper.h
 *
 * Created: 11/27/2022 11:52:52 AM
 *  Author: TECH VALLEY
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#define  F_CPU 8000000
#include <util\delay.h>
#define DELAY 50
#define coil1A pinb4
#define coil1B pinb5
#define coil2A pinb6
#define coil2B pinb7
void stepper_uni_cw(void);
void stepper_uni_ccw(void);




#endif /* STEPPER_H_ */