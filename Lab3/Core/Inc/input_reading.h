/*
 * input_reading.h
 *
 *  Created on: Nov 3, 2025
 *      Author: ASUS
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

/* ============================================================================
 * EXERCISE 5: BUTTON READING & DEBOUNCING FOR 3 BUTTONS
 * ============================================================================
 * Module này xử lý:
 * - Đọc trạng thái 3 buttons
 * - Debouncing (chống dội)
 * - Phát hiện nhấn ngắn và nhấn giữ (long press)
 * ============================================================================
 */

// ==================== BUTTON INDEX DEFINITIONS ====================
#define BUTTON_MODE     0   // Button 1: Chọn mode (1→2→3→4→1)
#define BUTTON_INCREASE 1   // Button 2: Tăng giá trị thời gian
#define BUTTON_SET      2   // Button 3: Xác nhận/set giá trị

// ==================== PUBLIC FUNCTIONS ====================

/**
 * @brief  Đọc và xử lý trạng thái tất cả buttons (gọi trong timer interrupt)
 * @note   Phải được gọi mỗi 10ms trong HAL_TIM_PeriodElapsedCallback
 */
void button_reading(void);

/**
 * @brief  Kiểm tra button có được nhấn không (edge detection)
 * @param  index: Chỉ số button (0-2)
 * @retval 1 nếu button vừa được nhấn (pressed edge), 0 nếu không
 * @note   Trả về 1 CHỈ 1 LẦN khi button được nhấn xuống
 */
unsigned char is_button_pressed(unsigned char index);

/**
 * @brief  Kiểm tra button có được nhấn giữ > 1s không
 * @param  index: Chỉ số button (0-2)
 * @retval 1 nếu button đang được giữ > 1s, 0 nếu không
 * @note   Trả về 1 LIÊN TỤC khi button được giữ
 */
unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
