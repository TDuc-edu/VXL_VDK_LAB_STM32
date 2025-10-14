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

int timer2_counter_LED = 0;
int timer2_flag_LED = 0;

int timer3_counter_LedMatrix = 0; 	//timer cho led matrix
int timer3_flag_LedMatrix = 0 ;

int TIMER_CYCLE = 10;  // Chu kỳ ngắt timer (10ms)

/**
 *  Thiết lập timer 0
 *   duration: Thời gian đếm (ms)
 */
void setTimer0(int duration) {
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}

//  Thiết lập timer 1

void setTimer1(int duration) {
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}

void setTimer2_LED(int duration) {
	timer2_counter_LED = duration / TIMER_CYCLE;
	timer2_flag_LED = 0;
}

void setTimer3(int duration) {
	timer3_counter_LedMatrix = duration / TIMER_CYCLE;
	timer3_flag_LedMatrix = 0;
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

	// Timer2
    if (timer2_counter_LED > 0) {
        timer2_counter_LED--;
        if (timer2_counter_LED == 0)
            timer2_flag_LED = 1;
    }

	// Timer3
    if (timer3_counter_LedMatrix > 0) {
        timer3_counter_LedMatrix--;
        if (timer3_counter_LedMatrix == 0)
            timer3_flag_LedMatrix = 1;
    }
}
