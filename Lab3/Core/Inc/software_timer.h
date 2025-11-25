/*
 * software_timer.h
 *
 *  Created on: Nov 22, 2025
 *      Author: TD
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define SIZE 10
extern int flag_timer[SIZE];

void setTimer(int index, int duration);		//khởi tạo timer
void runTimer(int index);					//Đếm ngược timer

#endif /* INC_SOFTWARE_TIMER_H_ */
