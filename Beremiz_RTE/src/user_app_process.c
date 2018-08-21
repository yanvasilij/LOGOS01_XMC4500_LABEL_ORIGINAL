/**
 * @brief All about user application polling
 * @author Yanikeev Vasily (yanvasilij@gmail.ru)
 */
#include "user_app_process.h"
#include "plc_abi.h"
#include "iap_api.h"

#define USER_APP_POINTER (plc_app_abi_t*)(0x80C0000) /**< brief pointer to user application */

static bool first_call = true;
bool stop_user_app = true;

/**
 * @brief Restart user application
 */
void reset_user_app (void)
{
	 first_call = true;
}

/**
 * @brief User application polling
 */
void poll_user_app (float *ai, float *ao)
{
	static bool user_app_is_downloaded = false;
    plc_app_abi_t * user_app = USER_APP_POINTER;

	if (stop_user_app)
		return;

	if (first_call)
	{
		upload_user_app_info();
		user_app_is_downloaded = is_user_app_correct();
		if (user_app_is_downloaded)
			user_app->start(0,0);
		first_call = false;
	}

	if ( user_app_is_downloaded && (is_user_app_programming_now() == false) )
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
