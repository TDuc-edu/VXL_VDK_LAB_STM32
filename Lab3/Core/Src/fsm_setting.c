/*
 * fsm_setting.c
 *
 *  Created on: Nov 24, 2025
 *      Author: TD
 */


#include "fsm_setting.h"

void fsm_setting_run(){
	switch (status) {
		case EDIT_RED:
			//TODO
			check_timer_and_display(2, red_edit);
			if (isButtonPress(BT1)){} // use for turn of flag
			if (isButtonPress(BT2)){
				red_edit++;
				if (red_edit > 99)
					red_edit = 1;
			}
			if (isButtonPress(BT3)){
				red_duration = red_edit;
				status = MAN_RED;
				setTimer(LED7SEG, led7duration);
			}
			break;
		case EDIT_GREEN:
			//TODO
			if (isButtonPress(BT1)){} // use for turn of flag
			check_timer_and_display(3, green_edit);
			if (isButtonPress(BT2)){
				green_edit++;
				if (green_edit > 99)
					green_edit = 1;
			}
			if (isButtonPress(BT3)){
				green_duration = green_edit;
				status = MAN_GREEN;
				setTimer(LED7SEG, led7duration);
			}

			break;
		case EDIT_YELLOW:
			//TODO
			check_timer_and_display(4, yellow_edit);
			if (isButtonPress(BT1)){} // use for turn of flag
			if (isButtonPress(BT2)){
				yellow_edit++;
				if (yellow_edit > 99)
					yellow_edit = 1;
			}
			if (isButtonPress(BT3)){
				yellow_duration = yellow_edit;
				status = MAN_YELLOW;
				setTimer(LED7SEG, led7duration);
			}

			break;
		default:
			break;
	}
}
