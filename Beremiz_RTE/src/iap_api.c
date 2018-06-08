/**
 * @brief In application programming api
 * @author Yanikeev Vasily (yanvasilij@gmail.com)
 */
#include <DAVE3.h>
#include "iap_api.h"
#include "crc_calc.h"

#define SECTOR_SIZE 	0x10000000U
#define USER_INFO_SIZE 	10240U
#define USER_APP_INFO_ADDR	(FLASH002_SECTOR11_BASE+SECTOR_SIZE-USER_INFO_SIZE)

static bool is_user_programming_now_flag = false;
static User_app_info user_app_info;

/**
 * @brief Enable user app downloading
 */
void enable_user_app_programming (bool value)
{
	is_user_programming_now_flag = value;
}

/**
 * @brief Check if user application downloading 
 */
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

/**
 * @brief Set crc of user application
 */
void set_user_app_crc (uint32_t value)
{
	user_app_info.crc = value;
}

/**
 * @brief Set len of user application
 */
void set_user_app_len (uint32_t value)
{
	user_app_info.len = value;
}

/**
 * @brief Get crc of user application
 */
uint32_t get_user_app_crc (void)
{
	return user_app_info.crc;
}

/**
 * @brief Download current user_app_info to flash
 */
void program_user_app_info(void)
{
	Flash002_WritePage(USER_APP_INFO_ADDR, (uint32_t*)&user_app_info);
}

/**
 * @brief Upload user_app_info from flash
 */
void upload_user_app_info (void)
{
	void * p = (void*)USER_APP_INFO_ADDR;
	memcpy (&user_app_info, p, sizeof(User_app_info));
}

/**
 * @brief Calculate CRC of downloaded user application
 */
uint32_t calc_user_app_crc (void)
{
	uint8_t *app_p = (uint8_t*)FLASH002_SECTOR11_BASE;
	return calcCrc(app_p, user_app_info.len);
}

/**
 * @brief Check if downloaded user app correct
 */
bool is_user_app_correct (void)
{
	uint16_t user_app_crc;
	uint8_t *app_p = (uint8_t*)FLASH002_SECTOR11_BASE;
	user_app_crc = calcCrc(app_p, user_app_info.len);
	if (user_app_crc != user_app_info.crc)
		return false;
	else
		return true;
}

/*
 * eof
 */
