/*
 * Utils.h
 *
 * Created: 11/3/2022 6:24:14 PM
 *  Author: TECH VALLEY
 */ 


#ifndef UTILS_H_
#define UTILS_H_
#include "StdTypes.h"
#define READ_BIT(reg,pin) ((reg>>pin)&1)
//#define WRITE_BIT(reg,pin,value)  (reg=(reg+value*power(2,pin)))
#define CLEAR_BIT(reg,pinNoo)  (reg=reg& ~(1<<pinNoo))
#define SET_BIT(reg,pinNoo)  (reg=reg| (1<<pinNoo))
#define  TOGGLE_BIT(reg,pinNoo) (reg=reg^(1<<pinNoo))
#define Stack_full 0
#define Stack_done 1
#define Stack_empty 0
void set_bit(volatile unsigned char* reg,unsigned char pinNoo);


u8 String_length(u8 *str);
/*int power(int x,int y)
{
	int result = 1;
	int i;
	for(i=1;i<=y;i++)
	{
		result =x*result;
	}
	return result;
}*/
u8 stringToInt(u8 *str);
u8 stringCompare(u8 * arr, u8 * str);
u8 arrayOfPointersSearch(u8 **arr, u8 size, u8*str);

#endif /* UTILS_H_ */