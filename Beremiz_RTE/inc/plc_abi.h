/*
 * Copyright Nucleron R&D LLC 2016
 *
 * This file is licensed under the terms of YAPL,
 * see License.txt for details.
 */

#ifndef _PLC_ABI_H_
#define _PLC_ABI_H_

#include <stdbool.h>
#include <iec_types_all.h>

#define PLC_LOC_CONCAT(a, b) a##b

#define PLC_LT_I 0
#define PLC_LT_M 1
#define PLC_LT_Q 2

#define PLC_LOC_TYPE(a) PLC_LOC_CONCAT(PLC_LT_, a)

#define PLC_LSZ_X 0
#define PLC_LSZ_B 1
#define PLC_LSZ_W 2
#define PLC_LSZ_D 3
#define PLC_LSZ_L 4

#define PLC_LOC_SIZE(a) PLC_LOC_CONCAT(PLC_LSZ_, a)

typedef struct _plc_loc_dsc_t plc_loc_dsc_t;

struct _plc_loc_dsc_t
{
    void           *v_buf;
    uint8_t         v_type;
    uint8_t         v_size;
    uint16_t        a_size;
    const uint32_t *a_data;
    uint16_t        proto;
};

typedef const plc_loc_dsc_t * plc_loc_tbl_t;

typedef void (*app_fp_t) (void);

typedef struct
{
    float * X_Pos;
    float * Y_Pos;
    float * Z_Pos;
    float * W_Pos;
    float * V_Pos;

    uint8_t pb1;
    uint8_t pb2;
    uint8_t pb3;
    uint8_t pb4;
    uint8_t pb5;
    uint8_t pb6;
    uint8_t pb7;
    uint8_t pb8;
    uint8_t pb9;
    uint8_t pb10;
}can_joystick_t;

typedef struct
{
    float * inputlevel; //If Analog port is configured as analog input (either as 4-20mA or 0-5V or 0-10V or ratiometric)
    can_joystick_t can1;
    can_joystick_t can2;
    float * targcurr;
}plc_variables_t;

typedef struct
{
    uint8_t * sectionconf; //Section Configuration
    uint8_t * analoginmode; //Analog Input Mode
    uint8_t * loopfreq; //Dithering Frequency
    uint8_t * ditherampl; //Dithering
    uint8_t * auxvolt; //Auxiliary Voltage Output
    uint8_t * can1DMenable; //Can1 Port Enable
    uint8_t * can2DMenable; //Can2 Port Enable
}plc_configuration_t;

typedef struct
{
    uint32_t * sstart;
    app_fp_t entry;
    //App startup interface
    uint32_t * data_loadaddr;
    uint32_t * data_start;
    uint32_t * data_end;
    uint32_t * bss_end;
    app_fp_t * pa_start;
    app_fp_t * pa_end;
    app_fp_t * ia_start;
    app_fp_t * ia_end;
    app_fp_t * fia_start;
    app_fp_t * fia_end;
    //RTE Version control
    //Semantic versioning is used
    uint32_t rte_ver_major;
    uint32_t rte_ver_minor;
    uint32_t rte_ver_patch;
    //Hardware ID
    uint32_t hw_id;
    //IO manager data
    plc_loc_tbl_t * l_tab; //Location table
    uint32_t      * w_tab; //Weigth table
    uint16_t        l_sz;  //Location table size
    //Control instance of PLC_ID
    const char    * check_id; //Must be placed to the end of .text
    //App interface
    const char    * id;       //Must be placed near the start of .text

	void (*set_ai_value)(float*); //pass current value of AI to user application
	void (*get_ao_value)(float*); // get AO value calculated by user application
	
    int (*start)(plc_variables_t * variables, plc_configuration_t * configuration);
    int (*stop)(void);
    void (*run)(void);

    void (*dbg_resume)(void);
    void (*dbg_suspend)(int);

    int  (*dbg_data_get)(unsigned long *, unsigned long *, void **);
    void (*dbg_data_free)(void);

    void (*dbg_vars_reset)(void);
    void (*dbg_var_register)(int, void *);

    uint32_t (*log_cnt_get)(uint8_t);
    uint32_t (*log_msg_get)(uint8_t, uint32_t, char*, uint32_t, uint32_t*, uint32_t*, uint32_t*);
    void     (*log_cnt_reset)(void);
    int (*log_msg_post)(uint8_t, char*, uint32_t);
}
plc_app_abi_t;

typedef struct
{
    void (*get_time)(IEC_TIME *);
    void (*set_timer)(unsigned long long, unsigned long long);

    int  (*check_retain_buf)(void);
    void (*invalidate_retain_buf)(void); //Вызывается перед сохранением
    void (*validate_retain_buf)(void);   //Вызывается после сохранения

    void (*retain)(unsigned int, unsigned int, void *);
    void (*remind)(unsigned int, unsigned int, void *);

    void (*set_dout)(uint32_t, bool);
    void (*set_aout)(uint32_t, uint32_t);
    bool     (*get_din)(uint32_t);
    uint32_t (*get_ain)(uint32_t);

    void (*set_mem)(uint32_t, uint32_t, uint8_t *); // mem addr, size, buff addr
    void (*get_mem)(uint32_t, uint32_t, uint8_t *); // mem addr, size, buff addr
}
plc_rte_abi_t;

extern plc_app_abi_t * plc_curr_app;

/*
*  Logging
*/
#define LOG_LEVELS 4
#define LOG_CRITICAL 0
#define LOG_WARNING 1
#define LOG_INFO 2
#define LOG_DEBUG 3

#endif // _PLC_ABI_H_
