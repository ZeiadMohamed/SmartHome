/*
 * MemMap.h
 *
 * Created: 11/3/2022 6:24:38 PM
 *  Author: TECH VALLEY
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_
#define PINA (*(volatile unsigned char*)0x39)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PORTA (*(volatile unsigned char*)0x3B)

#define PINB (*(volatile unsigned char*)0x36)
#define DDRB (*(volatile unsigned char*)0x37)
#define PORTB (*(volatile unsigned char*)0x38)

#define PINC (*(volatile unsigned char*)0x33)
#define DDRC (*(volatile unsigned char*)0x34)
#define PORTC (*(volatile unsigned char*)0x35)

#define PIND (*(volatile unsigned char*)0x30)
#define DDRD (*(volatile unsigned char*)0x31)
#define PORTD (*(volatile unsigned char*)0x32)

#define ADMUX (*(volatile unsigned char*)0x27)

#define ADLAR 5
#define REFS0 6
#define REFS1 7


#define ADCSRA (*(volatile unsigned char*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7

#define ADCL (*(volatile unsigned char*)0x24)
#define ADCH (*(volatile unsigned char*)0x25)

#define ADC (*(volatile unsigned short*)0x24)

#define MCUCR (*(volatile unsigned char*)0x55)
#define MCUCSR (*(volatile unsigned char*)0x54)
#define GICR (*(volatile unsigned char*)0x5B)

#define sei() __asm__ __volatile__("sei"::)
#define cli() __asm__ __volatile__("cli"::)

#define INT0_vect __vector_1
#define INT1_vect __vector_2
#define INT2_vect __vector_3
#define Timer0_vect __vector_11
#define OC0_vect __vector_10
#define Timer1_vect __vector_9
#define OC1B_vect __vector_8
//#define OC1A_vect __vector_7
#define UART_RX_vect __vector_13
#define UART_TX_vect __vector_15
#define ICU_vect __vector_6
#define SPI_vect __vector_12

#define  ISR(v) void v(void)__attribute__((signal)); \
				void v(void)
				
#define  ISR_with_GE(v) sei();                 \
						void v(void)__attribute__((signal)); \
						void v(void)


#define TIMSK (*(volatile unsigned char*)0x59)
#define TIFR (*(volatile unsigned char*)0x58)

#define TCCR0 (*(volatile unsigned char*)0x53)
#define WGM00 6
#define WGM01 3
#define COM00 4
#define COM01 5

#define TCNT0 (*(volatile unsigned char*)0x52)
#define TOEI0 0

#define OCR0	(*(volatile unsigned char*)0x5C)

#define TCCR1A	(*(volatile unsigned char*)0x4F)
#define TCCR1B	(*(volatile unsigned char*)0x4E)
#define TCNT1	(*(volatile unsigned short*)0x4C)
#define OCR1A	(*(volatile unsigned short*)0x4A)
#define OCR1B	(*(volatile unsigned short*)0x48)
#define ICR1	(*(volatile unsigned short*)0x46)	
	
#define UCSRA	(*(volatile unsigned char*)0x2B)
#define UCSRB	(*(volatile unsigned char*)0x2A)
#define UDR	(*(volatile unsigned char*)0x2C)
#define UCSRC	(*(volatile unsigned short*)0x40)
#define UBRRL	(*(volatile unsigned short*)0x29)
#define U2X 1
#define UDRE 5
#define TXC 6
#define RXC 7
#define TXEN 3 
#define RXEN 4 
#define TXCIE 6 
#define RXCIE 7


#define SPDR	(*(volatile unsigned char*)0x2F)
#define SPSR	(*(volatile unsigned char*)0x2E)
#define SPCR	(*(volatile unsigned char*)0x2D)

#define GICR	(*(volatile unsigned char*)0x5B)
#define SREG	(*(volatile unsigned char*)0x5F)

#define SREG	(*(volatile unsigned char*)0x5F)
#define SREG	(*(volatile unsigned char*)0x5F)

#define EEDR	(*(volatile unsigned char*)0x3D)
#define EECR	(*(volatile unsigned char*)0x3C)
#define EEAR	(*(volatile unsigned short*)0x3E)




#endif /* MEMMAP_H_ */