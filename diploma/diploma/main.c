/*
 * diploma.c
 *
 * Created: 10/22/2022 8:39:51 PM
 * Author : TECH VALLEY
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



int main(void)
{
    /* Replace with your application code */
	//eeprom_update_byte(VAL_APP_ADD,0);
	//u8 VAL_APP_VAL = eeprom_read_byte(VAL_APP_ADD);
	//u8 APP_REQ_VAL = eeprom_read_byte(APP_REQ_ADD);
	DIO_init();
	LCD_Init();
	keypad_init();
	SPI_Init();
	sei();
	u8 admin_pass_created = e2prom_read(ADMIN_PASS_CREATED_ADD);
	u8 guest_pass_created = e2prom_read(GUEST_PASS_CREATED_ADD);
	u8 blockingFlag = e2prom_read(BLOCKED_MODE_ADD);
	u8 keypad_read;
	u8 count_wrong=0;
	welcome_screen();
	_delay_ms(500);
	if(blockingFlag == 0x01)
	{
		blocking_screen();
		_delay_ms(3000);
		count_wrong=2;
		e2prom_write(BLOCKED_MODE_ADD,0xFF);
	}
	if(admin_pass_created  == 0xFF)
	{
			logging_1st_time_screen();
			_delay_ms(500);
			setting_adminPass_screen();
			for(u8 i=0;i<4;i++)
			{
					keypad_read=get_keypad_busyWait();
					e2prom_write(ADMIN_PASS_STARTING_ADD+i,keypad_read);
					displaying_password_inCursor(1,i,keypad_read);
			}
			_delay_ms(300);
			e2prom_write(ADMIN_PASS_CREATED_ADD,0x01);
			
	}
	if(guest_pass_created == 0xFF)
	{
		logging_1st_time_screen();
		_delay_ms(500);
		setting_guestPass_screen();
		for(u8 i=0;i<4;i++)
		{
			keypad_read=get_keypad_busyWait();
			e2prom_write(GUEST_PASS_STARTING_ADD+i,keypad_read);
			displaying_password_inCursor(1,i,keypad_read);
		}
		_delay_ms(300);
		e2prom_write(GUEST_PASS_CREATED_ADD,0x01);
	}
	u8 wrong_input=0,mode;
	  do
		{
			wrong_input=0;
			choosing_mode_screen();
			keypad_read=get_keypad_busyWait();
			if(keypad_read == '1')
			{
				u8 flag_pass=1;
				do
				{
					type_admin_pass_screen();
					flag_pass=1;
					for(u8 i=0;i<4;i++)
					{
						keypad_read=get_keypad_busyWait();
						if(e2prom_read(ADMIN_PASS_STARTING_ADD+i)!=keypad_read)
						{
							flag_pass=0;
							
						}
						displaying_password_inCursor(1,i,keypad_read);
					}
					_delay_ms(300);
					LCD_Clear();
					LCD_SetCursor(0,0);
					if(flag_pass==1)
					{
						
						LCD_WriteString("correct pass");
						_delay_ms(300);
						count_wrong=0;
					}
					else
					{
						LCD_WriteString("wrong pass");
						_delay_ms(300);
						count_wrong ++;
					}
					if(count_wrong == 3)
					{
						e2prom_write(BLOCKED_MODE_ADD,0x01);
						asm("jmp 0");
					}
					
				}while(flag_pass==0);
				mode = ADMIN_MODE;
			}
			else if(keypad_read == '2')
			{
				u8 flag_pass=1;
				do
				{
					type_guest_pass_screen();
					flag_pass=1;
					for(u8 i=0;i<4;i++)
					{
						keypad_read=get_keypad_busyWait();
						if(e2prom_read(GUEST_PASS_STARTING_ADD+i)!=keypad_read)
						{
							flag_pass=0;
							
						}
					displaying_password_inCursor(1,i,keypad_read);
					}
					_delay_ms(300);
					LCD_Clear();
					LCD_SetCursor(0,0);
					if(flag_pass==1)
					{
						
						LCD_WriteString("correct pass");
						_delay_ms(300);
						count_wrong=0;
					}
					else
					{
						LCD_WriteString("wrong pass");
						_delay_ms(300);
						count_wrong ++;
					}
					if(count_wrong == 3)
					{
						e2prom_write(BLOCKED_MODE_ADD,0x01);
						asm("jmp 0");
					}
				}while(flag_pass==0);
				mode = GUEST_MODE;
			}
			else
			{
				invalid_input_screen();
				wrong_input=1;
			}
		}while(wrong_input==1);
		Timer1_SetInterruptsecSingle(30, freset);
		u8 rec_data;
		while(1)
		{
			if(mode == GUEST_MODE)
			{
				
				u8 wrong_inputt=0,roomMode;
				do
				{
					guest_mode_screen();
					keypad_read=get_keypad_busyWait();
					LCD_Clear();
					LCD_SetCursor(0,0);
					if((keypad_read>='1') && (keypad_read <='4'))
					{
						rec_data=SPI_SendReceive(keypad_read);
						_delay_ms(200);
						rec_data=SPI_SendReceive(keypad_read);
						room_status_screen(keypad_read,rec_data);
						wrong_inputt=0;
						roomMode=keypad_read-'0';
					}
					else
					{
						invalid_input_screen();
						wrong_inputt=1;
					}
				}while(wrong_inputt==1);
				
				keypad_read=get_keypad_busyWait();
				if(keypad_read=='1')
					rec_data=SPI_SendReceive('a'+roomMode);
				else if(keypad_read=='2')
					rec_data=SPI_SendReceive('A'+roomMode);
				else if(keypad_read=='3');
				else
					invalid_input_screen();
			}
			else if(mode == ADMIN_MODE)
			{
				u8 wrong_inputt=0,roomMode,flagnext=1;
				do
				{
					flagnext=1;
					admin_mode_screen1();
					keypad_read=get_keypad_busyWait();
					LCD_Clear();
					LCD_SetCursor(0,0);
					if((keypad_read>='1') && (keypad_read<='3'))
					{
						rec_data=SPI_SendReceive(keypad_read);
							_delay_ms(200);
							rec_data=SPI_SendReceive(keypad_read);
						room_status_screen(keypad_read,rec_data);
						wrong_inputt=0;
						roomMode=keypad_read-'0';
					}
					else if(keypad_read=='4')
					{
						flagnext=0;
						u8 wrong_input2=0;
						do
						{
							admin_mode_screen2();
							keypad_read=get_keypad_busyWait();
							LCD_Clear();
							LCD_SetCursor(0,0);
							if((keypad_read=='1') || (keypad_read=='2'))
							{
								keypad_read +=3;
								rec_data=SPI_SendReceive(keypad_read);
								_delay_ms(200);
								rec_data=SPI_SendReceive(keypad_read);
								room_status_screen(keypad_read,rec_data);
								roomMode=keypad_read-'0';
								keypad_read=get_keypad_busyWait();
											if(keypad_read=='1')
												rec_data=SPI_SendReceive('a'+roomMode);
											else if(keypad_read=='2')
												rec_data=SPI_SendReceive('A'+roomMode);
											else if(keypad_read=='3');
											else
												invalid_input_screen();
								wrong_input2=1;
								wrong_inputt=0;
								
							}
							else if(keypad_read=='3')
							{
										u8 wrong_input3=0;
										do
										{
											air_cond_screen1();
											keypad_read=get_keypad_busyWait();
											LCD_Clear();
											LCD_SetCursor(0,0);
											if(keypad_read=='2')
											{
												rec_data=SPI_SendReceive('6');
												_delay_ms(100);
												rec_data=SPI_SendReceive('6');
												air_cond_screen2(rec_data);
												roomMode=6;
												
																	keypad_read=get_keypad_busyWait();
																	if(keypad_read=='1')
																		rec_data=SPI_SendReceive('a'+roomMode);
																	else if(keypad_read=='2')
																		rec_data=SPI_SendReceive('A'+roomMode);
																	else if(keypad_read=='3');
																	else
																		invalid_input_screen();	
												wrong_input2=0;
												wrong_input3=1;
											}
											else if(keypad_read=='1')
											{
												LCD_WriteString("SET TEMP");
												u8 temp=0;
												for(u8 i=0;i<2;i++)
												{
													keypad_read=get_keypad_busyWait();
													LCD_SetCursor(1,i);
													LCD_WriteChar(keypad_read);
													temp=temp*10+keypad_read-'0';
												}
												rec_data=SPI_SendReceive(temp);
												_delay_ms(300);
												wrong_input2=0;
												wrong_input3=1;
											}
											else if(keypad_read=='3')
											{
												wrong_input2=1;
												wrong_input3=0;
											}
											else
											{
												invalid_input_screen();
												wrong_input3=1;
											}
											wrong_inputt=0;
										}while(wrong_input3==1);
										
							}
							else if(keypad_read=='4')
							{
								wrong_input2=0;
								wrong_inputt=1;
							}
							else
							{
								invalid_input_screen();
								wrong_input2=1;
							}
						}while(wrong_input2==1);
					
					}
					else
					{
						invalid_input_screen();
						wrong_inputt=1;
					}
				}while(wrong_inputt==1);
			if(flagnext)
				{
							keypad_read=get_keypad_busyWait();
							if(keypad_read=='1')
								rec_data=SPI_SendReceive('a'+roomMode);
							else if(keypad_read=='2')
								rec_data=SPI_SendReceive('A'+roomMode);
							else if(keypad_read=='3');
							else
								invalid_input_screen();
				}
			}
		}
	return 0;
}