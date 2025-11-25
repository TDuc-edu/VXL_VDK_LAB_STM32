/*
 * led7_segment.c
 *
 *  Created on: Nov 23, 2025
 *      Author: TD
 */

#include "led7_segment.h"

extern int count_timer_7SEG;


uint8_t segment_code[10] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
		0x80, 0x90 };

int led7_buffer[NO_OF_7SEG] = { 0, 0, 0, 0 };

void update_buffer_mode(int mode, int value) {
	led7_buffer[0] = mode / 10;
	led7_buffer[1] = mode % 10;
	led7_buffer[2] = value / 10;
	led7_buffer[3] = value % 10;
}

void update_buffer_time(int time1, int time2) {
	led7_buffer[0] = time1 / 10;
	led7_buffer[1] = time1 % 10;
	led7_buffer[2] = time2 / 10;
	led7_buffer[3] = time2 % 10;
}

void display7SEG(int num) {
	// Lấy mã hex tương ứng
	uint8_t code = segment_code[num];


	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, ((code >> 0) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, ((code >> 1) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, ((code >> 2) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, ((code >> 3) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, ((code >> 4) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, ((code >> 5) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, ((code >> 6) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);


}

void update7SEG(int index) {

	HAL_GPIO_WritePin(GPIOA,
	GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12, GPIO_PIN_SET);

	// bật led tại vị trí index
	switch (index) {
	case 0:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	case 1:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
	case 2:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
	case 3:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
	default:
		break;

	}
}


void display7SEG_X(int time) {
    // Hiển thị thời gian trên LED1 và LED2
    int digit1 = time / 10;  // Hàng chục
    int digit2 = time % 10;  // Hàng đơn vị

    led7_buffer[0] = digit1;
    led7_buffer[1] = digit2;
}

void display7SEG_Y(int time) {
    // Hiển thị thời gian trên LED3 và LED4
    int digit1 = time / 10;  // Hàng chục
    int digit2 = time % 10;  // Hàng đơn vị

    led7_buffer[2] = digit1;
    led7_buffer[3] = digit2;
}

void clear_all(void) {
    // Tắt tất cả 4 LED 7-segment
    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
}
