/*
 * software_timer.c
 *
 *  Created on: Oct 15, 2025
 *      Author: ASUS
 */

#include <timer.h>

detail_time actions[NUMBER_OF_ACTIONS];
void Setup_time(int index, int duration) {
	actions[index].time = duration / TIMER_CYCLE;
	actions[index].timer_counter = duration / TIMER_CYCLE;
	actions[index].timer_flag = 0;
}

void reset(int index) {
	actions[index].timer_counter = actions[index].time;
	actions[index].timer_flag = 0;
}

void timer_run() {
	for (int i = 0; i < NUMBER_OF_ACTIONS; i++) {
		if (actions[i].timer_counter > 0) {
			actions[i].timer_counter--;
			if (actions[i].timer_counter <= 0) {
				actions[i].timer_flag = 1;
			}
		}

	}
}
