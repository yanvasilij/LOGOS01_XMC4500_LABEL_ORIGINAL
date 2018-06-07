/**
 * @brief In application programming api
 * @author Yanikeev Vasily (yanvasilij@gmail.com)
 */
#ifndef IAP_API_H_
#define IAP_API_H_

extern void enable_user_app_programming (bool value);
extern void clear_page_for_user_app (void);
extern void program_4096 (uint8_t * data, uint32_t shift);
extern void set_user_app_crc (uint32_t value);
extern void set_user_app_len (uint32_t value);
extern uint32_t get_user_app_crc (void);
extern uint32_t calc_user_app_crc (void);
extern bool is_user_app_correct (void);
extern bool is_user_app_programming_now (void);


typedef struct
{
	uint32_t len;
	uint32_t crc;
}User_app_info;

#endif

/*
 * eof
 */
