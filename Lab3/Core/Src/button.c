/*
 * button.c
 *
 *  Created on: Nov 10, 2025
 *      Author: ASUS
 */

#include "button.h"

int16_t pin_of_button[NO_BUTTON] = { BUTTON_0_Pin, BUTTON_1_Pin, BUTTON_2_Pin };

Key_Input button[NO_BUTTON];

int isButton_Pressed(int index) {
	if ((index > 2) && (index < 0)) {
		return -1;
	}
	if (button[index].flag == 1) {
		button[index].flag = 0;
		return 1;
	}
	return 0;
}
int is_MODE_Pressed() {
	return isButton_Pressed(MODE);
}
int is_TIME_Pressed() {
	return isButton_Pressed(TIME);
}
int is_SET_Pressed() {
	return isButton_Pressed(SET);
}
void getKeyInput() {
	for (int i = 0; i < NO_BUTTON; i++) {
		button[i].KeyReg2 = button[i].KeyReg1;
		button[i].KeyReg1 = button[i].KeyReg0;
		button[i].KeyReg0 = HAL_GPIO_ReadPin(GPIOB, pin_of_button[i]);

		if ((button[i].KeyReg0 == button[i].KeyReg1)
				&& (button[i].KeyReg1 == button[i].KeyReg2)) {
			if (button[i].KeyReg2 != button[i].KeyReg3) {
				button[i].KeyReg3 = button[i].KeyReg2;

				if (button[i].KeyReg3 == PRESSED_STATE) {
					button[i].timelongpress = TimeOutForKeyPress;
					button[i].flag = 1;
				}
			} else {
				button[i].timelongpress--;
				if (button[i].timelongpress <= 0) {
					button[i].timelongpress = TimeOutForKeyPress;
					if (button[i].KeyReg3 == PRESSED_STATE) {
						button[i].flag = 1;
					}
				}
			}
		}

	}
}
