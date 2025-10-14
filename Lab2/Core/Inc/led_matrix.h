/*
 * led_matrix.h
 *
 *  Created on: Oct 15, 2025
 *      Author: ASUS
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_

#include "main.h"


// Biến global
extern int index_led_matrix;
extern uint8_t matrix_buffer[8];
// Animation
extern int current_frame;
extern int total_frames;

// Hàm chính
void updateLEDMatrix(int index);
void setMatrixChar(const uint8_t* pattern);

// Hàm animation
void initAnimation(const uint8_t animation[][8], int num_frames);
void nextFrame(void);
void shiftLeft(void);
void shiftRight(void);

// Ký tự mẫu
extern const uint8_t CHAR_A[8];
extern const uint8_t CHAR_B[8];
extern const uint8_t CHAR_C[8];
extern const uint8_t ANIMATION_WALKING[8][8];  // Người đi bộ

#endif
