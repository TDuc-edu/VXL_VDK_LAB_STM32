/*
 * led_display.h
 *
 *  Created on: Nov 10, 2025
 *      Author: ASUS
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#define INC_LED_H_
#include<global.h>
#define RED_1               0
#define RED_2               1
#define GREEN_1             2
#define GREEN_2             3
#define YELLOW_1            4
#define YELLOW_2            5

void turn_on_LED(int Pos);
void turn_off_LED(int Pos);

void init_Blink_led(int color_of_led);
void Blink_led(int color_of_led);

#endif /* INC_LED_H_ */
