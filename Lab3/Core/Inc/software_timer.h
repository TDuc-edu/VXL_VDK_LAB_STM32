/*
 * software_timer.h
 *
 *  Created on: Oct 15, 2025
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

/* ============================================================================
 * EXERCISE 4: SCALABLE SOFTWARE TIMER SYSTEM
 * ============================================================================
 * Mục tiêu:
 * - Tạo hệ thống timer có thể mở rộng dễ dàng
 * - Không phụ thuộc vào TIMER_CYCLE cụ thể
 * - Dễ dàng thêm/xóa timer mới
 * ============================================================================
 */

// ==================== CẤU HÌNH TIMER ====================
#define TIMER_CYCLE_MS      10      // Chu kỳ ngắt timer hardware (ms)
#define MAX_TIMERS          10      // Số lượng timer tối đa

// ==================== CHỈ SỐ TIMER (TIMER INDEX) ====================
// Định nghĩa tên timer để code dễ đọc
typedef enum {
    TIMER_TRAFFIC_LIGHT = 0,    // Timer cho đèn giao thông
    TIMER_LED_BLINK     = 1,    // Timer cho LED nhấp nháy 2Hz
    TIMER_BUTTON_SCAN   = 2,    // Timer cho quét button
    TIMER_7SEG_SCAN     = 3,    // Timer cho quét 7-segment
    TIMER_AUTO_INC      = 4,    // Timer cho tự động tăng giá trị
    TIMER_MODE_DISPLAY  = 5,    // Timer cho hiển thị mode
    TIMER_RESERVED_6    = 6,    // Dự phòng
    TIMER_RESERVED_7    = 7,    // Dự phòng
    TIMER_RESERVED_8    = 8,    // Dự phòng
    TIMER_RESERVED_9    = 9     // Dự phòng
} TimerIndex;

// ==================== KHAI BÁO HÀM CÔNG KHAI ====================

/**
 * @brief  Khởi tạo hệ thống timer (gọi 1 lần khi khởi động)
 * @param  None
 * @retval None
 */
void timer_init(void);

/**
 * @brief  Thiết lập thời gian cho timer
 * @param  index: Chỉ số timer (0-9)
 * @param  duration: Thời gian đếm (milliseconds)
 * @retval None
 * @usage  setTimer(TIMER_TRAFFIC_LIGHT, 5000); // 5 giây
 */
void setTimer(int index, int duration);

/**
 * @brief  Kiểm tra timer đã hết thời gian chưa
 * @param  index: Chỉ số timer (0-9)
 * @retval 1 nếu timer hết thời gian, 0 nếu chưa
 * @usage  if(isTimerExpired(TIMER_LED_BLINK)) { ... }
 */
int isTimerExpired(int index);

/**
 * @brief  Xóa cờ timer (sau khi xử lý xong)
 * @param  index: Chỉ số timer (0-9)
 * @retval None
 * @usage  clearTimer(TIMER_LED_BLINK);
 */
void clearTimer(int index);

/**
 * @brief  Chạy tất cả timer (GỌI TRONG NGẮT TIMER)
 * @param  None
 * @retval None
 * @note   Hàm này phải được gọi trong HAL_TIM_PeriodElapsedCallback()
 */
void timer_run(void);

// ==================== COMPATIBILITY LAYER (TÙY CHỌN) ====================
// Giữ lại các hàm cũ để tương thích với code hiện tại
// Có thể xóa phần này sau khi refactor toàn bộ code

#define setTimer0(duration)         setTimer(0, duration)
#define setTimer1(duration)         setTimer(1, duration)
#define setTimer2_LED(duration)     setTimer(2, duration)
#define setTimer3(duration)         setTimer(3, duration)
#define setTimer4(duration)         setTimer(4, duration)

#define timer0_flag                 isTimerExpired(0)
#define timer1_flag                 isTimerExpired(1)
#define timer2_flag_LED             isTimerExpired(2)
#define timer3_flag_LedMatrix       isTimerExpired(3)
#define timer4_flag                 isTimerExpired(4)

#endif /* INC_SOFTWARE_TIMER_H_ */
