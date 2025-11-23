/*
 * button.c
 *
 *  Created on: Nov 22, 2025
 *      Author: TD
 */

#include "button.h"
#define BTN_COUNT 3

int button_flag[BTN_COUNT] = { 0, 0, 0 };
int TimeOutForKeyPress = 500;
int KeyReg0[BTN_COUNT] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg1[BTN_COUNT] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg2[BTN_COUNT] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg3[BTN_COUNT] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };

int isButtonPress(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;

}

void getKeyInput(int index) {
	KeyReg2[index] = KeyReg1[index];
	KeyReg1[index] = KeyReg0[index];

	if (index == 0)
		KeyReg0[index] = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin);
	else if (index == 1)
		KeyReg0[index] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	else if (index == 2)
		KeyReg0[index] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
	else {
		// nothing
	}

	if ((KeyReg0[index] == KeyReg1[index])
			&& (KeyReg1[index] == KeyReg2[index])) {
		if (KeyReg0[index] != KeyReg1[index]) {
			KeyReg3[index] = KeyReg0[index];
			if (KeyReg0[index] == PRESSED_STATE) {
				TimeOutForKeyPress = 500;
				// TODO
				button_flag[index] = 1;
			}
		} else {
			TimeOutForKeyPress--;
			if (TimeOutForKeyPress == 0) {
				TimeOutForKeyPress = 500;
				if (KeyReg0[index] == PRESSED_STATE) {
					// TODO
					button_flag[index] = 1;
				}
			}
		}
	}

}
