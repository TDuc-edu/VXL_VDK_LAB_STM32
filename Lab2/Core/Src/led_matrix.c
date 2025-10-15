/*
 * led_matrix.c
 *
 *  Created on: Oct 15, 2025
 *      Author: ASUS
 */


#include "led_matrix.h"


// Biến
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x00, 0xFC, 0xFE, 0x33, 0x33, 0xFE, 0xFC, 0x00};

// Animation
int current_frame = 0;
int total_frames = 0;
const uint8_t (*animation_data)[8] = NULL;

// Ký tự A
const uint8_t CHAR_A[8] = {0x00, 0xFC, 0xFE, 0x33, 0x33, 0xFE, 0xFC, 0x00};

// Ký tự B
const uint8_t CHAR_B[8] = {0x00, 0xFF, 0xFF, 0x99, 0x99, 0xFF, 0x66, 0x00};

// Ký tự C
const uint8_t CHAR_C[8] = {0x00, 0x7E, 0xFF, 0xC3, 0xC3, 0xC3, 0x42, 0x00};


// Giải mã 8 bit → 8 hàng ROW
void decodeLed(uint8_t _8bit_led_) {
    uint16_t ROW[8] = {ROW0_Pin, ROW1_Pin, ROW2_Pin, ROW3_Pin,
                       ROW4_Pin, ROW5_Pin, ROW6_Pin, ROW7_Pin};

    for (int i = 0; i < 8; i++) {
        if (_8bit_led_ & (1 << i)) {
            HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW[i], RESET);  // LED ON
        } else {
            HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW[i], SET);    // LED OFF
        }
    }
}

// Cập nhật LED Matrix tại cột index
void updateLEDMatrix(int index) {
    // Tắt tất cả cột
    HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin |
                                      ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin, SET);

    // Gửi dữ liệu hàng
    decodeLed(matrix_buffer[index]);

    // Bật cột tương ứng
    switch (index) {
        case 0: HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET); break;
        case 1: HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET); break;
        case 2: HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET); break;
        case 3: HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET); break;
        case 4: HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET); break;
        case 5: HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET); break;
        case 6: HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET); break;
        case 7: HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET); break;
    }
}

// Đổi ký tự hiển thị
void setMatrixChar(const uint8_t* pattern) {
    for (int i = 0; i < 8; i++) {
        matrix_buffer[i] = pattern[i];
    }
}

void shiftMatrixRight(void) {
    uint8_t temp = matrix_buffer[7];  // Lưu cột cuối

    // Dịch tất cả sang phải
    for (int i = 7; i > 0; i--) {
        matrix_buffer[i] = matrix_buffer[i - 1];
    }

    matrix_buffer[0] = temp;  // Cột cuối → Cột đầu
}

/**
 * @brief  Dịch chuyển buffer sang TRÁI
 * @note   Cột 0 → Cột 7 (vòng tròn)
 */
void shiftMatrixLeft(void) {
    uint8_t temp = matrix_buffer[0];  // Lưu cột đầu

    // Dịch tất cả sang trái
    for (int i = 0; i < 7; i++) {
        matrix_buffer[i] = matrix_buffer[i + 1];
    }

    matrix_buffer[7] = temp;  // Cột đầu → Cột cuối
}
