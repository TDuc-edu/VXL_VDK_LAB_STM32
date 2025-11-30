/*
 * uart_communication.c
 *
 *  Created on: Nov 30, 2025
 *      Author: TD
 */


#include "uart_communication.h"
#include "command_parser.h"
#include "software_timer.h"
#include <stdio.h>

int comm_state = WAITING_RST;
uint32_t ADC_value = 0;
char uart_tx_buffer[30];

void comm_init(void) {
    comm_state = WAITING_RST;
    ADC_value = 0;
}

void uart_communication_fsm(ADC_HandleTypeDef* hadc, UART_HandleTypeDef* huart) {
    switch (comm_state) {
        case WAITING_RST:
            if (get_cmd_flag() == CMD_RST) {
                clear_cmd_flag();
                comm_state = SEND_ADC;
            }
            break;

        case SEND_ADC:
            // Read ADC
            HAL_ADC_Start(hadc);
            if (HAL_ADC_PollForConversion(hadc, 100) == HAL_OK) {
                ADC_value = HAL_ADC_GetValue(hadc);
            }
            HAL_ADC_Stop(hadc);

            // Format and send
            int len = sprintf(uart_tx_buffer, "!ADC=%lu#\r\n", ADC_value);
            HAL_UART_Transmit(huart, (uint8_t*)uart_tx_buffer, len, 1000);

            // Start 3s timeout
            setTimer1(3000);

            comm_state = WAITING_OK;
            break;

        case WAITING_OK:
            // Check timeout
            if (isTimer1Expired()) {
                // Timeout! Resend
                int len = sprintf(uart_tx_buffer, "!ADC=%lu#\r\n", ADC_value);
                HAL_UART_Transmit(huart, (uint8_t*)uart_tx_buffer, len, 1000);
                setTimer1(3000);
            }

            // Check OK command
            if (get_cmd_flag() == CMD_OK) {
                clear_cmd_flag();
                comm_state = WAITING_RST;
            }
            break;
    }
}
