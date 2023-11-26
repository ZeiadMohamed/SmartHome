/*
 * RGB.h
 *
 * Created: 12/11/2022 9:48:14 AM
 *  Author: TECH VALLEY
 */ 


#ifndef RGB_H_
#define RGB_H_
#include "StdTypes.h"
#include "Utils.h"
#include "Timer.h"
typedef enum{
	Red,
	Green,
	Blue,
	Yellow
	
}Color_Type;
void RGB_init(void);
void RGB_color(Color_Type color);
void RGB_init_gradually(void);
void RGB_color_gradually(Color_Type color);




#endif /* RGB_H_ */