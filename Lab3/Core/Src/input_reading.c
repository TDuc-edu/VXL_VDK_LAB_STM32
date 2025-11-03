/*
 * input_reading.c
 *
 *  Created on: Nov 3, 2025
 *      Author: TD
 */

#include "main.h"
// chúng ta muốn làm việc với nhiều hơn một nút
#define N0_OF_BUTTONS 1
// thời gian ngắt timer là 10ms, vì vậy để qua 1 giây,
// chúng ta cần nhảy vào thủ tục phục vụ ngắt 100 lần
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

// buffer lưu kết quả cuối cùng sau khi chống dội
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];

// chúng ta định nghĩa hai buffer cho việc chống dội
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

// chúng ta định nghĩa một cờ cho nút được nhấn hơn 1 giây
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];

// chúng ta định nghĩa bộ đếm để tự động tăng giá trị
// sau khi nút được nhấn hơn 1 giây
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

void button_reading(void) {
    for(char i = 0; i < N0_OF_BUTTONS; i++) {
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);

        if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
            buttonBuffer[i] = debounceButtonBuffer1[i];

        if(buttonBuffer[i] == BUTTON_IS_PRESSED) {
            // nếu nút được nhấn, chúng ta bắt đầu đếm
            if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
                counterForButtonPress1s[i]++;
            } else {
                // cờ được bật khi 1 giây đã trôi qua
                // kể từ khi nút được nhấn
                flagForButtonPress1s[i] = 1;
                // todo
            }
        } else {
            counterForButtonPress1s[i] = 0;
            flagForButtonPress1s[i] = 0;
        }
    }
}

unsigned char is_button_pressed(uint8_t index) {
    if(index >= N0_OF_BUTTONS) return 0;
    return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index) {
    if(index >= N0_OF_BUTTONS) return 0xff;
    return (flagForButtonPress1s[index] == 1);
}
