/*
 * global.h
 *
 *  Created on: Nov 10, 2025
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include<main.h>
#include<math.h>
#include<button.h>
#include<7_SEGMENT.h>
#include<fsm_automatic.h>
#include<fsm_manual.h>
#include<timer.h>
#include<led.h>
//define same state here

#define TIMER_CYCLE 10
#define LED_SEGMENT_CYCLE 	200
#define SECOND				1000
#define INIT				0
#define ACTIVE_MODE 		1			//active mode have to function running and changeled
#define MANUAL_MODE			2

#define RUNNING				1
#define RED					5
#define GREEN				3
#define YELLOW				4

#define CHANGE_LED			2

// modify time
extern int pro_mode; // pro_mode
extern int Time_red;
extern int Time_green;
extern int Time_yellow;

void run();
#endif /* INC_GLOBAL_H_ */
