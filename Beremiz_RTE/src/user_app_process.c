/**
 * @brief All about user application polling
 * @author Yanikeev Vasily (yanvasilij@gmail.ru)
 */
#include "user_app_process.h"
#include "plc_abi.h"

#define USER_APP_POINTER (plc_app_abi_t*)(0x8050000) /**< brief pointer to user application */

/**
 * @brief Checks if downloaded user application is correct
 */
static bool is_user_app_correct (void)
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
		/* FIXME: user application polls as faster as possible. It is neccesary to poll it using timer */
		user_app->set_ai_value(ai);
		user_app->run();
		user_app->get_ao_value(ao);
	}
}

/*
 * eof
 */
