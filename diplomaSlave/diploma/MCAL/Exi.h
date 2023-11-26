/*
 * Exi.h
 *
 * Created: 11/22/2022 7:47:28 PM
 *  Author: TECH VALLEY
 */ 


#ifndef EXI_H_
#define EXI_H_
#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
typedef enum
{
	LOW_level,
	any,
	falling,
	rising	
}Exi_type;

typedef enum
{
	INT0,
	INT1,
	INT2
}Exi_no;
void GI_init(void);
void EXI_trigger_edge(Exi_no no,Exi_type type);
void EXI_enable(Exi_no no);
void EXI_disable(Exi_no no);
void EXI_init(void);
void EXI_set_call_back(Exi_no no,void(*localptr)(void));



#endif /* EXI_H_ */