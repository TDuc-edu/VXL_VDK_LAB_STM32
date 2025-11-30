/*
 * command_parser.h
 *
 *  Created on: Nov 30, 2025
 *      Author: TD
 *
 *      phân tích cú pháp lệnh !RST# và !OK#
 *      state machine 3 có trạng thái
 *      validate format lệnh
 */

#ifndef SRC_COMMAND_PARSER_H_
#define SRC_COMMAND_PARSER_H_

#include <stdint.h>

// Parser state
#define CMD_INIT	0
#define	CMD_WAITING	1
#define	CMD_CHECK	2

//command flags
#define CMD_NONE	0
#define	CMD_RST		1
#define	CMD_OK		2

// Parser Variable
extern int parser_state;
extern uint8_t cmd_data[10];
extern uint8_t cmd_index;
extern uint8_t cmd_flag;

// Function prototypes
void parser_init(void);
void command_parser_fsm(void);
uint8_t get_cmd_flag(void);
void clear_cmd_flag(void);

#endif /* SRC_COMMAND_PARSER_H_ */
