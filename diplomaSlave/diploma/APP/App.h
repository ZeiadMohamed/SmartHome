/*
 * App.h
 *
 * Created: 11/23/2023 11:52:36 AM
 *  Author: TECH VALLEY
 */ 


#ifndef APP_H_
#define APP_H_
#define Task1_Priority (2)
#define Task2_Priority (3)
#define Task3_Priority (1)

#define ROOM1_PIN pina0
#define ROOM2_PIN pina1
#define ROOM3_PIN pina2
#define ROOM4_PIN pina3
#define TV_PIN pina4
#define AC_PIN pina5

void Task1_takeAction(void*pvParamter);
void Task2_getTemp(void*pvParamter);
void Task3_AC(void*pvParamter);
void room_init(void);
void SPI_func(void);




#endif /* APP_H_ */