/*
 * button.h
 *
 *  Created on: Nov 22, 2025
 *      Author: TD
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET		// nút không nhấn = HIGH (pull-up)
#define	PRESSED_STATE RESET		// nút nhấn = LOW

int isButtonPress(int index);
void getKeyInput(int index);			// đọc và xử lý trạng thái nút (gọi từ interrupt)

#endif /* INC_BUTTON_H_ */
