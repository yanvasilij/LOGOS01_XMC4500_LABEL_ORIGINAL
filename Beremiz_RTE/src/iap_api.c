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

/**
 * @brief Clear page with user application 
 */
void clear_page_for_user_app (void)
{
	FLASH002_Init();
	FLASH002_ClearStatus();
	Flash002_EraseSector(FLASH002_SECTOR11_BASE);
}

/**
 * @brief Program 4096 bytes to page for user application
 * @param data Pointer to buffer with data for programming
 * @param shift Programming shift*4096 from base address
 */
void program_4096 (uint8_t * data, uint32_t shift)
{
	uint32_t adr = FLASH002_SECTOR11_BASE + 4096*shift;
	// 4096/256=16 (page size = 256)
	for (uint32_t i = 0; i < 16; i++)
	{
		Flash002_WritePage(adr, (uint32_t*)data);
		adr += 256;
	}
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
