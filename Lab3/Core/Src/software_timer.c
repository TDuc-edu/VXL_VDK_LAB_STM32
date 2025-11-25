/*
 * software_timer.c
 *
 *  Created on: Nov 22, 2025
 *      Author: TD
 */

#include "software_timer.h"

int flag_timer[SIZE];
int timer_counter[SIZE];
int TIMER_CYCLE = 10;
;

void setTimer(int index, int duration) {
	timer_counter[index] = duration / TIMER_CYCLE;
	flag_timer[index] = 0;
}

void runTimer(int index) {
	if (timer_counter[index] > 0) {
		timer_counter[index]--;
		if (timer_counter[index] <= 0) {
			flag_timer[index] = 1;
		}
	}
}
