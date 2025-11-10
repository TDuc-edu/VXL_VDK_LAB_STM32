/*
 * led_display.c
 *
 *  Created on: Nov 3, 2025
 *      Author: ASUS
 */

#include<led.h>

int state_led = 0;

int16_t array_LED_pin[] = { RED_1_Pin, RED_2_Pin, GREEN_1_Pin, GREEN_2_Pin,
		YELLOW_1_Pin, YELLOW_2_Pin };
void turn_on_LED(int Pos) {
	HAL_GPIO_WritePin(GPIOB, array_LED_pin[Pos], SET);
}
void turn_off_LED(int Pos) {
	HAL_GPIO_WritePin(GPIOB, array_LED_pin[Pos], RESET);
}
void toogle_LED(int Pos) {
	HAL_GPIO_TogglePin(GPIOB, array_LED_pin[Pos]);
}

void init_Blink_led(int color_of_led) {
	switch (color_of_led) {
	case RED:
		/* code */
		turn_on_LED(RED_1);
		turn_on_LED(RED_2);

		turn_off_LED(GREEN_1);
		turn_off_LED(GREEN_2);
		turn_off_LED(YELLOW_1);
		turn_off_LED(YELLOW_2);
		break;
	case GREEN:
		/* code */
		turn_on_LED(GREEN_1);
		turn_on_LED(GREEN_2);
		turn_off_LED(RED_1);
		turn_off_LED(RED_2);
		turn_off_LED(YELLOW_1);
		turn_off_LED(YELLOW_2);
		break;
	case YELLOW:
		turn_on_LED(YELLOW_1);
		turn_on_LED(YELLOW_2);

		turn_off_LED(RED_1);
		turn_off_LED(RED_2);
		turn_off_LED(GREEN_1);
		turn_off_LED(GREEN_2);
		break;
	default:
		break;
	}
}
void Blink_led(int color_of_led) {
	switch (color_of_led) {
	case RED:
		toogle_LED(RED_1);
		toogle_LED(RED_2);
		/* code */
		break;
	case GREEN:
		toogle_LED(GREEN_1);
		toogle_LED(GREEN_2);
		break;
	case YELLOW:
		toogle_LED(YELLOW_1);
		toogle_LED(YELLOW_2);
		break;
	default:
		break;
	}
}
