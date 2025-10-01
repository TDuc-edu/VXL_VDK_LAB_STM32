/*
 * auto_led.c
 *
 *  Created on: Oct 1, 2025
 *      Author: ASUS
 */


#include "auto_led.h"
#include "main.h"


void display_led(int num){
	switch (num){
	case 1:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;

	case 4:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;

	case 6:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;

	case 7:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;

	case 9:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;

	case 10:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;

	case 11:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 1);
		break;

	case 12:
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED6_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED7_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED8_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED9_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED10_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED11_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED12_Pin, 0);
		break;
	default: HAL_GPIO_WritePin(GPIOA, LED1_Pin | LED2_Pin | LED3_Pin | LED4_Pin |
			LED5_Pin | LED6_Pin | LED7_Pin | LED8_Pin | LED9_Pin | LED10_Pin | LED11_Pin | LED12_Pin, 0);
	break;

	}
}
