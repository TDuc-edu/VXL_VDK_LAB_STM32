/*
 * global.c
 *
 *  Created on: Nov 23, 2025
 *      Author: TD
 */


#include "global.h"


int status = 0;
int red_duration = 0;
int green_duration = 0;
int yellow_duration = 0;

int red_edit = 0;
int green_edit = 0;
int yellow_edit = 0;

int count_timer_7SEG = 0;
int led7duration = 250;


int light_traffic_x_countdown = 0;
int light_traffic_y_countdown = 0;

void check_timer_and_display(int mode, int duration){
	if (flag_timer[LED7SEG]){
		count_timer_7SEG++;
		if (count_timer_7SEG >= 4)
			count_timer_7SEG = 0;
		if (count_timer_7SEG % 2 == 0){
			if (mode == 2)
				toggle_all_red();
			else if (mode == 3)
				toggle_all_green();
			else if (mode == 4)
				toggle_all_yellow();
			else ;
		}

		display7SEG_X(mode);
		display7SEG_Y(duration);
		setTimer(LED7SEG, led7duration);
	}
}
