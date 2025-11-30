/*
 * software_timer.c
 *
 *  Created on: Nov 30, 2025
 *      Author: TD
 */

#ifndef SRC_SOFTWARE_TIMER_C_
#define SRC_SOFTWARE_TIMER_C_

#include "software_timer.h"

int timer1_counter = 0;
int timer1_flag = 0;

void setTimer(int duration) {
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}

void timer_run(void) {
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter == 0) {
			timer1_flag = 1;
		}
	}
}

int isTimer1Expired(void){
	return timer1_flag;
}

#endif /* SRC_SOFTWARE_TIMER_C_ */
