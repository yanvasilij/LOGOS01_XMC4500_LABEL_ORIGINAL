/**
 * @brief All about user application polling
 * @author Yanikeev Vasily (yanvasilij@gmail.ru)
 */

#ifndef USER_APP_PROCESS_H
#define USER_APP_PROCESS_H

#include "plc_abi.h"

#define USER_APP_POINTER (plc_app_abi_t*)(0x80C0000) /**< brief pointer to user application */

extern void reset_user_app (void);
extern void poll_user_app (plc_variables_t * variables, plc_configuration_t * configuration);
extern bool stop_user_app;

//#define USE_USER_APP_CAP 1

#endif

/*
 * eof
 */
