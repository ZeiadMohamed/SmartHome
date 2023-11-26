/*
 * Sensors.c
 *
 * Created: 11/21/2022 5:30:32 PM
 *  Author: TECH VALLEY
 */ 
#include "Sensors.h"
u16 temp_read(void)
{
	u16 temp=ADC_adcToVolt(LM35_CH);
	return temp;
}

u16 pressure_read(void)
{
	u16 adc=ADC_Read(MPX_CH);
	u16 pressure= (((u32)1000*(adc-40))/943)+150;
	return pressure;
	
}
#define queue_size 10
u16 queue[queue_size];
u16 in=0,out=0,mean=0;
void C_queue(u16 temp)
{
	if(in==queue_size)
		in=0;
	queue[in]=temp;
	in++;
}

void C_dequeue(void)
{
	if(out==queue_size)
		out=0;
	out++;
}

void tempf_init(void)
{	u16 temp= temp_read();
	for(u8 i=0;i<queue_size;i++)
	{
		queue[i]=temp;
	}
}

void tempf_runnable(void)
{	
	u16 temp=temp_read();
	C_dequeue();
	C_queue(temp);
	u16 sum=0;
	for(u8 i=0;i<queue_size;i++)
	{
		sum+=queue[i];
	}
	mean=sum/queue_size;
}

u16 tempf_getRead(void)
{
	return mean;
}

/*u8 c=0;
u8 getflag1=1,getflag2=1,getflag3=1,getflag4=1,flag1=0,flag2=0,flag3=0,flag4=0,t1,t2,t3,t4,t5,t6,t7,t8,c1,c2,c3,c4,c5,c6,c7,c8;
void FTIMER(void)
{
	c++;
}
void FICU(void)
{
	if(flag1==0)
	{
		t1=ICR1;
		c1=c;
		ICU_mode(Falling);
		flag1=1;
	}
	else if ( flag1==1)
	{
		t2=ICR1;
		c2=c;
		flag1=2;
	}
}
void FINT0(void)
{
	if(flag2==0)
	{
		t3=TCNT1;
		c3=c;
		EXI_trigger_edge(INT0,falling);
		flag2=1;
	}
	else if ( flag2==1)
	{
		t4=TCNT1;
		c4=c;
		flag2=2;
	}
}
void FINT1(void)
{
	if(flag3==0)
	{
		t5=TCNT1;
		c5=c;
		EXI_trigger_edge(INT1,falling);
		flag2=1;
	}
	else if ( flag3==1)
	{
		t6=TCNT1;
		c6=c;
		flag3=2;
	}
}
void FINT2(void)
{
	if(flag4==0)
	{
		t7=TCNT1;
		c7=c;
		EXI_trigger_edge(INT2,falling);
		flag4=1;
	}
	else if ( flag4==1)
	{
		t8=TCNT1;
		c8=c;
		flag4=2;
	}
}
void Ultrasonics_init(void)
{
	ICU_Interrupt_set_call_back(FICU);
	ICU_Interrupt_enable();
	EXI_set_call_back(INT0,FINT0);
	EXI_enable(INT0);
	EXI_set_call_back(INT1,FINT1);
	EXI_enable(INT1);
	EXI_set_call_back(INT2,FINT2);
	EXI_enable(INT2);
	Timer1_Interrupt_set_call_back(FTIMER);
	Timer1_Interrupt_enable();
	
}

void Ultrasonics_start(void)
{
	if(getflag1==1)
	{
		flag1=0;
		ICU_mode(Rising);
		DIO_write(US1,HIGH);
		_delay_ms(10);
		DIO_write(US1,LOW);
		
	}
	if(getflag2==1)
	{
		flag2=0;
		EXI_trigger_edge(INT0,rising);
		DIO_write(US2,HIGH);
		_delay_ms(10);
		DIO_write(US2,LOW);
	}
	if(getflag3==1)
	{
		flag3=0;
		EXI_trigger_edge(INT1,rising);
		DIO_write(US3,HIGH);
		_delay_ms(10);
		DIO_write(US3,LOW);
	}
	if(getflag4==1)
	{
		flag4=0;
		EXI_trigger_edge(INT2,rising);
		DIO_write(US4,HIGH);
		_delay_ms(10);
		DIO_write(US4,LOW);
	}
	
}
u8 d[4]={0};
void Ultrasonics_check(void)
{
	u16 tu1,tu2,tu3,tu4;
	if(flag1==2)
	{
		tu1=t2-t1+(c2-c1)*20000;
		d[0]=tu1/58;
	}
	else
	{
		getflag1=0;
	}
	if(flag2==2)
	{
		tu2=t4-t3+(c4-c3)*20000;
		d[1]=tu2/58;
	}
	else
	{
		getflag2=0;
	}
	if(flag3==2)
	{
		tu3=t6-t5+(c6-c5)*20000;
		d[2]=tu3/58;
	}
	else
	{
		getflag3=0;
	}
	if(flag4==2)
	{
		tu4=t8-t7+(c8-c7)*20000;
		d[3]=tu4/58;
	}
	else
	{
		getflag4=0;
	}	
}
u16  Ultrasonics_get(Ultrasonic_type no)
{
	if(no==US1)
		return d[0];
	if(no==US2)
	return d[1];
	if(no==US3)
	return d[2];
	if(no==US4)
	return d[3];
}*/
u8 getflag1=1,getflag2=1,getflag3=1,getflag4=1,flag1=0,flag2=0,flag3=0,flag4=0,t1,t2,t3,t4,t5,t6,t7,t8,c1,c2,c3,c4,c5,c6,c7,c8,c=0;
void FTIMER(void)
{
	c++;
}
void FICU(void)
{
	if(flag1==0)
	{
		t1=ICR1;
		c1=c;
		ICU_mode(Falling);
		flag1=1;
	}
	else if ( flag1==1)
	{
		t2=ICR1;
		c2=c;
		flag1=2;
	}
}
void Ultrasonics_init(void)
{
	ICU_Interrupt_set_call_back(FICU);
	ICU_Interrupt_enable();
		//Timer1_Interrupt_set_call_back(FTIMER);
		//Timer1_Interrupt_enable();
	
}
u16 Ultrasonics_start(void)
{

		flag1=0;
		TCNT1=0;
		ICU_mode(Rising);
		DIO_write(US1,HIGH);
		_delay_us(10);
		DIO_write(US1,LOW);
			u16 tu1,d;
			while(flag1<2);
				tu1=t2-t1;
				d=tu1/58;
	return d;
}

/*u8 getflag1=1,getflag2=1,getflag3=1,getflag4=1,flag1=0,flag2=0,flag3=0,flag4=0,t1,t2,t3,t4,t5,t6,t7,t8,c1,c2,c3,c4,c5,c6,c7,c8,c=0;
void FTIMER(void)
{
	c++;
}
void FINT0(void)
{
	if(flag2==0)
	{
		t3=TCNT1;
		c3=c;
		EXI_trigger_edge(INT0,falling);
		flag2=1;
		LCD_SetCursor(0,0);
		LCD_WriteChar('a');
	}
	else if ( flag2==1)
	{
		LCD_SetCursor(0,1);
		LCD_WriteChar('b');
		t4=TCNT1;
		c4=c;
		flag2=2;
	}
}
void Ultrasonics_init(void)
{
	//ICU_Interrupt_set_call_back(FICU);
	//ICU_Interrupt_enable();
	//Timer1_Interrupt_set_call_back(FTIMER);
	//Timer1_Interrupt_enable();
	EXI_set_call_back(INT0,FINT0);
	EXI_enable(INT0);
}
u16 Ultrasonics_start(void)
{

	flag2=0;
	TCNT1=0;
	EXI_trigger_edge(INT0,rising);
	DIO_write(US2,HIGH);
	_delay_us(10);
	DIO_write(US2,LOW);
	u16 tu2,d;
	LCD_SetCursor(1,5);
	LCD_WriteChar('b');
	while(flag2<2);
	LCD_SetCursor(1,6);
	LCD_WriteChar('d');
	tu2=t4-t3;
	d=tu2/58;
	return d;
}*/