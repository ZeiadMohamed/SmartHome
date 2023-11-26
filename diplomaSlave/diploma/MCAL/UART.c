
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "UART.h"

static void(*UART_RX_Fptr)(void)=NULLPTR;
static void(*UART_TX_Fptr)(void)=NULLPTR;

void UART_Init(void)
{
	// baud rate 
	UBRRL=51;
	//u8 ucsrc=0x80;
	// NORMAL SPEED
	CLEAR_BIT(UCSRA,U2X);
	// frame data bit , parity , stop 
	// 8 DATA , NO PARITY 1 STOP
	
	//UCSRC=ucsrc;
	//enable 
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
}

void UART_Send(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
	
}

u8 UART_Receive(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}

u8 UART_ReceivePerodic(u8*pdata)
{
	if (READ_BIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1 ;
	}
	return 0;
	
}


void UART_SendNoBlock(u8 data)
{
	UDR=data;
}

u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}

void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}

void UART_RX_SetCallBack(void (*LocalFptr)(void))
{
	UART_RX_Fptr = LocalFptr;
}

void UART_TX_SetCallBack(void (*LocalFptr)(void))
{
	UART_TX_Fptr = LocalFptr;
}


ISR(UART_RX_vect)
{
	if (UART_RX_Fptr!=NULLPTR)
	{
		UART_RX_Fptr();
	}
}

ISR(UART_TX_vect)
{
	if (UART_TX_Fptr!=NULLPTR)
	{
		UART_TX_Fptr();
	}
}


void UART_Receive_String(u8 *str)
{
	u8 i=0;
	str[i]=UART_Receive();
	for(;str[i]!='z';)
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]=0;
}