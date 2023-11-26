/*
 * ADC.c
 *
 * Created: 11/14/2022 6:26:48 PM
 *  Author: TECH VALLEY
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC.h"



void ADC_Init(ADC_VoltRef_type ref,ADC_Prescaler_type scaler)
{
	// prescaler
	
	ADCSRA=ADCSRA&0xF8;// 11111000
	scaler=scaler&0x07;// 00000111
	ADCSRA=ADCSRA|scaler;
	
	// vref
	
	switch(ref)
	{
		case VREF_AREF:
		CLEAR_BIT(ADMUX,REFS1);
		CLEAR_BIT(ADMUX,REFS0);
		break;
		case VREF_VCC:
		CLEAR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
	}
	
	CLEAR_BIT(ADMUX,ADLAR);

	/*ADC ENABLE*/
	SET_BIT(ADCSRA,ADEN);
}




u16 ADC_Read(ADC_Channel_type ch)
{
	u16 adc;
	/* select mux */
	ADMUX = ADMUX & 0xE0;
	ADMUX = ADMUX | ch;
		/* start conversion*/
		
	SET_BIT(ADCSRA,ADSC);
	
	/* wait to end */
	while(READ_BIT(ADCSRA,ADSC));

	
	
	/* get read */
	adc = ADC;
	return adc;
}

u8 ADC_adcToPercent(u16 adc)
{
	u8 percent=0;
	percent=((u32)(adc*(u32)100)/1023);
	return percent;
}

u16 ADC_adcToVolt(ADC_Channel_type ch)
{
	u16 volt=0;
	u16 adc=ADC_Read(ch);
	volt=((u32)(adc*(u32)5000)/1023);
	return volt;
}