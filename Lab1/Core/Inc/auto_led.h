/*
 * auto_led.h
 *
 *  Created on: Oct 1, 2025
 *      Author: ASUS
 */

#ifndef INC_AUTO_LED_H_
#define INC_AUTO_LED_H_

void display_led(int num);

void clearAllClock (); //tat tat ca 12 led
void setNumberOnClock(int num); //sáng từ 0->11
void clearNumberOnClock(int num); /// tắt từ 0->11

#endif /* INC_AUTO_LED_H_ */
