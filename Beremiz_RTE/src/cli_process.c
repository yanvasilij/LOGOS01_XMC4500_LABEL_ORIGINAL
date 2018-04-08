/**
 * @brief Command line interface
 * @author Yanikeev Vasily (yanvasilij@gmail.com)
 */
#include "cli_process.h"

/******************************************************************************
 *	prototypes 
******************************************************************************/

static void get_plc_status (char * cmd, char * response, uint32_t len);
static void boot (char * cmd, char * response, uint32_t len);
static void reset_download (char * cmd, char * response, uint32_t len);
static void download (char * cmd, char * response, uint32_t len);
static void send_total_crc (char * cmd, char * response, uint32_t len);
static void run_user_app (char * cmd, char * response, uint32_t len);

/******************************************************************************
 *	vars 
******************************************************************************/

static Seial_queue rx_queue; /**< @brief serial input queue */

/**
 * @brief List of commands
 */
static Cli_command commands[NUMBER_OF_CLI_COMMANDS] = 
{
	{"GetPlcStatus", 		12, 	get_plc_status},
	{"Boot", 				4, 		boot},
	{"ResetDownload", 		13, 	reset_download},
	{"Download", 			8, 		download},
	{"SendTotalCRC", 		12, 	send_total_crc},
	{"RunUserApp", 			10, 	run_user_app}
};

/******************************************************************************
 *	static 
******************************************************************************/

/**
 * @brief reset serial input queue
 */
static void reset_serial_rx_queue (void)
{
	rx_queue.count = 0;
	rx_queue.overflowed = false;
	rx_queue.last=0;
	rx_queue.first=0;
	memset(rx_queue.buf, 0, SERIAL_INPUT_BUFFER);
}

/**
 * @brief send character to cli
 * @param ch pointer to place readed character
 * @return true - succes, false - no elements in queue
 */
static bool get_ch_from_rx_queue (uint8_t * ch)
{
	if (rx_queue.last == rx_queue.first)
		return false;
	*ch = rx_queue.buf[rx_queue.first++];
	if (rx_queue.first >= SERIAL_INPUT_BUFFER)
		rx_queue.first = 0;
	return true;
}


/******************************************************************************
 *	comands callbacks 
******************************************************************************/

static void get_plc_status (char * cmd, char * response, uint32_t len)
{
}

static void boot (char * cmd, char * response, uint32_t len)
{
}

static void reset_download (char * cmd, char * response, uint32_t len)
{
}

static void download (char * cmd, char * response, uint32_t len)
{
}

static void send_total_crc (char * cmd, char * response, uint32_t len)
{
}

static void run_user_app (char * cmd, char * response, uint32_t len)
{
}

/******************************************************************************
 *	global
******************************************************************************/

/**
 * @brief send character to cli
 * @param ch incommint character
 */
void cli_serial_input (uint8_t ch)
{
	rx_queue.buf[rx_queue.last++] = ch;
	if (rx_queue.last >= SERIAL_INPUT_BUFFER)
		rx_queue.last = 0;
	rx_queue.count++;
	if (rx_queue.count>=SERIAL_INPUT_BUFFER)
	{
		rx_queue.overflowed = true;
	}
}

/**
 * @brief init command line interface
 */
void init_cli (void)
{
	reset_serial_rx_queue();
}

void cli_poll (void)
{
}

/*
 * eof
 */
