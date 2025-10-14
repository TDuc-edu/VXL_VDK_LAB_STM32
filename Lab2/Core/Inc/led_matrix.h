/*
 * led_matrix.h
 *
 *  Created on: Oct 15, 2025
 *      Author: ASUS
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_

#include "main.h"


// Biến toàn cục
extern int index_led_matrix;
extern uint8_t matrix_buffer[8];

// Hàm chính
void updateLEDMatrix(int index);
void setMatrixChar(const uint8_t* pattern);

// Ký tự mẫu
extern const uint8_t CHAR_A[8];
extern const uint8_t CHAR_B[8];
extern const uint8_t CHAR_C[8];

#endif
