/*
 * led7_segment.h
 *
 *  Created on: Nov 23, 2025
 *      Author: TD
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

void display7SEG();
void clear_all();

void turn_on_1();	//7-segment led 1
void turn_on_2();	//7-segment led 2
void turn_on_3();	//7 segment led 3
void turn_on_4();	//7	segment	led 4

void display7SEG_X(int time);	//led 1 2
void display7SEG_Y(int time);	//led 3 4

#endif /* INC_LED7_SEGMENT_H_ */
