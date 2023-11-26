/*
 * Utils.c
 *
 * Created: 11/16/2022 6:57:04 PM
 *  Author: TECH VALLEY
 */ 
#include "Utils.h"
void set_bit(volatile unsigned char* reg,unsigned char pinNoo)
{
	*reg=*reg|(1<<pinNoo);
}

u8 String_length(u8 *str)
{	u8 i;
	for(i=0;str[i];i++);
	return i;
	
}
u8 stringToInt(u8 *str)
{
	u8 num=0;
	u8 i;
	for(i=0;str[i];i++)
		num=num*10+(str[i]-'0');
	return num;
}
u8 stringCompare(u8 * arr, u8 * str)
{
	u8 i;
	for(i=0;str[i] || arr[i] ; i++)
	{
		if(str[i] != arr[i])
			return 0;
	}
	return 1;
}
u8 arrayOfPointersSearch(u8 **arr, u8 size, u8*str)
{
	u8 i;
	for(u8 i=0;i<size;i++)
	{
		if(stringCompare(arr[i],str))
			return i;
	}
	return -1;
}