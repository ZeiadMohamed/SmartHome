/*
 * Motor_interface.h
 *
 * Created: 11/9/2022 10:52:17 AM
 *  Author: TECH VALLEY
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_
typedef enum{
	M1,M2,M3,M4
	}Motor_type;
void Motor_stop(Motor_type motor);
void Motor_cw(Motor_type motor);
void Motor_ccw(Motor_type motor);





#endif /* MOTOR_INTERFACE_H_ */