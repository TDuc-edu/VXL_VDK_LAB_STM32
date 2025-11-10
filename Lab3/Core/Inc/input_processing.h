/*
 * input_processing.h
 *
 *  Created on: Nov 3, 2025
 *      Author: ASUS
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

/* ============================================================================
 * EXERCISE 5: MODE MANAGEMENT
 * ============================================================================
 * Module xử lý chuyển đổi mode và quản lý trạng thái mode
 * ============================================================================
 */

// ==================== MODE DEFINITIONS ====================
typedef enum {
    MODE_1_NORMAL = 1,          // Mode 1: Đèn giao thông hoạt động bình thường
    MODE_2_RED_MODIFY = 2,      // Mode 2: Chỉnh thời gian đèn đỏ
    MODE_3_AMBER_MODIFY = 3,    // Mode 3: Chỉnh thời gian đèn vàng
    MODE_4_GREEN_MODIFY = 4     // Mode 4: Chỉnh thời gian đèn xanh
} SystemMode;

// ==================== GLOBAL VARIABLE ====================
extern int current_mode;  // Biến toàn cục lưu mode hiện tại

// ==================== PUBLIC FUNCTIONS ====================

/**
 * @brief  FSM xử lý button MODE để chuyển đổi mode
 * @note   Gọi trong main loop
 */
void fsm_for_input_processing(void);

/**
 * @brief  Lấy mode hiện tại
 * @retval Mode hiện tại (1-4)
 */
int get_current_mode(void);

/**
 * @brief  Set mode hiện tại
 * @param  mode: Mode muốn set (1-4)
 */
void set_current_mode(int mode);

#endif /* INC_INPUT_PROCESSING_H_ */

