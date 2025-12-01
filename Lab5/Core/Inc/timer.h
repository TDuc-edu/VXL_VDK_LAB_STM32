/*
 * timer.h
 *
 *  Created on: NOV 30, 2025
 *      Author: TD
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

/* Define */
#define NO_Timer 1
#define TIME_CYCLE 10

/* Function -----*/
//Set time on timer[index] = duration
void setTimer(int duration, int index);
//Check timer out on timer[index]
int isTimerOut(int index);
//Run timer (counter on timer)
void timerRun(void);

#endif /* INC_TIMER_H_ */
