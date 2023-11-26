/*
 * LCD.h
 *
 * Created: 11/14/2022 6:51:45 PM
 *  Author: TECH VALLEY
 */ 


#ifndef LCD_H_
#define LCD_H_
#define  F_CPU  8000000UL
#include <util/delay.h>
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Utils.h"
#define  _8_BIT    1
#define  _4_BIT    0

/******************** pin config *************************/

/* choose _8_BIT  _4_BIT**/
#define  LCD_MODE  _4_BIT



#define  D7  pind7
#define  D6  pind6
#define  D5  pind5
#define  D4  pind4



/*********************************************************/


#define  RS   pinc6
#define  EN   pinc7

#define  LCD_PORT  PA


void LCD_Init(void);

void LCD_WriteNumber(s32 num);
void LCD_WriteString(u8*str);
void LCD_WriteChar(u8 ch);
void LCDW(u8 num);
void LCD_WriteHex(u8 num);
void LCD_WriteNumber_4D(u16 num);
void LCD_SetCursor(u8 line,u8 cell);

void LCD_Clear(void);








#endif /* LCD_H_ */