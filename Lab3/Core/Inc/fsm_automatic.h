/*
 * fsm_automatic.h
 *
 *  Created on: Nov 10, 2025
 *      Author: ASUS
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include<global.h>
#define RED_GREEN 				0
#define RED_YELLOW 				1
#define	GREEN_RED				2
#define YELLOW_RED				3
extern int state_automatic;
extern int lane1;
extern int lane2;
void fsm_automatic_run();
void come_back_auto();
void init_RED_GREEN();
void init_RED_YELLOW();
void init_GREEN_RED();
void init_YELLOW_RED();
#endif /* INC_FSM_AUTOMATIC_H_ */
