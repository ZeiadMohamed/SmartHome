/*
 * Keypad.c
 *
 * Created: 11/23/2022 9:48:30 AM
 *  Author: TECH VALLEY
 */
#define keypad_prog
#include "Keypad.h"
#include "Keypad_cfg.h"
void keypad_init(void)
{
	DIO_write(firstOut,HIGH);
	DIO_write(firstOut+1,HIGH);
	DIO_write(firstOut+2,HIGH);
	DIO_write(firstOut+3,HIGH);
}
u8 keypad_get_read(void)
{
	u8 key=NO_key;
	for(u8 i=0;i<rows;i++)
	{
		DIO_write(firstOut+i,LOW);
		for(u8 j=0;j<cols;j++)
		{
			if(!DIO_READ(firstIn+j))
				{
					key=keys_array[i][j];
					while(!DIO_READ(firstIn+j));
				}
			
		}
		DIO_write(firstOut+i,HIGH);
		
	}
	return key;
}
