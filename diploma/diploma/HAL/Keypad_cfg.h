/*
 * Keypad_cfg.h
 *
 * Created: 11/23/2022 9:48:17 AM
 *  Author: TECH VALLEY
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
#include "DIO_Interface.h"
#include "StdTypes.h"
#define firstOut pina0
#define firstIn pinc0
#define rows 4
#define cols 4
#ifdef keypad_prog
static const u8 keys_array[rows][cols]=
{
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'}
		
};
#endif




#endif /* KEYPAD_CFG_H_ */