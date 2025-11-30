/*
 * software_timer.h
 *
 *  Created on: Nov 30, 2025
 *      Author: TD
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIMER_CYCLE 10	// 10ms per tick

//Timer 1 variable
extern int timer1_counter;
extern int timer1_flag;

// function prototypes
void setTimer1(int duration);
void timer_run(void);
int isTimer1Expired(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
