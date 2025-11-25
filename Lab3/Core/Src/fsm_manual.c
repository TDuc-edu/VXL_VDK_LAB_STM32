/*
 * fsm_manual.c
 *
 *  Created on: Nov 24, 2025
 *      Author: TD
 */


#include "fsm_manual.h"

void fsm_manual_run(){
	switch (status) {
		case MAN_RED:
			//TODO
			check_timer_and_display(2, red_duration);
			//change status
			if (isButtonPress(BT1)){
				status = MAN_GREEN;
				clear_red_green_yellow();
				setTimer(LED7SEG, led7duration);
			}
			if (isButtonPress(BT2)){
				// change EDIT
				status = EDIT_RED;
				red_edit++;
				if (red_edit > 99)
					red_edit = 1;
				setTimer(LED7SEG, led7duration);
			}

			break;
		case MAN_GREEN:
			//TODO
			check_timer_and_display(3, green_duration);
			//change status
			if (isButtonPress(BT1)){
				status = MAN_YELLOW;
				clear_red_green_yellow();
				setTimer(LED7SEG, led7duration);
			}
			if (isButtonPress(BT2)){
				status = EDIT_GREEN;
				green_edit++;
				if (green_edit > 99)
					green_edit = 1;
				setTimer(LED7SEG, led7duration);
			}
			break;
		case MAN_YELLOW:
			//TODO
			check_timer_and_display(4, yellow_duration);
			//change status
			if (isButtonPress(BT1)){
				status = INIT;
				setTimer(LED7SEG, led7duration);
			}
			if (isButtonPress(BT2)){
				status = EDIT_YELLOW;
				yellow_edit++;
				if (yellow_edit > 99)
					yellow_edit = 1;
				setTimer(LED7SEG, led7duration);
			}
			break;
		default:
			break;
	}
}
