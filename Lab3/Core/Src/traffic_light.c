/*
 * traffic_light.c
 *
 *  Created on: Nov 24, 2025
 *      Author: TD
 */


#include "traffic_light.h"

void light_traffic_redX(void) {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
}

void light_traffic_yellowX(void) {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
}

void light_traffic_greenX(void) {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
}

void light_traffic_redY(void) {
    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}

void light_traffic_yellowY(void) {
    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}

void light_traffic_greenY(void) {
    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void toggle_all_red(void) {
    HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
    HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
}

void toggle_all_green(void) {
    HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
    HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
}

void toggle_all_yellow(void) {
    HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
    HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_1_Pin);
}

void clear_red_green_yellow(void) {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}
