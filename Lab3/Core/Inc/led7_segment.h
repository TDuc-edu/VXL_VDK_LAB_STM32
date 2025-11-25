/*
 * led7_segment.h
 *
 *  Created on: Nov 23, 2025
 *      Author: TD
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "main.h"
#include "global.h"


#define NO_OF_7SEG 4

extern int led7_buffer[NO_OF_7SEG];

void display7SEG(int num);
void update7SEG(int index);
void update_buffer_mode(int mode, int value);	//hàm hiển thị mode
void update_buffer_time(int time1, int time2);	//hàm hiển thị thời gian đếm ngược


void display7SEG_X(int time);  // Hiển thị thời gian X
void display7SEG_Y(int time);  // Hiển thị thời gian Y
void clear_all(void);          // Tắt tất cả LED 7-segment

#endif /* INC_LED7_SEGMENT_H_ */
