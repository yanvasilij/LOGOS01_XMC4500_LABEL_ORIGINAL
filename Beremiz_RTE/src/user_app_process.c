/**
 * @brief All about user application polling
 * @author Yanikeev Vasily (yanvasilij@gmail.ru)
 */
#include "plc_abi.h"

#define USER_APP_POINTER (plc_app_abi_t*)(0x8050000) /**< brief pointer to user application */

/**
 * @brief Checks if downloaded user application is correct
 */
bool is_user_app_correct (void)
{
	/* FIXME: Missing user application CRC check! */
	return true;
}

/**
 * @brief User application polling
 */
void poll_user_app (float *ai, float *ao)
{
    plc_app_abi_t * user_app = USER_APP_POINTER;
	if (is_user_app_correct())
	{
		user_app->set_ai_value(ai);
		user_app->run();
		user_app->get_ao_value(ao);
	}
}

/*
 * eof
 */
