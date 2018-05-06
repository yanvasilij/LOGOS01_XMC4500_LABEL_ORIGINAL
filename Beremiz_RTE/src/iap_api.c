/**
 * @brief In application programming api
 * @author Yanikeev Vasily (yanvasilij@gmail.com)
 */
#include <DAVE3.h>
#include "iap_api.h"

static bool is_user_programming_now_flag = false;

void enable_user_app_programming (bool value)
{
	is_user_programming_now_flag = value;
}

bool is_user_app_programming_now (void)
{
	return is_user_programming_now_flag;
}

void clear_page_for_user_app (void)
{
}

void program_4096 (uint8_t * data, uint32_t shift)
{
}

void set_user_app_crc (uint32_t value)
{
}

void set_user_app_len (uint32_t value)
{
}

uint32_t get_user_app_crc (void)
{
	return 0;
}

uint32_t calc_user_app_crc (void)
{
	return 0;
}

bool is_user_app_correct (void)
{
	return true;
}

/*
 * eof
 */
