/**
 * @brief Command line interface
 * @author Yanikeev Vasily (yanvasilij@gmail.com)
 */
#ifndef CLI_PROCESS_H_
#define CLI_PROCESS_H_

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define SERIAL_INPUT_BUFFER 	100
#define MAX_CLI_COMMAND_LEN 	20
#define NUMBER_OF_CLI_COMMANDS 	6

typedef struct
{
	uint8_t buf[SERIAL_INPUT_BUFFER];
	uint8_t count;
	uint8_t last;
	uint8_t first;
	bool overflowed;
}Seial_queue;

typedef void (*Cli_cmd_callback) (char *cmd, char * response, uint32_t *response_len);

typedef struct
{
	char cmd[MAX_CLI_COMMAND_LEN];
	uint32_t cmd_len;
	Cli_cmd_callback callback;
}Cli_command;

extern void serial_write (char *string, uint32_t len);
extern void cli_serial_input (uint8_t ch);


#endif

/*
 * eof
 */
