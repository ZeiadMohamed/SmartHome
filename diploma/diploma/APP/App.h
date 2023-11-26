/*
 * App.h
 *
 * Created: 11/23/2023 11:52:36 AM
 *  Author: TECH VALLEY
 */ 


#ifndef APP_H_
#define APP_H_
#define GUEST_MODE 0
#define ADMIN_MODE 1
#define ADMIN_PASS_CREATED_ADD 0x100
#define GUEST_PASS_CREATED_ADD 0x101
#define BLOCKED_MODE_ADD 0x98
#define ADMIN_PASS_STARTING_ADD 0x102
#define GUEST_PASS_STARTING_ADD 0x106

void freset(void);
void blocking_screen(void);
void welcome_screen(void);
void logging_1st_time_screen(void);
void setting_adminPass_screen(void);
void setting_guestPass_screen(void);
u8 get_keypad_busyWait(void);
void displaying_password_inCursor(u8 x,u8 y,u8 data);
void choosing_mode_screen(void);
void type_admin_pass_screen(void);
void type_guest_pass_screen(void);
void guest_mode_screen(void);
void room_status_screen(u8 roomNo,u8 data);
void invalid_input_screen(void);
void admin_mode_screen1(void);
void admin_mode_screen2(void);
void air_cond_screen1(void);
void air_cond_screen2(u8 rec_data);



#endif /* APP_H_ */