/*
 * App.c
 *
 * Created: 11/23/2023 11:52:14 AM
 *  Author: TECH VALLEY
 */ 


#include "Utils.h"
#include "MemMap.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Motor_interface.h"
#include "ADC.h"
#include "LCD.h"
#define  F_CPU 8000000
#include <util\delay.h>
//#include "sevenSeg.h"
#include "Sensors.h"
//#include "Exi.h"
#include "Keypad.h"
//#include "Stepper.h"
//#include "Timer.h"
//#include "RGB.h"
//#include "Servo.h"
//#include "UART.h"
//#include "UART_Services.h"
#include "SPI.h"
//#include "LEDMRX.h"
//#include "DAC.h"
//#include "avr/boot.h"
//#include "avr/eeprom.h"
//#include "e2prom.h"
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "App.h"


volatile u8 recdata='B';
volatile u8 roomst[6]={0};
volatile u8 ACflag=0,roomind,tempsent;
DIO_pin_no_type room_pins[6]={ROOM1_PIN,ROOM2_PIN,ROOM3_PIN,ROOM4_PIN,TV_PIN,AC_PIN};
void room_init(void)
{
		for(u8 i=0;i<6;i++)
		DIO_write(room_pins[i],LOW);
}
void SPI_func(void)
{
	u8 data= SPSR;
	recdata=SPI_ReceiveNoBlock();
	if((recdata>='1') && (recdata<='6'))
	SPI_SendNoBlock(roomst[recdata-'0'-1]);
}

void Task1_takeAction(void*pvParamter)
{
	while(1)
	{
		if((recdata >= 'b') && (recdata <'g'))
		{
			roomind=recdata-'b';
			DIO_write(room_pins[roomind],HIGH);
			roomst[roomind]=1;
		}
		else if((recdata >= 'B') && (recdata <'G'))
		{
			roomind=recdata-'B';
			DIO_write(room_pins[roomind],LOW);
			roomst[roomind]=0;
		}
		else if(recdata == 'g')
		ACflag=1;
		else if(recdata == 'G')
		ACflag=0;
		
		else
		{
			tempsent=recdata;
		}
		vTaskDelay(1000);
	}
}
u16 temp;
void Task2_getTemp(void*pvParamter)
{
	while(1)
	{
		temp = temp_read();
		temp =temp /10;
		LCD_SetCursor(0,0);
		LCD_WriteNumber(temp);
		vTaskDelay(500);
	}
	
}
void Task3_AC(void*pvParamter)
{
	while(1)
	{
		if(ACflag==0)
		DIO_write(room_pins[5],LOW);
		else
		{
			if(tempsent<=temp-1)
			{
				DIO_write(room_pins[5],HIGH);
				roomst[5]=1;
			}
			else if(tempsent>=temp+1)
			{
				DIO_write(room_pins[5],LOW);
				roomst[5]=0;
			}
		}
		vTaskDelay(1000);
	}
}

