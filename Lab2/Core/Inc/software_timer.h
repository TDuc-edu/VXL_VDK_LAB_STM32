/*
 * software_timer.h
 *
 *  Created on: Oct 15, 2025
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

// Khai báo biến timer
extern int timer0_counter;
extern int timer0_flag;

extern int timer1_counter;
extern int timer1_flag;

extern int timer2_counter_LED; // timer cho led scan.
extern int timer2_flag_LED;

extern int timer3_counter_LedMatrix; 	//timer cho led matrix
extern int timer3_flag_LedMatrix;

extern int timer5_counter; 	//timer cho LED_RED
extern int timer5_flag;


extern int TIMER_CYCLE;

// Khai báo hàm
void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2_LED(int duration);
void setTimer3(int duration);
void setTimer5(int duration);
void timer_run(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
