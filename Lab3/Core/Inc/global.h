/*
 * global.h
 *
 *  Created on: Nov 23, 2025
 *      Author: TD
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "led7_segment.h"
#include "traffic_light.h"



/*define for timer index*/
#define blinky 8
#define LED7SEG 9
#define light_traffic 0

/*define status for fsm*/

#define INIT 0

#define AUTO_RED_GREEN 1
#define AUTO_RED_YELLOW 2
#define AUTO_GREEN_RED 3
#define AUTO_YELLOW_RED 4

#define MAN_RED 10
#define MAN_GREEN 11
#define MAN_YELLOW 12


#define EDIT_RED 20
#define EDIT_GREEN 21
#define EDIT_YELLOW 22

extern int status;
extern int red_duration;
extern int green_duration;
extern int yellow_duration;

extern int red_edit;
extern int green_edit;
extern int yellow_edit;

extern int led7duration;
extern int count_timer_7SEG;

extern int light_traffic_x_countdown;
extern int light_traffic_y_countdown;



#define toggle 3

#define BT1 0
#define BT2 1
#define BT3 2

void check_timer_and_display(int mode, int duration);


#endif /* INC_GLOBAL_H_ */
