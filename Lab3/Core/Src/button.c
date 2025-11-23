/*
 * button.c
 *
 *  Created on: Nov 22, 2025
 *      Author: TD
 */


#include "button.h"


int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;
int TimerForKeyPress = 200;

void subKeyProcess(){
	HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
}
 void getKeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1	= KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin);
	if((KeyReg0 == KeyReg1)  && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if (KeyReg2 == PRESSED_STATE){
				//TODO
				subKeyProcess();
				TimerForKeyPress = 200;
			}
		}else{
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				//TODO
				subKeyProcess();
				TimerForKeyPress = 200;
			}

		}
	}
}
