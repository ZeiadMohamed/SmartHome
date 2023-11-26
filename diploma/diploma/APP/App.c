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
#include "sevenSeg.h"
#include "Sensors.h"
#include "Exi.h"
#include "Keypad.h"
#include "Stepper.h"
#include "Timer.h"
#include "RGB.h"
#include "Servo.h"
#include "UART.h"
#include "UART_Services.h"
#include "SPI.h"
#include "LEDMRX.h"
#include "DAC.h"
#include "avr/boot.h"
//#include "avr/eeprom.h"
#include "e2prom.h"
#include "App.h"

void freset(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("Session Timeout");
	_delay_ms(300);
	asm("jmp 0");
}

void blocking_screen(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("blocking mode");
}

void welcome_screen(void)
{
	LCD_SetCursor(0,0);
	LCD_WriteString("Smart Home");
}
void logging_1st_time_screen(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("Logging for 1st time");
}
void setting_adminPass_screen(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("Set Admin Pass");
}
void setting_guestPass_screen(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("Set Guest Pass");
}

u8 get_keypad_busyWait(void)
{
	u8 keypad_Read;
	keypad_Read=keypad_get_read();
	while(keypad_Read == NO_key)
	{
		keypad_Read = keypad_get_read();
	}
	return keypad_Read;
}

void displaying_password_inCursor(u8 x,u8 y,u8 data)
{
	LCD_SetCursor(x,y);
	LCD_WriteChar(data);
	_delay_ms(300);
	LCD_SetCursor(x,y);
	LCD_WriteChar('*');
}

void choosing_mode_screen(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("Choose mode");
	LCD_SetCursor(1,0);
	LCD_WriteString("1:Admin 2:Guest");
}

void type_admin_pass_screen(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("Type Admin Pass");
}
void type_guest_pass_screen(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("Type Guest Pass");
}

void guest_mode_screen(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("1:ROOM1 2:ROOM2");
	LCD_SetCursor(1,0);
	LCD_WriteString("3:ROOM3 4:ROOM4");
}

void room_status_screen(u8 roomNo,u8 data)
{
	LCD_WriteString("ROOM");
	LCD_WriteChar(roomNo);
	LCD_WriteString(" S:");
	if(data==0)
	LCD_WriteString("OFF");
	else
	LCD_WriteString("ON");
	LCD_SetCursor(1,0);
	LCD_WriteString("1:ON 2:OFF 3:RET");
}

void invalid_input_screen(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("invalid input");
	_delay_ms(300);
}

void admin_mode_screen1(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("1:ROOM1 2:ROOM2");
	LCD_SetCursor(1,0);
	LCD_WriteString("3:ROOM3 4:MORE");
}

void admin_mode_screen2(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("1:ROOM4 2:TV");
	LCD_SetCursor(1,0);
	LCD_WriteString("3:AIR COND 4:RET");
}

void air_cond_screen1(void)
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("1:Set Temp");
	LCD_SetCursor(1,0);
	LCD_WriteString("2:Control 3:RET");
	
}

void air_cond_screen2(u8 rec_data)
{
	LCD_WriteString("AIR COND S:");
	if(rec_data==0)
	LCD_WriteString("OFF");
	else
	LCD_WriteString("ON");
	LCD_SetCursor(1,0);
	LCD_WriteString("1:ON 2:OFF 3:RET");
}