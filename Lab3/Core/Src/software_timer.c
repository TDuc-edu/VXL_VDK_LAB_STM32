/*
 * software_timer.c
 *
 *  Created on: Oct 15, 2025
 *      Author: ASUS
 */

#include "software_timer.h"

/* ============================================================================
 * EXERCISE 4: IMPLEMENTATION - SCALABLE TIMER SYSTEM
 * ============================================================================
 * Giải thích cách hoạt động:
 * 
 * 1. Sử dụng ARRAY thay vì nhiều biến riêng lẻ
 *    - Dễ mở rộng: thêm timer = tăng MAX_TIMERS
 *    - Giảm code lặp lại
 * 
 * 2. Tự động tính toán dựa trên TIMER_CYCLE_MS
 *    - Đổi TIMER_CYCLE_MS từ 10ms → 1ms: code logic KHÔNG ĐỔI
 *    - duration (ms) / TIMER_CYCLE_MS = số lần ngắt cần đếm
 * 
 * 3. Flag tự động set khi counter = 0
 *    - User chỉ cần check isTimerExpired()
 * ============================================================================
 */

// ==================== BIẾN TOÀN CỤC NỘI BỘ ====================
static int timer_counter[MAX_TIMERS];  // Mảng counter cho mỗi timer
static int timer_flag[MAX_TIMERS];     // Mảng flag cho mỗi timer

// ==================== TRIỂN KHAI CÁC HÀM ====================

/**
 * @brief  Khởi tạo tất cả timer về 0
 */
void timer_init(void) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        timer_counter[i] = 0;
        timer_flag[i] = 0;
    }
}

/**
 * @brief  Thiết lập timer với thời gian duration (ms)
 * @note   Tự động chuyển đổi ms → số lần ngắt cần đếm
 */
void setTimer(int index, int duration) {
    // Kiểm tra index hợp lệ
    if (index < 0 || index >= MAX_TIMERS) return;
    
    // Chuyển đổi thời gian (ms) thành số lần ngắt
    // VD: duration = 1000ms, TIMER_CYCLE = 10ms → counter = 100 lần
    timer_counter[index] = duration / TIMER_CYCLE_MS;
    
    // Reset flag
    timer_flag[index] = 0;
}

/**
 * @brief  Kiểm tra timer đã hết thời gian chưa
 * @retval 1 = đã hết, 0 = chưa hết
 */
int isTimerExpired(int index) {
    // Kiểm tra index hợp lệ
    if (index < 0 || index >= MAX_TIMERS) return 0;
    
    // Trả về trạng thái flag
    return timer_flag[index];
}

/**
 * @brief  Xóa flag của timer (sau khi đã xử lý)
 */
void clearTimer(int index) {
    // Kiểm tra index hợp lệ
    if (index < 0 || index >= MAX_TIMERS) return;
    
    // Reset flag
    timer_flag[index] = 0;
}

/**
 * @brief  Hàm chạy timer - GỌI TRONG TIMER INTERRUPT
 * @note   Phải được gọi mỗi TIMER_CYCLE_MS (10ms)
 */
void timer_run(void) {
    // Duyệt qua tất cả timer
    for (int i = 0; i < MAX_TIMERS; i++) {
        // Nếu counter > 0, giảm dần
        if (timer_counter[i] > 0) {
            timer_counter[i]--;
            
            // Khi counter = 0, set flag
            if (timer_counter[i] == 0) {
                timer_flag[i] = 1;
            }
        }
    }
}

/* ============================================================================
 * VÍ DỤ SỬ DỤNG:
 * ============================================================================
 * 
 * // 1. Khởi tạo (trong main, trước khi vào while loop)
 * timer_init();
 * 
 * // 2. Thiết lập timer (bất cứ đâu trong code)
 * setTimer(TIMER_LED_BLINK, 250);      // 250ms
 * setTimer(TIMER_TRAFFIC_LIGHT, 5000); // 5 giây
 * 
 * // 3. Kiểm tra trong main loop
 * if (isTimerExpired(TIMER_LED_BLINK)) {
 *     clearTimer(TIMER_LED_BLINK);     // Xóa flag
 *     toggle_led();                     // Thực hiện hành động
 *     setTimer(TIMER_LED_BLINK, 250);  // Set lại timer
 * }
 * 
 * // 4. Trong timer interrupt callback
 * void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
 *     if (htim->Instance == TIM2) {
 *         timer_run();  // Chỉ cần gọi 1 dòng này!
 *     }
 * }
 * ============================================================================
 */
