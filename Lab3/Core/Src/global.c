/*
 * global.c
 *
 *  Created on: Nov 10, 2025
 *      Author: ASUS
 */

#include<global.h>

int pro_mode = 0;
int Time_red = 5;
int Time_green = 3;
int Time_yellow = 2;

void run() {
	switch (pro_mode) {
	case INIT:
		pro_mode = ACTIVE_MODE;
		/*code for init active mode*/
		Setup_time(TIME_SEGMENT, LED_SEGMENT_CYCLE / 4);
		Setup_time(ONE_SECOND, 1000);
		init_RED_GREEN();
		break;
	case ACTIVE_MODE:
		fsm_automatic_run();
		break;
	case MANUAL_MODE:
		fsm_manual();
	default:
		break;
	}
}
