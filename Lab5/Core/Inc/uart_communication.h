/*
 * uart_communication.h
 *
 *  Created on: Nov 30, 2025
 *      Author: TD
 *
 *
 *      Quản lý flow giao tiếp UART
 *      timeout 3s tự động resend
 *      đọc và gửi giá trị ADC
 *
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>

// Communication states
#define WAITING_RST    0
#define SEND_ADC       1
#define WAITING_OK     2

// Communication variables
extern int comm_state;
extern uint32_t ADC_value;
extern char uart_tx_buffer[30];

// Function prototypes
void comm_init(void);
void uart_communication_fsm(ADC_HandleTypeDef* hadc, UART_HandleTypeDef* huart);

#endif /* INC_UART_COMMUNICATION_H_ */
