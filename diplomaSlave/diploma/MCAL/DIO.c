/*
 * DIO.c
 *
 * Created: 11/3/2022 6:25:59 PM
 *  Author: TECH VALLEY
 */
#include "Utils.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "DIO_private.h"
void DIO_init_pin(DIO_pin_no_type pinno,DIO_pin_status_type pinstatus)
{	
	DIO_port_type port;
	if((pinno>=0)&&(pinno<=7))
	{
		port=PA;
	}
	else if((pinno>=8)&&(pinno<=15))
	{
		port=PB;
		pinno=pinno-8;
	}
	else if((pinno>=16)&&(pinno<=23))
	{
		port=PC;
		pinno=pinno-16;
	}
	else if((pinno>=24)&&(pinno<=31))
	{
		port=PD;
		pinno=pinno-24;
	}
	switch(pinstatus)
	{
		case OUTPUT:
			switch(port)
				{
					case PA:
						SET_BIT(DDRA,pinno);
						CLEAR_BIT(PORTA,pinno);
						break;
					case PB:
						SET_BIT(DDRB,pinno);
						CLEAR_BIT(PORTB,pinno);
						break;
					case PC:
						SET_BIT(DDRC,pinno);
						CLEAR_BIT(PORTC,pinno);
						break;
					case PD:
						SET_BIT(DDRD,pinno);
						CLEAR_BIT(PORTD,pinno);
						break;
				}
			break;
			case INFREE:
				switch(port)
					{
					case PA:
					CLEAR_BIT(DDRA,pinno);
					CLEAR_BIT(PORTA,pinno);
					break;
					case PB:
					CLEAR_BIT(DDRB,pinno);
					CLEAR_BIT(PORTB,pinno);
					break;
					case PC:
					CLEAR_BIT(DDRC,pinno);
					CLEAR_BIT(PORTC,pinno);
					break;
					case PD:
					CLEAR_BIT(DDRD,pinno);
					CLEAR_BIT(PORTD,pinno);
					break;
					}
				break;
			case INPULL:
				switch(port)
				{
					case PA:
					CLEAR_BIT(DDRA,pinno);
					SET_BIT(PORTA,pinno);
					break;
					case PB:
					CLEAR_BIT(DDRB,pinno);
					SET_BIT(PORTB,pinno);
					break;
					case PC:
					CLEAR_BIT(DDRC,pinno);
					SET_BIT(PORTC,pinno);
					break;
					case PD:
					CLEAR_BIT(DDRD,pinno);
					SET_BIT(PORTD,pinno);
					break;
				}
				break;
	}
}
void DIO_init(void)
{
	for(int i=0;i<total_pins;i++)
	{
		DIO_init_pin(i,pinstatusarray[i]);
	}
}
void DIO_write(DIO_pin_no_type pinno,DIO_volt_type volt)
{
	DIO_port_type port;
	if((pinno>=0)&&(pinno<=7))
	{
		port=PA;
	}
	else if((pinno>=8)&&(pinno<=15))
	{
		port=PB;
		pinno=pinno-8;
	}
	else if((pinno>=16)&&(pinno<=23))
	{
		port=PC;
		pinno=pinno-16;
	}
	else if((pinno>=24)&&(pinno<=31))
	{
		port=PD;
		pinno=pinno-24;
	}
	switch(volt)
	{
		case HIGH:
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pinno);
			break;
			case PB:
			SET_BIT(PORTB,pinno);
			break;
			case PC:
			SET_BIT(PORTC,pinno);
			break;
			case PD:
			SET_BIT(PORTD,pinno);
			break;
		}
		break;
		case LOW:
		switch(port)
		{
			case PA:
			CLEAR_BIT(PORTA,pinno);
			break;
			case PB:
			CLEAR_BIT(PORTB,pinno);
			break;
			case PC:
			CLEAR_BIT(PORTC,pinno);
			break;
			case PD:
			CLEAR_BIT(PORTD,pinno);
			break;
		}
		break;
	}
}
char DIO_READ(DIO_pin_no_type pinno)
{
	char volt;
	DIO_port_type port;
	if((pinno>=0)&&(pinno<=7))
	{
		port=PA;
	}
	else if((pinno>=8)&&(pinno<=15))
	{
		port=PB;
		pinno=pinno-8;
	}
	else if((pinno>=16)&&(pinno<=23))
	{
		port=PC;
		pinno=pinno-16;
	}
	else if((pinno>=24)&&(pinno<=31))
	{
		port=PD;
		pinno=pinno-24;
	}
		switch(port)
		{
			case PA:
			volt = READ_BIT(PINA,pinno);
			break;
			case PB:
			volt = READ_BIT(PINB,pinno);
			break;
			case PC:
			volt = READ_BIT(PINC,pinno);
			break;
			case PD:
			volt = READ_BIT(PIND,pinno);
			break;
		}
	return volt;
	
}

void DIO_toggle_pin(DIO_pin_no_type pinno)
{
	DIO_port_type port=pinno/8;
	DIO_pin_no_type pin=pinno%8;
	switch(port)
	{
		case PA:
		 TOGGLE_BIT(PORTA,pin);
		break;
		case PB:
		 TOGGLE_BIT(PORTB,pin);
		break;
		case PC:
		TOGGLE_BIT(PORTC,pin);
		break;
		case PD:
		TOGGLE_BIT(PORTD,pin);
		break;
	}
	
}

void DIO_write_port(DIO_port_type port,unsigned char value)
{
		switch(port)
		{
			case PA:
			PORTA=value;
			break;
			case PB:
			PORTB=value;
			break;
			case PC:
			PORTC=value;
			break;
			case PD:
			PORTD=value;
			break;
		}
}
unsigned char DIO_read_port(DIO_port_type port)
{	
	unsigned char volt=0;
		switch(port)
		{
			case PA:
			volt = PINA;
			break;
			case PB:
			volt = PINB;
			break;
			case PC:
			volt = PINC;
			break;
			case PD:
			volt = PIND;
			break;
		}
		return volt;
}