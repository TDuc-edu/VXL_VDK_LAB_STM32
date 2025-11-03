/*
 * timer.c
 *
 *  Created on: Nov 3, 2025
 *      Author: TD
 */
#include "main.h"
#include "input_reading.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if(htim->Instance == TIM2) {
        button_reading();
    }
}

