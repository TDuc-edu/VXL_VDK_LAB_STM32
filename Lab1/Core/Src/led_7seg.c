/*
 * led_7sg.c
 *
 *  Created on: Oct 1, 2025
 *      Author: ASUS
 */


#include "led_7seg.h"
#include "main.h"

void display7SEG(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_b_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_c_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_d_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_e_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, SEG7_f_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG7_g_Pin, 0);
		break;
	default:
		HAL_GPIO_WritePin(GPIOB, SEG7_a_Pin | SEG7_b_Pin | SEG7_c_Pin | SEG7_d_Pin | SEG7_e_Pin | SEG7_f_Pin | SEG7_g_Pin, 1);
		break;
	}
}
