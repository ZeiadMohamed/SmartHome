/*
 * DIO_Interface.h
 *
 * Created: 11/3/2022 6:25:45 PM
 *  Author: TECH VALLEY
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
typedef enum
	{
		pina0=0,
		pina1,
		pina2,
		pina3,
		pina4,
		pina5,
		pina6,
		pina7,
		pinb0,
		pinb1,
		pinb2,
		pinb3,
		pinb4,
		pinb5,
		pinb6,
		pinb7,
		pinc0,
		pinc1,
		pinc2,
		pinc3,
		pinc4,
		pinc5,
		pinc6,
		pinc7,
		pind0,
		pind1,
		pind2,
		pind3,
		pind4,
		pind5,
		pind6,
		pind7,
		total_pins
	}DIO_pin_no_type;
	
typedef enum
	{
		OUTPUT,
		INFREE,
		INPULL
	}DIO_pin_status_type;
typedef enum
	{	
	LOW=0,
	HIGH
	
	}DIO_volt_type;
typedef enum
{
	PA,
	PB,
	PC,
	PD
	
}DIO_port_type;
void DIO_init_pin(DIO_pin_no_type pinno,DIO_pin_status_type pinstatus);
void DIO_init(void);
void DIO_write(DIO_pin_no_type pinno,DIO_volt_type volt);
char DIO_READ(DIO_pin_no_type pinno);
void DIO_toggle_pin(DIO_pin_no_type pinno);
void DIO_write_port(DIO_port_type port,unsigned char value);
unsigned char DIO_read_port(DIO_port_type port);
#endif /* DIO_INTERFACE_H_ */