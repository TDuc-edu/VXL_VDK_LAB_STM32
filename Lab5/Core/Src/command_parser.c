/*
 * command_parser.c
 *
 *  Created on: Nov 30, 2025
 *      Author: TD
 */

#include "command_parser.h"
#include "uart_buffer.h"
#include <string.h>

int parser_state = CMD_INIT;
uint8_t cmd_data[10];
uint8_t cmd_index = 0;
uint8_t cmd_flag = CMD_NONE;

void parser_init(void) {
    parser_state = CMD_INIT;
    cmd_index = 0;
    cmd_flag = CMD_NONE;
}

void command_parser_fsm(void) {
    uint8_t* buffer = uart_get_buffer();
    uint8_t index = uart_get_index();
    uint8_t current_char = buffer[(index == 0) ? (MAX_BUFFER_SIZE - 1) : (index - 1)];

    switch (parser_state) {
        case CMD_INIT:
            if (current_char == '!') {
                parser_state = CMD_WAITING;
                cmd_index = 0;
            }
            break;

        case CMD_WAITING:
            if (current_char == '#') {
                cmd_data[cmd_index] = '\0';
                parser_state = CMD_CHECK;
            } else if (current_char != '!') {
                if (cmd_index < 9) {
                    cmd_data[cmd_index++] = current_char;
                } else {
                    parser_state = CMD_INIT;
                }
            }
            break;

        case CMD_CHECK:
            if (strcmp((char*)cmd_data, "RST") == 0) {
                cmd_flag = CMD_RST;
            } else if (strcmp((char*)cmd_data, "OK") == 0) {
                cmd_flag = CMD_OK;
            }
            parser_state = CMD_INIT;
            break;
    }
}

uint8_t get_cmd_flag(void) {
    return cmd_flag;
}

void clear_cmd_flag(void) {
    cmd_flag = CMD_NONE;
}
