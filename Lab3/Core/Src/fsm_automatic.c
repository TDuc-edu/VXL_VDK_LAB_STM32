/*
 * fsm_automatic.c
 *
 *  Created on: Nov 10, 2025
 *      Author: ASUS
 */

#include<fsm_automatic.h>

int state_automatic = 0;
int lane1 = 0;
int lane2 = 0;

void fsm_automatic_run() {
	if (is_MODE_Pressed()) {
		pro_mode = MANUAL_MODE;
		init_fsm_manual();
		return;
	}
	if (actions[ONE_SECOND].timer_flag == 1) {
		lane1--;
		lane2--;
		reset(ONE_SECOND);
	}
	if (actions[TIME_COUNT_PROGRAM].timer_flag == 1) {
		switch (state_automatic) {
		case RED_GREEN:
			init_RED_YELLOW();
			break;
		case RED_YELLOW:
			init_GREEN_RED();
			break;
		case GREEN_RED:
			init_YELLOW_RED();
			break;
		case YELLOW_RED:
			init_RED_GREEN();
			break;
		default:
			break;
		}
	}

	// Chỉ update display khi có thay đổi từ timer
	if (actions[TIME_SEGMENT].timer_flag == 1 || actions[ONE_SECOND].timer_flag == 1) {
		run_led(lane1, lane2);
	}
}
void come_back_auto() {
	switch (state_automatic) {
	case RED_GREEN:
		init_RED_GREEN();
		break;
	case RED_YELLOW:
		init_RED_YELLOW();
		break;
	case GREEN_RED:
		init_GREEN_RED();
		break;
	case YELLOW_RED:
		init_YELLOW_RED();
	default:
		break;
	}
}

void init_RED_GREEN() {
	turn_on_LED(RED_1);
	turn_on_LED(GREEN_2);

	turn_off_LED(RED_2);
	turn_off_LED(GREEN_1);
	turn_off_LED(YELLOW_1);
	turn_off_LED(YELLOW_2);

	state_automatic = RED_GREEN;
	Setup_time(TIME_COUNT_PROGRAM, Time_green * 1000);
	lane1 = Time_red;
	lane2 = Time_green;
	reset(ONE_SECOND);

}
void init_RED_YELLOW() {
	turn_on_LED(RED_1);
	turn_on_LED(YELLOW_2);
	//led turn on
	turn_off_LED(RED_2);
	turn_off_LED(GREEN_1);
	turn_off_LED(YELLOW_1);
	turn_off_LED(GREEN_2);
	//led turn off
	state_automatic = RED_YELLOW;
	Setup_time(TIME_COUNT_PROGRAM, Time_yellow * 1000);
	lane2 = Time_yellow;
	reset(ONE_SECOND);
}
void init_GREEN_RED() {
	turn_on_LED(GREEN_1);
	turn_on_LED(RED_2);
	//led turn on
	turn_off_LED(RED_1);
	turn_off_LED(GREEN_2);
	turn_off_LED(YELLOW_1);
	turn_off_LED(YELLOW_2);
	//led turn off
	state_automatic = GREEN_RED;
	Setup_time(TIME_COUNT_PROGRAM, Time_green * 1000);
	lane1 = Time_green;
	lane2 = Time_red;
	reset(ONE_SECOND);
}
void init_YELLOW_RED() {
	turn_on_LED(RED_2);
	turn_on_LED(YELLOW_1);
	//led turn on
	turn_off_LED(RED_1);
	turn_off_LED(GREEN_1);
	turn_off_LED(YELLOW_2);
	turn_off_LED(GREEN_2);
	//led turn off
	state_automatic = YELLOW_RED;
	Setup_time(TIME_COUNT_PROGRAM, Time_yellow * 1000);
	lane1 = Time_yellow;
	reset(ONE_SECOND);
}
