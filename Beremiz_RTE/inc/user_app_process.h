/**
 * @brief All about user application polling
 * @author Yanikeev Vasily (yanvasilij@gmail.ru)
 */

#ifndef USER_APP_PROCESS_H
#define USER_APP_PROCESS_H

#include "plc_abi.h"

extern void reset_user_app (void);
extern void poll_user_app (plc_variables_t * variables, plc_configuration_t * configuration);
extern bool stop_user_app;

#endif

/*
 * eof
 */
