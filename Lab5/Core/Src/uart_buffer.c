/*
 * uart_buffer.c
 *
 *  Created on: Nov 30, 2025
 *      Author: TD
 */

#include "uart_buffer.h"

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

void uart_init_buffer(void) {
	index_buffer = 0;
	buffer_flag = 0;
	for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
		buffer[i] = 0;
	}
}

void uart_receive_char(uint8_t ch) {
	buffer[index_buffer++] = ch;
	if (index_buffer >= MAX_BUFFER_SIZE) {
		index_buffer = 0;
	}
	buffer_flag = 1;
}

uint8_t uart_get_flag(void) {
	return buffer_flag;
}

void uart_clear_flag(void) {
	buffer_flag = 0;
}

uint8_t* uart_get_buffer(void){
	return buffer;
}

uint8_t uart_get_index(void){
	return index_buffer;
}

