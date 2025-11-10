/*
 * fsm_manual.c
 *
 *  Created on: Nov 10, 2025
 *      Author: ASUS
 */

#include<fsm_manual.h>

int temp_red;
int temp_green;
int temp_yellow;
int state_manual = 0;
void init_fsm_manual() {
	state_manual = RED;
	init_Blink_led(state_manual);
	Setup_time(TIME_COUNT_PROGRAM, 15000);
	Setup_time(ONE_SECOND, 1000);
	temp_red = Time_red;
	temp_green = Time_green;
	temp_yellow = Time_yellow;
	is_TIME_Pressed();
}

void fsm_manual() {
	if (actions[TIME_COUNT_PROGRAM].timer_flag == 1) {
		pro_mode = ACTIVE_MODE;
		come_back_auto();
		return;
	}
	if (is_SET_Pressed()) {
		pro_mode = ACTIVE_MODE;
		//continue
		// proces to make yellow, green and red is suitable for traffic lamp
		switch (state_manual) {
		case RED:
			if (temp_red < Time_red) {
				Time_red = temp_red;
				Time_green = ceil(Time_red * 0.6);
				Time_yellow = Time_red - Time_green;
			}
			if (temp_red > Time_red) {
				Time_green = Time_green + ceil((temp_red - Time_red) * 0.6);
				Time_yellow = temp_red - Time_green;
				Time_red = temp_red;
			}

			/* code */
			break;
		case GREEN:
			Time_green = temp_green;
			Time_red = Time_green + Time_yellow;
			break;
		case YELLOW:
			Time_yellow = temp_yellow;
			Time_red = Time_green + Time_yellow;
			break;
		default:
			break;
		}

		come_back_auto();

		return;
	}
	if (is_MODE_Pressed()) {
		switch (state_manual) {
		case RED:
			state_manual = GREEN;
			/* code */
			break;
		case GREEN:
			state_manual = YELLOW;
			/* code */
			break;
		case YELLOW:
			pro_mode = ACTIVE_MODE;
			come_back_auto();
			return;

			break;
		default:
			break;
		}
		init_Blink_led(state_manual);
		return;
	}

	if (is_TIME_Pressed()) {
		switch (state_manual) {
		case RED:
			temp_red = (temp_red + 1) % 100;

			/* code */
			break;
		case GREEN:
			temp_green = (temp_green + 1) % 100;
			/* code */
			break;
		case YELLOW:
			temp_yellow = (temp_yellow + 1) % 100;
			break;
		default:
			break;
		}
	}

	if (actions[ONE_SECOND].timer_flag == 1) {
		reset(ONE_SECOND);
		Blink_led(state_manual);
	} // Blink led

	// Chỉ update display khi có thay đổi từ timer
	if (actions[TIME_SEGMENT].timer_flag == 1) {
		switch (state_manual) {
		case RED:
			/* code */
			run_led(1, temp_red);
			break;
		case GREEN:
			/* code */
			run_led(2, temp_green);
			break;
		case YELLOW:
			run_led(3, temp_yellow);
			break;
		default:
			break;
		}
	} // 7 SEGMENT
}
