/*
 * fsm_autimatic.c
 *
 *  Created on: Nov 24, 2025
 *      Author: TD
 */


#include "fsm_automatic.h"

void count_second_by_timer7SEG_auto(){
	count_timer_7SEG++;
	if (count_timer_7SEG >= 4){ // equal 1 second
		light_traffic_x_countdown --;
		light_traffic_y_countdown --;
		count_timer_7SEG = 0;
	}
}
void fsm_automatic_run(){
	switch (status) {
		case INIT:
			//TODO
			status = AUTO_RED_GREEN;
			// set edit = normal before run normal
			red_edit = red_duration;
			green_edit = green_duration;
			yellow_edit = yellow_duration;
			/******************************/
			light_traffic_x_countdown = red_duration;
			light_traffic_y_countdown = green_duration;
			display7SEG_X(light_traffic_x_countdown);
			display7SEG_Y(light_traffic_y_countdown);
			setTimer(LED7SEG, led7duration);
			break;
		case AUTO_RED_GREEN:
			//TODO
			light_traffic_redX();
			light_traffic_greenY();
			// change status condition
			if (flag_timer[LED7SEG]){
				count_second_by_timer7SEG_auto(); //count second
				// change status
				if (light_traffic_y_countdown == 0){
					status = AUTO_RED_YELLOW;
					light_traffic_y_countdown = yellow_duration; //set from ms to s
				}
				//display LED7SEG
				display7SEG_X(light_traffic_x_countdown);
				display7SEG_Y(light_traffic_y_countdown);
				setTimer(LED7SEG, led7duration);
			}
			if (isButtonPress(BT1)){
				status = MAN_RED;
				clear_all();
				clear_red_green_yellow();
				setTimer(LED7SEG, led7duration);
			}
			break;
		case AUTO_RED_YELLOW:
			//TODO
			light_traffic_redX();
			light_traffic_yellowY();
			// change status condition
			if (flag_timer[LED7SEG]){
				count_second_by_timer7SEG_auto(); //count second
				// change status
				if (light_traffic_x_countdown == 0 || light_traffic_y_countdown == 0){
					status = AUTO_GREEN_RED;
					light_traffic_x_countdown = green_duration;//set from ms to s
					light_traffic_y_countdown = red_duration; //set from ms to s
				}
				//display LED7SEG
				display7SEG_X(light_traffic_x_countdown);
				display7SEG_Y(light_traffic_y_countdown);
				setTimer(LED7SEG, led7duration);
			}
			if (isButtonPress(BT1)){
				status = MAN_RED;
				clear_all(); // disable EN
				clear_red_green_yellow();
				setTimer(LED7SEG, led7duration);
			}
			break;
		case AUTO_GREEN_RED:
			//TODO
			light_traffic_greenX();
			light_traffic_redY();
			// change status condition
			if (flag_timer[LED7SEG]){
				count_second_by_timer7SEG_auto(); //count second
				// change status
				if (light_traffic_x_countdown == 0){
					status = AUTO_YELLOW_RED;
					light_traffic_x_countdown = yellow_duration;//set from ms to s
				}
				//display LED7SEG
				display7SEG_X(light_traffic_x_countdown);
				display7SEG_Y(light_traffic_y_countdown);
				setTimer(LED7SEG, led7duration);
			}
			if (isButtonPress(BT1)){
				status = MAN_RED;
				clear_all();
				clear_red_green_yellow();
				setTimer(LED7SEG, led7duration);
			}
			break;
		case AUTO_YELLOW_RED:
			//TODO
			light_traffic_yellowX();
			light_traffic_redY();
			// change status condition
			if (flag_timer[LED7SEG]){
				count_second_by_timer7SEG_auto(); //count second
				// change status
				if (light_traffic_x_countdown == 0 || light_traffic_y_countdown == 0){
					status = AUTO_RED_GREEN;
					light_traffic_x_countdown = red_duration;
					light_traffic_y_countdown = green_duration;
				}
				//display LED7SEG
				display7SEG_X(light_traffic_x_countdown);
				display7SEG_Y(light_traffic_y_countdown);
				setTimer(LED7SEG, led7duration);
			}
			if (isButtonPress(BT1)){
				status = MAN_RED;
				clear_all();
				clear_red_green_yellow();
				setTimer(LED7SEG, led7duration);
			}
			break;
		default:
			break;
	}
}
