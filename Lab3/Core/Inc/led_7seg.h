/*
 * led_7seg.h
 *
 *  Created on: Oct 7, 2025
 *      Author: ASUS
 */

#ifndef INC_LED_7SEG_H_
#define INC_LED_7SEG_H_

extern int hour , minute , second ;


void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer();
#endif /* INC_LED_7SEG_H_ */
