/*
 * LEDMRX.c
 *
 * Created: 10/26/2023 2:44:04 PM
 *  Author: TECH VALLEY
 */ 

#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#define  F_CPU 8000000
#include <util\delay.h>
DIO_pin_no_type LED_COLS[8]={pinb0,pinb1,pinb2,pinb3,pinb4,pinb5,pinb6,pinb7};
DIO_pin_no_type LED_ROWS[8]={pinc0,pinc1,pinc2,pinc3,pinc4,pinc5,pinc6,pinc7};
#define COLS_PORT PB
void LEDMRX_init(void)
{
	for(u8 i=0;i<8;i++)
		DIO_write(LED_ROWS[i],HIGH);
}
void LEDMRXDisplay(u8 *copy_data)
{
	for(u8 i=0;i<8;i++)
	{
		DIO_write_port(COLS_PORT,copy_data[i]);
		DIO_write(LED_ROWS[i],LOW);
		_delay_us(2500);
		DIO_write(LED_ROWS[i],HIGH);
		
	}
	
	
}
