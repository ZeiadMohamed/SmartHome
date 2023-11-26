/*
 * Motor.c
 *
 * Created: 11/9/2022 10:52:46 AM
 *  Author: TECH VALLEY
 */ 
#include "DIO_Interface.h"
#include "Motor_interface.h"
extern const DIO_pin_no_type Motor_pins_array[4][2];
void Motor_stop(Motor_type motor)
{
	DIO_write(Motor_pins_array[motor][0],LOW);
	DIO_write(Motor_pins_array[motor][1],LOW);
}
void Motor_cw(Motor_type motor)
{
	DIO_write(Motor_pins_array[motor][0],HIGH);
	DIO_write(Motor_pins_array[motor][1],LOW);
}
void Motor_ccw(Motor_type motor)
{
	DIO_write(Motor_pins_array[motor][0],LOW);
	DIO_write(Motor_pins_array[motor][1],HIGH);
}