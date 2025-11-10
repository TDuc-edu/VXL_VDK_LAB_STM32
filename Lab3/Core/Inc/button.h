/*
 * button.h
 *
 *  Created on: Nov 10, 2025
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define NO_BUTTON 3
#define TimeOutForKeyPress 50
#define MODE 0
#define TIME 1
#define SET 2

typedef struct {
	int KeyReg0;
	int KeyReg1;
	int KeyReg2;
	int KeyReg3;
	int timelongpress;
	int flag;
} Key_Input;
int isButton_Pressed(int index);
int is_MODE_Pressed();
int is_TIME_Pressed();
int is_SET_Pressed();
void getKeyInput();

#endif /* INC_BUTTON_H_ */
