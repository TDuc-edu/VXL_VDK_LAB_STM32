/*
 * led_7seg.c
 *
 *  Created on: Oct 7, 2025
 *      Author: ASUS
 */

#include "main.h"
#include "led_7seg.h"

void display7SEG(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG4_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_SEG6_Pin, 0);
		break;
	default:
		HAL_GPIO_WritePin(GPIOB, LED7_SEG0_Pin | LED7_SEG1_Pin | LED7_SEG2_Pin | LED7_SEG3_Pin | LED7_SEG4_Pin | LED7_SEG5_Pin | LED7_SEG6_Pin, 1);
		break;
	}
}
