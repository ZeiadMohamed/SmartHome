/*
 * RGB.c
 *
 * Created: 12/11/2022 9:48:47 AM
 *  Author: TECH VALLEY
 */ 
#define RGB_prog
#include "RGB.h"
#include "RGB_cfg.h"
u16 Rnew=0,Gnew=0,Bnew=0;
void fRGB(void)
{
	static u8 Rold=0;
	static u8 Gold=0;
	static u8 Bold=0;
	static u16 c=0;
	c++;
	if((Rnew==Rold) && (Gnew==Gold) && (Bnew==Bold))
	{
		return;
	}
	if(c==100)
	{
		if(Rnew>Rold)
		Rold++;
		else if(Rnew<Rold)
		Rold--;
		if(Gnew>Gold)
		Gold++;
		else if(Gnew<Gold)
		Gold--;
		if(Bnew>Bold)
		Bold++;
		else if(Bnew<Bold)
		Bold--;
		set_OC0(Rold);
		set_OC1A(Gold);
		set_OC1B(Bold);
		c=0;
	}
	
	
	
}
void RGB_init(void)
{
	Timer0_init(Fast_PWM,Prescaler_8);
	Timer1_init(Fast_PWM_8_bit,Prescaler_8);
	OC0_init(Non_inverting);
	OC1A_init(Non_inverting);
	OC1B_init(Non_inverting);

}
void RGB_color(Color_Type color)
{
	set_OC0(arr[color][0]);
	set_OC1A(arr[color][1]);
	set_OC1B(arr[color][2]);
}
void RGB_init_gradually(void)
{
	Timer0_init(Fast_PWM,Prescaler_8);
	Timer1_init(Fast_PWM_8_bit,Prescaler_8);
	OC0_init(Non_inverting);
	OC1A_init(Non_inverting);
	OC1B_init(Non_inverting);
	Timer0_Interrupt_set_call_back(fRGB);
	Timer0_Interrupt_enable();
	
}
void RGB_color_gradually(Color_Type color)
{
	Rnew=arr[color][0];
	Gnew=arr[color][1];
	Bnew=arr[color][2];
}
