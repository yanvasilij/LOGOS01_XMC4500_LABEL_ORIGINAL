/**
 * @brief Command line interface
 * @author Yanikeev Vasily (yanvasilij@gmail.com)
 */
#include <DAVE3.h>
#include "cli_process.h"
#include "iap_api.h"
#include "stdio.h"
#include "crc_calc.h"
#include "user_app_process.h"

/******************************************************************************
 *	defs 
******************************************************************************/
#define  TRACE_LIST_LEN 1024
#define  TRACE_BUFER_SIZE 1024
/******************************************************************************
 *	prototypes 
******************************************************************************/

static void get_plc_status (char * cmd, char * response, uint32_t *response_len);
static void boot (char * cmd, char * response, uint32_t *response_len);
static void reset_download (char * cmd, char * response, uint32_t *response_len);
static void send_segment (char * cmd, char * response, uint32_t *response_len);
static void send_total_crc (char * cmd, char * response, uint32_t *response_len);
static void send_total_len (char * cmd, char * response, uint32_t *response_len);
static void run_user_app (char * cmd, char * response, uint32_t *response_len);
static void show_user_app_hex (char * cmd, char * response, uint32_t *response_len);
static void register_debug_var (char * cmd, char * response, uint32_t *response_len);
static void get_debug_data (char * cmd, char * response, uint32_t *response_len);

/******************************************************************************
 *	vars 
******************************************************************************/

static u8 segment_buffer[5000]; /**< @brief Buffer for reciving incomming */
static u8 download_in_progress = 0; /**< @brief Flag is download in progress */
static uint32_t total_len = 0; /**< @brief total len of download user app */
static uint32_t segment_count = 0; /**< @brief number of incomming segments with user application */

static Seial_queue rx_queue; /**< @brief serial input queue */

/**
 * @brief List of commands
 */
static Cli_command commands[NUMBER_OF_CLI_COMMANDS] = 
{
	{"GetPlcStatus", 		12, 	get_plc_status},
	{"Boot", 				4, 		boot},
	{"ResetDownload", 		13, 	reset_download},
	{"SendSegment", 		8, 		send_segment},
	{"SendTotalCRC", 		11, 	send_total_crc},
	{"SendTotalLen", 		12, 	send_total_len},
	{"RunUserApp", 			10, 	run_user_app},
	{"Hex", 				3, 		show_user_app_hex},
	{"RegDbgVar", 			9, 		register_debug_var},
	{"GetDbg", 				6, 		get_debug_data}
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
	rx_queue.count--;
	if (rx_queue.first >= SERIAL_INPUT_BUFFER)
		rx_queue.first = 0;
	return true;
}

/**
 * @brief get character from queue with timeout
 * @param ch pointer to place readed character
 * @param time to wait (timeout value)
 * @return true - succes, false - no elements in queue
 */
static bool get_ch_from_rx_queue_by_timeout (uint8_t * ch, uint32_t timeout)
{
	uint32_t start_time = SYSTM001_GetTime();
	while ( (get_ch_from_rx_queue(ch) != true) && 
			( (start_time+timeout) > SYSTM001_GetTime() ) );

	if ( (start_time+timeout) <= SYSTM001_GetTime() )
		return false;
	else
		return true;
}

/**
 * @brief inserts waitng in ms
 * @param value delay value in ms
 */
static void delay_ms (uint32_t value)
{
	uint32_t start_time = SYSTM001_GetTime();
	while ( ( (start_time+value) > SYSTM001_GetTime() ) );
}

/******************************************************************************
 *	comands callbacks 
******************************************************************************/

static void get_plc_status (char * cmd, char * response, uint32_t *response_len)
{
	*response_len = sprintf(response, "Running\r\n");
}

static void boot (char * cmd, char * response, uint32_t *response_len)
{
	enable_user_app_programming(true);
	clear_page_for_user_app();
	*response_len = sprintf(response, "Done\r\n");
}

static void reset_download (char * cmd, char * response, uint32_t *response_len)
{
	download_in_progress = 0;
	total_len = 0;
	segment_count = 0;
	*response_len = sprintf(response, "Done\r\n");
}

static void send_segment (char * cmd, char * response, uint32_t *response_len)
{
	uint32_t segment_len;

	if (sscanf(cmd, "SendSegment %u\r\n", &segment_len) != 1)
	{
		*response_len = sprintf(response, "Wrong format\r\n");
		return;
	}

	if (download_in_progress == 0)
	{
		download_in_progress = 1;
		segment_count = 0;
		enable_user_app_programming(true);
	}
	uint32_t input_count = 0;

	for (uint32_t i = 0; i < segment_len+2; i++) //2 bytes for CRC
	{
		if (get_ch_from_rx_queue_by_timeout(&segment_buffer[i], 2000) == false)
		{
			*response_len = sprintf(response, "Time out!\r\n");
			return;
		}
		input_count = i;
	}
	uint16_t crc_from_cli = *(uint16_t*)&segment_buffer[segment_len];
	uint16_t crc_calc = calcCrc(segment_buffer, segment_len);

	if (crc_from_cli == crc_calc)
	{
		total_len += segment_len;

		program_4096(segment_buffer, segment_count++);
		//*response_len = sprintf(response, "CRC correct %u\r\n", input_count);
		*response_len = sprintf(response, "CRC correct!\r\n");
	}
	else
	{
		*response_len = sprintf(response, "CRC incorrect!\r\n");
	}
}

static void send_total_crc (char * cmd, char * response, uint32_t *response_len)
{
	u32 crc;
	u32 user_app_crc;
	if (sscanf(cmd, "SendTotalCRC %u\r\n", &crc) != 1)
	{
		*response_len = sprintf(response, "Wrong format\r\n");
		return;
	}

	user_app_crc = calc_user_app_crc();

//	if ( user_app_crc != crc )
//	{
//		*response_len = sprintf(response, "Total crc incorrect: %d %d %d\r\n",
//				user_app_crc, crc, total_len);
//		return;
//	}

	set_user_app_crc(user_app_crc);
	program_user_app_info();

	reset_user_app();
	enable_user_app_programming(false);

	*response_len = sprintf(response, "Total CRC correct\r\n");
	serial_write(response, *response_len);
}

static void send_total_len (char * cmd, char * response, uint32_t *response_len)
{
	u32 len;
	if (sscanf(cmd, "SendTotalLen %u\r\n", &len) != 1)
	{
		*response_len = sprintf(response, "Wrong format\r\n");
		return;
	}

	set_user_app_len (len);

	*response_len = sprintf(response, "Done!\r\n");
}

static void run_user_app (char * cmd, char * response, uint32_t *response_len)
{
	stop_user_app = false;
	*response_len = sprintf(response, "Done\r\n");
}

/**
 * @brief Shows the first part of downloaded hex
 */
static void show_user_app_hex (char * cmd, char * response, uint32_t *response_len)
{
	uint8_t *app_p = (uint8_t*)FLASH002_SECTOR11_BASE;
	char hex[4] = {0,0,0,0};
	char ln = '\n';
	u32 shift;

	if (sscanf(cmd, "Hex %u\r\n", &shift) != 1)
	{
		*response_len = sprintf(response, "Wrong format\r\n");
		return;
	}

	for (uint32_t i = 0, k=0; i < 10; i++)
	{
		for (uint32_t j=0; j<16; j++, k++)
		{
			sprintf (hex, "%02X ", app_p[k+shift]);
			serial_write(hex, 3);
		}
		serial_write(&ln, 1);
	}
	*response_len = sprintf(response, "Done\r\n");
}

static void register_debug_var (char * cmd, char * response, uint32_t *response_len)
{
    plc_app_abi_t * user_app = USER_APP_POINTER;

    unsigned long size;

    char force_buffer[24] = "";
    int ch_count = 0;
    void *get_data_buf;
    int force_flag;
    char trace_list[TRACE_LIST_LEN] = "NONE";
    u32 idx;

	u32 inlen;
	if (sscanf(cmd, "RegDbgVar %u\r\n", &inlen) != 1)
	{
		*response_len = sprintf(response, "Wrong format\r\n");
		return;
	}

	for (uint32_t i=0; i<inlen; i++)
	{
		if (get_ch_from_rx_queue_by_timeout(&trace_list[i], 100) == false)
		{
			*response_len = sprintf(response, "Wrong format\r\n");
			return;
		}
	}

	if (inlen < 5)
	{
		*response_len = sprintf(response, "Wrong format\r\n");
		return;
	}
	user_app->dbg_suspend(0);
	if (1) 
	{
		user_app->dbg_vars_reset();

		ch_count = 0;
		while(ch_count <= inlen - 1)
		{
			memcpy(&idx, trace_list + ch_count, 4);
			/* обращаяюсь к той части сообщения, где лежит флаг с размером изменяемой перменной*/
			force_flag = (int)(*(trace_list + ch_count + 4));
			if (force_flag  != 0)
			{
				/* обращаяюсь к той части сообщения, где лежат данные с новыи значение для перемнной */
				memcpy(&force_buffer, trace_list + ch_count + 5, force_flag);
				user_app->dbg_var_register(idx, (void *)force_buffer);
				/* добаляю смещение исходя из того, сколько занимает измененное значения, помиомо основного смещения
				   +5 (см. коммент ниже) */
				ch_count = ch_count + force_flag;
			}
			else
				user_app->dbg_var_register(idx, (void *)force_buffer);
			/*  добавляю смещение для получения данных по следующей переменной, прибавление +5 идет потому что
			 * данные для регистрации лежат в формате 4 байта с номером и 1 байт с флагом */
			ch_count = ch_count + 5;
		}
		user_app->dbg_resume();

	}
	*response_len = sprintf(response, "Done\r\n");
}

static void get_debug_data (char * cmd, char * buffer, uint32_t *response_len)
{
    plc_app_abi_t * user_app = USER_APP_POINTER;
    unsigned long size;
    void *get_data_buf;

	user_app->dbg_resume();

	if (user_app->dbg_data_get((unsigned long *)(buffer), &size, &get_data_buf) == 0)
	{
		/* прибавляю + 4, т.к. в первые байты кладется значение unsigned long, длинна которого равна 4,
		 * это деляется исходя из Beremiz-ского правила формирования сообщения с дебажнами данными*/
		memcpy(buffer + 4, get_data_buf, size);

		*response_len = size + 4;

		user_app->dbg_data_free();
		user_app->dbg_suspend(0);

		return;
	}
	*response_len = 0;
	user_app->dbg_suspend(0);
	return;

}

/**
 * @brief Execute terminated command
 */
void exec_cmd (char *cmd, char *response, uint32_t *response_len)
{
	for	(uint32_t i=0; i<NUMBER_OF_CLI_COMMANDS; i++)
	{
		if (memcmp(cmd, commands[i].cmd, commands[i].cmd_len) == 0)
		{
			commands[i].callback(cmd, response, response_len);
			return;
		}
	}
	*response_len = sprintf(response, "Unknown cmd!\r\n");
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
	if (rx_queue.count>=SERIAL_INPUT_BUFFER)
		rx_queue.overflowed = true;
	else
		rx_queue.count++;
}

/**
 * @brief init command line interface
 */
void init_cli (void)
{
	reset_serial_rx_queue();
}

/**
 * @brief polling CLI interface
 */
void cli_poll (void)
{
	static char cmd[MAX_CLI_COMMAND_LEN];
	static uint32_t cmd_len=0;

	char response[MAX_CLI_COMMAND_LEN];
	uint32_t response_len;
	char ch;

//	if ( (rx_queue.overflowed) || (cmd_len >=MAX_CLI_COMMAND_LEN) )
//	{
//		response_len = sprintf(response, "Wrong cmd: input queue is overfloved\r\n");
//		serial_write(response, response_len);
//
//		//response_len = sprintf(response, "\t %s \r\n", cmd);
//		//serial_write(response, response_len);
//
//		//reset_serial_rx_queue();
//		cmd_len = 0;
//		memset(cmd, 0, MAX_CLI_COMMAND_LEN);
//	}
//	else
//	{
		if (get_ch_from_rx_queue(&ch))
		{
			//ECHO - send back all recived characters
			serial_write(&ch, 1);
			cmd[cmd_len++] = ch;
			if (ch == '\n')
			{
				exec_cmd(cmd, response, &response_len);
				serial_write(response, response_len);
				cmd_len = 0;
				memset(cmd, 0, MAX_CLI_COMMAND_LEN);
			}
		}
//	}
}

void serial_write (char *string, uint32_t len)
{
	for (uint32_t i = 0; i<len; i++)
		while(!UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&string[i], 1));
}

/*
 * eof
 */
