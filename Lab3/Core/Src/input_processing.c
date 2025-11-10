/*
 * input_processing.c
 *
 *  Created on: Nov 3, 2025
 *      Author: TD
 */

#include "main.h"
#include "input_reading.h"
#include "input_processing.h"

/* ============================================================================
 * EXERCISE 5: MODE SWITCHING FSM
 * ============================================================================
 * FSM xử lý mode switching cho traffic light system
 * - Mode 1: Normal mode (đèn giao thông hoạt động bình thường)
 * - Mode 2: Modify red LED duration
 * - Mode 3: Modify amber LED duration
 * - Mode 4: Modify green LED duration
 * ============================================================================
 */

// ==================== GLOBAL VARIABLES ====================
int current_mode = MODE_1_NORMAL;  // Chế độ hiện tại

/* ============================================================================
 * FUNCTION: fsm_for_input_processing (MODE BUTTON)
 * ============================================================================
 * FSM xử lý button MODE để chuyển đổi giữa các mode
 * Mode transition: 1 → 2 → 3 → 4 → 1 (circular)
 * ============================================================================
 */
void fsm_for_input_processing(void) {
    // Kiểm tra button MODE được nhấn
    if(is_button_pressed(BUTTON_MODE)) {
        // Chuyển sang mode tiếp theo
        current_mode++;
        
        // Nếu vượt quá mode 4, quay về mode 1
        if(current_mode > MODE_4_GREEN_MODIFY) {
            current_mode = MODE_1_NORMAL;
        }
        
        // TODO Exercise 6: Thêm code hiển thị mode trên 7-segment
        // display_mode(current_mode);
    }
}

/* ============================================================================
 * HELPER FUNCTION: get_current_mode
 * ============================================================================
 * Trả về mode hiện tại
 * ============================================================================
 */
int get_current_mode(void) {
    return current_mode;
}

/* ============================================================================
 * HELPER FUNCTION: set_current_mode
 * ============================================================================
 * Set mode hiện tại (dùng khi button SET được nhấn)
 * ============================================================================
 */
void set_current_mode(int mode) {
    if(mode >= MODE_1_NORMAL && mode <= MODE_4_GREEN_MODIFY) {
        current_mode = mode;
    }
}

/* ============================================================================
 * VÍ DỤ SỬ DỤNG TRONG MAIN LOOP:
 * ============================================================================
 * 
 * while(1) {
 *     // Xử lý mode switching
 *     fsm_for_input_processing();
 *     
 *     // Xử lý tùy theo mode hiện tại
 *     switch(get_current_mode()) {
 *         case MODE_1_NORMAL:
 *             // Chạy traffic light bình thường
 *             fsm_traffic_light();
 *             break;
 *             
 *         case MODE_2_RED_MODIFY:
 *             // Nhấp nháy LED đỏ, cho phép chỉnh thời gian
 *             fsm_modify_red();
 *             break;
 *             
 *         case MODE_3_AMBER_MODIFY:
 *             // Nhấp nháy LED vàng
 *             fsm_modify_amber();
 *             break;
 *             
 *         case MODE_4_GREEN_MODIFY:
 *             // Nhấp nháy LED xanh
 *             fsm_modify_green();
 *             break;
 *     }
 * }
 * 
 * ============================================================================
 */
