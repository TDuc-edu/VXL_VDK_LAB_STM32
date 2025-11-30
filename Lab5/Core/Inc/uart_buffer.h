/*
 * uart_buffer.h
 *
 *  Created on: Nov 30, 2025
 *      Author: TD
 *
 *
 *   Nhận và lưu trữ dữ liệu UART
 *   cirular bufer chống tràn
 *   flag báo hiệu có dữ liệu mới
 */

#ifndef INC_UART_BUFFER_H_
#define INC_UART_BUFFER_H_

#include "stdint.h"

#define MAX_BUFFER_SIZE	30

//buffer variable
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

//function prototype
void uart_init_buffer(void);
void uart_receive_char(uint8_t ch);
uint8_t uart_get_flag(void);
void uart_clear_flag(void);
uint8_t* uart_get_buffer(void);
uint8_t uart_get_index(void);


#endif /* INC_UART_BUFFER_H_ */
