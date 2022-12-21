#ifndef _MENU_H_
#define _MENU_H_

#include <pthread.h>

#include "config_params.h"

static int occupation_quantity = 0;

void menu(config_params* params, char* data_send_to_server);
char* menu_options(char opc, config_params* params);
void menu_status_inputs(char* status, config_params* params);

#endif