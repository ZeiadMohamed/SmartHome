/*
 * Keypad.h
 *
 * Created: 11/23/2022 9:47:59 AM
 *  Author: TECH VALLEY
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO_Interface.h"
#include "StdTypes.h"
#define NO_key 'T'
void keypad_init(void);
u8 keypad_get_read(void);




#endif /* KEYPAD_H_ */