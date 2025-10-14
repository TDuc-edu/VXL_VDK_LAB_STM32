/*
 * software_timer.c
 *
 *  Created on: Oct 15, 2025
 *      Author: ASUS
 */

#include "software_timer.h"

// Biến toàn cục cho timer
int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int TIMER_CYCLE = 10;  // Chu kỳ ngắt timer (10ms)

/**
 *  Thiết lập timer 0
 *   duration: Thời gian đếm (ms)
 */
void setTimer0(int duration) {
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}

/**
 *   Thiết lập timer 1
 *   duration: Thời gian đếm (ms)
 */
void setTimer1(int duration) {
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}

/**
 *  Hàm chạy timer (gọi trong ngắt)
 */
void timer_run(void) {
	// Timer 0
	if (timer0_counter > 0) {
		timer0_counter--;
		if (timer0_counter == 0)
			timer0_flag = 1;
	}

	// Timer 1
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter == 0)
			timer1_flag = 1;
	}
}
