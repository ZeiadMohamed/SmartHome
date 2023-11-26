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
	ADC_Init(VREF_VCC,Prescaler_64);
	SPI_SetCallBack(SPI_func);
	SPI_InterruptEnable();
	sei();
	room_init();
	xTaskCreate(Task1_takeAction,NULL,250,NULL,Task1_Priority,NULL);
	xTaskCreate(Task2_getTemp,NULL,250,NULL,Task2_Priority,NULL);
	xTaskCreate(Task3_AC,NULL,250,NULL,Task3_Priority,NULL);
	vTaskStartScheduler();
	
	
	
	while(1)
	{
	}
	return 0;
}

