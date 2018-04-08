/**
 * @brief Command line interface
 * @author Yanikeev Vasily (yanvasilij@gmail.com)
 */
#ifndef CLI_PROCESS_H_
#define CLI_PROCESS_H_

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define SERIAL_INPUT_BUFFER 100

typedef struct
{
	uint8_t buf[SERIAL_INPUT_BUFFER];
	uint8_t count;
	uint8_t last;
	uint8_t first;
	bool overflowed;
}Seial_queue;

extern void serial_write (uint8_t *string, uint32_t len);

#endif

/*
 * eof
 */
