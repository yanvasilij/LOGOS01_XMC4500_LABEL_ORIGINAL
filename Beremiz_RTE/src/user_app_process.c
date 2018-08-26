/**
 * @brief All about user application polling
 * @author Yanikeev Vasily (yanvasilij@gmail.ru)
 */
#include "plc_abi.h"
#include "iap_api.h"
#include "user_app_process.h"

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

void plc_app_cstratup(void)
{
    volatile uint32_t *src, *dst, *end;
    app_fp_t *func, *func_end;
    plc_app_abi_t * PLC_APP = USER_APP_POINTER;
    //Init .data
    dst = PLC_APP->data_start;
    end = PLC_APP->data_end;
    src = PLC_APP->data_loadaddr;
    while (dst < end)
    {
        *dst++ = *src++;
    }
    //Init .bss
    end = PLC_APP->bss_end;
    while (dst < end)
    {
        *dst++ = 0;
    }
    // Constructors
    // .preinit_array
    func = PLC_APP->pa_start;
    func_end = PLC_APP->pa_end;
    while (func < func_end)
    {
        (*func)();
        func++;
    }
    // .init_array
    func = PLC_APP->ia_start;
    func_end = PLC_APP->ia_end;
    while (func < func_end)
    {
        (*func)();
        func++;
    }
}

/**
 * @brief User application polling
 */
void poll_user_app (plc_variables_t * variables, plc_configuration_t * configuration)
{
	static bool user_app_is_downloaded = false;
    plc_app_abi_t * user_app = USER_APP_POINTER;

	if (first_call)
	{
		upload_user_app_info();
		user_app_is_downloaded = is_user_app_correct();
		if (user_app_is_downloaded)
		{
			plc_app_cstratup();
			user_app->start(variables,configuration);
		}
		first_call = false;
	}

	if ( user_app_is_downloaded && (is_user_app_programming_now() == false) )
	{
		/* FIXME: user application polls as faster as possible. It is neccesary to poll it using timer */
		user_app->run();
	}
}

/*
 * eof
 */
