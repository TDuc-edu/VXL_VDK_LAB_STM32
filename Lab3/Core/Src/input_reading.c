/*
 * input_reading.c
 *
 *  Created on: Nov 3, 2025
 *      Author: TD
 */

#include "main.h"
#include "input_reading.h"

/* ============================================================================
 * EXERCISE 5: BUTTON READING & DEBOUNCING IMPLEMENTATION
 * ============================================================================
 * Xử lý 3 buttons cho traffic light system:
 * - Button 0 (MODE): Chuyển mode 1→2→3→4→1
 * - Button 1 (INCREASE): Tăng giá trị thời gian
 * - Button 2 (SET): Xác nhận giá trị
 * 
 * Kỹ thuật debouncing: So sánh 2 lần đọc liên tiếp
 * Long press detection: Đếm thời gian giữ button > 1s
 * ============================================================================
 */

// ==================== CONFIGURATION ====================
#define N0_OF_BUTTONS                   3       // 3 buttons cho Lab 3
#define DURATION_FOR_AUTO_INCREASING    100     // 100 x 10ms = 1000ms = 1s
#define BUTTON_IS_PRESSED               GPIO_PIN_RESET
#define BUTTON_IS_RELEASED              GPIO_PIN_SET

// ==================== INTERNAL BUFFERS ====================

// Buffer lưu kết quả cuối cùng sau debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];

// 2 buffers cho debouncing (N=2 filtering)
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

// Flag phát hiện button pressed edge (1 lần duy nhất khi nhấn)
static uint8_t buttonPressedFlag[N0_OF_BUTTONS];

// Flag cho button pressed > 1s
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];

// Counter đếm thời gian button được giữ
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

// ==================== BUTTON PIN MAPPING ====================
// TODO: Cấu hình pins trong STM32CubeMX:
// - Button 1 (MODE):     PA0 hoặc PC13 (tùy board)
// - Button 2 (INCREASE): PA1
// - Button 3 (SET):      PA2

/* ============================================================================
 * FUNCTION: button_reading
 * ============================================================================
 * Đọc và xử lý tất cả buttons
 * - Debouncing với N=2 filter
 * - Edge detection (phát hiện cạnh nhấn)
 * - Long press detection (> 1s)
 * 
 * GỌI TRONG TIMER INTERRUPT MỖI 10ms!
 * ============================================================================
 */
void button_reading(void) {
    for(uint8_t i = 0; i < N0_OF_BUTTONS; i++) {
        // ===== BƯỚC 1: DEBOUNCING =====
        // Lưu trạng thái lần đọc trước
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        
        // Đọc trạng thái hiện tại từ hardware
        switch(i) {
            case 0: // Button MODE
                debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin);
                break;
            case 1: // Button INCREASE
                debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
                break;
            case 2: // Button SET
                debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
                break;
        }
        
        // So sánh 2 lần đọc: nếu giống nhau → stable
        if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) {
            // ===== BƯỚC 2: EDGE DETECTION =====
            // Phát hiện cạnh xuống (pressed edge)
            if(buttonBuffer[i] == BUTTON_IS_RELEASED && 
               debounceButtonBuffer1[i] == BUTTON_IS_PRESSED) {
                // Button vừa được nhấn xuống → set flag
                buttonPressedFlag[i] = 1;
            }
            
            // Cập nhật buffer
            buttonBuffer[i] = debounceButtonBuffer1[i];
        }
        
        // ===== BƯỚC 3: LONG PRESS DETECTION =====
        if(buttonBuffer[i] == BUTTON_IS_PRESSED) {
            // Button đang được giữ → tăng counter
            if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
                counterForButtonPress1s[i]++;
            } else {
                // Đã giữ > 1s → set flag long press
                flagForButtonPress1s[i] = 1;
            }
        } else {
            // Button released → reset counters
            counterForButtonPress1s[i] = 0;
            flagForButtonPress1s[i] = 0;
        }
    }
}

/* ============================================================================
 * FUNCTION: is_button_pressed
 * ============================================================================
 * Kiểm tra button có được nhấn không (EDGE DETECTION)
 * 
 * @param index: Button index (0-2)
 * @return: 1 nếu button VỪA MỚI được nhấn, 0 nếu không
 * 
 * QUAN TRỌNG:
 * - Trả về 1 CHỈ 1 LẦN duy nhất khi button được nhấn xuống
 * - Flag tự động clear sau khi đọc
 * - Dùng cho: Chuyển mode, tăng giá trị từng bước
 * ============================================================================
 */
unsigned char is_button_pressed(uint8_t index) {
    // Kiểm tra index hợp lệ
    if(index >= N0_OF_BUTTONS) return 0;
    
    // Đọc và clear flag (one-shot)
    if(buttonPressedFlag[index] == 1) {
        buttonPressedFlag[index] = 0;  // Clear flag
        return 1;
    }
    
    return 0;
}

/* ============================================================================
 * FUNCTION: is_button_pressed_1s
 * ============================================================================
 * Kiểm tra button có được giữ > 1s không (LONG PRESS)
 * 
 * @param index: Button index (0-2)
 * @return: 1 nếu button đang được giữ > 1s, 0 nếu không
 * 
 * QUAN TRỌNG:
 * - Trả về 1 LIÊN TỤC khi button được giữ
 * - Không clear flag (flag chỉ clear khi release button)
 * - Dùng cho: Auto-increment giá trị
 * ============================================================================
 */
unsigned char is_button_pressed_1s(unsigned char index) {
    // Kiểm tra index hợp lệ
    if(index >= N0_OF_BUTTONS) return 0;
    
    // Trả về trạng thái long press flag
    return (flagForButtonPress1s[index] == 1);
}

/* ============================================================================
 * VÍ DỤ SỬ DỤNG:
 * ============================================================================
 * 
 * // 1. Trong timer interrupt callback (main.c hoặc stm32f1xx_it.c):
 * void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
 *     if(htim->Instance == TIM2) {
 *         button_reading();  // Gọi mỗi 10ms
 *     }
 * }
 * 
 * // 2. Trong main loop - Chuyển mode:
 * if(is_button_pressed(BUTTON_MODE)) {
 *     current_mode++;
 *     if(current_mode > 4) current_mode = 1;
 * }
 * 
 * // 3. Trong main loop - Tăng giá trị:
 * if(is_button_pressed(BUTTON_INCREASE)) {
 *     temp_value++;  // Tăng 1 lần khi nhấn
 * }
 * 
 * // 4. Trong main loop - Auto-increment:
 * if(is_button_pressed_1s(BUTTON_INCREASE)) {
 *     if(timer_flag_500ms) {  // Tăng mỗi 500ms
 *         temp_value++;
 *     }
 * }
 * 
 * // 5. Trong main loop - Set giá trị:
 * if(is_button_pressed(BUTTON_SET)) {
 *     red_duration = temp_value;  // Lưu giá trị
 *     current_mode = 1;           // Về mode normal
 * }
 * 
 * ============================================================================
 */
